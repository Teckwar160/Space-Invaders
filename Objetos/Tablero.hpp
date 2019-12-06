/**!<Guardas de inclusión*/
#ifndef TABLERO_HPP
#define TABLERP_HPP

/**!<Bibliotecas necesarias*/
#include "Figura.hpp"
#include "Jugador.hpp"

/**
 * @class Tablero
 * @brief Representa el tablero en el cual se pueden
 * mover todas las figuras
 */
class Tablero : public Figura{
	private:
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
		 * @param jugador Jugador a pintar en el tablero
		 */
		void pintaJugador(Jugador *J);
};

#endif
