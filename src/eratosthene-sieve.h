//
//
//  This code generate an chained list of primary numbers with the Eratosthene
//  Sieve For more details you can download the repport at :
//  http://mounirnasrallah.com/quadratic-save
//
//  Created on August 13, 2014
//
//  Author :
//  NASR ALLAH Mounir - <nasrallah.mounir@gmail.com>
//  http://mounirnasrallah.com


typedef struct _prime_number_t{
  unsigned long int value;
  struct _prime_number_t* next;
} prime_number_t;

