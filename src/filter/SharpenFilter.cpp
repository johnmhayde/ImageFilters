/*
  John Michael Hayde, Timothy Quinton
*/
#include "SharpenFilter.h"

//constructor
SharpenFilter::SharpenFilter() : KernelFilter() {}

//copy contructor
SharpenFilter::SharpenFilter(const SharpenFilter&) : KernelFilter() {}

//destructor
SharpenFilter::~SharpenFilter() {}

//k3 matrix definition
const Matrix SharpenFilter::k3 =
{{0, -1, 0},
{-1, 5, -1},
{0 ,-1, 0}};

/*
  Operation:
  calls KernelFilter's apply function with the input image and sharpen matrix

  Parameters:
  Image& img, the input image

  Return:
  void, alters the input image
*/
void SharpenFilter::apply(Image& img) const {
  KernelFilter::apply(img, k3);
}
