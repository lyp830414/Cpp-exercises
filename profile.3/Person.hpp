using namespace std;

class Person {
public:
	//Person() const;---> error: constructors may not be cv-qualified
	Person();
	Person(string name, string address);// const_val1("const_val1");
	~Person(){}
	
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
	Person3(string name){}
	string value;
private:

	string test;
};
