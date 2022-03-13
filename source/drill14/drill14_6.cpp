//drill14

#include <string>
#include <iostream>

using namespace std;

class B1{
	public:
			virtual void vf() {cout << "B1::vf()\n";}
			virtual void pvf()=0;


};

class D1 : public B1{

	public:	
			void vf() override {cout << "D1::vf()\n";}
			void pvf() override  {cout << "D1::pvf()\n";}
			void f() {cout << "D1::f" << endl;}
};

class D2: public D1{

	public:
			void pvf() override {cout<< "D2::pvf" << endl;}	
};


int main(){
	
	

	D1 d1;
	d1.vf();
	d1.pvf();
	d1.f();
	cout << endl;

	D2 d2;
	d2.vf();
	d2.pvf();
	d2.f();
	cout << endl;
	
	return 0;
	


}