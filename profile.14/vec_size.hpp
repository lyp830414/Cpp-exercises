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

class T1 {
	public:
		T1()=default;
		T1(const T1 &) = delete;
		~T1(){cout<<"T1 destructor"<<endl;} //not virtual
};

class T2: public T1 {
	public:
	T2()=default;
	~T2(){cout<<"T2 desturctor"<<endl;}
};

class TT1 {
	public:
		TT1()=default;
		virtual ~TT1(){cout<<"TT1 destructor"<<endl;}
};

class TT2: public TT1 {
	public: 
		TT2()=default;
		~TT2(){cout<<"TT2 destructor"<<endl;}
};

class TMP {
	public:
		explicit TMP(int){cout<<"TMP constructor"<<endl;}
		~TMP(){}
};

class TMP2{

	public:
		TMP2(const TMP &) {
			cout<<"TMP2 constructor"<<endl;
		}

		TMP2(const TMP2 &) = delete; /*forbid copy constructor*/
		TMP2 & operator<(const TMP2 &) = delete; /*forbid using operator < */
		int testval = 2;
		
		void echo_val() const {
			cout<<testval<<endl;
		}
};

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
		Y(string){}
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
