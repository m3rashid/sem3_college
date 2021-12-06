#include <stdio.h>
#include <stdlib.h>

int month_check(int m, int y){
    switch(m){
        case 1: return 31;
        case 2: 
            if(y%4 == 0){
                if(y%100 == 0){
                    if(y%400 == 0) return 29;
                    else return 28;
                } else return 29;
            } else return 28;

        case 3: return 31;
        case 4: return 30;
        case 5: return 31;
        case 6: return 30;
        case 7: return 31;
        case 8: return 31;
        case 9: return 30;
        case 10: return 31;
        case 11: return 30;
        case 12: return 31;
    }
}

int year_check(int y){
    if(y%4 == 0){
        if(y%100 == 0){
            if(y%400 == 0) return 366;
            else return 365;
        } else return 366;
    } else return 365;
}

int main(){
    char dates[25]; 
    printf("\nThis program was submitted by MD Rashid Hussain, 20BCS033");
    printf("\nEnter the two dates separated with comma in DD-MM-YYYY,DD-MM-YYYY format: ");
    scanf("%s", dates);

    char date1[11];
    char date2[11];
    for(int i=0; dates[i]!=','; i++){
        date1[i] = dates[i];
        date2[i] = dates[i+11];
    }

    // converting to integer type and extracting the day, month and year
    int d1=0, m1=0, y1=0, d2=0, m2=0, y2=0;
    d1 = (date1[0]-48)*10 + date1[1]-48;
    d2 = (date2[0]-48)*10 + date2[1]-48;

    m1 = (date1[3]-48)*10 + date1[4]-48;
    m2 = (date2[3]-48)*10 + date2[4]-48;
    
    y1 = (date1[6]-48)*1000 + (date1[7]-48)*100 + (date1[8]-48)*10 + date1[9]-48;
    y2 = (date2[6]-48)*1000 + (date2[7]-48)*100 + (date2[8]-48)*10 + date2[9]-48;

    // checks to ensure correct input
    if(d1!=(int)d1 || d2!=(int)d2 || d1<1 || d2<1 || d1>31 || d2>31){
        printf("\nInvalid date entered");
        return 0;
    }
    else if(m1!=(int)m1 || m2!=(int)m2 || m1<1 || m2<1 || m1>12 || m2>12){
        printf("\nInvalid month entered");
        return 0;
    }
    else if(y1!=(int)y1 || y2!=(int)y2 || y1<1 || y2<1 || y1>9999 || y2>9999 || y2<y1){
        printf("\nInvalid year entered");
        return 0;
    }
    else{
        int delta;
        for(int i=y1; i<y2; i++) delta += year_check(i);    // days from currrent year 1 to one before year 2
        for(int i=0; i<m2; i++) delta += month_check(i, y2);
        delta += d2;
        
        // remove the days from first year
        int minus = 0;
        for(int i=0; i<m1; i++) minus += month_check(i, y1);
        minus += d1;
        delta -= minus;
        
        printf("\nThe difference between dates is: %d days", delta-16);
    }

    return 0;
}

