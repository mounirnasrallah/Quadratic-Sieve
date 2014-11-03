//
//
//  This code generate an chained list of primary numbers with the Eratosthene
//  Sieve.
//  For sieving I used an array with base_max length, who index it's number and
//  the value of index's bit it's 0 (prime) or 1(not prime).
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
#include "eratosthene-sieve.h"
//#include "chained-list.h"

prime_number_t* insert_list_prime_number(prime_number_t* p, unsigned long int number);
void printing_list_of_primes_numbers(prime_number_t* list, unsigned long int b);

/*
mpz_t* create_init_table(mpz_t size_of_bit){

    mpz_t array;
    mpz_init2(array, 5600);

    return array;
}
*/


void sieve_for_number(char* array, unsigned long int number, unsigned long int offset){

  unsigned long int i;

  for(i = number; i < offset; i+=number){
    set_bit(array, i);
  }

}

/*
mpz_t* number_of_primes(mpz_t array, mpz_t offset){

  mpz_t i, result;
  mpz_init(i);
  mpz_init(mpz_result);

  for(mpz_set_ui(i,0); (mpz_cmp(i, offset) < 0); mpz_add_ui(i,i,1)){
    if(! mpz_tstbit (array_of_numbers, i) ){
      mpz_add_ui(result,result,1);
    }
  }

  return result;

  }
*/



prime_number_t* eratosthene_sieve( mpz_t offset){

//  mpz_t* array =  create_init_table(offset);

//  mpz_t array;
  unsigned long int i;
  unsigned long int ui_offset;
  ui_offset = mpz_get_ui(offset);


  // Creating list of prime numbers
  prime_number_t* list_of_primes = NULL;

  char* array = calloc(((ui_offset/8) + 1), sizeof(char));

  if(!array){
    fprintf(stderr,"Calloc Error at : File : %s Line : %d \n ",__FILE__,__LINE__);
  }

//  mpz_init2(array, ui_offset);

//    mpz_t i, number_of_primes;
  // mpz_init(i);
    //  mpz_init(number_of_primes);

    /* Eratosthene sieving */
  for( i = 2; i < ui_offset; i++){
    if(! get_bit(array, i) ){  // If is prime we sieve
      sieve_for_number(array, i, ui_offset);
      list_of_primes = insert_list_prime_number(list_of_primes, i);
    }
  }

  /* We calculate the number of prime afer sieving */
  // number_of_primes = number_of_primes(array, offset);

  // Creating list of prime numbers
  //prime_number_t* list_of_primes = NULL;

  /* Creating chained list of prime numbers */
  // for(i = 0; i < ui_offset; i++){
  // if(! get_bit(array, i) ){
      //    list_of_primes = insert_head_prime_number(list_of_primes, i);
  //    printf("%d\n", i);
  //  }
  // }


    return list_of_primes;
}

