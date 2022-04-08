#include <iostream>
#include <string.h>
#include<stdlib.h>	
#include<time.h>

//clases
class Personaje
{
public:
	Personaje(int, std::string);
	~Personaje();
	void mostrarNombre();
private:
	int edad;
	std::string nombre;
	
};
class NPC : public Personaje
{
public:
	NPC(int, std::string, std::string);
	~NPC();
private:
	std::string trabajo;
};
class PJ : public Personaje
{
public:
	PJ(int, std::string, int, int, int, int);
	~PJ ();
	int getPoderF();
	int getPoderM();
	int getHP();
private:
	int poderF,poderM, HP, defensa; 
};
class Player : public PJ
{
public:
	Player(int, std::string, int, int, int, int, int, int);
	~Player();
	void atacar(int);
	int getDanioP();
	int getSuerte();
private:
	int suerte;
	int danioP;
};
class Villano : public PJ
{
public:
	Villano(int, std::string, int, int, int, int, int, int);
	~Villano();
	void atacarV();
	int getDanioV();
private:
	int boostMaldad;
	int danioV;
};

//constructores y destructores de los objetos
//constructor y destructor de la clase padre personaje
Personaje::Personaje(int _edad, std::string _nombre)
{
	edad = _edad;
	nombre = _nombre;
}
Personaje::~Personaje()
{
}
//constructor y destructor de la clase hijo NPC
NPC::NPC(int _edad, std::string _nombre, std::string _trabajo) : Personaje(_edad, _nombre)
{
	trabajo = _trabajo;
}
NPC::~NPC()
{
}
//constructor y destructor de la clase hija de persona y padre PJ
PJ::PJ(int _edad, std::string _nombre, int _poderF,int _poderM, int _HP, int _defensa) : Personaje(_edad, _nombre)
{
	poderF = _poderF;
	poderM = _poderM;
	HP = _HP;
	defensa = _defensa;
}
PJ::~PJ()
{
}
//constructor y destructor de la clase hija Player
Player::Player(int _edad, std::string _nombre, int _poderF, int _poderM, int _HP, int _defensa, int _suerte, int _danioP) : PJ(_edad, _nombre, _poderF, _poderM, _HP, _defensa)
{
	suerte = _suerte;
	danioP = _danioP;
}
Player::~Player()
{
}
//constructor y destructor de la clase hija Villano
Villano::Villano(int _edad, std::string _nombre, int _poderF, int _poderM, int _HP, int _defensa, int _boostMaldad, int _danioV) : PJ (_edad, _nombre, _poderF, _poderM, _HP, _defensa)
{
	boostMaldad = _boostMaldad;
	danioV = _danioV;
}
Villano::~Villano()
{
}

//metodos de los objetos 
//este es para mostrar el nombre del personaje
void Personaje::mostrarNombre()
{
	std::cout << nombre;
}
//este es un getter para conseguir el numero de poder fisico del personaje
int PJ::getPoderF()
{
	return poderF;
}
//este es un getter para conseguir el numero de poder magico del personaje
int PJ::getPoderM()
{
	return poderM;
}
//metodo para atacar del personaje jugable
void Player::atacar(int suerte)
{
	int opcion;
	std::cout << "Que opcion eliges para atacar?: \n" << "1.Espada.\n" << "2.Magia.\n" << "3.A punio limpio.\n";
	std::cin >> opcion;
	switch (opcion)
	{
	case 1:
		danioP = getPoderF() / 3;
		if (suerte < 3)
		{
			std::cout << "Por tu mala suerte te resbalas y haces menos danio\n";
			danioP -= 2;
		}
		else
		{
			std::cout << "Por tu buena suerte haces mas danio\n";
			danioP += 2;
		}
		std::cout << "Escogiste la espada.\n" << "Haces " << danioP << " de danio" << std::endl;
		break;
	case 2:
		danioP = getPoderM() / 4;
		if (suerte < 3)
		{
			std::cout << "Por tu mala suerte te resbalas y haces menos danio\n";
			danioP -= 2;
		}
		else
		{
			std::cout << "Por tu buena suerte haces mas danio\n";
			danioP += 2;
		}
		std::cout << "Escogiste magia.\n" << "Haces " << danioP << " de danio" << std::endl;
		
		break;
	case 3:
		danioP = getPoderF() / 8;
		if (suerte < 3)
		{
			std::cout << "Por tu mala suerte te resbalas y haces menos danio\n";
			danioP -= 2;
		}
		else
		{
			std::cout << "Por tu buena suerte haces mas danio\n";
			danioP += 2;
		}
		std::cout << "Escogiste el punio (como por?).\n" << "Haces " << danioP << " de danio" << std::endl;
		
		break;
	default:
		std::cout << "Escoge un numero del 1 al 3." << std::endl;
		break;
	}
}
//getter para conseguir el daño que hizo el personaje jugable despues de atacar
int Player::getDanioP()
{
	return danioP;
}
//metodo para atacar del enemigo hacia el personaje jugable
void Villano::atacarV()
{
	srand((unsigned int)time(NULL));
	int opcion = rand() % 2 + 1;
	if (opcion == 1)
	{
		mostrarNombre();
		std::cout << " te esta atacando con su espada.\n";
		danioV = getPoderF() / 4 + boostMaldad;
		mostrarNombre();
		std::cout << " te hace " << danioV << " de danio\n";
	}
	else
	{
		mostrarNombre();
		std::cout << " te esta atacando con magia.\n";
		danioV = (getPoderM() / 3) + boostMaldad;
		mostrarNombre();
		std::cout << " te hace " << danioV << " de danio\n";
	}
}
//getter para conseguir el daño que hizo el enemigo
int Villano::getDanioV()
{
	return danioV;
}
//getter para conseguir la suerte del heroe
int Player::getSuerte()
{
	return suerte;
}
//getter para la vida del personaje
int PJ::getHP()
{
	return HP;
}


//metodos
void Historia();
//main
int main()
{
	Historia();
}

