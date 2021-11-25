#include "my.h"
#include "std_lib_facilities.h"

int foo = 7;




void swap_v(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void swap_r(int& a, int& b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

// void swap_cr(const int& a, const int& b)
// {
//      int temp;
//      temp = a;
//      a = b;
//      b = temp;
// }
//nem fut le mivel értéket rendelünk hozzá

 int main ()
{
    print_foo();
    print(99);


    
    int x = 7 ;
    int y = 9 ;
   
    // swap_v(x, y); // Lefordítja, de nem cserél semmit
    //              
    swap_r (x, y);   // fordul és cserél
    // swap_v(7, 9); // Lefordítja, de nem csinál semmit, mint ideiglenes objektumok
   
    // swap_r(7, 9); // Nem fordítható le, mivel a hivatkozást nem sikerült inicializálni
   

    cout << " x most " << x << " , y pedig " << y << " \n " ;

    const  int cx = 7 ;
    const  int cy = 9 ;

    // swap_v(cx, cy); // Lefordítja, de nem cseréli
    // swap_r(cx, cy); //nem fordul


    // swap_v(7.7; 9.9); // Lefordítja, de nem csinál semmit
    // swap_r(7,7; 9,9); // Nem fordítja le.

    cout << " cx most " << cx << " , cy pedig " << cy << " \n " ;

    double dx = 7 ;
    double dy = 9 ;

    // swap_v(dx, dy); // Lefordítja, de nem cseréli
    // swap_r(dx, dy); // nem fordul

    cout << " dx most " << dx << " , dy pedig " << dy << " \n " ;

    return  0 ;
} 
