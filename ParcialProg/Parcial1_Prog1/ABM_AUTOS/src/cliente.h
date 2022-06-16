/*
 * cliente.h
 *
 *  Created on: 20 may. 2022
 *      Author: Santt
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_

typedef struct{
	int id;
	char nombre[20];
	char sexo;
}eCliente;



#endif /* CLIENTE_H_ */

int cargarCliente(eCliente cliente[],int tam,int id,char descr[]);
