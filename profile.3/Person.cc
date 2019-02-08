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

	cout<<"INIT: const_val1: "<<const_val1<<", const_val2: "<<const_val2<<endl;
}

Person::Person(string name, string address) : const_val1("aa"), const_val2("cc") { //const value only allowed declare at place here 
	this->name = name;
	this->address = address;
	
	cout<<"INIT: const_val1: "<<const_val1<<", const_val2: "<<const_val2<<endl;
	
	//const_val1 = "const_val1"; //in CONSTRUCT FUNC, const value can be assigned;
	//this->const_val1 = "const_val11111"; //in CONSTRUCT FUNC, const value can be assigned;
	//this->const_val2 = this->name;
	//this->const_val2 = "const_val2222";
}





int main(int argc, char *argv[]) {
	Person abc1("", "");
	Person abc2("test2", "addr2"); //string is a value, so can use const, inside will be non-const string
	Person2 person2(); // Ok, it has default consttucter
	Person3 person3; // Wrong, it has no default constructer
	return 0;
}
