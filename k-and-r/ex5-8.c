#include <assert.h>
#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

int day_of_year(int year, int month, int day) {
    int i, leap;

    if (month < 1 || month > 12) {
        return 0;
    }

    leap = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);

    if (day < 0 || daytab[leap][month] < day) {
        return 0;
    }

    for (i = 1; i < month; i++) {
        day += daytab[leap][i];
    }
    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday) {
    int i, leap;

    leap = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);

    for (i = 1; yearday > daytab[leap][i] && i < 13; i++) {
        yearday -= daytab[leap][i];
    }

    if (i > 12 || yearday > 31) {
        *pmonth = 0;
        *pday = 0;
    }
    else {
        *pmonth = i;
        *pday = yearday;
    }
}

int main() {
    assert(day_of_year(2000, 3, 1) == 61);
    assert(day_of_year(2001, 3, 1) == 60);

    assert(day_of_year(2001, 2, 29) == 0);
    assert(day_of_year(2001, 13, 29) == 0);

    {
        int month, day;
        month_day(2000, 60, &month, &day);

        assert(month == 2);
        assert(day == 29);
    }

    {
        int month, day;
        month_day(2001, 60, &month, &day);

        assert(month == 3);
        assert(day == 1);
    }

    {
        int month, day;
        month_day(2001, 366, &month, &day);

        assert(month == 0);
        assert(day == 0);
    }

    {
        int month, day;
        month_day(2000, 367, &month, &day);

        assert(month == 0);
        assert(day == 0);
    }

    return 0;
}
