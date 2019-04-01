#include "static.hpp"

//wrong: outside cannot add 'static' for class-static variables
//static int Account::cc;
//ok
int Account::cc;// = 18;

//for constexpr static value, you can not init here or init here, both are ok.
//constexpr double Account::interestRate;

//ok
//double Account::interestRate = Account::initRate();//init step, only static meber in class can use private func.
double Account::dc2 = Account::initRate();

//also ok
//double Account::d2= Account::interestRate; //init step, only static meber in class can use private member or static private func.

//wrong: static member can only call static func, member, initRate2 is not static member func.
//double Account::interestRate = Account::initRate2();//wrong in init step, initRate2 is not a static func member.So private cannot be used.

//wrong: static member can only use static func or static member to init
//double Account::interestRate = Account::getvar();//wrong in init step, initRate2 is not a static func member.So private cannot be used.

//wrong: cc is not Account's static memeber, so use private func wrong
//static double cc = Account::initRate();

/*outside cannot add 'static' from static member of class*/
void Account::rate(double newRate) {
	//interestRate = newRate;
}

int main(int argc, char *argv[]) {
	Account ac1;
	Account *ac2 = &ac1;
	
	Account c9;
	//c9.cc=109;
	//wrong. only static class func can be called
	//double abc = Account::getvar();
	
	cout<<ac1.cc<<endl;
	cout<<Account::cc<<endl;
	

	//wrong
	//Account::interestRate = Account::initRate();//init, only in init step can static private func.
	//wrong
	//ac1.interestRate = Account::initRate();//init, only in init step can use static private func.


	double r;

	r = Account::rate();
	int b = ac1.cc; //ok
	cout<<ac1.cc<<endl;
	r = ac1.rate();//ok
	r= ac2->rate();//ok
	
	ac2->rate(r);
	Account::rate(r);

	cout<<Account::dc2<<endl;
	cout<<Account::test_val<<endl;
	cout<<Account::test_val2<<endl;
	return 0;
}


