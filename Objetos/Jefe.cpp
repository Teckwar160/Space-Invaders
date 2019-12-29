/**!<Bibliotecas necesarias*/
#include "Jefe.hpp"

Jefe::Jefe(int x, int y) : Figura(Figura::Sprite::JEFE), AdministradorDeBalas(){
	/*Definimos el punto de control del soldado*/
	this -> setX(x);
	this -> setY(y);

	/*Definimos el sentido*/
	this -> sentido = Jefe::Sentido::DERECHA;

	/*Definimos la vida del Jefe*/
	this -> vida = 150;
}

Jefe::~Jefe(){
	/*Destructor vacío*/
}

void Jefe::setSentido(Jefe::Sentido sentido){
	this -> sentido = sentido;
}

Jefe::Sentido Jefe::getSentido(){
	return this -> sentido;
}

void Jefe::setVida(int vida){
	this -> vida = vida;
}

int Jefe::getVida(){
	return this -> vida;
}

