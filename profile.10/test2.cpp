#include <iostream>
#include <memory>

using namespace std;
template<class T>
ostream& operator<< (ostream& os,auto_ptr<T> p){
    if(p.get() == NULL)
        os<<"NULL";
    else
        os<<*p;
    return os;
}
int main(int  argc,char *argv[]){
    auto_ptr<int> p(new int(42));
    //cout<<p<<endl;//also ok.due to we override operator <<. otherwise will be wrong.
    //pk-> if (p.get()) { 
	    //wrong-> if (p) {...}
    //cout<<p<<endl; //this will release p
    cout<<p.get()<<"."<<&p.get()[0]<<"."<<(void**)&p<<endl; //this will not release p. same addr for prev 2, the last is different.
	//}
    if(p.get() == NULL)
        cout<<"after call function, p = NULL"<<endl;
    return 0;
}
