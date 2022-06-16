/*
 ============================================================================
 Name        : Main.c
 Author      : MEDINA JULIAN
 Div	     : 1G
 Copyright   : Your copyright notice
 Description : Primera etapa parcial 1°
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ctype.h"
#include "strings.h"
#include "fecha.h"
#include "marca.h"
#include "color.h"
#include "auto.h"
#include "servicio.h"
#include "trabajo.h"
#include "cliente.h"


#define TAM_CAR 10
#define TAM_TRA 10
#define TAM_CLI 10
#define TAM_MAR 5
#define TAM_COL 5
#define TAM_SER 4

int main(void) {
	setbuf(stdout,NULL);

	char salir = 'n';
	int proximoID=100;
	int proximoIdTra=500;
	int proximoIdCliente=200;
	int flag=0;
	eAuto nuevoAuto[TAM_CAR];
	eTrabajo nuevoTrabajo[TAM_TRA];
	eCliente cliente[TAM_CLI];

	eMarca marcas[TAM_MAR]={
			{1000,"Renault"},
			{1001,"Ford"},
			{1002,"Fiat"},
			{1003,"Chevrolet"},
			{1004,"Peugeot"},
	};
	eColor colores[TAM_COL]={
				{5000,"Negro"},
				{5001,"Blanco"},
				{5002,"Rojo"},
				{5003,"Verde"},
				{5004,"Azul"},
		};
	eServicio servis[TAM_SER]={
			{20000,"Lavado",450},
			{20001,"Pulido",500},
			{20002,"Encerado",600},
			{20003,"Completo",900},
	};


	inicializarAutos(nuevoAuto,TAM_CAR);
	inicializarTrabajo(nuevoTrabajo, TAM_TRA);

	if(hardcodeoAutos(nuevoAuto,TAM_CAR, 10,&proximoID)){
		flag=1;//activa la carga forzada case 'd'
	}
	hardcodeoTrabajo(nuevoTrabajo,TAM_TRA, 9,&proximoIdTra);


    printf("///////////////////////////////\n");
    printf("-Apellido Nombre: Medina Julian\n");
    printf("-Div:1G\n");
    printf("-ABM PARCIAL_1 \n");
    printf("///////////////////////////////\n");

	do{

		switch(menuPrincipal()){
			case 'a':
				if(alta_NuevoAuto(nuevoAuto, TAM_CAR, marcas, TAM_MAR, colores, TAM_COL ,&proximoID,&proximoIdCliente)){
					printf("CARGADO CON EXITO");
					flag=1;
				}
				else{
					printf("NO SE PUDO CARGAR LOS DATOS");
				}
				break;
			case 'b':
				if(flag){
					modificar_NuevoAuto(nuevoAuto, TAM_CAR,marcas, TAM_MAR,colores, TAM_COL,cliente,TAM_CLI);
				}
				else{
					printf("DEBE REALIZAR AL MENOS UN ALTA!\n");
				}
				break;
			case 'c':
				if(flag){
					bajaAuto(nuevoAuto, TAM_CAR, marcas, TAM_MAR, colores, TAM_COL,cliente,TAM_CLI);
				}
				else{
					printf("DEBE REALIZAR AL MENOS UN ALTA!\n");
				}
				break;
			case 'd':
				if(flag){
					system("cls");
					ordenarxID(nuevoAuto, TAM_CAR);
					nuevoAuto_Vec(nuevoAuto, TAM_CAR,marcas,TAM_MAR, colores, TAM_COL,cliente,TAM_CLI);
					system("pause");
				}
				else{
					printf("DEBE REALIZAR AL MENOS UN ALTA!\n");
				}
				break;
			case 'e':
				mostrarMarcas(marcas, TAM_MAR);
				break;
			case 'f':
				mostrarColores(colores, TAM_COL);
				break;
			case 'g':
				mostrarServis(servis, TAM_SER);
				break;
			case 'h':
				if(alta_NuevoTrabajo(nuevoTrabajo, TAM_TRA, nuevoAuto, TAM_CAR, marcas, TAM_MAR, colores, TAM_COL, servis, TAM_SER,cliente,TAM_CLI, &proximoIdTra)){
					printf("CARGADO CON EXITO");
				}
				else{
					printf("NO SE PUDO CARGAR LOS DATOS");
				}
				break;
			case 'i':
				nuevoTrabajo_Vec(nuevoTrabajo, nuevoAuto, TAM_CAR,marcas,TAM_MAR, servis, TAM_SER);
				break;
			case 'j':
				ordenarAutoxColor(nuevoAuto, TAM_CAR, marcas, TAM_MAR, colores, TAM_COL, cliente, TAM_CLI);
				break;
			case 'k':
				ordenarAutoxMarca(nuevoAuto, TAM_CAR, marcas, TAM_MAR, colores, TAM_COL, cliente, TAM_CLI);
				break;
			case 'l':
				promedioCaja(nuevoAuto,TAM_CAR);
				break;
			case 'm':
				ordenarPorTipo(nuevoAuto, TAM_CAR, marcas, TAM_MAR, colores, TAM_COL, cliente, TAM_CLI);
				break;
			case 'n':
				ContadorMarca_Color(nuevoAuto, TAM_CAR, marcas, TAM_MAR, colores, TAM_COL, cliente, TAM_CLI);
				break;
			case 'o':
				totalMarca(nuevoAuto, TAM_CAR, marcas, TAM_MAR);
				break;
			case 'z':
				printf("Desea salir S/N\n");
				fflush(stdin);
				scanf("%c",&salir);
				salir=tolower(salir);
				break;

		}
		system("cls");
	}while(salir !='s');


	return EXIT_SUCCESS;
}
