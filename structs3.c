#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

struct libros{
	char titulo[35];
	char autor[35];
	char genero[35];
	unsigned int añodepublicacion;
	unsigned int codigodelibro;
	unsigned int stock;
};

struct compra{
	char producto[35];
	char marca[35];
	char formato[10];
	unsigned int codigodebarra;
	char categoria[20];
};

struct car{
	char marca[35];
	char categoria[20];
	char modelo[35];
	unsigned int año;
	char motor[10];
	char combustible[15];
	char color[10];
	bool usado;
	unsigned long int kilometraje;
};

struct paciente{
	char nombre[35];
	char apellido[35];
	char sexo;
	unsigned int edad;
	unsigned long int ci;
	unsigned long int codigodelasegurado;
	bool enfermedadbase;
};


struct empleado{
	char nombre[35];
	char apellido[35];
	unsigned long int ci;
	unsigned long int codigoempleado;
	bool asistencia;
	bool vacaciones;
	bool enfermedades;
	bool diafestivo;
	unsigned int horarioentrada;
	unsigned int horariosalida;
	unsigned int horaregulares;
	bool horaextra;
	unsigned int horasextras;
};

struct disco{
	char titulo[35];
	char artista[35];
	unsigned int añodepublicacion;
	unsigned int codigodedisco;
	char genero;
	int stock;
	char disquera[35];
};

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

void verifgenerolibro(char *arr){
	int i;
	bool esGenero=false;
	char generos[13][20]={ "Suspenso", "Romance", "Historia", "Ciencia Ficción", "Fantasía","Terror", "Poesía","Infantil","Juvenil","Autoayuda","Técnico","Biografía","Otros"};
	for(i=0; i<13; i++){
		if(strcmp(arr, generos[i])==0){
			esGenero=true;
			break;
		}
	}
	if(esGenero==false){
		printf("Introduzca otra vez el genero, este género es invalido");
		scanf("%s", arr);
		arr[strcspn(arr, "\n")]='\0';
		return(verifgenerolibro(arr));
	}
}



void verifaño(unsigned int *num){
	if(*num > 2024){
		printf("Error, introduzca el año de publicación de vuelta");
		scanf("%d", num);
		return(verifaño(num));
	}
}

void verifseccion(char* arr){
	char secciones[18][20]={"Rotiseria","Almacen","Verduleria","Bebidas con alcohol", "Bebidas sin alcohol","Carniceria","Fiambreria", "Queseria","Perfumeria","Libreria","Productos Dieteticos","Congelados","Limpieza","Panaderia","Jugueteria","Mascotas", "Delicatessen","Otro"};
	int i;
	bool esSeccion=false;
	for(i=0; i<18; i++){
		printf("%d", esSeccion);
		if(strcmp(arr, secciones[i])==0){
			esSeccion=true;
			break;
		}
	}
	if(!esSeccion){
		printf("Introduzca otra vez la sección ,esta sección es invalido");
		fgets(arr, 20, stdin);
		arr[strcspn(arr, "\n")]='\0';
		return(verifseccion(arr));
	}

}

void verifcategoria(char *arr){
	char secciones[14][20]={"SUV","Coupe","Sedan","Hatchback", "Cabriolet","Targa","Roadster", "Pickup","Compacto","Van","Minivan","Otro"};
	int i;
	bool esCategoria=false;
	for(i=0; i<14; i++){
		if((strcmp(arr, secciones[i]))==0){
			esCategoria=true;
			break;
		}
	}
	if(!esCategoria){
		printf("Introduzca otra vez la categoria ,esta sección es invalida");
		scanf("%s", arr);

		return(verifcategoria(arr));
	}
}

void verifcombustible(char *arr){
	char secciones[12][20]={"Diesel","Naftero","Alcohol","Hatchback"};
	int i;
	bool esCategoria=false;
	for(i=0; i<13; i++){
		if((strcmp(arr, secciones[i]))==0){
			esCategoria=true;
		}
	}
	if(esCategoria==false){
		printf("Introduzca otra vez la categoria ,esta sección es invalido");
		scanf("%s", arr);
		arr[strcspn(arr, "\n")]='\0';
		return(verifcategoria(arr));
	}
}

void verifsexo(char *sexo){
	if(isupper(*sexo)){
		if(*sexo!='M' && *sexo!='F'){
			printf("Error, sexo incorrecto\n");
			getchar();
			scanf("%c", sexo);
			return(verifsexo(sexo));
		}
	
	}
	if(islower(*sexo)){
		if(*sexo!='m' && *sexo!= 'f'){
			printf("Error, sexo incorrecto\n");
			getchar();
			scanf("%c", sexo);
			return(verifsexo(sexo));
		}
	}
}

void verifedad(unsigned int*edad){
	if(*edad>120){
		printf("Error, introduzca de nuevo la edad");
		scanf("%d", edad);
		return(verifedad(edad));
	}
}


