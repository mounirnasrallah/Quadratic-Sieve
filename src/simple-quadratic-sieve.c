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
#include <gmp.h>
#include "base.h"
#include "smooth.h"
#include "eratosthene-sieve.h"

//////
prime_number_t* eratosthene_sieve( mpz_t offset );
base_t* init_base(prime_number_t* list, mpz_t n);
/////


struct rusage statistics;   // Statistics about ressource usage



int main(int argc, char **argv) {

  char info[] = "\
Developped by Mounir Nasr Allah <http://mounirnasrallah.com>,\n         \
This program it's an implementation of Carl Pommerance's algorithm : Quadratic Sieve \n \
Usage:\n                                                                \
\tqs <number>\n                                                         \
\t\tnumber : composite number\n                                         \
\tSome example :\n                                                      \
\t\tsimple-quadratic-sieve 87463 \n";

  mpz_t composite_number;
  mpz_init(composite_number);

  mpz_t square_root_of_composite_number;
  mpz_init(square_root_of_composite_number);

  mpz_t B;
  mpz_init(B);

  prime_number_t* list_of_primes_numbers;

  base_t* base;

  uint64_t number_relation;

  uint64_t size_base;
  uint64_t i;

  if(argc != 2){
    fprintf(stderr, info);
    exit(EXIT_FAILURE);
  }

  if(mpz_init_set_str(composite_number, argv[1], 10) == -1) {
    printf("Cannot load the composite number %s\n", argv[1]);
    exit(2);
  }

  mpz_sqrt(square_root_of_composite_number, composite_number);

  printing_square_root_of_composite_number(square_root_of_composite_number, composite_number);

  base_max_prime(B, composite_number);

  printing_B_value(B);

  list_of_primes_numbers = eratosthene_sieve(B);

  printing_list_of_primes_numbers(list_of_primes_numbers, B);

  base = init_base(list_of_primes_numbers, composite_number);

  printing_base(base);

  find_modular_roots(base, composite_number);

  printing_roots_base(base);

  size_base = size_of_base(base);

  base_t* base_array[size_base];
  init_base_to_array(base, base_array);

  smooth_number_t* b_smooth_array[size_base];
  list_smooth_number_t* smooth_number_list = NULL;

  for( i = 0; number_relation <= size_base; i++){

    init_smooth_base(size_base, b_smooth_array, composite_number, square_root_of_composite_number, i);

    printing_smooth_array(b_smooth_array, size_base);

    sieving(base_array, size_base, b_smooth_array);

    number_relation += extract_smoot_numbers(size_base,b_smooth_array, smooth_number_list);

  }


  return EXIT_SUCCESS;
}
