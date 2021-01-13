/*UNIVERSIDAD TÉCNICA DEL NORTE
 * FICA-CITEL
 * SISTEMAS EMBEBIDOS 
 * 
 * NOMBRE: Ulcuango Pablo
 * FECHA: 13-01-2021
 * DOCENTE: Ing. Paul Rosero
 * 
 * DEBER #8:Realizar un código que el sistema se reinicia cada minuto, 
 * active el conversor análogo-digital realice una lectura y vuelve el 
 * sistema a un modo sleep.
 * 
 */

#include <MsTimer2.h>  //Libreria para Timer 2
#include <avr/power.h> //Libreria para ahorro de bateria
#include <avr/sleep.h> //Libreria para modo sleep
#include<avr/wdt.h>    //Libreria para reiniciar 

int i = 0; //variable para contar reloj
int valor = 0; //variable para el potenciometro

void setup() {

  wdt_disable(); //deshabilitamos el reinicio
  
  Serial.begin(9600); //Comunicacion serial a 9600 vaudios

  Serial.println(" "); 
  Serial.println("Sistema Encendido");
  Serial.println(" ");

  delay(500); //Detenemos el microcontrolador por 500 milisegundos
  
  MsTimer2::set(100, reloj); //Configuramos el reloj a 100 milisegundos y creamos el metodo reloj
  MsTimer2::start(); //Iniciamos el contador "Reloj"

}

void loop() {
if(i==0){ //Si el contador esta en 0 lee el potenciometro por ese segundo, hasta que cambie a 1s
  valor=analogRead(0); //leemos el valor del potenciometro y lo almacenamos en valor
  Serial.println("Valor: "+String(valor)); //Imprimimos el valor durante 1s
  }
if(i>0){ //Cuando el contador este mayor a 1, cambia al modo sleep
  Serial.println("");
  Serial.println("Modo Sleep");
  Serial.println("");
  delay(100); 
  sleep(); //Llamamos al metodo sleep, el cual contiene las opciones para ahorrar energia y dormir al microcontrolador
  }

}

void sleep(){ // metodo sleep
    set_sleep_mode(SLEEP_MODE_IDLE); //Definimos al modo sleep,
    sleep_enable(); // habilitamos el modo sleep
    power_adc_disable(); // deshabilitamos el conversor analogo digital
    power_spi_disable(); // deshabilita la comunicacion serial 
    power_timer0_disable(); // deshabilita el modulo timer 0
    power_timer1_disable(); // deshabilita el modulo timer 1
    power_timer2_disable(); // deshabilita el modulo timer 2
    power_twi_disable(); // deshabilita el modulo timer 0
    power_usart0_disable(); // deshabilita el módulo de interfaz del puerto C
    power_all_disable(); // Deshabilita la alimentacion de los pines
    sleep_mode(); // Modo sleep
    sleep_disable();// 
  }

void reloj() {
  i++; //la variable i se suma 1, cada 1 s
  if (i == 60) { //cuando i sea igual a 60, es decir haya pasado 1 min
    MsTimer2::stop(); //Detenemos el contador
    wdt_enable(WDTO_30MS); //Reiniciamos el sistema en 30 milisegundos 
  }else{
    wdt_disable(); //si no ha pasado 1 min, seguimos deshabilitando el reinicio. 
    }
}
