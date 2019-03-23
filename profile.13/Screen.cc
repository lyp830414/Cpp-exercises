#include "Screen.hpp"
int test(initializer_list<Screen> labc) {
	//for (auto &v : labc) {
	//	cout<<v.abc.c<<endl;
	//}

	return 0;
}

int main(void) {

	//cout<<"HERE"<<endl;
	//Screen abc(1, 2, 'a');
	
	//ok but cannot define using 'test(1,2)' in class-->TEST test1(1,2);

	Screen myscreen(2, 6, 'm');
	Screen myscreen2(2, 6);
	Screen myscreen3(myscreen);
	myscreen3.set(2, 's');
	
	cout<<"------------->"<<endl;
	myscreen.echo(2);
	myscreen3.echo(2);
	cout<<"<-------------"<<endl;




	cout<<"myscreen2 start"<<endl;
	char ch = myscreen2.get();
	cout<<ch<<endl;
	ch = myscreen2.get(0, 1);
	ch = myscreen2.get(1, 9);
	cout<<ch<<endl;
	cout<<"my screen2 end"<<endl;
	
	string abc= "abcdef";

	cout<<abc[87]<<","<<sizeof(abc[87])/*sizeof=1*/<<" "<<sizeof(abc)<<endl; //will not crash, default string length is 32(sizeof), abc.size() is 6(strlen), abc[87 is '' empty .

	const vector<Screen> screens{Screen(24,80,' '), Screen(24,81,' '), Screen(24,82,' '), Screen(24,83,' ')};
	
	//wrong-->test(screens);  initializer_list cannot convert to other container types.
	test(initializer_list<Screen>{Screen(24, 83, ' ')}); //ok
	//wrong->cannot convert: test((initializer_list<Screen>)screens);
	
	cout<<"============================================="<<endl;
	Screen myScreen;
	myScreen.move(1,2).set('h'); /*if move do not return reference of Screen & but just return Screen, then .set('h') won't change myScreen object. --> same as to Screen tmp = myScreen(4,0); tmp.set('h')*/
	myScreen.echo_cursor();
	
	myScreen.move(1,2);
	myScreen.set('h');
	myScreen.echo_cursor();
	
	myScreen.move(4,0);
	myScreen.set('#');
	myScreen.echo_cursor();

	//wrong-->display() const return const *this, cannot be changed
	//myScreen.display().set('h');
	
	//myScreen.display(cout).set('h');

	//myScreen.display(cout).set('h');
	
	Screen mytest1(5,3);
	const Screen mytest2(2,7);

	mytest1/*.set('#')*/.display(cout);
	mytest2.display(cout);

	Screen test6(5,5,'X');
	test6.move(4,0).set('#').display(cout);
	cout<<"\n";

	test6.display(cout);
	cout<<"\n";

	X x;

	Y y;
	
	x.py = &y;
	y.px = &x;

	cout<<(void*)y.px<<" "<<(void*)x.py<<endl;
	cout<<(void*)&x<<" "<<(void*)&y<<endl;
	
	X x2(&y);
	Y y2{&x};
	cout<<(void*)y2.px<<" "<<(void*)x2.py<<endl;
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

