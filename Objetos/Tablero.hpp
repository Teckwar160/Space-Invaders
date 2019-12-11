/**!<Guardas de inclusión*/
#ifndef TABLERO_HPP
#define TABLERP_HPP

/**!<Bibliotecas necesarias*/
#include "Figura.hpp"
#include "Jugador.hpp"
#include "Bala.hpp"

/**
 * @class Tablero
 * @brief Representa el tablero en el cual se pueden
 * mover todas las figuras
 */
class Tablero : public Figura{
	private:
		/**!<Caracter del fondo del tablero*/
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
		 */
		bool mueveBala(Jugador *J);
};

#endif
