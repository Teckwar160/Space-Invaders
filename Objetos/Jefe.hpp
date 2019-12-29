/**!<Guardas de inclusión*/
#ifndef JEFE_HPP
#define JEFE_HPP

/**!<Bibliotecas necesarias*/
#include "Figura.hpp"
#include "AdministradorDeBalas.hpp"

/**
 * @class Jefe
 * @brief Representa al enemigo Jefe del juego
 */
class Jefe : public Figura, public AdministradorDeBalas{

	private:

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