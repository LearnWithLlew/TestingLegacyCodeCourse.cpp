#include "TrigMath.h"

double TrigMath::sinRaw(int idx) {
    return SIN_TABLE[idx & SIN_MASK];
}

double TrigMath::cosRaw(int idx) {
    return SIN_TABLE[(idx + COS_OFFSET) & SIN_MASK];
}

double TrigMath::mxatan(double arg) {
    auto argsq = arg * arg;
    auto value = (((p4 * argsq + p3) * argsq + p2) * argsq + p1) * argsq + p0;
    value /= ((((argsq + q4) * argsq + q3) * argsq + q2) * argsq + q1) * argsq + q0;
    return value * arg;
}

double TrigMath::msatan(double arg) {
    if (arg < sq2m1)
        return mxatan(arg);
    if (arg > sq2p1)
        return HALF_PI - mxatan(1 / arg);
    return HALF_PI / 2 + mxatan((arg - 1) / (arg + 1));
}

void TrigMath::createSinTable() {
    for (auto i = 0; i < SIN_SIZE; i++)
        SIN_TABLE[i] = sin(i * TWO_PI / SIN_SIZE);
}

TrigMath::TrigMath() {
    createSinTable();
}

double TrigMath::sin(double angle) {
    return sinRaw(floor(angle * SIN_CONVERSION_FACTOR));
}

int TrigMath::floor(double a) {
    return (int) a;
}

double TrigMath::cos(double angle) {
    return cosRaw(floor(angle * SIN_CONVERSION_FACTOR));
}

double TrigMath::tan(double angle) {
    auto idx = floor(angle * SIN_CONVERSION_FACTOR);
    return sinRaw(idx) / cosRaw(idx);
}

double TrigMath::csc(double angle) {
    return 1 / sin(angle);
}

double TrigMath::sec(double angle) {
    return 1 / cos(angle);
}

double TrigMath::cot(double angle) {
    auto idx = floor(angle * SIN_CONVERSION_FACTOR);
    return cosRaw(idx) / sinRaw(idx);
}

double TrigMath::asin(double value) {
    if (value > 1)
        return NAN;
    if (value < 0)
        return -asin(-value);
    auto temp = sqrt(1 - value * value);
    if (value > 0.7)
        return HALF_PI - msatan(temp / value);
    return msatan(value / temp);
}

double TrigMath::acos(double value) {
    if (value > 1 || value < -1)
        return NAN;
    return HALF_PI - asin(value);
}

double TrigMath::atan(double value) {
    if (value > 0)
        return msatan(value);
    return -msatan(-value);
}

double TrigMath::atan2(double y, double x) {
    if (y + x == y)
        return y >= 0 ? HALF_PI : -HALF_PI;
    y = atan(y / x);
    if (x < 0) {
        if (y <= 0) {
            return y + PI;
        } else {
            return y - PI;
        }
    }
    return y;
}

double TrigMath::acsc(double value) {
    if (value == 0)
        return NAN;
    return asin(1 / value);
}

double TrigMath::asec(double value) {
    if (value == 0)
        return NAN;
    return acos(1 / value);
}

double TrigMath::acot(double value) {
    if (value == 0)
        return NAN;
    if (value > 0)
        return atan(1 / value);
    return atan(1 / value) + PI;
}

