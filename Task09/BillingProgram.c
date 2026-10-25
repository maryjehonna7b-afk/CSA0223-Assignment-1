#include <stdio.h>

#define METER_MAX 65535U
#define SLAB1_UNITS 100U
#define SLAB2_UNITS 200U
#define RATE1_PAISE 0LL
#define RATE2_PAISE 225LL
#define RATE3_PAISE 450LL
#define FIXED_CHARGE_PAISE 5000LL

unsigned int consumption(unsigned int previous, unsigned int current)
{
    if (current >= previous)
        return current - previous;
    return (METER_MAX - previous) + 1U + current;
}

long long compute_bill(unsigned int units)
{
    long long paise = FIXED_CHARGE_PAISE;
    if (units > SLAB2_UNITS)
        paise += (long long)(units - SLAB2_UNITS) * RATE3_PAISE;
    if (units > SLAB1_UNITS) {
        unsigned int second = units < SLAB2_UNITS ?
                              units - SLAB1_UNITS : SLAB2_UNITS - SLAB1_UNITS;
        paise += (long long)second * RATE2_PAISE;
    }
    paise += (long long)(units < SLAB1_UNITS ? units : SLAB1_UNITS) * RATE1_PAISE;
    return paise;
}

int main(void)
{
    long previous, current;
    unsigned int units;
    long long bill;

    printf("Enter previous reading (0-65535): ");
    if (scanf("%ld", &previous) != 1 || previous < 0 || previous > 65535) {
        printf("Invalid reading\n");
        return 1;
    }
    printf("Enter current reading (0-65535): ");
    if (scanf("%ld", &current) != 1 || current < 0 || current > 65535) {
        printf("Invalid reading\n");
        return 1;
    }

    units = consumption((unsigned int)previous, (unsigned int)current);
    bill = compute_bill(units);
    printf("Units consumed: %u\n", units);
    printf("Total bill: Rs %lld.%02lld\n", bill / 100, bill % 100);
    return 0;
}
