#include "test3.hpp"

int main(int argc, char *argv[]) {
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
