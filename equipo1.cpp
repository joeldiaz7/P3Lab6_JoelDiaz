#include <iostream>
#include <string.h>
#include <bits/stdc++.h>
#include <stdio.h>
#include <vector>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <typeinfo>
#include <fstream>
#include <sstream>

#include "jugador.cpp"
using namespace std;

#ifndef EQUIPO_CPP
#define EQUIPO_CPP

class equipo{
	public:
		string nombre;
		string anoFundacion;
		vector<jugador*> jugadores;
	public:
		equipo(){}
		equipo(string n, string a){
			nombre=n;
			anoFundacion=a;
		}
		string getNombre(){
			return nombre;
		}
		string getAnoFundacion(){
			return anoFundacion;
		}
		vector<jugador*> getJugadores(){
			return jugadores;
		}
		void addJugador(jugador *j){
            jugadores.push_back(j);
		}
		~equipo(){}
};
#endif
