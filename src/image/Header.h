#ifndef HEADER_T
#define HEADER_T 1

#include <string>
#include <iostream>

using namespace std;

class Header {
private:
    string MAGIC;
    int W, H, MC;

  public:
    Header ();
    Header (const Header& HDR);
    Header (string m, int w, int h, int mc);
    ~Header ();

    // Value getter, use only these for immutable headers
    string magic() const;
    int width() const;
    int height() const;
    int max_color() const;

    // Ref getter, might want to make these true setters...
    string& magic();
    int& width();
    int& height();
    int& max_color();

    // Assignment
    Header& operator= (const Header&);
    // Output
    friend ostream& operator<< (ostream&, const Header&);
};

#endif
