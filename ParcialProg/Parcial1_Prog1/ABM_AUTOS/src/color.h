/*
 * color.h
 *
 *  Created on: 16 may. 2022
 *      Author: Santt
 */

#ifndef COLOR_H_
#define COLOR_H_
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int id;// comienza en 5000;
    char nombreColor[20];
}eColor;

#endif /* COLOR_H_ */

int buscarColores(eColor colores[],int tam,int id, int* pIndice);
int cargarColores(eColor colores[],int tam,int id,char descr[]);
int mostrarColores(eColor colores[],int tam);
int validarColor(eColor colores[],int tam,int id);

