/*
  John Michael Hayde, Timothy Quinton
*/
#ifndef PIXELFILTER_H
#define PIXELFILTER_H

#include "Filter.h"

using namespace std;

class PixelFilter : public Filter {

public:
  //basic constructors and destructors
  PixelFilter();
  PixelFilter(const PixelFilter&);
  virtual ~PixelFilter() = 0;

  //PixelFilter's apply function
  virtual void apply(Image&) const;

  //apply_transform is pure virtual so the derived classes apply_transform
  //will be called
  virtual Pixel apply_transform(const Pixel&) const = 0;

};


#endif
