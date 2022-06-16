/*
 * auto.c
 *
 *  Created on: 16 may. 2022
 *      Author: Santt
 */

#include <stdio.h>
#include <stdlib.h>
#include "ctype.h"
#include "fecha.h"
#include "marca.h"
#include "color.h"
#include "auto.h"
#include "servicio.h"
#include "trabajo.h"
#include "cliente.h"
#include "string.h"


int inicializarAutos(eAuto nuevoAuto[],int tam){
	int retorno=0;

    if(nuevoAuto!=NULL && tam>0){
        for(int i=0;i<tam;i++){
            nuevoAuto[i].isEmpty=1;
        }
        retorno=1;
    }

	return retorno;
}
int buscarLibre(eAuto nuevoAuto[],int tam,int* pIndice){
	int retorno=0;

	if(nuevoAuto!=NULL && pIndice!=NULL && tam>0){
		*pIndice=-1;

		for(int i=0;i<tam;i++){
			if(nuevoAuto[i].isEmpty){
				*pIndice=i;
			}
		}
		retorno=1;
	}

	return retorno;
}



int hardcodeoAutos(eAuto nuevoAuto[],int tam,int cant, int* pProximoID){
    int retorno=0;

    eAuto autosHC[10]={
        {0,{0,"ana",'f'},1000,5000,'a',0},
        {0,{0,"juan",'m'},1001,5001,'a',0},
        {0,{0,"roberto",'m'},1002,5002,'a',0},
        {0,{0,"juana",'f'},1003,5003,'m',0},
        {0,{0,"maria",'f'},1003,5004,'a',0},
        {0,{0,"alberto",'m'},1000,5001,'m',0},
        {0,{0,"pedro",'m'},1001,5002,'a',0},
        {0,{0,"jorge",'m'},1002,5003,'m',0},
        {0,{0,"alicia",'f'},1003,5004,'a',0},
        {0,{0,"horacio",'m'},1004,5004,'m',0},
        };

    if(nuevoAuto!=NULL && pProximoID!=NULL && tam>0 && tam<=10 && cant<=tam){
        for(int i=0;i<cant;i++){
            nuevoAuto[i]=autosHC[i];
            nuevoAuto[i].id=*pProximoID;
            (*pProximoID)++;
        }
        retorno=1;
    }

	return retorno;


}

char menuPrincipal(){
    char opcion;

    printf("\n*******************************\n");
	printf("	MENU PRINCIPAL\n");
	printf("*******************************\n");
    printf("\nA. ALTA AUTO\n");
    printf("B. MODIFICAR AUTO\n");
    printf("C. BAJA AUTO\n");
    printf("D. LISTAR AUTOS\n");
    printf("E. LISTAR MARCAS\n");
    printf("F. LISTAR COLORES\n");
    printf("G. LISTAR SERVICIOS\n");
    printf("H. ALTA TRABAJO\n");
    printf("I. LISTAR TRABAJOS\n");
	printf("\n *** INFORMES *** \n\n");
	printf("J- AUTOS DEL MISMO COLOR\n");
	printf("K- AUTOS DE LA MISMA MARCA\n");
	printf("L- PROMEDIO DE AUTOS CON CAJA MANUAL Y CON CAJA AUTOMATICA\n");
	printf("M- LISTADO DE AUTO POR TIPO DE CAJA\n");
	printf("N- MOSTRAR POR COLOR, MARCA Y SUS RESPECTIVAS CANTIDADES\n");
	printf("O- MOSTRAR UNA O MAS MARCAS\n");
    printf("\nIngrese opcion: ");

    fflush(stdin);
    scanf("%c",&opcion);
    opcion=tolower(opcion);

    return opcion;
}

