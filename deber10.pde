/*
UNIVERSIDAD TÉCNICA DEL NORTE
FICA-CITEL
SISTEMAS EMBEBIDOS

NOMBRE: Ulcuango Pablo
FECHA:11-01-2021
DOCENTE:Ing Paul Rosero

DEBER #10: Realice una interfaz que permita mover
una esfera por toda la pantalla mediante teclas.
*/

int x = 450;
int y = 250;

void setup()
{
  size(900,500);
  background(#A4E6E8);
  line(0,15,900,15);
  line(15,0,15,500);
  line(0,485,900,485);
  line(885,0,885,500);
  fill(222,85,103);
  ellipse(x,y,100,100);
  textSize(30);
  fill(74,47,201);
  text("ULCUANGO PABLO DEBER 10",200,50);

}

void draw(){
  if(keyPressed)
{
  switch(keyCode)
  {
    case 38:
    y -= 5;
    break;
    case 40: 
    y += 5;
    break;
    case 39:
    x += 5;
    break;
    case 37: //37
    x -= 5;
    break;
    default:
    break;
  }
  background(#A4E6E8);  
  if(x>=850){ 
    x= 850;
  }
  else if(x<=50){ 
    x=50;
  }
  else if(y>=450){ 
    y= 450;
  }
  else if(y<=50){ 
    y=50;  
  }
   line(0,15,900,15);
   line(15,0,15,500);
   line(0,485,900,485);
   line(885,0,885,500);
   fill(222,85,103);
   ellipse(x,y,100,100); 
   textSize(30);
   fill(74,47,201);
   text("ULCUANGO PABLO DEBER 10",200,50);
 }
}
