#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <iostream>
#include <string>
#include "Person.hpp"

Person::Person() {
	this->name = "";
	this->address = "";
}

Person::Person(string name, string address) {
	this->name = name;
	this->address = address;
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
