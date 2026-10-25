#include <stdio.h>

int main(void)
{
    long paise;
    printf("Enter bill amount in paise: ");
    if (scanf("%ld", &paise) != 1 || paise < 0) {
        printf("Invalid amount\n");
        return 1;
    }
    printf("Bill: Rs %ld.%02ld\n", paise / 100, paise % 100);
    return 0;
}
