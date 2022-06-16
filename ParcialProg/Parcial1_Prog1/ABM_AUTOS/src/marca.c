/*
 * marca.c
 *
 *  Created on: 16 may. 2022
 *      Author: Santt
 */

#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "fecha.h"
#include "marca.h"
#include "color.h"
#include "auto.h"
#include "servicio.h"
#include "trabajo.h"


int cargarMarcas(eMarca marcas[],int tam,int id,char descr[]){
	int retorno=0;

	if(marcas!=NULL && tam>0 && descr!=NULL){
		for(int i=0;i<tam;i++){
			if(marcas[i].id==id){
				strcpy(descr,marcas[i].descripcion);
				retorno=1;
				break;
			}
		}
	}

	return retorno;
}

int mostrarMarcas(eMarca marcas[],int tam){
	int retorno=0;

	if(marcas!=NULL && tam>0){
		printf("\n*** LISTA DE MARCAS ***\n");
		printf(" ID 		  DESCRIPCION\n");
		printf("---------------------------------\n");
		for(int i=0;i<tam;i++){
			printf("%d		%10s \n",marcas[i].id,marcas[i].descripcion);
		}
		retorno=1;
	}

	return retorno;
}

int buscarMarcas(eMarca marcas[],int tam,int id, int* pIndice){
	int retorno=0;

		if(marcas!=NULL && tam>0 && pIndice!=NULL){
			*pIndice=-1;

			for(int i=0;i<tam;i++){
				if(marcas[i].id==id){
					*pIndice=i;
					retorno=1;
					break;
				}
			}
		}

	return retorno;

}

int validarMarcas(eMarca marcas[],int tam,int id){
	int esValido = 0;
	int indice;

	if(buscarMarcas(marcas, tam, id, &indice)){
		if(indice != -1){
			esValido= 1;
		}
	}


	return esValido;
}
