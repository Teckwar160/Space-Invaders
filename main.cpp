/**!<Bibliotecas de inclusión*/
#include "Objetos/Tablero.hpp"
#include "Objetos/Jugador.hpp"
#include <curses.h>
int main(){
	int Tecla;
	initscr();
	Jugador *p = new Jugador();
	Tablero *t = new Tablero();

	t -> pintaJugador(p);
	t -> mostrar();

	while((Tecla = getch()) != '.'){
		erase();
		t -> mueveJugador(p,Tecla);
		t -> mostrar();
	}

	delete p;
	delete t;

	endwin();
}
