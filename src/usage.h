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


void print_time_user_mode(struct rusage *statistics);


void print_time_kernel_mode(struct rusage *statistics);


void print_page_fault_minor(struct rusage *statistics);


void print_page_fault_major(struct rusage *statistics);


void print_number_swaps_processus(struct rusage *statistics);


void print_statistics(struct rusage *statistics);



//  Usage functions
// ----------------------------------------

void get_statistics(struct rusage *statistics);


