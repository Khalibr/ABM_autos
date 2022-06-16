/*
 * auto.h
 *
 *  Created on: 16 may. 2022
 *      Author: Santt
 */

#ifndef AUTO_H_
#define AUTO_H_
#include <stdio.h>
#include <stdlib.h>
#include "servicio.h"
#include "marca.h"
#include "color.h"
#include "cliente.h"


typedef struct{
    int id;
    eCliente cliente;
    int idMarca; //validado-
    int idColor; //validado-
    char caja; //'m' manual, 'a' automatica - validado
    int isEmpty;
}eAuto;


#endif /* AUTO_H_ */

int inicializarAutos(eAuto nuevoAuto[],int tam);
int buscarLibre(eAuto nuevoAuto[],int tam,int* pIndice);
int hardcodeoAutos(eAuto nuevoAuto[],int tam,int cant, int* pProximoID);
//menu
char menuPrincipal();
char submenuModificar_NuevoAuto();

//Mostrar
void nuevoAuto_Indiv(eAuto nuevoAuto, eMarca n_Marca[],int tamM,eColor n_Color[],int tamC,eCliente cliente[],int tamCli);
void nuevoAuto_Fila(eAuto nuevoAuto, eMarca n_Marca[], int tamM, eColor n_Color[], int tamC,eCliente cliente[],int tamCli);
int nuevoAuto_Vec(eAuto nuevoAuto[],int tam,eMarca n_Marca[],int tamM, eColor n_Color[],int tamC,eCliente cliente[],int tamCli);

//alta
int alta_NuevoAuto(eAuto nuevoAuto[],int tam,eMarca n_Marca[],int tamMar,eColor n_Color[],int tamCol, int* pProximoID, int* pProximoIDCliente);

//baja
int bajaAuto(eAuto nuevoAuto[],int tam,eMarca n_Marca[],int tamM,eColor n_Color[],int tamC,eCliente cliente[],int tamCli);

//modificar
int modificar_NuevoAuto(eAuto nuevoAuto[],int tam, eMarca n_Marca[],int tamM, eColor n_Color[],int tamC,eCliente cliente[],int tamCli);

int validarAuto(eAuto autos[],int tam,int id);

//ordencerrado
int ordenarxID(eAuto autos[],int tam);

//informes
int ordenarAutoxColor(eAuto autos[],int tam, eMarca marcas[],int tamM ,eColor colores[], int tamC, eCliente clientes[],int tamCli);
int ordenarAutoxMarca(eAuto autos[],int tam, eMarca marcas[],int tamM ,eColor colores[], int tamC, eCliente clientes[],int tamCli);
int promedioCaja(eAuto autos[],int tam);
int separarPorCaja(eAuto autos[],int tam, eMarca marcas[], int tamM,eColor colores[], int tamC, eCliente clientes[], int tamCli, char caja);
int ordenarPorTipo(eAuto autos[],int tam, eMarca marcas[], int tamM, eColor colores[], int tamC, eCliente clientes[], int tamCli);
int ContadorMarca_Color(eAuto autos[],int tam, eMarca marcas[],int tamM, eColor colores[], int tamC, eCliente clientes[],int tamCli);
int contadorMarca(eAuto autos[],int tam,int idMarca, int* pTotalMarca);
int totalMarca(eAuto autos[],int tam,eMarca marcas[], int tamM);
