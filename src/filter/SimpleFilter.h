/*
  John Michael Hayde, Timothy Quinton
*/
#ifndef SIMPLEFILTER_H
#define SIMPLEFILTER_H

#include "Filter.h"

using namespace std;

class SimpleFilter : public Filter {
protected:
  //constructor and copy constructor
  SimpleFilter();
  SimpleFilter(const SimpleFilter&);

public:
  //pure virtual destructor
  virtual ~SimpleFilter() = 0;

  //simplefilter's apply function, pure virtual so derived classes
  //apply function gets called
  virtual void apply(Image&) const = 0;

};

#endif
