/*
  John Michael Hayde, Timothy Quinton
*/
#include "SepiaFilter.h"

//constructor
SepiaFilter::SepiaFilter() : PixelFilter() {}

//copy contructor
SepiaFilter::SepiaFilter(const SepiaFilter&) : PixelFilter() {}

//destructor
SepiaFilter::~SepiaFilter() {}

/*
  Operation:
  finds the corresponding sepia sum for each RBg value,
  creates a new Pixel based on the new values

  Parameters:
  const Pixel& pix, the input pixel

  Return:
  The new pixel with altered RBG values to fit the sepia values
*/
Pixel SepiaFilter::apply_transform(const Pixel& pix) const {
  //finds new RGB values based on sepia algorithm
  int out_red = (pix.r() * .393) + (pix.g() * .769) + (pix.b() * .189);
  int out_green = (pix.r() * .349) + (pix.g() * .686) + (pix.b() * .168);
  int out_blue = (pix.r() * .272) + (pix.g() * .534) + (pix.b() * .131);

  //clamps new values
  out_red = clamp(0,255,out_red);
  out_green = clamp(0,255,out_green);
  out_blue = clamp(0,255,out_blue);

  //makes a new pixel off of new RBG values and returns it
  Pixel temp(out_red, out_green, out_blue);
  return temp;
}
