#include "test11.hpp"

int test(int argc, initializer_list<int> listInt) {

return 0;
}

auto remove_ptr(B* p)->void {
	cout<<"here"<<endl;
	delete p;
	
}

using Remove_Ptr = void (*)(B*);

B::B(){
	set_ptr(new A);
	cout<<"OK:"<<get_ptr()<<endl;
}

int main(int argc, char *argv[]) {
while(true) {
	B b, *pbobj = &b;
	A a, *paobj = &a;

	//delete &b; -->crash due to b is not in heap.
	//return 0;
	//
	
	//following 2 lines will both crash after main finished due to delete or std::default_delete happens.
	//unique_ptr<B, Remove_Ptr> pb(&b, remove_ptr);
	//unique_ptr<B> pb(&b);
	
	

	//cout<<b.b1<<endl;

	//wrong for following 2 lines: .*  or ->* only allows the member's owner class access it, but not the class who own this member-pointer.
	//cout<<b.a.*p<<endl;
	//cout<<pbobj->a.*p<<endl;

	//wrong
	//cout<<a.*p<<endl;
	//cout<<paobj->*p<<endl;
	
	
	
	//ok
	int A::*p2 = &A::pub_abc;
	cout<<a.*p2<<endl;
	cout<<paobj->*p2<<endl;
	

	//leads crash this line. do not use local variable for unique_ptr or other intellegent ptr. auto-free(or you declare the delete func with delete p) will be crashed.
	//b.set_ptr(&a);
	//
	b.set_ptr(new A);

	cout<<b.get_ptr()->pub_abc<<endl; //same as a.pub_abc;
	/*Following lineL: ->*pa_abc only can be inside class B's func, and in B to call
	following line, otherwise *pa_abc cannot be recognized outside class B functions. */
	//cout<<(b.get_ptr()->*pa_abc)<<endl; //same as a.pub_abc;
	cout<<b.get_ptr()->*p2<<endl; //same as a.pub_abc;
	
	//wrong. only use it in class, otherwise you must declare pb_ccc outside of the class.
	//cout<<b.*pb_ccc<<endl;

	//ok
	b.test_ptr();
	
	//wrong: private here
	//int A::*p3 = &A::pri_abc;
	

	cout<<"Done."<<endl;
	break;
}
	return 0;
}
