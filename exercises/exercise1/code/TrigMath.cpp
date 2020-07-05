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
