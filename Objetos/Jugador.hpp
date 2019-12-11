/**!<Guardas de inclusón*/
#ifndef TABLERO_HPP
#define TABLERO_HPP

/**!<Bibliotecas necesarias*/
#include "Figura.hpp"
#include "../Recursos/DLL.hpp"
#include "Municion.hpp"

class Jugador: public Figura{
	private:
		/**!<Son las vidas del jugador*/
		int vidas;

		/*!<Son los puntos obtenidos por el jugador*/
		int puntos;
		
		/**!<Cargador de municiones*/
		DLL<Municion*>* cargador;

		/**!<Contador que lleva el numero de municiones disparadas*/
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

		/**
		 * @brief Método que incrementa los disparos
		 */
		void incrementaDisparos();

		/**
		 * @brief Método que ingresa una munición al cargador
		 * @param M Munición que se va a cargar
		 * @return true si se logro cargar correctamente, en caso contrario false
		 */
		bool cargarMunicion(Municion *M);
		
		/**
		 * @brief Método que retorna una munición del cargador
		 * @return Apuntador de municion en el cargador
		 */
		Municion *getMunicion();

		/**
		 * @brief Método que ve si una munición debe seguir existiendo o no
		 */
		void caminoMunicion();

		/**
		 * @brief Método que indica si hay municiones en el cargador
		 * @return true si hay municiones en el cargador, en caso contrario false
		 */
		bool hayMuniciones();

		/**
		 * @brief Método que borra una bala del deposito
		 */
		void borrarBala();

		/**
		 * @brief Método que mueve el cursor del deposito a la primer bala
		 */
		void primerBala();

		/**
		 * @brief Método que mueve el cursor del deposito a la siguiente bala
		 */
		void siguienteBala();

		/**
		 * @brief Método que mueve el cursor del deposito a la ultima bala
		 */
		void ultimaBala();

		/**
		 * @brief Método que retorna el numero de balas en el deposito del jugador
		 * @return Numero de balas del deposito
		 */
		int getNumBalas();

};

#endif
