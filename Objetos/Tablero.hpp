/**!<Guardas de inclusión*/
#ifndef TABLERO_HPP
#define TABLERP_HPP

/**!<Bibliotecas necesarias*/
#include "Figura.hpp"
#include "Jugador.hpp"
#include "Municion.hpp"

/**
 * @class Tablero
 * @brief Representa el tablero en el cual se pueden
 * mover todas las figuras
 */
class Tablero : public Figura{
	private:
		/*Caracter del fondo del tablero*/
		char caracterBase;
	public:
		/**
		 * @brief Método constructor de Tablero
		 */
		Tablero();

		/**
		 * @brief Método destructor de Tablero
		 */
		~Tablero();

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
		 * @brief Método que pinta una munición
		 * @param M Munición que se va a pintar
		 */
		void pintaMunicion(Municion *M);

		/**
		 * @brief Método que borra a la munición
		 * @param M Munición que se va a borrar
		 */
		void borrarMunicion(Municion *M);

		/**
		 * @brief Método que hace que dispare la nave
		 * @param J Jugador que disparara la munición
		 * @param M Munición que se va a disparar
		 */
		void dispararJugador(Jugador *J);

		/**
		 * @brief Método que mueve la bala en la pantalla
		 * @param M Municiónm que se movera
		 */
		bool mueveMunicion(Jugador *J);
};

#endif
