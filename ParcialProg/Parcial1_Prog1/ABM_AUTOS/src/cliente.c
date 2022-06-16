/*
 * cliente.c
 *
 *  Created on: 20 may. 2022
 *      Author: Santt
 */
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "cliente.h"

int cargarCliente(eCliente cliente[],int tam,int id,char descr[]){
	int retorno=0;


	if(cliente!=NULL && tam>0 && descr!=NULL){
		for(int i=0;i<tam;i++){
			if(cliente[i].id==id){
				strcpy(descr,cliente[i].nombre);
				retorno=1;
				break;
			}
		}
	}

	return retorno;
}

