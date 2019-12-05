/**!<Guardas de inclusión*/
#ifndef TABLERO_HPP
#define TABLERP_HPP

/**!<Bibliotecas necesarias*/
#include "Figura.hpp"

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
};

#endif
