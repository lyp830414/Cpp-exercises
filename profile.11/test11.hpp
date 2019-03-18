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

#pragma once

using namespace std;

class A {
	public:
		A()=default;
		virtual void test(){}
		int pub_abc = 22;
		int pub_func(void){cout<<"a pub func"<<endl;return 1;}
	private:
		int pri_abc = 0;
		int pri_func(void){return 1;}

};

class B {
	public:
		B();
		~B(){}
		int b1 = 10;
		
		auto set_ptr(A * ptra)->void { pa.reset(ptra); }/*pa =move(ptra) will be wrong due to ptra is not a unique_ptr  */
		auto get_ptr()->A* { return pa.get();}

		auto move_ptr(unique_ptr<A> new_ptra)->A* {pa = std::move(new_ptra); return pa.get();}
		
		using A_PRIFUNC = decltype(&A::pub_func);

		int A::*pa_abc = &A::pub_abc;
		int B::*pb_ccc = &B::prib_ccc;

		A_PRIFUNC pa_func1 = &A::pub_func;
		//wrong
		//int A::(*pa_func11)(void) = &A::pub_func;
		
		//ok
		int (A::*pa_func11)(void) = &A::pub_func;
		
		auto test_ptr() ->void {
			cout<<"\n\n=========>=================>"<<endl;
			cout<<get_ptr()->*pa_abc<<endl;
			cout<<get_ptr()->pub_abc<<endl;
			//ok. can also change it.
			get_ptr()->*pa_abc = 55;
			cout<<get_ptr()->*pa_abc<<endl;
			cout<<get_ptr()->pub_abc<<endl;
			cout<<"<=========<=================<\n\n";
			//wrong. do not support this usage.
			//cout<<get_ptr()->&pa_abc<<endl;

			(get_ptr()->*pa_func1)();
			(get_ptr()->*pa_func11)();
			
			cout<<"this->*pb_ccc"<<endl;
			cout<<this->*pb_ccc<<endl;
			this->*pb_ccc = 20;
			cout<<this->*pb_ccc<<endl;
			cout<<this->prib_ccc<<endl;
			this->prib_ccc= 23;
			cout<<this->prib_ccc<<endl;
			cout<<this->*pb_ccc<<endl;
		}
	
	private:
		int prib_ccc = 19;
		using Remove_PtrA = void (*)(A*);
		auto remove_ptr(A* p)->void {
			cout<<"here"<<endl;
			delete p;
		}
		unique_ptr<A> pa;
		

		//unique_ptr<A> pa/*(new A--> not allow in class)*/;
		//unique_ptr<A, Remove_PtrA> pa(-->not allow in class:  new A,remove_ptr);





};



