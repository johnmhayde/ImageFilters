/*
  John Michael Hayde, Timothy Quinton
*/
#include "KernelFilter.h"

//constructor
KernelFilter::KernelFilter() : Filter() {}

//copy constructor
KernelFilter::KernelFilter(const KernelFilter& f) : Filter(f.name) {}

//destructor
KernelFilter::~KernelFilter() {}

//clamp that takes int parameters
int KernelFilter::clamp (int lo, int hi, int x) {
  return std::max(lo, std::min(x, hi));
}

//clamp that takes double parameters
double KernelFilter::clamp (double lo, double hi, double x) {
  return std::max(lo, std::min(x, hi));
}

/*
  Operation:
  loops through each pixel of the image and calls apply_kernel

  Parameters:
  Image& img, the input image
  const Matrix& k, the input matrix

  Return:
  void, alters the input image
*/
void KernelFilter::apply(Image& img, const Matrix& k) const {
  //gets center and header info
  int k_center = k.size()/2;
  int img_rows = img.header().height();
  int img_cols = img.header().width();

  // Make reference image
  Image copy(img);

  // Apply kernel to each pixel
  // Omit outer edges. Simplest solution
  for (int y = k_center; y < img_rows-k_center; y++) {
    for (int x = k_center; x < img_cols-k_center; x++) {
      img(x,y) = this->apply_kernel(copy, x, y, k);
    }
  }
}

/*
  Operation:
  loops through each pixel surrounding the given pixel at x,y and applies the
  equivalent matrix value to the pixel, then adds all the RBG values together

  Parameters:
  Image& ing, int x, int y, const Matrix& k

  Return:
  the new pixel that is created after the matrix is applied
*/
Pixel KernelFilter::apply_kernel(Image& img, int x, int y, const Matrix& k) const {
  int k_center = k.size()/2;
  int r, g, b;
  r = g = b = 0;

  // The kernel is centered at k_center (1 for a 3x3 kernel)
  // This loop takes values -1, 0, 1 which we can use as offsets
  // Nice because we can use as offsets for kernel and image pixel at x,y
  for (int j = -k_center; j <= k_center; j++) {
    for (int i = -k_center; i <= k_center; i++) {
      Pixel& p = img(x+i,y+i);
      double modifier = k[k_center+i][k_center+j];
      r += (int)(p.r() * modifier);
      g += (int)(p.g() * modifier);
      b += (int)(p.b() * modifier);
    }
  }

  // Make sure within RBG range of pixel
  r = clamp(0,255,r);
  g = clamp(0,255,g);
  b = clamp(0,255,b);

  return Pixel(r,g,b);
}