void verifci(unsigned long int* ci){
	if(*ci<900){
		printf("Error, número de cédula invalida");
		scanf("%ld", ci);
		return(verifci(ci));
	}
}


void verifhoras(unsigned int*horaentrada, unsigned int*horasalida){
	printf("%d", *horaentrada);
	printf("%d", *horasalida);
	if(*horasalida<*horaentrada){
		printf("Error, horarios incorrectos\n");
		printf("Introduzca el horario de entrada, recuerde que el mismo debe ser en un formato de 24 horas:\n");
		scanf("%d", horaentrada);
		printf("Introduzca el horario de salida, recuerde que el mismo debe ser en un formato de 24 horas:\n");
		scanf("%d", horasalida);
		return(verifhoras(horaentrada,horasalida));
	}
}

void verifhorasextra(unsigned int* horasextra){
	if(*horasextra>3){
		printf("Error, cantidad de horas extra incorrecta");
		scanf("%d", horasextra);
		return(verifhorasextra(horasextra));
	}
}













int main(){
	struct libros biblioteca;
	struct compra supermercado;
	struct car playadeauto;
	struct paciente seguromedico;
	struct empleado registroempleado;
	struct disco disquera;
	unsigned int opcion;
	printf("Bienvenido! Seleccione que opción desea registrar:\n");
	printf("1-Biblioteca\n2-Registro de un producto de supermercado\n3-Auto\n4-Paciente de un seguro médico\n5-Registro de asistencia de un empleado\n6-Registro de una disquera\n");
	scanf("%d", &opcion);
	while(opcion>6){
		printf("Error, opción invalida");
		scanf("%d", &opcion);
	}
	switch (opcion) {
  		case 1:
    		printf("Introduzca el titulo:");
    		getchar();
    		fgets(biblioteca.titulo, 35, stdin);
    		printf("Introduzca el autor:");
    		fgets(biblioteca.autor, 35, stdin);
    		esAlfa(biblioteca.autor);
    		printf("Introduzca el genero:");
    		getchar();
    		fgets(biblioteca.genero, 35, stdin);
    		biblioteca.genero[strcspn(biblioteca.genero, "\n")]='\0';
    		verifgenerolibro(biblioteca.genero);
    		printf("Introduzca el año de publicacion");
    		scanf("%d", &biblioteca.añodepublicacion);
    		verifaño(&biblioteca.añodepublicacion);
    		printf("Introduzca el codigo de libro");
    		scanf("%d", &biblioteca.codigodelibro);
    		break;
  		case 2:
  			printf("Introduzca el producto:\n");
  			getchar();
  			fgets(supermercado.producto, 35, stdin);
  			esAlfa(supermercado.producto);
   		 	printf("Introduzca la marca");
   		 	fgets(supermercado.marca, 35, stdin);
   		 	printf("Introduzca el formato");
   		 	scanf("%s", supermercado.formato);
   		 	fgets(supermercado.formato, 35, stdin);
   		 	printf("Introduzca el codigo de barra");
   		 	scanf("%d", &supermercado.codigodebarra);
   		 	getchar();
   		 	printf("Introduzca la categoria");
   		 	fgets(supermercado.categoria, 20, stdin);
   		 	supermercado.categoria[strcspn(supermercado.categoria, "\n")]='\0';
   		 	verifseccion(supermercado.categoria);
    		break;
  		case 3:
    		printf("Introduzca la marca:");
    		getchar();
    		fgets(playadeauto.marca, 20, stdin);
    		esAlfa(playadeauto.marca);
    		printf("Introduzca la categoria");
    		getchar();
    		fgets(playadeauto.categoria, 20, stdin);
    		playadeauto.categoria[strcspn(playadeauto.categoria, "\n")]='\0';
    	    verifcategoria(playadeauto.categoria); /*la funcion retorna error a pesar de introducir correctamente la categoria*/
    		printf("Introduzca el modelo:");
    		getchar();
    		fgets(playadeauto.modelo, 20, stdin);
    		printf("Introduzca el año");
    		scanf("%d", &playadeauto.año);
    		verifaño(&playadeauto.año);
    		printf("Introduzca el motor:");
    		scanf("%s", playadeauto.motor);
    		printf("Introduzca el tipo de combustible que utiliza el vehiculo:");
    		scanf("%s", playadeauto.combustible);
    		verifcombustible(playadeauto.combustible);
    		printf("Introduzca el color del vehiculo:");
    		scanf("%s", playadeauto.color);
    		unsigned int temp;
    		printf("Es el auto usado? Introduzca 1 si es usado, 0 si es 0 km");
    		scanf("%d", &temp);
    		playadeauto.usado=temp;
    		if(playadeauto.usado==1){
    			printf("Introduzca el kilometraje");
    			scanf("%ld", &playadeauto.kilometraje);
    		}else{
    			playadeauto.kilometraje = 0;
    		}
    		break;
    	case 4: 
    		printf("Introduzca el nombre del paciente:");
    		getchar();
    		fgets(seguromedico.nombre,35, stdin);
    		esAlfa(seguromedico.nombre);
    		printf("Introduzca el apellido del paciente:");
    		getchar();
    		fgets(seguromedico.apellido, 35, stdin);
    		esAlfa(seguromedico.apellido);
    		printf("Introduzca el sexo del paciente,M si es masculino, F si es femenino");
    		scanf("%c", &seguromedico.sexo);
    		verifsexo(&seguromedico.sexo); /*la funcion no permite directamente introducir el genero de vuelta*/
    		printf("Introduzca la edad del asegurado:");
    		scanf("%d", &seguromedico.edad);
    		verifedad(&seguromedico.edad);
    		printf("Introduzca el ci del paciente:");
    		scanf("%ld", &seguromedico.ci);
    		verifci(&seguromedico.ci);
    		printf("Introduzca el codigo del asegurado:");
    		scanf("%ld", &seguromedico.codigodelasegurado);
    		printf("El asegurado tiene enfermedad de base? Introduzca 1 si es el caso, 0 si no es el caso");
    		scanf("%d", &temp);
    		while(temp>1){
    			printf("Error, introduzca la opción de vuelta:\n");
    			scanf("%d", &temp);
    		}
    		seguromedico.enfermedadbase=temp;
    		break;
    	case 5:
    		printf("Introduzca el nombre del empleado:");
    		getchar();
    		fgets(registroempleado.nombre, 35, stdin);
    		esAlfa(registroempleado.nombre);
    		printf("Introduzca el apellido del empleado:");
    		getchar();
    		fgets(registroempleado.apellido, 35, stdin);
    		esAlfa(registroempleado.apellido);
    		printf("Introduzca el ci del empleado:");
    		scanf("%ld", &registroempleado.ci);
    		printf("Introduzca el codigo del empleado");
    		scanf("%ld", &registroempleado.codigoempleado);
    		printf("Ha asistido hoy el empleado? Introduzca 1 si es asi, introduzca 0 si se ha ausentado");
    		scanf("%d", &temp);
    		while(temp>1){
    			printf("Error, opción incorrecta");
    			scanf("%d", &temp);
    		}
    		registroempleado.asistencia=temp;
    		if(registroempleado.asistencia==true){
    			printf("Introduzca el horario de entrada(regular) del empleado");
    			scanf("%d", &registroempleado.horarioentrada);
    			printf("Introduzca el horario de salida(regular) del empleado, recuerde que debe ser utilizando el formato de 24 horas");
    			scanf("%d", &registroempleado.horariosalida);
    			verifhoras(&registroempleado.horarioentrada, &registroempleado.horariosalida);
    			printf("Ha realizado horas extra? Introduzca 1 si es el caso, 0 si no es asi");
    			scanf("%d", &temp);
    			while(temp>1){
    			printf("Error, opción incorrecta");
    			scanf("%d", &temp);
    			}
    			registroempleado.horaextra=temp;
    			if(registroempleado.horaextra){
    				printf("Introduzca la cantidad de horas extra realizadas");
    				scanf("%d", &registroempleado.horasextras);
    				verifhorasextra(&registroempleado.horasextras);
    			}else{
    				registroempleado.horasextras=0;
    			}
    		}else{
    			while(true){
    				printf("El empleado ha tomado vacaciones?, introduzca 1 si es asi, si no, introduzca 0");
    				scanf("%d", &temp);
    				registroempleado.vacaciones=temp;
    				if(registroempleado.vacaciones){
    					break;
    				}
    				printf("El empleado ha tomado reposo?, introduzca 1 si es asi, si no, introduzca 0");
    				scanf("%d", &temp);
    				registroempleado.enfermedades=temp;
    				if(registroempleado.enfermedades){
    					break;
    				}
    				printf("Ha sido un dia festivo?, introduzca 1 si es asi, si no, introduzca 0");
    				scanf("%d", &temp);
    				registroempleado.diafestivo=temp;
    				if(registroempleado.diafestivo==0){
    					unsigned int opcion;
    					printf("Error, introduzca de vuelta el motivo de la ausencia del empleado: 1-Vacaciones, 2-Reposo, 3-Dia festivo");
    					scanf("%d", &opcion);
    					while(opcion>3){
    						printf("Error, opcion incorrecta, introduzca la opcion otra vez");
    						scanf("%d", &opcion);
    					}
    					switch(opcion){
    						case 1: 
    							registroempleado.vacaciones=true;
    							break;
    						case 2: 
    							registroempleado.enfermedades=true;
    							break;
    						case 3: 
    							registroempleado.diafestivo=true;
    							break;
    					}
    				}
    			}
    		}
	}

}



