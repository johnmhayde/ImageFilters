/*
  John Michael Hayde, Timothy Quinton
*/
#include "GrayscaleFilter.h"

//constructor
GrayscaleFilter::GrayscaleFilter() : PixelFilter() {}

//copy constructor
GrayscaleFilter::GrayscaleFilter(const GrayscaleFilter&) : PixelFilter() {}

//destructor
GrayscaleFilter::~GrayscaleFilter() {}

/*
  Operation:
  finds the grayscale value of the input pixel by averaging the RGB values

  Parameters:
  const Pixel& pix, the input pixel

  Return:
  the new grayscale pixel constructed based on grayscale value
*/
Pixel GrayscaleFilter::apply_transform(const Pixel& pix) const {
  int grayscale = (pix.r() + pix.g() + pix.b()) / 3;
  grayscale = clamp(0,255,grayscale);

  Pixel temp(grayscale, grayscale, grayscale);
  return temp;
}
