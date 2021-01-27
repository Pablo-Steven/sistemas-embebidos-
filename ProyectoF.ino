/*
UNIVERSIDAD TECNICA DEL NORTE
FICA-CITEL
SISTEMAS EMBEBIDOS

NOMBRE:Ulcuango Pablo
FECHA:25-01-2021
DOCENTE: Ing. Paul Rosero
TECNICO DOCENTE: Ing. Alejandra Pinto
********PROYECTO********
*/
#include "datos.h"
float prueba[5] = {0.6,0.1,0.7,0.4,3};
float distancia [202];
float etiquetas [202];
float dis;
float aux;
float aux2;

int k=11; //Numero impar

int etiquetas1=0;
int etiquetas2=0;
int etiquetas3=0;
int etiquetas4=0;

void setup() {
  Serial.begin(9600);
  //--------------------Distancia-----------------------------------
  for (int filas = 0; filas < 202; filas++) {
    for (int columnas = 0; columnas < 4; columnas++) {
      dis = dis + pow(datos[filas][columnas] - prueba[columnas], 2);
    }
    dis = sqrt(dis);
    distancia[filas] = dis;
    etiquetas[filas]=datos[filas][4];
    dis = 0;
    //Serial.println(distancia[filas]);
  }

  //---------------------Ordenar------------------------------------
  for (int i = 0; i < 202; i++) {
    for (int j = 0; j < 202; j++) {
      if (distancia[j] > distancia[j + 1]) {
        aux = distancia[j];
        aux2=etiquetas[j];
        etiquetas[j]=etiquetas[j+1];
        distancia[j]=distancia[j+1];
        distancia[j + 1] = aux;
        etiquetas[j+1]=aux2;
      }
    }
  }
  
//
//  for (int i = 0; i < 202; i++) {
//    Serial.println(distancia[i]);
//    Serial.println(etiquetas[i]);
//  }
//--------------------------------------------------------------------------------------------------------
    Serial.println("-------------------------------------");
    Serial.println("                K-NN                 ");
    Serial.println("-------------------------------------");
    for(int a=2;a<k+2;a++){
      Serial.println("k: "+String(a-1)+" etiq: "+String(etiquetas[a]));
    }

//-----------------------Calcular cuantas etiquetas tienes segun K--------------------------------------
  for(int a=2;a<k+2;a++){
      if(etiquetas[a]==1){
        etiquetas1=etiquetas1+1;
        }
      else if(etiquetas[a]==2){
        etiquetas2=etiquetas2+1;
        }
      else if(etiquetas[a]==3){
        etiquetas3=etiquetas3+1;
        }
      else {
        etiquetas4=etiquetas4+1;
        }
    }
    Serial.println("-------------------------------------");
    Serial.println("       Cantidad de Etiquetas         ");
    Serial.println("-------------------------------------");
    Serial.println("Etiquetas #1: "+String(etiquetas1));
    Serial.println("Etiquetas #2: "+String(etiquetas2));
    Serial.println("Etiquetas #3: "+String(etiquetas3));
    Serial.println("Etiquetas #4: "+String(etiquetas4));
    
//---------------------Determinar etiqueta a la que pertenece----------------------------------
    if(etiquetas1>etiquetas2 && etiquetas1>etiquetas3 && etiquetas1>etiquetas4){
    Serial.println("-------------------------------------");
    Serial.println("     Pertenece a la etiqueta 1       ");
    Serial.println("-------------------------------------");  
      } 
    else if(etiquetas2>etiquetas1 && etiquetas2>etiquetas3 && etiquetas2>etiquetas4){
    Serial.println("-------------------------------------");
    Serial.println("     Pertenece a la etiqueta 2       ");
    Serial.println("-------------------------------------");  
      }
    else if(etiquetas3>etiquetas1 && etiquetas3>etiquetas2 && etiquetas3>etiquetas4){
    Serial.println("-------------------------------------");
    Serial.println("     Pertenece a la etiqueta 3       ");
    Serial.println("-------------------------------------");
      }
      else{
    Serial.println("-------------------------------------");
    Serial.println("     Pertenece a la etiqueta 4       ");
    Serial.println("-------------------------------------");
        }

}

void loop() {
  // put your main code here, to run repeatedly:

}
