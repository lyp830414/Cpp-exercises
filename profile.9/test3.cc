#include "test3.hpp"

int main33(int argc, char *argv[]) {
	A a;
	B b;
	A *pa = &a;
	A *c2f = nullptr;
	A *m = dynamic_cast<A*>(&b);
	B *f2c = nullptr;

	c2f = dynamic_cast<A*>(&b); //child ptr -> father* class pointer
	//Wrong: if father class has no virtual function, following will be failed. Otherwise will be ok.
	f2c = dynamic_cast<B*>(m); //father ptr -> child* class pointer
	cout<<"c2f:"<<(void *)c2f<<", F:"<<(void *)pa<<", f2c:"<<(void*)f2c<<endl;
	
}


class parent
{
public:
int i;
char c;
int j;
virtual void abc(){}
};

class child:public parent
{
public:
int m;
void pp()
{
cout << "hello," << m << endl;
}
};
int main22()
{
parent a;
child  b;
parent *pa = &a;
parent *pb = &b;

child *pcld= dynamic_cast<child*>(&a);
}

class F {
public:
	F()=default;
	virtual void abc(){cout<<"F: abc"<<endl;}
	virtual void abcd(){cout<<"C1: abcd"<<endl;}
	virtual void testthis(){cout<<"F this"<<endl;}
	virtual void hello(){cout<<"hello F"<<endl;}
	void hihi(){cout<<"F hihi"<<endl;}
};

class C1 : public F {
public:
	C1()=default;
	void abc(){cout<<"C1: abc"<<endl;}
	void abcd(){cout<<"C1: abcd"<<endl;}
	void testthis(){cout<<"C1 this"<<endl;}
	void hello(){cout<<"hello C1"<<endl;}
	void hihi(){cout<<"C1 hihi"<<endl;}
};

class C2: public C1 {
public:
	C2()=default;
	void hello(){cout<<"hello c2"<<endl;}
	void testthis(){cout<<"C2 this:"<<sizeof(*this)<<endl;/*for cpn, here is c2 len: 8 */ this->abcd();/*for cpn, here is C3's abc func due to it is virtual func */  this->hihi(); /*for cpn, here is C2 hihi */ cout<<"||||"<<endl;}
	void abc(){cout<<"C2: abc"<<endl;}
	void hihi(){cout<<"C2 hihi"<<endl;}
};

class C3: public C2 {
public:
	C3()=default;
	void testmysize(){cout<<sizeof(*this)<<endl;}	
	void hello(){cout<<"hello C3"<<endl;}
	void abc(){cout<<"C3: abc"<<endl;}
	void hihi(){cout<<"C3 hihi"<<endl;}
private:
	string abcd="ssssssssssssssssssssssssssss";
};

int main() {
	C1 c1;
	C2 c2;
	C3 c3;

	C2 *cp3 = &c3;

	cp3->abc(); //c3 has no abc(), so use c2's virtual function, vptr[0] CHANGES to C2::abc(). otherwise vptr[0] will be c3's abc() if c3 has abc(). vptr table is at very beginning of a class object.
	//F *cp = &c2;
	C1 *cp = &c2;
	//F *cp = dynamic_cast<C1*>(&c2);
	//C1 *cp2 = dynamic_cast<C1*>(&c2);
	cp->abc();
	//cp2->abc();
	//cout<<"cp:"<<(void*)cp<<endl;
	F *cpn = &c3;
	
	cout<<"!!!!!!"<<endl;
	//c2.testthis();
	cpn->testthis();
	c3.testmysize();
	cpn->hihi();
}