void Historia()
{
	srand((unsigned int)time(NULL));
	int hpV[5], hpJ = 60;
	Villano* malo[5];
	for (int i = 0; i < 5; i++)
	{
		hpV[i] = rand() % 30 + 30;
	}
	std::string nombreP, nombreV;
	malo[0] = new Villano(300, "Biff", 20, 30, hpV[0], 10, 2, 0);
	malo[1] = new Villano(290, "John", 15, 25, hpV[1], 15, 1, 0);
	malo[2] = new Villano(310, "Rai", 13, 28, hpV[2], 12, 1, 0);
	malo[3] = new Villano(270, "Shin", 18, 32, hpV[3], 8, 2, 0);
	malo[4] = new Villano(300, nombreV, 25, 35, hpV[4], 20, 3, 0);
	bool seguir = true, jugando = true;
	int opc = 0, suerte = 2;
	Player* jugador = new Player(300, nombreP, 35, 25, hpJ, 15, suerte, 0);
	
	do
	{
		std::cout << "Hola, bienvenido, aqui empieza tu aventura, primero que nada escoge tu nombre: ";
		std::cin >> nombreP;
		do
		{
			int opcion;
			std::cout << "Ya veo, entonces te llamas: " << nombreP << "\nEstas seguro o quieres cambiarlo?" << "\n1.Seguro.\n2.Cambiarlo\n";
			std::cin >> opcion;
			switch (opcion)
			{
			case 1:
				std::cout << "Okay, sigamos adelante:)\n";
				seguir = false;
				break;
			case 2:
				std::cout << "Okay, cual es tu nombre?:\n ";
				std::cin >> nombreP;
				break;
			default:
				std::cout << "Escoge una opcion valida (1 o 2)\n";
				break;
			}
		} while (seguir);
		seguir = true;
		std::cout << "Es un lindo nombre, ahora escoge el nombre de tu archienemigo: ";
		do
		{
			std::cin >> nombreV;
			std::cout << "Ya veo, entonces asi se llamaba, estas seguro o quieres cambiarlo?\n1.Seguro.\n2.Cambiarlo\n";
			int opcion;
			std::cin >> opcion;
			switch (opcion)
			{
			case 1:
				std::cout << "Okay, sigamos adelante:)\n";
				seguir = false;
				break;
			case 2:
				std::cout << "Okay, cual es su nombre?:\n ";
				std::cin >> nombreP;
				break;
			default:
				std::cout << "Escoge una opcion valida (1 o 2)\n";
				break;
			}
		} while (seguir);
		seguir = true;
		std::cout << "Este es tu nombre y estadisticas hasta el momento:\nNombre: " << nombreP << "\nPoder fisico: 35\nPoder magico: 25\nVida: 60\nDefensa: 15\nSuerte: " << suerte << std::endl;
		std::cout << "Excelente, tu historia comienza!\nNo recuerdas nada, solo sabes que despertaste en este bosque y tienes la extraña sensacion que te estas siguiendo.\nQue haces?\n1.Me quedo.\n2.Empiezo a caminar en busca de pistas.\n";
		std::cin >> opc;
		switch (opc)
		{
		case 1:
			std::cout << "Te has quedado.\nDe la nada oyes unos pasos atras de ti que haces?\n1.Corro\n2.Investigo\n";
			std::cin >> opc;
			switch (opc)
			{
			case 1:
				std::cout << "Corres." << std::endl;
				std::cout << "Pero te caes:(, ves como alguien se acerca, tiene un arma, que haces?\n1.Me levanto y corro\n2.Peleo.\n";
				std::cin >> opc;
				switch (opc)
				{
				case 1:
					std::cout << "Te levantas y corres (por cobarde te quito -1 de suerte)" << std::endl;
					suerte -= 1;
					std::cout << "Al correr te encuentras con una persona herida, que haces?\n1.La ayudo\n2.Sigo corriendo\n";
					std::cin >> opc;
					switch (opc)
					{
					case 1:
						std::cout << "La ayudas, es una sacerdotisa, por tu ayuda te regala +3 de suerte." << std::endl;
						suerte += 3;
						std::cout << "Por ayudarla, te alcanza el enemigo.\nPreparate para luchar." << std::endl;
						opc = 0;
						do
						{
							jugador->atacar(suerte);
							hpV[0] -= jugador->getDanioP();
							std::cout << "Al enemigo le quedan: " << hpV[0] << "puntos de vida." << std::endl;
							malo[0]->atacarV();
							hpJ -= malo[0]->getDanioV();
							std::cout << "Te quedan: " << hpJ << " puntos de vida." << std::endl;
							if (hpJ <= 0)
							{
								opc = 2;
								seguir = false;

							}
							else if (hpV[0] <= 0)
							{
								opc = 1;
								seguir = false;
							}
						} while (seguir);
						switch (opc)
						{
						case 1:
							std::cout << "Has ganado:)))" << std::endl;
							std::cout << "Por ayudarle se ofrece a ayudarte pues te ha visto muy perdido, que haces?\n1.Aceptar la ayuda.\n2.No aceptar la ayuda.\n";
							switch (opc)
							{
							case 1:
								std::cout << "Aceptas la ayuda, mientras le platicas de tu situacion, llega un paladin, parece ser amigo de la sacaerdotisa, despues de presentarse te dice que hay un pueblo cerca.\nQue haces?\n1.Decides ir.\n2.Les dices que acampen.\n";
								std::cin >> opc;
								switch (opc)
								{
								case 1:
									std::cout << "Decides ir al pueblo, despues de un rato de caminar, llegas.\nQue haces?\n1.Buscar algo de comer.\n2.Buscar un lugar donde dormir.\n";
									std::cin >> opc;
									switch (opc)
									{
									case 1:
										std::cout << "Buscan comida, despues de un rato encuentran un puesto de comida ambulante.\nPiden un plato para cado uno." << std::endl;
										std::cout << "Despues de comer te sientes mejor.\n";
										std::cout << "Se escucha un estruendo en el centro del pueblo, que haces?\n1.Vas a ver.\n2.Huyes.\n";
										std::cin >> opc;
										switch (opc)
										{
										case 1:
											std::cout << "Vas a ver." << std::endl;
											std::cout << "Al llegar a la escena te encuentras con alguien que se te hace conocido, se ve fuerte.\nLe ibas a pedir respuestas, pero te interrumpe y te dice: Con que ahi estabas, supongo que no te acordaras de mi, asi que me presento de nuevo, soy: " << nombreV << " y he venido a matarte." << std::endl;
											std::cout << "Continuara...." << std::endl;
											std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
											std::cin >> opc;
											switch (opc)
											{
											case 1:
												jugando = true;
												break;
											case 2:
												jugando = false;
												break;
											default:
												std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
												break;
											}
											break;
										case 2:
											std::cout << "El paladin detiene un intento de asesinato hacie ti, volteas a ver quien fue y..." << std::endl;
											std::cout << "Continuara..." << std::endl;
											std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
											std::cin >> opc;
											switch (opc)
											{
											case 1:
												jugando = true;
												break;
											case 2:
												jugando = false;
												break;
											default:
												std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
												break;
											}
											break;
										default:
											std::cout << "Escoge una opcion valida(1 o 2)" << std::endl;
											break;
										}
										break;
									case 2:
										std::cout << "Buscan un lugar donde dormir, despues de caminar un rato, encuentran donde hospedarse, el paladin paga las habitacion y cada uno va a dormir" << std::endl;
										std::cout << "Al despertar, te encuetras rodeado, ves una cara que se te hace conocida conocida.\nTe dice: Un gusto volvernos a encontrar " << nombreP << " me imagino que no me recordaras, asi que me presento antes de matarte, soy : " << nombreV << std::endl;
										std::cout << nombreV << " te apuniala, mueres." << std::endl;
										std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
										std::cin >> opc;
										switch (opc)
										{
										case 1:
											jugando = true;
											break;
										case 2:
											jugando = false;
											break;
										default:
											std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
											break;
										}
										break;
									default:
										std::cout << "Escoge una opcion valida(1 o 2)" << std::endl;
										break;
									}
									break;
								case 2:
									std::cout << "Decides acampar ahi, despues de un rato dormidos, despiertas y se encuentran rodeados.\n";
									std::cout << "Ves una cara que se te hace conocida conocida.\nTe dice: Un gusto volvernos a encontrar " << nombreP << " me imagino que no me recordaras, asi que me presento antes de matarte, soy : " << nombreV << std::endl;
									std::cout << nombreV << " te apuniala, mueres." << std::endl;
									std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
									std::cin >> opc;
									switch (opc)
									{
									case 1:
										jugando = true;
										break;
									case 2:
										jugando = false;
										break;
									default:
										std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
										break;
									}
									break;
								default:
									std::cout << "Escoge una opcion valida(1 o 2)" << std::endl;
									break;
								}
								break;
							case 2:
								std::cout << "No has aceptado la ayuda, ella lo acepta y te regala un talisman (+3 en suerte y +5 en vida)" << std::endl;
								suerte += 3;
								hpJ += 5;
								std::cout << "Sigues tu camino y encuentras un pueblo.\nTienes hambre.\nQue haces ? \n1.Entro al pueblo.\n2.Paso de largo.\n";
								std::cin >> opc;
								switch (opc)
								{
								case 1:
									std::cout << "Entras al pueblo.\nQue haces?:\n1.Busco comida.\n2.Busco respuestas.\n";
									switch (opc)
									{
									case 1:
										std::cout << "Buscas comida, despues de un rato encuentras un puesto de comida ambulante.\nPides un plato." << std::endl;
										std::cout << "Despues de comer te sientes mejor.\n";
										std::cout << "Se escucha un estruendo en el centro del pueblo, que haces?\n1.Vas a ver.\n2.Huyes.\n";
										std::cin >> opc;
										switch (opc)
										{
										case 1:
											std::cout << "Vas a ver." << std::endl;
											std::cout << "Al llegar a la escena te encuentras con alguien que se te hace conocido, se ve fuerte.\nLe ibas a pedir respuestas, pero te interrumpe y te dice: Con que ahi estabas, supongo que no te acordaras de mi, asi que me presento de nuevo, soy: " << nombreV << " y he venido a matarte." << std::endl;
											std::cout << "Continuara...." << std::endl;
											std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
											std::cin >> opc;
											switch (opc)
											{
											case 1:
												jugando = true;
												break;
											case 2:
												jugando = false;
												break;
											default:
												std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
												break;
											}
											break;
										case 2:
											std::cout << "Sales del pueblo.\nAl salir, sientes como algo se te clava en la esplada, volteas a ver a tu estomago y tienes una espada clavaad, la sacan y caes." << std::endl;
											std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
											std::cin >> opc;
											switch (opc)
											{
											case 1:
												jugando = true;
												break;
											case 2:
												jugando = false;
												break;
											default:
												std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
												break;
											}
											break;
										default:
											std::cout << "Escoge una opcion valida(1 o 2)" << std::endl;
											break;
										}
										break;
									case 2:
										std::cout << "Buscas respuestas, empiezas a caminar y encuentras a alguien que parece ser importante, te acercas." << std::endl;
										std::cout << "Lo saludas y al instante te reconoce: Crei que estaba muerto senior.\nAntes de que le puedas preguntar algo, se escucha un estruendo en el centro del pueblo. La persona con la que estabas hablando corre a ver que pasa y tu lo sigues." << std::endl;
										std::cout << "Al llegar a la escena te encuentras con alguien que se te hace conocido, se ve fuerte.\nLe ibas a pedir respuestas, pero te interrumpe y te dice: Con que ahi estabas, supongo que no te acordaras de mi, asi que me presento de nuevo, soy: " << nombreV << " y he venido a matarte." << std::endl;
										std::cout << "Continuara...." << std::endl;
										std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
										std::cin >> opc;
										switch (opc)
										{
										case 1:
											jugando = true;
											break;
										case 2:
											jugando = false;
											break;
										default:
											std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
											break;
										}
										break;
									default:
										break;
									}
									break;
								case 2:
									std::cout << "Pasas de largo.\nDespues de un rato caminando te desmayas del hambre.\nAl despertar estas rodeado de personas, ves una cara que se te hace conocida conocida.\nTe dice: Un gusto volvernos a encontrar " << nombreP << " me imagino que no me recordaras, asi que me presento antes de matarte, soy: " << nombreV << std::endl;
									std::cout << nombreV << " te apuniala, mueres." << std::endl;
									std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
									std::cin >> opc;
									switch (opc)
									{
									case 1:
										jugando = true;
										break;
									case 2:
										jugando = false;
										break;
									default:
										std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
										break;
									}
									break;
								default:
									std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
									break;
								}
								break;
							default:
								std::cout << "Escoge una opcion valida(1 o 2)" << std::endl;
								break;
							}
						case 2:
							std::cout << "Te han matado:(, se acaba el juego." << std::endl;
							std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
							std::cin >> opc;
							switch (opc)
							{
							case 1:
								jugando = true;
								break;
							case 2:
								jugando = false;
								break;
							default:
								std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
								break;
							}
							break;
						}
						break;
					case 2:
						std::cout << "Has pasado de largo.\nPor no ayudarle te maldice, -3 de suerte.\nQue haces?\n1.Te vengas\n2.Pasas de largo.\n";
						suerte -= 3;
						std::cin >> opc;
						switch (opc)
						{
						case 1:
							std::cout << "Decides vengarte y la matas, te cae una maldicion divina -30 en suerte y -5 en HP" << std::endl;
							hpJ -= 5;
							suerte -= 30;
							opc = 0;
							std::cout << "Escuchas unos pasos detras de ti.\nVes a una persona, parece que te estaba buscansdo, trae un arma y se ve decidido a atacar.\nPreparate para luchar.\n";
							do
							{
								jugador->atacar(suerte);
								hpV[0] -= jugador->getDanioP();
								std::cout << "Al enemigo le quedan: " << hpV[0] << "puntos de vida." << std::endl;
								malo[0]->atacarV();
								hpJ -= malo[0]->getDanioV();
								std::cout << "Te quedan: " << hpJ << " puntos de vida." << std::endl;
								if (hpJ <= 0)
								{
									opc = 2;
									seguir = false;

								}
								else if (hpV[0] <= 0)
								{
									opc = 1;
									seguir = false;
								}
							} while (seguir);
							switch (opc)
							{
							case 1:
								std::cout << "Has ganado:)))" << std::endl;
								std::cout << "Despues de la pelea caminas hacia un lugar seguro y decides descansar un poco para recuperar HP." << std::endl;
								hpJ = 60;
								std::cout << "Al levantarte oyes un caballo acercandose.\nQue haces?\n1.Corro.\n2.Investigo." << std::endl;
								std::cin >> opc;
								switch (opc)
								{
								case 1:
									std::cout << "Has decidido correr\nTal parece que haz hecho mucho ruido y la persona del caballo te ha odio, te empieza a buscar.\n";
									std::cout << "No corres lo suficientemente rapido y te alcanza.\n";
									std::cout << "Te has encontrado con lo que parece ser un paladin.\nTe ve manchado en sangre e inmediatamente te ataca.\nPreparate para luchar.\n";
									opc = 0;
									do
									{
										jugador->atacar(suerte);
										hpV[1] -= jugador->getDanioP();
										std::cout << "Al enemigo le quedan: " << hpV[1] << " puntos de vida." << std::endl;
										malo[1]->atacarV();
										hpJ -= malo[1]->getDanioV();
										std::cout << "Te quedan: " << hpJ << " puntos de vida." << std::endl;
										if (hpJ <= 0)
										{
											opc = 2;
											seguir = false;

										}
										else if (hpV[1] <= 0)
										{
											opc = 1;
											seguir = false;
										}
									} while (seguir);
									switch (opc)
									{
									case 1:
										std::cout << "Has ganado:)))" << std::endl;
										std::cout << "Despues de la pelea caminas hacia un lugar seguro y decides descansar un poco para recuperar HP." << std::endl;
										hpJ = 60;
										std::cout << "Al despertar, vess una cara que se te hace conocida conocida.\nTe dice: Un gusto volvernos a encontrar " << nombreP << " me imagino que no me recordaras, asi que me presento antes de matarte, soy : " << nombreV << std::endl;
										std::cout << nombreV << " te apuniala, mueres." << std::endl;
										std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
										std::cin >> opc;
										switch (opc)
										{
										case 1:
											jugando = true;
											break;
										case 2:
											jugando = false;
											break;
										default:
											std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
											break;
										}
									case 2:
										std::cout << "Te han matado:(, se acaba el juego." << std::endl;
										std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
										std::cin >> opc;
										switch (opc)
										{
										case 1:
											jugando = true;
											break;
										case 2:
											jugando = false;
											break;
										default:
											std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
											break;
										}
										break;
									default:
										std::cout << "Escoge una opcion valida(1 o 2)" << std::endl;
										break;
									}
									break;
								case 2:
									std::cout << "Te has encontrado con lo que parece ser un paladin.\nTe ve manchado en sangre e inmediatamente te ataca.\nPreparate para luchar.\n";
									opc = 0;
									do
									{
										jugador->atacar(suerte);
										hpV[1] -= jugador->getDanioP();
										std::cout << "Al enemigo le quedan: " << hpV[1] << "puntos de vida." << std::endl;
										malo[1]->atacarV();
										hpJ -= malo[1]->getDanioV();
										std::cout << "Te quedan: " << hpJ << " puntos de vida." << std::endl;
										if (hpJ <= 0)
										{
											opc = 2;
											seguir = false;

										}
										else if (hpV[1] <= 0)
										{
											opc = 1;
											seguir = false;
										}
									} while (seguir);
									switch (opc)
									{
									case 1:
										std::cout << "Has ganado:)))" << std::endl;
										std::cout << "Despues de la pelea caminas hacia un lugar seguro y decides descansar un poco para recuperar HP." << std::endl;
										hpJ = 60;
										std::cout << "Despiertas y empiezas a caminar, despues de caminar un rato encuentras un pueblo.\nTienes hambre.\nQue haces ? \n1.Entro al pueblo.\n2.Paso de largo.\n";
										std::cin >> opc;
										switch (opc)
										{
										case 1:
											std::cout << "Entras al pueblo.\nQue haces?:\n1.Busco comida.\n2.Busco respuestas.\n";
											switch (opc)
											{
											case 1:
												std::cout << "Buscas comida, despues de un rato encuentras un puesto de comida ambulante.\nPides un plato." << std::endl;
												std::cout << "Despues de comer te sientes mejor.\n";
												std::cout << "Se escucha un estruendo en el centro del pueblo, que haces?\n1.Vas a ver.\n2.Huyes.\n";
												std::cin >> opc;
												switch (opc)
												{
												case 1:
													std::cout << "Vas a ver." << std::endl;
													std::cout << "Al llegar a la escena te encuentras con alguien que se te hace conocido, se ve fuerte.\nLe ibas a pedir respuestas, pero te interrumpe y te dice: Con que ahi estabas, supongo que no te acordaras de mi, asi que me presento de nuevo, soy: " << nombreV << " y he venido a matarte." << std::endl;
													std::cout << "Continuara...." << std::endl;
													std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
													std::cin >> opc;
													switch (opc)
													{
													case 1:
														jugando = true;
														break;
													case 2:
														jugando = false;
														break;
													default:
														std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
														break;
													}
													break;
												case 2:
													std::cout << "Sales del pueblo.\nAl salir, sientes como algo se te clava en la esplada, volteas a ver a tu estomago y tienes una espada clavaad, la sacan y caes." << std::endl;
													std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
													std::cin >> opc;
													switch (opc)
													{
													case 1:
														jugando = true;
														break;
													case 2:
														jugando = false;
														break;
													default:
														std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
														break;
													}
													break;
												default:
													std::cout << "Escoge una opcion valida(1 o 2)" << std::endl;
													break;
												}
												break;
											case 2:
												std::cout << "Buscas respuestas, empiezas a caminar y encuentras a alguien que parece ser importante, te acercas." << std::endl;
												std::cout << "Lo saludas y al instante te reconoce: Crei que estaba muerto senior.\nAntes de que le puedas preguntar algo, se escucha un estruendo en el centro del pueblo. La persona con la que estabas hablando corre a ver que pasa y tu lo sigues." << std::endl;
												std::cout << "Al llegar a la escena te encuentras con alguien que se te hace conocido, se ve fuerte.\nLe ibas a pedir respuestas, pero te interrumpe y te dice: Con que ahi estabas, supongo que no te acordaras de mi, asi que me presento de nuevo, soy: " << nombreV << " y he venido a matarte." << std::endl;
												std::cout << "Continuara...." << std::endl;
												std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
												std::cin >> opc;
												switch (opc)
												{
												case 1:
													jugando = true;
													break;
												case 2:
													jugando = false;
													break;
												default:
													std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
													break;
												}
												break;
											default:
												break;
											}
											break;
										case 2:
											std::cout << "Pasas de largo.\nDespues de un rato caminando te desmayas del hambre.\nAl despertar estas rodeado de personas, ves una cara que se te hace conocida conocida.\nTe dice: Un gusto volvernos a encontrar " << nombreP << " me imagino que no me recordaras, asi que me presento antes de matarte, soy: " << nombreV << std::endl;
											std::cout << nombreV << " te apuniala, mueres." << std::endl;
											std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
											std::cin >> opc;
											switch (opc)
											{
											case 1:
												jugando = true;
												break;
											case 2:
												jugando = false;
												break;
											default:
												std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
												break;
											}
											break;
										default:
											std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
											break;
										}
										break;
									case 2:
										std::cout << "Te han matado:(, se acaba el juego." << std::endl;
										std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
										std::cin >> opc;
										switch (opc)
										{
										case 1:
											jugando = true;
											break;
										case 2:
											jugando = false;
											break;
										default:
											std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
											break;
										}
										break;
									default:
										std::cout << "Escoge una opcion valida(1 o 2)" << std::endl;
										break;
									}
									break;
								default:
									std::cout << "Escoge una opcion valida(1 o 2)" << std::endl;
									break;
								}
							case 2:
								std::cout << "Te han matado:(, se acaba el juego." << std::endl;
								std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
								std::cin >> opc;
								switch (opc)
								{
								case 1:
									jugando = true;
									break;
								case 2:
									jugando = false;
									break;
								default:
									std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
									break;
								}
								break;
							default:
								std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
								break;
							}
							break;
						case 2:
							std::cout << "Pasas de largo.\nDespues de caminar un rato encuentras un pueblo.\nTienes hambre.\nQue haces?\n1.Entro al pueblo.\n2.Paso de largo.\n";
							std::cin >> opc;
							switch (opc)
							{
							case 1:
								std::cout << "Entras al pueblo.\nQue haces?:\n1.Busco comida.\n2.Busco respuestas.\n";
								switch (opc)
								{
								case 1:
									std::cout << "Buscas comida, despues de un rato encuentras un puesto de comida ambulante.\nPides un plato." << std::endl;
									std::cout << "Despues de comer te sientes mejor.\n";
									std::cout << "Se escucha un estruendo en el centro del pueblo, que haces?\n1.Vas a ver.\n2.Huyes.\n";
									std::cin >> opc;
									switch (opc)
									{
									case 1:
										std::cout << "Vas a ver." << std::endl;
										std::cout << "Al llegar a la escena te encuentras con alguien que se te hace conocido, se ve fuerte.\nLe ibas a pedir respuestas, pero te interrumpe y te dice: Con que ahi estabas, supongo que no te acordaras de mi, asi que me presento de nuevo, soy: " << nombreV << " y he venido a matarte." << std::endl;
										std::cout << "Continuara...." << std::endl;
										std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
										std::cin >> opc;
										switch (opc)
										{
										case 1:
											jugando = true;
											break;
										case 2:
											jugando = false;
											break;
										default:
											std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
											break;
										}
										break;
									case 2:
										std::cout << "Sales del pueblo.\nAl salir, sientes como algo se te clava en la esplada, volteas a ver a tu estomago y tienes una espada clavaad, la sacan y caes." << std::endl;
										std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
										std::cin >> opc;
										switch (opc)
										{
										case 1:
											jugando = true;
											break;
										case 2:
											jugando = false;
											break;
										default:
											std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
											break;
										}
										break;
									default:
										std::cout << "Escoge una opcion valida(1 o 2)" << std::endl;
										break;
									}
									break;
								case 2:
									std::cout << "Buscas respuestas, empiezas a caminar y encuentras a alguien que parece ser importante, te acercas." << std::endl;
									std::cout << "Lo saludas y al instante te reconoce: Crei que estaba muerto senior.\nAntes de que le puedas preguntar algo, se escucha un estruendo en el centro del pueblo. La persona con la que estabas hablando corre a ver que pasa y tu lo sigues." << std::endl;
									std::cout << "Al llegar a la escena te encuentras con alguien que se te hace conocido, se ve fuerte.\nLe ibas a pedir respuestas, pero te interrumpe y te dice: Con que ahi estabas, supongo que no te acordaras de mi, asi que me presento de nuevo, soy: " << nombreV << " y he venido a matarte." << std::endl;
									std::cout << "Continuara...." << std::endl;
									std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
									std::cin >> opc;
									switch (opc)
									{
									case 1:
										jugando = true;
										break;
									case 2:
										jugando = false;
										break;
									default:
										std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
										break;
									}
									break;
								default:
									std::cout << "Escoge una opcion valida(1 o 2)" << std::endl;
									break;
								}
								break;
							case 2:
								std::cout << "Pasas de largo.\nDespues de un rato caminando te desmayas del hambre.\nAl despertar estas rodeado de personas, ves una cara que se te hace conocida conocida.\nTe dice: Un gusto volvernos a encontrar " << nombreP << " me imagino que no me recordaras, asi que me presento antes de matarte, soy: " << nombreV << std::endl;
								std::cout << nombreV << " te apuniala, mueres." << std::endl;
								std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
								std::cin >> opc;
								switch (opc)
								{
								case 1:
									jugando = true;
									break;
								case 2:
									jugando = false;
									break;
								default:
									std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
									break;
								}
								break;
							default:
								std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
								break;
							}
							break;
						default:
							std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
							break;
						}
						break;
					default:
						std::cout << "Escoge una opcion valida (1 o 2)" << std::endl;
						break;
					}
					break;
				case 2:
					std::cout << "Peleas, por valiente te doy +1 en suerte" << std::endl;
					suerte += 1;
					opc = 0;
					do
					{
						jugador->atacar(suerte);
						hpV[0] -= jugador->getDanioP();
						std::cout << "Al enemigo le quedan: " << hpV[0] << "puntos de vida." << std::endl;
						malo[0]->atacarV();
						hpJ -= malo[0]->getDanioV();
						std::cout << "Te quedan: " << hpJ << " puntos de vida." << std::endl;
						opc = 0;
						if (hpJ <= 0)
						{
							opc = 2;
							seguir = false;

						}
						else if (hpV[0] <= 0)
						{
							opc = 1;
							seguir = false;
						}
					} while (seguir);
					switch (opc)
					{
					case 1:
						std::cout << "Has ganado:)))" << std::endl;
						std::cout << "Despues de la pelea decides descansar un poco, recuperas tus HP." << std::endl;
						hpJ = 60;
						std::cout << "Al despertar decides caminar, despues de un rato caminando te encuentras con una persona herida, que haces?\n1.La ayudo\n2.Sigo corriendo\n";
						std::cin >> opc;
						switch (opc)
						{
						case 1:
							std::cout << "La ayudas, es una sacerdotisa, por tu ayuda te regala +3 de suerte." << std::endl;
							suerte += 3;
							std::cout << "Por ayudarla, te alcanza el enemigo.\nPreparate para luchar." << std::endl;
							opc = 0;
							do
							{
								jugador->atacar(suerte);
								hpV[0] -= jugador->getDanioP();
								std::cout << "Al enemigo le quedan: " << hpV[0] << "puntos de vida." << std::endl;
								malo[0]->atacarV();
								hpJ -= malo[0]->getDanioV();
								std::cout << "Te quedan: " << hpJ << " puntos de vida." << std::endl;
								if (hpJ <= 0)
								{
									opc = 2;
									seguir = false;

								}
								else if (hpV[0] <= 0)
								{
									opc = 1;
									seguir = false;
								}
							} while (seguir);
							switch (opc)
							{
							case 1:
								std::cout << "Has ganado:)))" << std::endl;
								std::cout << "Por ayudarle se ofrece a ayudarte pues te ha visto muy perdido, que haces?\n1.Aceptar la ayuda.\n2.No aceptar la ayuda.\n";
								switch (opc)
								{
								case 1:
									std::cout << "Aceptas la ayuda, mientras le platicas de tu situacion, llega un paladin, parece ser amigo de la sacaerdotisa, despues de presentarse te dice que hay un pueblo cerca.\nQue haces?\n1.Decides ir.\n2.Les dices que acampen.\n";
									std::cin >> opc;
									switch (opc)
									{
									case 1:
										std::cout << "Decides ir al pueblo, despues de un rato de caminar, llegas.\nQue haces?\n1.Buscar algo de comer.\n2.Buscar un lugar donde dormir.\n";
										std::cin >> opc;
										switch (opc)
										{
										case 1:
											std::cout << "Buscan comida, despues de un rato encuentran un puesto de comida ambulante.\nPiden un plato para cado uno." << std::endl;
											std::cout << "Despues de comer te sientes mejor.\n";
											std::cout << "Se escucha un estruendo en el centro del pueblo, que haces?\n1.Vas a ver.\n2.Huyes.\n";
											std::cin >> opc;
											switch (opc)
											{
											case 1:
												std::cout << "Vas a ver." << std::endl;
												std::cout << "Al llegar a la escena te encuentras con alguien que se te hace conocido, se ve fuerte.\nLe ibas a pedir respuestas, pero te interrumpe y te dice: Con que ahi estabas, supongo que no te acordaras de mi, asi que me presento de nuevo, soy: " << nombreV << " y he venido a matarte." << std::endl;
												std::cout << "Continuara...." << std::endl;
												std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
												std::cin >> opc;
												switch (opc)
												{
												case 1:
													jugando = true;
													break;
												case 2:
													jugando = false;
													break;
												default:
													std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
													break;
												}
												break;
											case 2:
												std::cout << "El paladin detiene un intento de asesinato hacie ti, volteas a ver quien fue y..." << std::endl;
												std::cout << "Continuara..." << std::endl;
												std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
												std::cin >> opc;
												switch (opc)
												{
												case 1:
													jugando = true;
													break;
												case 2:
													jugando = false;
													break;
												default:
													std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
													break;
												}
												break;
											default:
												std::cout << "Escoge una opcion valida(1 o 2)" << std::endl;
												break;
											}
											break;
										case 2:
											std::cout << "Buscan un lugar donde dormir, despues de caminar un rato, encuentran donde hospedarse, el paladin paga las habitacion y cada uno va a dormir" << std::endl;
											std::cout << "Al despertar, te encuetras rodeado, ves una cara que se te hace conocida conocida.\nTe dice: Un gusto volvernos a encontrar " << nombreP << " me imagino que no me recordaras, asi que me presento antes de matarte, soy : " << nombreV << std::endl;
											std::cout << nombreV << " te apuniala, mueres." << std::endl;
											std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
											std::cin >> opc;
											switch (opc)
											{
											case 1:
												jugando = true;
												break;
											case 2:
												jugando = false;
												break;
											default:
												std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
												break;
											}
											break;
										default:
											std::cout << "Escoge una opcion valida(1 o 2)" << std::endl;
											break;
										}
										break;
									case 2:
										std::cout << "Decides acampar ahi, despues de un rato dormidos, despiertas y se encuentran rodeados.\n";
										std::cout << "Ves una cara que se te hace conocida conocida.\nTe dice: Un gusto volvernos a encontrar " << nombreP << " me imagino que no me recordaras, asi que me presento antes de matarte, soy : " << nombreV << std::endl;
										std::cout << nombreV << " te apuniala, mueres." << std::endl;
										std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
										std::cin >> opc;
										switch (opc)
										{
										case 1:
											jugando = true;
											break;
										case 2:
											jugando = false;
											break;
										default:
											std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
											break;
										}
										break;
									default:
										std::cout << "Escoge una opcion valida(1 o 2)" << std::endl;
										break;
									}
									break;
								case 2:
									std::cout << "No has aceptado la ayuda, ella lo acepta y te regala un talisman (+3 en suerte y +5 en vida)" << std::endl;
									suerte += 3;
									hpJ += 5;
									std::cout << "Sigues tu camino y encuentras un pueblo.\nTienes hambre.\nQue haces ? \n1.Entro al pueblo.\n2.Paso de largo.\n";
									std::cin >> opc;
									switch (opc)
									{
									case 1:
										std::cout << "Entras al pueblo.\nQue haces?:\n1.Busco comida.\n2.Busco respuestas.\n";
										switch (opc)
										{
										case 1:
											std::cout << "Buscas comida, despues de un rato encuentras un puesto de comida ambulante.\nPides un plato." << std::endl;
											std::cout << "Despues de comer te sientes mejor.\n";
											std::cout << "Se escucha un estruendo en el centro del pueblo, que haces?\n1.Vas a ver.\n2.Huyes.\n";
											std::cin >> opc;
											switch (opc)
											{
											case 1:
												std::cout << "Vas a ver." << std::endl;
												std::cout << "Al llegar a la escena te encuentras con alguien que se te hace conocido, se ve fuerte.\nLe ibas a pedir respuestas, pero te interrumpe y te dice: Con que ahi estabas, supongo que no te acordaras de mi, asi que me presento de nuevo, soy: " << nombreV << " y he venido a matarte." << std::endl;
												std::cout << "Continuara...." << std::endl;
												std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
												std::cin >> opc;
												switch (opc)
												{
												case 1:
													jugando = true;
													break;
												case 2:
													jugando = false;
													break;
												default:
													std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
													break;
												}
												break;
											case 2:
												std::cout << "Sales del pueblo.\nAl salir, sientes como algo se te clava en la esplada, volteas a ver a tu estomago y tienes una espada clavaad, la sacan y caes." << std::endl;
												std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
												std::cin >> opc;
												switch (opc)
												{
												case 1:
													jugando = true;
													break;
												case 2:
													jugando = false;
													break;
												default:
													std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
													break;
												}
												break;
											default:
												std::cout << "Escoge una opcion valida(1 o 2)" << std::endl;
												break;
											}
											break;
										case 2:
											std::cout << "Buscas respuestas, empiezas a caminar y encuentras a alguien que parece ser importante, te acercas." << std::endl;
											std::cout << "Lo saludas y al instante te reconoce: Crei que estaba muerto senior.\nAntes de que le puedas preguntar algo, se escucha un estruendo en el centro del pueblo. La persona con la que estabas hablando corre a ver que pasa y tu lo sigues." << std::endl;
											std::cout << "Al llegar a la escena te encuentras con alguien que se te hace conocido, se ve fuerte.\nLe ibas a pedir respuestas, pero te interrumpe y te dice: Con que ahi estabas, supongo que no te acordaras de mi, asi que me presento de nuevo, soy: " << nombreV << " y he venido a matarte." << std::endl;
											std::cout << "Continuara...." << std::endl;
											std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
											std::cin >> opc;
											switch (opc)
											{
											case 1:
												jugando = true;
												break;
											case 2:
												jugando = false;
												break;
											default:
												std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
												break;
											}
											break;
										default:
											break;
										}
										break;
									case 2:
										std::cout << "Pasas de largo.\nDespues de un rato caminando te desmayas del hambre.\nAl despertar estas rodeado de personas, ves una cara que se te hace conocida conocida.\nTe dice: Un gusto volvernos a encontrar " << nombreP << " me imagino que no me recordaras, asi que me presento antes de matarte, soy: " << nombreV << std::endl;
										std::cout << nombreV << " te apuniala, mueres." << std::endl;
										std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
										std::cin >> opc;
										switch (opc)
										{
										case 1:
											jugando = true;
											break;
										case 2:
											jugando = false;
											break;
										default:
											std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
											break;
										}
										break;
									default:
										std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
										break;
									}
									break;
								default:
									std::cout << "Escoge una opcion valida(1 o 2)" << std::endl;
									break;
								}
							case 2:
								std::cout << "Te han matado:(, se acaba el juego." << std::endl;
									std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
	std::cin >> opc;
	switch (opc)
	{
	case 1:
		jugando = true;
		break;
	case 2:
		jugando = false;
		break;
	default:
		std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
		break;
	}
								break;
							}
							break;
						case 2:
							std::cout << "Has pasado de largo.\nPor no ayudarle te maldice, -3 de suerte.\nQue haces?\n1.Te vengas\n2.Pasas de largo.\n";
							suerte -= 3;
							std::cin >> opc;
							switch (opc)
							{
							case 1:
								std::cout << "Decides vengarte y la matas, te cae una maldicion divina -30 en suerte y -5 en HP" << std::endl;
								hpJ -= 5;
								suerte -= 30;
								opc = 0;
								std::cout << "Escuchas unos pasos detras de ti.\nVes a una persona, parece que te estaba buscansdo, trae un arma y se ve decidido a atacar.\nPreparate para luchar.\n";
								do
								{
									jugador->atacar(suerte);
									hpV[0] -= jugador->getDanioP();
									std::cout << "Al enemigo le quedan: " << hpV[0] << "puntos de vida." << std::endl;
									malo[0]->atacarV();
									hpJ -= malo[0]->getDanioV();
									std::cout << "Te quedan: " << hpJ << " puntos de vida." << std::endl;
									if (hpJ <= 0)
									{
										opc = 2;
										seguir = false;

									}
									else if (hpV[0] <= 0)
									{
										opc = 1;
										seguir = false;
									}
								} while (seguir);
								switch (opc)
								{
								case 1:
									std::cout << "Has ganado:)))" << std::endl;
									std::cout << "Despues de la pelea caminas hacia un lugar seguro y decides descansar un poco para recuperar HP." << std::endl;
									hpJ = 60;
									std::cout << "Al levantarte oyes un caballo acercandose.\nQue haces?\n1.Corro.\n2.Investigo." << std::endl;
									std::cin >> opc;
									switch (opc)
									{
									case 1:
										std::cout << "Has decidido correr\nTal parece que haz hecho mucho ruido y la persona del caballo te ha odio, te empieza a buscar.\n";
										std::cout << "No corres lo suficientemente rapido y te alcanza.\n";
										std::cout << "Te has encontrado con lo que parece ser un paladin.\nTe ve manchado en sangre e inmediatamente te ataca.\nPreparate para luchar.\n";
										opc = 0;
										do
										{
											jugador->atacar(suerte);
											hpV[1] -= jugador->getDanioP();
											std::cout << "Al enemigo le quedan: " << hpV[1] << " puntos de vida." << std::endl;
											malo[1]->atacarV();
											hpJ -= malo[1]->getDanioV();
											std::cout << "Te quedan: " << hpJ << " puntos de vida." << std::endl;
											if (hpJ <= 0)
											{
												opc = 2;
												seguir = false;

											}
											else if (hpV[1] <= 0)
											{
												opc = 1;
												seguir = false;
											}
										} while (seguir);
										switch (opc)
										{
										case 1:
											std::cout << "Has ganado:)))" << std::endl;
											std::cout << "Despues de la pelea caminas hacia un lugar seguro y decides descansar un poco para recuperar HP." << std::endl;
											hpJ = 60;
											std::cout << "Al despertar, vess una cara que se te hace conocida conocida.\nTe dice: Un gusto volvernos a encontrar " << nombreP << " me imagino que no me recordaras, asi que me presento antes de matarte, soy : " << nombreV << std::endl;
											std::cout << nombreV << " te apuniala, mueres." << std::endl;
											std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
											std::cin >> opc;
											switch (opc)
											{
											case 1:
												jugando = true;
												break;
											case 2:
												jugando = false;
												break;
											default:
												std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
												break;
											}
										case 2:
											std::cout << "Te han matado:(, se acaba el juego." << std::endl;
											std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
											std::cin >> opc;
											switch (opc)
											{
											case 1:
												jugando = true;
												break;
											case 2:
												jugando = false;
												break;
											default:
												std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
												break;
											}
											break;
										default:
											std::cout << "Escoge una opcion valida(1 o 2)" << std::endl;
											break;
										}
										break;
									case 2:
										std::cout << "Te has encontrado con lo que parece ser un paladin.\nTe ve manchado en sangre e inmediatamente te ataca.\nPreparate para luchar.\n";
										opc = 0;
										do
										{
											jugador->atacar(suerte);
											hpV[1] -= jugador->getDanioP();
											std::cout << "Al enemigo le quedan: " << hpV[1] << "puntos de vida." << std::endl;
											malo[1]->atacarV();
											hpJ -= malo[1]->getDanioV();
											std::cout << "Te quedan: " << hpJ << " puntos de vida." << std::endl;
											if (hpJ <= 0)
											{
												opc = 2;
												seguir = false;

											}
											else if (hpV[1] <= 0)
											{
												opc = 1;
												seguir = false;
											}
										} while (seguir);
										switch (opc)
										{
										case 1:
											std::cout << "Has ganado:)))" << std::endl;
											std::cout << "Despues de la pelea caminas hacia un lugar seguro y decides descansar un poco para recuperar HP." << std::endl;
											hpJ = 60;
											std::cout << "Despiertas y empiezas a caminar, despues de caminar un rato encuentras un pueblo.\nTienes hambre.\nQue haces ? \n1.Entro al pueblo.\n2.Paso de largo.\n";
											std::cin >> opc;
											switch (opc)
											{
											case 1:
												std::cout << "Entras al pueblo.\nQue haces?:\n1.Busco comida.\n2.Busco respuestas.\n";
												switch (opc)
												{
												case 1:
													std::cout << "Buscas comida, despues de un rato encuentras un puesto de comida ambulante.\nPides un plato." << std::endl;
													std::cout << "Despues de comer te sientes mejor.\n";
													std::cout << "Se escucha un estruendo en el centro del pueblo, que haces?\n1.Vas a ver.\n2.Huyes.\n";
													std::cin >> opc;
													switch (opc)
													{
													case 1:
														std::cout << "Vas a ver." << std::endl;
														std::cout << "Al llegar a la escena te encuentras con alguien que se te hace conocido, se ve fuerte.\nLe ibas a pedir respuestas, pero te interrumpe y te dice: Con que ahi estabas, supongo que no te acordaras de mi, asi que me presento de nuevo, soy: " << nombreV << " y he venido a matarte." << std::endl;
														std::cout << "Continuara...." << std::endl;
														std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
														std::cin >> opc;
														switch (opc)
														{
														case 1:
															jugando = true;
															break;
														case 2:
															jugando = false;
															break;
														default:
															std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
															break;
														}
														break;
													case 2:
														std::cout << "Sales del pueblo.\nAl salir, sientes como algo se te clava en la esplada, volteas a ver a tu estomago y tienes una espada clavaad, la sacan y caes." << std::endl;
														std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
														std::cin >> opc;
														switch (opc)
														{
														case 1:
															jugando = true;
															break;
														case 2:
															jugando = false;
															break;
														default:
															std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
															break;
														}
														break;
													default:
														std::cout << "Escoge una opcion valida(1 o 2)" << std::endl;
														break;
													}
													break;
												case 2:
													std::cout << "Buscas respuestas, empiezas a caminar y encuentras a alguien que parece ser importante, te acercas." << std::endl;
													std::cout << "Lo saludas y al instante te reconoce: Crei que estaba muerto senior.\nAntes de que le puedas preguntar algo, se escucha un estruendo en el centro del pueblo. La persona con la que estabas hablando corre a ver que pasa y tu lo sigues." << std::endl;
													std::cout << "Al llegar a la escena te encuentras con alguien que se te hace conocido, se ve fuerte.\nLe ibas a pedir respuestas, pero te interrumpe y te dice: Con que ahi estabas, supongo que no te acordaras de mi, asi que me presento de nuevo, soy: " << nombreV << " y he venido a matarte." << std::endl;
													std::cout << "Continuara...." << std::endl;
													std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
													std::cin >> opc;
													switch (opc)
													{
													case 1:
														jugando = true;
														break;
													case 2:
														jugando = false;
														break;
													default:
														std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
														break;
													}
													break;
												default:
													break;
												}
												break;
											case 2:
												std::cout << "Pasas de largo.\nDespues de un rato caminando te desmayas del hambre.\nAl despertar estas rodeado de personas, ves una cara que se te hace conocida conocida.\nTe dice: Un gusto volvernos a encontrar " << nombreP << " me imagino que no me recordaras, asi que me presento antes de matarte, soy: " << nombreV << std::endl;
												std::cout << nombreV << " te apuniala, mueres." << std::endl;
												std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
												std::cin >> opc;
												switch (opc)
												{
												case 1:
													jugando = true;
													break;
												case 2:
													jugando = false;
													break;
												default:
													std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
													break;
												}
												break;
											default:
												std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
												break;
											}
											break;
										case 2:
											std::cout << "Te han matado:(, se acaba el juego." << std::endl;
											std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
											std::cin >> opc;
											switch (opc)
											{
											case 1:
												jugando = true;
												break;
											case 2:
												jugando = false;
												break;
											default:
												std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
												break;
											}
											break;
										default:
											std::cout << "Escoge una opcion valida(1 o 2)" << std::endl;
											break;
										}
										break;
									default:
										std::cout << "Escoge una opcion valida(1 o 2)" << std::endl;
										break;
									}
								case 2:
									std::cout << "Te han matado:(, se acaba el juego." << std::endl;
									std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
									std::cin >> opc;
									switch (opc)
									{
									case 1:
										jugando = true;
										break;
									case 2:
										jugando = false;
										break;
									default:
										std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
										break;
									}
									break;
								default:
									std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
									break;
								}
								break;
							case 2:
								std::cout << "Pasas de largo.\nDespues de caminar un rato encuentras un pueblo.\nTienes hambre.\nQue haces?\n1.Entro al pueblo.\n2.Paso de largo.\n";
								std::cin >> opc;
								switch (opc)
								{
								case 1:
									std::cout << "Entras al pueblo.\nQue haces?:\n1.Busco comida.\n2.Busco respuestas.\n";
									switch (opc)
									{
									case 1:
										std::cout << "Buscas comida, despues de un rato encuentras un puesto de comida ambulante.\nPides un plato." << std::endl;
										std::cout << "Despues de comer te sientes mejor.\n";
										std::cout << "Se escucha un estruendo en el centro del pueblo, que haces?\n1.Vas a ver.\n2.Huyes.\n";
										std::cin >> opc;
										switch (opc)
										{
										case 1:
											std::cout << "Vas a ver." << std::endl;
											std::cout << "Al llegar a la escena te encuentras con alguien que se te hace conocido, se ve fuerte.\nLe ibas a pedir respuestas, pero te interrumpe y te dice: Con que ahi estabas, supongo que no te acordaras de mi, asi que me presento de nuevo, soy: " << nombreV << " y he venido a matarte." << std::endl;
											std::cout << "Continuara...." << std::endl;
											std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
											std::cin >> opc;
											switch (opc)
											{
											case 1:
												jugando = true;
												break;
											case 2:
												jugando = false;
												break;
											default:
												std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
												break;
											}
											break;
										case 2:
											std::cout << "Sales del pueblo.\nAl salir, sientes como algo se te clava en la esplada, volteas a ver a tu estomago y tienes una espada clavaad, la sacan y caes." << std::endl;
											std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
											std::cin >> opc;
											switch (opc)
											{
											case 1:
												jugando = true;
												break;
											case 2:
												jugando = false;
												break;
											default:
												std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
												break;
											}
											break;
										default:
											std::cout << "Escoge una opcion valida(1 o 2)" << std::endl;
											break;
										}
										break;
									case 2:
										std::cout << "Buscas respuestas, empiezas a caminar y encuentras a alguien que parece ser importante, te acercas." << std::endl;
										std::cout << "Lo saludas y al instante te reconoce: Crei que estaba muerto senior.\nAntes de que le puedas preguntar algo, se escucha un estruendo en el centro del pueblo. La persona con la que estabas hablando corre a ver que pasa y tu lo sigues." << std::endl;
										std::cout << "Al llegar a la escena te encuentras con alguien que se te hace conocido, se ve fuerte.\nLe ibas a pedir respuestas, pero te interrumpe y te dice: Con que ahi estabas, supongo que no te acordaras de mi, asi que me presento de nuevo, soy: " << nombreV << " y he venido a matarte." << std::endl;
										std::cout << "Continuara...." << std::endl;
										std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
										std::cin >> opc;
										switch (opc)
										{
										case 1:
											jugando = true;
											break;
										case 2:
											jugando = false;
											break;
										default:
											std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
											break;
										}
										break;
									default:
										std::cout << "Escoge una opcion valida(1 o 2)" << std::endl;
										break;
									}
									break;
								case 2:
									std::cout << "Pasas de largo.\nDespues de un rato caminando te desmayas del hambre.\nAl despertar estas rodeado de personas, ves una cara que se te hace conocida conocida.\nTe dice: Un gusto volvernos a encontrar " << nombreP << " me imagino que no me recordaras, asi que me presento antes de matarte, soy: " << nombreV << std::endl;
									std::cout << nombreV << " te apuniala, mueres." << std::endl;
									std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
									std::cin >> opc;
									switch (opc)
									{
									case 1:
										jugando = true;
										break;
									case 2:
										jugando = false;
										break;
									default:
										std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
										break;
									}
									break;
								default:
									std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
									break;
								}
								break;
							default:
								std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
								break;
							}
							break;
						default:
							std::cout << "Escoge una opcion valida (1 o 2)" << std::endl;
							break;
						}
						break;
					case 2:
						std::cout << "Te han matado:(, se acaba el juego." << std::endl;
						std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
						std::cin >> opc;
						switch (opc)
						{
						case 1:
							jugando = true;
							break;
						case 2:
							jugando = false;
							break;
						default:
							std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
							break;
						}
						break;
					}
					break;
				default:
					std::cout << "Escoge una opcion valida(1 o 2)" << std::endl;
					break;
				}
				break;
			case 2: 
				std::cout << "Decides investigar.\nTe has encontrado con una persona, parece que te estaba buscansdo, trae un arma y se ve decidido a atacar.\nPreparate para luchar.\n";
				opc = 0;
				do
				{
					jugador->atacar(suerte);
					hpV[0] -= jugador->getDanioP();
					std::cout << "Al enemigo le quedan: " << hpV[0] << "puntos de vida." << std::endl;
					malo[0]->atacarV();
					hpJ -= malo[0]->getDanioV();
					std::cout << "Te quedan: " << hpJ << " puntos de vida." << std::endl;
					if (hpJ <= 0)
					{
						opc = 2;
						seguir = false;

					}
					else if (hpV[0] <= 0)
					{
						opc = 1;
						seguir = false;
					}
				} while (seguir);
				switch (opc)
				{
				case 1:
					std::cout << "Has ganado:)))" << std::endl;
					std::cout << "Despues de la pelea decides descansar un poco, recuperas tus HP." << std::endl;
					hpJ = 60;
					std::cout << "Al despertar decides caminar, despues de un rato caminando te encuentras con una persona herida, que haces?\n1.La ayudo\n2.Sigo corriendo\n";
					std::cin >> opc;
					switch (opc)
					{
					case 1:
						std::cout << "La ayudas, es una sacerdotisa, por tu ayuda te regala +3 de suerte." << std::endl;
						suerte += 3;
						std::cout << "Por ayudarla, te alcanza el enemigo.\nPreparate para luchar." << std::endl;
						opc = 0;
						do
						{
							jugador->atacar(suerte);
							hpV[0] -= jugador->getDanioP();
							std::cout << "Al enemigo le quedan: " << hpV[0] << "puntos de vida." << std::endl;
							malo[0]->atacarV();
							hpJ -= malo[0]->getDanioV();
							std::cout << "Te quedan: " << hpJ << " puntos de vida." << std::endl;
							if (hpJ <= 0)
							{
								opc = 2;
								seguir = false;

							}
							else if (hpV[0] <= 0)
							{
								opc = 1;
								seguir = false;
							}
						} while (seguir);
						switch (opc)
						{
						case 1:
							std::cout << "Has ganado:)))" << std::endl;
							std::cout << "Por ayudarle se ofrece a ayudarte pues te ha visto muy perdido, que haces?\n1.Aceptar la ayuda.\n2.No aceptar la ayuda.\n";
							switch (opc)
							{
							case 1:
								std::cout << "Aceptas la ayuda, mientras le platicas de tu situacion, llega un paladin, parece ser amigo de la sacaerdotisa, despues de presentarse te dice que hay un pueblo cerca.\nQue haces?\n1.Decides ir.\n2.Les dices que acampen.\n";
								std::cin >> opc;
								switch (opc)
								{
								case 1:
									std::cout << "Decides ir al pueblo, despues de un rato de caminar, llegas.\nQue haces?\n1.Buscar algo de comer.\n2.Buscar un lugar donde dormir.\n";
									std::cin >> opc;
									switch (opc)
									{
									case 1:
										std::cout << "Buscan comida, despues de un rato encuentran un puesto de comida ambulante.\nPiden un plato para cado uno." << std::endl;
										std::cout << "Despues de comer te sientes mejor.\n";
										std::cout << "Se escucha un estruendo en el centro del pueblo, que haces?\n1.Vas a ver.\n2.Huyes.\n";
										std::cin >> opc;
										switch (opc)
										{
										case 1:
											std::cout << "Vas a ver." << std::endl;
											std::cout << "Al llegar a la escena te encuentras con alguien que se te hace conocido, se ve fuerte.\nLe ibas a pedir respuestas, pero te interrumpe y te dice: Con que ahi estabas, supongo que no te acordaras de mi, asi que me presento de nuevo, soy: " << nombreV << " y he venido a matarte." << std::endl;
											std::cout << "Continuara...." << std::endl;
											std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
											std::cin >> opc;
											switch (opc)
											{
											case 1:
												jugando = true;
												break;
											case 2:
												jugando = false;
												break;
											default:
												std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
												break;
											}
											break;
										case 2:
											std::cout << "El paladin detiene un intento de asesinato hacie ti, volteas a ver quien fue y..." << std::endl;
											std::cout << "Continuara..." << std::endl;
											std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
											std::cin >> opc;
											switch (opc)
											{
											case 1:
												jugando = true;
												break;
											case 2:
												jugando = false;
												break;
											default:
												std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
												break;
											}
											break;
										default:
											std::cout << "Escoge una opcion valida(1 o 2)" << std::endl;
											break;
										}
										break;
									case 2:
										std::cout << "Buscan un lugar donde dormir, despues de caminar un rato, encuentran donde hospedarse, el paladin paga las habitacion y cada uno va a dormir" << std::endl;
										std::cout << "Al despertar, te encuetras rodeado, ves una cara que se te hace conocida conocida.\nTe dice: Un gusto volvernos a encontrar " << nombreP << " me imagino que no me recordaras, asi que me presento antes de matarte, soy : " << nombreV << std::endl;
										std::cout << nombreV << " te apuniala, mueres." << std::endl;
										std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
										std::cin >> opc;
										switch (opc)
										{
										case 1:
											jugando = true;
											break;
										case 2:
											jugando = false;
											break;
										default:
											std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
											break;
										}
										break;
									default:
										std::cout << "Escoge una opcion valida(1 o 2)" << std::endl;
										break;
									}
									break;
								case 2:
									std::cout << "Decides acampar ahi, despues de un rato dormidos, despiertas y se encuentran rodeados.\n";
									std::cout << "Ves una cara que se te hace conocida conocida.\nTe dice: Un gusto volvernos a encontrar " << nombreP << " me imagino que no me recordaras, asi que me presento antes de matarte, soy : " << nombreV << std::endl;
									std::cout << nombreV << " te apuniala, mueres." << std::endl;
									std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
									std::cin >> opc;
									switch (opc)
									{
									case 1:
										jugando = true;
										break;
									case 2:
										jugando = false;
										break;
									default:
										std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
										break;
									}
									break;
								default:
									std::cout << "Escoge una opcion valida(1 o 2)" << std::endl;
									break;
								}
								break;
							case 2:
								std::cout << "No has aceptado la ayuda, ella lo acepta y te regala un talisman (+3 en suerte y +5 en vida)" << std::endl;
								suerte += 3;
								hpJ += 5;
								std::cout << "Sigues tu camino y encuentras un pueblo.\nTienes hambre.\nQue haces ? \n1.Entro al pueblo.\n2.Paso de largo.\n";
								std::cin >> opc;
								switch (opc)
								{
								case 1:
									std::cout << "Entras al pueblo.\nQue haces?:\n1.Busco comida.\n2.Busco respuestas.\n";
									switch (opc)
									{
									case 1:
										std::cout << "Buscas comida, despues de un rato encuentras un puesto de comida ambulante.\nPides un plato." << std::endl;
										std::cout << "Despues de comer te sientes mejor.\n";
										std::cout << "Se escucha un estruendo en el centro del pueblo, que haces?\n1.Vas a ver.\n2.Huyes.\n";
										std::cin >> opc;
										switch (opc)
										{
										case 1:
											std::cout << "Vas a ver." << std::endl;
											std::cout << "Al llegar a la escena te encuentras con alguien que se te hace conocido, se ve fuerte.\nLe ibas a pedir respuestas, pero te interrumpe y te dice: Con que ahi estabas, supongo que no te acordaras de mi, asi que me presento de nuevo, soy: " << nombreV << " y he venido a matarte." << std::endl;
											std::cout << "Continuara...." << std::endl;
											std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
											std::cin >> opc;
											switch (opc)
											{
											case 1:
												jugando = true;
												break;
											case 2:
												jugando = false;
												break;
											default:
												std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
												break;
											}
											break;
										case 2:
											std::cout << "Sales del pueblo.\nAl salir, sientes como algo se te clava en la esplada, volteas a ver a tu estomago y tienes una espada clavaad, la sacan y caes." << std::endl;
											std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
											std::cin >> opc;
											switch (opc)
											{
											case 1:
												jugando = true;
												break;
											case 2:
												jugando = false;
												break;
											default:
												std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
												break;
											}
											break;
										default:
											std::cout << "Escoge una opcion valida(1 o 2)" << std::endl;
											break;
										}
										break;
									case 2:
										std::cout << "Buscas respuestas, empiezas a caminar y encuentras a alguien que parece ser importante, te acercas." << std::endl;
										std::cout << "Lo saludas y al instante te reconoce: Crei que estaba muerto senior.\nAntes de que le puedas preguntar algo, se escucha un estruendo en el centro del pueblo. La persona con la que estabas hablando corre a ver que pasa y tu lo sigues." << std::endl;
										std::cout << "Al llegar a la escena te encuentras con alguien que se te hace conocido, se ve fuerte.\nLe ibas a pedir respuestas, pero te interrumpe y te dice: Con que ahi estabas, supongo que no te acordaras de mi, asi que me presento de nuevo, soy: " << nombreV << " y he venido a matarte." << std::endl;
										std::cout << "Continuara...." << std::endl;
										std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
										std::cin >> opc;
										switch (opc)
										{
										case 1:
											jugando = true;
											break;
										case 2:
											jugando = false;
											break;
										default:
											std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
											break;
										}
										break;
									default:
										break;
									}
									break;
								case 2:
									std::cout << "Pasas de largo.\nDespues de un rato caminando te desmayas del hambre.\nAl despertar estas rodeado de personas, ves una cara que se te hace conocida conocida.\nTe dice: Un gusto volvernos a encontrar " << nombreP << " me imagino que no me recordaras, asi que me presento antes de matarte, soy: " << nombreV << std::endl;
									std::cout << nombreV << " te apuniala, mueres." << std::endl;
									std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
									std::cin >> opc;
									switch (opc)
									{
									case 1:
										jugando = true;
										break;
									case 2:
										jugando = false;
										break;
									default:
										std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
										break;
									}
									break;
								default:
									std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
									break;
								}
								break;
							default:
								std::cout << "Escoge una opcion valida(1 o 2)" << std::endl;
								break;
							}
						case 2:
							std::cout << "Te han matado:(, se acaba el juego." << std::endl;
							std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
							std::cin >> opc;
							switch (opc)
							{
							case 1:
								jugando = true;
								break;
							case 2:
								jugando = false;
								break;
							default:
								std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
								break;
							}
							break;
						}
						break;
					case 2:
						std::cout << "Has pasado de largo.\nPor no ayudarle te maldice, -3 de suerte.\nQue haces?\n1.Te vengas\n2.Pasas de largo.\n";
						suerte -= 3;
						std::cin >> opc;
						switch (opc)
						{
						case 1:
							std::cout << "Decides vengarte y la matas, te cae una maldicion divina -30 en suerte y -5 en HP" << std::endl;
							hpJ -= 5;
							suerte -= 30;
							opc = 0;
							std::cout << "Escuchas unos pasos detras de ti.\nVes a una persona, parece que te estaba buscansdo, trae un arma y se ve decidido a atacar.\nPreparate para luchar.\n";
							do
							{
								jugador->atacar(suerte);
								hpV[0] -= jugador->getDanioP();
								std::cout << "Al enemigo le quedan: " << hpV[0] << "puntos de vida." << std::endl;
								malo[0]->atacarV();
								hpJ -= malo[0]->getDanioV();
								std::cout << "Te quedan: " << hpJ << " puntos de vida." << std::endl;
								if (hpJ <= 0)
								{
									opc = 2;
									seguir = false;

								}
								else if (hpV[0] <= 0)
								{
									opc = 1;
									seguir = false;
								}
							} while (seguir);
							switch (opc)
							{
							case 1:
								std::cout << "Has ganado:)))" << std::endl;
								std::cout << "Despues de la pelea caminas hacia un lugar seguro y decides descansar un poco para recuperar HP." << std::endl;
								hpJ = 60;
								std::cout << "Al levantarte oyes un caballo acercandose.\nQue haces?\n1.Corro.\n2.Investigo." << std::endl;
								std::cin >> opc;
								switch (opc)
								{
								case 1:
									std::cout << "Has decidido correr\nTal parece que haz hecho mucho ruido y la persona del caballo te ha odio, te empieza a buscar.\n";
									std::cout << "No corres lo suficientemente rapido y te alcanza.\n";
									std::cout << "Te has encontrado con lo que parece ser un paladin.\nTe ve manchado en sangre e inmediatamente te ataca.\nPreparate para luchar.\n";
									opc = 0;
									do
									{
										jugador->atacar(suerte);
										hpV[1] -= jugador->getDanioP();
										std::cout << "Al enemigo le quedan: " << hpV[1] << " puntos de vida." << std::endl;
										malo[1]->atacarV();
										hpJ -= malo[1]->getDanioV();
										std::cout << "Te quedan: " << hpJ << " puntos de vida." << std::endl;
										if (hpJ <= 0)
										{
											opc = 2;
											seguir = false;

										}
										else if (hpV[1] <= 0)
										{
											opc = 1;
											seguir = false;
										}
									} while (seguir);
									switch (opc)
									{
									case 1:
										std::cout << "Has ganado:)))" << std::endl;
										std::cout << "Despues de la pelea caminas hacia un lugar seguro y decides descansar un poco para recuperar HP." << std::endl;
										hpJ = 60;
										std::cout << "Al despertar, vess una cara que se te hace conocida conocida.\nTe dice: Un gusto volvernos a encontrar " << nombreP << " me imagino que no me recordaras, asi que me presento antes de matarte, soy : " << nombreV << std::endl;
										std::cout << nombreV << " te apuniala, mueres." << std::endl;
										std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
										std::cin >> opc;
										switch (opc)
										{
										case 1:
											jugando = true;
											break;
										case 2:
											jugando = false;
											break;
										default:
											std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
											break;
										}
									case 2:
										std::cout << "Te han matado:(, se acaba el juego." << std::endl;
										std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
										std::cin >> opc;
										switch (opc)
										{
										case 1:
											jugando = true;
											break;
										case 2:
											jugando = false;
											break;
										default:
											std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
											break;
										}
										break;
									default:
										std::cout << "Escoge una opcion valida(1 o 2)" << std::endl;
										break;
									}
									break;
								case 2:
									std::cout << "Te has encontrado con lo que parece ser un paladin.\nTe ve manchado en sangre e inmediatamente te ataca.\nPreparate para luchar.\n";
									opc = 0;
									do
									{
										jugador->atacar(suerte);
										hpV[1] -= jugador->getDanioP();
										std::cout << "Al enemigo le quedan: " << hpV[1] << "puntos de vida." << std::endl;
										malo[1]->atacarV();
										hpJ -= malo[1]->getDanioV();
										std::cout << "Te quedan: " << hpJ << " puntos de vida." << std::endl;
										if (hpJ <= 0)
										{
											opc = 2;
											seguir = false;

										}
										else if (hpV[1] <= 0)
										{
											opc = 1;
											seguir = false;
										}
									} while (seguir);
									switch (opc)
									{
									case 1:
										std::cout << "Has ganado:)))" << std::endl;
										std::cout << "Despues de la pelea caminas hacia un lugar seguro y decides descansar un poco para recuperar HP." << std::endl;
										hpJ = 60;
										std::cout << "Despiertas y empiezas a caminar, despues de caminar un rato encuentras un pueblo.\nTienes hambre.\nQue haces ? \n1.Entro al pueblo.\n2.Paso de largo.\n";
										std::cin >> opc;
										switch (opc)
										{
										case 1:
											std::cout << "Entras al pueblo.\nQue haces?:\n1.Busco comida.\n2.Busco respuestas.\n";
											switch (opc)
											{
											case 1:
												std::cout << "Buscas comida, despues de un rato encuentras un puesto de comida ambulante.\nPides un plato." << std::endl;
												std::cout << "Despues de comer te sientes mejor.\n";
												std::cout << "Se escucha un estruendo en el centro del pueblo, que haces?\n1.Vas a ver.\n2.Huyes.\n";
												std::cin >> opc;
												switch (opc)
												{
												case 1:
													std::cout << "Vas a ver." << std::endl;
													std::cout << "Al llegar a la escena te encuentras con alguien que se te hace conocido, se ve fuerte.\nLe ibas a pedir respuestas, pero te interrumpe y te dice: Con que ahi estabas, supongo que no te acordaras de mi, asi que me presento de nuevo, soy: " << nombreV << " y he venido a matarte." << std::endl;
													std::cout << "Continuara...." << std::endl;
													std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
													std::cin >> opc;
													switch (opc)
													{
													case 1:
														jugando = true;
														break;
													case 2:
														jugando = false;
														break;
													default:
														std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
														break;
													}
													break;
												case 2:
													std::cout << "Sales del pueblo.\nAl salir, sientes como algo se te clava en la esplada, volteas a ver a tu estomago y tienes una espada clavaad, la sacan y caes." << std::endl;
													std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
													std::cin >> opc;
													switch (opc)
													{
													case 1:
														jugando = true;
														break;
													case 2:
														jugando = false;
														break;
													default:
														std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
														break;
													}
													break;
												default:
													std::cout << "Escoge una opcion valida(1 o 2)" << std::endl;
													break;
												}
												break;
											case 2:
												std::cout << "Buscas respuestas, empiezas a caminar y encuentras a alguien que parece ser importante, te acercas." << std::endl;
												std::cout << "Lo saludas y al instante te reconoce: Crei que estaba muerto senior.\nAntes de que le puedas preguntar algo, se escucha un estruendo en el centro del pueblo. La persona con la que estabas hablando corre a ver que pasa y tu lo sigues." << std::endl;
												std::cout << "Al llegar a la escena te encuentras con alguien que se te hace conocido, se ve fuerte.\nLe ibas a pedir respuestas, pero te interrumpe y te dice: Con que ahi estabas, supongo que no te acordaras de mi, asi que me presento de nuevo, soy: " << nombreV << " y he venido a matarte." << std::endl;
												std::cout << "Continuara...." << std::endl;
												std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
												std::cin >> opc;
												switch (opc)
												{
												case 1:
													jugando = true;
													break;
												case 2:
													jugando = false;
													break;
												default:
													std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
													break;
												}
												break;
											default:
												break;
											}
											break;
										case 2:
											std::cout << "Pasas de largo.\nDespues de un rato caminando te desmayas del hambre.\nAl despertar estas rodeado de personas, ves una cara que se te hace conocida conocida.\nTe dice: Un gusto volvernos a encontrar " << nombreP << " me imagino que no me recordaras, asi que me presento antes de matarte, soy: " << nombreV << std::endl;
											std::cout << nombreV << " te apuniala, mueres." << std::endl;
											std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
											std::cin >> opc;
											switch (opc)
											{
											case 1:
												jugando = true;
												break;
											case 2:
												jugando = false;
												break;
											default:
												std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
												break;
											}
											break;
										default:
											std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
											break;
										}
										break;
									case 2:
										std::cout << "Te han matado:(, se acaba el juego." << std::endl;
										std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
										std::cin >> opc;
										switch (opc)
										{
										case 1:
											jugando = true;
											break;
										case 2:
											jugando = false;
											break;
										default:
											std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
											break;
										}
										break;
									default:
										std::cout << "Escoge una opcion valida(1 o 2)" << std::endl;
										break;
									}
									break;
								default:
									std::cout << "Escoge una opcion valida(1 o 2)" << std::endl;
									break;
								}
							case 2:
								std::cout << "Te han matado:(, se acaba el juego." << std::endl;
								std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
								std::cin >> opc;
								switch (opc)
								{
								case 1:
									jugando = true;
									break;
								case 2:
									jugando = false;
									break;
								default:
									std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
									break;
								}
								break;
							default:
								std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
								break;
							}
							break;
						case 2:
							std::cout << "Pasas de largo.\nDespues de caminar un rato encuentras un pueblo.\nTienes hambre.\nQue haces?\n1.Entro al pueblo.\n2.Paso de largo.\n";
							std::cin >> opc;
							switch (opc)
							{
							case 1:
								std::cout << "Entras al pueblo.\nQue haces?:\n1.Busco comida.\n2.Busco respuestas.\n";
								switch (opc)
								{
								case 1:
									std::cout << "Buscas comida, despues de un rato encuentras un puesto de comida ambulante.\nPides un plato." << std::endl;
									std::cout << "Despues de comer te sientes mejor.\n";
									std::cout << "Se escucha un estruendo en el centro del pueblo, que haces?\n1.Vas a ver.\n2.Huyes.\n";
									std::cin >> opc;
									switch (opc)
									{
									case 1:
										std::cout << "Vas a ver." << std::endl;
										std::cout << "Al llegar a la escena te encuentras con alguien que se te hace conocido, se ve fuerte.\nLe ibas a pedir respuestas, pero te interrumpe y te dice: Con que ahi estabas, supongo que no te acordaras de mi, asi que me presento de nuevo, soy: " << nombreV << " y he venido a matarte." << std::endl;
										std::cout << "Continuara...." << std::endl;
										std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
										std::cin >> opc;
										switch (opc)
										{
										case 1:
											jugando = true;
											break;
										case 2:
											jugando = false;
											break;
										default:
											std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
											break;
										}
										break;
									case 2:
										std::cout << "Sales del pueblo.\nAl salir, sientes como algo se te clava en la esplada, volteas a ver a tu estomago y tienes una espada clavaad, la sacan y caes." << std::endl;
										std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
										std::cin >> opc;
										switch (opc)
										{
										case 1:
											jugando = true;
											break;
										case 2:
											jugando = false;
											break;
										default:
											std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
											break;
										}
										break;
									default:
										std::cout << "Escoge una opcion valida(1 o 2)" << std::endl;
										break;
									}
									break;
								case 2:
									std::cout << "Buscas respuestas, empiezas a caminar y encuentras a alguien que parece ser importante, te acercas." << std::endl;
									std::cout << "Lo saludas y al instante te reconoce: Crei que estaba muerto senior.\nAntes de que le puedas preguntar algo, se escucha un estruendo en el centro del pueblo. La persona con la que estabas hablando corre a ver que pasa y tu lo sigues." << std::endl;
									std::cout << "Al llegar a la escena te encuentras con alguien que se te hace conocido, se ve fuerte.\nLe ibas a pedir respuestas, pero te interrumpe y te dice: Con que ahi estabas, supongo que no te acordaras de mi, asi que me presento de nuevo, soy: " << nombreV << " y he venido a matarte." << std::endl;
									std::cout << "Continuara...." << std::endl;
									std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
									std::cin >> opc;
									switch (opc)
									{
									case 1:
										jugando = true;
										break;
									case 2:
										jugando = false;
										break;
									default:
										std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
										break;
									}
									break;
								default:
									std::cout << "Escoge una opcion valida(1 o 2)" << std::endl;
									break;
								}
								break;
							case 2:
								std::cout << "Pasas de largo.\nDespues de un rato caminando te desmayas del hambre.\nAl despertar estas rodeado de personas, ves una cara que se te hace conocida conocida.\nTe dice: Un gusto volvernos a encontrar " << nombreP << " me imagino que no me recordaras, asi que me presento antes de matarte, soy: " << nombreV << std::endl;
								std::cout << nombreV << " te apuniala, mueres." << std::endl;
								std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
								std::cin >> opc;
								switch (opc)
								{
								case 1:
									jugando = true;
									break;
								case 2:
									jugando = false;
									break;
								default:
									std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
									break;
								}
								break;
							default:
								std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
								break;
							}
							break;
						default:
							std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
							break;
						}
						break;
					default:
						std::cout << "Escoge una opcion valida (1 o 2)" << std::endl;
						break;
					}
					break;
				case 2:
					std::cout << "Te han matado:(, se acaba el juego." << std::endl;
					std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
					std::cin >> opc;
					switch (opc)
					{
					case 1:
						jugando = true;
						break;
					case 2:
						jugando = false;
						break;
					default:
						std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
						break;
					}
					break;
				default:
					break;
				}
				break;
			default:
				std::cout << "Escoge una opcion valida(1 o 2)" << std::endl;
				break;
			}
			break;
		case 2:
			std::cout << "Has caminado por pistas.\nDespues de un tramo encuentras a una persona herida, le ayudas?\n1.Ayudarle.\n2.Seguir.\n";
			std::cin >> opc;
			switch (opc)
			{
			case 1: 
				std::cout << "Le has ayudado, por tus buenas obras te ha bendecido (es una sacerdotisa), ganas +3 en suerte." << std::endl;
				suerte += 3;
				std::cout << "Por ayudarle se ofrece a ayudarte pues te ha visto muy perdido, que haces?\n1.Aceptar la ayuda.\n2.No aceptar la ayuda.\n";
				switch (opc)
				{
				case 1:
					std::cout << "Aceptas la ayuda, mientras le platicas de tu situacion, llega un paladin, parece ser amigo de la sacaerdotisa, despues de presentarse te dice que hay un pueblo cerca.\nQue haces?\n1.Decides ir.\n2.Les dices que acampen.\n";
					std::cin >> opc;
					switch (opc)
					{
					case 1:
						std::cout << "Decides ir al pueblo, despues de un rato de caminar, llegas.\nQue haces?\n1.Buscar algo de comer.\n2.Buscar un lugar donde dormir.\n";
						std::cin >> opc;
						switch (opc)
						{
						case 1: 
							std::cout << "Buscan comida, despues de un rato encuentran un puesto de comida ambulante.\nPiden un plato para cado uno." << std::endl;
							std::cout << "Despues de comer te sientes mejor.\n";
							std::cout << "Se escucha un estruendo en el centro del pueblo, que haces?\n1.Vas a ver.\n2.Huyes.\n";
							std::cin >> opc;
							switch (opc)
							{
							case 1:
								std::cout << "Vas a ver." << std::endl;
								std::cout << "Al llegar a la escena te encuentras con alguien que se te hace conocido, se ve fuerte.\nLe ibas a pedir respuestas, pero te interrumpe y te dice: Con que ahi estabas, supongo que no te acordaras de mi, asi que me presento de nuevo, soy: " << nombreV << " y he venido a matarte." << std::endl;
								std::cout << "Continuara...." << std::endl;
								std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
								std::cin >> opc;
								switch (opc)
								{
								case 1:
									jugando = true;
									break;
								case 2:
									jugando = false;
									break;
								default:
									std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
									break;
								}
								break;
							case 2:
								std::cout << "El paladin detiene un intento de asesinato hacie ti, volteas a ver quien fue y..." << std::endl;
								std::cout << "Continuara..." << std::endl;
								std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
								std::cin >> opc;
								switch (opc)
								{
								case 1:
									jugando = true;
									break;
								case 2:
									jugando = false;
									break;
								default:
									std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
									break;
								}
								break;
							default:
								std::cout << "Escoge una opcion valida(1 o 2)" << std::endl;
								break;
							}
							break;
						case 2:
							std::cout << "Buscan un lugar donde dormir, despues de caminar un rato, encuentran donde hospedarse, el paladin paga las habitacion y cada uno va a dormir" << std::endl;
							std::cout << "Al despertar, te encuetras rodeado, ves una cara que se te hace conocida conocida.\nTe dice: Un gusto volvernos a encontrar " << nombreP << " me imagino que no me recordaras, asi que me presento antes de matarte, soy : " << nombreV << std::endl;
							std::cout << nombreV << " te apuniala, mueres." << std::endl;
							std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
							std::cin >> opc;
							switch (opc)
							{
							case 1:
								jugando = true;
								break;
							case 2:
								jugando = false;
								break;
							default:
								std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
								break;
							}
							break;
						default:
							std::cout << "Escoge una opcion valida(1 o 2)" << std::endl;
							break;
						}
						break;
					case 2:
						std::cout << "Decides acampar ahi, despues de un rato dormidos, despiertas y se encuentran rodeados.\n";
						std::cout << "Ves una cara que se te hace conocida conocida.\nTe dice: Un gusto volvernos a encontrar " << nombreP << " me imagino que no me recordaras, asi que me presento antes de matarte, soy : " << nombreV << std::endl;
						std::cout << nombreV << " te apuniala, mueres." << std::endl;
						std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
						std::cin >> opc;
						switch (opc)
						{
						case 1:
							jugando = true;
							break;
						case 2:
							jugando = false;
							break;
						default:
							std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
							break;
						}
						break;
					default:
						std::cout << "Escoge una opcion valida(1 o 2)" << std::endl;
						break;
					}
					break;
				case 2:
					std::cout << "No has aceptado la ayuda, ella lo acepta y te regala un talisman (+3 en suerte y +5 en vida)" << std::endl;
					suerte += 3;
					hpJ += 5;
					std::cout << "Sigues tu camino y encuentras un pueblo.\nTienes hambre.\nQue haces ? \n1.Entro al pueblo.\n2.Paso de largo.\n";
					std::cin >> opc;
					switch (opc)
					{
					case 1:
						std::cout << "Entras al pueblo.\nQue haces?:\n1.Busco comida.\n2.Busco respuestas.\n";
						switch (opc)
						{
						case 1:
							std::cout << "Buscas comida, despues de un rato encuentras un puesto de comida ambulante.\nPides un plato." << std::endl;
							std::cout << "Despues de comer te sientes mejor.\n";
							std::cout << "Se escucha un estruendo en el centro del pueblo, que haces?\n1.Vas a ver.\n2.Huyes.\n";
							std::cin >> opc;
							switch (opc)
							{
							case 1:
								std::cout << "Vas a ver." << std::endl;
								std::cout << "Al llegar a la escena te encuentras con alguien que se te hace conocido, se ve fuerte.\nLe ibas a pedir respuestas, pero te interrumpe y te dice: Con que ahi estabas, supongo que no te acordaras de mi, asi que me presento de nuevo, soy: " << nombreV << " y he venido a matarte." << std::endl;
								std::cout << "Continuara...." << std::endl;
								std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
								std::cin >> opc;
								switch (opc)
								{
								case 1:
									jugando = true;
									break;
								case 2:
									jugando = false;
									break;
								default:
									std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
									break;
								}
								break;
							case 2:
								std::cout << "Sales del pueblo.\nAl salir, sientes como algo se te clava en la esplada, volteas a ver a tu estomago y tienes una espada clavaad, la sacan y caes." << std::endl;
								std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
								std::cin >> opc;
								switch (opc)
								{
								case 1:
									jugando = true;
									break;
								case 2:
									jugando = false;
									break;
								default:
									std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
									break;
								}
								break;
							default:
								std::cout << "Escoge una opcion valida(1 o 2)" << std::endl;
								break;
							}
							break;
						case 2:
							std::cout << "Buscas respuestas, empiezas a caminar y encuentras a alguien que parece ser importante, te acercas." << std::endl;
							std::cout << "Lo saludas y al instante te reconoce: Crei que estaba muerto senior.\nAntes de que le puedas preguntar algo, se escucha un estruendo en el centro del pueblo. La persona con la que estabas hablando corre a ver que pasa y tu lo sigues." << std::endl;
							std::cout << "Al llegar a la escena te encuentras con alguien que se te hace conocido, se ve fuerte.\nLe ibas a pedir respuestas, pero te interrumpe y te dice: Con que ahi estabas, supongo que no te acordaras de mi, asi que me presento de nuevo, soy: " << nombreV << " y he venido a matarte." << std::endl;
							std::cout << "Continuara...." << std::endl;
							std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
							std::cin >> opc;
							switch (opc)
							{
							case 1:
								jugando = true;
								break;
							case 2:
								jugando = false;
								break;
							default:
								std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
								break;
							}
							break;
						default:
							break;
						}
						break;
					case 2:
						std::cout << "Pasas de largo.\nDespues de un rato caminando te desmayas del hambre.\nAl despertar estas rodeado de personas, ves una cara que se te hace conocida conocida.\nTe dice: Un gusto volvernos a encontrar " << nombreP << " me imagino que no me recordaras, asi que me presento antes de matarte, soy: " << nombreV << std::endl;
						std::cout << nombreV << " te apuniala, mueres." << std::endl;
						std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
						std::cin >> opc;
						switch (opc)
						{
						case 1:
							jugando = true;
							break;
						case 2:
							jugando = false;
							break;
						default:
							std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
							break;
						}
						break;
					default:
						std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
						break;
					}
					break;
				default:
					std::cout << "Escoge una opcion valida(1 o 2)" << std::endl;
					break;
				}
				break;
			
			case 2:
				std::cout << "Has pasado de largo.\nPor no ayudarle te maldice, -3 de suerte.\nQue haces?\n1.Te vengas\n2.Pasas de largo.\n";
				suerte -= 3;
				std::cin >> opc;
				switch (opc)
				{
				case 1:
					std::cout << "Decides vengarte y la matas, te cae una maldicion divina -30 en suerte y -5 en HP" << std::endl;
					hpJ -= 5;
					suerte -= 30;
					opc = 0;
					std::cout << "Escuchas unos pasos detras de ti.\nVes a una persona, parece que te estaba buscansdo, trae un arma y se ve decidido a atacar.\nPreparate para luchar.\n";
					do
					{
						jugador->atacar(suerte);
						hpV[0] -= jugador->getDanioP();
						std::cout << "Al enemigo le quedan: " << hpV[0] << "puntos de vida." << std::endl;
						malo[0]->atacarV();
						hpJ -= malo[0]->getDanioV();
						std::cout << "Te quedan: " << hpJ << " puntos de vida." << std::endl;
						if (hpJ <= 0)
						{
							opc = 2;
							seguir = false;

						}
						else if (hpV[0] <= 0)
						{
							opc = 1;
							seguir = false;
						}
					} while (seguir);
					switch (opc)
					{
					case 1:
						std::cout << "Has ganado:)))" << std::endl;
						std::cout << "Despues de la pelea caminas hacia un lugar seguro y decides descansar un poco para recuperar HP." << std::endl;
						hpJ = 60;
						std::cout << "Al levantarte oyes un caballo acercandose.\nQue haces?\n1.Corro.\n2.Investigo." << std::endl;
						std::cin >> opc;
						switch (opc)
						{
						case 1:
							std::cout << "Has decidido correr\nTal parece que haz hecho mucho ruido y la persona del caballo te ha odio, te empieza a buscar.\n";
							std::cout << "No corres lo suficientemente rapido y te alcanza.\n";
							std::cout << "Te has encontrado con lo que parece ser un paladin.\nTe ve manchado en sangre e inmediatamente te ataca.\nPreparate para luchar.\n";
							opc = 0;
							do
							{
								jugador->atacar(suerte);
								hpV[1] -= jugador->getDanioP();
								std::cout << "Al enemigo le quedan: " << hpV[1] << " puntos de vida." << std::endl;
								malo[1]->atacarV();
								hpJ -= malo[1]->getDanioV();
								std::cout << "Te quedan: " << hpJ << " puntos de vida." << std::endl;
								if (hpJ <= 0)
								{
									opc = 2;
									seguir = false;

								}
								else if (hpV[1] <= 0)
								{
									opc = 1;
									seguir = false;
								}
							} while (seguir);
							switch (opc)
							{
							case 1:
								std::cout << "Has ganado:)))" << std::endl;
								std::cout << "Despues de la pelea caminas hacia un lugar seguro y decides descansar un poco para recuperar HP." << std::endl;
								hpJ = 60;
								std::cout << "Al despertar, vess una cara que se te hace conocida conocida.\nTe dice: Un gusto volvernos a encontrar " << nombreP << " me imagino que no me recordaras, asi que me presento antes de matarte, soy : " << nombreV << std::endl;
								std::cout << nombreV << " te apuniala, mueres." << std::endl;
								std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
								std::cin >> opc;
								switch (opc)
								{
								case 1:
									jugando = true;
									break;
								case 2:
									jugando = false;
									break;
								default:
									std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
									break;
								}
							case 2:
								std::cout << "Te han matado:(, se acaba el juego." << std::endl;
								std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
								std::cin >> opc;
								switch (opc)
								{
								case 1:
									jugando = true;
									break;
								case 2:
									jugando = false;
									break;
								default:
									std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
									break;
								}
								break;
							default:
								std::cout << "Escoge una opcion valida(1 o 2)" << std::endl;
								break;
							}
							break;
						case 2:
							std::cout << "Te has encontrado con lo que parece ser un paladin.\nTe ve manchado en sangre e inmediatamente te ataca.\nPreparate para luchar.\n";
							opc = 0;
							do
							{
								jugador->atacar(suerte);
								hpV[1] -= jugador->getDanioP();
								std::cout << "Al enemigo le quedan: " << hpV[1] << "puntos de vida." << std::endl;
								malo[1]->atacarV();
								hpJ -= malo[1]->getDanioV();
								std::cout << "Te quedan: " << hpJ << " puntos de vida." << std::endl;
								if (hpJ <= 0)
								{
									opc = 2;
									seguir = false;

								}
								else if (hpV[1] <= 0)
								{
									opc = 1;
									seguir = false;
								}
							} while (seguir);
							switch (opc)
							{
							case 1:
								std::cout << "Has ganado:)))" << std::endl;
								std::cout << "Despues de la pelea caminas hacia un lugar seguro y decides descansar un poco para recuperar HP." << std::endl;
								hpJ = 60;
								std::cout << "Despiertas y empiezas a caminar, despues de caminar un rato encuentras un pueblo.\nTienes hambre.\nQue haces ? \n1.Entro al pueblo.\n2.Paso de largo.\n";
								std::cin >> opc;
								switch (opc)
								{
								case 1:
									std::cout << "Entras al pueblo.\nQue haces?:\n1.Busco comida.\n2.Busco respuestas.\n";
									switch (opc)
									{
									case 1:
										std::cout << "Buscas comida, despues de un rato encuentras un puesto de comida ambulante.\nPides un plato." << std::endl;
										std::cout << "Despues de comer te sientes mejor.\n";
										std::cout << "Se escucha un estruendo en el centro del pueblo, que haces?\n1.Vas a ver.\n2.Huyes.\n";
										std::cin >> opc;
										switch (opc)
										{
										case 1:
											std::cout << "Vas a ver." << std::endl;
											std::cout << "Al llegar a la escena te encuentras con alguien que se te hace conocido, se ve fuerte.\nLe ibas a pedir respuestas, pero te interrumpe y te dice: Con que ahi estabas, supongo que no te acordaras de mi, asi que me presento de nuevo, soy: " << nombreV << " y he venido a matarte." << std::endl;
											std::cout << "Continuara...." << std::endl;
											std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
											std::cin >> opc;
											switch (opc)
											{
											case 1:
												jugando = true;
												break;
											case 2:
												jugando = false;
												break;
											default:
												std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
												break;
											}
											break;
										case 2:
											std::cout << "Sales del pueblo.\nAl salir, sientes como algo se te clava en la esplada, volteas a ver a tu estomago y tienes una espada clavaad, la sacan y caes." << std::endl;
											std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
											std::cin >> opc;
											switch (opc)
											{
											case 1:
												jugando = true;
												break;
											case 2:
												jugando = false;
												break;
											default:
												std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
												break;
											}
											break;
										default:
											std::cout << "Escoge una opcion valida(1 o 2)" << std::endl;
											break;
										}
										break;
									case 2:
										std::cout << "Buscas respuestas, empiezas a caminar y encuentras a alguien que parece ser importante, te acercas." << std::endl;
										std::cout << "Lo saludas y al instante te reconoce: Crei que estaba muerto senior.\nAntes de que le puedas preguntar algo, se escucha un estruendo en el centro del pueblo. La persona con la que estabas hablando corre a ver que pasa y tu lo sigues." << std::endl;
										std::cout << "Al llegar a la escena te encuentras con alguien que se te hace conocido, se ve fuerte.\nLe ibas a pedir respuestas, pero te interrumpe y te dice: Con que ahi estabas, supongo que no te acordaras de mi, asi que me presento de nuevo, soy: " << nombreV << " y he venido a matarte." << std::endl;
										std::cout << "Continuara...." << std::endl;
										std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
										std::cin >> opc;
										switch (opc)
										{
										case 1:
											jugando = true;
											break;
										case 2:
											jugando = false;
											break;
										default:
											std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
											break;
										}
										break;
									default:
										break;
									}
									break;
								case 2:
									std::cout << "Pasas de largo.\nDespues de un rato caminando te desmayas del hambre.\nAl despertar estas rodeado de personas, ves una cara que se te hace conocida conocida.\nTe dice: Un gusto volvernos a encontrar " << nombreP << " me imagino que no me recordaras, asi que me presento antes de matarte, soy: " << nombreV << std::endl;
									std::cout << nombreV << " te apuniala, mueres." << std::endl;
									std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
									std::cin >> opc;
									switch (opc)
									{
									case 1:
										jugando = true;
										break;
									case 2:
										jugando = false;
										break;
									default:
										std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
										break;
									}
									break;
								default:
									std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
									break;
								}
								break;
							case 2:
								std::cout << "Te han matado:(, se acaba el juego." << std::endl;
								std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
								std::cin >> opc;
								switch (opc)
								{
								case 1:
									jugando = true;
									break;
								case 2:
									jugando = false;
									break;
								default:
									std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
									break;
								}
								break;
							default:
								std::cout << "Escoge una opcion valida(1 o 2)" << std::endl;
								break;
							}
							break;
						default:
							std::cout << "Escoge una opcion valida(1 o 2)" << std::endl;
							break;
						}
					case 2:
						std::cout << "Te han matado:(, se acaba el juego." << std::endl;
						std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
						std::cin >> opc;
						switch (opc)
						{
						case 1:
							jugando = true;
							break;
						case 2:
							jugando = false;
							break;
						default:
							std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
							break;
						}
						break;
					default:
						std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
						break;
					}
					break;
				case 2:
					std::cout << "Pasas de largo.\nDespues de caminar un rato encuentras un pueblo.\nTienes hambre.\nQue haces?\n1.Entro al pueblo.\n2.Paso de largo.\n";
					std::cin >> opc;
					switch (opc)
					{
					case 1: 
						std::cout << "Entras al pueblo.\nQue haces?:\n1.Busco comida.\n2.Busco respuestas.\n";
						switch (opc)
						{
						case 1:
							std::cout << "Buscas comida, despues de un rato encuentras un puesto de comida ambulante.\nPides un plato." << std::endl;
							std::cout << "Despues de comer te sientes mejor.\n";
							std::cout << "Se escucha un estruendo en el centro del pueblo, que haces?\n1.Vas a ver.\n2.Huyes.\n";
							std::cin >> opc;
							switch (opc)
							{
							case 1:
								std::cout << "Vas a ver." << std::endl;
								std::cout << "Al llegar a la escena te encuentras con alguien que se te hace conocido, se ve fuerte.\nLe ibas a pedir respuestas, pero te interrumpe y te dice: Con que ahi estabas, supongo que no te acordaras de mi, asi que me presento de nuevo, soy: " << nombreV << " y he venido a matarte." << std::endl;
								std::cout << "Continuara...." << std::endl;
								std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
								std::cin >> opc;
								switch (opc)
								{
								case 1:
									jugando = true;
									break;
								case 2:
									jugando = false;
									break;
								default:
									std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
									break;
								}
								break;
							case 2:
								std::cout << "Sales del pueblo.\nAl salir, sientes como algo se te clava en la esplada, volteas a ver a tu estomago y tienes una espada clavaad, la sacan y caes." << std::endl;
								std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
								std::cin >> opc;
								switch (opc)
								{
								case 1:
									jugando = true;
									break;
								case 2:
									jugando = false;
									break;
								default:
									std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
									break;
								}
								break;
							default:
								std::cout << "Escoge una opcion valida(1 o 2)" << std::endl;
								break;
							}
							break;
						case 2:
							std::cout << "Buscas respuestas, empiezas a caminar y encuentras a alguien que parece ser importante, te acercas." << std::endl;
							std::cout << "Lo saludas y al instante te reconoce: Crei que estaba muerto senior.\nAntes de que le puedas preguntar algo, se escucha un estruendo en el centro del pueblo. La persona con la que estabas hablando corre a ver que pasa y tu lo sigues." << std::endl;
							std::cout << "Al llegar a la escena te encuentras con alguien que se te hace conocido, se ve fuerte.\nLe ibas a pedir respuestas, pero te interrumpe y te dice: Con que ahi estabas, supongo que no te acordaras de mi, asi que me presento de nuevo, soy: " << nombreV << " y he venido a matarte." << std::endl;
							std::cout << "Continuara...." << std::endl;
							std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
							std::cin >> opc;
							switch (opc)
							{
							case 1:
								jugando = true;
								break;
							case 2:
								jugando = false;
								break;
							default:
								std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
								break;
							}
							break;
						default:
							std::cout << "Escoge una opcion valida(1 o 2)" << std::endl;
							break;
						}
						break;
					case 2:
						std::cout << "Pasas de largo.\nDespues de un rato caminando te desmayas del hambre.\nAl despertar estas rodeado de personas, ves una cara que se te hace conocida conocida.\nTe dice: Un gusto volvernos a encontrar " << nombreP << " me imagino que no me recordaras, asi que me presento antes de matarte, soy: " << nombreV << std::endl;
						std::cout << nombreV << " te apuniala, mueres." << std::endl;
						std::cout << "Quieres repetir la historia?\n1.Si.\n2.No, salir del juego.\n";
						std::cin >> opc;
						switch (opc)
						{
						case 1:
							jugando = true;
							break;
						case 2:
							jugando = false;
							break;
						default:
							std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
							break;
						}
						break;
					default:
						std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
						break;
					}
					break;
				default:
					std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
					break;
				}
				break;
			default:
				std::cout << "Escoge una opcion valida(1 0 2)" << std::endl;
				break;
			}
			break;
		default:
			std::cout << "Escoge una opcion valida(1 o 2)" << std::endl;
			break;
		}
	} while (jugando);
}
