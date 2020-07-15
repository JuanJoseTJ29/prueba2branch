/*
 ============================================================================
 Name        : PE-24.c
 Author      : Ingrid Fiorella, Cortez Rosas
 Version     : Final
 Copyright   : Your copyright notice
 Description : Escriba un programa para eliminar el nodo k_esimo de una lista enlazada.
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
struct nodo
{
    int dato;
    struct nodo *siguiente;
};
struct nodo *inicio = NULL;
struct nodo *crearlista(struct nodo *);
struct nodo *mostrarlista(struct nodo *);
struct nodo *eliminarnodoinicial(struct nodo *);
struct nodo *eliminarnodo(struct nodo *);
int main(int argc, char *argv[])
{
    int opcion;
    do
    {
        printf("\n\n *****EJERCICIO24****");
        printf("\n 1: Crear una lista");
        printf("\n 2: Mostrar la lista");
        printf("\n 3: Elininar nodo k_esimo");
        printf("\n 4: SALIR");
        printf("\n\n Imgrese una opcion : ");
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1:
            inicio = crearlista(inicio);
            printf("\n La lista fue creada con exito");
            break;
        case 2:
            inicio = mostrarlista(inicio);
            break;
        case 3:
            inicio = eliminarnodo(inicio);
            printf("\n El nodo fue eliminado");
            break;
        }
    }
    while(opcion !=4);
    getch();
    return 0;
}
struct nodo *crearlista(struct nodo *inicio)
{
    struct nodo *nuevonodo, *ptr;
    int num;
    int op;
    printf("\n ********CREAR LISTA********");
    printf("\n Ingrese un numero : ");
    scanf("%d", &num);
    while(op!= 2)
    {
        nuevonodo = (struct nodo*)malloc(sizeof(struct nodo));
        nuevonodo -> dato=num;
        if(inicio==NULL)
        {
            nuevonodo -> siguiente = NULL;
            inicio = nuevonodo;
        }
        else
        {
            ptr=inicio;
            while(ptr->siguiente!=NULL)
                ptr=ptr->siguiente;
            ptr->siguiente = nuevonodo;
            nuevonodo->siguiente=NULL;
        }
        do
        {
            printf("\n\tDesea continuar?");
            printf("\n\t1:Si");
            printf("\n\t2:No");
            printf("\n\tElija una opcion: ");
            scanf("%d",&op);
            if(op<1||op>2)
            {
                printf("Elejir una de las 2 opciones\n");
            }
        }
        while(op<1||op>2);
        if(op==1){
            printf("\n Ingrese un numero: ");
            scanf("%d", &num);
        }
    }
    return inicio;
}
struct nodo *mostrarlista(struct nodo *inicio)
{
    struct nodo *ptr;
    ptr = inicio;
    printf("\n ********LISTA********");
    while(ptr != NULL)
    {
        printf("\t %d", ptr -> dato);
        ptr = ptr -> siguiente;
    }
    return inicio;
}
struct nodo *eliminarnodoinicial(struct nodo *inicio)
{
    struct nodo *ptr;
    ptr = inicio;
    inicio = inicio -> siguiente;
    free(ptr);
    return inicio;
}
struct nodo *eliminarnodo(struct nodo *inicio)
{
    struct nodo *ptr, *anterior;
    int val;
    printf("\n ********ELIMINAR NODO********");
    printf("\n Ingrese la posicion del nodo que desea eliminar : ");
    scanf("%d", &val);
    ptr = inicio;
    if(ptr -> dato == val)
    {
        inicio = eliminarnodoinicial(inicio);
        return inicio;
    }
    else
    {
        while(ptr -> dato != val)
        {
            anterior = ptr;
            ptr = ptr -> siguiente;
        }
        anterior -> siguiente = ptr -> siguiente;
        free(ptr);
        return inicio;
    }
}
