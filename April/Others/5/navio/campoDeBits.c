#include <stdio.h>
typedef struct 
{
  int red;
  int green;
  int blue;
} RGB;

typedef struct 
{
  int red: 12;
  int green: 12;
  int blue: 12;
} RGBbf;


int main(int argc, char const *argv[])
{
    RGB mRGB;
    RGBbf mRGBbf;

    mRGB.red=0;
    mRGB.green=0;
    mRGB.blue=0;

    mRGBbf.red=0;
    mRGBbf.green=0;
    mRGBbf.blue=0;

    for(int i=0; i<100; i++){
        printf("RGB   r(%d) g(%d) b(%d)\n", mRGB.red, mRGB.green, mRGB.blue);
        printf("RGBfb r(%d) g(%d) b(%d)\n\n", mRGBbf.red, mRGBbf.green, mRGBbf.blue);

        mRGB.red+=100;
        mRGB.green+=100;
        mRGB.blue+=100;

        mRGBbf.red+=100;
        mRGBbf.green+=100;
        mRGBbf.blue+=100;
    }

    printf("RGB   sof(%d)\n", sizeof(mRGB));
    printf("RGBfb sof(%d)\n", sizeof(mRGBbf));

    return 0;
}
