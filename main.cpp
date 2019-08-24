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

#include "admLiga.cpp"
#include "liga.cpp"
using namespace std;
int op;
bool isActivo = true;
string nombre, pais, fund, dorsal;
int pos, pos2, pos3;
admLiga adm("./ligas.txt");

int main(){
	bool isCargado = false;
	while(true){
		isActivo=true;
		cout<<"NOTA: Recuerde cargar el archivo antes de hacer cualquier cosa y guardar los cambios"<<endl;
		cout<<"Ingrese una opcion: "<<endl;
		cout<<"1) Administrar ligas"<<endl;
		cout<<"2) Administrar equipos"<<endl;
		cout<<"3) Administrar jugadores"<<endl;
		cout<<"4) Jugar partdo"<<endl;
		cout<<"5) Cargar archivo"<<endl;
		cout<<"6) Guardar archivo"<<endl;
		cout<<"7) Ver tablas"<<endl;
		cout<<"8) Salir"<<endl;
		cin>>op;
		switch(op){
			case 1://adm ligas
				if(isCargado){
					while(isActivo){
						cout<<"Ingrese una opcion: "<<endl;
						cout<<"1) Agregar liga"<<endl;
						cout<<"2) Eliminar liga"<<endl;
						cout<<"Ingrese cualquier otro numero para regresar"<<endl;
						cin>>op;
						switch(op){
							case 1://add
								cout<<"Ingrese nombre de la liga: "<<endl;
								cin>>nombre;
								cout<<"Ingrese pais de la liga: "<<endl;
								cin>>pais;
								adm.addLiga(new liga(nombre,pais));
								cout<<"--- Liga creada! ---"<<endl;
								break;
							case 2://elim
								adm.print();
								cout<<"Ingrese posicion a eliminar: "<<endl;
								cin>>pos;
								adm.removerLiga(pos);
								cout<<"--- Liga removida! ---"<<endl;
								break;
							default://err
								isActivo=false;
								break;
						}
					}
					adm.escribir();
				} else {
					cout<<"--- Error, no se ha cargado ningun archivo! ---"<<endl;
				}
				break;
			case 2://adm equipos
				if(isCargado){
					while(isActivo){
						cout<<"Ingrese una opcion: "<<endl;
						cout<<"1) Agregar equipo"<<endl;
						cout<<"2) Eliminar equipo"<<endl;
						cout<<"Ingrese cualquier otro numero para regresar"<<endl;
						cin>>op;
						switch(op){
							case 1://add
								cout<<"Ingrese nombre del equipo: "<<endl;
								cin>>nombre;
								cout<<"Ingrese ano de fundacion: "<<endl;
								cin>>fund;
								adm.print();
								cout<<"Ingrese posicion de la liga a la que se agregara: "<<endl;
								cin>>pos;
								adm.getLigas().at(pos)->addEquipo(new equipo(nombre, fund));
								cout<<"--- Nuevo equipo anadido a Liga! ---"<<endl;
								break;
							case 2://elim
								cout<<"Ingrese posicion de la liga: "<<endl;
								cin>>pos;
								cout<<"Ingrese posicion del equipo a eliminar: "<<endl;
								cin>>pos2;
								adm.getLigas().at(pos)->getEquipos().erase( adm.getLigas().at(pos)->getEquipos().begin()+1 );
								break;
							default://err
								isActivo=false;
								break;
						}
					}
					adm.escribir();
				} else {
					cout<<"--- Error, no se ha cargado ningun archivo! ---"<<endl;
				}
				break;
			case 3://adm jugadores
				if(isCargado){
					while(isActivo){
						cout<<"Ingrese una opcion: "<<endl;
						cout<<"1) Agregar jugador"<<endl;
						cout<<"2) Eliminar jugador"<<endl;
						cout<<"Ingrese cualquier otro numero para regresar"<<endl;
						cin>>op;
						switch(op){
							case 1://add
								cout<<"Ingrese nombre del jugador: "<<endl;
								cin>>nombre;
								cout<<"Ingrese dorsal: "<<endl;
								cin>>dorsal;
								cout<<"Ingrese pais de origen: "<<endl;
								cin>>pais;
								cout<<"Ingrese posicion de la liga: "<<endl;
								cin>>pos;
								cout<<"Ingrese posicion del equipo: "<<endl;
								cin>>pos2;
								adm.getLigas().at(pos)->getEquipos().at(pos2)->addJugador(new jugador(nombre,dorsal, pais));
								break;
							case 2://elim
								cout<<"Ingrese posicion de la liga: "<<endl;
								cin>>pos;
								cout<<"Ingrese posicion del equipo: "<<endl;
								cin>>pos2;
								cout<<"Ingrese posicion del jugador a eliminar: "<<endl;
								cin>>pos2;
								adm.getLigas().at(pos)->getEquipos().at(pos2)->getJugadores().erase(  adm.getLigas().at(pos)->getEquipos().at(pos2)->getJugadores().begin()+1 );
								break;
							default://err
								isActivo=false;
								break;
						}
					}
					adm.escribir();
				} else {
					cout<<"--- Error, no se ha cargado ningun archivo! ---"<<endl;
				}
				break;
			case 4://jugar
				if(isCargado){
					//
					//		...
					//
				} else {
					cout<<"--- Error, no se ha cargado ningun archivo! ---"<<endl;
				}
				break;
			case 5://CARGAR -----
				adm.leer();
				isCargado=true;
				cout<<"--- Archivo cargado exitosamente! ---"<<endl;
				break;
			case 6://GUARDAR -----
				adm.escribir();
				cout<<"--- Archivo actualizado! ---"<<endl;
				break;
			case 7://tablas
				if(isCargado){
					//
					//		...
					//
				} else {
					cout<<"--- Error, no se ha cargado ningun archivo! ---"<<endl;
				}
				break;
			case 8://salir
				return 0;
				break;
			default://error
				cout<<"--- Error, opcion no valida! ---"<<endl;
				break;
		}
	}
	//
	return 0;
}

