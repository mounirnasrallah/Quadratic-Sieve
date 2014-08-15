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



typedef struct {
    mpz_z value;
    prime_number_t* next;
} prime_number_t;



mpz_t create_init_table(mpz_t size_of_bit){
    
    mpz_t array;
    mpz_init2(array, size_of_bit);
    return array;
}




void sieve_table_of_numbers(mpz_t array_of_numbers, mpz_t p){
    
    mpz_t i;
    mpz_init(i);
    
    for(mpz_mul(i,p,2); (mpz_cmp(i, p) < 0); mpz_add(i,i,p)){
        mpz_setbit(array_of_numbers, i);
    }
    
}


void number_of_primes(mpz_t array_of_numbers, mpz_t p, mpz_result){

    mpz_t i;
    mpz_init(i);
    mpz_init(mpz_result);
    
    for(mpz_set_ui(i,0); (mpz_cmp(i, p) < 0); mpz_add_ui(i,i,1)){
        if(! mpz_tstbit (array_of_numbers, i) ){
            mpz_add_ui(result,result,1);
        }
    }
    
}



prime_number_t* eratosthene_sieve( mpz_t offset){
    
    mpz_t array_of_numbers =  create_init_table(offset);
 
    mpz_t i;
    
    mpz_init(i);
    
    for(mpz_set_ui(i,2); (mpz_cmp(i, offset) < 0); mpz_add_ui(i,i,1)){
        if(! mpz_tstbit (array_of_numbers, i) ){
            sieve_table_of_numbers(array_of_numbers, i);
        }
    }
    
    number_of_primes(array_of_numbers, p, number_of_primes);
    
    prime_number_t* list_of_primes = malloc(size_of(prime_number_t));
    
    //  First element of prime list it's -1
    mpz_set_ui(list_of_primes->value, -1);
    list_of_primes->next = NULL;
    
    prime_number_t* last;
    last = &list_of_primes;
    
    for(mpz_set_ui(i,0); (mpz_cmp(i, offset) < 0); mpz_add_ui(i,i,1)){
        if(! mpz_tstbit (array_of_numbers, i) ){
            
            prime_number_t* p = malloc(size_of(prime_number_t));
            
            mpz_set(p->value, i);
            last.next = p;
            
            last = p;
        }
    }
    
    return list_of_primes;
}

