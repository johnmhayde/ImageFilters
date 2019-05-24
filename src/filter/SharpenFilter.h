/*
  John Michael Hayde, Timothy Quinton
*/
#ifndef SHARPENFILTER_H
#define SHARPENFILTER_H

#include <string>
#include <algorithm>
#include <sstream>
#include "KernelFilter.h"

using namespace std;
using Matrix = vector<vector<double>>;

class SharpenFilter : public KernelFilter {
protected:
  //sharpens matrix
  static const Matrix k3;


public:
  //basic constructors and desrructors
  SharpenFilter();
  SharpenFilter(const SharpenFilter&);
  ~SharpenFilter();

  //sharpens apply function
  virtual void apply(Image&) const;

};


#endif
