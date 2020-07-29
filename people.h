#include <string>

using namespace std;

class people {
    int number;
    string name;
    int age;
    int sex;
    string phone;
public:
    void set_number(int _v);

    int get_number() const;

    void set_name(string _v);

    string get_name() const;

    void set_age(int _v);

    int get_age() const;

    void set_sex(int _v);

    int get_sex() const;

    void set_phone(string _v);

    string get_phone() const;
};