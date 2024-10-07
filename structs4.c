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

int main(){
	struct alumno student;
	printf("Introduzca el nombre del estudiante:");
	fgets(student.nombre, 35, stdin);
	esAlfa(student.nombre);
	student.nombre[strcspn(student.nombre, "\n")]='\0';
	printf("Introduzca el apellido del estudiante");
	fgets(student.apellido, 35, stdin);
	esAlfa(student.apellido);
	student.apellido[strcspn(student.apellido, "\n")]='\0';
	printf("Introduzca el número de cédula del estudiante");
	scanf("%ld", &student.ci);
	verifci(&student.ci);
	int i;
	int acum=0;
	for(i=0;i<2;i++){
		printf("Introduzca la nota del trabajo práctico número %d", i+1);
		scanf("%d", &student.trabajopractico[i]);
		acum = acum+student.trabajopractico[i];
	}
	for(i=0;i<2;i++){
		printf("Introduzca la nota del examen %d", i+1);
		scanf("%d", &student.trabajopractico[i]);
		acum = acum+student.trabajopractico[i];
	}
	printf("El promedio del alumno/a %s%s es de %d", student.nombre, student.apellido, acum/4);

}