#include "meetup.h"
#include <string.h>

static int parse_day(const char *day) {
    if      (!strcmp(day, "Saturday"))  return 0;
    else if (!strcmp(day, "Sunday"))    return 1;
    else if (!strcmp(day, "Monday"))    return 2;
    else if (!strcmp(day, "Tuesday"))   return 3;
    else if (!strcmp(day, "Wednesday")) return 4;
    else if (!strcmp(day, "Thursday"))  return 5;
    else if (!strcmp(day, "Friday"))    return 6;
    else return -1;
}

static int parse_week(const char *week) {
    if      (!strcmp(week, "first"))  return 0;
    else if (!strcmp(week, "second")) return 1;
    else if (!strcmp(week, "third"))  return 2;
    else if (!strcmp(week, "fourth")) return 3;
    else if (!strcmp(week, "fifth"))  return 4;
    else if (!strcmp(week, "teenth")) return 5;
    else if (!strcmp(week, "last"))   return 6;
    else return -1;
}

static int max_days(int m, int y) {
    int l      = !(y % 4) && ((y % 100) || !(y % 400));
    int feb    = 28 + l;
    int days[] = {31, feb, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return days[m - 1];
}

static int zeller(int y, int m, int h, int q) {
    return h == (q + ((13 * (m+1)) / 5) + y + (y/4) - (y/100) + (y/400)) % 7;
}

static int calc_day(int y, int m, int d, int i, int j) {
    if (m < 3) { 
        m += 12;
        y -= 1;
    }
    for (; i <= j; i++)
        if (zeller(y, m, d, i)) return i;
    return 0;
}

int meetup_day_of_month(unsigned int  year,
                        unsigned int  month,
                        const char   *week, 
                        const char   *day_of_week) {
    int day = parse_day(day_of_week);
    int w   = parse_week(week);
    int max = max_days(month, year);

    switch (w) {
    case 0: return calc_day(year, month, day, 1, 7);
    case 1: return calc_day(year, month, day, 8, 14);
    case 2: return calc_day(year, month, day, 15, 21);
    case 3: return calc_day(year, month, day, 22, 28);
    case 4: return calc_day(year, month, day, 29, max);
    case 5: return calc_day(year, month, day, 13, 19);
    case 6: return calc_day(year, month, day, max-6, max);
    default: return 0;
    }
}
