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
};

class C1 : public F {
public:
	C1()=default;
	void abc(){cout<<"C1: abc"<<endl;}
};

class C2: public C1 {
public:
	C2()=default;
	void abc(){cout<<"C2: abc"<<endl;}
};

class C3: public C2 {
public:
	C3()=default();
		
}

int main() {
	C1 c1;
	C2 c2;
	C3 c3;

	C2 *cp3 = &c3;

	c3->abc(); //c3 has no abc(), so use c2's virtual function, vptr[0] CHANGES to C2::abc(). otherwise vptr[0] will be c3's abc() if c3 has abc(). vptr table is at very beginning of a class object.
	//F *cp = &c2;
	C1 *cp = &c2;
	//F *cp = dynamic_cast<C1*>(&c2);
	//C1 *cp2 = dynamic_cast<C1*>(&c2);
	cp->abc();
	//cp2->abc();
	//cout<<"cp:"<<(void*)cp<<endl;
}
