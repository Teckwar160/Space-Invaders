/**!<Bibliotecas necesarias*/
#include "Tablero.hpp"

/***************************************
 *	Método privado
 **************************************/
void Tablero::liberaSoldado(Soldado *S){
	delete S;
}

/***************************************
 * 	Métodos publicos
 **************************************/
Tablero::Tablero():Figura(4){
	/*Obtenemos la forma del tablero*/
	char **Forma = this -> getForma();

	/*Definimos el fondo del tablero*/
	caracterBase = Forma[2][2];

	/*Creamos la lista de los soldados*/
	soldados = new DLL<Soldado*>();

	/*Creamos a los soldados*/
	for(size_t i = 0; i< ENEMIGOS; i++){
		this -> soldados -> InsertBack(new Soldado(4+i*7,2));
	}
}

Tablero::~Tablero(){
	/*Liberamos la memoria de los soldados que no se elminaron*/
	if(this -> soldados -> Len() > 0){
		this -> soldados -> Traverse(this -> liberaSoldado);
	}

	/*Borramos la lista de soldados*/
	delete soldados;
}

/*========Métodos para el jugador========*/
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

int Tablero::mueveBala(Jugador *J){

	/*Obtenemos a la bala*/
	Bala *B = J -> getBala();

	/*Obtenemos las coordenadas de la bala*/
	int x = B -> getX();
	int y = B -> getY();

	/*Movemos la bala una posición*/
	y -=1;
	
	/*Obtenemos la forma del tablero*/
	char **formaTablero = this -> getForma();

	/*Veirifcamos si choco contra un muro*/
	if(formaTablero[y][x] == '#'){

		/*Borramos la bala*/
		this -> borrarBala(B);

		/*Pintamos el tablero con el fondo*/
		formaTablero[y][x] = this -> caracterBase;

		/*Borramos la bala de la lista de balas del jugador*/
		J -> borrarBala();

		/*Salimos del método*/
		return Bala::Choco::MURO;
	}

	/*Verificamos si choco contra un soldado*/

	/**!<Soldados que se verificara si choco contra el la bala*/
	Soldado *S = NULL;

	/**!<Indicador de si el soldado fue eliminado o no*/
	bool muereSoldado = false;

	/*Colocamos el cursor de los soldados en la primera posición*/
	this -> soldados -> CursorFirst();

	/*Recorremos la lista de soldados para verificacar si la bala choco contra alguno*/
	for(size_t i = this -> soldados -> Len(); i > 0; i--){

		/*Obtenemos al soldado*/
		this -> soldados -> Peek(&S);
		
		/*Vemos si la bala choco contra el soldado*/
		if(y -2 == S -> getY() && x == S -> getX() ||  x -1 == S -> getX() || x +1 == S -> getX() || x +2 == S -> getX() || x -2 == S -> getX()){
			
			/*Borramos la bala*/
			this -> borrarBala(B);

			/*Borramos al soldado*/
			this -> borrarSoldado(S);

			/*Eliminamos al soldado de la lista*/
			this -> soldados -> Remove(&S);

			/*Liberamos la memoria del soldado*/
			delete S;

			/*Borramos la bala de la lista de balas del jugador*/
			J -> borrarBala();

			/*Cambiamos el estado del soldado*/
			muereSoldado = true;

			/*Salimos el bucle*/
			break;
		}

		/*Movemos el cursor al siguiente soldado en la lista*/
		this -> soldados -> CursorNext();
	}

	/*Si el soldado murio lo indicamos y salimos del método*/
	if(muereSoldado){
		return Bala::Choco::SOLDADO;
	}


	/*Verificamos que siga en el tablero*/
	if(y > 0){
		/*Borramos la bala*/
		this -> borrarBala(B);

		/*Actualizamos la posicón de la bala*/
		B -> setY(y);
		
		/*Repintamos la bala*/
		this -> pintaBala(B);

	}else{
		/*Borramos la bala*/
		this -> borrarBala(B);

		/*Borramos a la bala de la lista de balas del jugador*/
		J -> borrarBala();
	}

	return Bala::Choco::NADA;

}

