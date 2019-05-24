/*
  John Michael Hayde, Timothy Quinton
*/
#ifndef BINARYFILTER_H
#define BINARYFILTER_H

#include "PixelFilter.h"

using namespace std;

class BinaryFilter : public PixelFilter {
private:
  //the binary pixels
  Pixel white_pix;
  Pixel black_pix;

public:
  //basic constructors and destructor
  BinaryFilter();
  BinaryFilter(Pixel& left, Pixel& right);
  BinaryFilter(const BinaryFilter&);
  ~BinaryFilter();

  //binary's apply trnasform
  virtual Pixel apply_transform(const Pixel&) const;

};


#endif
