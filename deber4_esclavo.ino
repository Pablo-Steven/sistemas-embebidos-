/*DEBER4
 * NOMBRE: PABLO ULCUANGO 
 *  FECHA:30/11/2020
 * ++++++++ESCLAVO+++++++
 * Realice un sistema que codifique las vocales en palabras ingresadas por comunicación serial. 
 * Este mensaje se ingresa por comunicación serial en el master, este envía al esclavo para que 
 * realice la codificación por comunicación I2C. 
 * Luego, lo envía al master por el mismo medio y se muestra el resultado en una LCD en el master. 
 * La codificación es:
a=@
e=#
i= !
o = *
u= $
Ejemplo: CARRO = C@RR*
         01234
 */
#include <Wire.h>
String dato;
String letra;
int tam;
String a;
String total="";
String total2="";
int on=0;


void setup() {
  Wire.begin(4); 
  Wire.onReceive(datoRecivido);
  Wire.onRequest(respuesta);
  Serial.begin(9600);

}

void loop() {
  total="";
  a="";
  
  if (on==1){
    tam= total2.length();
    for(int i=0;i<tam;i++){          //para ir leyendo acada letra e identificar
     letra=total2.substring(i,i+1);
     codificar();
     total=total+a;
    }
    Serial.println(total2);
    Serial.println(total);
    total2="";
    on=0;
    
  }
}

void codificar(){
  if (letra=="a"){
    a="@";
  }
  else if (letra=="e"){
    a="#";  
  }
   else if (letra=="i"){
    a="!";  
  }
   else if (letra=="o"){
    a="*";  
  }
   else if (letra=="u"){
    a="$";  
  }
  else {
    a=letra;
  }
}

void datoRecivido(){
  while (Wire.available()>0){
    
    char C=Wire.read();
    total2=total2+C;
    on=1; 
  }
}

void respuesta(){
  byte tam2=total.length()+1;
    char cadena[tam2];
    total.toCharArray(cadena,tam2);
    for (byte j=0; j<=tam2; j++){
    Wire.write(cadena[j]); // envio de dato
  }
}
