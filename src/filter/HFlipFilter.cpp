/*
  John Michael Hayde, Timothy Quinton
*/
#include "HFlipFilter.h"
#include "../image/Header.h"

//contructor
HFlipFilter::HFlipFilter() : SimpleFilter() {}

//copy constructor
HFlipFilter::HFlipFilter(const HFlipFilter&) : SimpleFilter() {}

//destructor
HFlipFilter::~HFlipFilter() {}

/*
  Operation:
  reverses the order of each row of pixels in the image

  Parameters:
  Image& img, the input image

  Return:
  void, alters the input image
*/
void HFlipFilter::apply(Image& img) const {
  //gets width and height info
  Header temp_header(img.header());
  int width = temp_header.width();
  int height = temp_header.height();

  //loops through each column and row, reverses the pixels in each row
  for(int i = 0; i < height; i++) {
    int end = width - 1;
    for(int k = 0; k <= end; k++) {
      Pixel temp = img(k,i);
      img(k,i) = img(end,i);
      img(end,i) = temp;
      end--;
    }
  }
}
