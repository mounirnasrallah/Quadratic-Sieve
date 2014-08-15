//
//
//  This code permit to show some informations about ressources
//  usage.
//  We use those statistics for helping to optimize code and
//  operating system configuration.
//
//  For more details you can download the repport at :
//  http://mounirnasrallah.com/quadratic-save
//
//  Created on August 13, 2014
//
//  Author :
//  NASR ALLAH Mounir - <nasrallah.mounir@gmail.com>
//  http://mounirnasrallah.com


#include <sys/ressources.h>


struct rusage statistics;   // Statistics about ressource usage




//  Printing functions
// ----------------------------------------

void print_time_user_mode(struct rusage *statistics){
    fprintf(stdout,
            "User mode time = \t %ld s %ld ms \n",
            statistics.ru_utime.tv_sec,
            statistics.ru_utime.tv_usec/1000,
            );
}


void print_time_kernel_mode(struct rusage *statistics){
    fprintf(stdout,
            "Kernel mode time : \t %ld s %ld ms \n",
            statistics.ru_stime.tv_sec,
            statistics.ru_stime.tv_usec/1000,
            );
}


void print_page_fault_minor(struct rusage *statistics){
    fprintf(stdout,
            "Minor page fault : \t %ld \n",
            statistics.ru_minflt
            );
}


void print_page_fault_major(struct rusage *statistics){
    fprintf(stdout,
            "Major page fault : \t %ld \n",
            statistics.ru_majflt
            );
}


void print_number_swaps_processus(struct rusage *statistics){
    fprintf(stdout,
            "Number of processus swaps : \t %ld \n",
            statistics.ru_nswap
            );
}


void print_statistics(struct rusage *statistics){
    print_time_user_mode(statistics);
    print_time_kernel_mode(statistics);
    print_page_fault_minor(statistics);
    print_page_fault_major(statistics);
    print_number_swaps_processus(statistics);
}



//  Usage functions
// ----------------------------------------

void get_statistics(struct rusage *statistics){
    if(getrusage(RUSAGE_BOTH,statistics) != 0){
        fprintf(stderr, "Impossible to get statistics");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

