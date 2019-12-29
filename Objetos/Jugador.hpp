/**!<Guardas de inclusón*/
#ifndef TABLERO_HPP
#define TABLERO_HPP

/**!<Bibliotecas necesarias*/
#include "Figura.hpp"
#include "AdministradorDeBalas.hpp"

/**
 * @class Jugador
 * @brief Representa al jugador
 */
class Jugador: public Figura, public AdministradorDeBalas{
	private:
		/**!<Son las vidas del jugador*/
		int vidas;

		/*!<Son los puntos obtenidos por el jugador*/
		int puntos;

		/**!<Contador que lleva el número de balas disparadas*/
		int disparos;

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
		 * @brief Método que retorna el número de vidas del jugador
		 */
		int getVidas();

		/**
		 * @brief Método que define el valor de las vidas del jugador
		 * @param vidas Nuevo número de vidas del jugador
		 */
		void setVidas(int vidas);

		/**
		 * @brief Método que retorna el número de puntos del jugador
		 */
		int getPuntos();

		/**
		 * @brief Método que define el número de puntos del jugador
		 * @param puntos Nuevo número de puntos del jugador
		 */
		void setPuntos(int puntos);

		/**
		 * @brief Método que incrementa los disparos
		 */
		void incrementaDisparos();

};

#endif
