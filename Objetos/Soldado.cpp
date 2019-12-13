/**!<Bibliotecas necesarias*/
#include "Soldado.hpp"

Soldado::Soldado(int x, int y) : Figura(1){
	/*Definimos el punto de control del soldado*/
	this -> setX(x);
	this -> setY(y);

	/*Definimos el sentido del movimiento del soldado*/
	this -> sentido = this -> Sentido::DERECHA;
}

Soldado::~Soldado(){
	/*Destructor vacío*/
}

void Soldado::setSentido(int sentido){
	this -> sentido = sentido;
}

int Soldado::getSentido(){
	return this -> sentido;
}
