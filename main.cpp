/**!<Bibliotecas de inclusión*/
#include "Objetos/Tablero.hpp"
#include "Objetos/Jugador.hpp"
#include "Objetos/Soldado.hpp"
#include <curses.h>

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

	/*Cargamos a los enemigos en el tablero*/
	T -> pintaSoldados();

	/*Iniciamos el juego*/
	while(J -> getVidas() != 0 && Tecla != '.'){

		/*Mostramos el tablero*/
		T -> mostrar();

		/*Leemos la tecla*/
		Tecla = getch();

		/*Vemos si se quiere mover el jugador*/
		if(Tecla == 'a' || Tecla == 'd'){
			T -> mueveJugador(J,Tecla);
			Tecla = 0;
		}

		/*Vemos si quiere disparar*/
		if(Tecla == 'f'){
			T -> dispararJugador(J);
		}

		/*Ponemos el cursor del deposito del jugador en la primer bala*/
		J -> primerBala();
		
		/*Recorremos todo el deposito moviendo cada bala*/
		for(int i = J -> getNumBalas(); i>0; i--){
			/*Movemos a la bala*/
			T -> mueveBala(J);

			/*Nos movemos a la siguiente bala del deposito*/
			J -> siguienteBala();
		}	

		/*Mueve a los soldados en el tablero*/
		T -> mueveSoldados();

		/*Borramos el tablero*/
		erase();
	
	}

	/*Fin del cambio de modo*/
	endwin();

	/*Eliminamos los objetos creados*/
	delete T;
	delete J;
}
