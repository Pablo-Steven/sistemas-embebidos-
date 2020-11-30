/* DEBER #3
 *  NOMBRE: PABLO ULCUANGO 
 *  FECHA:30/11/2020
 * Realizar un programa de juego de preguntas. Se debe tener mínimo 8 preguntas que deben observarse en orden aleatorio. 
 * La forma de visualización es por medio de comunicación serial. Su respuesta solo debe ser "SI" y "NO" 
 * ingresadas de la misma forma por comunicación serial.
   Al final de mostrar solo 5 de las 8 preguntas. Se presentan el puntaje (respuestas acertadas) en un display.
 * 
 */String pregunta1="El triangulo tiene tres lados";
String pregunta2="El agua del mar es dulce ";
String pregunta3="El capacitor es un elemento activo";
String pregunta4="El futbol se juega solo con los pies";

String respuesta1="SI";
String respuesta2="NO";
String respuesta3="SI";
String respuesta4="SI";

int cont=0;
int cont2=0;

int aleatorio;
int a=0;
int b=0;
int c=0;
int d=0;

int bloqueo=0;

String Dato;

int puntaje=0;

void setup() {
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  
  Serial.begin(9600);
  Serial.println("Responda a las preguntas con SI o NO");
  Serial.println("");
  delay(500);
}

void loop() {
  aleatorio=random(1,5);
  delay(200);

//--------------LEER RESPUESTA-------------------------
  if(Serial.available()>0 && cont<5){
    Dato=Serial.readString();
    Serial.println("");
    
    if(aleatorio==1){
      if(Dato==respuesta1){
        puntaje=puntaje+1;
        cont2=cont2+1;
        bloqueo=0;
        }else{
          cont2=cont2+1;
          bloqueo=0;
          }
      }
    if(aleatorio==2){
      if(Dato==respuesta2){
        puntaje=puntaje+1;
        cont2=cont2+1;
        bloqueo=0;
        }else{
          cont2=cont2+1;
          bloqueo=0;
          }
      }
    if(aleatorio==3){
      if(Dato==respuesta3){
        puntaje=puntaje+1;
        cont2=cont2+1;
        bloqueo=0;
        }else{
          cont2=cont2+1;
          bloqueo=0;
          }
      }
    if(aleatorio==4){
      if(Dato==respuesta4){
        puntaje=puntaje+1;
        cont2=cont2+1;
        bloqueo=0;
        }else{
          cont2=cont2+1;
          bloqueo=0;
          }
      }
      
    }
  
//-----------------PREGUNTAR------------------------
  if(cont<4 && bloqueo==0){
  if(aleatorio==1 && a==0){
    Serial.println(pregunta1);
    bloqueo=1;
    cont=cont+1;
    a=1;
    }
  if(aleatorio==2 && b==0){
    Serial.println(pregunta2);
    bloqueo=1;
    cont=cont+1;
    b=1;
    
    }
  if(aleatorio==3 && c==0){
    Serial.println(pregunta3);
    bloqueo=1;
    cont=cont+1;
    c=1;
    
    }
  if(aleatorio==4 && d==0){
    Serial.println(pregunta4);
    bloqueo=1;
    cont=cont+1;
    d=1;
    }
    }
//---------------FIN PREGUNTAS------------
  if(cont2==4){
    Serial.println("");
    Serial.print("Su puntaje es: ");
    Serial.print(puntaje);
    Serial.println("/4");
    Serial.println("FIN DEL JUEGO");
    ver();
    cont2=0;
    }
}

//------------------DISPLAY------------------

void ver(){
  switch(puntaje){
    case 0:
    digitalWrite(13,LOW);
    digitalWrite(12,LOW);
    digitalWrite(11,LOW);
    digitalWrite(10,LOW);
    break;

    case 1:
    digitalWrite(13,HIGH);
    digitalWrite(12,LOW);
    digitalWrite(11,LOW);
    digitalWrite(10,LOW);
    break;

    case 2:
    digitalWrite(13,LOW);
    digitalWrite(12,HIGH);
    digitalWrite(11,LOW);
    digitalWrite(10,LOW);
    break;

    default:
    digitalWrite(13,LOW);
    digitalWrite(12,LOW);
    digitalWrite(11,LOW);
    digitalWrite(10,LOW);
    break;
    }
  }