void nuevoAuto_Indiv(eAuto nuevoAuto, eMarca n_Marca[],int tamM,eColor n_Color[],int tamC,eCliente cliente[],int tamCli){
	char descripcionM[20];
	char descripcionC[20];

	cargarMarcas(n_Marca, tamM, nuevoAuto.idMarca, descripcionM);
	cargarColores(n_Color, tamC, nuevoAuto.idColor, descripcionC);

	printf("ID del auto: %d\n",nuevoAuto.id);
	printf("Dueño/a: %s\n",nuevoAuto.cliente.nombre);
	printf("ID color: %s\n",descripcionC);
	printf("ID marca: %s\n",descripcionM);
	printf("Tipo de caja: %c\n",nuevoAuto.caja);


}



int nuevoAuto_Vec(eAuto nuevoAuto[],int tam,eMarca n_Marca[],int tamM, eColor n_Color[],int tamC,eCliente cliente[],int tamCli){
	int retorno=0;
	int flag=1;

	    if(nuevoAuto!=NULL && n_Color!=NULL && n_Marca!=NULL && cliente!= NULL && tamCli>0 && tam>0 && tamM>0 && tamC>0 ){
	    	printf("			*** LISTADO DE AUTOS ***\n\n");
	    	printf("ID 	     dueño/a 	       idColor       idMarca	  Caja   \n");
	    	printf("--------------------------------------------------------------\n");
	        for(int i=0;i<tam;i++){
	            if(!nuevoAuto[i].isEmpty){
					nuevoAuto_Fila(nuevoAuto[i],n_Marca,tamM,n_Color,tamC,cliente,tamCli);
					flag=0;
	            }
	        }
	        if(flag){
	        	printf("No hay autos en el sistema");
	        }

	        retorno=1;
	    }

		return retorno;

}

void nuevoAuto_Fila(eAuto nuevoAuto, eMarca n_Marca[], int tamM, eColor n_Color[], int tamC,eCliente cliente[],int tamCli){

	char descripcionC[20];
	char descripcionM[20];

	cargarMarcas(n_Marca, tamM, nuevoAuto.idMarca, descripcionM);
	cargarColores(n_Color, tamC, nuevoAuto.idColor, descripcionC);

	printf("%02d 	 %10s 	   %10s 	  %10s 	   %c \n",
			nuevoAuto.id,
			nuevoAuto.cliente.nombre,
			descripcionC,
			descripcionM,
			nuevoAuto.caja
			);

}

int alta_NuevoAuto(eAuto nuevoAuto[],int tam,eMarca n_Marca[],int tamMar,eColor n_Color[],int tamCol, int* pProximoID, int* pProximoIDCliente){
	int retorno=0;
	int indice;
	eAuto altaAuto;
	eCliente n_Cliente;
	int marca;
	int color;
	char caja;

    if(nuevoAuto!=NULL && n_Color!=NULL && n_Color!=NULL && tam>0 && tamMar>0 && tamCol>0 && pProximoID!=NULL && pProximoIDCliente!=NULL){
        printf(" 		*** ALTA NUEVO AUTO ***\n");
    	buscarLibre(nuevoAuto, tam, &indice);

    	if(indice==-1){
    		printf("No hay lugar disponible en el sistema\n");
    	}
    	else{
    		altaAuto.id=*pProximoID;
    		altaAuto.cliente.id=*pProximoIDCliente;

    		printf("Ingrese nombre: ");
    		fflush(stdin);
    		gets(n_Cliente.nombre);

    		printf("Ingrese sexo:");
    		fflush(stdin);
    		scanf("%c",&n_Cliente.sexo);

    		altaAuto.cliente=n_Cliente;

    		mostrarMarcas(n_Marca, tamMar);
    		printf("Ingrese ID marca: ");
    		scanf("%d",&marca);
    		while(!validarMarcas(n_Marca, tamMar, marca)){
    			printf("Id invalido, Reingrese id de la marca: ");
				scanf("%d",&marca);
    		}
    		altaAuto.idMarca=marca;

    		mostrarColores(n_Color, tamCol);
    		printf("Ingrese ID color: ");
			scanf("%d",&color);
			while(!validarColor(n_Color, tamCol, color)){
				printf("Id invalido, Reingrese id del color: ");
				scanf("%d",&color);
			}
			altaAuto.idColor=color;


			printf("- Caja Automatica 'a'\n");
			printf("- Caja Manual 'm'\n");
			printf("Ingrese el tipo de caja: ");
			fflush(stdin);
			scanf("%c",&caja);
			while(caja!='a' && caja!='m'){
				printf("- Caja Automatica 'a'\n");
				printf("- Caja Manual 'm'\n");
				printf("ERROR. Reingrese el tipo de caja: ");
				fflush(stdin);
				scanf("%c",&caja);
			}

			altaAuto.caja=caja;

			altaAuto.isEmpty=0;
			nuevoAuto[indice]=altaAuto;

			(*pProximoID)++;
			(*pProximoIDCliente)++;
			retorno=1;
    	}
    }

	return retorno;
}

