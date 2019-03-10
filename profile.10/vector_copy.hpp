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

class Vec {
	public:
		Vec()=default;
		auto echo_addrs() -> void;
		auto echo_vec() -> void;
		~Vec(){cout <<"Deconstructor.."<<endl;}
		int *p2 = new int[3];
		
		//explicit Vec(const Vec & obj) {
			//p = auto_ptr<int>(new int[4]);
		//}
		
		vector<int> abc = {1,2,3}; //initializer_list
		vector<int*> def = {new int, new int, new int};
		//wrong-->vector<auto_ptr<int>> def2 = {auto_ptr<int>(new int)};
		//wrong->
		vector<auto_ptr<int>> def22; //= {auto_ptr<int>(new int)};//, auto_ptr<int>(new int), auto_ptr<int>(new int)};

	private:
		int a[10] = {0};
		string b[10] ={""};
		auto_ptr<int> p = auto_ptr<int>(new int[4]);
		
		
};
