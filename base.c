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
typedef struct{
    mpz_t value;
    mpz_t * next;
} base_t;


//  Define smooth number like his value, his square, and an array of exponents
//  This is a representation of a row in Figure XX at the specified report in
//  the header.
typedef struct{
    mpz_t value;
    mpz_t square;
    mpz_t* exponents;
} smooth_number_t;


//  Define the matrix row
typedef struct{
    mpz_t *value;
} matrix_row_t;


// Define base
base_t base;

// Define the matrix of even exponents ( mod 2 )
matrix_row_t *matrix;


// mpz_t *base;        // Base
// mpz_t base_size;    // Number of



//  Calculate the value of B.
//  B represent the maximum value of prime number in the base.
//  B = exp( (1/2) * sqrt( ln(n) * ln(ln(n)) ) )

void base_max_prime(mpz_t result, mpz_t n){

    mpz_t base_max, ln_N, ln_ln_N;
   
    mpz_init(base_max);
    mpz_init(ln_N);
    mpz_init(ln_ln_N);
    
	mpz_log(ln_N, n);
	mpz_log(ln_ln_N, ln_N);
    
	mpz_mul(base_max, ln_N, ln_ln_N);
	mpz_sqrt(base_max, base_max);
	mpz_div_ui(base_max, base_max, 2);
	mpz_exp(base_max, base_max);
    
    mpz_set(result, base_max);
    
    mpz_clear(ln_ln_N);
    mpz_clear(ln_N);
    mpz_clear(base_max);
    
}



//  Initialization of the base with primes numbers

void init_base(mpz_t base, mpz_t n){

    mpz_t base_max;
    mpz_init(base_max);
    base_max_prime(base_max, n);

    mpz_t i;
    mpz_init(i);
    
    base.value = -1;
    base.next = NULL;
    
    for(mpz_set(i, 2); mpz_cmp(i, base_max) < 0; mpz_nextprime( i, i) ){
    
        mpz_legendre (const mpz t a, const mpz t p)
    }
    
    
    base_max_prime();
}














