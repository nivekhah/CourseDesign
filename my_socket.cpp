#include "my_socket.h"

my_socket::my_socket(const string& ip, int port) {
    if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        now = "error at creating socket";
    }
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(ip.c_str());
    if (connect(client_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        now = "error at connecting";
    }
    now = "ok";
}

string my_socket::get_msg() {
    net_len = recv(client_socket, input, 199, 0);
    input[net_len] = 0;
    return input;
}

void my_socket::send_msg(string msg) {
    msg += '\n';
    strcpy(output, msg.c_str());
    output[200] = 0;
    send(client_socket, output, strlen(output), 0);
}

void my_socket::close_socket() {
    close(client_socket);
}
