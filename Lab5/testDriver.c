/*
 * Filename: testDriver.c
 *
 * Description: Test functions from imgops.c
 * 
 * Author: RV - 2014
 * Modified by: AL - 2022
 */

#include <stdlib.h> // for random()
#include <stdint.h> // for explicit integer types, eg. uint8_t
#include <string.h> // for memset()
#include <assert.h>
#include <stdio.h>

// image drawing functions
#include "draw.h"

// load PNG image function
#include "png.h"

// image manipulation functions
#include "imgops.h"


int main( int argc, char* argv[] ) {

  // Windowing system setup
  const unsigned int winwidth  = 500;
  const unsigned int winheight = 500;

  // Declaring variables modelling a raster image:
  unsigned int imgwidth  = winwidth / 4;
  unsigned int imgheight = winheight / 4 ;
  uint8_t* img = NULL;
  
  // Initialize the graphics system
  // ********************************************************
  // Get a first window
  draw_startup( (char*)"Window 1", winwidth, winheight );

  if( argc == 2 ) { // If a filename was specified: open it
  
      uint32_t depth = 0;
      int alpha = 0;
      if ( LoadPngImage( argv[1], &imgwidth, &imgheight, &depth, &alpha, &img ) == 0 ) {
         printf( "failed to load image %s\n", argv[1] );
         exit(1);
      }
  }
  else { // No filename specified: create a blank image

      // Allocate an array for our image
      img = malloc( imgwidth * imgheight * sizeof(uint8_t) );
      if ( img == NULL ) {
         printf( "failed to allocate memory for image.\n" );
         exit(1);
      }

      // Set the whole array to zero 0 (black)
      memset( img, 0, imgwidth * imgheight * sizeof(img[0] ));
    }


  // Draw the array as a grey-scale image in the window
  // This function returns after a user clicks in the window or presses a button 
  printf( "Original image\n" );
  draw_image_grey( img, imgwidth, imgheight );


  // Test the darkest color function 
  uint8_t darkestColor = darkest(img, imgwidth, imgheight);
  printf("The darkest color in the image is: %u\n", darkestColor);


  // Test the lightest color function 
  uint8_t lightestColor = lightest(img, imgwidth, imgheight);
  printf("The lightest color in the image is: %u\n", lightestColor);


  // Testing the copy function
  printf("Copy of image\n");
  uint8_t *img2 = copy(img, imgwidth, imgheight); 
  draw_image_grey(img2, imgwidth, imgheight);
  

  // Testing the flipped horizontally function
  printf("Copy of image flipped horizontally\n");
  flip_horizontal (img2, imgwidth, imgheight);
  draw_image_grey(img2, imgwidth, imgheight);
  

  // Testing the replace color function
  printf("Copy of image with colors replaced\n");
  replace_color(img2, imgwidth, imgheight, 0, 255);
  draw_image_grey(img2, imgwidth, imgheight);
  
  
  // Testing the locate color function
  printf("Finding the first pixel with a value that is white\n");
  unsigned int x;
  unsigned int y; 
  locate_color(img2, imgwidth, imgheight, 0, &x, &y);
  printf("The first appearance of color white (255) is at the pixel (%d, %d)\n", x, y);
  

  // Testing the zero function
  printf("Copy of image zero'd\n");
  zero(img2, imgwidth, imgheight); 
  lightestColor = lightest(img2, imgwidth, imgheight);
  darkestColor = darkest(img2, imgwidth, imgheight);
  printf("The darkest color in the zero'd image is: %u\n", darkestColor);
  printf("The lightest color in the zero'd image is: %u\n", lightestColor);
  draw_image_grey(img2, imgwidth, imgheight);
  

  // ********************************************************
  // Get more windows if needed by copying, pasting and modifying the above code
  // ********************************************************
  
  // ********************************************************
  // Finalize the graphics system, freeing its resources
  draw_shutdown();

  // Every malloc() should have a matching free()
  free(img);
  free(img2);
   
  // Let's get in the habit of setting all freed pointers to NULL
  img = NULL;
  img2 = NULL;
  
  return 0;
}
