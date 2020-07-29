#include "date.h"

void date::setYear(int y) {
    year = y;
}

void date::setMonth(int m) {
    month = m;
}

void date::setDay(int d) {
    day = d;
}

int date::getYear() const {
    return year;
}

int date::getMonth() const {
    return month;
}

int date::getDay() const {
    return day;
}

