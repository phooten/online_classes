// Copied from Donald H. House's "Computer Graphics Images" in Chapter 1
// Class: Clemson University -> CPSC 6040

// Purpose:
//    a mixture of take aways and example programs from chapter 1 discussing
//    how to store pixels in an accessable and efficent way to refence each pixel
//    in a 2D array vs one continuous 1D array

void print_bitmap(unsigned char *bitmap, int width, int height);
void print_greymap(unsigned char *greymap, int width, int height);
void print_pixmap(unsigned int *pixmap, int width, int height);

int main(){
  const int ROWS = 8;
  const int COLS = 8;

  // image allocation - 1D
  //    - Continuous data but cant be accessesed by [rows][cols]
  unsigned char pixmap[ROWS][COLS];
  unsigned char * pixmap3;            // like pixmap2[]
  pixmap3 = new unsigned char[ROWS * COLS];

  // image allocation - 2D
  //    - inefficient and image dimensions are determined in runtime
  unsigned char pixmap2[ROWS * COLS];
  unsigned char ** pixmap4;           // like pixmap[][]
  pixmap4 = new unsigned char*[ROWS];
  for(int y = 0; y < ROWS; y++){
    pixmap3[y] = new unsigned char[COLS];
  }

  // Pixmap access
  pixmap[0][0];   // top left pixel (y, x) = (0, 0)
  pixmap2[0];

  pixmap[0][7];   // top right pixel (y, x) = (0, 7)
  pixmap2[7];

  pixmap[7][0];   // bottom left pixel, in general [index] = [y * COLS + x]
  pixmap2[56];

  pixmap[7][7];
  pixmap2[63];

  return 0;
}


//
//  pixmap display
//

void print_bitmap(unsigned char *bitmap, int width, int height){
  // Variables
  int w = (width + 7) / 8;  // number of bytes per scanline

  int row;                    // scan line number
  int col;                    // pixel number on scanline
  int byte;                 // byte number within bitmap array
  int bit;                  // bit number within byte
  int value;                // value of bit (0 or 1)

  for(row = 0; row < height; row++){          // loop for each scanline
    for(col = 0; col < width; col++){         // loop for each pixel on line
      byte = row * w + col / 8;
      value = bitmap[byte] >> bit & 1;  // isolate bit
      printf("%1d", value);
    }
    printf("\n");
  }
}



//
//  pixmap display
//

void print_greymap(unsigned char *greymap, int width, int height){
  // Variables
  int row;                                // scanline number
  int col;                                // pixel number on scanline
  int value;                            // value of pixel (0 to 255)

  for(row = 0; row < height; row++){          // loop for each scanline
    for(col = 0; col < width; col++){         // loop for each pixel on line
      value = greymap[y * width + col];   // fetch pixel value
      printf("%5.3f ", value / 255.0);
    }
    printf("\n");
  }
}


//
//  pixmap display
//

void print_pixmap(unsigned int *pixmap, int width, int height){
  int y;              // scanline number
  int x;              // pixel number on scanline
  unsigned int value; // pixel as fetched from pixmap
  int r, g, b;        // RGB values of pixel (0 to 255)

  for(y = 0; y < height; y++){        // loop for each scanline
    for(x = 0; x < width; x++){       // loop for each pixel on line
      value = pixmap[y * width + x];  // fetch pixel value
      r = value >> 24;
      g = (value >> 16) & 0xFF;
      b = (value >> 8) & 0xFF;
      printf("(%5.3f,%5.3f,%5.3f) ",
      r / 255.0, g / 255.0, b / 255.0);
    }
    printf("\n");
  }
}
