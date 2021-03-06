/**!<Guardas de inclusión*/
#ifndef TABLERO_HPP
#define TABLERP_HPP

/**!<Bibliotecas necesarias*/
#include "Figura.hpp"
#include "Jugador.hpp"
#include "Bala.hpp"
#include "Soldado.hpp"
#include "Jefe.hpp"
#include "../Recursos/DLL.hpp"
#include <stdlib.h>
#include <time.h>

/**!<Número de puntos que se dan por soldado derrotado*/
#define puntosSoldado 3

/**
 * @class Tablero
 * @brief Representa el tablero en el cual se pueden
 * mover todas las figuras
 */
class Tablero : public Figura{
	public:
		enum Mensajes{VICTORIA,INSTRUCCIONES,GAMEOVER};
	private:
		/**!<Caracter del fondo del tablero*/
		char caracterBase;

		/**!<Lista de soldados en el tablero*/
		DLL<Soldado*>* soldados;

		/**!<Método que libera la memoria de los soldados que no se hayan matado*/
		static void liberaSoldado(Soldado *S);

		/**!<Número de enemigos por tablero*/
		int numEnemigos;

		/**!<Posición en x de los puntos del jugador en el tablero*/
		int puntosX;

		/**!<Posición en y de los puntos del jugador en el tablero*/
		int puntosY;

		/**!<Posición en x de las vidas del jugador en el tablero*/
		int vidasX;

		/**!<Posición en y de las vidas del jugador en el tablero*/
		int vidasY;

		/**!<Posición en x del nivel*/
		int nivelX;

		/**!<Posición en y del nivel*/
		int nivelY;	

		/**!<Posición en x de la vida del Jefe*/
		int vidaJefeX;

		/**!<Posición en y de la vida dek jefe*/
		int vidaJefeY;

		/**!<Posición en x de los mensaje*/
		int mensajeX;

		/**!<Posición en y de los mensajes*/
		int mensajeY;	

		/**!<Guarda el número anterior de puntos del jugador*/
		int puntosJugador;

		/**!<Número de balas que pueden disparar los soldados*/
		int balasSoldados;

	public:
		/**
		 * @brief Método constructor de Tablero
		 * @param numEnemigos Número de enemigos que tendra el tablero
		 */
		Tablero(int numEnemigos);

		/**
		 * @brief Método destructor de Tablero
		 */
		~Tablero();

		/**
		 *@brief Método que muestar en pantalla el numero de puntos del jugador
		 *@param J Jugador que se mostraran sus puntos
		 */
		void pintaPuntos(Jugador *J);

		/**
		 * @brief Método que se encarga de mostrar el nivel en el que va el juego
		 * @param nivel Nivel a mostrar en la pantalla
		 * @param JefeListo Indica si sale o no el jefe
		 */
		void mostrarNivel(int nivel,bool *JefeListo);

		/**
		 * @brief Método que aumenta el nivel del juego
		 * @param J Jugador del tablero
		 * @param nivel Nivel en el que se va el juego
		 */
		void subirNivel(Jugador *J, int *nivel);

		/**
		 * @brief Método encargado de mostrar mensajes en el tablero
		 * @param Mensaje que se mostrara en el tablero
		 */
		void Mensaje(Tablero::Mensajes Mensaje);

		/**
		 * @brief Método que borra las isntrucciones
		 */
		void borrarInstrucciones();

		/*========Métodos para el jugador========*/

		/**
		 * @brief Método que pinta al jugador
		 * @param J Jugador a pintar en el tablero
		 */
		void pintaJugador(Jugador *J);

		/**
		 * @brief Método que mueve al jugador
		 * @param J Jugador a mover
		 * @param Tecla Tecla pulsada por el jugador
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
		Bala::Choco mueveBala(Jugador *J, Jefe *Je);
		
		/*========Métodos de los soldados========*/

		/**
		 * @brief Método que pinta a los soldados en el tablero
		 */
		void pintaSoldados();

		/**
		 * @brief Método que borra al soldado en el tablero
		 * @param S Soldado que se va a borrar del tablero
		 */
		void borrarSoldado(Soldado *S);

		/**
		 * @brief Método que borra a los soldados del tablero
		 */
		void borrarSoldados();

		/**
		 * @brief Método que mueve a los soldados en el tablero
		 */
		void mueveSoldados();

		/**
		 * @brief Método que hace que disparen los soldados
		 */
		void dispararSoldados();

		/**
		 * @brief Método que mueve las balas de los soldados
		 * @param S Soldado que se moveran sus balas
		 * @param J Jugador del tablero
		 * @return Contra que choco la bala
		 */
		Bala::Choco mueveBala(Soldado *S, Jugador *J);

		/**
		 * @brief Método que mueve el cursor de los soldados al primero de ellos
		 */
		void primerSoldado();

		/**
		 * @brief Método que mueve el cursor de los soldados al siguiente de ellos
		 */
		void siguienteSoldado();

		/**
		 * @brief Método que dice cuantos soldados vivos hay
		 * @return Número de soldados vivos
		 */
		int getNumSoldados();

		/**
		 * @brief Método que retorna al soldado al que apunte el cursor de soldados
		 * @return Soldado al que esta apuntando el cursor de soldados
		 */
		Soldado *getSoldado();

		/*========Métodos para el jefe========*/

		/**
		 * @brief Método que pinta al jefe del juego
		 * @param J Jefe del juego
		 */
		void pintaJefe(Jefe *J);

		/**
		 * @brief Método que borra al jefe del juego
		 * @param J Jefe del juego
		 */
		void borrarJefe(Jefe *J);

		/**
		 * @brief Método que mueve al jefe por el tablero
		 * @param J Jefe del juego
		 */
		void mueveJefe(Jefe *J);

		/**
		 * @brief Método que mostrara la vida del jefe en el tablero
		 * @param J Jefe que se mostrara su vida
		 */
		void mostrarVida(Jefe *J);

		/**
		 * @brief Método que hace que dispare el Jefe
		 * @param J Jefe que disparar las balas
		 */
		void dispararJefe(Jefe *J);

		/**
		 * @brief Método que mueve las balas del enemigo
		 * @param J Jugador del tablero
		 * @param Je Jefe del juego
		 */
		Bala::Choco mueveBalaJefe(Jugador *J, Jefe *Je);

};

#endif
