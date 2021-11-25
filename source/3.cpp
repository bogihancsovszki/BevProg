#include "std_lib_facilities.h"

class Date {
    int y, m, d;                    
public:
    Date(int yy, int mm, int dd);  
    void add_day(int n);           
    int month() const { return m; }
    int day() const { return d; }
    int year() const { return y; }
};

Date::Date(int yy, int mm, int dd)

{
    if (dd < 1 || dd > 31) error("init_day: Invalid day");
    if (mm < 1 || mm > 12) error("init_day: Invalid month");

    y = yy;       
    m = mm;
    d = dd;
}

void Date::add_day(int n)

{
    
    int n_d = n % 31;          
    int n_m = (n / 31) % 12;   
    int n_y = n / (31*12);     

    y += n_y;
    m += n_m;
    d += n_d;
     
    
    if (d > 31) { ++m; d -= 31; }     
    if (d < 1)  { --m; d += 31; }     
    
    if (m > 12) { ++y; m -= 12; }     
    if (m < 1)  { --y; m += 12; }     
}

ostream& operator<<(ostream& os, const Date& d)
{
    return os << '(' << d.year()
              << ',' << d.month()
              << ',' << d.day() << ')';
}

int main()
try
{
    Date today{1978, 6, 25};

    Date tomorrow{today};
    tomorrow.add_day(1);

    cout << "Today: " << today << '\n';
    cout << "Tomorrow: " << tomorrow << '\n';

    Date test{2010, 12, 31};

    test.add_day(6);  
    cout << "January the 6th 2011? " << test << '\n';
    test.add_day(-6);  
    cout << "December the 31st 2010? " << test << '\n';

    test = Date{2010, 2, 5};
    test.add_day(-7);   
    cout << "January the 29th 2010? " << test << '\n';
    test.add_day(7);    
    cout << "February the 5th 2010? " << test << '\n';
    test.add_day(3650);  
    cout << "Somewhere circa February 2020? " << test << '\n';
    test.add_day(-3650); 
    cout << "Somewhere circa February 2010? " << test << '\n';

    // Invalid date
    Date today_e{2004, 13, -5};

    return 0;
}
catch(exception& e)
{
    cerr << e.what() << '\n';
    return 1;
}
catch(...)
{
    cerr << "Unknown exception!!\n";
    return 2;
}