/**!<Guardas de inclusión*/
#ifndef TABLERO_HPP
#define TABLERP_HPP

/**!<Bibliotecas necesarias*/
#include "Figura.hpp"
#include "Jugador.hpp"
#include "Bala.hpp"
#include "Soldado.hpp"

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

		/*========Métodos para el jugador========*/

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
		 * @param J Jugador que disparo la bala
		 * @return Contra que choco la bala
		 */
		int mueveBala(Jugador *J);
		
		/*========Métodos de los soldados========*/

		/**
		 * @brief Método que pinta al soldado en el tablero
		 * @param S Soldado que se pintara en el tablero
		 */
		void pintaSoldado(Soldado *S);

		/**
		 * @brief Método que borra al soldado en el tablero
		 * @param S Soldado que se va a borrar del tablero
		 */
		void borrarSoldado(Soldado *S);

		/**
		 * @brief Método que mueve al soldado en el tablero
		 * @param S Sodlado que se movera en el tablero
		 */
		void mueveSoldado(Soldado *S);

};

#endif
