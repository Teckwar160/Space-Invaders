/**!<Bibliotecas de inclusión*/
#include "Objetos/Tablero.hpp"
#include "Objetos/Jugador.hpp"
#include "Objetos/Municion.hpp"
#include <curses.h>

#define BALAS 1000

int main(){
	/**!<Tecla pulsada por el usuario*/
	int Tecla = 0;
	
	/**!<Indica si se disparo o no una bla*/
	bool disparo[BALAS] = {false};

	/**!<Contador de que bala fue disparada*/
	int martillo = 0;

	/**!<Tablero del juego*/
	Tablero *T;

	/**!<Arreglo de municiones del jugador*/
	Municion **Cargador;

	/**!<Jugador*/
	Jugador *J;

	/*Iniciamos los componenes del juego*/
	T = new Tablero();
	J = new Jugador();

	/*Creamos el cargador del jugador*/
	Cargador = new Municion*[BALAS];

	for(size_t i = 0; i<BALAS; i++){
		Cargador[i] = new Municion();
	}

	/*Cambiamos el modo de pantalla para usar curses*/
	initscr();

	/*Cargamos al jugador en el tablero*/
	T -> pintaJugador(J);

	/*Iniciamos el juego*/
	while(J -> getVidas() != 0 && Tecla != '.'){

		/*Mostramos el tablero*/
		T -> mostrar();

		/*Leemos la tecla*/
		Tecla = getch();

		/*Vemos si se quiere mover el jugador*/
		if(Tecla == 'w' || Tecla == 'a' || Tecla == 's' || Tecla == 'd'){
			T -> mueveJugador(J,Tecla);
			Tecla = 0;
		}

		/*Vemos si quiere disparar*/
		if(Tecla == 'f' && martillo != BALAS -1){
			T -> dispararJugador(J,Cargador[martillo]);
			disparo[martillo] = true;
			
			if(martillo < BALAS){
				martillo++;
			}
		}
		
		/*Verificamos que haya balas que mover*/
		if(martillo > 0){
		
			for(size_t i = 0; i< BALAS; i++){
				disparo[i] = T -> mueveMunicion(Cargador[i]);
			}
		}

		/*Borramos el tablero*/
		erase();
	
	}

	/*Fin del cambio de modo*/
	endwin();

	/*Eliminamos los objetos creados*/

	delete T;
	delete J;

	for(size_t i = 0; i< BALAS; i++){
		delete Cargador[i];
	}

	delete[] Cargador;
}
