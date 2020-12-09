/*
 * UNIVERSIDAD TECNICA DEL NORTE
 * FICA-CITEL
 * SISTEMAS EMBEBIDOS
 * NOMBRE: ULCUANGO PABLO 
 * FECHA:09/12/2020
 * DEBER 5: Realizar un programa que mediante interrupciones tenga 3 modos: 
 * Inicio del sistema, giro de motor y fin de programa. 
 * El giro debe ser ingresado por comunicación serial.
 */
#include <Servo.h>
String dato;
int angulo;
int cont=0;
Servo servo1; // creación de objeto para servo 1
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  servo1.attach(9);
 attachInterrupt(0,int1,HIGH);
 attachInterrupt(1,int2,HIGH);
}

void loop() {
  
if(cont==0){
  
  Serial.println("Inicio Sistema");
  cont++;
}

 if(cont==2){
  
  Serial.println("Sistema encendido");
  Serial.println("Ingrese angulo del servo motor de 0 a 180 grados ");  
  cont++;}
  
  if(cont==4){
 if(Serial.available()>0){ 
 dato=Serial.readString(); 
 
 angulo=dato.toInt();
 servo1.write(angulo);
 delay(300);
 Serial.println();
 Serial.println("El angulo ingresado es " +String(angulo)+ "grados ");
  Serial.println("El angulo del servo es  " +String(angulo-90)+ "grados ");
 }

 }
 
  if(cont==6){
    Serial.println("Sistema APAGADO");
  delay(1000);
    Serial.println("Para reiniciar presione la segunda interrupccion");
 cont++; }
 


}
void int1(){
  cont++;
  delay(1000);
}
void int2(){
  cont=0;
   delay(1000);
}