int buscarAuto(eAuto n_Auto[],int tam,int id, int* pIndice){
	int retorno=0;

	if(n_Auto!=NULL && tam>0 && pIndice!=NULL){
		*pIndice=-1;

		for(int i=0;i<tam;i++){
			if(!n_Auto[i].isEmpty && n_Auto[i].id==id){
				*pIndice=i;
				break;
			}
		}
		retorno=1;
	}

	return retorno;
}
int bajaAuto(eAuto nuevoAuto[],int tam,eMarca n_Marca[],int tamM,eColor n_Color[],int tamC,eCliente cliente[],int tamCli){
	int retorno=0;
	int indice;
	int id;
	char confirmar;

	if(nuevoAuto!=NULL && n_Marca!=NULL && n_Color!=NULL && cliente!= NULL && tamCli>0  && tam>0 && tamM>0 && tamC>0){
		nuevoAuto_Vec(nuevoAuto, tam, n_Marca, tamM, n_Color, tamC,cliente,tamCli);

		printf("\n       *** BAJA AUTO ***\n\n");
		printf("Ingresar ID: ");
		scanf("%d",&id);

		if(buscarAuto(nuevoAuto, tam, id, &indice)){
			if(indice==-1){
				printf("NO EXISTE EL AUTO CON EL ID: %d EN EL SISTEMA\n",id);
			}
			else{
				nuevoAuto_Indiv(nuevoAuto[indice], n_Marca, tamM, n_Color, tamC,cliente,tamCli);
				printf("Confirmar baja?: ");
				fflush(stdin);
				scanf("%c",&confirmar);
				if(confirmar=='s' || confirmar=='S'){
					nuevoAuto[indice].isEmpty=1;
					printf("Baja exitosa!!!\n");
				}
				else{
					printf("Baja cancela por el usuario\n");
				}
			}
			retorno=1;
		}

	}

	return retorno;
}

char submenuModificar_NuevoAuto(){
	char opcion;
	printf("\n		*** CAMPO A MODIFICAR ***    \n\n");
	printf("A. MODIFICAR COLOR\n");
	printf("B. MODIFICAR MARCA\n");
	printf("C. MODIFICAR CAJA\n");
	printf("D. VOLVER MENU PRINCIPAL\n");
	printf("Ingrese opcion: ");
	fflush(stdin);

	scanf("%c", &opcion);
	opcion=tolower(opcion);
	return opcion;
}

