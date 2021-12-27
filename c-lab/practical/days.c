#include <stdio.h>
#include <stdlib.h>

int DaysInMonth(int month);
int LeapYears(int year, int month);

int main()
{
    printf("\n\nThis program is submitted by MD Rashid Hussain, 20BCS033\n");
    printf("\nEnter The Two inputDate Sepearted By Special Characters: ");
    char inputDate[100];
    scanf(" %[^\n]s", inputDate);
    int len = 0;
    while (inputDate[len] != '\0')
        len++;

    int day[2] = {0}, month[2] = {0}, year[2] = {0};
    int NumDates = 0, i = 0;
    while (NumDates < 2)
    {
        int multi = 10;
        while (inputDate[i] >= '0' && inputDate[i] <= '9')
        {
            day[NumDates] += (inputDate[i] - '0') * multi;
            multi /= 10;
            i++;
        }
        i++;
        multi = 10;
        while (inputDate[i] >= '0' && inputDate[i] <= '9')
        {
            month[NumDates] += (inputDate[i] - '0') * multi;
            multi /= 10;
            i++;
        }
        i++;
        multi = 1000;
        while (inputDate[i] >= '0' && inputDate[i] <= '9' && i < len)
        {
            year[NumDates] += (inputDate[i] - '0') * multi;
            multi /= 10;
            i++;
        }
        i++;
        NumDates++;
    }
    long long DaystillFirst = (long long)year[0] * 365;

    DaystillFirst += DaysInMonth(month[0]);
    DaystillFirst += LeapYears(year[0], month[0]);
    DaystillFirst += day[0];

    long long DaystillSecond = (long long)year[1] * 365;
    DaystillSecond += day[1];
    DaystillSecond += DaysInMonth(month[1]);
    DaystillSecond += LeapYears(year[1], month[1]);

    long long CountDays = abs(DaystillFirst - DaystillSecond) + 1;
    printf("The No Of Days Between Given Dates %lld\n\n\n", CountDays);
    return 0;
}

int LeapYears(int year, int month)
{
    if (month <= 2)
        year--;
    return year / 4 - year / 100 + year / 400;
}

int DaysInMonth(int month)
{
    int MonthDays[12] = {31, 28, 31, 30, 31, 30,
                         31, 31, 30, 31, 30, 31};
    int Days = 0;
    for (int i = 0; i < month - 1; i++)
        Days += MonthDays[i];
    return Days;
}
