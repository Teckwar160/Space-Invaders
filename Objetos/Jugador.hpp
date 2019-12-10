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
		
		/**!<Contador de que bala fue disparada*/	
	public:
		/**
		 * @brief Método constructor de figura
		 */
		Jugador();

		/**
		 * @brief Método destructor de figura
		 */
		~Jugador();

		/**
		 * @brief Método que retorna el numero de vidas del jugador
		 */
		int getVidas();

		/**
		 * @brief Método que define el valor de las vidas del jugador
		 * @param vidas Nuevo numero de vidas del jugador
		 */
		void setVidas(int vidas);

		/**
		 * @brief Método que retorna el numero de puntos del jugador
		 */
		int getPuntos();

		/**
		 * @brief Método que define el numero de puntos del jugador
		 * @param puntos Nuevo numero de puntos del jugador
		 */
		void setPuntos(int puntos);
};

#endif
