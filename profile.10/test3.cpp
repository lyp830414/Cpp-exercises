#include <iostream>
#include <tr1/memory>

using namespace std;

class base{
    public:
        base(){cout<<"base init"<<endl;}
        virtual ~base(){cout<<"base over"<<endl;}
        virtual void show(){cout<<"from base"<<endl;}
};

class derived: public base{
    public:
        derived(){cout<<"derived init"<<endl;}
        ~derived(){cout<<"derived over"<<endl;}
        void show(){cout<<"from derived"<<endl;}
};

int main () {
    tr1::shared_ptr<derived> ptr(new derived());
    tr1::shared_ptr<derived> ptr2(ptr);
    cout<<ptr.get()<<endl;
    cout<<ptr2.get()<<endl;

    class derived *dptr=ptr.get();
    dptr->show();

    return 0;
}
