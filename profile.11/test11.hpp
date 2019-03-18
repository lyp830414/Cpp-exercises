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
		int pub_func(void){return 1;}
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
		
		int A::*pa_abc = &A::pub_abc;
		int B::*pb_ccc = &B::prib_ccc;
		
		auto test_ptr() ->void {
			cout<<get_ptr()->*pa_abc<<endl;
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



