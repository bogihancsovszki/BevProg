
#include "std_lib_facilities.h"

int main()
try {
    

    
    int ab = 4;
    double d =   5.0/ ab + 2.0;
    if (d==2*ab+0.5) 
        cout << "Success!\n";



    keep_window_open();
    return 0;
}
catch (exception& e) {
    cerr << "error: " << e.what() << '\n';
    keep_window_open();
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n";
    keep_window_open();
    return 2;
}
