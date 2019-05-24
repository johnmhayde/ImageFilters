/*
  John Michael Hayde, Timothy Quinton
*/
#include "BinaryFilter.h"

//default constructor
BinaryFilter::BinaryFilter() : PixelFilter(),
white_pix(255,255,255), black_pix(0,0,0) {}

//parameter constructor
BinaryFilter::BinaryFilter(Pixel& left, Pixel& right) :
PixelFilter(), white_pix(left), black_pix(right) {}

//copy constructor
BinaryFilter::BinaryFilter(const BinaryFilter& filter) :
PixelFilter(), white_pix(filter.white_pix), black_pix(filter.black_pix) {}

//destructor
BinaryFilter::~BinaryFilter() {}

/*
  Operation:
  finds luminace, if that is greater than half the max pixel value, returns
  white if greater than and black if less than

  Parameters:
  const Pixel& pix, the input pixel.

  Return:
  The new pixel, either white or black depending on luminance value
*/
Pixel BinaryFilter::apply_transform(const Pixel& pix) const {
  if(pix.luminance() > 127) {
    return white_pix;
  }
  else {
    return black_pix;
  }
}
