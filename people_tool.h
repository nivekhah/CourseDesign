#include "static.h"
#include "people.cpp"
#include "str_tool.h"
#include <iostream>
#include <utility>

#define ERR_CONNECT

using namespace std;

int people_num;
people *people_list;

int people_init();
int people_index(const string& info);
int people_index(int number);
people people_new();
int people_append(people p);
int people_upload();

void people_end();

int people_init() {
    data_socket->send_msg("/get-people");
    people_num = str_to_int(data_socket->get_msg());
    people_list = (people *) malloc(people_num * sizeof(people));
    for (int i = 0; i < people_num; ++i) {
        people_list[i].set_number(str_to_int(data_socket->get_msg()));
        people_list[i].set_name(data_socket->get_msg());
        people_list[i].set_age(str_to_int(data_socket->get_msg()));
        people_list[i].set_sex(str_to_int(data_socket->get_msg()));
        people_list[i].set_phone(data_socket->get_msg());
    }
    return 0;
}

void people_end() {
    free(people_list);
}

int people_index(const string& info) {
    for (int i = 0; i < people_num; ++i) {
        if (people_list[i].get_name() == info || people_list[i].get_phone() == info)
            return i;
    }
    return -1;
}

int people_index(int number) {
    for (int i = 0; i < people_num; ++i) {
        if (people_list[i].get_number() == number)
            return i;
    }
    return -1;
}

people people_new() {
    people ret;
    string in;
    cout << "输入会员编号: ";
    cin >> in;
    ret.set_number(str_to_int(in));
    cout << "输入会员名: ";
    cin >> in;
    ret.set_name(in);
    cout << "输入会员年龄: ";
    cin >> in;
    ret.set_age(str_to_int(in));
    cout << "输入会员性别: ";
    cin >> in;
    ret.set_sex(in == "m" ? 1 : 2);
    cout << "输入会员手机号: ";
    cin >> in;
    ret.set_phone(in);
    return ret;
}

int people_append(people p) {
    people_list = (people *) realloc(people_list, sizeof(people) * (people_num + 1));
    people_list[people_num] = std::move(p);
    people_num++;
    return 0;
}

int people_upload() {
    data_socket->send_msg("/upload-people");
    data_socket->send_msg(to_string(people_num));
    for (int i = 0; i < people_num; ++i) {
        people n = people_list[i];
        data_socket->send_msg(to_string(n.get_number()));
        data_socket->send_msg(n.get_name());
        data_socket->send_msg(to_string(n.get_age()));
        data_socket->send_msg(to_string(n.get_sex()));
        data_socket->send_msg(n.get_phone());
    }
    return 0;
}