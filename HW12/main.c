#include <stdio.h>
#include <unistd.h>
#include "temp_api.h"

#define ARRAY_SIZE 5
SENSOR records[ARRAY_SIZE] = {
    {2026, 8, 31, 12, 0, 25},
    {2026, 8, 31, 18, 30, 22},
    {2026, 12, 1, 6, 15, -10},
    {2026, 12, 1, 8, 55, -25},
    {2026, 8, 31, 0, 0, 52}
};

int main(int argc, char *argv[]) 
{
    if(argc == 1){
        printf("Enter \"temp_app.exe -h\" to get help\n");
        return 1;
    }
    int rez=0;
    while ( (rez = getopt(argc,argv,"hfm:")) != -1){
        switch(rez){
            case 'h':
                printf("List of arguments:\n\
                     -h to view help\n\
                     -f <CSV file name> to process the file\n\
                     -m <month number> to get statistics for the month\n"); 
                break;
            case 'f': 
                printf("The function is not implemented yet\n"); 
                break;
            case 'm': 
                printf("found argument \"m = %s\"\n", optarg);
                int month;
                sscanf(optarg, "%d", &month);
                int rec_size = sizeof(records)/sizeof(records[0]);
                print_month_stat(records, rec_size, month);
                break;
            case '?': 
                printf("Error found !\n");
                break;
        }
    }
    
    //print_year_stat(records, rec_size, 2026);

    return 0;
}