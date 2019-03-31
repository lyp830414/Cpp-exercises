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

//聚合类　aggregate class:　all public + no constructor + no ini val + no father + no virtual funcs
struct Data {
	int ival;
	string s; //due to string cannot be constexpr, so this struc is not constexpr struct
}; 

//非聚合类

struct Data2 {
	constexpr Data2(int a, int b):val(a), val2(b)/*, ss("")*/{}
	constexpr Data2():Data2(0, 13){}

	int val;
	int val2;
	//string ss; -->string cannot be constexpr
};

class ABC {
	public:
		ABC()=default;
		ABC(const ABC &) = delete;
		int abc = 1;
		string defg = "";
};

//constexpr 和　字面值常量类
//
//	1. 函数参数和返回值都必须是字面值类型
//	2. 算数类型, 引用，指针　可以做字面值类型
//	3. 字面值常量类:如果类是聚合类，其次必须数据成员都是字面值类型；　如果类不是聚合类，那么必须成员都是字面值类型，且类至少含有一个constexpr构造函数，且类内如果有初始值，该值必须是一个常量表达式;　如果成员是某个类类型，该成员初始值必须使用成员自己的constexpr构造函数，且类必须私用析构函数的默认定义，该成员负责销毁对象。
//	4. 字面值常量类可能含有constexpr函数成员，这些成员都是隐式const的。虽然构造函数不可以是const, 但是字面值常量类的构造函数可以是constexpr
//


//constexpr函数必须初始化所有数据成员，初始值或使用构造函数都是一个常量表达式



//字面值常量类class Debug
//
constexpr bool setting_val(int aval, int bval){
	return aval+bval == 12;
}

bool setting_val2(int aval, int bval){
	return aval+bval == 12;
}

class Debug {
	public:
		//wrong-->constexpr Debug(constexpr Data data):hw(true), io(true), other(false){}
		
		//ok
		constexpr Debug(Data2 data):hw(true), io(true), other(false){}
	//wrong :cannot add 'constexpr' at parameter declarsion
	//constexpr Debug(constexpr Data2 data):hw(true), io(true), other(false){}
		constexpr Debug(bool b=true):hw(b), io(b), other(b) /*constexpr构造函数必须在这里初始化所有的成员，不可以缺省*/{
			//wrong for following codes: constexpr constructor must be empty function body.
			
			//constexpr int c=3;
			//cout<<"1"<<endl;
			//if (true) {
			//b = true;
			//} //else {
				//b = false;
			//}
}
		constexpr Debug(bool h, bool i, bool o=false): hw(h), io(i), other(o) { }
		constexpr Debug(int a, int b):hw(setting_val(a,b)), io(a==0), other(b==2){}
		//wrong for following: init local members for constexpr constructor , must call constexpr, or must give a constexpr expression for each init value !! Here setting_val2 func is not constexpr.
		//constexpr Debug(int a, int b, int c=0):hw(setting_val2(a,b)), io(a==0), other(b==2){}
		constexpr bool any() {return hw || io || other; }
		//For C11:  following 3 funcs cannot be constexpr because cannot only use return syntax, they need do value setting.
		void set_io(bool b) {io = b; }
		void set_hw(bool b) {hw = b; }
		void set_other(bool b){hw = b;}
	private:
		bool hw = false;
		bool io;
		bool other;
};


//通过前置constexpr关键字，就可以声明constexpr构造函数，同时：

//除了声明为=default或者=delete以外，constexpr构造函数的函数体一般为空，使用初始化列表或者其他的constexpr构造函数初始化所有数据成员。

//constexpr声明中如果定义了一个指针，限定符constexpr仅仅对指针有效，与指针所指的对象无关。constexpr把它所定义的对象置为了顶层const。
//constexpr *p = &a; --->p不可变，*p(a的值)可变: *p =16;

//constexpr构造函数
//
//用于构造产生一个constexpr对象以及constexpr函数的参数或返回类型。
//
//
//constexpr函数
//
//c11: constexpr函数有且只有一条return 语句，不允许其他语句出现或多判断return出现。constexpr函数入参和返回值必须都是字面值常量(但C14允许更多语句)

//constexpr int i=20;                          //20是常量表达式

//constexpr int j=i+1;                         //i+1是常量表达式

//constexpr int k=size();                    //当size是个constexpr函数时，才是正确的声明语句
//
//

//   constexpr int i(){return 0;}

//   constexpr int foo=i(); 变量是constexpr,则调用函数返回必须是constexpr



//const VS constexpr区别
//
//const 所定义的变量，一经初始化便不能修改，但是不要求const所定义变量在编译的时候就能被算出。

//constexpr 定义的变量要求，变量在程序被编译的时候就能被判定为常量，否则出错。

//总结来说，constexpr 定义的变量“常量的属性” 比const 所定义的变量更彻底（这是我自己的语言）

//还有知乎上某网友总结：const 就像readonly，constexpr 是一直为常量。
