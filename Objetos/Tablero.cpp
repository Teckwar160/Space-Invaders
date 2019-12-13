/**!<Bibliotecas necesarias*/
#include "Tablero.hpp"


Tablero::Tablero():Figura(4){
	/*Obtenemos la forma del tablero*/
	char **Forma = this -> getForma();

	caracterBase = Forma[2][2];
}

Tablero::~Tablero(){

}

void Tablero::pintaJugador(Jugador *J){
	
	/*Obtenemos la forma del jugador*/
	char **formaJugador = J -> getForma();
	
	/*Obtenemos la forma del tablero*/
	char **formaTablero = this -> getForma();

	/*Obtenemos la posición del punto de control del jugador*/
	int x = J -> getX();
	int y = J -> getY();

	/*Pintamos en punto de control del jugador*/
	formaTablero[y][x] = formaJugador[2][3];

	/*Pintamos el pico de la nave*/
	formaTablero[y-1][x] = formaJugador[1][3];
	formaTablero[y-1][x+1] = formaJugador[1][4];
	formaTablero[y-1][x-1] = formaJugador[1][2];
	formaTablero[y-2][x] = formaJugador[0][3];

	/*Pintamos el lado superior izquierdo de la nave*/
	formaTablero[y][x-1] = formaJugador[2][2];
	formaTablero[y][x-2] = formaJugador[2][1];
	formaTablero[y][x-3] = formaJugador[2][0];	
	
	/*Pintamos el lado superior derecho de la nave*/
	formaTablero[y][x+1] = formaJugador[2][4];
	formaTablero[y][x+2] = formaJugador[2][5];
	formaTablero[y][x+3] = formaJugador[2][6];

	/*Pintamos el lado inferior izquierdo de la nave*/
	formaTablero[y+1][x-1] = formaJugador[3][2];
	formaTablero[y+1][x-2] = formaJugador[3][1];
	formaTablero[y+1][x-3] = formaJugador[3][0];

	/*Pintamos el lado inferior derecho de la nave*/
	formaTablero[y+1][x+1] = formaJugador[3][4];
	formaTablero[y+1][x+2] = formaJugador[3][5];
	formaTablero[y+1][x+3] = formaJugador[3][6];

	/*Pintamos la parte de abajo del punto de control de la nave*/
	formaTablero[y+1][x] = formaJugador[3][3];
}

void Tablero::mueveJugador(Jugador *J, int Tecla){
	
	/*Obtenemos las coordenadas del jugador*/
	int x = J -> getX();
	int y = J -> getY();

	/*Obtenemos las dimensiones del tablero*/
	int tableroFilas = this -> getFilas();
	int tableroColumnas = this -> getColumnas();

	/*Dependiendo la tecla sera el movimiento*/
	switch(Tecla){
		case 'a':
			if(x -3 > 1){
				x -=1;
			}
			break;
		case 'd':
			if(x + 3 < tableroColumnas -2){
				x+=1;
			}
			break;
	}

	/*Borramos al antiguo sprite*/
	this -> borrarJugador(J);

	/*Actualizamos las coordenadas del jugador*/
	J -> setX(x);
	J -> setY(y);

	/*Pintamos al nuevo sprite*/
	this -> pintaJugador(J);
	


}

void Tablero::borrarJugador(Jugador *J){
	/*Obtenemos la forma del tablero*/
	char **formaTablero = this -> getForma();

	/*Obtenemos la posición del punto de control del jugador*/
	int x = J -> getX();
	int y = J -> getY();

	/*Borramos en punto de control del jugador*/
	formaTablero[y][x] = this -> caracterBase;

	/*Borramos el pico de la nave*/
	formaTablero[y-1][x] = this -> caracterBase;
	formaTablero[y-1][x+1] = this -> caracterBase;
	formaTablero[y-1][x-1] = this -> caracterBase;
	formaTablero[y-2][x] = this -> caracterBase;

	/*Borramos el lado superior izquierdo de la nave*/
	formaTablero[y][x-1] = this -> caracterBase;
	formaTablero[y][x-2] = this -> caracterBase;
	formaTablero[y][x-3] = this -> caracterBase;
	
	/*Borramos el lado superior derecho de la nave*/
	formaTablero[y][x+1] = this -> caracterBase;
	formaTablero[y][x+2] = this -> caracterBase;
	formaTablero[y][x+3] = this -> caracterBase;

	/*Borramos el lado inferior izquierdo de la nave*/
	formaTablero[y+1][x-1] = this -> caracterBase;
	formaTablero[y+1][x-2] = this -> caracterBase;
	formaTablero[y+1][x-3] = this -> caracterBase;

	/*Borramos el lado inferior derecho de la nave*/
	formaTablero[y+1][x+1] = this -> caracterBase;
	formaTablero[y+1][x+2] = this -> caracterBase;
	formaTablero[y+1][x+3] = this -> caracterBase;

	/*Borramos la parte de abajo del punto de control de la nave*/
	formaTablero[y+1][x] = this -> caracterBase;
}

void Tablero::pintaBala(Bala *B){

	/*Obtenemos la forma del tablero*/
	char **formaTablero = this -> getForma();

	/*Obtenemos la forma de la bala*/
	char **formaBala = B -> getForma();

	/*Obtenemos las coordenadas de la bala*/
	int x = B -> getX();
	int y = B -> getY();

	/*Pintamos la bala en el tablero*/
	formaTablero[y][x] = formaBala[0][0];
}

void Tablero::borrarBala(Bala *B){
	/*Obtenemos la forma del tablero*/
	char **formaTablero = this -> getForma();

	/*Obtenemos las coordenadas de la bala*/
	int x = B -> getX();
	int y = B -> getY();

	/*Borramos a la bala*/
	formaTablero[y][x] = this -> caracterBase;
}

void Tablero::dispararJugador(Jugador *J){

	/*Obtenemos la forma del tablero*/
	char **formaTablero = this -> getForma();

	/*Obtenemos las coordenadas del jugador*/
	int x = J -> getX();
	int y = J -> getY();
	
	/*Creamos la bala*/
	Bala *B = new Bala();

	/*Definimos las coordenadas de la bala*/
	B -> setX(x);
	B -> setY(y-3);

	/*Pintamos la bala*/
	this -> pintaBala(B);

	/*Cargamos la bala al depósito*/
	J -> cargarBala(B);

	/*Incrementamos el numero de disparos*/
	J -> incrementaDisparos();
}

bool Tablero::mueveBala(Jugador *J){

	/*Obtenemos a la bala*/
	Bala *B = J -> getBala();

	/*Obtenemos las coordenadas de la bala*/
	int x = B -> getX();
	int y = B -> getY();

	/*Movemos la bala una posición*/
	y -=1;
	
	/*Obtenemos la forma del tablero*/
	char **formaTablero = this -> getForma();

	/*Veirifcamos que no choque contra un muro*/

	if(formaTablero[y][x] == '#'){
		this -> borrarBala(B);
		formaTablero[y][x] = this -> caracterBase;
		J -> borrarBala();
		return false;
	}

	/*Verificamos que siga en el tablero*/

	if(y > 0){
		this -> borrarBala(B);
		B -> setY(y);
		this -> pintaBala(B);
		return true;
	}else{
		this -> borrarBala(B);
		J -> borrarBala();
		return false;
	}

}
