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




//  Define base like a chained list of mpz_t
typedef struct _base_t{
  uint64_t value;
  mpz_t first_root;
  mpz_t second_root;
  struct _base_t * next;
} base_t;












