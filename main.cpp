/**!<Bibliotecas de inclusión*/

/**!<Objeto Tablero*/
#include "Objetos/Tablero.hpp"

/**!<Objeto Jugador*/
#include "Objetos/Jugador.hpp"

/**!<Objeto Soldado*/
#include "Objetos/Soldado.hpp"

/**!<Biblioteca para moverse en pantalla*/
#include <curses.h>

/**!<Para manejo de hilos*/
#include <thread>        

/**!<Para uso del tiempo*/ 
#include <chrono>

/**
 * @brief Función que checa si se pulso una tecla
 * @return 1 Si si se pulso una tecla 0 en caso contrario
 */
int kbhit()
{
    int ch = getch();
 
    if (ch != ERR) {
        ungetch(ch);
        return 1;
    } else {
        return 0;
    }
}

int main(){
	/**!<Tecla pulsada por el usuario*/
	int Tecla = 0;
	
	/**!<Tablero del juego*/
	Tablero *T;

	/**!<Jugador*/
	Jugador *J;

	/**!<Soldado generico de apoyo*/
	Soldado *S;

	/**!<Indica si el juego acabo o no*/
	bool gameOver = false;

	/*Iniciamos los componenes del juego*/
	T = new Tablero(7);
	J = new Jugador();

	/*Cambiamos el modo de pantalla para usar curses y la función kbhit*/
	initscr();
    cbreak();
    noecho();
    nodelay(stdscr, TRUE);
    scrollok(stdscr, TRUE);

	/*Cargamos al jugador en el tablero*/
	T -> pintaJugador(J);

	/*Cargamos a los enemigos en el tablero*/
	T -> pintaSoldados();

	/*Iniciamos el juego*/
	while(Tecla != '.' && !gameOver){

		/*Mostramos los puntos del jugador*/
		T -> pintaPuntos(J);

		/*Mostramos el tablero*/
		T -> mostrar();

		/*Comprobamos si se pulso una tecla*/
		if(kbhit()){

			/*Leemos la tecla*/
			Tecla = getch();

			/*Vemos si se quiere mover el jugador*/
			if(Tecla == 'a' || Tecla == 'd'){
				T -> mueveJugador(J,Tecla);
				Tecla = 0;
			}

			/*Vemos si quiere disparar*/
			if(Tecla == 'f'){
				T -> dispararJugador(J);
			}
		}

		/*Ponemos el cursor del depósito del jugador en la primer bala*/
		J -> primerBala();
		
		/*Recorremos todo el depósito del jugador moviendo a las balas que disparo*/
		for(int i = J -> getNumBalas(); i>0; i--){
			/*Movemos a la bala*/
			T -> mueveBala(J);

			/*Nos movemos a la siguiente bala del depósito*/
			J -> siguienteBala();
		}	

		/*Mueve a los soldados en el tablero*/
		T -> mueveSoldados();

		/*Hacemos que disparen los enemigos*/
		T -> dispararSoldados();

		/*Movemos las balas de cada soldado*/

		/*Colocamos el cursor de los soldados en el primero*/
		T -> primerSoldado();

		/*Recorremos a todos los soldados*/
		for(size_t i = T -> getNumSoldados(); i>0; i--){
			
			/*Obtenemos al soldado que se moveran sus balas*/
			S = T -> getSoldado();

			/*Colocamos el cursor del depósito de balas del soldado en la primera*/
			S -> primerBala();

			/*Recorremos a todos las balas del soldado*/
			for(size_t j = S -> getNumBalas(); j>0; j--){

				/*Movemos a la bala del soldado*/
				T -> mueveBala(S,J);

				/*Pasamos a la siguiente bala*/
				S -> siguienteBala();
			}

			/*Pasamos al siguiente soldado*/
			T -> siguienteSoldado();
		}

		/*Borramos el tablero*/
		erase();

		/*Dormimos el hilo para que no haga cosas extrañas*/
		std::this_thread::sleep_for (std::chrono::milliseconds(50));

		/*Verificamos que se pueda seguir jugando*/
		if(J -> getVidas() == 0){
			gameOver = true;
		}
	}

	/*Fin del cambio de modo*/
	endwin();

	/*Eliminamos los objetos creados*/
	delete T;
	delete J;
}
