#ifndef COLOR_FILE
#define COLOR_FILE

struct color_file
{
    unsigned short int r;
    unsigned short int g;
    unsigned short int b;
    color_file(unsigned short int red, unsigned short int green, unsigned short int blue):
        r(red), g(green), b(blue) {}
};

#endif
