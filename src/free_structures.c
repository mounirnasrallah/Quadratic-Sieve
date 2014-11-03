


#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include "smooth.h"



void free_smooth_number(smooth_number_t* elem){

  mpz_clears(elem->x, elem->f_x, elem->result, NULL);
  free(elem->exponents);
  free(elem->exponents_mod_2);
  free(elem);

}
