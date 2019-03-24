#include "Screen.hpp"
#include "Screen2.hpp"
//wrong:  for member static value init, forbid carry 'static'
//static int TEST_STATIC2::aaa = 0; 

//ok
int TEST_STATIC2::aaa; //static member must declare at cpp file beginning(nomather private, public), oterwise cannot be found in codes.
int M0::aaac;
int M0::s_pri_m0;
int Screen2::pri_val1;

//also ok for following

/*int TEST_STATIC2::aaa = 0; //static member must declare at cpp file beginning(nomather private, public), oterwise cannot be found in codes.
int M0::aaac = 0;
int M0::s_pri_m0 = 0;
*/

string abcd(6, 'c'); //-->/*cccccc*/
char *pc = "c12345678";

string def(pc, 6);  //-->/*c12345*/
string def2("pcsssssS:", 6);  //-->/*c12345*/
string def3("pcs:", 6);  //-->/*c12345*/


void Window_mgr::clear(ScreenIndex i) {
	Screen & s = screens[i];
	s.contents = string(s.height*s.width, ' ');
}


int main(void) {
	A a(1);
	A a2(cin); //also A a2(); cin will be the default istream
	cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
	B(cin);
	cout<<"uyuuuuuuuxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
	C c;
	BB bb;
	cout<<"bb vec size:"<<bb.vec.size()<<", vec[1]:"<<bb.vec[0].dd<<endl;
	cout<<"XXXXXuyuuuuuuuxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
	M0 m0_0;
	M1 m1_1;
	M2 m2_2;

	storeOn(cout, m0_0);
	storeOn(m1_1, m2_2);
	
	cout<<"-->............."<<endl;
	Windows_mgr2 mgr2;
	mgr2.mm();
	cout<<"<--............."<<endl;
	Screen screen0;

	mgr2.clear();
	
	cout<<"+++++++++++++++"<<endl;

	Screen screen;
	TESTCLASS tst(screen);
	M0 m0;
	//wrong. private cannot be used in code, even for member-pointer.
	//int M0::*p = &M0::pri_m0;
	
	int M0::*p = &M0::pub_m0; //ok
	//auto p = &M0::pub_m0; //ok
	
	M1 m1;
	M2 m2;


	m1.test_m(m2);


	
	cout<<m0.*p<<endl;
	//equal to: cout<<m0.pub_m0<<endl;
	cout<<"================================"<<endl;
	TEST_STATIC2 st;
	st.testvalue(22);

	Excercise ex;
	cout<<"hi"<<endl;
	cout<<ex.setVal(1)<<endl;
	cout<<"ok"<<endl;
	return 0;
}

inline Screen & Screen::move(pos r, pos c) {
	pos row = r * width;
	cursor = row + c;

	return *this;
}

inline char Screen::get(pos r, pos c) const {
	pos row = r*width;
	return contents[row + c];
}

void Screen::some_member()const {
	access_ctr++;
}

inline Screen & Screen::set(char c) {
	contents[cursor] = c;
	return *this;
}

inline Screen & Screen::set(pos r, pos col, char ch) {
	contents[r*width+col] = ch;
	return *this;
}

//wrong: must return const Screen here--> Screen & Screen::display() const {
const Screen & Screen::display() const {
	cout<<contents[cursor]<<endl;

	return *this; //*this will be const and cannot be changed.
}

void ABC::testabc(){
	Window_mgr mgr;
	//wrong: in Window_mgr screens is private, but screens[0].height is another class' private.so you must let  class ABC be the Screen's friend class.
	//cout<<mgr.screens[0].height<<endl;
	cout<<mgr.screens[0].test_tval<<endl;
	cout<<mgr.ccc<<endl;
}

void M1::test_m(M2 m2){
	cout<<"M1::TEST_M here."<<endl;
	m2.test_m2();
}

