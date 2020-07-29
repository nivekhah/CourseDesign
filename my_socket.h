#include <netinet/in.h>
#include <arpa/inet.h>
#include <string>
#include <cstdlib>
#include <unistd.h>

using namespace std;

class my_socket {
    int client_socket;
    struct sockaddr_in server_addr{};
    char output[201]{};
    char input[201]{};
    int net_len{};
public:
    string now;
    my_socket(const string& ip, int port);
    string get_msg();
    void send_msg(string msg);
    void close_socket();
};