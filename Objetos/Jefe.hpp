/**!<Guardas de inclusión*/
#ifndef JEFE_HPP
#define JEFE_HPP

/**!<Bibliotecas necesarias*/
#include "Figura.hpp"
#include "../Recursos/DLL.hpp"
#include "Bala.hpp"

/**
 * @class Jefe
 * @brief Representa al enemigo Jefe del juego
 */
class Jefe : public Figura{


	private:
		/**!<Depósito de balas*/
		DLL<Bala*>* deposito;

		/**
		 * @brief Método que libera la memoria de las balas
		 * @param B Bala que se liberara la memoria
		 */
		static void liberaBala(Bala *B);	

		/**!<Vida del Jefe*/
		int vida;
		
	public:
		/**!<Indica el posible movimiento de los enemigos*/
		enum Sentido{DERECHA,IZQUIERDA};

		/**!<Indica el sentido del movimiento del soldado*/
		Jefe::Sentido sentido;

		/**
		 * @brief Método constructor del jefe
		 * @param x Posición en x del jefe
		 * @param y Posición en y del jefe
		 */
		Jefe(int x, int y);

		/**
		 * @brief Método destructor del jefe
		 */
		~Jefe();

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
		 * @brief Método que retorna el numero de balas en el depósito del soldado
		 * @return Numero de balas del depósito
		 */
		int getNumBalas();

		/**
		* @brief Método que permite definir el sentido del movimiento del jefe
		* @param sentido Nuevo Sentido del Jefe
		*/
		void setSentido(Jefe::Sentido sentido);

		/**
		 * @brief Método que nos permite obtener el sentido del Jefe
		 * @return Sentido del movimiento del Jefe
		 */
		Jefe::Sentido getSentido();

		/**
		 * @brief Método que define la vida del jefe
		 * @param vida Nuevo valor de la vida del jefe
		 */
		void setVida(int vida);

		/**
		 * @brief Método que devuelve la vida del Jefe
		 * @return Vida del jefe
 		 */
		int getVida();
};


#endif