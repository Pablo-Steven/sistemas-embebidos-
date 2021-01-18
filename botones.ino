/*UNIVERSIDAD TÉCNICA DEL NORTE
FICA-CITE
SISTEMAS EMBEBIDOS

NOMBRE: Ulcuango Pablo
FECHA: 18-01-2021
DOCENTE: Ing. Paul Rosero
TÉCNICO DOCENTE: Ing. Alejandra Pinto

LABORATORIO 3: Realice una interfaz controlada con un Arduino haciendo referencia a los juegos de la consola ATARI.
Añada la carcasa del control.
*/
int dato;
void setup() {
Serial.begin(9600);
}

void loop() {

 if(digitalRead(7)--LOW){
  delay(250);
  Serial.print("W");
 }
 if(digitalRead(6)--LOW){
  delay(250);
  Serial.print("S");
 }
 if(digitalRead(5)--LOW){
  delay(250);
  Serial.print("UP");
 }
 if(digitalRead(4)--LOW){
  delay(250);
  Serial.print("DOWN");
 }
}
