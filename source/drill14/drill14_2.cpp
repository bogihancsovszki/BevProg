//drill14

#include <string>
#include <iostream>

using namespace std;

class B1{
	public:
			virtual void vf() {cout << "B1::vf()\n";}
			void f() {cout << "B1::f()\n";}


};

class D1 : public B1{

	public:	
			virtual void vf() {cout << "D1::vf()\n";}
			void f() {cout << "D1::f()\n";}
};


int main(){
	
	B1 b1;
	b1.vf();
	b1.f();

	D1 d1;
	d1.vf();
	d1.f();

	
	
	return 0;
	


}