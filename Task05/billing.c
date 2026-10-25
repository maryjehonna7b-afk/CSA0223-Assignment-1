#include <stdio.h>
#include "billing.h"

long compute_bill(int units)
{
    long paise = FIXED_CHARGE_PAISE;

    if (units < 0)
        return -1;

    if (units > SLAB2_UNITS)
        paise += (long)(units - SLAB2_UNITS) * RATE3_PAISE;

    if (units > SLAB1_UNITS) {
        int second_slab;

        if (units < SLAB2_UNITS)
            second_slab = units - SLAB1_UNITS;
        else
            second_slab = SLAB2_UNITS - SLAB1_UNITS;

        paise += (long)second_slab * RATE2_PAISE;
    }

    if (units < SLAB1_UNITS)
        paise += (long)units * RATE1_PAISE;
    else
        paise += (long)SLAB1_UNITS * RATE1_PAISE;

#ifdef DEBUG
    printf("[DEBUG] units=%d, bill paise=%ld\n", units, paise);
#endif

    return paise;
}
