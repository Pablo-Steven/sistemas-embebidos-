/*
 *
UNIVERSIDAD TECNICA DEL NORTE
FICA-CITEL
SISTEMAS EMBEBIDOS

NOMBRE:Ulcuango Pablo
FECHA:20-01-2021
DOCENTE: Ing. Paul Rosero
TECNICO DOCENTE: Ing. Alejandra Pinto

LABORATORIO 4:Realizar un interfaz donde se evidencie el proceso de
aprendizaje de maquina realizado por el sistema
embebido de la siguiente forma:
-Imprimir los puntos del conjunto de entrenamiento correspondientes a la regresion lineal (pesoestatura)
y la tendencia lineal o exponencial.
-Al ingresar un nuevo valor por comunicacion serial al sistema electronico, realizar el pronostico (en
depedencia de la interfaz si se desea una tendencia lineal o exponencial) y gracarlo en la interfaz
con un color diferente a lo ya visto del conjunto de entrenamiento.
 */
#include <SoftwareSerial.h>
SoftwareSerial cx(2,3);

#define recept 2
#define trasmit 3
//String dato;
int dato1;
int datoM;
int i=0;
int j=0;
//matriz de datos (Altura,Peso)
int matriz [14][2]={
{170,67},
{180,80},
{170,65},
{178,75},
{160,55},
{163,60},
{165,63},
{170,70},
{164,62},
{176,77},
{164,60},
{170,76},
{170,56},
{168,60},
};
int col=0; //moverse en columnas
int fil=0; //moverse en filas
int Ex=0; //Sumatoria de x
int Ey=0; //Sumatoria de y
long int Exy=0; //Sumatoria de xy
long int Ex2=0; //Sumatoria de x^2
long int Ex_2=0; //Sumatoria de (Ex)^2
int n=14; //tam de muestras
float Bo;//ordenada en el origen
float m; //pendiente
String dato; //recibir estatura
int estatura; //convertir dato
float peso; 
int m1; //Aux
void setup() {
  Serial.begin(9600);
  pinMode(recept, INPUT);
  pinMode(trasmit, OUTPUT);
  cx.begin(9600);
  for(;fil<n;fil++){
    Ex=Ex+matriz[fil][0];
    Ey=Ey+matriz[fil][1];
    Exy=Exy+(matriz[fil][0]*matriz[fil][1]);
    Ex2=Ex2+pow(matriz[fil][0],2);
    }
  Ex_2=pow(Ex,2);
  Bo=(float(Ex2*Ey)-float(Ex*Exy))/(float(n*Ex2-Ex_2));
  m1=(n*Exy)-(Ex*Ey); //aux de desborde
  m=float(m1)/(float(n*Ex2-Ex_2));
  //Serial.println("El modelo es: ");
  //Serial.println(String("y= ")+String(m)+String("x")+String("+")+String(Bo));
  Serial.println("Ingrese su estatura para determinar su peso: ");

  
}

void loop() {
  //Captura de datos por cx Serial
   if(Serial.available()>0){
      delay(3000);
      dato=Serial.readString();
      estatura=dato.toInt();
      peso=m*estatura+Bo;
      cx.write(estatura); //Envio de datos
      Serial.println("");
      Serial.println(String("Su peso es: ")+String(peso)+String("Kg"));
    }
}
