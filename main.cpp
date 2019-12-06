/**!<Bibliotecas de inclusión*/
#include "Objetos/Tablero.hpp"
#include "Objetos/Jugador.hpp"
#include <curses.h>
int main(){
	initscr();
	Jugador *p = new Jugador();
	Tablero *t = new Tablero();

	t -> pintaJugador(p);
	t -> mostrar();

	while(getch() != '.'){

	}

	delete p;
	delete t;

	endwin();
}
