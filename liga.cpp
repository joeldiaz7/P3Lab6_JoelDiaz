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

#include "equipo1.cpp"
#include "jugador.cpp"
using namespace std;

#ifndef LIGA_CPP
#define LIGA_CPP

class liga{
	private:
		string nombre;
		string pais;
		vector<equipo*> equipos;
	public:
		liga(){}
		liga(string n, string p){
			nombre=n;
			pais=p;
		}
		string getNombre(){
			return nombre;
		}
		string getPais(){
			return pais;
		}
		void setEquipos(vector<equipo*> e){
			equipos=e;
		}
		vector<equipo*> getEquipos(){
			return equipos;
		}
		void addEquipo(equipo *e) {
        	equipos.push_back(e);
		}
		~liga(){}
};
#endif

