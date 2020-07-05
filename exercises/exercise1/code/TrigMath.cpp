#include "TrigMath.h"

double TrigMath::SinRaw(int idx) {
    return SIN_TABLE[idx & SIN_MASK];
}

double TrigMath::CosRaw(int idx) {
    return SIN_TABLE[(idx + COS_OFFSET) & SIN_MASK];
}
