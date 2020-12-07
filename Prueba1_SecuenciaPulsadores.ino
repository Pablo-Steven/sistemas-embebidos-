//****************EJERCICIO 2:Secuencia de 5 pulsadores**************


#include <Servo.h>

String numero="";
String secuencia="24153";
int cont=0;

Servo servo;

void setup() {

  servo.attach(8);
  
  pinMode(3,INPUT);
  pinMode(4,INPUT);
  pinMode(5,INPUT);
  pinMode(6,INPUT);
  pinMode(7,INPUT);

}

void loop() {
//----------------------------
if(digitalRead(3)==HIGH){
    numero=numero+"1";
    cont=cont+1;
    delay(300);
    }
//---------------------------------
if(digitalRead(4)==HIGH){
    numero=numero+"2";
    cont=cont+1;
    delay(300);
    }
//-----------------------------------
 
 if(digitalRead(5)==HIGH){
    numero=numero+"3";
    cont=cont+1;
    delay(300);
    }

//------------------------------------
 
 if(digitalRead(6)==HIGH){
    numero=numero+"4";
    cont=cont+1;
    delay(300);
    }

//-------------------------------------
 
 if(digitalRead(7)==HIGH){
    numero=numero+"5";
    cont=cont+1;
    delay(300);
    }

//-------------- validar---------------------

if(cont==5){

  if(numero==secuencia){

  servo.write(0);
  delay(500);
  servo.write(100);
  delay(500);
  servo.write(0);
  
  numero="";
  cont=0;
  
  }
  else{

  servo.write(0);
  
  numero="";
  cont=0;
    }
  
  }
}