int modificar_NuevoAuto(eAuto nuevoAuto[],int tam, eMarca n_Marca[],int tamM, eColor n_Color[],int tamC,eCliente cliente[],int tamCli){
	int retorno=0;
	int id;
	int indice;
	int idMarca;
	int idColor;
	char caja;

	if (nuevoAuto!=NULL && n_Marca!=NULL && n_Color!=NULL && cliente!= NULL && tamCli>0 && tam>0 && tamM>0 && tamC>0) {
		nuevoAuto_Vec(nuevoAuto, tam, n_Marca, tamM, n_Color, tamC,cliente, tamCli);

		printf("\n\n--------------- MODIFICAR AUTO --------------\n\n");

		printf("Ingrese id del auto: ");
		scanf("%d", &id);

		if (buscarAuto(nuevoAuto, tam, id, &indice)) {
			if (indice == -1) {
				printf("No existe un auto con id: %d en el sistema\n", id);
			} else {
				nuevoAuto_Indiv(nuevoAuto[indice], n_Marca, tamM, n_Color, tamC,cliente, tamCli);
				switch (submenuModificar_NuevoAuto()){
					case 'a':
						mostrarColores(n_Color, tamC);
						printf("Ingrese ID color: ");
						scanf("%d",&idColor);
						while(!validarColor(n_Color, tamC, idColor)){
							printf("Id invalido, Reingrese id del color: ");
							scanf("%d",&idColor);
						}

						nuevoAuto[indice].idColor=idColor;
						printf("Color modificado con exito!\n");
						break;
					case 'b':
						mostrarMarcas(n_Marca, tamM);
						printf("Ingrese ID marca: ");
						scanf("%d",&idMarca);
						while(!validarMarcas(n_Marca, tamM, idMarca)){
							printf("Id invalido, Reingrese id de la marca: ");
							scanf("%d",&idMarca);
						}

						nuevoAuto[indice].idMarca=idMarca;
						printf("Marca modificada con exito!\n");
						break;
					case 'c':
						printf("- Caja Automatica 'a'\n");
						printf("- Caja Manual 'm'\n");
						printf("Ingrese el tipo de caja: ");
						fflush(stdin);
						scanf("%c",&caja);

						while(caja!='a' && caja!='m'){
							printf("- Caja Automatica 'a'\n");
							printf("- Caja Manual 'm'\n");
							printf("ERROR. Reingrese el tipo de caja: ");
							fflush(stdin);
							scanf("%c",&caja);
						}

						nuevoAuto[indice].caja=caja;
						printf("Caja Modificada con exito!\n");
						break;
				}

			}
			retorno = 1;
		}

	}

	return retorno;
}


int validarAuto(eAuto autos[],int tam,int id){
	int esValido = 0;
	int indice;

	if(buscarAuto(autos, tam, id, &indice)){
		if(indice != -1){
			esValido= 1;
		}
	}


	return esValido;
}

int ordenarxID(eAuto autos[],int tam){
	int retorno=0;
	eAuto aux;

	if(autos!=NULL && tam>0){
		for(int i=0;i<tam-1;i++){
			for(int j=i+1;j<tam;j++){
				if(autos[i].id>autos[j].id){
					aux=autos[i];
					autos[i]=autos[j];
					autos[j]=aux;
				}
			}
		}
		retorno=1;
	}

	return retorno;
}


//2da parte de

int ordenarAutoxColor(eAuto autos[],int tam, eMarca marcas[],int tamM ,eColor colores[], int tamC, eCliente clientes[],int tamCli){
	int retorno=0;
	int idColor;
	int flag=1;
	char descripcionCol[20];

	if(autos!=NULL && marcas!=NULL && colores!=NULL && clientes!=NULL && tam>0 && tamM>0 && tamC>0 && tamCli>0){
		printf("*** INFORME DE AUTOS POR COLOR ***\n");
		printf("-----------------------------------\n");

		mostrarColores(colores, tamC);
		printf("Ingrese ID del color: ");
		scanf("%d",&idColor);
		while(!validarColor(colores, tamC, idColor)){
			printf("ID invalido. Ingrese ID del color: ");
			scanf("%d",&idColor);
		}

		cargarColores(colores, tamC, idColor, descripcionCol);
		printf("Autos del color: %s\n\n",descripcionCol);

		printf("			*** LISTADO DE AUTOS ***\n\n");
		printf("ID 	     dueño/a 	       idColor       idMarca	  Caja   \n");
		printf("--------------------------------------------------------------\n");
		for(int i=0;i<tam;i++){
			if(!autos[i].isEmpty && autos[i].idColor == idColor){
				nuevoAuto_Fila(autos[i], marcas, tamM, colores, tamC, clientes, tamCli);
				flag=0;
			}
		}
		if(flag){
			printf("NO HAY AUTOS DEL COLOR %s EN EL SISTEMA\n\n",descripcionCol);
		}

		retorno = 1;
	}

	return retorno;
}

