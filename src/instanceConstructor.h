#ifndef INSTANCECONSTRUCTOR_H
#define INSTANCECONSTRUCTOR_H

#include <vector>
#include <string>

class instanceConstructor{
	
public:		
	instanceConstructor(char *filePath);	
	int getEnfermerasTotales();
	int getDiasTotales();
	int getTurnosTotales();
	std::vector<int> getEnfermerasXturno();
	std::vector<std::vector<int> > getPreferenciasXenfermera();

private:
	int enfermerasTotal, diasTotal, turnosTotal, total, aux, contador=0, contadorDias = 0, contadorTurnos = 0, contadorEnfermeras = 0;
	std::vector<int> aux_vec, enfermerasXturno;
	std::vector<std::vector<int> > preferenciasXenfermera;
};

#endif /* INSTANCECONSTRUCTOR_H */
