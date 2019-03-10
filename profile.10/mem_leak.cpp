#include <unistd.h>
#include <iostream>
#include <string.h>
#include <memory>
#include <string>
//#include <Windows.h>
#include <map>
#include <ctime>
#include <vector>

using namespace std;
#define MAXN 10
class test_ptr
{
public:
map<int,int> *p;
test_ptr()
{
//p = auto_ptr<map<int,int> > (new map<int,int>());
p = new map<int,int>();
for(int i = 0;i<MAXN;i++)
p->insert(make_pair(i,i));
}
~test_ptr()
{
cout<<"DEL P"<<endl;
delete p;
}
};

auto_ptr<test_ptr> g_tmp(new test_ptr());


int main(int argc,char *argv[])
{
for(int i = 0;i<100;i++)
{
//usleep(1000);
//cout << i << endl; 
//test_ptr * tmp = new test_ptr(); -->will not call deconstructor!!!! you must "delete tmp" in each loop. otherwise deconstructor will not be called. also you can use auto_ptr.

// test_ptr abc; ---> will call constructor.
static int cnt = 0;
//auto_ptr<test_ptr> tmp(new test_ptr()); //auto_ptr will call decontructor if ptr is invalid.
//return 0; //ok. here can call deconstructor.
//
cout<<"HERE 1"<<endl;
g_tmp = auto_ptr<test_ptr>(new test_ptr());
cout<<"HERE 2"<<endl;

if(g_tmp.get()) {
	
	cout<<"---->"<<g_tmp.get()<<endl;
} else {

	cout<<"auto_ptr is deleted by itself."<<endl;
}

return 0;

if (cnt < 3) {
	cout<<"CHECK.."<<endl;
}
cnt++;

if (cnt >=3) {
	return 0;
}
}
//system("pause");
return 0;
}
