/**!<Bibliotecas de inclusión*/
#include "Objetos/Tablero.hpp"

int main(){
	Tablero *t = new Tablero();

	t -> mostrar();

	delete t;
}
