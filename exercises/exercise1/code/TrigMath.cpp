#include "TrigMath.h"

double TrigMath::SinRaw(int idx) {
    return SIN_TABLE[idx & SIN_MASK];
}

double TrigMath::CosRaw(int idx) {
    return SIN_TABLE[(idx + COS_OFFSET) & SIN_MASK];
}

double TrigMath::Mxatan(double arg) {
    auto argsq = arg * arg;
    auto value = (((p4 * argsq + p3) * argsq + p2) * argsq + p1) * argsq + p0;
    value /= ((((argsq + q4) * argsq + q3) * argsq + q2) * argsq + q1) * argsq + q0;
    return value * arg;
}

double TrigMath::Msatan(double arg) {
    if (arg < sq2m1)
        return Mxatan(arg);
    if (arg > sq2p1)
        return HALF_PI - Mxatan(1 / arg);
    return HALF_PI / 2 + Mxatan((arg - 1) / (arg + 1));
}

void TrigMath::CreateSinTable() {
    for (auto i = 0; i < SIN_SIZE; i++)
        SIN_TABLE[i] = sin(i * TWO_PI / SIN_SIZE);
}

TrigMath::TrigMath() {
    CreateSinTable();
}

double TrigMath::Sin(double angle) {
    return SinRaw(Floor(angle * SIN_CONVERSION_FACTOR));
}

int TrigMath::Floor(double a) {
    return (int) a;
}

double TrigMath::Cos(double angle) {
    return CosRaw(Floor(angle * SIN_CONVERSION_FACTOR));
}

double TrigMath::Tan(double angle) {
    auto idx = Floor(angle * SIN_CONVERSION_FACTOR);
    return SinRaw(idx) / CosRaw(idx);
}

double TrigMath::Sec(double angle) {
    return 1 / Cos(angle);
}

double TrigMath::Cot(double angle) {
    auto idx = Floor(angle * SIN_CONVERSION_FACTOR);
    return CosRaw(idx) / SinRaw(idx);
}

double TrigMath::Asin(double value) {
    if (value > 1)
        return NAN;
    if (value < 0)
        return -Asin(-value);
    auto temp = sqrt(1 - value * value);
    if (value > 0.7)
        return HALF_PI - Msatan(temp / value);
    return Msatan(value / temp);
}

double TrigMath::Acos(double value) {
    if (value > 1 || value < -1)
        return NAN;
    return HALF_PI - Asin(value);
}

double TrigMath::Atan(double value) {
    if (value > 0)
        return Msatan(value);
    return -Msatan(-value);
}

double TrigMath::Atan2(double y, double x) {
    if (y + x == y)
        return y >= 0 ? HALF_PI : -HALF_PI;
    y = Atan(y / x);
    if (x < 0) {
        if (y <= 0) {
            return y + PI;
        } else {
            return y - PI;
        }
    }
    return y;
}

double TrigMath::Acsc(double value) {
    if (value == 0)
        return NAN;
    return Asin(1 / value);
}

double TrigMath::Asec(double value) {
    if (value == 0)
        return NAN;
    return Acos(1 / value);
}

double TrigMath::Acot(double value) {
    if (value == 0)
        return NAN;
    if (value > 0)
        return Atan(1 / value);
    return Atan(1 / value) + PI;
}

