#include "temp_api.h"
#include <stdio.h>
#include <stdlib.h>

SENSOR* read_data(char *filename, int *out_size)
{
    // выделение памяти
    int capacity = 10;
    SENSOR *data = malloc(sizeof(SENSOR)*capacity);
    if(data==NULL){
        printf("Memory allocation error");
        return NULL;
    }

    // открытие файла
    FILE *f = fopen(filename,"r");
    if(f==NULL){
        perror(filename);
        free(data);
        *out_size=0;
        return NULL;
    }

    // чтение строк в буфер до конца файла
    char buff[100]="";
    int line_num=0, cnt_data=0;

    while(fgets(buff, sizeof(buff), f)!=NULL)
    {
        line_num++;

        int y, m, d, h, min, t;
        if(sscanf(buff, "%d;%d;%d;%d;%d;%d", &y, &m, &d, &h, &min, &t) == 6)
        {
            data[cnt_data].year = (uint16_t)y;
            data[cnt_data].month = (uint8_t)m;
            data[cnt_data].day = (uint8_t)d;
            data[cnt_data].hour = (uint8_t)h;
            data[cnt_data].minute = (uint8_t)min; 
            data[cnt_data].temperature = (int8_t)t;
            cnt_data++;
        }   
        else
            printf("Read data error in line %d \"%s\". This data is not used.\n", line_num, filename);

        // динамическое выделение памяти
        if(cnt_data >= capacity)
        {
            capacity += 1000;
            SENSOR *tmp = realloc(data, capacity * sizeof(SENSOR));
            if(tmp==NULL){
                printf("Memory allocation error");
                free(data);
                fclose(f);
                return NULL;
            }
            data = tmp;
        }
    }

    fclose(f);
    printf("\nNumber of valid measuments in \"%s\": %d\n", filename, cnt_data);
    printf("Number of read errors: %d\n\n", line_num - cnt_data);

    *out_size = cnt_data;
    return data;
};

void print_month_stat(SENSOR* data, const int size, uint8_t month)
{
    static int cnt_call = 0;
    if(month==0)
    {
        for(int i=1; i<13 ;i++)
            print_month_stat(data, size, i);
        return;
    }

    float avg = 0;
    int cnt = 0;
    int min = 999;
    int max =-999;
    for(int i=0; i<size; i++){
        if(data[i].month == month){
            avg += data[i].temperature;
            if(data[i].temperature < min)
                min = data[i].temperature;
            if(data[i].temperature > max)
                max = data[i].temperature;
            cnt++;
        }
    }
    if(cnt==0){
        printf("Input data does not contain the specified month %2d\n", month);
        return;
    }
    avg /= cnt;
    
    if(cnt_call==0){
        printf("Year Month MonthAvg MonthMax MonthMin NumMeas\n");
        cnt_call++;
    }
    printf("%4d %3d %8.1f %7d %7d %10d\n", data[0].year, month, avg, max, min, cnt);
};


void print_year_stat(SENSOR* data, int size, uint16_t year)
{
    float avg = 0;
    int cnt = 0;
    int min = 999;
    int max =-999;
    for(int i=0; i<size; i++){
        if(data[i].year == year){
            avg += data[i].temperature;
            if(data[i].temperature < min)
                min = data[i].temperature;
            if(data[i].temperature > max)
                max = data[i].temperature;
            cnt++;
        }
    }
    if(cnt==0){
        printf("Input data does not contain the specified year %4d\n", year);
        return;
    }
    avg /= cnt;
    
    printf("Year statistic: T_avg = %2.1f degC, T_max = %2d degC, T_min = %2d degC\n", avg, max, min);
};