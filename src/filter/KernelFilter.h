/*
  John Michael Hayde, Timothy Quinton
*/
#ifndef KERNELFILTER_H
#define KERNELFILTER_H

#include "Filter.h"

using namespace std;
using Matrix = vector<vector<double>>;

class KernelFilter : public Filter {
protected:
  //basic contructors
  KernelFilter();
  KernelFilter(const KernelFilter&);

  //KernelFilter's apply and apply kernel
  virtual void apply(Image&, const Matrix& k) const;
  virtual Pixel apply_kernel(Image&, int x, int y, const Matrix&) const;

public:
  //pure virtual destructor
  virtual ~KernelFilter() = 0;

  //static helpers
  static int clamp (int lo, int hi, int x);
  static double clamp (double lo, double hi, double x);

  //image functions
  virtual void apply (Image&) const = 0;

};

#endif
