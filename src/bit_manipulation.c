
//
//
//  This code it's for bit manipulation
//  For more details you can download the repport at :
//  http://mounirnasrallah.com/quadratic-save
//
//  Created on August 13, 2014
//
//  Author :
//  NASR ALLAH Mounir - <nasrallah.mounir@gmail.com>
//  http://mounirnasrallah.com


int get_bit(char* array, unsigned long int x)
{
  unsigned long int byte_index = x / 8;
  unsigned long int bit_index = x % 8;
  unsigned long int bit_mask = ( 1 << bit_index);
  return ((array[byte_index] & bit_mask) != 0);
}

void set_bit(char* array, unsigned long int x)
{
  unsigned long int byte_index = x/8;
  unsigned long int bit_index = x % 8;
  unsigned long int bit_mask = ( 1 << bit_index);
  array[byte_index] |= bit_mask;
}

void clear_bit(char* array, unsigned long int x)
{
  unsigned long int byte_index = x/8;
  unsigned long int bit_index = x % 8;
  unsigned long int bit_mask = ( 1 << bit_index);
  array[byte_index] &= ~bit_mask;
}
