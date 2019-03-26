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
#include <memory>
#include <vector>
#pragma once

using namespace std;
class Sales_data {
	public:
		Sales_data()=default;
		/*explicit*/ Sales_data(const char *){}
		/*explicit*/ Sales_data(std::istream &){}
};

class J {
	public:
		J(Sales_data){}

};

class M {
	public:
		M(string){}
		M(istream &) {cout<<"cin!!!"<<endl;}
		~M(){}
};
class H {
	public:
		H(M){}
		~H(){}	
};

class A {
public:
	A(int abc){}
	A(string ccc){}
	~A(){};
};

class B {
public:
	//B(const A&){}
	B(const A&){}
	//B(string b):B(3){} //委托构造
};

class Y {
	public:
		explicit Y(int){}
};

class Z {
	public:
		Z(int){}

};
class K {
	public:
		/*explicit*/ K(string){}
		explicit K(M){}
		explicit K(int cc);
		//wrong -> explicit only used in constructors
		// explicit combine(A){}
		void combine(Y) {}
		~K(){}
		K(Z){}
		//wrong-->not construct func, cannot init abc--->void testk():abc(2){}
		int abc;
};

class C {
public:
	C(const A &) {} //ok for C(123);
	C(const B &) {} //ok for A a; C(a);
			//but bad for C(123) -->隐式转换只可转1层，但是2层不支持。
};
