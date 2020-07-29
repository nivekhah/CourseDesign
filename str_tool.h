#include <string>

using namespace std;

int char_to_int(char *str) {
    int len = strlen(str);
    int ret = 0;
    for (int i = 0; i < len; ++i) {
        ret *= 10;
        ret += str[i] - '0';
    }
    return ret;
}

int str_to_int(const string& str) {
    return char_to_int((char *) str.c_str());
}