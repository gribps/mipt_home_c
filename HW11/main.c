#include <stdio.h>
#include "temp_api.h"

#define ARRAY_SIZE 3

int main() 
{
    SENSOR records[ARRAY_SIZE] = {
        {2026, 8, 31, 12, 0, 25},
        {2026, 8, 31, 18, 30, 22},
        {2026, 12, 1, 6, 15, -10}
    };

    print_month_stat(records, ARRAY_SIZE, 8);
    print_year_stat(records, ARRAY_SIZE, 2026);

    return 0;
}