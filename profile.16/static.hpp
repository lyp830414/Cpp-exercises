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

	private:
		std::string owner;
		double amount; 
		//for static values-->only "static constexpr" values canbe init in class.
		static constexpr double interestRate = 12; //=12 -wrong: static member cannot init value here.
		static constexpr int test_val = 77;//static constexpr do not need to declare again in head of cc files, but also you can delcare in head of cc if you like.
		int array_test[test_val] = {0}; //ok. can use
		static double initRate(){/*this->cc=19; wrong*/cc=19;/*ok*/ return 1.1;}
		double initRate2(){/*this->cc=19; wrong*/cc=19;/*ok*/ return 1.1;}
};
