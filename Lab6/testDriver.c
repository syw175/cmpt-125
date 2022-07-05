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
#include "Quiz2.h"


int main( int argc, char* argv[] ) {

  // Windowing system setup
  const unsigned int winwidth  = 400;
  const unsigned int winheight = 400;

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

  // ********************************************************
  // Get more windows if needed by copying, pasting and modifying the above code
  // ********************************************************
  
  // Testing the print pixel function here
  printf("The original pixel color is: ");
  print_pixel(img, imgwidth, imgheight, 0, 0);


  // Testing the scale_factor function here
  scale_brightness(img, imgwidth, imgheight, 1000000);
  printf("The new color after changing by a factor of 100 is: ");
  print_pixel(img, imgwidth, imgheight, 0, 0);
  draw_image_grey(img, imgwidth, imgheight);






  // ********************************************************
  // Finalize the graphics system, freeing its resources
  draw_shutdown();

  // Every malloc() should have a matching free()
  free(img);
   
  // Let's get in the habit of setting all freed pointers to NULL
  img = NULL;
  
  return 0;
}
