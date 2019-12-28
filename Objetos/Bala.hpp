/**!<Guardas de inclusión*/
#ifndef BALA_HPP
#define BALA_HPP

/**!<Bibliotecas necesarias*/
#include "Figura.hpp"
/**
 * @class Bala
 * @brief Representa a la bala que dispara el jugador y los soldados
 */
class Bala : public Figura{
	public:
		/**!<Indica contra que choco la bala*/
		enum Choco{SOLDADO,MURO,NADA,JUGADOR,BALA,JEFE};
	public:
		/**
		 * @brief Método constructor de bala
		 */
		Bala();

		/**
		 * @brief Método destructor de bala
		 */
		~Bala();
};


#endif
