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

string abc(6, 'c'); //-->/*cccccc*/
char *pc = "c12345678";

string def(pc, 6);  //-->/*c12345*/
string def2("pcsssssS:", 6);  //-->/*c12345*/
string def3("pcs:", 6);  //-->/*c12345*/

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

typedef struct {
	int a = 0;
	int b = 0;
	mutable int c = 0;
} ABC;

class Screen {
	public:
		typedef std::string::size_type pos;
		//using pos=std::string:size_type;
		inline void echo(int num) const {
			cout<<contents[num]<<endl;
		}
		Screen()=default;
		~Screen(){}
		Screen(pos ht, pos wd, char c):height(ht), width(wd), contents(ht * wd, c)/*string constructor method 1: "cccccc...(n's)c*/, contents2("cabcdedggg", 6 /*string constructor method 2: differs to string constructor method1, it point to 'c' start string and cut to n values, like "cabcsdd...(end in the n values)"*/), test/*{*/(3,4)/*} also ok for {..}*/ {
			//cout<<::def<<" "<<::def2<<" "<<::def3<<" "<<abc<<endl;
			//cout<<contents<<endl;
			//cout<<contents2<<endl;
			//wrong-->test(6,7);
			//wrong-->test{6,7};
			cout<<"Screen echo test!!1"<<endl;
			test.echo();
			
			abc.a=1;
			abc.b=2;
			abc.c=3;
			
			//wrong due to abc2 is const ==>abc2.a=2;
			//wrong due to abc2 is const ==>abc2.b=2;
			//ok due to abc.c is mutable type, allow change in const or change in const func.
			abc2.c=2;
			test_mutable_func(3);

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
	
	void test_mutable_func(int aa) const{
		int cc = 0;
		change_val ++; /* special: mutable variable change_val canbe changed even in const function */
		cout<<"in const func: mutable change_val is:"<<change_val<<endl;
		aa++;
		cc++;
		cout<<abc2.c<<endl; //mutable type
	}

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
		ABC abc;
		const ABC abc2;
		void do_display(std::ostream &os) const {os<<contents<<endl;}
};

class Window_mgr {
	public:
		Window_mgr * next = nullptr;
		Window_mgr *prev = nullptr;
	private:
		std::vector<Screen> screens{Screen(24, 80, ' ')};

};

class Link_screen {
	Screen Window;
	Link_screen *prev;
	Link_screen *next;
};



class Y;

class X {
	public:
		X()=default;
		X(Y *ptr):py(ptr){}
		Y *py = nullptr;
};

class Y {
	public:
		Y()=default;
		Y(X *ptr): px(ptr){}
		X *px = nullptr;
};
