#include "TrigMath.h"

double TrigMath::SinRaw(int idx) {
    return SIN_TABLE[idx & SIN_MASK];
}
