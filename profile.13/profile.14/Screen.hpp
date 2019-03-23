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

//#pragma once
#ifndef _SCREEN_HPP
#define _SCREEN_HPP
using namespace std;

class Window_mgr;

class TEST {
	public:
		TEST()=default;
		TEST(int abc, int def):ccc(abc*def) {
			cout<<"!!!TEST constructor: abc:"<<abc<<", def:"<<def<<endl;
		}
		void echo(void){cout<<ccc<<endl;}
	private:
		int ccc;		

};

class Window_mgr;

class Screen {
		//freind class，note: friend class/ friend functions are NOT this class member!!!
		friend class Window_mgr;
		//friend class ABC;
		//friend void ABC::testabc();
		friend class TESTCLASS;
	public:
		int test_tval = 0;
		typedef std::string::size_type pos;
		//using pos=std::string:size_type;
		inline void echo(int num) const {
			cout<<contents[num]<<endl;
		}
		Screen()=default;
		~Screen(){}
		Screen(pos ht, pos wd, char c):height(ht), width(wd), contents(ht * wd, c)/*string constructor method 1: "cccccc...(n's)c*/, contents2("cabcdedggg", 6 /*string constructor method 2: differs to string constructor method1, it point to 'c' start string and cut to n values, like "cabcsdd...(end in the n values)"*/), test/*{*/(3,4)/*} also ok for {..}*/ {
		}
	Screen(pos ht, pos wd):contents(ht*wd, 'k') {
		//wrong--->contents{ht*wd, ' '};
		
	}

	Screen &set(char);
	Screen &set(pos, pos, char);
	
	inline char get() const {
		return contents[cursor];
	}
	
	char get(pos ht, pos wd) const;
	void set(size_t num, char ch) {
		contents[num] = ch;
	}
	
	Screen & move(pos r, pos c);
	
	void some_member() const;

	void echo_cursor() const {
		cout<<contents[cursor]<<endl;
	}
	const Screen & display() const;
	
	Screen & display (std::ostream & os) {
		cout<<"display non-const"<<endl;
		do_display(os); return *this;
	}
	const Screen & display(std::ostream &os) const {
		cout<<"display const"<<endl;
		do_display(os); return *this;
	}
	
	private:
		pos cursor = 0;
		pos height = 0, width = 0;
		std::string contents;
		std::string contents2;
		//wrong if has no TEST() constructor-->TEST test(1,2);
		//wrong if has no TEST() constructor ->TEST test(1,2); 
		//TEST test1(1,2); wrong. only canbe use outof class
		TEST test{1,2}; //ok, but in fact in construct see constructor func, that time abc, def will be 3, 4 in constructor func, see TEST constructor
	
		mutable int change_val = 0;
		mutable size_t access_ctr = 0;
		void do_display(std::ostream &os) const {os<<contents<<endl;}
};

class DEF {

	public:
		DEF(){cout<<"DEF default constructor"<<endl;};
		DEF(int a, int b) {cout<<"DEF a, b constructor"<<endl;}
};

class TESTCLASS{
	public:
		TESTCLASS()=default;
		TESTCLASS(Screen scr):def(1,2){cout<<scr.height<<"~~~"<<endl;}
		DEF def;
		//wrong-> TESTCLASS is Window_mgr friend class, but cannot access Screen private part, only Window_mgr can access, because Wondow_mgr is Screen friend class. The authority cannot be transferred.
		//wrong: void test() {Screen s; cout<<s.weight<<endl; }

};

class Window_mgr;
class ABC;
/* wrong: Window_mgr in ABC here can only use pointer , otherwise compiler cannot recognzise its variables. So let ABC function body in cpp files then.
*/
class ABC {
	public:
		void testabc();
};

class Window_mgr {
	friend class TESTCLASS;
	friend void ABC::testabc();
	public:
		//using ScreenIndex = std::vector<Screen>::size_type; //ok

		using ScreenIndex = vector<Screen>::size_type; //or vector<int>::size_type, it belongs to vector<...>
		void clear(ScreenIndex);
	private:
		std::vector<Screen> screens{Screen(24, 80, ' ')};
		int ccc = 0;
};

class M0;
class M1;
class M2;

extern ostream & storeOn(ostream &, M0 &);
extern M1 & storeOn(M1 &, M2 &);


class M0 {
	friend ostream & storeOn(ostream &, M0 &);

