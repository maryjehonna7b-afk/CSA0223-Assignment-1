#include <stdio.h>
#include "billing.h"

int main(void)
{
    int units = 150;
    long bill = compute_bill(units);

    if (bill < 0) {
        printf("Invalid units\n");
        return 1;
    }

    printf("Bill for %d units: Rs %ld.%02ld\n",
           units, bill / 100, bill % 100);

    return 0;
}
