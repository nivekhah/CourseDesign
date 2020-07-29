#include <string>
#include "date.h"

#define UNK 0
#define LIB 1
#define OUT 2

using namespace std;

class book {
    int index, age, mode;
    double price;
    string name, author, publish, language;
    date publish_date;
public:
    book();

    void setIndex(int i);

    int getIndex() const;

    void setAge(int a);

    int getAge() const;

    void setMode(int m);

    int getMode() const;

    void setPrice(double p);

    double getPrice() const;

    void setName(string s);

    string getName();

    void setAuthor(string s);

    string getAuthor();

    void setPublish(string s);

    string getPublish();

    void setLanguage(string s);

    string getLanguage();

    void setPublishDate(int y, int m, int d);

    date getPublishDate();
};