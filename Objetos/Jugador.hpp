/**!<Guardas de inclusón*/
#ifndef TABLERO_HPP
#define TABLERO_HPP

/**!<Bibliotecas necesarias*/
#include "Figura.hpp"


class Jugador: public Figura{
	private:
		/**!<Son las vidas del jugador*/
		int vidas;

		/*!<Son los puntos obtenidos por el jugador*/
		int puntos;
		
		/**!<Posición en x del jugador*/
		int x;

		/**!<Posición en y del jugador*/
		int y;
	public:
		/**
		 * @brief Método constructor de figura
		 */
		Jugador();

		/**
		 * @brief Método destructor de figura
		 */
		~Jugador();
};

#endif
