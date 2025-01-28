#include <stdio.h>

int daynumber(int day,int month, int year) {
    static int t[]  ={0,3,2,5,0,3,
                      5,1,4,6,2,4};
    year -=month <3;
    return((year + year /4
        - year/100
        + year/400
        + t[month-1]+day)
        %7);
}

char* getmonthname(int monthnumber) {
    char*month ;
    switch(monthnumber) {
        case 0 :
            month = "Ocak";
        break;
        case 1 :
            month = "Subat";
        break;
        case 2 :
            month = "Mart";
        break;
        case 3 :
            month = "Nisan";
        break;
        case 4 :
            month="Mayis";
        break;
        case 5 :
            month = "Haziran";
        break;
        case 6 :
            month = "Temmuz";
        break;
        case 7 :
            month = "Agustos";
        break;
        case 8 :
            month = "Eylul";
        break;
        case 9 :
            month = "Ekim";
        break;
        case 10:
            month="Kasım";
        break;
        case 11:
            month = "Aralik";
        break;
        default:
            month = "Invalid";
        break;
    }
    return month;
}

int numberofdays(int monthnumber, int year) {
    if (monthnumber == 0)
        return(31);

if (monthnumber ==  1) {
    if (year%400 == 0 || (year % 4 == 0 && year % 100 != 0))
        return(29);
    else
        return (28);
}
if (monthnumber == 2)
    return(31);
    if (monthnumber == 3)
        return(30);
    if (monthnumber == 4)
        return(31);
    if (monthnumber == 5)
        return(30);
    if (monthnumber == 6)
        return(31);
    if (monthnumber == 7)
        return(31);
    if (monthnumber == 8)
        return(30);
    if (monthnumber == 9)
        return(31);
    if (monthnumber == 10)
        return(30);
    if (monthnumber == 11)
        return(31);
}

void printcalendar(int year) {
    printf("Takvim - %d\n\n",year);
    int days;
    int current =  daynumber(1,1,year);
    for (int i = 0; i<12; i++) {
        days=numberofdays(i,year);

        printf("\n------------%s------------\n",getmonthname(i));

        int k;
        for (k=0; k<current; k++)
            printf("    ");
            for (int j =1; j<=days; j++) {
                printf("%5d",j);
                if (++k  > 6) {
                    k=0;
                    printf("\n");
                }
            }
        if (k)
            printf("\n");
        current = k;
    }
    return;
}

int main() {
int year = 2025;
    printcalendar(year);
    return 0;
}

