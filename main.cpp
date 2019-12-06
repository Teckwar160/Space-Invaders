/**!<Bibliotecas de inclusión*/
#include "Objetos/Tablero.hpp"
#include "Objetos/Jugador.hpp"
int main(){
	Jugador *p = new Jugador();
	
	Tablero *t = new Tablero();
	t -> mostrar();
	t -> pintaJugador(p);
	std::cout <<std::endl;
	t -> mostrar();
	delete p;
	delete t;
}
