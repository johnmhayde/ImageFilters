/*
  John Michael Hayde, Timothy Quinton
*/
#include "Filter.h"

//constructor
Filter::Filter() : name("") {}

//parameter constructor
Filter::Filter(string name) : name(name) {}

//copy constructor
Filter::Filter(const Filter& f) : name(f.name)  {}

//destructor
Filter::~Filter() {}

//clamp with int parameters
int Filter::clamp (int lo, int hi, int x) {
  return std::max(lo, std::min(x, hi));
}

//clamp with double parameters
double Filter::clamp (double lo, double hi, double x) {
  return std::max(lo, std::min(x, hi));
}
