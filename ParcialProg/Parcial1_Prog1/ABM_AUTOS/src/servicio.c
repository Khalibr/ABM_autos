/*
 * servicio.c
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



int cargarServis(eServicio servis[],int tam,int id,char descr[]){
	int retorno=0;

	if(servis!=NULL && tam>0 && descr!=NULL){
		for(int i=0;i<tam;i++){
			if(servis[i].id==id){
				strcpy(descr,servis[i].descripcion);
				retorno=1;
				break;
			}
		}
	}

	return retorno;
}

int mostrarServis(eServicio servis[],int tam){
	int retorno=0;

		if(servis!=NULL && tam>0){
			printf("\n*** LISTA DE SERVICIOS ***\n");
			printf(" ID 	 DESCRIPCION	PRECIO\n");
			printf("---------------------------------\n");
			for(int i=0;i<tam;i++){
				printf("%d	%10s 	%3.2f\n",servis[i].id,servis[i].descripcion,servis[i].precio);
			}
			retorno=1;
		}

		return retorno;
}

int buscarServis(eServicio servis[],int tam,int id, int* pIndice){
	int retorno=0;

		if(servis!=NULL && tam>0 && pIndice!=NULL){
			*pIndice=-1;

			for(int i=0;i<tam;i++){
				if(servis[i].id==id){
					*pIndice=i;
					retorno=1;
					break;
				}
			}
		}

	return retorno;

}


int validarServis(eServicio servis[],int tam,int id){
	int esValido = 0;
	int indice;

	if(buscarServis(servis, tam, id, &indice)){
		if(indice != -1){
			esValido= 1;
		}
	}


	return esValido;
}
