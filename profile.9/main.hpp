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
#include <unistd.h>
#include <string.h>

#pragma once

using namespace std;

class IOstream;
class IOstreamChild;


class IOstream {
public:
	IOstream()= default;
	//IOstream(){cout<<"father constructor"<<endl;}
	~IOstream(){cout<<"IOstream desconstructor~!~"<<endl; this->value = "IODES hihi"; cout<<this->value<<endl; delete this->memory_pool;}
	explicit IOstream(string inits); 	
//not allow implicit init
	IOstream & operator<<(IOstream & ios_obj);

	IOstream & operator>>(IOstream & ios_obj);
	void echo_value() {
		cout<<"father echo!!!"<<endl;
		cout<<value<<endl;
	}

	//copy desconstructor
	IOstream(const IOstream & iosobj) {
		/*this->memory_pool=>*/ 
		this->alloc_mem(16);
		if (iosobj.memory_pool != nullptr ) {
			memcpy(this->memory_pool, iosobj.memory_pool, 16);
		}
	}

	//BAD case:  only constructor can use explicit-->explicit void set_value(string inputval);
	void set_value(string inputval);
	void echo_mem() {
		cout<<"H 1"<<endl;
		//BAD--> this will be treated as string, and all following cannot be prompt then---> cout<<memory_pool<<endl;

		cout<<(void *)(this->memory_pool)<<endl;
		cout<<"H 2"<<endl;
	}
	
	char *& alloc_mem(size_t size) {
		if (this->memory_pool == nullptr) {
			this->memory_pool = new char[size];
		}
		return this->memory_pool;	
	}	

friend void echo_all_values(IOstream &iobj, IOstreamChild & cobj);

private:
	string value = "father_val";

	char *memory_pool = nullptr;
};

class IOstreamChild : public IOstream {
public:
	IOstreamChild()=default;
	//IOstreamChild(){cout<<"Child constructor"<<endl;}
	~IOstreamChild(){cout<<"IOstreamChild desconstructor~!~"<<endl; this->value = "IOCHILD DES hihi"; cout<<this->value<<endl;}
	explicit IOstreamChild(string father_input); //explicit only allows one input parameter
	void echo_value() {
		cout<<"child echo!!!"<<endl;
		cout<<value<<endl;
	}

friend void echo_all_values(IOstream &iobj, IOstreamChild & cobj);
	
private:
	string value = "child_val";

};


class A {
public:
	A()=default;
	~A(){};

private:
	int a = 1;
	int b = 5;	
	
};

//-------------------------------------------------------
//
typedef enum {
	NO_INPUT = 1,
	UNKNOWN

} ERROR_NUMBER;

class ISSales_data {
public:
	ISSales_data(istream is);
	//ISSales_data(ISSales_data & obj);
private:
	int total = 0;
	int price = 0;
	int bookno = 0;
	bool Read(istream & is, ISSales_data & trans);
	
	void combine(const ISSales_data & trans);
	void Prompt() const;
	void EPrompt(ERROR_NUMBER) const;
};
