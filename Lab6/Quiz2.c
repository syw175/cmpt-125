/*
 * 3
 * Filename: Quiz2.c
 *
 * Description: Simple operations on raster images
 *
 * Author: RV - 2014
 * Modified by: AL - 2022
 *
 * Completed by: Steven Wong
 * Completion Date: June 28
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
	// Validate the parameters
	assert( array != NULL );
    assert( x < cols );
    assert( y < rows ); 
    return array[ y*cols + x ];
}

/* Set the pixel at coordinate (x,y) to the specified colour. */
void set_pixel( uint8_t array[], 
                unsigned int cols, 
                unsigned int rows,
                unsigned int x,
                unsigned int y,
                uint8_t colour )
{
	// Validate the parameters
	assert( array != NULL ); 
	assert( x < cols );
    assert( y < rows );
    array[ y * cols + x ] = colour;
    return;
} 
						
/* ---------------------- Quiz 2 ---------------------- */
/* Print the colour of the pixel located at the coordinates 
   (x,y) in the raster image array[] on stdout.
*/
void print_pixel( const uint8_t array[],
                  unsigned int cols, 
                  unsigned int rows,
                  unsigned int x,
                  unsigned int y )
{
    // Put your code here
    uint8_t color = get_pixel(array, cols, rows, x, y);
    printf("The color located at (%d, %d) is %u\n", x, y, color);	
    return;
} 				 		

/*-------------------------------------------------
  OPERATIONS ON THE WHOLE IMAGE 
*/

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
 	// Validate the parameter
	assert( array != NULL );

	uint8_t* ret = malloc(cols*rows*sizeof(uint8_t));
    if (!ret) {
        perror("Call to malloc failed\n");
        exit(1);
    }
    memcpy(ret, array, cols*rows*sizeof(uint8_t));
	
    return ret;
}

/* ---------------------- Quiz 2 ---------------------- */
/* Multiply every pixel by "scale_factor", in order to brighten or
   darken the image. Resulting values are rounded to the nearest
   integer (0.5 rounded up) and any resulting value over 255 is
   thresholded (i.e., set) to 255.
*/
void scale_brightness( uint8_t array[],
                       unsigned int cols,
                       unsigned int rows,
                       double scale_factor )
{

    // Put your code here
    for (int y = 0; y < rows; y++) { 
      for (int x = 0; x < cols; x++) { 
        uint8_t currColor = get_pixel(array, cols, rows, x, y);
        uint8_t newColor;
        
        if (scale_factor*currColor > 255) { 
          newColor = 255;
        } else {  
          newColor = floor((100*(int)currColor) + 0.5);
        }
        
        set_pixel(array, cols, rows, x, y, newColor);
	printf("%d %d\n", currColor, newColor);


        //if (newColor > 255)
          //newColor = 255;

        //if (newColor < 0)
          //newColor = 0;
   
      }
    }

   return;

    
}
