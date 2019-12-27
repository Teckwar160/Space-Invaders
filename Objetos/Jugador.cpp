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
Jugador::Jugador():Figura(Figura::Sprite::JUGADOR){
	/*Definimos los datos visibles del jugador*/
	this -> vidas = 3;
	this -> puntos = 0;
	this -> disparos = 0;

	/*Definimos el punto de control del jugador*/
	this -> setX(50);
	this -> setY(25);

	/*Creamos el depósito de balas del jugador*/
	this -> deposito = new DLL<Bala*>();

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

int Jugador::getNumBalas(){
	this -> deposito -> Len();
}
