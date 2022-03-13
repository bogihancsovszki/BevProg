//drill14

#include <string>
#include <iostream>

using namespace std;

class B1{
	public:
			virtual void vf() {cout << "B1::vf()\n";}
			void f() {cout << "B1::f" << endl;} 


};

class D1 : public B1{

	public:	
			void vf() override {cout << "D1::vf()\n";}
			void f() {cout << "D1::f" << endl;}
};




int main(){
	
	

	B1 b1;
	b1.vf();
	b1.f();
	cout << endl;

	D1 d1;
	d1.vf();
	d1.f();
	cout << endl;

	B1& b1Ref =d1;
	b1Ref.vf();
	b1Ref.f();
	cout << endl;
	
	return 0;
	


}