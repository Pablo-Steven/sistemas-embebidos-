/*UNIVERSIDAD TÉCNICA DEL NORTE
 * FICA-CITEL
 * SISTEMAS EMBEBIDOS 
 * 
 * NOMBRE: Ulcuango Pablo
 * FECHA: 13-01-2021
 * DOCENTE: Ing. Paul Rosero
 * 
 * DEBER #9:Realice un programa que mediante un conversor análogo-digital 
 * se configure el tiempo de reinicio del perro guardián (tiempos seleccionados 
 * por el usuario). Envíe mensajes por comunicación serial validando todo el proceso.
 */
 
#include <MsTimer2.h>//Libreria para el Timer 2
#include<avr/wdt.h>//Libreria para reinicio del sistema "Perro Guardian"

int dato = 0; //Variable para almacenar la lectura del potenciometro
int valor; //Variable para almacenar la conversion 
int bloqueo = 0;//Variable para bloquear la seleccion

void setup() {
  Serial.begin(9600); //Iniciamos la comunicacion serial a 9600 vaudios 
  pinMode(4, INPUT); //Definimos el pin digital 4 como entrada, para detectar la activacion de un boton 
  wdt_disable(); //Deshabilitamos el reinicio del sistema
  Serial.println(" ");
  Serial.println("Seleccione el tiempo a reiniciar");
  delay(1500); //Detenemos el microcontrolador por 1500 milisegundos
}

void loop() {

  if (bloqueo == 0) { //mientras no se haya oprimido el boton, se puede selecionar el tiempo de reinicio
    dato = analogRead(0); //Leemos el dato del potenciometro
    valor = map(dato, 0, 1023, 1, 60);// convertimos el valor del potenciometro de 0-1023 a 1-60 utilizando la funcion map

    Serial.print("Segundos: "); //Imprimimos el valor en s
    Serial.println(valor); //

    delay(250);//
  }

  if (digitalRead(4) == HIGH && bloqueo == 0) { //Detecta la pulsacion del boton 

    MsTimer2::set(1000, contador); //Configuramos el contador a 1s y creamos el metodo contador, el cual se repetira cada 1s
    MsTimer2::start(); //Iniciamos el metodo
    Serial.println("");
    Serial.print("Reinicio en: "); //Imprimimos el tiempo de reinicio seleccionado
    Serial.println(valor);
    Serial.println("");
    bloqueo = 1; //Bloqueamos la seleecion y deshabilitamos el reloj
    delay(300); //
  }

}

void contador() {
  valor--; //Restamos el tiempo seleccionado
  Serial.println("             "+String(valor) + "s"); //Imprmimimos el tiempo para el reinicio

  if (valor == 0) { //cuando la variable llegue a 0 
    MsTimer2::stop(); //Detenemos el contador
    wdt_enable(WDTO_30MS); //Reiniciamos el sistema
  }
  else {
    wdt_disable(); //Mientras la variable no sea 0, deshabilitamos el reinicio 
  }
}
