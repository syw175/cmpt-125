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
    for (int y = 0; y < rows; ++y) {  // Iterate through rows in img
        for (int x = 0; x < cols; ++x) {  // Iterate through cols in img
            set_pixel(array, cols, rows, x, y, 0);  // Set each pixel to black (0)
        }
    }
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
    // Create a new array on heap of the same size as array
    uint8_t* imgCopy = malloc(cols * rows * sizeof(uint8_t));

    // Check if malloc correctly allocated mem to heap 
    if (imgCopy == NULL) {
        return NULL;
    }

    // Set each color value in newCopy img to the color value of original
    for (int y = 0; y < rows; ++y) { 
        for (int x = 0; x < cols; ++x) { 
            uint8_t color = get_pixel(array, cols, rows, x, y);
            set_pixel(imgCopy, cols, rows, x, y, color);
        }
    }
    return imgCopy;
}

/* Return the darkest color that appears in the image. */
uint8_t darkest( const uint8_t array[], 
                 unsigned int cols, 
                 unsigned int rows )
{   
    // Set darkest color to maximum color value
    uint8_t darkestColor = 255;

    // Check colors in img to see if there is a darker color than darkestCol
    for (int y = 0; y < rows; ++y) { 
        for (int x = 0; x < cols; ++x) { 
            uint8_t currentColor = get_pixel(array, cols, rows, x, y);
            if (currentColor < darkestColor) { 
                darkestColor = currentColor;
            }
        }
    }
    return darkestColor;
}

/* Return the lightest color that appears in the image. */
uint8_t lightest( const uint8_t array[], 
	              unsigned int cols, 
	              unsigned int rows )
{
    uint8_t lightestColor = 0; 
    for (int y = 0; y < rows; ++y) { 
        for (int x = 0; x < cols; ++ x) { 
            uint8_t currentColor = get_pixel(array, cols, rows, x, y); 
            if (lightestColor < currentColor) {
                lightestColor = currentColor;
            } 
        }
    }
    return lightestColor;
}

/* Replace every instance of pre_color with post_color. */
void replace_color( uint8_t array[], 
                    unsigned int cols, 
                    unsigned int rows,
                    uint8_t pre_color,
                    uint8_t post_color )
{
    for (int y = 0; y < rows; ++y) { 
        for (int x = 0; x < cols; ++x) { 
            if (get_pixel(array, cols, rows, x, y) == pre_color) { 
                set_pixel(array, cols, rows, x, y, post_color);
            }
        }
    }
	return;
}

/* Flip the image horizontally, left-to-right, like in a mirror. */
void flip_horizontal( uint8_t array[], 
                      unsigned int cols, 
                      unsigned int rows )
{
    // Copy the image to be mirrored 
    const uint8_t imgCopy[] = copy(array, cols, rows);

    for (int y = 0; y < rows; ++y) { 
        for (int x = 0; x < cols; ++x) { 
            uint8_t color = get_pixel(imgCopy, cols, rows, (cols-1-x), y);
            set_pixel(array, cols, rows, x, y, color);
        }
    }
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
    for (int yValue = 0; yValue < rows; ++yValue) { 
        for (int xValue = 0; xValue < cols; ++xValue) { 
            if (get_pixel(array, cols, rows, xValue, yValue) == color) { 
                // Is this how you set a pointer value? 
                *x = xValue;
                *y = yValue;
                return 1;             
            }
        }
    }
    return 0;
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
