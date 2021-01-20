/*
Erazo Carlos - Laboratorio 4
Regresión lineal
*/

import processing.serial.*;

Serial port; //Objeto para puerto com
int dato=0; // Variable de rx de datos
int aux;

float [][] matriz ={
{(170-154.37)*40.0078064,475-67*5},
{(180-154.37)*40.0078064,475-80*5},
{(170-154.37)*40.0078064,475-65*5},
{(178-154.37)*40.0078064,475-75*5},
{(160-154.37)*40.0078064,475-55*5},
{(163-154.37)*40.0078064,475-60*5},
{(165-154.37)*40.0078064,475-63*5},
{(170-154.37)*40.0078064,475-70*5},
{(164-154.37)*40.0078064,475-62*5},
{(176-154.37)*40.0078064,475-77*5},
{(164-154.37)*40.0078064,475-60*5},
{(170-154.37)*40.0078064,475-76*5},
{(170-154.37)*40.0078064,475-56*5},
{(168-154.37)*40.0078064,475-60*5},
};


float sep,sep2;
int k=150;
int m=100;
float x=157,y,y1,v=225;

void setup() {
  port=new Serial(this,"COM11",9600);
  background(#A488E8);
  size(1250,600);
  sep=200;
  sep2=50;
  planoF();
  fill(0);  
  textSize(20);
  text("Regresión Lineal",50,18);
  text("Ulcuango Pablo - LABORATORIO 4",50,538);
    //  text("y=paso/ x=altura",1000,680);
  fill(5,180,103);
  stroke(0);
  rect(775,510,180,75);
  fill(255);
  textSize(15);
  text("y=1,1797x-133,39",800,535);
  textSize(15);  
  text("R = 0,7036",800,565);
  textSize(8);  
  text("2",810,415);
}

void draw() {
  if(dato>0){
    y1 = 1.1797*dato-133.39;
    fill(0);
    stroke(0);
    ellipse((dato-154.37)*40.0078064,475-y1*5,10,10);
  }
 
}

void planoF(){
  strokeWeight(1);
  rect(25,25,1200,450);
  for(float i=25;i<=1200;i+=sep){
    line(i,25,i,475);
    k=k+5;
    fill(0);  
    textSize(10);
    text(k,i,490); 
  }
    for(float j=25;j<=450;j+=sep2){
    line(25,j,1225,j);
    m=m-10;
    fill(0);  
    textSize(10);
    text(m,10,j);
  }
    for(int c=0;c<14;c++){
    fill(#11F2F0);
    stroke(0);
    ellipse(matriz[c][0],matriz[c][1],10,10);
    }
    // Proyección de Linea 
    for(float v=50;v<=1080;v+=10){
    x+=0.25;
    y=1.1797*x-133.39;
    fill(#FC7A2E);
    stroke(#FC7A2E);
    ellipse((x-154.37)*40.0078064,475-y*5,6,2);
    }

}

void serialEvent(Serial port){
  
  dato=port.read();
  aux=int(dato); //Convertir de string a int
  println(dato);    

}
