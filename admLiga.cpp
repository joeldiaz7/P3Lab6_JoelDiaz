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

#include "liga.cpp"
#ifndef ADMLIGA_CPP
#define ADMLIGA_CPP
using namespace std;

class admLiga{
    private:
        string ruta; //rom
        vector<liga*> ligas; //ram                      
    public:
        admLiga(string ruta){
        	this->ruta=ruta;
		}            
        string getRuta(){
            return ruta;
		} 
        void addLiga(liga *l){
            ligas.push_back(l);
		}
        vector<liga*> getLigas(){
            return this->ligas;
        } 
		void removerLiga(int p){
        	ligas.erase( ligas.begin()+p );
        }
		int getTamano(){
            ligas.size();
		}             
        ~admLiga(){}
        //
        string token(string cadena, string divisor, int pos){
            if(cadena.size()>0){
                char oracion[cadena.size()]; 
                for (int i=0;i<=cadena.size();i++){
					oracion[i]=cadena[i];
				}                    
                char *ptrtoken; 
                int num=1;
                const char* d=divisor.c_str();
                ptrtoken = strtok(oracion , d);             
                while(ptrtoken){
                    if(num==pos){ 
                        return ptrtoken;
					}                 
                    ptrtoken = strtok(NULL, d);
                    num++;
				}
                return "";
               	}else{
			   		return "";
			   	}
            }
		//
        void escribir(){
          	ofstream Escribir;
        	Escribir.open(ruta.c_str());  
        	for(int i=0; i<ligas.size();i++){
        		Escribir<<"$"<<ligas.at(i)->getNombre()<<":"<<ligas.at(i)->getPais()<<endl;
        		for (int j=0; j<ligas.at(i)->getEquipos().size(); j++){
        			Escribir<<ligas.at(i)->getEquipos().at(j)->getNombre()<<":"<<ligas.at(i)->getEquipos().at(j)->getAnoFundacion()<<"{";
        			for (int k=0; k<ligas.at(i)->getEquipos().at(j)->getJugadores().size(); k++){
        				Escribir<<ligas.at(i)->getEquipos().at(j)->getJugadores().at(k)->getNombre()<<"|"<<ligas.at(i)->getEquipos().at(j)->getJugadores().at(k)->getDorsal()<<"|"<<ligas.at(i)->getEquipos().at(j)->getJugadores().at(k)->getPaisOrigen();
        				if (k!= (ligas.at(i)->getEquipos().at(j)->getJugadores().size() -1)){
        					Escribir<<";";
        				}else{
        					Escribir<<"}"<<endl;
						}
					}
				}
			}             
          Escribir.close(); 
        }
		//
        void leer(){
            fstream Leer;
            string linea;
            ligas.clear();                 
            Leer.open(ruta.c_str()); 
            if(Leer.is_open()){                
                while(! Leer.eof()){
                    getline(Leer,linea);
                    if(linea.size()>0){
						if(linea[0]=='$'){
							linea = linea.substr(1,linea.size());
							addLiga(new liga(token(linea,":", 1), token(linea,":", 2)));  
						}else{
							int max=1;
							for(int i=0; i < linea.size(); i++){
								if(linea[i]=='{'){
									max=i;	
								}
							}
							if(max!=1){
								string subs1, subs2;
								subs1 = linea.substr(0, max);
								subs2 = linea.substr(max+1,linea.size()-1);
								subs2 = subs2.substr(0, subs2.size() - 1);	
								ligas.at(ligas.size()-1)->addEquipo(new equipo(token(subs1, ":", 1), token(subs1,":",2)));
								int posToken=1;
								while(true){
									if(token(subs2,";",posToken)==""){
										break;
									}
									string jug = token(subs2, ";", posToken);
									string nombre, dorsal, origen;
									nombre = token(jug, "|", 1);
									dorsal = token(jug, "|", 2);
									origen = token(jug, "|", 3);
									ligas.at(ligas.size() - 1)->getEquipos().at(ligas.at(ligas.size()-1)->getEquipos().size()-1)->addJugador(new jugador(nombre,dorsal,origen));
									posToken++;
								}
							}
						}                  
                    }
                }
            }    
            Leer.close();
        }
		//
        void print(){
			for (int i = 0; i < getLigas().size(); i++) {
				cout << i << "- " << getLigas().at(i)->getNombre() << endl;
			}
        }           
};
#endif

