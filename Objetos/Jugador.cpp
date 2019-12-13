/**!<Bibliotecas necesarias*/
#include "Jugador.hpp"

/***************************************
 *	Método privado
 **************************************/
void Jugador::liberaBala(Bala *B){
	delete B;
}

/***************************************
 * 	Métodos publicos
 **************************************/
Jugador::Jugador():Figura(0){
	this -> vidas = 3;
	this -> puntos = 0;
	this -> setX(50);
	this -> setY(25);
	this -> deposito = new DLL<Bala*>();
	this -> disparos = 0;
}

Jugador::~Jugador(){
	/*Liberamos la memoria de las balas que no se eliminaron solas*/
	if(this -> getNumBalas() > 0){
		this -> deposito -> Traverse(this -> liberaBala);
	}

	/*Borramos el depósito*/
	delete deposito;
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

bool Jugador::cargarBala(Bala *B){
	this -> deposito -> InsertBack(B);
}

Bala *Jugador::getBala(){
	Bala *tmp;

	this -> deposito -> Peek(&tmp);

	return tmp;
}

void Jugador::borrarBala(){
	Bala *B;

	this -> deposito -> Remove(&B);

	delete B;
}

void Jugador::primerBala(){
	this -> deposito -> CursorFirst();
}

void Jugador::siguienteBala(){
	this -> deposito -> CursorNext();
}

void Jugador::ultimaBala(){
	this -> deposito -> CursorLast();
}

int Jugador::getNumBalas(){
	this -> deposito -> Len();
}
