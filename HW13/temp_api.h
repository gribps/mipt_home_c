#ifndef TEMP_API_H
#define TEMP_API_H

#include <stdint.h>

// структура для хранения данных о температуре
typedef struct {
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    int8_t temperature;
} SENSOR;

void print_month_stat(SENSOR* data, int size, uint8_t month);
void print_year_stat(SENSOR* data, int size, uint16_t year);
SENSOR* read_data(char *filename, int *out_size);

#endif