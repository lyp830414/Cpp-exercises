using namespace std;

class Person {
public:
	//Person() const;---> error: constructors may not be cv-qualified
	Person();
	Person(string name, string address);// const_val1("const_val1");
	~Person(){}
	
	string pubname="33";
private:
	
	string name = "init_name";
	string address = "init_address";
	
	const string const_val1 = "init_const_val1";
	const string const_val2 = "init_const_val2";	
};


class Person2 {
public:
	string name;
private:

	string test;
};

class Person3 {
public:
	Person3(string name){cout<<"HERE person3!"<<endl;}
	string value="newvalue";
	void hello(){cout<<"Hello!"<<endl;}
private:

	string test;
};

class Person4 {

public:
	Person4()= default; //SAME AS THE DEFAULT CONSTRUCTURE---> it is an inline function here
	
	string name;//="init_test_p4";
private:
	string mytest;
};

class Person5 {
public:
	Person5();


};

