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
Tablero::Tablero(int numEnemigos):Figura(Figura::Sprite::TABLERO){
	/*Obtenemos la forma del tablero*/
	char **Forma = this -> getForma();

	/*Definimos el fondo del tablero*/
	caracterBase = Forma[2][2];

	/*Definimos el número de enemigos*/
	this -> numEnemigos = numEnemigos;

	/*Creamos la lista de los soldados*/
	soldados = new DLL<Soldado*>();

	/*Creamos a los soldados*/
	for(size_t i = 0; i< this -> numEnemigos; i++){
		this -> soldados -> InsertBack(new Soldado(4+i*7,2));
	}

	/*Definimos la posición de los puntos en el tablero*/
	this -> puntosX = 63;
	this -> puntosY = 28;

	/*Definimos la posición de las vidas en el tablero*/
	this -> vidasX = 37;
	this -> vidasY = 28;

	/*Definimos la posición del nivel en el tablero*/
	this -> nivelX = 11;
	this -> nivelY = 28;

	/*Definimos el numero inicial de puntos del jugador*/
	this -> puntosJugador = 0;

	/*Definimos las balas que pueden disparar los soldados*/
	this -> balasSoldados = 2;
}

Tablero::~Tablero(){
	/*Liberamos la memoria de los soldados que no se elminaron*/
	if(this -> soldados -> Len() > 0){
		this -> soldados -> Traverse(this -> liberaSoldado);
	}

	/*Borramos la lista de soldados*/
	delete soldados;
}

void Tablero::pintaPuntos(Jugador *J){
	/*Obtenemos la forma de tablero*/
	char **formaTablero = this -> getForma();

	/*Obtenemos los puntos del jugador*/
	int puntos = J -> getPuntos();

	/*Separamos el numero*/
	int millares = puntos/1000;
	int centenas = (puntos - (millares *1000))/100;
	int decenas = (puntos - (millares*1000 + centenas*100))/10;
	int unidades = puntos -(millares*1000 + centenas*100 +decenas*10);

	/*Actualizamos los puntos en el pantalla*/
	formaTablero[puntosY][puntosX] = '0' + unidades;
	formaTablero[puntosY][puntosX -2] = '0' + decenas;
	formaTablero[puntosY][puntosX -4] = '0' + centenas;
	formaTablero[puntosY][puntosX -6] = '0' + millares;
}

void Tablero::mostrarNivel(int nivel){

	/*Obtenemos la forma del tablero*/
	char **formaTablero = this -> getForma();

	/*Se seguira mostrando el nivel en el que va hasta llegar al 10 que es el jefe final*/
	if(nivel <=9){

		/*Vamos actualizando el nivel del juego*/
		formaTablero[nivelY][nivelX] = '0' + nivel;

	}else{

		/*Al llegar al nivel 10 se mostrara que es el jefe final*/
		formaTablero[nivelY][nivelX] = 'B';
		formaTablero[nivelY][nivelX+1] = 'O';
		formaTablero[nivelY][nivelX+2] = 'O';
		formaTablero[nivelY][nivelX+3] = 'S';
	}
	
}

void Tablero::subirNivel(Jugador *J, int *nivel){

	/*Se comprobara que el jugador haya terminado con todos los enemigos*/
	if(J -> getPuntos() == numEnemigos*puntosSoldado + this -> puntosJugador){

		/*Incrementamos el nivel*/
		*nivel +=1;

		if(*nivel <= 9){

			/*Guardamos los puntos actuales del jugador*/
			this -> puntosJugador = J -> getPuntos();

			/*Comprobamos que el numero de enemigos no pase de 10 para evitar que sea muy difícil*/
			if(this -> numEnemigos <=10){

				/*Incrementamos el numero de enemigos*/
				this -> numEnemigos++;
			}

			/*Creamos a los nuevos soldados para que el juego continue*/
			for(size_t i = 0; i< this -> numEnemigos; i++){

				this -> soldados -> InsertBack(new Soldado(4+i*7,2));
			}

			/*Para mayor dificultad aumentamos el número de balas que pueden disparar los soldados*/
			this -> balasSoldados +=1;			
		}
	}
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

	/*Borramos al antiguo jugador*/
	this -> borrarJugador(J);

	/*Actualizamos las coordenadas del jugador*/
	J -> setX(x);
	J -> setY(y);

	/*Pintamos al nuevo jugador*/
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

	/*Incrementamos el número de disparos*/
	J -> incrementaDisparos();
}