int ordenarAutoxMarca(eAuto autos[],int tam, eMarca marcas[],int tamM ,eColor colores[], int tamC, eCliente clientes[],int tamCli){
	int retorno = 0;
	int flag = 1;
	int idMarca;
	char descripcionMar[20];

	if(autos!=NULL && marcas!=NULL && colores!=NULL && clientes!=NULL && tam>0 && tamM>0 && tamC>0 && tamCli>0){
		printf("*** INFORME DE AUTOS POR MARCA ***\n");
		printf("-----------------------------------\n");

		mostrarMarcas(marcas, tamM);
		printf("Ingrese ID de la marca: ");
		scanf("%d",&idMarca);
		while(!validarMarcas(marcas, tamM, idMarca)){
			printf("ID invalido. Reingrese ID de la marca: ");
			scanf("%d",&idMarca);
		}

		cargarMarcas(marcas, tamM, idMarca, descripcionMar);
		printf("Autos de la marca: %s\n\n",descripcionMar);


		printf("			*** LISTADO DE AUTOS ***\n\n");
		printf("ID 	     dueño/a 	       idColor       idMarca	  Caja   \n");
		printf("--------------------------------------------------------------\n");
		for(int i=0;i<tam;i++){
			if(!autos[i].isEmpty && autos[i].idMarca == idMarca){
				nuevoAuto_Fila(autos[i], marcas, tamM, colores, tamC, clientes, tamCli);
				flag=0;
			}
		}
		if(flag){
			printf("No hay autos de la marca %s en el sistema\n\n",descripcionMar);
		}

		retorno = 1;
	}

	return retorno;

}

int promedioCaja(eAuto autos[],int tam){
	int retorno=0;
	int contador=0;
	float acumM=0;
	float acumA=0;
	float promedioM=0;
	float promedioA=0;

	if(autos!=NULL && tam>0){
		for(int i=0;i<tam;i++){
			if(!autos[i].isEmpty){
				acumM+=autos[i].caja=='m';
				acumA+=autos[i].caja=='a';
				contador++;
			}
		}
	}

	if(contador!=0){
		promedioM=acumM/contador;
		promedioA=acumA/contador;
	}

	printf("\n *** PROMEDIO DE AUTOS CON CAJA MANUAL Y AUTOMATICA *** \n");
	printf("-Promedio de autos con caja 'Manual': %.2f\n",promedioM);
	printf("-Promedio de autos con caja 'Automatica': %.2f\n\n",promedioA);


	return retorno;
}

int ordenarPorTipo(eAuto autos[],int tam, eMarca marcas[], int tamM, eColor colores[], int tamC, eCliente clientes[], int tamCli){
	int retorno=0;

	if(autos!=NULL && colores!=NULL && marcas!=NULL && clientes!= NULL && tamCli>0 && tam>0 && tamM>0 && tamC>0 ){
		printf("		*** LISTADO DE AUTOS POR TIPO DE CAJA ***\n\n");
		printf("ID 	     dueño/a 	       idColor       idMarca	  Caja   \n");
		printf("--------------------------------------------------------------\n");
		printf("--------------------*** CAJA AUTOMATICA ***-------------------\n");
		separarPorCaja(autos, tam, marcas, tamM, colores, tamC, clientes, tamCli, 'a');
		printf("--------------------*** CAJA MANUAL ***-----------------------\n");
		separarPorCaja(autos, tam, marcas, tamM, colores, tamC, clientes, tamCli, 'm');




	}


	return retorno;
}
int separarPorCaja(eAuto autos[],int tam, eMarca marcas[], int tamM,eColor colores[], int tamC, eCliente clientes[], int tamCli, char caja){
	int retorno=0;

	if(autos!=NULL && marcas!=NULL && colores!=NULL && clientes!=NULL && tam>0 && tamM>0 && tamC>0 && tamCli>0){
		for(int i=0;i<tam;i++){
			if(!autos[i].isEmpty && autos[i].caja==caja){
				nuevoAuto_Fila(autos[i], marcas, tamM, colores, tamC, clientes, tamCli);
			}
		}
		retorno = 1;
	}


	return retorno;
}

