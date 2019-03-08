#include "main.hpp"

constexpr int ivalue = 100;

IOstream::IOstream(string inits) {

	value = inits;
}

IOstream & IOstream::operator<<(IOstream & iosobj) {
	this->value += iosobj.value;
	return *this;
}

IOstream & IOstream::operator>>(IOstream &iosobj) {
	cin>>iosobj.value;
	return *this;
}

void IOstream::set_value(string input) {
	value = input;
}

IOstreamChild::IOstreamChild(string father_input) {
	value = father_input;
}


//bad case: friend and class name not allowed to be marked outside class
//void IOstream::echo_all_values(IOstream &isobj, IOstreamChild &cobj) {

void echo_all_values(IOstream & isobj, IOstreamChild & cobj) {
	cout<<isobj.value<<cobj.value<<endl;
}


void test1() {	
	IOstream *pfobj = new IOstream;
	IOstream *pcobj = new IOstreamChild;
	IOstreamChild *pccobj = new IOstreamChild;

	pfobj->echo_value(); //father echo
	pcobj->echo_value(); //father echo
	
	pccobj->echo_value(); //child echo
	pccobj->IOstream::set_value(string("def"));//father
	pccobj->IOstream::echo_value(); //father echo->def
	pccobj->set_value(string("zzz")); 
	pccobj->IOstream::echo_value(); //father echo->zzz
	pccobj->echo_value(); //child echo
	
	//delete pfobj;
	
	
	//delete pcobj;  //memory leak. only father mem will be free.
	//Wrong: dynamic_cast only allows to let child point convert to fsther pointer ---> delete dynamic_cast<IOstreamChild*>(pcobj);
	delete static_cast<IOstreamChild*>(pcobj); //child desconstruct-->father desconstruct

	
	//delete pccobj;

	return;
}

using FATHER=IOstream;
using CHILD=IOstreamChild;

void test2() {
	//auto_ptr<FATHER> pobj = new FATHER;
	//auto_ptr<CHILD> cobj = new CHILD;
	
	
	return;

}

int &c() {
    int a = 2;
    cout << "a的地址为：" << &a << endl;
    return a;
}

int pointer_test()
{
	int *p;
	p = &c();
	cout << "p的内容为：" << p << endl;  // ADDR NO CHANGE.
	cout << "p指向的内容为："<<hex<<*p << endl; //CRASH HERE==>INFO CHANGED
	return 0;
}


int & ref_test() {
	int a = 22;
	return a;
}

int *& ref_test2() {
	int *p = new int[4];

	return p;
}

void test3() {
	//int b = ref_test(); //value copy
	int & b = ref_test(); //ref value
	//Note: if ref_test() is not & return, then cannot use int & b = ref_test().
	int c = 12;
	cout<<"b:"<<b<<endl; //CRASH HERE,.
}

void test4() {
	cout<<"test4"<<endl;
 	//int * p2 = ref_test2(); //CRASH HERE.
	//cout<<"p2:"<<(void*)p2<<endl;//CRASH HERE
	//cout<<"p2:"<<(void*)ref_test2()<<endl;//CRASH HERE
 	//int * p2 = ref_test2();
	//cout<<"p2:"<<(void*)p2<<endl;//CRASH HERE
}

int main(int argc, char*argv[]) {
	
	ISSales_data test(cin);

	return 0;
	
	A a;
	A b;

	a=b;

	//pointer_test();
	//test3();
	//test4();
	//return 0;

	//test1();
	cout<<"HI"<<endl;
	IOstreamChild abc, abc2(abc); //CHILD be desconstruct first, then fater desconstruct.
	IOstreamChild def = abc;
	


	//cout<<"____"<<endl; //after return , class will be destruct in this main area.
	cout<<"+++++++++++++++++++++"<<endl;
	abc.echo_mem();
	abc2.echo_mem();


	abc.alloc_mem(16);
	//abc.echo_mem(); // addr has value
	//def.echo_mem(); // addr is 0
	
	abc2.alloc_mem(15);
	abc2 = abc; //same addr, because it is operator, not copy constructor!!!!!
	//IOstream abc3(abc);-->ok. allowed use father/child init.
	IOstream abc3(abc); //copy construct, like IOstream abc3=abc;--->different addrs
	//IOstream abc3=abc; //same to prev-line.
	abc.echo_mem();
	
	abc3.echo_mem(); //differs to abc addr

	//WRONG-->for 2 different class types case, need define operator =. 
	//abc2 = abc3;
	abc = abc2; //here not copy construct, just operator =, so same addr

	abc.echo_mem();
	abc2.echo_mem(); //differ addr, due to used copy construct.
	

	return 0;

	IOstream def2 = abc;
	//abc.echo_mem(); 
	//def2.echo_mem(); //same addr to abc
	def2.alloc_mem(16);
	abc.echo_mem();
	def2.echo_mem(); //differs to abc's addr

	cout<<"========================"<<endl;

	return 0;

	abc<<def;
	def.set_value("hihi");
	abc<<def;
	
	echo_all_values(abc, def);
	return 0;
}

