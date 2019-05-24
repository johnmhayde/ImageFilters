#include "Pixel.h"

Pixel::Pixel () : R(0), G(0), B(0) {}
Pixel::Pixel (const Pixel& P) : R(P.R), G(P.G), B(P.B) {}
Pixel::Pixel (Pixel&& P) : R(P.R), G(P.G), B(P.B) {}
Pixel::Pixel (uint8_t R, uint8_t G, uint8_t B) : R(R), G(G), B(B) {}
Pixel::~Pixel() {}

uint8_t Pixel::r () const { return this->R; }
uint8_t Pixel::g () const { return this->G; }
uint8_t Pixel::b () const { return this->B; }

uint8_t& Pixel::r () { return this->R; }
uint8_t& Pixel::g () { return this->G; }
uint8_t& Pixel::b () { return this->B; }

// "brightness" of a pixel
uint8_t Pixel::luminance () const {
  double lR, lG, lB;
  lR = Pixel::gamma_expansion((double)this->R/255.0);
  lG = Pixel::gamma_expansion((double)this->G/255.0);
  lB = Pixel::gamma_expansion((double)this->B/255.0);
  double lY = 0.2126*lR + 0.7152*lG + 0.0722*lB;
  double sY = lY > 1.0 ? inverse_gamma(1.0) : inverse_gamma(lY);
  return (uint8_t) (sY*255.0);
}

// Output
ostream& operator<< (ostream& out, const Pixel& P) {
 return out  << "(" << (int)P.R << " "
                    << (int)P.G << " "
                    << (int)P.B << ")";
}

// Assignment
Pixel& Pixel::operator= (const Pixel& rhs) {
  if (&rhs == this)
    return *this;
  this->R = rhs.R;
  this->G = rhs.G;
  this->B = rhs.B;
  return *this;
}

Pixel& Pixel::operator= (Pixel&& rhs) {
  this->R = rhs.R;
  this->G = rhs.G;
  this->B = rhs.B;
  return *this;
}
