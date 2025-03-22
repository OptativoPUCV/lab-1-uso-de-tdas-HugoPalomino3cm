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
   Stack stack = create_stack();  
   
   int largo = 0;

   for(size_t k = 0; cadena[k] != '\0'; k++){
      largo++;
   }

   
   if (largo % 2 != 0) return 0;

   // Recorre la cadena
   for (size_t i = 0; cadena[i] != '\0'; i++) {
       
       if (cadena[i] == '(' || cadena[i] == '{' || cadena[i] == '[') {
           char *data = malloc(sizeof(char)); 
           *data = cadena[i];
           push(&stack, data); 
       }
       
       else if (cadena[i] == ')' || cadena[i] == '}' || cadena[i] == ']') {
           void *top_data = top(&stack); 
           if (top_data == NULL) return 0; 

           char ultimo = *(char *)top_data;  
           pop(&stack);  

           // Verifica si coincide el par
           if (cadena[i] == ')' && ultimo != '(') return 0;
           if (cadena[i] == '}' && ultimo != '{') return 0;
           if (cadena[i] == ']' && ultimo != '[') return 0;

           free(top_data); 
       }
   }

   
   void *top_data = top(&stack);
   return (top_data == NULL) ? 1 : 0;  
}

