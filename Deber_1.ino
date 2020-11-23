/*Npmbre:Ulcuango Pablo
 * Fecha: 23-11-2020
 * Deber#1: Realizar un programa que accione mediante 4 switchs a un juego de luces diferente. Es decir.
sw3   sw2  sw1  sw0
0        0       0        1            Juego 1
0        0       1        0            Juego 2
0        1       0        0            Juego 3
1        0       0        0            Juego 4
Juego #1
Se usan 6 leds, de los cuales se encienden los pares por 10 ocasiones
Juego #2
Se usan 6 leds, de los cuales se encienden los impartes por 10 ocasiones
Juego #3
Se encienden secuencialmente cada uno ellos (flexible a su criterio)
Juego #4
Su propio diseño de juego.
 * 
 */
 const int led1=0;
const int led2=1;
const int led3=2;
const int led4=3;
const int led5=4;
const int led6=5;
const int sw1=9;
const int sw2=8;
const int sw3=7;
const int sw4=6;
int var1;
int var2;
int var3;
int var4;
int cont1=0;
int cont2=0;
void setup() {
pinMode(led1,OUTPUT); // pin8 declarado como salida
pinMode(led2,OUTPUT); // pin9 declarado como salida
pinMode(led3,OUTPUT); // pin10 declarado como salida
pinMode(led4,OUTPUT); 
pinMode(led5,OUTPUT); 
pinMode(led6,OUTPUT); 
pinMode(sw1,INPUT);
pinMode(sw2,INPUT); 
pinMode(sw3,INPUT); 
pinMode(sw4,INPUT); 
}

void loop() {
  if(digitalRead(sw1)==HIGH){ 
  var1=1;
}
  else{
  var1=0;
  }
  if(digitalRead(sw2)==HIGH){ 
  var2=1;
}
  else{
  var2=0;
  }
  if(digitalRead(sw3)==HIGH){ 
  var3=1;
}
  else{
  var3=0;
  }
  if(digitalRead(sw4)==HIGH){ 
  var4=1;
}
  else{
  var4=0;
  }

if(var1==1&&var2==0&&var3==0&&var4==0&&cont1<10){

   digitalWrite(led2,HIGH);
   digitalWrite(led4,HIGH);
   digitalWrite(led6,HIGH); 
   delay(200);
  
   digitalWrite(led2,LOW);
   digitalWrite(led4,LOW);
   digitalWrite(led6,LOW); 
   delay(200);
cont1++;
}
if(var1==0&&var2==1&&var3==0&&var4==0&&cont2<10){  
   digitalWrite(led1,HIGH);
   digitalWrite(led3,HIGH);
   digitalWrite(led5,HIGH); 
   delay(200);
  
   digitalWrite(led2,LOW);
   digitalWrite(led4,LOW);
   digitalWrite(led6,LOW); 
   delay(200); 
cont2++;
}
if(var1==0&&var2==0&&var3==1&&var4==0){ 
  digitalWrite(led1,HIGH);
  delay(200);
  digitalWrite(led2,HIGH);
  delay(200);
  digitalWrite(led3,HIGH);
  delay(200);
  digitalWrite(led4,HIGH);
  delay(200);
  digitalWrite(led5,HIGH);
  delay(200);
  digitalWrite(led6,HIGH); 
  delay(200); 
  digitalWrite(led2,LOW);
  digitalWrite(led4,LOW);
  digitalWrite(led6,LOW);
  digitalWrite(led1,LOW);
  digitalWrite(led3,LOW);
  digitalWrite(led5,LOW);

}
if(var1==0&&var2==0&&var3==0&&var4==1){ 
  digitalWrite(led1,HIGH);
  digitalWrite(led2,LOW);
  digitalWrite(led3,LOW);
  digitalWrite(led4,LOW);
  digitalWrite(led5,LOW);
  digitalWrite(led6,HIGH);
  delay(200); 
  digitalWrite(led1,LOW);
  digitalWrite(led2,HIGH);
  digitalWrite(led3,LOW);
  digitalWrite(led4,LOW);
  digitalWrite(led5,HIGH);
  digitalWrite(led6,LOW);
  delay(200); 
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
  digitalWrite(led3,HIGH);
  digitalWrite(led4,HIGH);
  digitalWrite(led5,LOW);
  digitalWrite(led6,LOW);
  delay(200); 
  digitalWrite(led1,HIGH);
  digitalWrite(led2,HIGH);
  digitalWrite(led3,HIGH);
  digitalWrite(led4,HIGH);
  digitalWrite(led5,HIGH);
  digitalWrite(led6,HIGH);
  delay(200); 
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
  digitalWrite(led3,LOW);
  digitalWrite(led4,LOW);
  digitalWrite(led5,LOW);
  digitalWrite(led6,LOW);
  delay(200); 

}
if(var1==0&&var2==0&&var3==0&&var4==0){ 
  cont1=0;
  cont2=0;
}
}
