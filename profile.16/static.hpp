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
		static double interestRate; //=12 -wrong: static member cannot init value here.
		static double initRate(){/*this->cc=19; wrong*/cc=19;/*ok*/ return 1.1;}
		double initRate2(){/*this->cc=19; wrong*/cc=19;/*ok*/ return 1.1;}
};
