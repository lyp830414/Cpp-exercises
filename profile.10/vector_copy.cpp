
#include "vector_copy.hpp"


#pragma once

using namespace std;

auto Vec::echo_addrs() -> void {

	cout<<(void*)a<<endl;
	cout<<(void*)b<<endl;
	//if (p.get()) { 
		cout<<p.get()<<endl;
	//}
	cout<<(void*)p2<<endl;
	//delete p; -->wrong: intellegent pointer do not support delete func, it will gc itself.
}

auto test()->void { 
	//cout<<"Here 1"<<endl;
	//Vec avec; //ok. will deconstructor.
	//Vec *pavec = new Vec; //leak memory this line!!!!
	//
	//cout<<"Here 2"<<endl;
	int a = 0;
	decltype(a) cnt = 0;

	while (cnt < 10)
	{
		auto_ptr<int> pm(new int[4]);
		cout<<"--->"<<pm.get()<<endl; //same addr?
		pm = auto_ptr<int>(new int[2]);

		cout<<"===>"<<pm.get()<<endl; //same addr?
		
		pm = auto_ptr<int>(new int[10]);
		
		cout<<"++++>"<<pm.get()<<endl;
		cout<<"\n\n\n\n"<<endl;
		cnt++;
	}
}

auto Vec::echo_vec() -> void {
	//cout<<(void*)&abc[0]<<endl;
	//cout<<abc[0]<<endl;
	//cout<<(void**)&def[0]<<"."<<(void**)&def[1]<<"."<<(void**)&def[2]<<"."<<endl;
	//cout<<(void*)def[0]<<"."<<(void*)def[1]<<"."<<(void*)def[2]<<endl;
	
	//cout<<def2[0].get()<<"."<<def2[1].get()<<"."<<def2[1].get()<<"."<<endl;
	//cout<<def2[0].get()<<endl;
	//cout<<(void**)&def2[0]<<"."<<(void**)&def2[1]<<"."<<(void**)&def2[2]<<endl;
	if (p.get()) {
		cout<<p.get()[0]<<endl;
	} else {
		cout<<"NULLPTR"<<endl;
	}
}



auto test2() -> void {

	Vec avec;
	avec.p2 = new int[50];

	//avec.echo_addrs();
	//cout<<"+++------+++!!!!!\n\n\n\n\n"<<endl;
	Vec bvec(avec); //here ,if no copy constructor, then avec's auto_ptr p will be released(avec.p = 0 ), then bvec's pointer p takes over it..(bvec.p is valid value)
	
	avec.echo_addrs();
	cout<<"+++------+++"<<endl;
	bvec.echo_addrs();

}

auto test3() ->void {
	Vec avec;
	avec.p.get()[0] = 200;
	Vec bvec(avec);
	
	avec.abc[0]=100;
	//avec.echo_vec();
	//bvec.echo_vec();
	//cout<<"---------------\n\n"<<endl;
	int i = 0;
	for (i= 0; i < 100; i++) {
		avec.abc.push_back(300); //NOte here avec's abc memory addr changes!!!!!
	}
	avec.echo_vec(); 
	bvec.echo_vec();
}

auto test4(initializer_list<int> ltest) -> void {
	/*initializer_list::const_iterator item;
	//for auto & item  ： ltest {
	for (item = ltest.begin(); item != ltest.end(); item++)
		cout<<*item<<endl;
	}*/
}

int main(int argc, char*argv[]) {
	auto_ptr<int> pt(new int[3]);
	auto_ptr<int> pt2(new int[3]);

	pt.get()[0]=10;
	pt.get()[1]=21;
	pt.get()[2]=22;

	pt2 = pt; //pt will be 0(pt.release()), but data and memory will be kepted to pt2.
	auto_ptr<int> & pt3 = pt2; //pt2 and pt3 all keeping, no release,they are same people.
	
	cout<<pt3.get()[0]<<"."<<pt3.get()[1]<<"."<<pt3.get()[2]<<endl;

	//bad-->for (auto &v: pt2.get()) {
		//cout<<v<<endl;
	//}
	return 0;
	//test();
	//test2();
	test3();

 //Vec *pavec = new Vec;



 //Vec bvec(avec);

}
