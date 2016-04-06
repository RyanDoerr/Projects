//
//  pi.cpp
//  PI
//
//  Created by Ryan Doerr on 4/6/16.
//  Copyright © 2016 Ryan Doerr. All rights reserved.
//

#include <iostream>
#include <math.h>


//Nilikantha algorithm
//π = 3 + 4/(2*3*4) - 4/(4*5*6) + 4/(6*7*8) - 4/(8*9*10) + 4/(10*11*12) - 4/(12*13*14)

double Nilikantha(double four, long double pi, double n, bool sign){
    if (n==36000){//this is about how many n/2 iterations are required for cout.precision(14
        return pi;
    }
    else {
        n += 2;
        if (!sign){
            four = -4;
        }
        else {
            four = 4;
        }
        return pi + (Nilikantha(four, (four/(n*(n+1)*(n+2))), n,!(sign)));
    }
};
int main(int argc, const char * argv[]) {
    std::cout.precision(14);
    double pi;
    pi = Nilikantha(4, 3, 0, 1);
    std::cout << "PI: 14 decimal points of precision" << std::endl << pi << std::endl;
    return 0;
}
