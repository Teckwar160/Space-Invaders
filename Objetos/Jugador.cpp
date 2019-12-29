/**!<Bibliotecas necesarias*/
#include "Jugador.hpp"

Jugador::Jugador():Figura(Figura::Sprite::JUGADOR), AdministradorDeBalas(){
	/*Definimos los datos visibles del jugador*/
	this -> vidas = 3;
	this -> puntos = 0;
	this -> disparos = 0;

	/*Definimos el punto de control del jugador*/
	this -> setX(50);
	this -> setY(25);
}

Jugador::~Jugador(){
	/*Destructor vacío*/
}

int Jugador::getVidas(){
	return this -> vidas;
}

void Jugador::setVidas(int vidas){
	this -> vidas = vidas;
}

int Jugador::getPuntos(){
	return this -> puntos;
}

void Jugador::setPuntos(int puntos){
	this -> puntos = puntos;
}

void Jugador::incrementaDisparos(){
	this -> disparos++;
}