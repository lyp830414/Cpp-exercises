using namespace std;

class Person {
public:
	Person();
	Person(string name, string address);
	~Person(){}
	
	void get_value();

	void set_value(istream &);
	void set_value(string name, string address);
private:
	void print_name(ostream & output ) const { output<<name<<endl; }
	void print_address(ostream & output ) const { output<<address<<endl; }
	
	string name;
	string address;
	
};
