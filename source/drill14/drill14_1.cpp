//drill14

#include <string>
#include <iostream>

using namespace std;

class B1{
	public:
			virtual void vf() {cout << "B1::vf()\n";}
			void f() {cout << "B1::f()\n";}


};




int main(){
	
	B1 b1;
	b1.vf();
	b1.f();

	
	
	
	


}