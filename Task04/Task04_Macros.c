#include <stdio.h>

#define SQUARE(x) ((x) * (x))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define RUPEES_TO_PAISE(x) ((long)(x) * 100L)

static inline int square_function(int x)
{
    return x * x;
}

static inline int max_function(int a, int b)
{
    return a > b ? a : b;
}

int main(void)
{
    int a = 4, b = 7;
    printf("SQUARE(a + 1) = %d\n", SQUARE(a + 1));
    printf("MAX(a, b) = %d\n", MAX(a, b));
    printf("50 rupees in paise = %ld\n", RUPEES_TO_PAISE(50));
    printf("Function square = %d\n", square_function(a + 1));
    printf("Function max = %d\n", max_function(a, b));
    return 0;
}
