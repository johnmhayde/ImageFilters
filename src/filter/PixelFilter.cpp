/*
  John Michael Hayde, Timothy Quinton
*/
#include "PixelFilter.h"

//constructor
PixelFilter::PixelFilter() : Filter() {}

//copy constructor
PixelFilter::PixelFilter(const PixelFilter&) : Filter() {}

//destructor
PixelFilter::~PixelFilter() {}

/*
  Operation:
  loops through each pixel in the image and calls apply_transform on each pixel

  Parameters:
  image& img, the input image

  Return:
  void, alters the input image
*/
void PixelFilter::apply(Image& img) const {
  Header temp_header(img.header());
  int width = temp_header.width();
  int height = temp_header.height();

  for(int i = 0; i < height; i++) {
    for(int k = 0; k < width; k++) {
      img(k,i) = apply_transform(img(k,i));
    }
  }
}
