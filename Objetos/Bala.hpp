/**!<Guardas de inclusión*/
#ifndef BALA_HPP
#define BALA_HPP

/**!<Bibliotecas necesarias*/
#include "Figura.hpp"
/**
 * @class Bala
 * @brief Representa a la bala que dispara el jugador
 */
class Bala : public Figura{
	public:
		/**
		 * @brief Método constructor de bala
		 */
		Bala();

		/**
		 * @brief Método destrucotr de bala
		 */
		~Bala();
};


#endif