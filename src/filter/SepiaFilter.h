/*
  John Michael Hayde, Timothy Quinton
*/
#ifndef SEPIAFILTER_H
#define SEPIAFILTER_H

#include "PixelFilter.h"

using namespace std;

class SepiaFilter : public PixelFilter {
public:
  //basic constructors and destructors
  SepiaFilter();
  SepiaFilter(const SepiaFilter&);
  ~SepiaFilter();

  //sepia filter's apply_transform, will be called since PixelFilter's
  //apply_transform is pure virtual
  virtual Pixel apply_transform(const Pixel&) const;

};


#endif
