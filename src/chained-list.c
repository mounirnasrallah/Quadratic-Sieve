
#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include "base.h"
#include "eratosthene-sieve.h"
#include "smooth.h"


prime_number_t* insert_list_prime_number(prime_number_t* p, unsigned long int number){

  prime_number_t* tmp = p;
  prime_number_t* new_element = (prime_number_t*)malloc(sizeof(prime_number_t));

  if(!new_element){
    fprintf(stderr,"Malloc Error at : File : %s Line : %d \n ",__FILE__,__LINE__);
  }

  new_element->value = number;
  new_element->next = NULL;

  if(p == NULL){
    return new_element;
  }
  else{

    while(tmp->next != NULL){
      tmp = tmp->next;
    }

    tmp->next = new_element;
    return p;

  }

}



base_t* insert_list_base(base_t* p, unsigned long int number){

  base_t* tmp = p;
  base_t* new_element = (base_t*)malloc(sizeof(base_t));

  if(!new_element){
    fprintf(stderr,"Malloc Error at : File : %s Line : %d \n ",__FILE__,__LINE__);
  }

  new_element->value = number;
  new_element->next = NULL;

  if(p == NULL){
    return new_element;
  }
  else{

    while(tmp->next != NULL){
      tmp = tmp->next;
    }

    tmp->next = new_element;
    return p;

  }

}




void insert_list_smooth_number(list_smooth_number_t* list, smooth_number_t* elem){

  list_smooth_number_t* tmp = list;
  list_smooth_number_t* new_element = (list_smooth_number_t*)malloc(sizeof(list_smooth_number_t));

  if(!new_element){
    fprintf(stderr,"Malloc Error at : File : %s Line : %d \n ",__FILE__,__LINE__);
  }

  new_element->value = elem;
  new_element->next = NULL;

  if(tmp->value == NULL){
    tmp->value = elem;
    tmp->next = NULL;
  }
  else{

    while(tmp->next != NULL){
      tmp = tmp->next;
    }

    tmp->next = new_element;
  }

}

