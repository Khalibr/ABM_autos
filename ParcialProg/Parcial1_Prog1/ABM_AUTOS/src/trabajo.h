/*
 * trabajo.h
 *
 *  Created on: 16 may. 2022
 *      Author: Santt
 */

#ifndef TRABAJO_H_
#define TRABAJO_H_
#include <stdio.h>
#include <stdlib.h>
#include "servicio.h"
#include "auto.h"
#include "marca.h"
#include "color.h"
#include "fecha.h"

typedef struct{
    int id; //autoincremental
    int idAuto; //debe exitir / validar
    int idServicio; // debe existir / validar
    eFecha fecha;
    int isEmpty;
}eTrabajo;

#endif /* TRABAJO_H_ */

int alta_NuevoTrabajo(eTrabajo trabajos[],int tam,eAuto nuevoAuto[],int tamA,eMarca n_Marca[],int tamMar,eColor n_Color[],int tamCol,eServicio n_Servis[],int tamSer,eCliente n_cliente[],int tamCli, int* pProximoID);
int buscarLibreTrabajo(eTrabajo trabajos[],int tam,int* pIndice);
int inicializarTrabajo(eTrabajo trabajos[],int tam);

void nuevoTrabajo_Fila(eTrabajo trabajo,eAuto n_Auto[],int tamA,eMarca n_Marca[],int tamM, eServicio n_Servis[], int tamS);
int nuevoTrabajo_Vec(eTrabajo trabajo[],eAuto n_Auto[],int tamA,eMarca n_Marca[],int tamM, eServicio n_Servis[], int tamS);

//
int hardcodeoTrabajo(eTrabajo trabajo[],int tam,int cant, int* pProximoID);

