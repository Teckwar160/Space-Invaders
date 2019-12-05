/**!<Guardas de inclusión*/
#ifndef FIGURA_HPP
#define FIGURA_HPP

/**!<Bibliotecas necesarias*/
#include <iostream>
#include <fstream>

/**
 * @class Figura
 * @brief Representa a cualquier figura
 * capaz de moverse en el tablero
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
};

#endif
