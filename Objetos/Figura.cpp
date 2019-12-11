/**!<Bibliotecas necesarias*/
#include "Figura.hpp"


Figura::Figura(int id){
	/*Definimos el id*/
	this -> id = id;
	this -> x = 0;
	this -> y =0;

	/*Variables necesarias para crear la forma*/
	std::ifstream sprite;
	std::ifstream dimensiones;

	std::string direccionDimension;
	std::string direccionSprite;
	

	/*Dependiendo el id se toman los datos de las figuras*/
	switch(this -> id){
		case 0:
			/*Jugador*/
			direccionSprite = "Sprites/Jugador.txt";
			direccionDimension = "Sprites/dimensionesJugador.txt";
			break;
		case 1:
			/*Enemigo soldado*/
			direccionDimension = "Sprites/dimensionesSoldado.txt";
			break;
		case 2:
			/*Enemigo jefe*/
			direccionDimension = "Sprites/dimensionesJefe.txt";
			break;
		case 3:
			/*Bala*/
			direccionDimension = "Sprites/dimensionesBala.txt";
			break;
		case 4:
			/*Tablero*/
			direccionSprite = "Sprites/Tablero.txt";
			direccionDimension = "Sprites/dimensionesTablero.txt";
			break;
		case 5:
			/*Munición*/
			direccionSprite = "Sprites/Municion.txt";
			direccionDimension = "Sprites/dimensionesMunicion.txt";
			break;
	}

	/*Cargamos las dimensiones de la matriz de la figura*/
	dimensiones.open(direccionDimension,std::ios::in);
	
	if(!dimensiones.fail()){
		
		dimensiones >> this -> Filas;
		dimensiones >> this -> Columnas;

	}else{
		std::cout << "Fallo #0" << std::endl;
	}

	dimensiones.close();

	/*Cargamos los datos de los ficheros*/
	sprite.open(direccionSprite,std::ios::in);

	if(!sprite.fail()){

		/*Creamos la matriz de la figura*/
		this -> Forma = new char*[this -> Filas];

		for(size_t i = 0; i<this -> Filas; i++){
			Forma[i] = new char[this -> Columnas];
		}

		/*Cargamos la figura*/
		for(size_t i = 0; i<this -> Filas; i++){
			for(size_t j = 0; j<this -> Columnas; j++){
				sprite >> this -> Forma[i][j];
			}
		}

	}else{
		std::cout << "Fallo #1" << std::endl;
	}

	sprite.close();
}

Figura::~Figura(){
	/*Liberamos la memoria solicitada*/
	for(size_t i = 0; i< this -> Filas; i++){
		delete this -> Forma[i];
	}

	delete[] this -> Forma;
}

void Figura::mostrar(){
	for(size_t i = 0; i< this -> Filas; i++){
		for(size_t j = 0; j< this -> Columnas; j++){
			printw("%c",this -> Forma[i][j]);
		}
		printw("\n");
	}
}

void Figura::setX(int x){
	this -> x = x;
}

void Figura::setY(int y){
	this -> y = y;
}

int Figura::getX(){
	return this -> x;
}

int Figura::getY(){
	return this -> y;
}

char **Figura::getForma(){
	return this -> Forma;
}

int Figura::getFilas(){
	return this -> Filas;
}

int Figura::getColumnas(){
	return this -> Columnas;
}
