#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

struct alumno{
	char nombre[35];
	char apellido[35];
	unsigned long int ci;
	unsigned int trabajopractico[2];
	unsigned int examenes[2];
	unsigned int promedio;
};



void verifci(unsigned long int* ci){
	if(*ci<900){
		printf("Error, número de cédula invalida");
		scanf("%ld", ci);
		return(verifci(ci));
	}
}

void esAlfa(char *array){
	bool esAlf=true;
	int i;
	for(i=0;i<strlen(array)-1;i++){
		if(!isalpha(array[i])&& array[i]!=' '){
			esAlf=false;
		}

	}
	if(esAlf==false){
		printf("Error, introduzca el dato otra vez");
		fgets(array, 35, stdin);
		return(esAlfa(array));
	}
}

int compareByCI(const void* a, const void* b){
    return ((struct alumno*)a)->ci
           - ((struct alumno*)b)->ci;
}


void esRepetido(int *final){
	struct alumno alumno[*final];
	bool rep=false;
	for(int i=0;i<*final-1; i++){
		for(int j=j+1;i<*final;j++){
			if(alumno[i].ci==alumno[j].ci){
				rep=true;
				break;
			}
		}
		break;
	}
	if(rep==true){
		printf("Error, número de cedula repetida");
		scanf("%lu", &alumno[*final].ci);
		return(esRepetido(final));
	}
}



int main(){
	unsigned int estudiantes;
	printf("Escriba la cantidad de alumnos");
	scanf("%d", &estudiantes);
	struct alumno student[estudiantes];
	int promedio[4]={0, 0.0,0};
	for(int i=0;i<estudiantes;i++){
		student[i].promedio=0;
		printf("Introduzca el nombre del estudiante:");
		getchar();
		fgets(student[i].nombre, 35, stdin);
		esAlfa(student[i].nombre);
		printf("Introduzca el apellido del estudiante");
		fgets(student[i].apellido, 35, stdin);
		esAlfa(student[i].apellido);
		printf("Introduzca el número de cédula del estudiante");
		scanf("%ld", &student[i].ci);
		verifci(&student[i].ci);
		esRepetido(&i);
		for(int j=0;j<2;j++){
			printf("Introduzca la nota del trabajo práctico número %d", j+1);
			scanf("%d", &student[i].trabajopractico[j]);
			promedio[j]=promedio[j]+student[i].trabajopractico[j];
			student[i].promedio=student[i].promedio+student[i].trabajopractico[j];
		}
		for(int j=0;j<2;j++){
			printf("Introduzca la nota del examen %d", j+2);
			scanf("%d", &student[i].examenes[j]);
			promedio[j+2]=promedio[j+2]+student[i].examenes[j];
			student[i].promedio=student[i].promedio+student[i].examenes[j];
		}
		student[i].promedio=student[i].promedio/4;
	}
	for(int i=0;i<estudiantes;i++){
		promedio[i]=promedio[i]/estudiantes;
	}
	int n = sizeof(student) / sizeof(student[0]);
	qsort(student, n, sizeof(struct alumno), compareByCI);
	int mayor=0;
	int nroestudiante;
	for(int i=0; i<estudiantes;i++){
		printf("Estudiante %s%s de ci %lu:\n", student[i].nombre, student[i].apellido, student[i].ci);
		for(int j=0;j<2;j++){
			printf("Trabajo práctico:\n");
			printf("%d", student[i].trabajopractico[j]);
		}
		for(int j=0;j<2;j++){
			printf("Examen:\n");
			printf("%d", student[i].examenes[j]);
		}
		printf("Promedio final: %d", student[i].promedio);
		if(student[i].promedio>mayor){
			mayor = student[i].promedio;
			nroestudiante=i;
		}

	}
	
	for(int i=0;i<4;i++){
		printf("El promedio de la clase en la evaluacion es de %d", promedio[i]);
	}
	printf("El estudiante de mayor promedio es %s%s con un promedio de %d", student[nroestudiante].nombre,student[nroestudiante].apellido, mayor);
}