/*========Métodos de los soldados========*/
void Tablero::pintaSoldados(){
	/*Obtenemos la forma del tablero*/
	char **formaTablero = this -> getForma();
	
	/*Colocamos al cursor de la lista de soldados en el primer soldado*/
	this -> soldados -> CursorFirst();

	/**!<Soldado que se pintara*/
	Soldado *S;

	/*Recorremos toda la lista de soldados para pintarlos*/
	for(size_t i = this -> soldados -> Len(); i > 0; i--){

		/*Obtenemos al soldado*/
		this -> soldados -> Peek(&S);

		/*Obtenemos la forma del soldado*/
		char **formaSoldado = S -> getForma();

		/*Obtenemos las coordenadas del punto de control del soldado*/
		int x = S -> getX();
		int y = S -> getY();

		/*Pintamos el punto de control del soldado*/
		formaTablero[y][x] = formaSoldado[1][3];

		/*Pintamos la parte superior izquierda*/
		formaTablero[y-1][x-1] = formaSoldado[0][2];
		formaTablero[y-1][x-2] = formaSoldado[0][1];

		/*Pintamos la parte superior central*/
		formaTablero[y-1][x] = formaSoldado[0][3];

		/*Pintamos la parte superior derecha*/
		formaTablero[y-1][x+1] = formaSoldado[0][4];
		formaTablero[y-1][x+2] = formaSoldado[0][5];

		/*Pintamos la parte central izquierda*/
		formaTablero[y][x-1] = formaSoldado[1][2];
		formaTablero[y][x-2] = formaSoldado[1][1];

		/*Pintamos la parte central derecha*/
		formaTablero[y][x+1] = formaSoldado[1][4];
		formaTablero[y][x+2] = formaSoldado[1][5];

		/*Pintamos la parte inferior izquierda*/
		formaTablero[y+1][x-1] = formaSoldado[2][2];
		formaTablero[y+1][x-2] = formaSoldado[2][1];

		/*Pintamos la parte inferior central*/
		formaTablero[y+1][x] = formaSoldado[2][3];

		/*Pintamos la parte inferior derecha*/
		formaTablero[y+1][x+1] = formaSoldado[2][4];
		formaTablero[y+1][x+2] = formaSoldado[2][5];

		/*Movemos al cursor a la siguiente posición*/
		this -> soldados -> CursorNext();	
	}


}

void Tablero::borrarSoldado(Soldado *S){
	/*Obtenemos la forma del tablero*/
	char **formaTablero = this -> getForma();

	/*Obtenemos la forma del soldado*/
	char **formaSoldado = S -> getForma();

	/*Obtenemos las coordenadas del punto de control del soldado*/
	int x = S -> getX();
	int y = S -> getY();

	/*Borramos el punto de control del soldado*/
	formaTablero[y][x] = this -> caracterBase;

	/*Borramos la parte superior izquierda*/
	formaTablero[y-1][x-1] = this -> caracterBase;
	formaTablero[y-1][x-2] = this -> caracterBase;

	/*Borramos la parte superior central*/
	formaTablero[y-1][x] = this -> caracterBase;

	/*Borramos la parte superior derecha*/
	formaTablero[y-1][x+1] = this -> caracterBase;
	formaTablero[y-1][x+2] = this -> caracterBase;

	/*Borramos la parte central izquierda*/
	formaTablero[y][x-1] = this -> caracterBase;
	formaTablero[y][x-2] = this -> caracterBase;

	/*Borramos la parte central derecha*/
	formaTablero[y][x+1] = this -> caracterBase;
	formaTablero[y][x+2] = this -> caracterBase;

	/*Borramos la parte inferior izquierda*/
	formaTablero[y+1][x-1] = this -> caracterBase;
	formaTablero[y+1][x-2] = this -> caracterBase;

	/*Borramos la parte inferior central*/
	formaTablero[y+1][x] = this -> caracterBase;

	/*Borramos la parte inferior derecha*/
	formaTablero[y+1][x+1] = this -> caracterBase;
	formaTablero[y+1][x+2] = this -> caracterBase;	
			
}

