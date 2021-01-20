/*
UNIVERSIDAD TECNICA DEL NORTE
FICA-CITEL
SISTEMAS EMBEBIDOS

NOMBRE:Ulcuango Pablo
FECHA:20-01-2021
DOCENTE: Ing. Paul Rosero
TECNICO DOCENTE: Ing. Alejandra Pinto

DEBER 11:
Realice la regresión lineal exponencial dentro del entorno de 
Arduino con el conjunto de datos estatura-peso. Con esto,
ingrese por comunicación serial los nuevos datos de estatura e
imprima el pronóstico del peso.
*/
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

int col=0; 
int fil=0; 
int Ex=0; 
int Ey=0; 
long int Exy=0; 
long int Ex2=0;
long int Ex_2=0; 
float Ey_1p=0;
float Exy_1p=0;
float B=0;
float A=0;
float A_1p=0;
int n=14; 
float Bo;
float m; 
String dato; 
int estatura; 
float peso; 
int m1; 
void setup() {
  Serial.begin(9600);
  //creacion del modelo
  for(;fil<n;fil++){
    Ex=Ex+matriz[fil][0];
    Ey_1p=Ey_1p+log(matriz[fil][1]);
    Exy_1p=Exy_1p+(matriz[fil][0]*log(matriz[fil][1]));
    Ex2=Ex2+pow(matriz[fil][0],2);
    }
  Ex_2=pow(Ex,2);
  B=((float(n*Exy_1p)-(float(Ex*Ey_1p)))/((float(14*Ex2))-(float(Ex_2))));
  A_1p=(float((Ey_1p/n)))-((float(B))*(float(Ex/n)));
  A=exp(A_1p);
  Serial.println("El modelo de regresion lineal exponecial es: ");
  Serial.println(String("y= ")+String(A)+String("*")+String("e^")+String(B)+String("x"));
  Serial.println("Ingrese su estatura:");
}

void loop() {
  
  if(Serial.available()>0){
      delay(3000);
      dato=Serial.readString();
      estatura=dato.toInt();
      peso=A*exp(B*estatura);
      Serial.println("");
      Serial.println(String("Su peso es: ")+String(peso)+String("Kg"));
    }

}
