#include "book.h"

#include <utility>

book::book() : publish_date(0, 0, 0) {
    index = 0;
    age = 9;
    price = 10.00;
    mode = UNK;
    name = "unknown";
    author = "unknown";
    publish = "unknown";
    language = "unknown";
}

void book::setIndex(int i) {
    index = i;
}

int book::getIndex() const {
    return index;
}

void book::setAge(int a) {
    age = a;
}

int book::getAge() const {
    return age;
}

void book::setMode(int m) {
    mode = m;
}

int book::getMode() const {
    return mode;
}

void book::setPrice(double p) {
    price = p;
}

double book::getPrice() const {
    return price;
}

void book::setName(string s) {
    name = move(s);
}

string book::getName() {
    return name;
}

void book::setAuthor(string s) {
    author = move(s);
}

string book::getAuthor() {
    return author;
}

void book::setPublish(string s) {
    publish = move(s);
}

string book::getPublish() {
    return publish;
}

void book::setLanguage(string s) {
    language = move(s);
}

string book::getLanguage() {
    return language;
}

void book::setPublishDate(int y, int m, int d) {
    publish_date = date(y, m, d);
}

date book::getPublishDate() {
    return publish_date;
}


