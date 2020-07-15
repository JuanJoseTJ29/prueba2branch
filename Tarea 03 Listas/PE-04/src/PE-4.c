/*
 ============================================================================
 Name        : PE-4.c
 Author      : Quinteros Peralta, Rodrigo Ervin
 Version     : Final
 Copyright   : Your copyright notice
 Description : Escriba un programa para imprimir el número de elementos distintos de cero en la lista.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>

//Struct NODO
struct nodo {
	int dato;
	struct nodo *siguiente;
};

//Prototipos de Funcion
struct nodo *inicio = NULL;
struct nodo *crearLista(struct nodo *);
struct nodo *mostarLista(struct nodo *);

void menuPrincipal( );

//Funcion principal
int main(int argc, char *argv[]) {
	int opcion;
	do {
        menuPrincipal();
		scanf("%d", &opcion);
		switch(opcion){
			case 0://Si es 0 sale del while
				exit(1);
				break;
			case 1:
				inicio = crearLista(inicio);
				printf("\n !-->LISTA ENLAZADA CREADA!!!\n\n\n");
				system("pause");
				break;
			case 2:
				inicio = mostarLista(inicio);
				printf("\n");
				system("pause");
                break;
            default:
            	printf("\n --->ERROR!!!...DEBE ELEGIR UNA OPCION DADA EN EL MENU PRINCIPAL\n");
            	system("pause");
            	break;
		}
		system("cls");
	}while(opcion !=12);
	getch(); //	getch nos permite guardar una letra en una variable

	return 0;
}

//Funcion para crear Lista
struct nodo *crearLista(struct nodo *inicio){
	struct nodo *nuevo_node, *ptr;//variable de puntero PTR que apunta al nodo al que se está accediendo actualmente
	int num;
	int op=1;
	printf("\n\n\n *****CREAR LISTA*****");
	printf("\n ->Ingrese el dato: ");
	scanf("%d", &num);
	while(op!=2){
		nuevo_node = (struct nodo*)malloc(sizeof(struct nodo));
		nuevo_node -> dato=num;
		if(inicio==NULL){
			nuevo_node -> siguiente = NULL;
			inicio = nuevo_node;
		}
		else{
			ptr=inicio;
			while(ptr->siguiente!=NULL)
            ptr=ptr->siguiente;
			ptr->siguiente = nuevo_node;
			nuevo_node->siguiente=NULL;
		}
		do{
            printf("\n\tDesea Continuar?");
            printf("\n\t1:SI");
            printf("\n\t2:NO");
            printf("\n\tELIJA: ");
            scanf("%d",&op);
            if(op<1||op>2){
                printf("--->ERROR!!!...DEBE ELEGIR UNA OPCION DADA\n");
            }
		}while(op<1||op>2);
		if(op==1){
            printf("\n Ingrese el dato: ");
            scanf("%d", &num);
		}
	}
	return inicio;
}

//Funcion para mostrar Lista
//Escriba un programa para imprimir el número de elementos distintos de cero en la lista.
struct nodo *mostarLista(struct nodo *inicio){
    int a=0;
	struct nodo *ptr;
	printf("\n\n\n *****MOSTRAR LISTA*****\n\n");
	ptr = inicio;
	while(ptr != NULL){
		if(ptr->dato!=0){ //Distinto a Cero
			printf("\t%d", ptr -> dato);
			a=a+1;
		}
		ptr = ptr -> siguiente;
	}
	printf("\n\nNumero de Elementos: %d\n\n", a);
	return inicio;
}


void menuPrincipal(){
    printf("\n\n ***** MENU PRINCIPAL *****");
    printf("\n 1:  Crear una Lista");
    printf("\n 2:  Mostrar una Lista");
    printf("\n\n 0: SALIR");
    printf("\n\n INGRESAR UNA OPCION : ");
}
