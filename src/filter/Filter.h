/*
  John Michael Hayde, Timothy Quinton
*/
#ifndef FILTER_H
#define FILTER_H

#include "../image/Image.h"

using namespace std;

class Filter {
  protected:
    // Data - Shows that abstract classes can still contain data
    string name;

    // Derived classes need these visible
    Filter();
    Filter(string);
    Filter(const Filter&);

  public:
    // Pure virtual destructor - Still needs definition!
    virtual ~Filter () = 0;

    // Static helpers - should be a template
    static int clamp (int lo, int hi, int x);
    static double clamp (double lo, double hi, double x);

    // Public Interface - every derived class must implement
    //                  - or be abstract itself
    virtual void apply (Image&) const = 0;
};

#endif
