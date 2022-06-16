/*
 * trabajo.c
 *
 *  Created on: 16 may. 2022
 *      Author: Santt
 *      idxmarca = fiat
 */

#include <stdio.h>
#include <stdlib.h>
#include "fecha.h"
#include "marca.h"
#include "color.h"
#include "auto.h"
#include "servicio.h"
#include "trabajo.h"


int inicializarTrabajo(eTrabajo trabajos[],int tam){
	int retorno=0;

    if(trabajos!=NULL && tam>0){
        for(int i=0;i<tam;i++){
            trabajos[i].isEmpty=1;
        }
        retorno=1;
    }

	return retorno;
}

int buscarLibreTrabajo(eTrabajo trabajos[],int tam,int* pIndice){
	int retorno=0;

	if(trabajos!=NULL && pIndice!=NULL && tam>0){
		*pIndice=-1;

		for(int i=0;i<tam;i++){
			if(trabajos[i].isEmpty){
				*pIndice=i;
			}
		}
		retorno=1;
	}

	return retorno;
}

int alta_NuevoTrabajo(eTrabajo trabajos[],int tam,eAuto nuevoAuto[],int tamA,eMarca n_Marca[],int tamMar,eColor n_Color[],int tamCol,eServicio n_Servis[],int tamSer,eCliente n_cliente[],int tamCli, int* pProximoID){
	int retorno=0;
	int indice;
	int idAuto;
	int idServis;

	eTrabajo altaTrabajo;
	eFecha fecha;

    if(trabajos!=NULL && nuevoAuto!=NULL && n_Color!=NULL && n_Color!=NULL && n_Servis!=NULL && tam>0 && tamMar>0 && tamCol>0 && tamSer>0 && pProximoID!=NULL){
        printf(" 		*** ALTA NUEVO TRABAJO ***\n");
    	buscarLibreTrabajo(trabajos, tam, &indice);

    	if(indice==-1){
    		printf("No hay lugar disponible en el sistema\n");
    	}
    	else{
    		altaTrabajo.id=*pProximoID;

    		nuevoAuto_Vec(nuevoAuto, tamA, n_Marca, tamMar, n_Color, tamCol, n_cliente,tamCli);
    		printf("Ingrese ID del auto: ");
    		scanf("%d",&idAuto);
    		while(!validarAuto(nuevoAuto, tamA, idAuto)){
    			printf("Id invalido, Reingrese id del auto: ");
				scanf("%d",&idAuto);
    		}
    		altaTrabajo.idAuto=idAuto;

			mostrarServis(n_Servis, tamSer);
			printf("Ingrese ID servis: ");
			scanf("%d",&idServis);
			while(!validarServis(n_Servis, tamSer, idServis)){
				printf("Id invalido, Reingrese id del servicio: ");
				scanf("%d",&idServis);
			}
			altaTrabajo.idServicio=idServis;

			printf("Ingrese Fecha dd/mm/aaaa: ");
			scanf("%d/%d/%d: ",
					&fecha.dia,
					&fecha.mes,
					&fecha.anio);

			altaTrabajo.fecha=fecha;



			altaTrabajo.isEmpty=0;
			trabajos[indice]=altaTrabajo;

			(*pProximoID)++;
			retorno=1;
    	}

    }

	return retorno;
}

void nuevoTrabajo_Fila(eTrabajo trabajo,eAuto n_Auto[],int tamA,eMarca n_Marca[],int tamM, eServicio n_Servis[], int tamS){

	char descripcionS[20];
	char descripcionM[20];

	cargarServis(n_Servis, tamS, trabajo.idServicio, descripcionS);
	cargarMarcas(n_Marca, tamM, trabajo.idAuto, descripcionM);

	printf("%d	%10s       %10s  	%02d/%02d/%d \n",
			trabajo.id,
			descripcionM,
			descripcionS,
			trabajo.fecha.dia,
			trabajo.fecha.mes,
			trabajo.fecha.anio);

}

int nuevoTrabajo_Vec(eTrabajo trabajo[],eAuto n_Auto[],int tamA,eMarca n_Marca[],int tamM, eServicio n_Servis[], int tamS){
	int retorno=0;
	int flag=1;

	    if(trabajo!=NULL && n_Servis!=NULL && n_Auto!=NULL && tamA>0 && tamS>0){
	    	printf("	*** LISTADO DE TRABAJOS ***\n\n");
	    	printf("ID	    Auto 	    Servicio      Fecha\n");
	    	printf("----------------------------------------------------\n");
	        for(int i=0;i<tamA;i++){
	            if(!trabajo[i].isEmpty){
	            	nuevoTrabajo_Fila(trabajo[i],n_Auto,tamA,n_Marca,tamM,n_Servis,tamS);
	            	flag=0;
	            }
	        }
	        if(flag){
	        	printf("No hay trabajos en el sistema");
	        }

	        retorno=1;
	    }

		return retorno;

}

int hardcodeoTrabajo(eTrabajo trabajo[],int tam,int cant, int* pProximoID){
    int retorno=0;

    eTrabajo trabajoHC[10]={
        {0,1002,20001,{20,20,2022},0},
        {0,1003,20000,{2,2,2022},0},
        {0,1004,20002,{02,02,2022},0},
        {0,1000,20003,{2,2,2022},0},
        {0,1001,20004,{2,2,2022},0},
        {0,1002,20001,{2,2,2022},0},
        {0,1003,20001,{2,2,2022},0},
        {0,1004,20001,{2,2,2022},0},
        {0,1002,20001,{2,2,2022},0},
        {0,1001,20001,{2,2,2022},0},
        };

    if(trabajo!=NULL && pProximoID!=NULL && tam>0 && tam<=10 && cant<=tam){
        for(int i=0;i<cant;i++){
            trabajo[i]=trabajoHC[i];
            trabajo[i].id=*pProximoID;
            (*pProximoID)++;
        }
        retorno=1;
    }

	return retorno;

}

