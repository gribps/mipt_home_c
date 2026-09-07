#include "temp_api.h"
#include <stdio.h>

void print_month_stat(SENSOR* data, const int size, uint8_t month)
{

    // mean
    float res=0;
    int cnt=0;
    int inx_month[size];
    for(int i=0; i<size; i++){
        if(data[i].month == month){
            res += data[i].temperature;
            inx_month[cnt] = i;
            cnt++;
        }
    }
    if(cnt==0){
        printf("Input data does not contain the specified month\n");
        return;
    }
    res /= cnt;
    printf("\n--- Statistics for month %02d ---\n", month);
    printf("Average temperature: %.1f deg Cels\n", res);

    // min-max
    int min = data[inx_month[0]].temperature;
    int max = data[inx_month[0]].temperature;
    for(int i=1; i<cnt; i++){
        if(min > data[inx_month[i]].temperature)
            min = data[inx_month[i]].temperature;
        if(max < data[inx_month[i]].temperature)
            max = data[inx_month[i]].temperature;
    }
    printf("Minimum temperature: %d deg Cels\n", min);
    printf("Maximum temperature: %d deg Cels\n", max);
};

void print_year_stat(SENSOR* data, int size, uint16_t year)
{
    // mean
    float res=0;
    int cnt=0;
    int inx_year[size];
    for(int i=0; i<size; i++){
        if(data[i].year == year){
            res += data[i].temperature;
            inx_year[cnt] = i;
            cnt++;
        }
    }
    if(cnt==0){
        printf("Input data does not contain the specified year\n");
        return;
    }
    res /= cnt;

    printf("\n--- Statistics for year %d ---\n", year);
    printf("Average temperature: %.1f deg Cels\n", res);

    // min-max
    int min = data[inx_year[0]].temperature;
    int max = data[inx_year[0]].temperature;
    for(int i=1; i<cnt; i++){
        if(min > data[inx_year[i]].temperature)
            min = data[inx_year[i]].temperature;
        if(max < data[inx_year[i]].temperature)
            max = data[inx_year[i]].temperature;
    }    
    printf("Minimum temperature: %d deg Cels\n", min);
    printf("Maximum temperature: %d deg Cels\n", max);
};