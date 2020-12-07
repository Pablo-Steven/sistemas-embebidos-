//**************EJERCICIO 3: Ordenamiento de vocales************

#include<LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);

String ct[5];

String cc[5];
String dato;
int c=0;
int i=0;
int m1=0;
void setup() {


 Serial.begin(9600); 
 lcd.begin(16,2); 

}
void loop() {
  if( m1==0){
  Serial.println("Ingrese Vocales");
  m1++;
  }
  if(Serial.available()>0){
 
 dato=Serial.readString(); 

delay(1000);

 }
   lcd.setCursor(0,1);
   lcd.print(dato); 
   Serial.print(dato);
  
for(i=0;i<6;i++){ 

  if(ct[i]=='a'){
  cc[c]="a";
      
    }
    if(i==5){
      i=0;}}
for(i=0;i<6;i++){ 

  if(ct[i]=='e'){
  cc[c]="e";
      
    }  if(i==5){
      i=0;}}   
    for(i=0;i<6;i++){ 

  if(ct[i]=='i'){
  cc[c]="i";
      
    } if(i==5){
      i=0;} }   
    for(i=0;i<6;i++){ 

  if(ct[i]=='o'){
  cc[c]="o";
      
    } if(i==5){
      i=0;} }   
    for(i=0;i<6;i++){ 

  if(ct[i]=='u'){
  cc[c]="u";
      
    }  if(i==5){
      Serial.print(ct[0]);
      Serial.print(ct[1]);
      Serial.print(ct[2]);
      Serial.print(ct[3]);
      Serial.print(ct[4]);

      lcd.setCursor(0,2);
      lcd.print("orden");
      lcd.setCursor(0,2);
      lcd.print(ct[0]);
      lcd.print(ct[1]);
      lcd.print(ct[2]);
      lcd.print(ct[3]);
      lcd.print(ct[4]);

      i=0;
}
}    
  
}
