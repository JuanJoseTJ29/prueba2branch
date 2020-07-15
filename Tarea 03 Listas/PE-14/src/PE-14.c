/*
 ============================================================================
 Name        : PE-14.c
 Author      : Tirado Julca, Juan Jose
 Version     : Final
 Copyright   : Your copyright notice
 Description : Escriba un programa:
              (1) Eliminar la primera aparición de un determinado
                  elemento en una lista enlazada
              (2) Eliminar la última aparición de un elemento dado
              (3) Eliminar todas las ocurrencias de un elemento dado

 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>


struct nodo
{
    int dato;
    struct nodo *siguiente;
} * head;



void crearLista(int n);
void borrarPrimerElem(int key);
void borrarUltimoElem(int key);
int borrarTodosElem(int key);
void mostrarLista();

int main()
{
    int n, key;

     int opcion;


     do{


    printf("\n********* MENU *********");
    printf("\n0. Eliminar la primera aparicion de un determinado elemento ");
    printf("\n1. Eliminar la ultima aparicion de un elemento dado");
    printf("\n2. Eliminar todas las ocurrencias de un elemento dado");
    printf("\n3. Salir del programa");
    printf("\n\nIngrese un numero de las opciones del menu:  ");

    scanf("%d",&opcion);


    switch(opcion){

        case 0:

                printf("Ingrese el numero de nodos a crear: ");
                scanf("%d", &n);
                crearLista(n);
                printf("\nLista antes de borrar\n");
                mostrarLista();
                printf("\nIngrese el numero que desea borrar: ");
                scanf("%d", &key);
                borrarPrimerElem(key);


                printf("\nLista despues de borrar\n");
                mostrarLista();
                break;


        case 1:

                printf("Ingrese el numero de nodos a crear:  ");
                scanf("%d", &n);
                crearLista(n);

                printf("\nLista antes de borrar\n");
                mostrarLista();

                printf("\nIngrese el numero que desea borrar: ");
                scanf("%d", &key);


                borrarUltimoElem(key);


                printf("\nLista despues de borrar\n");
                mostrarLista();


                break;


        case 2:

               printf("Ingrese el numero de nodos a crear:  ");
               scanf("%d", &n);
               crearLista(n);

               printf("\nLista antes de borrar\n");
               mostrarLista();

               printf("\nIngrese el numero que desea borrar: ");
               scanf("%d", &key);

               borrarTodosElem(key);

              printf("\nLista despues de borrar\n");
              mostrarLista();
              break;

     case 3:
                    printf("\nPrograma finalizado");
                    break;

    default:
                 printf("\nOpcion incorrecta.");
                 getchar();
        }
}while(opcion!=3);
    getchar();
    getchar();
}




void crearLista(int n){
    struct nodo *nuevoNodo, *temp;
    int dato, i;

    head = malloc(sizeof(struct nodo));


    if (head == NULL){
        printf("No se puede asignar memoria");
        exit(0);
    }



    printf("Ingrese un numero en el nodo 1:");
    scanf("%d", &dato);

    head->dato = dato;
    head->siguiente = NULL;

    temp = head;


    for (i = 2; i <= n; i++){
        nuevoNodo = malloc(sizeof(struct nodo));


        if (nuevoNodo == NULL){
            printf("No se puede asignar memoria");
            exit(0);
        }

        printf("Ingrese un numero en el nodo %d:", i);
        scanf("%d", &dato);

        nuevoNodo->dato = dato;
        nuevoNodo->siguiente = NULL;

        temp->siguiente = nuevoNodo;
        temp = temp->siguiente;
    }

return;
}



void mostrarLista(){
    struct nodo *temp;


    if (head == NULL){
        printf("La lista esta vacia.\n");
        return;
    }

    temp = head;
    while (temp != NULL){
        printf("%d ", temp->dato);

        temp = temp->siguiente;
    }

    printf("\n");
return ;
}



void borrarPrimerElem(int key){
    struct nodo *prev, *cur;

    while (head != NULL && head->dato == key){

        prev = head;
        head = head->siguiente;
        free(prev);
        return;
    }

    prev = NULL;
    cur  = head;

    while (cur != NULL){

        if (cur->dato == key){

            if (prev != NULL)
                prev->siguiente = cur->siguiente;


            free(cur);


            return;
        }

        prev = cur;
        cur = cur->siguiente;
    }
}

void borrarUltimoElem(int key){
    struct nodo *prevUltimo, *ultimoNodoBorr, *prev, *cur;

    prev = NULL;
    prevUltimo    = NULL;
    ultimoNodoBorr = NULL;


    if (head != NULL && head->dato == key){

        ultimoNodoBorr = head;
    }

    cur = head;


    while (cur != NULL){

        if (cur->dato == key){
            ultimoNodoBorr = cur;

            if (prev != NULL) {
                prevUltimo = prev;
            }
        }
        prev = cur;
        cur = cur->siguiente;
    }

    if (ultimoNodoBorr != NULL){

        if (prevUltimo != NULL) {
            prevUltimo->siguiente = ultimoNodoBorr->siguiente;
        }

        if (ultimoNodoBorr == head){
            head = head->siguiente;
        }


        free(ultimoNodoBorr);
    }
}

int borrarTodosElem(int key){
    int borradoTotal = 0;
    struct nodo *prev, *cur;

    while (head != NULL && head->dato == key){

        prev = head;
        head = head->siguiente;
        free(prev);
        borradoTotal++;
    }

    prev = NULL;
    cur  = head;

    while (cur != NULL){

        if (cur->dato == key){

            if (prev != NULL) {
                prev->siguiente= cur->siguiente;
            }

            free(cur);
            cur = prev->siguiente;
            borradoTotal++;
        }
        else{
            prev = cur;
            cur = cur->siguiente;
        }

    }

    return borradoTotal;
}
