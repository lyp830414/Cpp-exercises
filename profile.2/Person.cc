#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <iostream>
#include <string>
#include "Person.hpp"

//Person::Person() const { => WRONG:  constructors may not be cv-qualified
	                     // DO NOT ALLOW THE CONSTRUCT FUNC USE 'const' in the construct func
Person::Person() : const_val1("aa"), const_val2("cc"), name(""), address("") {//const value only allowed declare at place here 
	this->name = "";
	this->address = "";
}

Person::Person(string name, string address) : const_val1("aa"), const_val2("cc") { //const value only allowed declare at place here 
	this->name = name;
	this->address = address;
	
	//const_val1 = "const_val1"; //in CONSTRUCT FUNC, const value can be assigned;
	//this->const_val1 = "const_val11111"; //in CONSTRUCT FUNC, const value can be assigned;
	//this->const_val2 = this->name;
	//this->const_val2 = "const_val2222";
}


void Person::get_value() {

	this->print_name(cout);
	this->print_address(cout);
}

void Person::set_value(string name, string address) {

	this->name = name;
	
	//this->print_name(cout);
	//this->print_address(cout);
	this->address = address;

}

void Person::set_value(istream & is) {
	cout<<"input name address:"<<endl;
	is>>this->name>>this->address;
}


int main(int argc, char *argv[]) {
	Person abc1("", "");
	Person abc2("test2", "addr2"); //string is a value, so can use const, inside will be non-const string
	
	abc1.set_value("lyp1", "lypaddr1");
	
	abc1.get_value();
	abc2.get_value();
	return 0;
}
