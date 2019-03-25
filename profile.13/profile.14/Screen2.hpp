
class A {
public:
	A() = default;
	//Note:
	//in fact, the seq is :  i first init, so i = j, j is 0; then j init, i is 6
	//so i=0, j =6; the init seq is not like following, but obey to declarsion sequences.
	
	//So , for iniitial here of constructor, you'd better do not use member-variables to init them;
	//like: A(int val): i(val), j(val)  or  also  A(int val): j(val), i(val). in fact setting i is earlier than j
	A(int a, string s = ""): j(6), i(j), bookNo(s) {cout<<"i:"<<i<<", j:"<<j<<endl;}
	
	A(string s, unsigned int cnt, double rev):bookNo(s), units_sold(cnt), revenue(rev*cnt){}
	A(istream &is = cin) {}
	
	//wrong-> j is 0 :   A(int ii, int jj):base(i), rem(base%j){}
private:
	int i = 0;
	int j = 0;
	int rem, base;
	string bookNo;
	int units_sold = 0;
	int revenue = 0;
};


//C11 feature: use constructor to be another new constructor function.
//委托构造函数
class B {
	public:
		B (string s, unsigned cnt, double price):bookNo(s), units_sold(cnt), revenue(cnt * price) {cout<<"B basic :"<<endl;}
		B (int a): B("", 0, 0 ){c = 15;cout<<"B(int a): c is:"<<c<<endl;}
		B (string s): B (s, 0, 0){cout<<"B string:"<<endl; c = 15;}
		
		//exec seq is : B basic-->B string--> B istream
		B (istream & is=cin): B("s"){cout<<"B istream: "<<endl; hello_world();}
		
		//wrong: 委托构造函数 only canbe used in init part, cannot be in function body
		// wrong --> B (string ccc): {B(2); hello_world();}
	private:
		void hello_world(){a=1; b=2; c=3;cout<<"hello world!"<<a<<"|"<<b<<"|"<<c<<endl;}
		int a = 9;
		int b = 10;
		int c = 11;
		string bookNo = "k";
		int units_sold = 0;
		int revenue = 0;

};

class C {
	public:
		//here c will be {1,2,3}, d will be {9, 10}
		C():c{1,2,3}, d{9,10}{cout<<d[0]<<"|"<<d[1]<<"|"<<d.size()<<endl;}
	private:
		vector<int> c;
		vector<int> d{2};
};

class NoDefault { 
	public:
		string dd = "rr";
		NoDefault(string &s){cout<<"hi"<<endl;}
};

struct AA {
	//wrong NoDefault my_mem("S");
	string aa = "s";
	NoDefault my_mem{aa};
};

struct BB {
	BB(){}
	string cc = "s";
	NoDefault my_mem{cc};
	//wrong
	//vector<NoDefault> vec(10);
	
	//vector<NoDefault> vec{(10, cc)};
	vector<NoDefault> vec{(10, cc, cc, 10, cc)}; //only the last member-->cc is vec's value. vec.size() is 1, value is cc
	
	//vector<NoDefault> vec{30, cc}; //ok, vec.size() is 30, all values are cc.
	
	//wrong->NoDefault my_mem(); --> a FUNCTION, not member
	//NoDefault my_mem{} --> still wrong. Here we did not provide non-param or default param constructors.
	
	//wrong NoDefault b_member(string("ss"));
	//wrong NoDefault b_member{const_cast<string &>(string("cc"))};

};

