/**!<Guardas de inclusión*/
#ifndef SOLDADO_HPP
#define SOLDADO_HPP

/**!<Bibliotecas necesarias*/
#include "Figura.hpp"

/**
 * @class Soldado
 * @brief Representa al enemigo simple del juego
 */
class Soldado : public Figura{
	public:
		enum Sentido{DERECHA,IZQUIERDA};

		/**!<Indica el sentido del movimiento del soldado*/
		static int sentido;

		/**
		 * @brief Método constructor de soldado
		 * @param x Posición en x del soldado
		 * @param y Posición en y del soldado
		 */
		Soldado(int x, int y);

		/**
		 * @brief Método destructor de soldado
		 */
		~Soldado();
};


#endif
