/*
  John Michael Hayde, Timothy Quinton
*/
#ifndef VFLIPFILTER_H
#define VFLIPFILTER_H

#include "SimpleFilter.h"

using namespace std;

class VFlipFilter : public SimpleFilter {

public:
  //basic constructors and destructor
  VFlipFilter();
  VFlipFilter(const VFlipFilter&);
  ~VFlipFilter();

  //VFlipFilter's apply function
  virtual void apply(Image&) const;

};


#endif
