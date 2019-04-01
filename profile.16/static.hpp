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
class Bar {
	public:
		Bar(){cout<<"Bar constructor"<<endl; abc=21;}
		virtual ~Bar(){}
		int abc = 19;
		static Bar mem; //static same member.static独立于类外，所以只会做一次构造，不会死循环。
	private:
		Bar *p_mem;//OK
		//Bar mem2;//wrong　-->本类不能构造本类对象，指针除外，或者static除外
};

class Account {
	public:
		Account()/*:cc(6)-wrong: static member cannot be init except in func body*/{this->cc= 6;/*ok*/}
		void calculate() { this->cc=17; amount += amount * interestRate; }
		//static func in class cannot use 'this->....'
		static const double rate() /*const: wrong: static func cannot be func-end-const */ { 
			/*amount = 12; wrong: static can only use static member from class */

			//ok. cc is static member
			cc = 29; 
			return interestRate; 
		}
		static void rate(double);//{initRate();}
		static int cc;
		double getvar(void){return 1.1;}
		static double dc2;
		
		static constexpr int test_val = 77;//static constexpr do not need to declare again in head of cc files, but also you can delcare in head of cc if you like.
		static const int test_val2 = 78; //ok 

	private:
		std::string owner;
		double amount; 
		//for static values-->only "static constexpr | static const" values canbe init in class. and you can skip declare in head of cc file. Also you can declare again in head of cc file

		static constexpr double interestRate = 12; //=12 -wrong: static member cannot init value here.

		int array_test[test_val] = {0}; //ok. can use
		int array_test2[test_val2] = {0}; //ok. can use
		static double initRate(){/*this->cc=19; wrong*/cc=19;/*ok*/ return 1.1;}
		double initRate2(){/*this->cc=19; wrong*/cc=19;/*ok*/ return 1.1;}
};

class Screen {
	public:
		//ok. can use static part
		Screen():abc(background), abc2(abc){
			//abc = background; -->both init ok.
		}
		//wrong: b=ddm, ddm must be static or const /constexpr
		//Screen & clear(char=background, int b=ddm){}
		//wrong: b=ddm, ddm2 must be static or const /constexpr
		//Screen & clear(char=background, int b=ddm2){}
		//wrong: ddm3 must be static.
		//Screen & clear(char=background, int b=ddm3){}
		
		//ok
		Screen & clear(char=background, int b=ddm3){}
		static /*const*/ char background;
		char abc;
		int ddm = 0;
		const int ddm2 = 2;
		constexpr int ddm3 = 2;
		static int abc;
		constexpr static int dde= 16;
		constexpr static int ddf;
	private:
		char abc2;
};