	public:
		int pub_m0;
		static int s_pub_m0;
		friend class M2;
		void testvalue(int mmm) const {
			int cc = 0;
			cc = 17; //ok. local tmp variable can be changed.
			aaac = 134; //ok. static variable can be changed.
			bbb = 12; //ok. mutable variable can be changed
			//wrong->m0 = 17; except than static and mutable and temp variables, the class variables cannot be changed.
			
			cout<<cc<<" "<<aaac<<" "<<bbb<<endl;
			cout<<"M0 end."<<endl;
		}

		M0(){cout<<"M0 start:"<<endl; this->testvalue(3);}
		/* wrong: only construct func can use class variable inits, like M0(): aaa(2), bbb(16) {....}
		void testvalue(int mmm):aaa(2), bbb(16) {
			
		}*/
		

	private:
		int m0 = 0;
		//static int aaa = 0; -->wrong, if  use init value, must use const static int aaa = 0; otherwise cannot use = *** style for static variable */
		static int aaac; //ok
		mutable int bbb = 0;
		static int s_pri_m0;
};

class M1 {
	friend M1 & storeOn(M1 &, M2 &);
	//wrong: friend void M2::test_m2();
	friend class M2; //ok
	public:
		//int M2::*pri_val_m2 = &M0::m0; //private is also ok for member-pointer.
		M1()=default;
		void test_m(M2 m2);
};

class M2 {
	friend void M1::test_m(M2 m2); //if M1::test_m(M2 m2) is private func, then here will be wrong.

	public:
		M2()=default;
	private:
		void test_m2(){cout<<"hi M2 private"<<endl;M0 m0; cout<<m0.m0<<endl; M1 m1; /*m1.test_m(*this);---> DEAD LOOP!!!!!  M1--> m1-->test_m-->M2 m2-->m2.test_m2()-->again--->always loops*/}
};		
//int pri_val_m2 = 0;

class TEST_STATIC {
	public:
		void test_static() const {a = 17;}
	private:
		static int a;
};

class TEST_STATIC2 {
	friend ostream & storeOn(ostream &, M0 &);
	
	public:
		friend class M2;

		//using PM1_FUNC = decltype(&M1::test_m);
		using PM1_FUNC = void (M1::*)(M2);
		
		PM1_FUNC p_m1_func = &M1::test_m;
		unique_ptr<M1> pm1;


		TEST_STATIC2(){aaa= 1; pm0.reset(new M0); pm1.reset(new M1);M2 m2; (pm1.get()->*p_m1_func)(m2);}
		void testvalue(int mmm) const {
			int cc = 0;
			cc = 17; //ok. local tmp variable can be changed.
			aaa = 134; //ok. static variable can be changed.
			bbb = 12; //ok. mutable variable can be changed
			//wrong->m0 = 17; except than static and mutable and temp variables, the class variables cannot be changed.
			
			cout<<cc<<" "<<aaa<<" "<<bbb<<endl;
			cout<<"TEST_STATIC end."<<endl;

			if(pm0.get()) {
				cout<<pm0.get()->*m0_ptr<<endl;
			}
		}

		//TEST_STATIC2(){cout<<"TEST_STATIC start:"<<endl; this->testvalue(3);}
		/* wrong: only construct func can use class variable inits, like M0(): aaa(2), bbb(16) {....}
		void testvalue(int mmm):aaa(2), bbb(16) {
			
		}*/
		

	private:
		int M0::*m0_ptr = &M0::pub_m0;
		unique_ptr<M0> pm0 = nullptr; 
		int m0 = 0;
		//static int aaa = 0; --> wrong, if  use init value, must use const static int aaa = 0; otherwise cannot use = *** style for static variable */
		//static int aaa; -->if function used it, then in link stage will be wrong if function() const  is used. 
		static int aaa; //static must be initialized in the very beginning of cc files, no mater it is private or static
		mutable int bbb = 0;
};

class Screen2;

class Windows_mgr2 {
	public:
		void clear() const;
		Windows_mgr2();
	private:
		vector<Screen2> screens;

};

class Screen2 {
	friend void Windows_mgr2::clear() const;
	public:
		Screen2(vector<Screen2>::size_type ht, vector<Screen2>::size_type wd, char c){
			pri_val1 = 0;
		}
		
	private:
		int pri_val_0 = 1;
		static int pri_val1;
		mutable int pri_val2 = 17;
};

#endif
