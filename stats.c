/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file <stats.c> 
 * @brief <File consist functions for statistics
   and get you minimal, maximum, median and mean values >
 *
 * <Add Extended Description Here>
 *
 * @author <Andrii Puzyrnyi>
 * @date <28.01.2024>
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void print_array(unsigned char* data, unsigned int length);
void print_statistics(unsigned char* data, unsigned int length);
unsigned char find_median(unsigned char*data, unsigned int length);
double find_mean(unsigned char*data, unsigned int length);
unsigned char find_max(unsigned char* data, unsigned int length);
unsigned char find_min(unsigned char* data, unsigned int length);
void sort_array(unsigned char* data, unsigned int length);
 

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  print_array(test,SIZE);
  print_statistics(test,SIZE);
  sort_array(test,SIZE);
  printf("\nArray after sort:");
  print_array(test,SIZE);

  
  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */

}

/* Add other Implementation File Code Here */
void print_array(unsigned char* data, unsigned int length)
{
  printf("Array: ");
  for(unsigned int i = 0;i < length; ++i)
  {
    printf("%u ",data[i]);
  }
  printf("\n");
}

void print_statistics(unsigned char* data, unsigned int length)
{
  printf("\nStatistics: \n");
  printf("Min: %u\n", find_min(data, length));
  printf("Max: %u\n", find_max(data, length));
  printf("Mean: %.2f\n", find_mean(data, length));
  printf("Median: %u\n", find_median(data, length));
}

unsigned char find_median(unsigned char* data, unsigned int length)
{
  sort_array(data, length);
  
  if(length %2 == 0)
  {
    return (data[length /2 - 1] + data[length /2])/2; //if the lengthis even, average the middle two elements
  }
  else
  {
    return data[length/2];
  }

}

double find_mean(unsigned char* data, unsigned int length)
{
  double sum = 0;
 
  for(unsigned int i = 0; i < length; ++i)
  {
    sum += data[i];
  }
  
  return sum/length;

}


unsigned char find_max(unsigned char* data, unsigned int length)
{
  unsigned char max = data[0];

  for(unsigned int i = 1; i < length; ++i)
  {
    if(data[i]>max)
    {
      max = data[i];
    }
  }

  return max;
}

unsigned char find_min(unsigned char* data, unsigned int length)
{
  unsigned char min = data[0];
  for(unsigned int i = 1; i < length; ++i)
  {
    if(data[i] < min)
    {
      min = data[i];
    }
  }
  return min;
}


void sort_array(unsigned char* data, unsigned int length)
{
  for(unsigned int i = 0;i < length - 1; ++i)
  {
    for(unsigned j = 0; j < length - i - 1; ++j)
    {
      if(data[j]<data[j+1])
      {
        unsigned char temp = data[j];
        data[j] = data[j+1];
        data[j+1] = temp;
      }
    }
  }
}
