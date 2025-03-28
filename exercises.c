#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "arraylist.h"
#include "stack.h"

//#include "exercises.h"

//Funciones auxiliares que puedes utilizar para debuggear tus ejercicios
//NO MODIFICAR
void imprime_lista(List *L) {
   int *dato;
   dato = (int*)first(L);
   printf("[");
   while(dato != NULL) {
      printf("%d ", *dato);
      dato = (int*)next(L);
   }
   printf("]\n");

}

//Ojo que la pila se vacía al imprimir y se imprime en orden inverso
//NO MODIFICAR
void imprime_y_vacia_pila(Stack *P) {
   void *dato;
   printf("[");
   while((dato = pop(P)) != NULL) {
      printf("%d ", *(int*)dato);
   }
   printf("]\n");
}

/* 
Ejercicio 1.
Crea una Lista y agrega punteros a elementos del 1 al 10.
Recuerda que la lista almacena punteros, por lo que
debes reservar memoria para cada elemento que agregues.
Al finalizar retorna la lista creada.
*/

List* crea_lista() {
   List* L = create_list();

   for(size_t k = 1; k <= 10; k++)
   {
      int *numero = (int *) malloc(sizeof(int));
      if (numero == NULL) exit(1);
      (*numero) = k;
      pushBack(L,&(*numero));
   }
   return L;
}

/*
Ejercicio 2.
Crea una función que reciba una lista de enteros (int*) y 
retorne la suma de sus elementos.
*/
int sumaLista(List *L) {
   int total = 0;
   int *num = first(L);
   while(num!= NULL)
   {
      total += *num;
      num = next(L);
   }
   return total;
}

/*
Ejercicio 3.
Crea una función que reciba una lista de punteros a int (int*) y
un entero elem. La función debe eliminar todos los elementos 
de la lista que sean iguales a elem.
Asume que popCurrent luego de eliminar un elemento se
posiciona en el elemento anterior.
*/

void eliminaElementos(List*L, int elem){
   int *numero = first(L);
   while(numero != NULL){
      if (*numero == elem) popCurrent(L);
      numero = next(L);
   }
}

/*
Ejercicio 4.
La función copia los punteros de la pila P1 en la pila P2.
El orden de ambas pilas se debe mantener.
Puedes usar una pila auxiliar.
*/

void copia_pila(Stack* P1, Stack* P2) {
   Stack *aux = create_stack();
   
   while (top(P1) != NULL) {
      void *elemento = top(P1);
      push(aux, elemento);
      pop(P1);
      
  }

  while (top(aux) != NULL) {
      void *elemento = top(aux);
      push(P1, elemento); 
      push(P2, elemento); 
      pop(aux);
  }

}

/*
Ejercicio 5.
La función verifica si la cadena de entrada tiene sus 
paraéntesis balanceados. Retorna 1 si están balanceados,
0 en caso contrario.
*/

int parentesisBalanceados(char *cadena) {
   
   Stack *pila = create_stack();   

   while (*cadena) {
      if (*cadena == '(' || *cadena == '[' || *cadena == '{') {
         char *nuevo = (char*) malloc(sizeof(char))
         if (nuevo == NULL) exit(1);
         *nuevo = *cadena;
         push(pila, nuevo);
      }

      else if (*cadena == ')' || *cadena == ']' || *cadena == '}') {
         if (top(pila) == NULL) {  
            return 0; 
         }
         char *ultimoPtr = (char*) pop(pila);
         char ultimo = *ultimoPtr;
         free(ultimoPtr); 

         if ((*cadena == ')' && ultimo != '(') || (*cadena == ']' && ultimo != '[') || (*cadena == '}' && ultimo != '{')) return 0;
      }
      cadena++;  
   }

   if (top(pila) == NULL) return 1;
   return 0;
}

