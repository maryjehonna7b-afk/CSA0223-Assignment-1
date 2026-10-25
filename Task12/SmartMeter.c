#include <stdio.h>

int main(void)
{
    long long yearly_wh, peak_wh, offpeak_wh;
    long long rate_paise_per_kwh, fixed_paise;
    int peak_percent;
    long long offpeak_kwh, peak_kwh, energy_paise, peak_charge, bill_paise;

    /* tariff.cfg contains: off-peak rate, peak rate, fixed charge, peak percentage */
    FILE *fp = fopen("tariff.cfg", "r");
    if (fp == NULL) {
        printf("Could not open tariff.cfg\n");
        return 1;
    }
    if (fscanf(fp, "%lld %lld %lld %d",
               &rate_paise_per_kwh, &peak_charge, &fixed_paise, &peak_percent) != 4) {
        fclose(fp);
        printf("Invalid tariff file\n");
        return 1;
    }
    fclose(fp);

    printf("Enter yearly energy in Wh: ");
    if (scanf("%lld", &yearly_wh) != 1 || yearly_wh < 0) {
        printf("Invalid reading\n");
        return 1;
    }
    printf("Enter peak-hour energy in Wh: ");
    if (scanf("%lld", &peak_wh) != 1 || peak_wh < 0 || peak_wh > yearly_wh) {
        printf("Invalid peak reading\n");
        return 1;
    }

    offpeak_wh = yearly_wh - peak_wh;
    offpeak_kwh = offpeak_wh / 1000;
    peak_kwh = peak_wh / 1000;

    /* This beginner version uses whole kWh. The report notes this limitation. */
    energy_paise = offpeak_kwh * rate_paise_per_kwh +
                   peak_kwh * peak_charge;
    energy_paise += (energy_paise * peak_percent + 50) / 100;
    bill_paise = energy_paise + fixed_paise;

    printf("Readings per year: 35040\n");
    printf("Yearly energy: %lld Wh\n", yearly_wh);
    printf("Peak energy: %lld Wh; off-peak energy: %lld Wh\n", peak_wh, offpeak_wh);
    printf("Bill: Rs %lld.%02lld\n", bill_paise / 100, bill_paise % 100);
    return 0;
}
