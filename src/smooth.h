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



//  Define smooth number like his value, his square, and an array of exponents
//  This is a representation of a row in Figure XX at the specified report in
//  the header.
typedef struct{
  mpz_t x;
  mpz_t f_x;
  mpz_t result;
  char* exponents;
  char* exponents_mod_2;
} smooth_number_t;

typedef struct{
  smooth_number_t* value;
  smooth_number_t* next;
}list_smooth_number_t;

