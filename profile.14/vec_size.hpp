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

class TCASE{
	public:
		TCASE(string) {}
		TCASE(vector<int> cc){}
};

class EXPLICIT_TEST {
	public:
		explicit EXPLICIT_TEST(TCASE) {} //TCASE, 允许被隐式构造，传入string,　你要是传入　const char *　，比如"123"则不可。除非string("123")
};

class EXPLICIT2 {
	public:
		explicit EXPLICIT2(const string &){} //string类，允许隐式构造，允许传入const char *.　构造本对象时要看构造参数的对象是否可以隐式构造，而不是看自己的构造函数是不是带explicit.可以看到参数对象　TCASE允许被隐式构造。只有在当前类作为别人类的构造函数对象时，自己的explicit才管用。
};

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

class VEC {
	public:

	VEC(int){cout<<"VEC constructor"<<endl;}
	virtual ~VEC(){}
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
		explicit K(string){}
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
