#include <cstdlib>
#include <iostream>
#include <chrono>
#include <random>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <string>
#include "instanceConstructor.h"

using namespace std;

class instanceConstructor;

//Crear la matriz de soluciones
std::vector<std::vector<int> > solucion (std::vector<std::vector<int> > vectorAsignaciones, int enfermeras, int dias, int turnos){
		std::vector<std::vector<int> > matrizSolucion;
		std::vector<int> vec_aux;
		std::vector<int>::iterator it;
		int total=turnos*dias, turnoActual, enfermeraActual=0, contador;
		
		do{
			turnoActual=0;
			do{
				//Chequear si la enfermera fue asignada al turno actual
				it = find (vectorAsignaciones[turnoActual].begin(), vectorAsignaciones[turnoActual].end(), enfermeraActual);
				if (it == vectorAsignaciones[turnoActual].end()){
					vec_aux.push_back(0);
				}
				else{
					vec_aux.push_back(1);
				}
				turnoActual++;
			}while (total != turnoActual);
			matrizSolucion.push_back(vec_aux);
			contador = 0;
			while ((total - contador) != 0){
				vec_aux.pop_back();
				contador++;
			}
			enfermeraActual++;
		}while (enfermeras != enfermeraActual);
		
		return matrizSolucion;
}

int main(int argc, char** argv) {
	
	int turno=0, enfermera=0, preferencia, enfermerasTotal, diasTotal, turnosTotal, b, penalizacion=0;
	std::vector<int> enfermerasXturno, vec_aux;
	std::vector<std::vector<int> > preferenciasXenfermera, matrizSolucion, vectorAsignaciones;
	pair<int,int > enfermeraCandidata; //Par del tipo (enfermera, preferencia)
	std::pair<int,std::vector<int> > parAux;

	instanceConstructor data (argv[1]); //Se desglosa el archivo de datos
	
	//Seteo de parametros a utilizar
	enfermerasTotal = data.getEnfermerasTotales();
	diasTotal = data.getDiasTotales();
	turnosTotal = data.getTurnosTotales();
	enfermerasXturno = data.getEnfermerasXturno();
	preferenciasXenfermera = data.getPreferenciasXenfermera();

	for (int cantidad : enfermerasXturno){
		//Greedy: seleccionar la enfermera que tenga la preferencia mas cercana a 1
		while (cantidad != 0){
			enfermeraCandidata = make_pair(0, 9999999);
			while (enfermerasTotal != enfermera){
				preferencia = preferenciasXenfermera[enfermera][turno];
				if (preferencia < enfermeraCandidata.second){
					enfermeraCandidata = make_pair(enfermera, preferencia);
				}
				enfermera++;
			}
			penalizacion+=(enfermeraCandidata.second - 1);
			preferenciasXenfermera[enfermeraCandidata.first][turno] = 9999999;
			vec_aux.push_back(enfermeraCandidata.first);
			enfermera = 0;
			cantidad--;
		}
		vectorAsignaciones.push_back(vec_aux);
		while (vec_aux.size() != 0){
			vec_aux.pop_back();
		}
		turno++;
	}
	
	matrizSolucion = solucion (vectorAsignaciones, enfermerasTotal, diasTotal, turnosTotal);
	
	for(std::vector<int> a : matrizSolucion){
		b = 0;
		while ((unsigned)b != a.size()){
		cout <<a[b]<<"|";
		b++;
		}
		cout << '\n';
	}
	
	cout << "penalizacion: " << penalizacion << '\n';

	return 0;
}
