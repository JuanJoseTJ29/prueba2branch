/*
 ============================================================================
 Name        : RQ-5.c
 Author      : Cortez Rosas, Ingrid Fiorella
 Version     : Final
 Copyright   : Your copyright notice
 ============================================================================
 */


#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <stdlib.h>

struct nodo
{
    int num;
    int exponente1;
    int exponente2;
    struct nodo *siguiente;
};
struct nodo *inicio = NULL;
struct nodo *crearpolinomio(struct nodo *);
struct nodo *mostrarpolinomio(struct nodo *);
int main()
{
    int opcion;
    do
    {
        printf("\n******** EJERCICIO 5 *********");
        printf("\n 1. Ingrese el polinomio");
        printf("\n 2. Mostrar el polinomio");
        printf("\n 3. SALIR");
        printf("\n\n Ingrese una opcion : ");
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1:
            inicio = crearpolinomio(inicio);
            printf("El polinomio fue creado con exito...!!!");
            break;
        case 2:
            inicio = mostrarpolinomio(inicio);
            break;
        }
    }
    while(opcion!=3);
    getch();
    return 0;
}
struct nodo *crearpolinomio(struct nodo *inicio)
{
    struct nodo *nuevonodo, *ptr;
    int n, ex1, ex2;
    int op;
    printf("\n ***** Crear el polinomio *****");
    printf("\n Ingrese un numero : ");
    scanf("%d", &n);
    printf("\t Ingrese el exponente para X : ");
    scanf("%d", &ex1);
    printf("\t Ingrese el exponente para Y : ");
    scanf("%d", &ex2);
    while(op != 2)
    {
        if(inicio==NULL)
        {
            nuevonodo = (struct nodo *)malloc(sizeof(struct nodo));
            nuevonodo -> num = n;
            nuevonodo -> exponente1 = ex1;
            nuevonodo -> exponente2 = ex2;
            nuevonodo -> siguiente = NULL;
            inicio = nuevonodo;
        }
        else
        {
            ptr = inicio;
            while(ptr -> siguiente != NULL)
                ptr = ptr -> siguiente;
            nuevonodo = (struct nodo *)malloc(sizeof(struct nodo));
            nuevonodo -> num = n;
            nuevonodo -> exponente1 = ex1;
            nuevonodo -> exponente2 = ex2;
            nuevonodo -> siguiente = NULL;
            ptr -> siguiente = nuevonodo;
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
        if(op==1)
        {
            printf("\n Ingrese un numero : ");
            scanf("%d", &n);
            if(n == -1)
                break;
            printf("\n Ingrese el exponente para X: ");
            scanf("%d", &ex1);

            printf("\n Ingrese el exponente para Y : ");
            scanf("%d", &ex2);
        }
    }
    return inicio;
}
struct nodo *mostrarpolinomio(struct nodo *inicio)
{
    struct nodo *ptr;
    ptr = inicio;
    while(ptr != NULL)
    {
        printf("%d X^%dY^%d  ", ptr -> num, ptr -> exponente1, ptr -> exponente2);
        ptr = ptr -> siguiente;
    }
    return inicio;
}
