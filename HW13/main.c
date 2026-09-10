#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "temp_api.h"

int main(int argc, char *argv[]) 
{
    if(argc == 1){
        printf("Enter \"temp_app.exe -h\" to get help\n");
        return 1;
    }

    int month = 0;
    char f_name[100]="";

    int rez;
    while ( (rez = getopt(argc,argv,"hf:m:")) != -1){
        switch(rez){
            case 'h':
                printf("List of arguments:\n\
                     -h to view help\n\
                     -f <CSV file name> to process the file\n\
                     -m <month number> to get statistics for the month\n"); 
                break;
            case 'f': 
                strncpy(f_name, optarg, sizeof(f_name)-1);
                f_name[sizeof(f_name)-1] = '\0';
                break;
            case 'm': 
                sscanf(optarg, "%d", &month);
                break;
            case '?': 
                printf("Error found !\n");
                break;
        }
    }

    if(strlen(f_name)!=0)
    {
        int cnt_data;
        //char *filename = "temp_big.csv";
        SENSOR *data = read_data(f_name, &cnt_data);

        if(data == NULL)
            return 1;

        //printf("Year Month MonthAvg MonthMax MonthMin NumMeas\n");
        print_month_stat(data, cnt_data, month);

        if(month==0)
            print_year_stat(data, cnt_data, data[0].year);

        free(data);
    }

    return 0;
}