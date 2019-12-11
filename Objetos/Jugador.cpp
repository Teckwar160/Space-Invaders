/**!<Bibliotecas necesarias*/
#include "Jugador.hpp"

Jugador::Jugador():Figura(0){
	this -> vidas = 3;
	this -> puntos = 0;
	this -> setX(9);
	this -> setY(27);
	this -> cargador = new DLL<Municion*>();
	this -> disparos = 0;
}

Jugador::~Jugador(){
	delete cargador;
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

bool Jugador::cargarMunicion(Municion *M){
	this -> cargador -> InsertBack(M);
}

Municion *Jugador::getMunicion(){
	Municion *tmp;

	this -> cargador -> Peek(&tmp);

	return tmp;
}

void Jugador::caminoMunicion(){
	
}

bool Jugador::hayMuniciones(){
	return !this -> cargador -> IsEmpty();
}

void Jugador::borrarBala(){
	Municion *M;

	this -> cargador -> Remove(&M);

	delete M;
}

void Jugador::primerBala(){
	this -> cargador -> CursorFirst();
}

void Jugador::siguienteBala(){
	this -> cargador -> CursorNext();
}

void Jugador::ultimaBala(){
	this -> cargador -> CursorLast();
}

int Jugador::getNumBalas(){
	this -> cargador -> Len();
}
