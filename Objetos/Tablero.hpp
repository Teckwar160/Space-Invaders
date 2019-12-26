/**!<Guardas de inclusión*/
#ifndef TABLERO_HPP
#define TABLERP_HPP

/**!<Bibliotecas necesarias*/
#include "Figura.hpp"
#include "Jugador.hpp"
#include "Bala.hpp"
#include "Soldado.hpp"
#include "../Recursos/DLL.hpp"
#include <stdlib.h>
#include <time.h>

/**!<Numero de puntos que se dan por soldado derrotado*/
#define puntosSoldado 3

/**
 * @class Tablero
 * @brief Representa el tablero en el cual se pueden
 * mover todas las figuras
 */
class Tablero : public Figura{
	private:
		/**!<Caracter del fondo del tablero*/
		char caracterBase;

		/**!<Lista de soldados en el tablero*/
		DLL<Soldado*>* soldados;

		/**!<Método que libera la memoria de los soldados que no se hayan matado*/
		static void liberaSoldado(Soldado *S);

		/**!<Número de enemigos por tablero*/
		int numEnemigos;

		/**!<Posición en x de los puntos del jugador en el tablero*/
		int puntosX;

		/**!<Posición en y de los puntos del jugador en el tablero*/
		int puntosY;

		/**!<Posición en x de las vidas del jugador en el tablero*/
		int vidasX;

		/**!<Posición en y de las vidas del jugador en el tablero*/
		int vidasY;		

	public:
		/**
		 * @brief Método constructor de Tablero
		 * @param numEnemigos Número de enemigos que tendra el tablero
		 */
		Tablero(int numEnemigos);

		/**
		 * @brief Método destructor de Tablero
		 */
		~Tablero();

		/**
		 *@brief Método que muestar en pantalla el numero de puntos del jugador
		 *@param J Jugador que se mostraran sus puntos
		 */
		void pintaPuntos(Jugador *J);

		/*========Métodos para el jugador========*/

		/**
		 * @brief Método que pinta al jugador
		 * @param J Jugador a pintar en el tablero
		 */
		void pintaJugador(Jugador *J);

		/**
		 * @brief Método que mueve al jugador
		 * @param J Jugador a mover
		 * @param Tecla tecla pulsada por el jugador
		 */
		void mueveJugador(Jugador *J, int Tecla);

		/**
		 * @brief Método que borra al jugador
		 * @param J Jugador a borrar
		 */
		void borrarJugador(Jugador *J);

		/**
		 * @brief Método que pinta una bala
		 * @param B Bala que se va a pintar
		 */
		void pintaBala(Bala *B);

		/**
		 * @brief Método que borra a la bala
		 * @param B Bala que se va a borrar
		 */
		void borrarBala(Bala *B);

		/**
		 * @brief Método que hace que dispare la nave
		 * @param J Jugador que disparara la bala
		 */
		void dispararJugador(Jugador *J);

		/**
		 * @brief Método que mueve la bala en la pantalla
		 * @param J Jugador que disparo la bala
		 * @return Contra que choco la bala
		 */
		int mueveBala(Jugador *J);
		
		/*========Métodos de los soldados========*/

		/**
		 * @brief Método que pinta a los soldados en el tablero
		 */
		void pintaSoldados();

		/**
		 * @brief Método que borra al soldado en el tablero
		 * @param S Soldado que se va a borrar del tablero
		 */
		void borrarSoldado(Soldado *S);

		/**
		 * @brief Método que borra a los soldados del tablero
		 */
		void borrarSoldados();

		/**
		 * @brief Método que mueve al soldado en el tablero
		 * @param S Soldado que se movera en el tablero
		 */
		void mueveSoldados();

		/**
		 * @brief Método que hace que disparen los soldados
		 */
		void dispararSoldados();

		/**
		 * @brief Método que mueve las balas de los soldados
		 * @param S Soldado que se moveran sus balas
		 * @param J Jugador del tablero
		 * @return Contra que choco la bala
		 */
		int mueveBala(Soldado *S, Jugador *J);

		/**
		 * @brief Método que mueve el cursor de los soldados al primero de ellos
		 */
		void primerSoldado();

		/**
		 * @brief Método que mueve el cursor de los soldados al siguiente de ellos
		 */
		void siguienteSoldado();

		/**
		 * @brief Método que dice cuantos soldados vivos hay
		 * @return Numero de soldados vivos
		 */
		int getNumSoldados();

		/**
		 * @brief Método que retorna al soldado al que apunte el cursor de soldados
		 * @return Soldado al que esta apuntando el cursor de soldados
		 */
		Soldado *getSoldado();
};

#endif
