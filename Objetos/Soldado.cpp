/**!<Bibliotecas necesarias*/
#include "Soldado.hpp"

Soldado::Soldado(int x, int y) : Figura(1){
	/*Definimos el punto de control del soldado*/
	this -> setX(x);
	this -> setY(y);
}

Soldado::~Soldado(){
	/*Destructor vacío*/
}
