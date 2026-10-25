#include <stdio.h>

int main(void)
{
    int counts[] = {4000, 60000, 800000};
    int i;
    for (i = 0; i < 3; i++) {
        int n = counts[i], j;
        double total_rupees = 0.0;
        long long total_paise = 0;
        for (j = 0; j < n; j++) {
            total_rupees += 162.50;
            total_paise += 16250;
        }
        printf("%d bills: double Rs %.2f; integer paise Rs %lld.%02lld; difference Rs %.8f\n",
               n, total_rupees, total_paise / 100, total_paise % 100,
               total_rupees - (double)total_paise / 100.0);
    }
    return 0;
}
