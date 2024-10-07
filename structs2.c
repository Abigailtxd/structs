#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


struct date
{
	int dia;
	int mes;
	int año;
};

int bisiesto(int dia,int mes, int año){
	bool esBisiesto;
	if(año%4==0 && año%100==0){
		esBisiesto=false;
	}else if(año%4==0 && año%100!=0){
		esBisiesto=true;
	}
	if((dia==29 || dia>29) && mes==2 && esBisiesto==false){
		printf("Introduzca el dia otra vez, este no es bisiesto");
		scanf("%d", &dia);
		return(bisiesto(dia, mes, año));
	} 
	if(esBisiesto==true && dia>29 && mes==2){
		printf("Error, febrero no puede tener más de 29 días en un año bisiesto");
		scanf("%d", &dia);
		return(bisiesto(dia, mes, año));
	}
	
	return(dia);
}

int verifmes(int mes){
	if(mes>12 || mes<0){
		printf("Error, mes incorrecto");
		scanf("%d", &mes);
		return(verifmes(mes));
	}
	return(mes);
}

int verifdias(int dia,int mes){
	bool tiene31;
	if(mes==1|| mes==3||mes==5||mes==7||mes==8||mes==10||mes==12){
		tiene31=true;
	}else{
		tiene31=false;
	}
	if((dia==31 || dia>31) && tiene31 == false){
		printf("Error, introduzca el dia de vuelta, este mes no puede tener más de 30 dias");
		scanf("%d", &dia);
		return(verifdias(dia, mes));
	}
	if(tiene31 == true && dia>31){
		printf("Error, introduzca el dia de vuelta, este mes no puede tener más de tener 31 días");
		scanf("%d", &dia);
		return(verifdias(dia, mes));
	}
	return(dia);
}



int main(){
	struct date fecha;
	printf("introduzca el dia:");
	scanf("%d", &fecha.dia);
	printf("introduzca el mes:");
	scanf("%d", &fecha.mes);
	fecha.mes = verifmes(fecha.mes);
	fecha.dia = verifdias(fecha.dia, fecha.mes);
	printf("introduzca el año");
	scanf("%d", &fecha.año);
	fecha.dia = bisiesto(fecha.dia, fecha.mes, fecha.año);
	printf("el dia es: %d \n", fecha.dia);
	printf("el mes es: %d\n", fecha.mes);
	printf("el año es: %d\n", fecha.año);
}