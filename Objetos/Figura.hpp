/**!<Guardas de inclusión*/
#ifndef FIGURA_HPP
#define FIGURA_HPP

/**!<Bibliotecas necesarias*/
#include <iostream>
#include <fstream>
#include <curses.h>

/**
 * @class Figura
 * @brief Representa a cualquier figura
 * del juego
 */
class Figura{
	private:
		/**!<Es la forma que tomara la Figura*/
		char **Forma;

		/**!<Identificador de la figura que representa*/
		int id;

		/**!<Filas de la matriz*/
		int Filas;

		/**!<Columnas de la matriz*/
		int Columnas;

		/**!<Posición en x de la figura*/
		int x;

		/**!<Posición en y de la figura*/
		int y;

	public:
		/**
		 * @brief Método constructor de la Figura
		 * @param id Identificador de la figura
		 */
		Figura(int id);

		/**
		 * @brief Método destructor de la Figura
		 */
		~Figura();

		/**
		 * @brief Método que imprime la figura
		 */
		void mostrar();

		/**
		 * @breif Método que coloca un valor en la posición x
		 * @param x Posición en x de la figura
		 */
		void setX(int x);

		/**
		 * @brief Método que coloca un valor en la posición y
		 * @param y Posición en y de la figura
		 */
		void setY(int y);

		/**
		 * @brief Método que retorna la posición en x de la figura
		 * @return La posición en x de la figura
		 */
		int getX();

		/**
		 * @brief Método que retorna la posción en y de la figura
		 * @return La psoción en y de la figura
		 */
		int getY();

		/**
		 * @brief Método que retorna la forma de la figura
		 * @return Forma de la figura
		 */
		char **getForma();
};

#endif
