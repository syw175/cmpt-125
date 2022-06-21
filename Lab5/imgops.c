/*
 * Filename: imgops.c
 *
 * Description: Simple operations on raster images
 *
 * Author: RV - 2014
 * Modified by: AL - 2022
 *
 * Completed by: <Put your name here>
 * Completion Date: 
 */

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*-------------------------------------------------
  OPERATIONS ON A PIXEL 
*/

/* Get the pixel in the array at coordinate (x,y). */
uint8_t get_pixel( const uint8_t array[], 
                   unsigned int cols, 
                   unsigned int rows,
                   unsigned int x,
                   unsigned int y ) 
{	   
    assert( x < cols );
    assert( y < rows );
    return array[ y * cols + x ];
}

/* Set the pixel at coordinate (x,y) to the specified color. */
void set_pixel( uint8_t array[], 
                unsigned int cols, 
                unsigned int rows,
                unsigned int x,
                unsigned int y,
                uint8_t color ) 
{
    assert( x < cols );
    assert( y < rows );
    array[ y * cols + x ] = color;
    return;
} 

/*-------------------------------------------------
  OPERATIONS ON THE WHOLE IMAGE 
*/

/* Set every pixel to zero 0 (black). */
void zero( uint8_t array[],
	   unsigned int cols,
	   unsigned int rows )
{
    // Put your code here
    return;
}

/*
  Returns a pointer to a freshly allocated array that contains the
  same values as the original array, or a null pointer if the
  allocation fails. The caller is responsible for freeing the array
  later.
*/
uint8_t* copy( const uint8_t array[], 
               unsigned int cols, 
               unsigned int rows )
{
    // Put your code here
    return NULL; // You will need to change NULL to something more appropriate.
}

/* Return the darkest color that appears in the image. */
uint8_t darkest( const uint8_t array[], 
                 unsigned int cols, 
                 unsigned int rows )
{
    // Put your code here
    return 0; // You will need to change 0 to something more appropriate.
}

/* Return the lightest color that appears in the image. */
uint8_t lightest( const uint8_t array[], 
	              unsigned int cols, 
	              unsigned int rows )
{
	// Put your code here
	return 0; // You will need to change 0 to something more appropriate.
}

/* Replace every instance of pre_color with post_color. */
void replace_color( uint8_t array[], 
                    unsigned int cols, 
                    unsigned int rows,
                    uint8_t pre_color,
                    uint8_t post_color )
{
	// Put your code here
	return;
}

/* Flip the image horizontally, left-to-right, like in a mirror. */
void flip_horizontal( uint8_t array[], 
                      unsigned int cols, 
                      unsigned int rows )
{
    // Put your code here
    return;
}


/* Find the coordinates (x,y) of the first pixel with a value that
   equals color. Search from left-to-right, top-to-bottom. If it is
   found, store the coordinates in *x and *y and return 1. If it is
   not found, return 0.
*/
int locate_color( const uint8_t array[],              
                  unsigned int cols, 
                  unsigned int rows,
                  uint8_t color,
                  unsigned int *x,
                  unsigned int *y )
{
    // Put your code here
    return 0;  // You will need to change 0 to something more appropriate.
}

/* Invert the image such that black becomes white and vice
   versa and light shades of grey become the corresponding dark
   shade.
*/
void invert( uint8_t array[], 
             unsigned int cols, 
             unsigned int rows )
{
    // Put your code here
	return;
}
