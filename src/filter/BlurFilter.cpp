/*
  John Michael Hayde, Timothy Quinton
*/
#include "BlurFilter.h"

//constructor
BlurFilter::BlurFilter() : KernelFilter() {}

//copy constructor
BlurFilter::BlurFilter(const BlurFilter&) : KernelFilter() {}

//destrctor
BlurFilter::~BlurFilter() {}

//k3 definition
const Matrix BlurFilter::k3 =
{{0.0625, 0.125, 0.0625},
{0.125, 0.25, 0.125},
{0.0625 ,0.125, 0.0625}};

/*
  Operation:
  calls kernelfilter's apply on the image with the desired matrix

  Parameters:
  Image& img, the input image

  Return:
  void, the function alters the image passed in
*/
void BlurFilter::apply(Image& img) const {
  KernelFilter::apply(img, k3);
}
