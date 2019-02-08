#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <iostream>
#include <string>
#include "class_sales.hpp"


sales_data::sales_data(){
}

sales_data::~sales_data() {
}


ostream & sales_data::print(ostream & os /*must use & reference, otherwise compile failed*/, const sales_data & item) const {
	os<<"=====>isbn  units_sold  revenue  avg_price<===="<<endl;
	os<<item.isbn()<<" "<<item.units_sold<<" "<<item.revenue<<" "<<item.avg_price()<<endl;
	
	return os;

}

istream & sales_data::read(istream & is, sales_data &item) {
	double price = 1;
	cout<<"imput: boolsNo units_sold, price"<<endl;
	if(is>>item.booksNo>>item.units_sold>>price) {
		item.revenue = price *item.units_sold;
		return is;
	} else {
		cout<<"BAD CASE"<<endl;
		return is;
	}
}


sales_data & sales_data::combine (const sales_data & trans) {
	this->units_sold += trans.units_sold;
   	this->revenue    += trans.revenue;
	return *this; //Refence should return '*this'
}

double sales_data::avg_price() const {
	if(this->units_sold) {
		return this->revenue / this->units_sold;
	} else {
		return 0;
	}
}

sales_data sales_data::add(const sales_data & obj1, const sales_data & obj2 ) {
	*this = obj1;
	
	this->combine(obj2);
	
	return *this;
}


void WrkProcess(int nsig)  
{  
        printf("WrkProcess .I get signal.%d threadid:%d/n",nsig,pthread_self());  
  
  	
        //while(1){  
                //printf("%d/n",i);  
                //sleep(1);  
                //i++;  
       // }  
}

void set_signals() {

	struct sigaction act,oldact;  
        act.sa_handler  = WrkProcess;  
//      sigaddset(&act.sa_mask,SIGQUIT);  
//      sigaddset(&act.sa_mask,SIGTERM)  
        act.sa_flags = SA_NODEFER | SA_RESETHAND;    
//        act.sa_flags = 0;  
  
        sigaction(SIGTSTP,&act,&oldact/*alaso here can use NULL*/);  
        
	return;  
}


int main(int argc, char *argv[]) {
	
sales_data test_sum;

set_signals();

if(/*0 &&*/ test_sum.read(cin, test_sum)) {
	sales_data trans;
	while(trans.read(cin, trans)) {
		if (test_sum.isbn() == trans.isbn()) {
			test_sum.combine(trans);
		} else {
			test_sum.print(cout, test_sum);
			test_sum = trans;
		}
	}
	cout<<"READ DONE!"<<endl;
	test_sum.print(cout, test_sum);	
}


sales_data test_sum2, test_sum3;
if (test_sum3.read(test_sum2.read(cin, test_sum2), test_sum3)) {
	cout<<"test_sum2 read's result---> test_sum2: "<<endl;
	test_sum2.print(cout, test_sum2);
	cout<<"test_sum23 read's result---> test_sum3: "<<endl;
	test_sum3.print(cout, test_sum3);
	return 0; // In fact, test_sum2 and test_sum3 values are all ok, no issue.

}


cout<<"END PLACE."<<endl;
/*
test1.read(cin, test1);
test1.print(cout, test1);
test2.read(cin, test2);
test2.print(cout, test2);

cout<<"test_sum info:"<<endl;
test_sum.add(test1, test2);
test_sum.print(cout, test_sum);
*/

}