int ContadorMarca_Color(eAuto autos[],int tam, eMarca marcas[],int tamM, eColor colores[], int tamC, eCliente clientes[],int tamCli){
	int retorno=0;
	int contador=0;
	int flag=1;
	int idColor;
	int idMarca;
	char descripcionCol[20];
	char descripcionMar[20];

	if(autos!=NULL && marcas!=NULL && colores!=NULL && clientes!=NULL && tam>0 && tamM>0 && tamC>0 && tamCli>0){
		mostrarColores(colores, tamC);
		printf("Ingrese ID del color: ");
		scanf("%d",&idColor);
		while(!validarColor(colores, tamC, idColor)){
			printf("ID Invalido. Reingrese ID del color: ");
			scanf("%d",&idColor);
		}

		mostrarMarcas(marcas, tamM);
		printf("Ingrese ID de la marca: ");
		scanf("%d",&idMarca);
		while(!validarMarcas(marcas, tam, idMarca)){
			printf("ID Invalido. Reingrese ID del color: ");
			scanf("%d",&idMarca);
		}


		cargarColores(colores, tamC, idColor, descripcionCol);
		cargarMarcas(marcas, tamM, idMarca, descripcionMar);
		printf("Autos de la marca %s de color %s\n\n",descripcionMar, descripcionCol);


		printf("	*** CANTIDAD DE AUTOS POR COLOR Y MARCA SELECCIONADA ***\n\n");
		printf("--------------------------------------------------------------\n");
		for(int i=0;i<tam;i++){
			if(!autos[i].isEmpty && autos[i].idMarca == idMarca && autos[i].idColor == idColor){
				contador++;
				flag=0;
			}
		}
		if(flag){
			printf("No hay autos de la marca %s y de color %s en el sistema\n\n",descripcionMar,descripcionCol);
		}

		printf("Autos de la marca %s y de color %s hay en total: %d\n",descripcionMar,descripcionCol,contador);
		printf("--------------------------------------------------------------\n\n");
		retorno = 1;

	}

	return retorno;
}

int totalMarca(eAuto autos[],int tam,eMarca marcas[], int tamM){//MIRAR
	int retorno=0;
	int total[tamM];
	int flag = 1;
	int mayor;
	char descripcionM[20];

	if(autos!=NULL && marcas!=NULL && tam>0 && tamM>0){
		for(int i=0;i<tamM;i++){
			total[i]=0;
		}
		for(int i=0;i<tamM;i++){
			contadorMarca(autos, tam, marcas[i].id, &total[i]);
		}
		for(int i=0;i<tamM;i++){
			if(flag || total[i]>mayor){
				mayor = total[i];
				flag = 0;
			}
		}


		printf("La o las marcas mas elegidas: ");
		for(int i=0;i<tamM;i++){
			cargarMarcas(marcas, tamM, marcas[i].id, descripcionM);
			if(total[i] == mayor){
				printf("%s\n",descripcionM);
			}
		}
		retorno=1;
	}


	return retorno;
}

int contadorMarca(eAuto autos[],int tam,int idMarca, int* pTotalMarca){
	int retorno=0;
	int contador=0;

	if(autos!=NULL && pTotalMarca!=NULL && tam>0){
		for(int i=0;i<tam;i++){
			if(!autos[i].isEmpty && autos[i].idMarca==idMarca){
				contador++;
			}
		}
		*pTotalMarca=contador;
		retorno=1;
	}

	return retorno;
}
