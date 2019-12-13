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
	private:
		/**!<Indica el sentido del movimiento del soldado*/
		int sentido;

	public:
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

		/**
		 * @brief Método que define el sentido del movimiento del soldado
		 * @param sentido Nuevo sentido de movmiento del soldado
		 */
		void setSentido(int sentido);

		/**
		 * @brief Método que regresa el sentido del movimiento del soldado
		 * @return Sentido del movimiento del soldado
		 */
		int getSentido();
};
#endif
