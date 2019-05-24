/*
  John Michael Hayde, Timothy Quinton
*/
#ifndef BLURFILTER_H
#define BLURFILTER_H

#include "KernelFilter.h"

using namespace std;
using Matrix = vector<vector<double>>;

class BlurFilter : public KernelFilter {
protected:
  //k3 matrix for blurring image
  static const Matrix k3;

public:
  //basic constructors and destructor
  BlurFilter();
  BlurFilter(const BlurFilter&);
  ~BlurFilter();

  //blur's apply function
  virtual void apply(Image&) const;

};


#endif