Bala::Choco Tablero::mueveBala(Jugador *J){

	/*Obtenemos a la bala*/
	Bala *B = J -> getBala();

	/*Obtenemos las coordenadas de la bala*/
	int x = B -> getX();
	int y = B -> getY();

	/*Movemos la bala una posición*/
	y -=1;
	
	/*Obtenemos la forma del tablero*/
	char **formaTablero = this -> getForma();

	/*Verificamos si choco contra un muro*/
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

	/*Verificamos si choco contra otra bala*/
	if(formaTablero[y][x] == '*'){

		/*Borramos a la bala*/
		this -> borrarBala(B);

		/*Pintamos el tablero con el fondo*/
		formaTablero[y][x] = this -> caracterBase;

		/*Borramos la bala de la lista de balas del jugador*/
		J -> borrarBala();

		/*Salimos del método*/
		return Bala::Choco::BALA;
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

		/*Verificamos la coordenada en Y*/
		if(y-1 == S -> getY() + 1 || y -2 == S -> getY() || y - 3 == S -> getY() - 1){
			
			/*Verificamos la coordenada en X*/
			if(x == S -> getX() ||  x -1 == S -> getX() || x -2 == S -> getX() || x +1 == S -> getX() || x +2 == S -> getX()){
				
				/*Borramos la bala*/
				this -> borrarBala(B);

				/*Liberamos la memoria de las balas disparadas por el soldado*/

				/*Ponemos el cursor del depósito de balas del soldado en la primer bala*/
				S -> primerBala();

				/**!<Bala temporal que sirve de apoyo para liberar memoria*/
				Bala *tmp;

				/*Recorremos todo el depósito de balas del soldado*/
				for(size_t i = S -> getNumBalas(); i> 0; i--){

					/*Obtenemos a la bala*/
					tmp = S -> getBala();

					/*Eliminamos a la bala del tablero*/
					formaTablero[tmp -> getY()][tmp -> getX()] = this -> caracterBase;

					/*Borramos a la bala del depósito del soldado*/
					S -> borrarBala();

					/*Pasamos a la siguiente bala*/
					S -> siguienteBala();
				}

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

				/*Aumentamos los puntos del jugador*/
				J -> setPuntos(J -> getPuntos() + puntosSoldado);

				/*Salimos el bucle*/
				break;			
			}

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

		/*Movemos el cursor al siguiente soldado*/
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
Soldado::Sentido Soldado::sentido;

void Tablero::mueveSoldados(){

	/*Verificamos que existan soldados que mover*/
	if(this -> soldados -> Len() > 0){

		/*Obtenemos al primer y al ultimo soldado*/
		Soldado *primer;
		Soldado *ultimo;

		this -> soldados -> CursorFirst();
		this -> soldados -> Peek(&primer);

		this -> soldados -> CursorLast();
		this -> soldados -> Peek(&ultimo);

		/*Borramos a los viejos soldados*/
		this -> borrarSoldados();


		/**!<Indica si se moveran a los soldados hacia la derecha o no*/
		bool derecha = false;

		/**!<Indica si se moveran a los soldados hacia la izquierda o no*/
		bool izquierda = false;

		/**!<Indica si se moveran a los soldados hacia abajo o no*/
		bool abajo = false;

		/*Obtenemos las coodenadas de los soldados especiales*/

		/*Coordenadas del primer soldado*/
		int xP = primer -> getX();
		int yP = primer -> getY();

		/*Coordenadas del ultimo soldado*/
		int xU = ultimo -> getX();
		int yU = ultimo -> getY();

		/*Obtenemos las dimensiones del tablero*/
		int tableroFilas = this -> getFilas();
		int tableroColumnas = this -> getColumnas();

		/*Obtenemos el sentido del movimiento del soldado*/
		int sentido = Soldado::sentido;

		/*Vemos si se puede mover a los soldados hacia la derecha*/
		if(sentido == Soldado::Sentido::DERECHA && xU +2 < tableroColumnas -2){
			derecha = true;

		}else if(xU == tableroColumnas -4 && sentido == Soldado::Sentido::DERECHA){
			
			/*Si llego al limite de la pantalla, indicamos que se muevan hacia abajo a los soldados*/
			if(yU +1 != tableroFilas -4){
				abajo = true;
			}

			/*Cambiamos el sentido del movimiento*/
			Soldado::sentido = Soldado::Sentido::IZQUIERDA;
		}

		/*Vemos si se puede mover a los soldados hacia la izquierda*/
		if(sentido == Soldado::Sentido::IZQUIERDA && xP -2 > 1){
			izquierda = true;

		}else if(xP == 3 && sentido == Soldado::Sentido::IZQUIERDA){

			/*Si llego al limite de la pantalla, indicamos que se muevan hacia abajo a los soldados*/
			if(yP +1 != tableroFilas -4){
				abajo = true;	
			}

			/*Cambiamos el sentido del movimiento*/
			Soldado::sentido = Soldado::Sentido::DERECHA;
		}

		/*Una vez definidos los movimientos de los soldados, actualizamos sus posiciones*/

		/*Colocamos el cursor de los soldados en la primera posición*/
		this -> soldados -> CursorFirst();

		/**!<Soldado de apoyo para actualizar las coordenadas de los soldados*/
		Soldado *S;

		/*Bucle que actualiza las coordenadas de los soldados*/
		for(size_t i = this -> soldados -> Len(); i> 0; i--){

			/*Obtenemos al soldado*/
			this ->  soldados -> Peek(&S);

			/*Dependiendo el movimiento actualizamos su posición*/
			if(derecha == true){
				S -> setX(S -> getX() +1);
			}

			if(izquierda == true){
				S -> setX(S -> getX() -1 );
			}

			if(abajo == true){
				S -> setY(S -> getY() + 1);
			}

			/*Pasamos al siguiente soldado*/
			this -> soldados -> CursorNext();
		}

		/*Pintamos al nuevo soldado*/
		this -> pintaSoldados();

	}
}

void Tablero::dispararSoldados(){
	
	srand(time(NULL));

	/**!<Soldado de apoyo*/
	Soldado *S;

	/*Colocamos el cursor de soldados en el primero de ellos*/
	this -> soldados -> CursorFirst();

	/*Recorremos a todos los soldados vivos*/
	for(size_t i = this -> soldados -> Len(); i > 0; i--){

		this -> soldados -> Peek(&S);

		/*Si el destino dice que dispare*/
		if(rand()%999%5 == 0 && S -> getNumBalas() < this -> balasSoldados && S -> getY() +2 <27){
			
			/*Obtenemos al soldado*/
			this -> soldados -> Peek(&S);

			/*Creamos a la bala que se dispara*/
			Bala *B = new Bala();

			/*Asignamos las coordenadas de la bala*/
			B -> setX(S -> getX());
			B -> setY(S -> getY() +2);

			/*Pintamos la bala en el tablero*/
			this -> pintaBala(B);

			/*Cargamos la bala en el deposito del soldado*/
			S -> cargarBala(B);			
		}

		/*Pasamos al siguiente soldado*/
		this -> soldados -> CursorNext();

	}
}

Bala::Choco Tablero::mueveBala(Soldado *S, Jugador *J){

	/*Obtenemos a la bala*/
	Bala *B = S -> getBala();

	/*Obtenemos las coordenadas de la bala*/
	int x = B -> getX();
	int y = B -> getY();

	/*Movemos la bala una posición*/
	y +=1;
	
	/*Obtenemos la forma del tablero*/
	char **formaTablero = this -> getForma();

	/*Veirificamos si choco contra un muro*/
	if(formaTablero[y][x] == '#'){

		/*Borramos la bala*/
		this -> borrarBala(B);

		/*Pintamos el tablero con el fondo*/
		formaTablero[y][x] = this -> caracterBase;

		/*Borramos la bala de la lista de balas del soldado*/
		S -> borrarBala();

		/*Salimos del método*/
		return Bala::Choco::MURO;
	}

	/*Verificamos si choco contra otra bala*/
	if(formaTablero[y][x] == '*'){

		/*Borramos a la bala*/
		this -> borrarBala(B);

		/*Pintamos el tablero con el fondo*/
		formaTablero[y][x] = this -> caracterBase;

		/*Borramos la bala de la lista de balas del soldado*/
		S -> borrarBala();

		/*Salimos del método*/
		return Bala::Choco::BALA;
	}

	/*Verificamos si choco contra el jugador*/

	/*Verificamos la coordenada en Y*/
	if(y + 2 == J -> getY() || y +1 == J -> getY() -1 || y +3 == J -> getY() + 1 || y + 4 == J -> getY() + 2){
			
		/*Verificamos la coordenada en X*/
		if(x == J -> getX() ||  x -1 == J -> getX() ||  x -2 == J -> getX() ||  x -3 == J -> getX() ||  x +1 == J -> getX() || x +2 == J -> getX() || x + 3 == J -> getX()){
				
				/*Borramos la bala*/
				this -> borrarBala(B);

				/*Restamos vidas al jugador*/
				J -> setVidas(J -> getVidas() -1);

				/*Dependiendo el numero de vidas, se actualizara el tablero*/
				if(formaTablero[vidasY][vidasX] == '$'){
					formaTablero[vidasY][vidasX] = '.';
				}else if(formaTablero[vidasY][vidasX -2] == '$'){
					formaTablero[vidasY][vidasX -2] = '.';
				}else if(formaTablero[vidasY][vidasX -4] == '$'){
					formaTablero[vidasY][vidasX -4] = '.';
				}
				

				/*Borramos la bala de la lista de balas del soldado*/
				S -> borrarBala();

				/*Salimos del método*/
				return Bala::Choco::JUGADOR;
		}

	}

	/*Verificamos que siga en el tablero*/
	if(y < 27){
		/*Borramos la bala*/
		this -> borrarBala(B);

		/*Actualizamos la posicón de la bala*/
		B -> setY(y);
		
		/*Repintamos la bala*/
		this -> pintaBala(B);

	}else{
		/*Borramos la bala*/
		this -> borrarBala(B);

		/*Borramos a la bala de la lista de balas del soldado*/
		S -> borrarBala();
	}

	/*Indicamos que no paso nada*/
	return Bala::Choco::NADA;

}

void Tablero::primerSoldado(){
	this -> soldados -> CursorFirst();
}	
void Tablero::siguienteSoldado(){
	this -> soldados -> CursorNext();
}

int Tablero::getNumSoldados(){
	return this -> soldados -> Len();
}

Soldado *Tablero::getSoldado(){
	Soldado *tmp;

	this -> soldados -> Peek(&tmp);

	return tmp;
}

/*========Métodos para el jefe========*/

void Tablero::pintaJefe(Jefe *J){
	/*Obtenemos la forma del tablero*/
	char **formaTablero = this -> getForma();

	/*Obtenemos la forma del Jefe*/
	char **formaJefe = J -> getForma();

	/*Obtenemos las coordenadas del punto de control del jefe*/
	int x = J -> getX();
	int y = J -> getY();

	/*pintamos el punto de contro del Jefe*/
	formaTablero[y][x] = formaJefe[3][5];

	/*Pintamos la parte superior del jefe*/
	formaTablero[y-1][x-1] = formaJefe[2][4];
	formaTablero[y-1][x-2] = formaJefe[2][3];
	formaTablero[y-1][x-3] = formaJefe[2][2];
	formaTablero[y-1][x] = formaJefe[2][5];
	formaTablero[y-1][x+1] = formaJefe[2][6];
	formaTablero[y-1][x+2] = formaJefe[2][7];
	formaTablero[y-1][x+3] = formaJefe[2][8];

	/*Pintamos la antena izquierda*/
	formaTablero[y-2][x-2] = formaJefe[1][3];
	formaTablero[y-3][x-3] = formaJefe[0][2];

	/*Pintamos la antena derecha*/
	formaTablero[y-2][x+2] = formaJefe[1][7];
	formaTablero[y-3][x+3] = formaJefe[0][8];

	/*Pintamos la parte central izquierda*/
	formaTablero[y][x-1] = formaJefe[3][4];
	formaTablero[y][x-3] = formaJefe[3][2];
	formaTablero[y][x-4] = formaJefe[3][1];

	/*Pintamos la parte central derecha*/
	formaTablero[y][x+1] = formaJefe[3][6];
	formaTablero[y][x+3] = formaJefe[3][8];
	formaTablero[y][x+4] = formaJefe[3][9];

	/*Pintamos la parte inferior del jefe*/
	formaTablero[y+1][x] = formaJefe[3][5];
	formaTablero[y+1][x-1] = formaJefe[3][4];
	formaTablero[y+1][x-2] = formaJefe[3][3];
	formaTablero[y+1][x-3] = formaJefe[3][2];
	formaTablero[y+1][x-4] = formaJefe[3][1];
	formaTablero[y+1][x-5] = formaJefe[3][0];
	formaTablero[y+1][x+1] = formaJefe[3][6];
	formaTablero[y+1][x+2] = formaJefe[3][7];
	formaTablero[y+1][x+3] = formaJefe[3][8];
	formaTablero[y+1][x+4] = formaJefe[3][9];
	formaTablero[y+1][x+5] = formaJefe[3][10];

	/*Pintamos las piernas y los brazos*/
	formaTablero[y+2][x] = formaJefe[5][5];
	formaTablero[y+2][x-1] = formaJefe[5][4];
	formaTablero[y+2][x-2] = formaJefe[5][3];
	formaTablero[y+2][x-3] = formaJefe[5][2];
	formaTablero[y+2][x-5] = formaJefe[5][0];
	formaTablero[y+2][x+1] = formaJefe[5][6];
	formaTablero[y+2][x+2] = formaJefe[5][7];
	formaTablero[y+2][x+3] = formaJefe[5][8];
	formaTablero[y+2][x+5] = formaJefe[5][10];
	formaTablero[y+3][x-3] = formaJefe[6][2];
	formaTablero[y+3][x-5] = formaJefe[6][0];
	formaTablero[y+3][x+3] = formaJefe[6][8];
	formaTablero[y+3][x+5] = formaJefe[6][10];
	formaTablero[y+4][x-1] = formaJefe[7][4];
	formaTablero[y+4][x-2] = formaJefe[7][3];
	formaTablero[y+4][x+1] = formaJefe[7][6];
	formaTablero[y+4][x+2] = formaJefe[7][7];
}

void Tablero::borrarJefe(Jefe *J){
	/*Obtenemos la forma del tablero*/
	char **formaTablero = this -> getForma();

	/*Obtenemos las coordenadas del punto de control del jefe*/
	int x = J -> getX();
	int y = J -> getY();

	/*pintamos el punto de contro del Jefe*/
	formaTablero[y][x] = this -> caracterBase;

	/*Pintamos la parte superior del jefe*/
	formaTablero[y-1][x-1] = this -> caracterBase;
	formaTablero[y-1][x-2] = this -> caracterBase;
	formaTablero[y-1][x-3] = this -> caracterBase;
	formaTablero[y-1][x] = this -> caracterBase;
	formaTablero[y-1][x+1] = this -> caracterBase;
	formaTablero[y-1][x+2] = this -> caracterBase;
	formaTablero[y-1][x+3] = this -> caracterBase;

	/*Pintamos la antena izquierda*/
	formaTablero[y-2][x-2] = this -> caracterBase;
	formaTablero[y-3][x-3] = this -> caracterBase;

	/*Pintamos la antena derecha*/
	formaTablero[y-2][x+2] = this -> caracterBase;
	formaTablero[y-3][x+3] = this -> caracterBase;

	/*Pintamos la parte central izquierda*/
	formaTablero[y][x-1] = this -> caracterBase;
	formaTablero[y][x-3] = this -> caracterBase;
	formaTablero[y][x-4] = this -> caracterBase;

	/*Pintamos la parte central derecha*/
	formaTablero[y][x+1] = this -> caracterBase;
	formaTablero[y][x+3] = this -> caracterBase;
	formaTablero[y][x+4] = this -> caracterBase;

	/*Pintamos la parte inferior del jefe*/
	formaTablero[y+1][x] = this -> caracterBase;
	formaTablero[y+1][x-1] = this -> caracterBase;
	formaTablero[y+1][x-2] = this -> caracterBase;
	formaTablero[y+1][x-3] = this -> caracterBase;
	formaTablero[y+1][x-4] = this -> caracterBase;
	formaTablero[y+1][x-5] = formaJefe[3][0];
	formaTablero[y+1][x+1] = formaJefe[3][6];
	formaTablero[y+1][x+2] = formaJefe[3][7];
	formaTablero[y+1][x+3] = formaJefe[3][8];
	formaTablero[y+1][x+4] = formaJefe[3][9];
	formaTablero[y+1][x+5] = formaJefe[3][10];

	/*Pintamos las piernas y los brazos*/
	formaTablero[y+2][x] = formaJefe[5][5];
	formaTablero[y+2][x-1] = formaJefe[5][4];
	formaTablero[y+2][x-2] = formaJefe[5][3];
	formaTablero[y+2][x-3] = formaJefe[5][2];
	formaTablero[y+2][x-5] = formaJefe[5][0];
	formaTablero[y+2][x+1] = formaJefe[5][6];
	formaTablero[y+2][x+2] = formaJefe[5][7];
	formaTablero[y+2][x+3] = formaJefe[5][8];
	formaTablero[y+2][x+5] = formaJefe[5][10];
	formaTablero[y+3][x-3] = formaJefe[6][2];
	formaTablero[y+3][x-5] = formaJefe[6][0];
	formaTablero[y+3][x+3] = formaJefe[6][8];
	formaTablero[y+3][x+5] = formaJefe[6][10];
	formaTablero[y+4][x-1] = formaJefe[7][4];
	formaTablero[y+4][x-2] = formaJefe[7][3];
	formaTablero[y+4][x+1] = formaJefe[7][6];
	formaTablero[y+4][x+2] = formaJefe[7][7];
}

