/*
 * marca.h
 *
 *  Created on: 16 may. 2022
 *      Author: Santt
 */

#ifndef MARCA_H_
#define MARCA_H_
#include <stdio.h>
#include <stdlib.h>


typedef struct{
    int id;//comienza en 1000
    char descripcion[20];
}eMarca;


#endif /* MARCA_H_ */

int buscarMarcas(eMarca marcas[],int tam,int id, int* pIndice);
int cargarMarcas(eMarca marcas[],int tam,int id,char descr[]);
int mostrarMarcas(eMarca marcas[],int tam);
int validarMarcas(eMarca marcas[],int tam,int id);
