#include "temp_api.h"
#include <stdio.h>


void print_month_stat(SENSOR* data, int size, uint8_t month)
{
    printf("\n--- Статистика за месяц %02d ---\n", month);
    printf("Среднемесячная температура: [заглушка]\n");
    printf("Минимальная температура: [заглушка]\n");
    printf("Максимальная температура: [заглушка]\n");
};

void print_year_stat(SENSOR* data, int size, uint16_t year)
{
    printf("\n--- Статистика за год %d ---\n", year);
    printf("Среднегодовая температура: [заглушка]\n");
    printf("Минимальная температура в году: [заглушка]\n");
    printf("Максимальная температура в году: [заглушка]\n");
};