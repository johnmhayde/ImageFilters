/*
  John Michael Hayde, Timothy Quinton
*/
#include "VFlipFilter.h"
#include "../image/Header.h"

//constuctor
VFlipFilter::VFlipFilter() : SimpleFilter() {}

//copy constuctor
VFlipFilter::VFlipFilter(const VFlipFilter&) : SimpleFilter() {}

//destructor
VFlipFilter::~VFlipFilter() {}

/*
  Operation:
  reverses the order of each column of pixels in the image

  Parameters:
  Image& img, the input image

  Return:
  void, alters the input image
*/
void VFlipFilter::apply(Image& img) const {
  //gets width and height
  Header temp_header(img.header());
  int width = temp_header.width();
  int height = temp_header.height();

  //loops through each column and row, reverses the pixels in each column
  for(int k = 0; k < width; k++) {
    int end = height - 1;
    for(int i = 0; i <= end; i++) {
      Pixel temp = img(k,i);
      img(k,i) = img(k,end);
      img(k,end) = temp;
      end--;
    }
  }
}
