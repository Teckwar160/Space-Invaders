/**!<Guardas de inclusón*/
#ifndef TABLERO_HPP
#define TABLERO_HPP

/**!<Bibliotecas necesarias*/
#include "Figura.hpp"
#include "../Recursos/DLL.hpp"
#include "Bala.hpp"

/**
 * @class Jugador
 * @brief Representa al jugador
 */
class Jugador: public Figura{
	private:
		/**!<Son las vidas del jugador*/
		int vidas;

		/*!<Son los puntos obtenidos por el jugador*/
		int puntos;
		
		/**!<Depósito de balas*/
		DLL<Bala*>* deposito;

		/**!<Contador que lleva el número de balas disparadas*/
		int disparos;

		/**
		 * @brief Método que libera la memoria de las balas
		 * @param B Bala que se eliminara
		 */
		static void liberaBala(Bala *B);	
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

		/**
		 * @brief Método que ingresa una bala al depósito
		 * @param B Bala que se va agregar al depósito
		 * @return true si se logro cargar correctamente, en caso contrario false
		 */
		bool cargarBala(Bala *B);
		
		/**
		 * @brief Método que retorna una bala del depósito
		 * @return Apuntador de bala del depósito
		 */
		Bala *getBala();

		/**
		 * @brief Método que borra una bala del depósito
		 */
		void borrarBala();

		/**
		 * @brief Método que mueve el cursor del depósito a la primer bala
		 */
		void primerBala();

		/**
		 * @brief Método que mueve el cursor del depósito a la siguiente bala
		 */
		void siguienteBala();

		/**
		 * @brief Método que retorna el número de balas en el depósito del jugador
		 * @return Número de balas del depósito
		 */
		int getNumBalas();

};

#endif
