#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

#include "main.hpp"

//All Wrong: 
//Sales_data::Sales_data(int a, int b):a(1), b(2) {
//Sales_data::Sales_data(int a, int b):a(1), b(2) { 
	//Wrong:  a , b is not class's local variableds -->cout<<"Hello World"<<this->a<<","<<this->b<<endl;

//Can not using '=' both in declarsion and in cpp, but either use '=' all canbe ok-->Sales_data::Sales_data(int a=1, int b=2) {	

//Not allowed, a, b are not inside variables of this class--->Sales_data::Sales_data(int a, int b) : a(1), b(2) {
Sales_data::Sales_data(int a, int b) : cc(1), dd(2) /*ok. allowed, only variables in class canbe init in this place,  a, b is parameter of func, are not class's variable, so cannot be init here */ {	
cout<<a<<","<<b<<endl;
}


//Not allowed. In function body, do not use 'friend' keyword again.
Sales_data & read(istream & is, Sales_data & sobj, A & b) {
	cout<<"read: bookNo units_sold revenue"<<endl;
	is>>sobj.bookNo>>sobj.units_sold>>sobj.revenue;
	b.value = 3;

	cout<<sobj.bookNo<<","<<sobj.units_sold<<","<<sobj.revenue<<endl;
	cout<<b.value<<endl;
}

Sales_data::Sales_data(std::istream &is) {

	//read(is, *this);
}

Sales_data & Sales_data::combine(const Sales_data) {
	return *this;
}

double Sales_data::avg_price() const {
return 0;
}


//NOT allowed
/*Sales_data::Sales_data & operator >> (Sales_data & obj = *this, string book = "", unsigned units_s = 0, double rev = static_cast<double>(book*unit_s)) { */


Sales_data & Sales_data::operator >>(Sales_data & sobj) const {

	sobj = *this;

	//Warning ! must use const cast here--> 'this' is  const * const p, so *this is const value--> so return *this without const_cast is not allowed.	
	return const_cast<Sales_data &>(*this);
}


//no ambigious
void Sales_data::operator >>(int a) const {

	//Convert string to int
	cout<<"Class operator >>int !!!!"<<endl;
	int ba = atoi(bookNo.c_str());
}

//ambigious
/*void Sales_data::operator >>(int a) {

	//Convert string to int
	cout<<"Class operator >>int !!!!"<<endl;
//	int a = atoi(bookNo.c_str());

}*/

void Sales_data::operator>>(const string a) const {

	//Not allowed!!  Func end's const means local variables cannot be changed!!!
	//bookNo = a;
	
	cout<<"Class operator >> string!!"<<endl;
	return;
}

int testfunc(const Sales_data & a) {}
int testfunc2(int a){}
//+++++++++++++OUTSIDE operator++++++++++: only allow to use 1 or 2 parameters

//Not allowed--> operator do not allow to use default values
//
//Sales_data & operator+ (string a = "test", int b=2) {

//Not allowed, outside's operator + only allow to use 1 or 2 parameters.
//Note inside class's operator + , only allow to use 1 parameter.
//Not allowed:
//Sales_data & operator+ (string a, int b, int c) {

//Allowed
Sales_data & operator + (string a) {

 static Sales_data obj;
 return obj;
}

Sales_data & operator + (string a, int b) {
	cout<<"GLOBAL operator [+] !! "<<endl;
	static Sales_data s_sobj{}; //use default constructor as we declareed constructor-> =default;

	s_sobj.teststr = a;
	s_sobj.testno = b;

	return s_sobj;
}

//Not allowed: operator + parameters must have a class or enumerate type
//int operator+(int a, int b) {
string operator+(string a, string b) {
	cout<<"Class operator [+] !!!"<<endl;
	return a+b;
}

//not allowed in calss operator +
//int Sales_data::operator+(int a, int b) {


//Allowed
string Sales_data::operator+(string b) const {
	return b+"test";
}

Sales_data & operator + (Sales_data & sobj, int a) {
	cout<<"Global operator [+] !!!"<<endl;
	sobj.testno += a;
	return sobj;
}

Sales_data & Sales_data::operator + (int a) {
	cout<<"Class operator [+] !!!"<<endl;
	testno += a;
	return *this;
}




//Not allowed: Outside's operator ! only allow to use 1 parameter
//Sales_data & operator ! (string a, int b) {

Sales_data & operator ! (Sales_data & obj) {

	static Sales_data s_sobj{}; //use default constructor as we declareed constructor-> =default;

	s_sobj.teststr = "";
	s_sobj.testno = 2;
	
	cout<<"Global operator [!]"<<endl;
	return s_sobj;
}

//Not allowed: Inside Class's ! operator inside the class, only use void parameter
//void Sales_data::operator!(int ccc) const {

//Allowed
Sales_data & Sales_data::operator ! (void) const {
	static Sales_data s_sobj{};
	cout<<"Class operator [!] "<<endl;
	return s_sobj;
}


//Not allowed: << and >> operator must use 1st param as class or struct
//void operator<<(int a, int b) {

//Not Allowed: for out sise << and >>. only 1 or 2 parameters can be used.
//	       for inside class's << and >> operator extends, only 1 parameter can be used.
//void operator<<(Sales_data obj, int b, int c) {

	
void operator<<(Sales_data obj, int b) {
	return;
}

Sales_data & operator>>(Sales_data & obj, const int c) {

	cout<<"GLOBAL operator >>!!!"<<endl;
	
	return obj;
}

void operator>>(Sales_data obj, string c) {

	cout<<"GLOBAL operator >>!!!"<<endl;
}

//allowed
//void operator<<(Sales_data & obj, int b) {

//Also allowed
//void operator<<(Sales_data obj, int b) {

//	return;
//}






int main(int argc, char *argv[]) {

//	Sales_data abc{};
	Sales_data abc2(9, 10);
//	Sales_data abc3();
	

	//AMBIGIOUS
	//abc2>>"abc";
	
	//global operator >>
	operator>>(abc2, 2);
	
	//global operator >>, same as prev
	cout<<"mmmm"<<endl;
	abc2>>2;
	
	//not allowed, must use operator>>(abc2, 2) or abc.operator>>(2);
	//>>(abc2,2);

	//class operator
	abc2.operator>>(2);
	
	//Not allowed
	 	 //abc2!()
        	//!abc2();
		

	//global operator [!]
	!abc2;

	//class operator[!]
	abc2.operator ! ();
	//Not allowed
		//abc2.operator!;
		//ab2.operator!(abc2);

	cout<<"--------------------- 1"<<endl;
	//none operator func
	auto c = abc2.testno + 1; // No operator func called, because testno is not a class.
	
	cout<<"--------------------- 2"<<endl;
	
	//AMBIGOUS!!!!
	//auto d = abc2 + 1;
	cout<<"--------------------- 3"<<endl;

	//class
	auto d = abc2.operator+(1);
	
	//AMBIGIOUS
	//abc2 = abc2+2;
	
	//class
	//abc2.operator+(2);
	A b;
	//Not allowed
		//read(cin, Sales_data sobj=Sales_data{}, b);
	//Allowed
		//decltype(abc2) sobj;
		Sales_data sobj;
		read(cin, sobj=Sales_data{}, b);
		
	testfunc(Sales_data{});

	//BAD
		//testfunc2(int a = 5);
	//OK
	int a = 9;
	testfunc2(a= 5);
	return 0;
}
