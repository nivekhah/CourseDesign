#include "static.h"
#include <iostream>
#include "str_tool.h"

using namespace std;

int init_socket(string ip, int port);

int main() {
    string ip = "120.79.179.172";
}

int init_socket(string ip, int port) {
    data_socket = new my_socket(ip, port);
    return data_socket->now != "ok" ? 1 : 0;
}