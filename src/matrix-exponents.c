//
//
//  This code generate an chained list of exponents rows
//  For more details you can download the repport at :
//  http://mounirnasrallah.com/quadratic-save
//
//  Created on August 13, 2014
//
//  Author :
//  NASR ALLAH Mounir - <nasrallah.mounir@gmail.com>
//  http://mounirnasrallah.com

/*
#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

void init(matrix_t m, mpz_t number_of_col){

  mpz_init(m->nb_col);
  mpz_init(m->nb_row);

  mpz_set_ui(m->nb_col, number_of_col);
  mpz_set_ui(m->nb_row, 0);

  m->rows = (row_t*) malloc(sizeof(row_t));

  mpz_init(m->rows->value);

  m->value->next_row = NULL;

}



void insert_row(matrix_t m, row_t *row){

  row_t tmp = m->rows;

  while(tmp->next_row != NULL){}

  tmp->next_row = row;

  mpz_add_ui(m->nb_row, m->nb_row, 1);

}


void gauss_jordan_elimination(){

}

*/
