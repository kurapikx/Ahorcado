#include <iostream>
#include <windows.h>
#include <time.h>
#include <string>
using namespace std;

void main() {
	//posem srand()  perque ens deixi randomitzar
	srand(time(NULL));
	//Creem una llista amb un array tipo string de les posibles paraules quepoden sortir de manera hardcodeadas
	string ListaParaules[] = { "hola", "movil", "alarma" };

	//Creem com un contador de les rondes que portem
	short int numRondesJugadas = 0;
	short int numRondesPerdudes = 0;
	short int numRondesGuanyades = numRondesJugadas - numRondesPerdudes;

	//evitem magic number de numero de rondas
	short int numRondesTotals = 3;

	//Bucle de les 3 rondas
	for (int i = 0; i < numRondesTotals; i++)
	{
		//creem un numero random que ens ajudara a decidir quina de les tres paraules sortira.
		short int IndexRandom = rand() % 3; //aquest valor podra ser del 0 al 2.

		//Creem una variable de string que combinant la array de la llista de paraules amb l'indexRandom, em pugui donar la paraula justa que necesito.
		string ParaulaSelecionada = ListaParaules[IndexRandom];

		//Creem una variable tipo char on el numdero del index es igual al maxim numero de caracters que te la paraula mes llarga en aquest cas es "alarma"
		char taulell[6];

		//Numero de intents que te el jugado en funcio dela llargada de la paraula que surti randomitzada
		short int numIntentos = ParaulaSelecionada.length();

		//variable que guardara el input del usuari
		char letra = ' ';

		// bool que nos servira para saber si el input de usuario es adecuat per a seguir amb el codi
		bool puedeSeguir = false;
		
		//creem un taulell amb un bucle for que contengui tants "_", com lletras tinguila paraula,
		
			for (int i = 0; i < ParaulaSelecionada.length(); i++)
			{
				taulell[i] = '_';
			}
			//Mostrem la paraula al principi en un instant.
			system("cls");
			cout << ParaulaSelecionada;
			Sleep(500);
			system("cls");

			while (numIntentos > 0)
			{
				do
				{
					cout << "Dame una letra" << endl;
					cin >> letra;
					//Comprovacio de la lletra, eliminem Key sensitive y comprovem que el input sigui una lletra

					//MAYUS
					if (letra >= 65 && letra <= 90)
					{
						letra = letra + 32;
						puedeSeguir = true;
					}//MINUS
					else if (letra >= 97 && letra <= 122)
					{
						puedeSeguir = true;
					}
					//SI NO ES LETRA
					else
					{
						cout << "ERROR: introduce una letra valida, Le Restan " << numIntentos  << " intentos" << endl;
						puedeSeguir = false;
					}

				} while (!puedeSeguir);

				//creem dos bools per a tenir en compte si es correcte i si es correcte i repetida.
				bool escorrecte = false;
				bool esrepetida = false;
				
				//Comprovacio de si la lletra es corresponent, si es reptida o si no es corresponent
				for (int i = 0; i < ParaulaSelecionada.length(); i++)
				{
					//Cas en que si la lletra concideixi amb la lletra corresponent de la paraula selecionada i a mes a mes en el lloc on hi ha la paraulaen el taulell encara te el '_', voldra dir que es certa
					if (letra == ParaulaSelecionada[i] && taulell[i] == '_')
					{
						taulell[i] = letra;
						cout << taulell[i];
						escorrecte = true;
					}
					//Cas en que la lletra concideixi amb la lletra corresponent de la paraula selecionada, pero en el lloc del taulell es diferent a '_', aixi que hi ha una lletra ja
					else if (letra == ParaulaSelecionada[i] && taulell[i] != '_')
					{
						taulell[i] = letra;
						cout << taulell[i];
						escorrecte = true;
						esrepetida = true;
					}
					//Cas en que la lletra no coincideixi amb la lletra de la paraula
					else
					{
						cout << taulell[i];
					}
				}

				//Resultats i consequencies de quan es correcte, repetida i si no es correcte

				//CAS INCORRECTE
				if (!escorrecte)
				{
					numIntentos = numIntentos - 1;
					cout << endl << "Letra Fallada. Le Restan " << numIntentos << " intentos" << endl;
				}
				

				//CAS REPETIT	
				if (esrepetida == true && escorrecte == true)
				{
					cout << endl << "Letra Repetida. Le Restan " << numIntentos << " intentos" << endl;
					taulell[i];
				}
				//CAS ENCERT	
				else if (escorrecte == true)
				{
					cout << endl << "Letra Correcta. Le Restan " << numIntentos << " intentos" << endl;
					taulell[i];
				}


				//Comprovacio de SI GUANYA O SI PERD la paraula (ronda)

				//CAS FALLAR PARAULA
				if (numIntentos == 0) //Si el jugador es queda sense intents = perdera la paraula.
				{
					numRondesJugadas++;
					numRondesPerdudes++;
					cout << endl << "Te has quedado sin INTENTOS. Has fallado la palabra, Llevas " << numRondesPerdudes << " rondas perdidas y " << numRondesGuanyades << " rondas ganadas" << endl;
					Sleep(4500);
					break;
				}

				//CAS DE ENCERTAR PARAULA

				/*creem una variable int per poder contar les paraules del taulell que no siguin '_' osigui lletras, aixi que dsp podrem comparar que si es te exacatment
				el mateix numero de lletras encertades que el numero de lletras que conte la paraula, podrem afirmar que s ha adivinat la paraula*/
				short int lletrasEncertades = 0;

				for (int i = 0; i < ParaulaSelecionada.length(); i++)
				{
					//Mirem si en els espais del taulell segueixen quedant '_' o son lletras.
					if (taulell[i] != '_')
					{
						lletrasEncertades++; // per a cada lletra que no sigui iguala _, se sumara +1 a la variable lletrasEncertades
					}
				}
				// Si el numero de lletras encertades(caracters que no son '_') son els mateixos que numeros de lletres que te la paraula significara que la paraula s 'ha completat correctament
				if (lletrasEncertades == ParaulaSelecionada.length())
				{
					numRondesJugadas++;
					numRondesGuanyades++;
					cout << endl << "Has adivinado la palabra, Llevas " << numRondesPerdudes << " rondas perdidas y " << numRondesGuanyades << " rondas ganadas" << endl;
					Sleep(4500);
					break;
				}
			}
	
		//Comprovacio de si ha perdut el joc
		if (numRondesPerdudes == 2)
		{
			cout << "------------" << endl;
			cout << "HAS PERDIDO " << endl;
			cout << "------------" << endl;
			break;
		}
		//Comprovacio de si ha guanyat el joc
		if (numRondesGuanyades == 2)
		{
			cout << "------------" << endl;
			cout << "HAS GANADO " << endl;
			cout << "------------" << endl;
			break;
		}
	}
}