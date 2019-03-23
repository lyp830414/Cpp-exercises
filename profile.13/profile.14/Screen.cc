#include "Screen.hpp"

void Window_mgr::clear(ScreenIndex i) {
	Screen & s = screens[i];
	s.contents = string(s.height*s.width, ' ');
}


int main(void) {
	Screen screen;
	TESTCLASS tst(screen);
	M0 m0;
	M1 m1;
	M2 m2;

	m1.test_m(m2);
	TEST_STATIC2 st;

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
	m2.test_m2();
}
