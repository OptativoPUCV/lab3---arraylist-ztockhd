#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "arraylist.h"

//normal array
typedef struct ArrayList {
    void **data;
    int capacity;
    int size;
} ArrayList;

ArrayList *createList(void) {
  ArrayList * list = (ArrayList *)malloc(sizeof(ArrayList));
  if(list == NULL) exit(EXIT_FAILURE);
  list->data = (void **)malloc(2*sizeof(void**));
  list->capacity = 2;
  list->size = 0;
  return list;  
  
}

void append(ArrayList * l, void * data){
  if(l->size == l->capacity){
    l->capacity *= 2;
    l->data = realloc(l->data,l->capacity*sizeof(void**));
  }
  l->data[l->size] = data;
  l->size++;

}

void push(ArrayList * l, void * data, int i){
  if(i > l->size) return;
  
  if(l->size == l->capacity){
    l->capacity *= 2;
    l->data = realloc(l->data,l->capacity*sizeof(void**));
  }

  for(int j = l->size ; j > i ; j--)
    {
      l->data[j] = l->data[j-1];
    }

  l->data[i] = data;
  l->size++;
}

void* get(ArrayList * l, int i){
  if(i >= l->size) return NULL;
  if(i < 0)
  {
    return l->data[i+l->size]; 
  }
  return l->data[i];
}


void* pop(ArrayList * l, int i){
  
  if(l->size == 0) return NULL;
  
  if(i < 0){
    i = i+l->size;
  }

  void* aux = l->data[i];

  for(int j = i ; j < l->size ; j++)
    {
      l->data[j] = l->data[j+1];
    }

  l->size--;
  
  return aux;
}

int get_size(ArrayList * l){
    return l->size;
}

//remove elements
void clean(ArrayList * l){
    free(l);
    l = createList();
}
