//
//
//  This code factorize numbers with the Quadratic Sieve method, using
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
#include <assert.h>
#include <gmp.h>
#include <mpfr.h>
#include "base.h"
#include "eratosthene-sieve.h"



base_t* insert_list_base(base_t* p, unsigned long int number);



void find_modular_roots(base_t* base, mpz_t n){

  base_t* tmp = base;

  mpz_t value;
  mpz_init(value);

  while(tmp != NULL){
    mpz_init(tmp->first_root);
    mpz_init(tmp->second_root);

    mpz_set_ui(value, tmp->value);

    gmp_printf("%Zd  -  %Zd\n", n, value);
    mpz_sqrtm(tmp->first_root, n, value);

    mpz_neg(tmp->second_root, tmp->first_root);
    mpz_mod(tmp->second_root, tmp->second_root, value);

    tmp = tmp->next;
  }

}


//  Calculate the value of B.
//  B represent the maximum value of prime number in the base.
//  B = sqrt( exp( sqrt( ln(n) * ln(ln(n)))))
//  MPFR_RNDU: 'ROUND_TOWARD_POSITIVE'
void base_max_prime(mpz_t result, mpz_t n){

  mpfr_t tmp_result, tmp_exp, tmp_n, tmp_ln, tmp_ln_ln;
  mpfr_init(tmp_result);
  mpfr_init(tmp_exp);
  mpfr_init(tmp_n);
  mpfr_init(tmp_ln);
  mpfr_init(tmp_ln_ln);

  mpfr_set_z(tmp_n, n, MPFR_RNDU);

  mpfr_log(tmp_ln_ln, tmp_n, MPFR_RNDU);
  mpfr_log(tmp_ln_ln, tmp_ln_ln, MPFR_RNDU);

  mpfr_log(tmp_ln, tmp_n, MPFR_RNDU);

  mpfr_mul(tmp_exp, tmp_ln, tmp_ln_ln, MPFR_RNDU);

  mpfr_sqrt(tmp_exp, tmp_exp, MPFR_RNDU);
  mpfr_div_ui(tmp_exp, tmp_exp, 2, MPFR_RNDU);

  mpfr_exp(tmp_result, tmp_exp, MPFR_RNDU);

  //mpfr_sqrt_ui(tmp_result, 2, MPFR_RNDU);

  mpfr_get_z(result, tmp_result, MPFR_RNDU);

  mpfr_clear(tmp_result);
  mpfr_clear(tmp_exp);
  mpfr_clear(tmp_ln);
  mpfr_clear(tmp_ln_ln);

}


uint64_t size_of_base(base_t* base){

  uint64_t result = 0;

  base_t* l = base;

  while(l != NULL){
    result++;
    l = l->next;
  }

  return result;
}


//  Initialization of the base with primes numbers
base_t* init_base(prime_number_t* list, mpz_t n){

  prime_number_t* l = list;

  mpz_t value;
  mpz_init(value);

  base_t* base = NULL;

  while(l != NULL){
    mpz_set_ui(value, l->value);
    if( mpz_legendre(n, value) == 1 ){
      base = insert_list_base(base, l->value);
    }
    l = l-> next;
  }

  return base;
}



void init_base_to_array(base_t* base, base_t** base_array){

  base_t* l = base;
  uint64_t i = 0;

  while(l != NULL){
    base_array[i] = l;
    l = l->next;
  }

}













