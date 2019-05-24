#ifndef PIXEL_H
#define PIXEL_H 1

#include <math.h>
#include <ostream>
#include <iostream>

using namespace std;

class Pixel {
  private:
    uint8_t R, G, B;

  public:
    Pixel ();
    Pixel (const Pixel&);
    Pixel (Pixel&&);
    Pixel (uint8_t, uint8_t, uint8_t);
    ~Pixel ();

    // Plain getters, use only these for immutable pixels
    uint8_t r () const;
    uint8_t g () const;
    uint8_t b () const;

    // Non-const ref getters, use for Python style accessors
    // If we want to do validation, we can use true setters...
    // But a Pixel is basically a glorified struct
    uint8_t& r ();
    uint8_t& g ();
    uint8_t& b ();

    // Brightness of a pixel, useful in many filters
    uint8_t luminance() const;

    // input: color channel (C) intensity between 0-1
    // output: linear color curve mapping 0-1
    // Gamma exspansion of sRGB value to linear RGB
    static inline double gamma_expansion (double C) {
      return C < 0.04045 ? C/12.92 : pow((C + 0.055)/1.055 , 2.4);
    }

    // Inverse gamma expansion
    // input: linear color intensity (C) between 0-1
    // output: sRGB color curve mapping 0-1
    static inline double inverse_gamma (double C) {
      return C < 0.0031308 ? C*12.92 : pow(1.055 * C, 1.0/2.4) - 0.055;
    }

    // Assignment operator
    Pixel& operator=(const Pixel&);
    Pixel& operator=(Pixel &&);

    // Output operator
    friend ostream& operator<<(ostream&, const Pixel&);
};

#endif
