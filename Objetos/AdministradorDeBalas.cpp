/**!<Bibliotecas necesarias*/
#include "AdministradorDeBalas.hpp"

/***************************************
 *	Método privado
 **************************************/
void AdministradorDeBalas::liberaBala(Bala *B){
	delete B;
}

/***************************************
 * 	Métodos publicos
 **************************************/

AdministradorDeBalas::AdministradorDeBalas(){
	/*Creamos el depósito de balas*/
	this -> deposito = new DLL<Bala*>();
}

AdministradorDeBalas::~AdministradorDeBalas(){
	/*Liberamos la memoria de las balas que no se eliminaron solas*/
	if(this -> getNumBalas() > 0){
		this -> deposito -> Traverse(this -> liberaBala);
	}

	/*Borramos el depósito*/
	delete deposito;
}

bool AdministradorDeBalas::cargarBala(Bala *B){
	this -> deposito -> InsertBack(B);
}

Bala *AdministradorDeBalas::getBala(){
	Bala *tmp;

	this -> deposito -> Peek(&tmp);

	return tmp;
}

void AdministradorDeBalas::borrarBala(){
	Bala *B;

	this -> deposito -> Remove(&B);

	delete B;
}

void AdministradorDeBalas::primerBala(){
	this -> deposito -> CursorFirst();
}

void AdministradorDeBalas::siguienteBala(){
	this -> deposito -> CursorNext();
}

int AdministradorDeBalas::getNumBalas(){
	this -> deposito -> Len();
}