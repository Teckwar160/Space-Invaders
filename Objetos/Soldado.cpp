/**!<Bibliotecas necesarias*/
#include "Soldado.hpp"

/***************************************
 *	Método privado
 **************************************/
void Soldado::liberaBala(Bala *B){
	delete B;
}

/***************************************
 * 	Métodos publicos
 **************************************/
Soldado::Soldado(int x, int y) : Figura(1){
	/*Definimos el punto de control del soldado*/
	this -> setX(x);
	this -> setY(y);

	/*Creamos el depósito de balas del soldado*/
	this -> deposito = new DLL<Bala*>();
}

Soldado::~Soldado(){
	/*Liberamos la memoria de las balas que no se eliminaron solas*/
	if(this -> getNumBalas() > 0){
		this -> deposito -> Traverse(this -> liberaBala);
	}

	/*Borramos el depósito*/
	delete deposito;
}

bool Soldado::cargarBala(Bala *B){
	this -> deposito -> InsertBack(B);
}

Bala *Soldado::getBala(){
	Bala *tmp;

	this -> deposito -> Peek(&tmp);

	return tmp;
}

void Soldado::borrarBala(){
	Bala *B;

	this -> deposito -> Remove(&B);

	delete B;
}

void Soldado::primerBala(){
	this -> deposito -> CursorFirst();
}

void Soldado::siguienteBala(){
	this -> deposito -> CursorNext();
}

void Soldado::ultimaBala(){
	this -> deposito -> CursorLast();
}

int Soldado::getNumBalas(){
	this -> deposito -> Len();
}

