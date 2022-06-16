/*
 * servicio.h
 *
 *  Created on: 16 may. 2022
 *      Author: Santt
 */

#ifndef SERVICIO_H_
#define SERVICIO_H_
#include <stdio.h>
#include <stdlib.h>


typedef struct{
    int id; //comienza en 20.000
    char descripcion[25];
    float precio;
}eServicio;


#endif /* SERVICIO_H_ */

int buscarServis(eServicio servis[],int tam,int id, int* pIndice);
int cargarServis(eServicio servis[],int tam,int id,char descr[]);
int mostrarServis(eServicio servis[],int tam);
int validarServis(eServicio servis[],int tam,int id);
