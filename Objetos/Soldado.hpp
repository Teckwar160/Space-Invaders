/**!<Guardas de inclusión*/
#ifndef SOLDADO_HPP
#define SOLDADO_HPP

/**!<Bibliotecas necesarias*/
#include "Figura.hpp"
#include "../Recursos/DLL.hpp"
#include "Bala.hpp"

/**
 * @class Soldado
 * @brief Representa al enemigo simple del juego
 */
class Soldado : public Figura{


	private:
		/**!<Depósito de balas*/
		DLL<Bala*>* deposito;

		/**
		 * @brief Método que libera la memoria de las balas
		 * @param B Bala que se liberara la memoria
		 */
		static void liberaBala(Bala *B);	
		
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
		 * @brief Método que mueve el cursor del depósito a la ultima bala
		 */
		void ultimaBala();

		/**
		 * @brief Método que retorna el numero de balas en el depósito del soldado
		 * @return Numero de balas del depósito
		 */
		int getNumBalas();
};


#endif
