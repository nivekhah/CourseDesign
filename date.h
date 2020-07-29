class date {
    int year, month, day;
public:
    date(int y, int m, int d) {
        year = y;
        month = m;
        day = d;
    }

    void setYear(int y);

    void setMonth(int m);

    void setDay(int d);

    int getYear() const;

    int getMonth() const;

    int getDay() const;
};