/*/*Npmbre:Ulcuango Pablo
 * Fecha: 23-11-2020
 * Deber#2:Realizar un programa que al presionar el pulsador cada vez, se visualiza a cada número primo hasta el 99
  */
  const int A=8;
const int B=9;
const int C=10;
const int D=11;
const int decenas=13;
const int unidades=12;
const int btn1=4;
int cont=0;
int limite=0;
int dec; 
int uni;
void setup() {
  pinMode (A,OUTPUT);
  pinMode (B,OUTPUT);
  pinMode (C,OUTPUT);
  pinMode (D,OUTPUT);
  pinMode (decenas,OUTPUT);
  pinMode (unidades,OUTPUT);
  pinMode (btn1,INPUT);
  
  }

void loop() {
  if(digitalRead(btn1)==HIGH){
   delay(200);
  
   if(limite<25){ 
   limite ++;
   segmentos1(limite); 
   
    
  }else{
  limite=0;
  }
  dec= cont/10;
  uni=cont-(dec*10);                   //calculos para verficar decenas y unidades

digitalWrite(decenas,HIGH);
digitalWrite(unidades,LOW);
segmentos(dec);                  //llamar al metodo segmentos para obtener el valor
delay(200);
digitalWrite(decenas,LOW);
digitalWrite(unidades,HIGH);
segmentos(uni);                //llamar al metodo segmentos para obtener el valor
delay(200);                
}else{
  digitalWrite(decenas,HIGH);
digitalWrite(unidades,LOW);
segmentos(dec);                  //llamar al metodo segmentos para obtener el valor
delay(200);
digitalWrite(decenas,LOW);
digitalWrite(unidades,HIGH);
segmentos(uni);                //llamar al metodo segmentos para obtener el valor
delay(200);    
  }}

void segmentos(int i) {      // metodo segmentos para evitar redundancia en lineas de codigo
  switch (i){
    case 0:
    digitalWrite(D,LOW);
    digitalWrite(C,LOW);
    digitalWrite(B,LOW);
    digitalWrite(A,LOW);
    break;
      case 1:
    digitalWrite(D,HIGH);
    digitalWrite(C,LOW);
    digitalWrite(B,LOW);
    digitalWrite(A,LOW);
    break;
      case 2:
    digitalWrite(D,LOW);
    digitalWrite(C,HIGH);
    digitalWrite(B,LOW);
    digitalWrite(A,LOW);
    break;
      case 3:
    digitalWrite(D,HIGH);
    digitalWrite(C,HIGH);
    digitalWrite(B,LOW);
    digitalWrite(A,LOW);
    break;
      case 4:
    digitalWrite(D,LOW);
    digitalWrite(C,LOW);
    digitalWrite(B,HIGH);
    digitalWrite(A,LOW);
    break;
      case 5:
    digitalWrite(D,HIGH);
    digitalWrite(C,LOW);
    digitalWrite(B,HIGH);
    digitalWrite(A,LOW);
    break;
      case 6:
    digitalWrite(D,LOW);
    digitalWrite(C,HIGH);
    digitalWrite(B,HIGH);
    digitalWrite(A,LOW);
    break;
      case 7:
    digitalWrite(D,HIGH);
    digitalWrite(C,HIGH);
    digitalWrite(B,HIGH);
    digitalWrite(A,LOW);
    break;
      case 8:
    digitalWrite(D,LOW);
    digitalWrite(C,LOW);
    digitalWrite(B,LOW);
    digitalWrite(A,HIGH);
    break;
      case 9:
    digitalWrite(D,HIGH);
    digitalWrite(C,LOW);
    digitalWrite(B,LOW);
    digitalWrite(A,HIGH);
  break;
    
}}
void segmentos1(int j) {    
  switch (j){
    case 0:

   cont=0;
    break;
      case 1:
   cont=2;
    break;
      case 2:
   cont=3;
    break;
      case 3:
cont=5;
    break;
      case 4:
cont=7;
    break;
      case 5:
cont=11;
    break;
      case 6:
cont=13;
break;
      case 7:
cont=17;
    break;
      case 8:
      cont=19;
   
    break;
      case 9:
   cont=23;
  break;
   case 10:
   cont=29;
  break;
   case 11:
   cont=31;
   
  break;
   case 12:
   cont=37;
  break;
   case 13:
   cont=41;
  break;
   case 14:
   cont=43;
  break;
   case 15:
   cont=47;
  break;
   case 16:
   cont=53;
  break;
   case 17:
   cont=59;
  break;
   case 18:
   cont=61;
  break;
   case 19:
   cont=67;
  break;
     case 20:
   cont=71;
  break;
      case 21:
   cont=73;
  break;
      case 22:
   cont=79;
  break;
      case 23:
   cont=83;
  break;
      case 24:
   cont=89;
  break;
      case 25:
   cont=97;
  break;
}
}
