//
//
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
#include "smooth.h"
#include "base.h"



/* Create an smooth number */
smooth_number_t* create_struct_smooth_number(uint64_t size_of_base){

  smooth_number_t* smooth = malloc(sizeof(smooth_number_t));
  if(!smooth){
    fprintf(stderr,"Malloc Error at : File : %s Line : %d \n ",__FILE__,__LINE__);
  }

  uint64_t* exp = calloc(size_of_base, sizeof(char));

  if(!exp){
    fprintf(stderr,"Malloc Error at : File : %s Line : %d \n ",__FILE__,__LINE__);
  }

  char* exp_mod2 = calloc(((size_of_base/8) + 1), sizeof(char));

  if(!exp_mod2){
    fprintf(stderr,"Malloc Error at : File : %s Line : %d \n ",__FILE__,__LINE__);
  }

  mpz_init(smooth->x);
  mpz_init(smooth->f_x);
  mpz_init(smooth->result);
//  mpz_init2(smooth->exponents_mod_2, size_of_base);
  smooth->exponents = exp;
  smooth->exponents_mod_2 = exp_mod2;

  return smooth;
}


/* Calculate the value */
void polynomial_f(smooth_number_t* smooth_number, mpz_t x, mpz_t n){

  mpz_t tmp;
  mpz_init(tmp);

  mpz_mul(tmp, x, x);
  mpz_sub(smooth_number->f_x, tmp, n);

}


/* Initialization of smooth bases */
void init_smooth_base(uint64_t size_base, smooth_number_t** array, mpz_t composite_number, mpz_t square_root_of_composite, uint64_t number){

  uint64_t i;

  for( i = 0; i < size_base; i++){
    smooth_number_t* smooth = create_struct_smooth_number(size_base);
    mpz_add_ui(smooth->x, square_root_of_composite, number+ i +1);
    polynomial_f(smooth, smooth->x, composite_number);
    mpz_set(smooth->result, smooth->x);
    array[i] = smooth;
  }

}




/* Search the index to start sieving for one number */
uint64_t search_index_to_start_sieving(smooth_number_t** smooth_array, uint64_t size_base, uint64_t prime_number, mpz_t root){

  uint64_t i;
  smooth_number_t* smooth;
  mpz_t remainder;
  mpz_init(remainder);

  for( i = 0; i < size_base; i++){
    smooth = smooth_array[i];
    mpz_mod_ui(remainder, smooth->x, prime_number);
    if(mpz_cmp(remainder, root) == 0){
      return i;
    }
  }

  return -1;
}


void sieving_for(uint64_t index, uint64_t prime_number, uint64_t prime_number_position, smooth_number_t** smooth_array, uint64_t size_base){

  uint64_t i, bit;
  smooth_number_t* smooth;

  for( i = index; i < size_base; i = i + prime_number ){
    smooth = smooth_array[i];
    mpz_cdiv_q_ui(smooth->result, smooth->result, prime_number);

    smooth->exponents[prime_number_position]++;

    if( mpz_tstbit(smooth->exponents_mod_2, prime_number_position) ){
      mpz_clrbit(smooth->exponents_mod_2, prime_number_position);
    }
    else{
      mpz_setbit(smooth->exponents_mod_2, prime_number_position);
    }

  }

}


uint64_t extract_smoot_numbers(uint64_t size_base, smooth_number_t** smooth_array, list_smooth_number_t list){

  uint64_t i;
  uint64_t result = 0;
  smooth_number_t* tmp;

  for(i = 0; i < size_base; i++){

    tmp = smooth_array[i];

    if(mpz_cmp_ui(tmp->result, 1)){
      insert_list_smooth_number(list, tmp);
      result++;
    }
    else{
      free_smooth_number(tmp);
    }

  }

  return result;
}



void sieving(base_t** base, uint64_t size_base, smooth_number_t* smooth_array){

  uint64_t i, index;
  base_t* tmp;

  for(i = 0; i < size_base; i++){

    tmp = base[i];

    index = search_index_to_start_sieving(smooth_array, size_base, tmp->value, tmp->first_root);
    sieving_for(index, tmp->value, i, smooth_array, size_base);

    if(tmp->first_root == tmp->second_root)
      continue;

    index = search_index_to_start_sieving(smooth_array, size_base, tmp->value, tmp->second_root);
    sieving_for(index, tmp->value, i, smooth_array, size_base);

  }

}

