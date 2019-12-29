/**!<Guardas de inclusión*/
#ifndef ADMINISTRADORDEBALAS_HPP
#define ADMINISTRADORDEBALAS_HPP

/**!<Bibliotecas necesarias*/
#include "../Recursos/DLL.hpp"
#include "Bala.hpp"

/**
 * @class AdministradorDeBalas
 * @brief Es el encargado de administrar las balas
 */
class AdministradorDeBalas{
	private:
		/**!<Depósito de balas*/
		DLL<Bala*>* deposito;

		/**
		 * @brief Método que libera la memoria de las balas
		 * @param B Bala que se liberara la memoria
		 */
		static void liberaBala(Bala *B);	

	public:

		/**
		 * @brief Método constructor del AdministradorDeBalas
		 */
		AdministradorDeBalas();

		/**
		 * @brief Método destructor del AdministradorDeBalas
		 */
		~AdministradorDeBalas();

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
		 * @return Número de balas del depósito
		 */
		int getNumBalas();

};


#endif