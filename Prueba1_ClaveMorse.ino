//**************EJERCICIO 1:Convertidor de clave morse **********

#include <LiquidCrystal.h>

LiquidCrystal lcd (13,12,11,10,9,8);
String dato;
int tam;
String letra;
String codigo;
String total="";


void setup() {
  Serial.begin(9600);
  Serial.println("Ingrese una palabara a Codificar");

}

void loop() {
  total="";
  codigo="";
  if(Serial.available()>0){
    dato=Serial.readString();
    tam=dato.length();
    for(int i=0;i<tam;i++){    
      letra=dato.substring(i,i+1);//separando caracteres
      codificacion();//llamar al metodo para comparar y guardar
      total=total+codigo;//y guarda en codigo lo que almacena
    }
    Serial.println("");
    Serial.println(total);
  }

}

void codificacion(){
  if(letra=="A"){
    codigo=".-";
  }

  if(letra=="B"){
    codigo="-...";
  }

  if(letra=="C"){
    codigo="-.-.";
  }

  if(letra=="D"){
    codigo="-..";
  }
  if(letra=="E"){
    codigo=".";
  }
  if(letra=="F"){
    codigo="..-.";
  }
  if(letra=="G"){
    codigo="--.";
  }
  if(letra=="H"){
    codigo="....";
  }
  if(letra=="I"){
    codigo="..";
  }
  if(letra=="J"){
    codigo=".---";
  }
  if(letra=="K"){
    codigo="-.-";
  }
  if(letra=="L"){
    codigo=".-..";
  }
  if(letra=="M"){
    codigo="--";
  }
  if(letra=="N"){
    codigo="-.";
  }
  if(letra=="O"){
    codigo="--";
  }
  if(letra=="P"){
    codigo=".--.";
  }
  if(letra=="Q"){
    codigo="--.-";
  }
  if(letra=="R"){
    codigo=".-.";
  }
  if(letra=="S"){
    codigo="...";
  }
  if(letra=="T"){
    codigo="-";
  }
  if(letra=="U"){
    codigo="..-";
  }
  if(letra=="V"){
    codigo="...-";
  }
  if(letra=="W"){
    codigo=".--";
  }
  if(letra=="X"){
    codigo="-..-";
  }
  if(letra=="Y"){
    codigo="-.--";
  }
  if(letra=="Z"){
    codigo="--..";
  }
  if(letra=="0"){
    codigo="-----";
  }
  if(letra=="1"){
    codigo=".----";
  }
  if(letra=="2"){
    codigo="..---";
  }
  if(letra=="3"){
    codigo="...--";
  }
  if(letra=="4"){
    codigo="....-";
  }
   if(letra=="5"){
    codigo=".....";
  }
  if(letra=="6"){
    codigo="-....";
  }
  if(letra=="7"){
    codigo="--...";
  }
  if(letra=="8"){
    codigo="---..";
  }
  if(letra=="9"){
    codigo="----.";
  }
  lcd.setCursor(0,0);   //ubicación en lcd
  lcd.print(String (codigo)); //mensaje lcd
  delay(3000);           // tiempo de espera
  lcd.clear();
}
