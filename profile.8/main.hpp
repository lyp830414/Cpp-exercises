#pragma once

using namespace std;

class A;

class Sales_data {
public:
	int testno = 0;
	string teststr = "";
	//Can not using '=' both in declarsion and in cpp, but either use '=' all canbe ok--->Sales_data(int a=1, int b=2);
	//Sales_data(int a, int b):cc(1), dd(2);//Not allowed here, only allowed in body
	
	//Not allowed, default can only use non-parameter---> Sales_data(int a, int b)=default;
	
	/*ok, allowed*/
	Sales_data()=default; 
	/*Note: if you have any constructor, then default constructor func will be missing,  i.e,  if you only provide  Sales_data(int a, int b); --> Then Sales_data() will be missing, so you must define the func Sales_data() to define it in case you need Sales_datea{} or  Sales_data a; ( or using Sales_data()=default to be like default, like this sample) */
	/*NOTE 2:  Sales_data()=default; in here , then  it is inline func, if you decalre it out of class declarsion, like: Sales_data::Sales_data()=default; it will be non-inline function */


	//Sales_data(int a, int b) const --->Not allowed using func's const in any CONSTRUCTOR FUNC

	Sales_data(int a, int b);
	

	Sales_data(const string &s): bookNo(s){
	
	} // same as : Sales_data(const string &s):bookNo(s), units_sold(0), revenue(0) {  }

	Sales_data(string &s, unsigned n, double p): bookNo(s), units_sold{n} /*also ok*/, revenue(p*n/*also ok*/) /*Constructor func's init list */ { 
		
	} 

	Sales_data(std::istream &);


	string isbn() const { return bookNo; } 

	Sales_data & combine (const Sales_data);

	double avg_price() const;


	//Not allowed， in class: only 1 arg can be used-->i.e (Sales_data & sobj);
	//Sales_data & operator>>(Sales_data & obj, int book, unsigned units_s, double rev);

	//Also not allowed as prev case in class.
	//Sales_data & operator>>(const Sales_data& sobj, const istream & is) {
	//	return *this;
	//}

	//Allowed
	Sales_data & operator>>(Sales_data &sobj) const;
	//Also allowed
	void operator>>(const int a) const;
	
	void operator >>(const string a) const;
	Sales_data & operator ! (void) const;
	
	//allowed, BUT CONFLICT TO CLASS INSIDE FUNC Sales_data & operator+(int a);
	//int operator+(int a){}
	
	string operator+(string b) const;
	Sales_data & operator+(int a);
	
	friend Sales_data & read(istream &is, Sales_data &sobj, A & b);	

	//void operator + (int a, int b) const;	
private:
	int cc=0;
	int dd=2;	
	
	string bookNo;
	
	unsigned units_sold = 0;

	double revenue = 0;
};

class A {

	public:
		A()=default;
	
	private:
		int value = 0;	
		friend Sales_data & read(istream & is, Sales_data & sobj, A & b);
};
