/*
  John Michael Hayde, Timothy Quinton
*/
#ifndef HFLIPFILTER_H
#define HFLIPFILTER_H

#include "SimpleFilter.h"

using namespace std;

class HFlipFilter : public SimpleFilter {

public:
  //basic constructors and destructor
  HFlipFilter();
  HFlipFilter(const HFlipFilter&);
  ~HFlipFilter();

  //HFlipFilter's apply function
  virtual void apply(Image&) const;

};


#endif
