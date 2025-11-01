#include <stdio.h>
typedef unsigned float_bits; // alias for clarity

float_bits f2u(float f) {
    union {
        float f;
        unsigned u;
    } temp;
    temp.f = f;
    return temp.u;
}

float u2f(float_bits u) {
    union {
        unsigned u;
        float f;
    } temp;
    temp.u = u;
    return temp.f;
}

int float_le (float x, float y) { //Less or equal comparison
    unsigned ux = f2u(x); //f2u is a function that converts float to unsigned int
    unsigned uy = f2u(y);
    unsigned sx = ux >> 31;
    unsigned sy = uy >> 31;

    return (ux == uy) ||//Returns 1 when x == y
    ((sx ^ sy) && sx) || //Returns 1 when x < 0 and y >= 0
    (!(sx ^ sy) && ( (sx && ux >= uy) || 
    //Returns 1 when x and y have same sign
    //and are negative and x >= y
    (!sx && ux <= uy)));
    /*Returns 1 when x and y have same sign
    and are positive and x <= y*/
}

int main (){
    //Test problem 1 
    float a = -3.5;
    float b = 2.0;
    int result = float_le(a, b);
    printf("%d\n", result);

    float c = 1.5;
    float d = 1.5;
    int result2 = float_le(c, d);
    printf("%d\n", result2);

    float e = 4.0;
    float f = 5.0;
    int result3 = float_le(e, f);
    printf("%d\n", result3);

    return 0;
}