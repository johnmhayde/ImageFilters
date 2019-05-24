/*
  John Michael Hayde, Timothy Quinton
*/
#ifndef GRAYSCALEFILTER_H
#define GRAYSCALEFILTER_H

#include "PixelFilter.h"

using namespace std;

class GrayscaleFilter : public PixelFilter {
public:
  //basic constructors and destructor
  GrayscaleFilter();
  GrayscaleFilter(const GrayscaleFilter&);
  ~GrayscaleFilter();

  //apply transform for grayscale
  virtual Pixel apply_transform(const Pixel&) const;

};


#endif
