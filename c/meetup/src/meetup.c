#include "meetup.h"
#include <string.h>

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

int meetup_day_of_month(unsigned int  year,
                        unsigned int  month,
                        const char   *week, 
                        const char   *day_of_week) {
    int d = parse_day(day_of_week);
    int w = parse_week(week);
}
