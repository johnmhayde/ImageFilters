#include "Image.h"

Image::Image (ifstream& in) :
 HDR (Image::read_header(in)), PIX (Image::read_pixels(HDR, in)) {}
Image::Image (const Image& img) :
  HDR(img.header()), PIX(img.pixels()) {}
Image::~Image () {}

// accessors1
const Header& Image::header () const { return this->HDR; }
const vector<Pixel>& Image::pixels () const { return this->PIX; }

// Get one pixel
Pixel& Image::operator() (int x, int y) {
  int ndx = (this->HDR.width() * y) + x;
  return this->PIX[ndx];
}

Header Image::read_header (ifstream& in) {
  string magic;
  int w, h, mc;

  in >> magic;
  Image::ignore_comments(in);
  in >> w;
  Image::ignore_comments(in);
  in >> h;
  Image::ignore_comments(in);
  in >> mc;
  in.ignore(256, '\n');
  return Header(magic, w, h, mc);
}

void Image::ignore_comments (ifstream& in) {
  char c;
  in.get(c);

  while (isspace(c) || c == '#') {
    if (c == '#')
      in.ignore(256, '\n');
    in.get(c);
  }

  in.unget();
}

vector<Pixel> Image::read_pixels (const Header& hdr, ifstream& in) {
  int num_pixels = hdr.width() * hdr.height();
  vector<Pixel> pixels(num_pixels);

  if (hdr.magic() == "P3") {
    uint r,g,b;
    for (Pixel& p : pixels) {
      in >> r >> g >> b;
      p = Pixel(r, g, b);
    }
  } else {
    uint8_t r,g,b;
    for (Pixel& p : pixels) {
      r = in.get();
      g = in.get();
      b = in.get();
      p = Pixel(r, g, b);
    }
  }

  return pixels;
}

void Image::make_p3 () { this->HDR.magic() = "P3"; }
void Image::make_p6 () { this->HDR.magic() = "P6"; }

void Image::write_header (ofstream& out) const {
  out << this->HDR.magic() << " "
      << this->HDR.width() << " "
      << this->HDR.height() << " "
      << this->HDR.max_color() << "\n";
}

void Image::write_to (ofstream& out) const {
  write_header(out);

  if (this->HDR.magic() == "P3") {
    for (const Pixel& p : this->PIX) {
      out << (int) p.r() << ' '
          << (int) p.g() << ' '
          << (int) p.b() << ' ';
    }
  } else {
    for (const Pixel& p : this->PIX) {
      out << p.r() << p.g() << p.b();
    }
  }
}
