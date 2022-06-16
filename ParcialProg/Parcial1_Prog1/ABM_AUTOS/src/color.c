/*
 * color.c
 *
 *  Created on: 16 may. 2022
 *      Author: Santt
 */

#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "fecha.h"
#include "color.h"
/*
#include "marca.h"
#include "auto.h"
#include "servicio.h"
#include "trabajo.h"*/


int buscarColores(eColor colores[],int tam,int id, int* pIndice){
	int retorno=0;

		if(colores!=NULL && tam>0 && pIndice!=NULL){
			*pIndice=-1;

			for(int i=0;i<tam;i++){
				if(colores[i].id==id){
					*pIndice=i;
					retorno=1;
					break;
				}
			}
		}

	return retorno;

}

int cargarColores(eColor colores[],int tam,int id,char descr[]){
	int retorno=0;

	if(colores!=NULL && tam>0 && descr!=NULL){
		for(int i=0;i<tam;i++){
			if(colores[i].id==id){
				strcpy(descr,colores[i].nombreColor);
				retorno=1;
				break;
			}
		}
	}

	return retorno;
}

int mostrarColores(eColor colores[],int tam){
	int retorno=0;

	if(colores!=NULL && tam>0){
		printf("\n*** LISTA DE COLORES ***\n");
		printf(" ID 		  DESCRIPCION\n");
		printf("---------------------------------\n");
		for(int i=0;i<tam;i++){
			printf("%d		%10s \n",colores[i].id,colores[i].nombreColor);
		}
		retorno=1;
	}

	return retorno;
}

int validarColor(eColor colores[],int tam,int id){
	int esValido = 0;
	int indice;

	if(buscarColores(colores, tam, id, &indice)){
		if(indice != -1){
			esValido= 1;
		}
	}


	return esValido;
}
