#include "static.h"
#include "people.cpp"
#include "str_tool.h"
#include <iostream>
#include <utility>

#define ERR_CONNECT

using namespace std;

int people_num;
people *people_list;

int people_load_cache();
people people_new_command_line();
void people_clean_cache();
people get_from_net();
people get_by_name(string name);
people get_by_number(int number);
people get_by_phone(string phone);
int remove_people(int number);
int add_people(const people& n);
void send_people(const people& n);

int people_load_cache() {
    data_socket->send_msg("/get-people-all");
    people_num = str_to_int(data_socket->get_msg());
    people_list = (people *) malloc(people_num * sizeof(people));
    for (int i = 0; i < people_num; ++i) {
        people_list[i] = get_from_net();
    }
    return 0;
}

people get_from_net() {
    people ret;
    ret.set_number(str_to_int(data_socket->get_msg()));
    ret.set_name(data_socket->get_msg());
    ret.set_age(str_to_int(data_socket->get_msg()));
    ret.set_sex(str_to_int(data_socket->get_msg()));
    ret.set_phone(data_socket->get_msg());
    return ret;
}

void people_clean_cache() {
    free(people_list);
}

#if COMMAND_LINE

people people_new_command_line() {
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

#endif

people get_by_name(string name) {
    data_socket->send_msg("/get-people-name");
    data_socket->send_msg(std::move(name));
    return get_from_net();
}

people get_by_number(int number) {
    data_socket->send_msg("/get-people-number");
    data_socket->send_msg(to_string(number));
    return get_from_net();
}

people get_by_phone(string phone) {
    data_socket->send_msg("/get-people-phone");
    data_socket->send_msg(move(phone));
    return  get_from_net();
}

int remove_people(int number) {
    data_socket->send_msg("/del-people");
    data_socket->send_msg(to_string(number));
    return str_to_int(data_socket->get_msg());
}

void send_people(const people& n) {
    data_socket->send_msg(to_string(n.get_number()));
    data_socket->send_msg(n.get_name());
    data_socket->send_msg(to_string(n.get_age()));
    data_socket->send_msg(to_string(n.get_age()));
    data_socket->send_msg(n.get_phone());
}

int add_people(const people& n) {
    data_socket->send_msg("/add-people");
    send_people(n);
    return str_to_int(data_socket->get_msg());
}