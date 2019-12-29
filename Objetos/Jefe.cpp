/**!<Bibliotecas necesarias*/
#include "Jefe.hpp"

/***************************************
 *	Método privado
 **************************************/
void Jefe::liberaBala(Bala *B){
	delete B;
}

/***************************************
 * 	Métodos publicos
 **************************************/
Jefe::Jefe(int x, int y) : Figura(Figura::Sprite::JEFE){
	/*Definimos el punto de control del soldado*/
	this -> setX(x);
	this -> setY(y);

	/*Creamos el depósito de balas del soldado*/
	this -> deposito = new DLL<Bala*>();

	/*Definimos el sentido*/
	this -> sentido = Jefe::Sentido::DERECHA;

	/*Definimos la vida del Jefe*/
	this -> vida = 150;
}

Jefe::~Jefe(){
	/*Liberamos la memoria de las balas que no se eliminaron solas*/
	if(this -> getNumBalas() > 0){
		this -> deposito -> Traverse(this -> liberaBala);
	}

	/*Borramos el depósito*/
	delete deposito;
}

bool Jefe::cargarBala(Bala *B){
	this -> deposito -> InsertBack(B);
}

Bala *Jefe::getBala(){
	Bala *tmp;

	this -> deposito -> Peek(&tmp);

	return tmp;
}

void Jefe::borrarBala(){
	Bala *B;

	this -> deposito -> Remove(&B);

	delete B;
}

void Jefe::primerBala(){
	this -> deposito -> CursorFirst();
}

void Jefe::siguienteBala(){
	this -> deposito -> CursorNext();
}

int Jefe::getNumBalas(){
	this -> deposito -> Len();
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

