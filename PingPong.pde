/*UNIVERSIDAD TÉCNICA DEL NORTE
FICA-CITE
SISTEMAS EMBEBIDOS

NOMBRE: Ulcuango Pablo
FECHA: 18-01-2021
DOCENTE: Ing. Paul Rosero
TÉCNICO DOCENTE: Ing. Alejandra Pinto

LABORATORIO 3: Realice una interfaz controlada con un Arduino haciendo referencia a los juegos de la consola ATARI.
A~nada la carcasa del control.
*/
Jugador jugador1, jugador2;//creacion constantes jugadores
Pelota pelota;
boolean ganador;
int puntajeMaximo;

void setup() {
  size(900,500);
  
  jugador1 = new Jugador(1); //creacion  jugadores , llamando a la clase
  jugador2 = new Jugador(2); //creacion   jugadores , llamando a la clase
  
  pelota = new Pelota(1); //creacion pelota , llamando a la clase
  
  ganador = false; //condicion de inicialisación del juego
  
  puntajeMaximo = 3; //el puntaje que los jugadores deben de alcanzar para ganar
}

void draw() {
  background(0);  

  textSize(15);
  fill(255);
  text("Ulcuango Pablo",700,480);
  textSize(30);
  text("JUGADOR 1",100,30);
  text("JUGADOR 2",600,30);
  text("MARCADOR",358,70);
  textSize(30);
  fill(#F58719);
  text(jugador1.getPuntos(), width/2 - 60, 40);//Posicion jugador
  text(jugador2.getPuntos(), width/2 + 30, 40);//Posicion jugador
  

  if(ganador == false) {//Miebtras se ejecuta la condicion el juego funcionara
    strokeWeight(2);
    stroke(255);
    
    for(int y = 0; y < height; y+= 10) {//juego
      line(width/2,y,width/2,y+5);
    }
    
    pelota.mostrar();//LLamar a metodos
    pelota.mover();//LLamar a metodos
  }
  
  jugador1.mostrar();
  jugador1.mover();
  pelota.validarReboteJugador1(jugador1.getPosicion());
  
  jugador2.mostrar();
  jugador2.mover();
  pelota.validarReboteJugador2(jugador2.getPosicion());
  
  pelota.validarReboteParedes();
  validarPuntos();
  validarGanador();
}

void validarPuntos() {
  
  PVector posicionPelota = pelota.getPosicion();//Tomar posicion de clase pelota

  if(posicionPelota.x > width && jugador1.getPuntos() <= puntajeMaximo) {
    jugador1.setPuntos(1);

    pelota = new Pelota(-1);
  } 

  else if(posicionPelota.x < 0 && jugador2.getPuntos() <= puntajeMaximo) { 
    jugador2.setPuntos(1);

    pelota = new Pelota(1);
  }

  else if (keyPressed && ganador == true) {
    setup();
  }
}

void validarGanador() {

  if(jugador1.getPuntos() == puntajeMaximo) {
    fill(245,135,25);
    text("Felicidades Jugador 1 haz ganado la partida", 80, height/2);
    textSize(20);
    text("Oprime un tecla para jugar nuevamente", 95, height/2 + 30);
    ganador = true;
  } else if(jugador2.getPuntos() == puntajeMaximo) {
    text("Felicidades Jugador 1 haz ganado la partida", 80, height/2);
    textSize(20);
    text("Oprime un tecla para jugar nuevamenter", 95, height/2 + 30);
    ganador = true;
  }
}
class Jugador {
  PVector posicion, velocidad;// toma variables
  int ancho, alto, numeroJugador, puntos;// toma variables
  
  Jugador(int numeroJugador_) {
    numeroJugador = numeroJugador_;//tamaño del jugador
    ancho = 20; //ancho del rectangulo del jugador
    alto = 100; //alto del rectangulo del jugador
    puntos = 0; //puntos del jugador

    if(numeroJugador == 1) {
      posicion = new PVector(ancho/2, height/2);
    } else if(numeroJugador == 2) {
      posicion = new PVector(width - ancho/2, height/2);
    }
    
 
    velocidad = new PVector(0,6);
  }
  
  void mover() { //metodo mover asignacion de controles J1=w,s J2=>> << por teclado

    if(numeroJugador == 1 && key == 'w') {
      //Se moverá hacia arriba
      posicion.sub(velocidad);
    } 
    else if(numeroJugador == 1 && key == 's') {
      //se moverá hacia abajo
      posicion.add(velocidad);
    }
       if(numeroJugador == 2 && keyCode == UP) {
      //Se moverá hacia arriba
      posicion.sub(velocidad);
    } 
     else if(numeroJugador == 2 && keyCode == DOWN) {
      //Se moverá hacia abajo
      posicion.add(velocidad);
    }
    posicion.y = constrain(posicion.y,alto/2,height - alto/2);
  }

  void mostrar() {// creacion de movimiento
    fill(85,75,211);
    noStroke();
    rectMode(CENTER);
    rect(posicion.x, posicion.y, ancho, alto);
  }
  
  PVector getPosicion() {
    return posicion;
  }
  
  //contador de puntos
  void setPuntos(int puntos_) {
    puntos += puntos_;
  }
  
  int getPuntos() {
    return puntos;
  }
}
class Pelota {
  PVector posicion, velocidad;
  int anchoJugador, altoJugador;
  
  Pelota(int direccion) {// crea pelota en direccion especifica
    anchoJugador = 20;
    altoJugador = 100;
    posicion = new PVector(width/2, height/2);
 
    velocidad = new PVector(direccion*random(4,5), random(4,5));// velocidad pelota
  }
  
  void mover() {// movimiento en base a la velocidad
    posicion.add(velocidad);
  }
  

  void mostrar() {
    fill(26,144,54);
    noStroke();
    ellipse(posicion.x, posicion.y, 20,20);
  }
  
  void validarReboteJugador1(PVector posicionJugador) {// rebote en jugadores

    float min = posicionJugador.y - altoJugador/2;
    

    float max = posicionJugador.y + altoJugador/2;

    if(posicion.x < anchoJugador && posicion.y > min && posicion.y < max) {
      velocidad.x *= -1;
    }
  }
  
  void validarReboteJugador2(PVector posicionJugador) {
    float min = posicionJugador.y - altoJugador/2;
    float max = posicionJugador.y + altoJugador/2;
    
    if(posicion.x > width - anchoJugador && posicion.y > min && posicion.y < max) {
      velocidad.x *= -1;
    }
  }
  
  void validarReboteParedes() {// rebotes en paredes
    if(posicion.y > height) {
      velocidad.y *= -1;
    } else if(posicion.y < 0) {
      velocidad.y *= -1;
    }
  }
  
  PVector getPosicion() {
    return posicion;
  }
}
