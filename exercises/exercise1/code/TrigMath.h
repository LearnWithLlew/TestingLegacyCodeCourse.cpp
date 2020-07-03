//
// Created by LLEWELLYN FALCO on 12/10/17.
//

#ifndef CATCHPLAYGROUND_TRIGMATH_H
#define CATCHPLAYGROUND_TRIGMATH_H

#define _USE_MATH_DEFINES
#include <math.h>
#include <cmath>

class TrigMath {
public:
    const double PI = M_PI;
    const double SQUARED_PI = PI * PI;
    const double HALF_PI = PI / 2;
    const double QUARTER_PI = HALF_PI / 2;
    const double TWO_PI = 2 * PI;
    const double THREE_PI_HALVES = TWO_PI - HALF_PI;
    const double DEG_TO_RAD = PI / 180;
    const double HALF_DEG_TO_RAD = PI / 360;
    const double RAD_TO_DEG = 180 / PI;
    double SQRT_OF_TWO = std::sqrt(2);
    double HALF_SQRT_OF_TWO = SQRT_OF_TWO / 2;
private  :

    const int SIN_SIZE = 100000;
    double SIN_TABLE[100000];
    const int SIN_MASK = SIN_SIZE - 1;
    const double SIN_CONVERSION_FACTOR = SIN_SIZE / TWO_PI;

    const int COS_OFFSET = SIN_SIZE / 4;

//Arc trig
    const double sq2p1 = 2.414213562373095048802;

    const double sq2m1 = 0.414213562373095048802;
    const double p4 = 0.161536412982230228262E2;
    const double p3 = 0.26842548195503973794141E3;
    const double p2 = 0.11530293515404850115428136E4;
    const double p1 = 0.178040631643319697105464587E4;
    const double p0 = 0.89678597403663861959987488E3;
    const double q4 = 0.5895697050844462222791E2;
    const double q3 = 0.536265374031215315104235E3;
    const double q2 = 0.16667838148816337184521798E4;
    const double q1 = 0.207933497444540981287275926E4;
    const double q0 = 0.89678597403663861962481162E3;

    double sinRaw(int idx);

    double cosRaw(int idx);

    double mxatan(double arg);

    double msatan(double arg);

    void createSinTable();

public:

    TrigMath();


    double sin(double angle);

    int floor(double a);


    double cos(double angle);

    double tan(double angle);

    double csc(double angle) {
        return 1 / sin(angle);
    }

    double sec(double angle);


    double cot(double angle);

    double asin(double value);

    double acos(double value);

    double atan(double value);

    double atan2(double y, double x);

    double acsc(double value);

    double asec(double value);

    double acot(double value);


};

#endif //CATCHPLAYGROUND_TRIGMATH_H
