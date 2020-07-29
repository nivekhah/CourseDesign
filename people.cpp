#include "people.h"

#include <utility>

void people::set_number(int _v) {
    number = _v;
}

int people::get_number() const {
    return number;
}

void people::set_name(string _v) {
    name = std::move(_v);
}

string people::get_name() const {
    return name;
}

void people::set_age(int _v) {
    age = _v;
}

int people::get_age() const {
    return age;
}

void people::set_sex(int _v) {
    sex = _v;
}

int people::get_sex() const {
    return sex;
}

void people::set_phone(string _v) {
    phone = std::move(_v);
}

string people::get_phone() const {
    return phone;
}

