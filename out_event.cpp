#include "out_event.h"

void out_event::set_book_num(int _v) {
    book_num = _v;
}

int out_event::get_book_num() const {
    return book_num;
}

void out_event::set_people_num(int _v) {
    people_num = _v;
}

int out_event::get_people_num() const {
    return people_num;
}

void out_event::set_out(date _v) {
    out = _v;
}

date out_event::get_out() const {
    return out;
}

void out_event::set_ret(date _v) {
    ret = _v;
}

date out_event::get_ret() const {
    return ret;
}

