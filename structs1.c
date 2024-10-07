#include <stdlib.h>
#include <stdio.h>


struct date
{
	int dia;
	int mes;
	int año;
};

int main(){
	struct date fecha;
	printf("introduzca el dia:");
	scanf("%d", &fecha.dia);
	printf("introduzca el mes:");
	scanf("%d", &fecha.mes);
	printf("introduzca el año");
	scanf("%d", &fecha.año);
	printf("el dia es: %d \n", fecha.dia);
	printf("el mes es: %d\n", fecha.mes);
	printf("el año es: %d\n", fecha.año);
}