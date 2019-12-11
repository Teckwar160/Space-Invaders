/**!<Bibliotecas de inclusión*/
#include "Objetos/Tablero.hpp"
#include "Objetos/Jugador.hpp"
#include <curses.h>

#define BALAS 1000

int main(){
	/**!<Tecla pulsada por el usuario*/
	int Tecla = 0;
	
	/**!<Tablero del juego*/
	Tablero *T;

	/**!<Jugador*/
	Jugador *J;

	/*Iniciamos los componenes del juego*/
	T = new Tablero();
	J = new Jugador();

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
		if(Tecla == 'f'){
			T -> dispararJugador(J);
		}
#if 1
		/*Verificamos que haya balas que mover*/
		J -> primerBala();
		for(int i = J -> getNumBalas(); i>0; i--){
			T -> mueveMunicion(J);
			J -> siguienteBala();
		}	
#endif
		/*Borramos el tablero*/
		erase();
	
	}

	/*Fin del cambio de modo*/
	endwin();

	/*Eliminamos los objetos creados*/

	delete T;
	delete J;
}
