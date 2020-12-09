/*
 * UNIVERSIDAD TECNICA DEL NORTE
 * FICA-CITEL
 * SISTEMAS EMBEBIDOS
 * NOMBRE: ULCUANGO PABLO 
 * FECHA:09/12/2020
 * DEBER 7: Realiza un programa que valide y actualice una contraseña almacenada 
 * en la memoria EEPROM. Como estado inicial, la contraseña es de 4 dígitos que son: 4563.
 */
#include<EEPROM.h>
int i=0;
int dato1;
int contraseña=4563;
int c=0;

String dato;
String dato2;

int clave2;


void setup(){
  Serial.begin(9600);
  EEPROM.write(0,contraseña);
  Serial.println("Bienvenido ");
  Serial.println("Ingrese su contraseña ");
}

void loop(){
  if(c==0){
  if(Serial.available()>0){
    dato=Serial.readString();
    dato1=dato.toInt();
    if(dato1==contraseña){
      c=1;
    
      Serial.println("Contraseña correcta Correcta");
      delay(3000);
      Serial.println("Ingrese la Nueva contraseña");
      delay(3000);
      dato2=Serial.readString();
      clave2=dato2.toInt();
      contraseña=clave2;
      EEPROM.update(0,contraseña);
      Serial.println(String("La nueva contraseña es: ")+String(contraseña));
      Serial.println("Contraseña Actualizada");
      c=0;      
      
    }else{
      Serial.println("");
      Serial.println("Contaseña invalida");
      c=0;
    }
  }
 }
}
