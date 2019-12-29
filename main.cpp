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

	/**!<Jefe del juego*/
	Jefe *Je;

	/**!<Indica si el juego acabo o no*/
	bool gameOver = false;

	/**!<Indica si sale el Jefe o no*/
	bool jefe = false;

	/**!<Indica si se vencio al juego o no*/
	bool victoria = false;

	/**!<Indica el nivel del juego*/
	int nivel = 1;

	/*Iniciamos los componenes del juego*/
	T = new Tablero(5);
	J = new Jugador();
	Je = new Jefe(25,6);

	/*Cambiamos el modo de pantalla para usar curses y la función kbhit*/
	initscr();
    cbreak();
    noecho();
    nodelay(stdscr, TRUE);
    scrollok(stdscr, TRUE);

	/*Cargamos al jugador en el tablero*/
	T -> pintaJugador(J);

	/*Mostramos las instrucciones*/
	T -> Mensaje(Tablero::Mensajes::INSTRUCCIONES);

	/*Mostramos el tablero*/
	T -> mostrar();

	/*Bucle para que no continue el programa*/
	while(getch() != 'e'){
		/*No necesitamos nada aquí*/
	}

	/*Borramos las instrucciones*/
	T -> borrarInstrucciones();

	/*Limpiamos la pantalla*/
	erase();

	/*Cargamos a los enemigos en el tablero*/
	T -> pintaSoldados();

	/*Iniciamos el juego*/
	while(Tecla != 'k' && !gameOver){

		/*Mostramos los puntos del jugador*/
		T -> pintaPuntos(J);

		/*Mostramos el tablero*/
		T -> mostrar();

		/*Mostrar nivel*/
		T -> mostrarNivel(nivel,&jefe);

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
			T -> mueveBala(J,Je);

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

		if(jefe){
			/*Hacemos que dispare el jefe*/
			T -> dispararJefe(Je);

			/*Recorremos toda la lista de balas del jefe si es que esta activo*/

			/*Colocamos el cursor de las balas del depósito del jefe en la primer bala*/
			Je -> primerBala();

			for(size_t i = Je -> getNumBalas(); i>0; i--){
				T -> mueveBalaJefe(J,Je);

				Je -> siguienteBala();
			}

			/*Mostramos la vida del jefe*/
			T -> mostrarVida(Je);

			/*Movemos al Jefe*/
			T -> mueveJefe(Je);
			
			/*Si la vida del jefe se acabo activamos la victoria*/
			if(Je -> getVida() == 0){
				jefe = false;
				victoria = true;

			}
		}


		/*Borramos el tablero*/
		erase();

		/*Dormimos el hilo para que no haga cosas extrañas*/
		std::this_thread::sleep_for (std::chrono::milliseconds(50));

		/*Verificamos que se pueda seguir jugando*/
		if(J -> getVidas() == 0){
			gameOver = true;
		}

		/*Cambia el nivel si se llega a una cantidad de puntos*/
		T -> subirNivel(J,&nivel);

		/*Si gano el jugador*/
		if(victoria){

			/*Borramos al jefe*/
			T -> borrarJefe(Je);

			/*Ponemos los puntos del jugar a todo*/
			J -> setPuntos(9999);

			/*Mostramos el mensaje de victoria*/
			T -> Mensaje(Tablero::Mensajes::VICTORIA);
		}
			
	}

	/*Si el jugador perdio lo mostramos*/
	if(gameOver){

		/*Borramos a los soldados para evitar fallos*/
		T -> borrarSoldados();

		/*Mostramos el mensaje de gameOver*/
		T -> Mensaje(Tablero::Mensajes::GAMEOVER);

		/*Mostramos el tablero*/
		T -> mostrar();

		/*Evitamos que se cierre el juego*/
		while(getch() != 'k'){
			/*No necesitamos nada aquí*/
		}		
	}


	/*Fin del cambio de modo*/
	endwin();

	/*Eliminamos los objetos creados*/
	delete T;
	delete J;
	delete Je;
}
