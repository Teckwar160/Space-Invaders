/**!<Bibliotecas necesarias*/
#include "Jugador.hpp"

Jugador::Jugador():Figura(0){
	this -> vidas = 3;
	this -> puntos = 0;
	this -> setX(9);
	this -> setY(27);
}

Jugador::~Jugador(){
	std::cout << "Destructor jugador" << std::endl;
}