void Tablero::borrarSoldados(){
	/*Obtenemos la forma del tablero*/
	char **formaTablero = this -> getForma();

	/*Colocamos al cursor de la lista de soldados en el primer soldado*/
	this -> soldados -> CursorFirst();

	/**!<Soldado que se borrara*/
	Soldado *S;

	/*Recorremos la lista de soldados*/
	for(size_t i = this -> soldados -> Len(); i> 0; i--){
		/*Obtenemos al soldado*/
		this -> soldados -> Peek(&S);

		/*Obtenemos la forma del soldado*/
		char **formaSoldado = S -> getForma();

		/*Obtenemos las coordenadas del punto de control del soldado*/
		int x = S -> getX();
		int y = S -> getY();

		/*Borramos el punto de control del soldado*/
		formaTablero[y][x] = this -> caracterBase;

		/*Borramos la parte superior izquierda*/
		formaTablero[y-1][x-1] = this -> caracterBase;
		formaTablero[y-1][x-2] = this -> caracterBase;

		/*Borramos la parte superior central*/
		formaTablero[y-1][x] = this -> caracterBase;

		/*Borramos la parte superior derecha*/
		formaTablero[y-1][x+1] = this -> caracterBase;
		formaTablero[y-1][x+2] = this -> caracterBase;

		/*Borramos la parte central izquierda*/
		formaTablero[y][x-1] = this -> caracterBase;
		formaTablero[y][x-2] = this -> caracterBase;

		/*Borramos la parte central derecha*/
		formaTablero[y][x+1] = this -> caracterBase;
		formaTablero[y][x+2] = this -> caracterBase;

		/*Borramos la parte inferior izquierda*/
		formaTablero[y+1][x-1] = this -> caracterBase;
		formaTablero[y+1][x-2] = this -> caracterBase;

		/*Borramos la parte inferior central*/
		formaTablero[y+1][x] = this -> caracterBase;

		/*Borramos la parte inferior derecha*/
		formaTablero[y+1][x+1] = this -> caracterBase;
		formaTablero[y+1][x+2] = this -> caracterBase;	

		/*Movemos al cursor al siguiente soldado*/
		this -> soldados -> CursorNext();			
	}
}

/**!<Inicialización de la variable de sentido*/
int Soldado::sentido;

void Tablero::mueveSoldados(){
	/*Borramos al viejo soldado*/
	this -> borrarSoldados();

	this -> soldados -> CursorFirst();
	Soldado *S;
	for(size_t i = this -> soldados -> Len(); i> 0; i--){
		/*Obtenemos al soldado*/
		this -> soldados -> Peek(&S);

		/*Obtenemos las coordenadas del soldado*/
		int x = S -> getX();
		int y = S -> getY();

		/*Obtenemos las dimensiones del tablero*/
		int tableroFilas = this -> getFilas();
		int tableroColumnas = this -> getColumnas();

		/*Obtenemos el sentido del movimiento del soldado*/
		int sentido = Soldado::sentido;

		/*Movemos al jugador a la derecha*/
		if(sentido == Soldado::Sentido::DERECHA && x +2 < tableroColumnas -2){
			x +=1;
		}else if(x == tableroColumnas -4 && sentido == Soldado::Sentido::DERECHA){
			/*Si llego al limite de la pantalla bajamos un lugar al soldado y cambiamos su sentido*/
			if(y +1 != tableroFilas -4){
				y += 1;	
			}

			Soldado::sentido = Soldado::Sentido::IZQUIERDA;
		}

		/*Movemos al jugador a la izquierda*/
		if(sentido == Soldado::Sentido::IZQUIERDA && x -2 > 1){
			x -=1;
		}else if(x == 3 && sentido == Soldado::Sentido::IZQUIERDA){
			/*Si llego al limite de la pantalla bajamos un lugar al soldado y cambiamos su sentido*/
			if(y +1 != tableroFilas -4){
				y += 1;	
			}

			Soldado::sentido = Soldado::Sentido::DERECHA;
		}

		/*Actualziamos las coordenadas*/
		S -> setX(x);
		S -> setY(y);

		this -> soldados -> CursorNext();
	}

	/*Pintamos al nuevo soldado*/
	this -> pintaSoldados();

}