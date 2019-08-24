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

using namespace std;

#ifndef JUGADOR_CPP
#define JUGADOR_CPP

class jugador{
	private:
		string nombre;
		string dorsal;
		string paisOrigen;
	public:
		jugador(){}
		jugador(string n, string d, string o){
			nombre=n;
			dorsal=d;
			paisOrigen=o;
		}
		string getNombre(){
			return nombre;
		}
		string getDorsal(){
			return dorsal;
		}
		string getPaisOrigen(){
			return paisOrigen;
		}
		~jugador(){}
};
#endif
