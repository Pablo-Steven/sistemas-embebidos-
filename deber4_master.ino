/*MASTER
 * 
 */
 #include <Wire.h>
 String dato;
 int on=0;
 
void setup() {
  Wire.begin(); //cx i2c
  Serial.begin(9600); // cx serial
  Serial.println("Ingrese palabra");

}

void loop() {
  if(Serial.available()>0 && on==0){
    dato=Serial.readString();
    Serial.println("");
    byte tam=dato.length()+1;
    char cadena[tam];
    dato.toCharArray(cadena,tam);
  Wire.beginTransmission(4); // enviar informacion al esclavo con id 4
  for (byte i=0; i<=tam; i++){
    Wire.write(cadena[i]); // envio de dato
  }
    Serial.println(String("Envio: ")+String (dato)); //envio de mensaje 
    Wire.endTransmission(); //fin de transmision 
    on=1;
    delay(100); //retardo
  }
  Wire.requestFrom(4,10);
  if (on==1){
    char C=Wire.read();
    Serial.print(C);
    delay(100);
    on=0;

    
  }

}
