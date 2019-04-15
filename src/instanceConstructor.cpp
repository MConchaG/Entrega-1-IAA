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

instanceConstructor::instanceConstructor(char *filePath) { //Se desglosa el archivo de entrada
	
	ifstream archivo;
	
	archivo.open(filePath);
	
	if (archivo.is_open()){
		archivo >> aux;
		enfermerasTotal = aux;

		archivo >> aux;
		diasTotal = aux;
		
		archivo >> aux;
		turnosTotal = aux;
		
		while ((diasTotal - contadorDias != 0)){
			while ((turnosTotal - contadorTurnos) != 0){
				archivo >> aux;
				enfermerasXturno.push_back(aux);
				contadorTurnos++;
			}
			contadorTurnos = 0;
			contadorDias++;
		}
		
		total = turnosTotal * diasTotal;
		while ((enfermerasTotal - contadorEnfermeras != 0)){
			contador = 0;
			while ((total - contador) != 0){
				archivo >> aux;
				aux_vec.push_back(aux);
				contador++;
			}
			preferenciasXenfermera.push_back(aux_vec);
			contador = 0;
			contadorEnfermeras++;
			while ((total - contador) != 0){
				aux_vec.pop_back();
				contador++;
			}
		}
		
		archivo.close();
		
	}
	
	else cout << "Unable to open file";
	
	
}
//Retorna el numero de enfemeras disponibles
int instanceConstructor::getEnfermerasTotales(){
	return enfermerasTotal;
}

//Retorna el numero de dias
int instanceConstructor::getDiasTotales(){
	return diasTotal;
}

//Retorna el numero de turnos
int instanceConstructor::getTurnosTotales(){
	return turnosTotal;
}

//Retorna el numero de enfermeras requeridas por turno
std::vector<int> instanceConstructor::getEnfermerasXturno(){
	return enfermerasXturno;
}

//Retorna las preferencias de cada enfermera
std::vector<std::vector<int> > instanceConstructor::getPreferenciasXenfermera(){
	return preferenciasXenfermera;
}
