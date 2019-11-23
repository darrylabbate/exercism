#include "meetup.h"
#include <string.h>

static int is_leap_year(int year) {
    return !(year % 4) && ((year % 100) || !(year % 400));
}

static int parse_day(const char *day) {
    if      (!strcmp(day, "Sunday"))    return 0;
    else if (!strcmp(day, "Monday"))    return 1;
    else if (!strcmp(day, "Tuesday"))   return 2;
    else if (!strcmp(day, "Wednesday")) return 3;
    else if (!strcmp(day, "Thursday"))  return 4;
    else if (!strcmp(day, "Friday"))    return 5;
    else if (!strcmp(day, "Saturday"))  return 6;
}

static int parse_week(const char *week) {
    if      (!strcmp(week, "first"))  return 0;
    else if (!strcmp(week, "second")) return 1;
    else if (!strcmp(week, "third"))  return 2;
    else if (!strcmp(week, "fourth")) return 3;
    else if (!strcmp(week, "fifth"))  return 4;
    else if (!strcmp(week, "teenth")) return 5;
    else if (!strcmp(week, "last"))   return 6;
}

static int max_days(int m, int y) {
    int days[] = {31, 28 + is_leap_year(y), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return days[m-1];
}

static int offset() {
}

static int calc_day(int y, int m, int d, int i, int j) {
    if ((i > j) || (max_days(m, y) < j)) return 0;
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
    }
}
