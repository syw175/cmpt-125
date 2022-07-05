/*
 * 3
 * Filename: Quiz2.h
 *
 * Description: Simple operations on raster images
 *
 * Author: RV - 2014
 * Modified by: AL - 2022
 */

/*-------------------------------------------------
  OPERATIONS ON A PIXEL 
*/
           
/* Get the pixel in the array at coordinate (x,y). */
uint8_t get_pixel( const uint8_t array[], 
                   unsigned int cols, 
                   unsigned int rows,
                   unsigned int x,
                   unsigned int y );

/* Set the pixel at coordinate (x,y) to the specified colour. */
void set_pixel( uint8_t array[], 
                unsigned int cols, 
                unsigned int rows,
                unsigned int x,
                unsigned int y,
                uint8_t colour );
				
/* ---------------------- Quiz 2 ---------------------- */
/* Print the colour of the pixel located at the coordinates 
   (x,y) in the raster image array[] on stdout.
*/
void print_pixel( const uint8_t array[],
                  unsigned int cols, 
                  unsigned int rows,
                  unsigned int x,
                  unsigned int y );	
				  
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
               unsigned int rows );

/* ---------------------- Quiz 2 ---------------------- */
/* Multiply every pixel by "scale_factor", in order to brighten or
   darken the image. Resulting values are rounded to the nearest
   integer (0.5 rounded up) and any resulting value over 255 is
   thresholded (i.e., set) to 255.
*/
void scale_brightness( uint8_t array[],
                       unsigned int cols,
                       unsigned int rows,
                       double scale_factor );
