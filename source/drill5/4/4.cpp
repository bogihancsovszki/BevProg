#include "std_lib_facilities.h"

int main()
try {
    
   
    cout << "success" << '\n'; /* cout << success << '\n'; -> a succes string típusu karakter ezért "" be kell írni ->  cout << "success" << '\n';    */


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