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


prime_number_t* insert_list_prime_number(prime_number_t* p, unsigned long int number);
void printing_list_of_primes_numbers(prime_number_t* list, unsigned long int b);


void sieve_for_number(char* array, unsigned long int number, unsigned long int offset){

  unsigned long int i;

  for(i = number; i < offset; i+=number){
    set_bit(array, i);
  }

}


prime_number_t* eratosthene_sieve( mpz_t offset){

  unsigned long int i;
  unsigned long int ui_offset;
  ui_offset = mpz_get_ui(offset);


  // Creating list of prime numbers
  prime_number_t* list_of_primes = NULL;

  char* array = calloc(((ui_offset/8) + 1), sizeof(char));

  if(!array){
    fprintf(stderr,"Calloc Error at : File : %s Line : %d \n ",__FILE__,__LINE__);
  }


    /* Eratosthene sieving */
  for( i = 2; i < ui_offset; i++){
    if(! get_bit(array, i) ){  // If is prime we sieve
      sieve_for_number(array, i, ui_offset);
      list_of_primes = insert_list_prime_number(list_of_primes, i);
    }
  }


    return list_of_primes;
}

