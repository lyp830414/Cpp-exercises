#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <iostream>
#include <string>
#include "Person.hpp"


Person5::Person5()=default; //Person5() here is not an inline function here


//Person::Person() const { => WRONG:  constructors may not be cv-qualified
	                     // DO NOT ALLOW THE CONSTRUCT FUNC USE 'const' in the construct func
Person::Person() : const_val1("aa"), const_val2("cc"), name(""), address("") {//const value only allowed declare at place here 
	cout<<"HERE 1"<<endl;
	this->name = "";
	this->address = "";

	cout<<"+++  INIT: pubname: "<<pubname<<", const_val1: "<<const_val1<<", const_val2: "<<const_val2<<endl;
}

Person::Person(string name, string address) : const_val1("aa"), const_val2("cc") { //const value only allowed declare at place here 
	cout<<"HERE 2"<<endl;
	this->name = name;
	this->address = address;
	
	cout<<"!!!! INIT: const_val1: "<<const_val1<<", const_val2: "<<const_val2<<endl;
}

//Person abc() {return new Person};


int main(int argc, char *argv[]) {
	
	Person abc1{}; //OK, it will use Person()
	Person abc2("11", "22");//OK
	Person2 abc3{}; //OK, it will use default constructure
	Person4 abc4{}; //OK. it will use default constructure-> Person4()=default;	

	Person abc(); // WRONG, this will not call any constructure, because it is not a class-object, it is a FUNCTION DECLARE, So if you use abc.** will compile wrong!!!
	

	//cout<<person2.name<<endl; -->WRONG
	//cout<<person4.name<<endl; -->WRONG
	return 0;
}
