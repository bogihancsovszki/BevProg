#include "std_lib_facilities.h"

int main(){

	string first_name;
	 cout << "Enter the name of the person you want to write to" <<"\n";
	 cin >> first_name ;
	 cout << " \t  Dear " << first_name << " ,\n";

	 string valasz;
	 cout << "how are you?" << "\n";
	 cout << "I'm fine thanks. " << "\n";
	 cout << "miss you " << "\n";

	
	 
	 string friend_name;
     cout <<"Enter a friend's name"<<"\n";
	 cin >> friend_name;
	 cout << "Have you seen " + friend_name + " latery? \n"; 

	 char friend_sex=0;
	 cout <<"Enter an m if the friend is male and an f if the friend is female" << "\n";
	 cin >> friend_sex;
	 if(friend_sex=='m')
	 	cout << "if you see "+ friend_name + " please ask him to call me" << "\n";
	 	else if(friend_sex=='f') 
	 		cout << "If you see "+ friend_name + " please ask her to call me" <<"\n";
	 	else
	 		cout << "Incorrect character" <<"\n";


	 cout <<"Enter the age of the recipient " << "\n";
	 int age;
	 cin >> age;
	 cout << "I hear you just had a birthday and you are " << age << "years old"<< "\n";
	 if (age <=0 || age >=110)
	 {
	 	simple_error("you're kidding!");
	 }


	 if (age<12)
	 {
	 	cout << "Next year you will be " << age+1 << ".\n";

	 }
	 else if (age==17)
	 {
	 	cout << "Next year you will be able to vote." << "\n";
	 }
	 else if (age>70)
	 {
	 	cout << "I hope you are enjoying retirement." << "\n";
	 }
	 cout <<"Yours sincerely." << "\n";
	 cout << "\n" << "\n";
	 cout << first_name << "\n";
	return 0;
}
