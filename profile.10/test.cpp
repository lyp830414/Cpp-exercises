#include <iostream>
#include <memory>

using namespace std;
template<class T>
ostream& operator<< (ostream& os,const auto_ptr<T>& p){
    if(p.get() == NULL)
        os<<"NULL";
    else
        os<<*p;
    return os;
}
int main(int  argc,char *argv[]){
    auto_ptr<int> p(new int(42));
    auto_ptr<int> q;

    cout<<"after initialization"<<endl;
    cout<<"p:"<<p<<endl;
    cout<<"q:"<<q<<endl;
    
    q=p;
    cout<<"after assign"<<endl;
    cout<<"p:"<<p<<endl;
    cout<<"q:"<<q<<endl;

    *q += 13;
    p=q;
    cout<<"another assign"<<endl;
    cout<<"p:"<<p<<endl;
    cout<<"q:"<<q<<endl;
    return 0;
}
