//
//
//  This code printing informations
//  GNU Multiple Precision Arithmetic Library.
//  For more details you can download the repport at :
//  http://mounirnasrallah.com/quadratic-save
//
//  Created on August 13, 2014
//
//  Author :
//  NASR ALLAH Mounir - <nasrallah.mounir@gmail.com>
//  http://mounirnasrallah.com


#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include "base.h"
#include "smooth.h"
#include "eratosthene-sieve.h"



void printing_square_root_of_composite_number(mpz_t square_root_of_composite_number, mpz_t composite_number){

  gmp_printf("\nThe composite number %Zd have %Zd for square root \n",composite_number, square_root_of_composite_number);

}

void printing_B_value(mpz_t b){

  gmp_printf("\nB-value : %Zd\n", b);

}


void printing_list_of_primes_numbers(prime_number_t* list, mpz_t b){

  prime_number_t* tmp = list;

  gmp_printf("\nPrimes numbers less than %Zd are :\n\t", b);

  while(tmp->next != NULL){
    printf("%lu, ",tmp->value);
    tmp = tmp->next;
  }

  printf("%lu\n",tmp->value);

}


void printing_base(base_t* list){

  base_t* tmp = list;

  printf("\nBase is = { ");

  while(tmp->next != NULL){
    printf("%lu; ",tmp->value);
    tmp = tmp->next;
  }

  printf("%lu }\n",tmp->value);

}



void printing_roots_base(base_t* list ){

  base_t* tmp = list;

  printf("\nSolving roots :\n");

  while(tmp != NULL){
    printf("\tThe roots of %lu = { ", tmp->value);

    if(tmp->first_root)
      gmp_printf("%Zd ; ", tmp->first_root);

    if(tmp->second_root)
      gmp_printf("%Zd ", tmp->second_root);

    printf("}\n");

    // if(tmp->next != NULL){
      tmp = tmp->next;
      // }

  }

}




void first_printing_smooth_array(){

  printf("Smooth numbers :\n");

}


void printing_smooth_array(smooth_number_t** array, uint64_t size_base){

  smooth_number_t* tmp;
  uint64_t i, j;

  for( i = 0; i < size_base; i++){
    tmp = array[i];
    printf("\n----------------------------\n");
    gmp_printf("x | %Zd\n", tmp->x);
    gmp_printf("f(x) | %Zd\n", tmp->f_x);
    gmp_printf("result | %Zd\n", tmp->result);
    printf("----------------------------\n");

  }

}



void printing_final_smooth_number(list_smooth_number_t* smooth_number_list){

  list_smooth_number_t* tmp = smooth_number_list;
  smooth_number_t* value;

  printf("\nFinal B-Smooth numbers are :\n");

  while(tmp != NULL){
    value = tmp->value;
    gmp_printf("\t x = %Zd , f(x) = %Zd , result = %Zd , exponents = (%c) , exponents mod 2 = (%c) \n", value->x, value->f_x, value->result, value->exponents, value->exponents_mod_2);
    tmp = tmp->next;
  }

}
