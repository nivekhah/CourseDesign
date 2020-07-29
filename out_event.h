#include "date.h"

class out_event {
    int book_num;
    int people_num;
    date out;
    date ret;
public:
    void set_book_num(int _v);

    int get_book_num() const;

    void set_people_num(int _v);

    int get_people_num() const;

    void set_out(date _v);

    date get_out() const;

    void set_ret(date _v);

    date get_ret() const;
};
