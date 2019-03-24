#include "Screen.hpp"

ostream & storeOn(ostream & os, M0 & m0){
	
	vector<int>aa{6, 7};
	vector<int>bb(aa);
	vector<int>cc = bb;

	Screen::pos ht=24, wd=60;

	Screen scr(ht, wd, ' ');

	Screen *p = &scr;

	char c = scr.get();
	
	c = p->get();

	unique_ptr<int> pobj(new int);
	
	//wrong if (ponj->get)
	//ok
	if (pobj.get()) {
		*(pobj.get()) =  12;

		cout<<*(pobj.get())<<endl;
	}

	pobj.reset(new int);
	if (pobj.get()) {
		*(pobj.get()) =  10;

		cout<<*(pobj.get())<<endl;
	}


	return os;
}

M1 & storeOn(M1 & m1, M2 & m2){
	return m1;
}

Windows_mgr2::Windows_mgr2():screens{Screen2(1,2,' ')}{
	hello_mgr();
}

Windows_mgr2::lyp_type Windows_mgr2::hello_mgr(){
	Windows_mgr2::lyp_type abc = 123;
	
	Screen2 tmp_screen(1,2, 'c');

	screens.push_back(tmp_screen);

	cout<<screens.size()<<endl;
	cout<<"PA!"<<endl;
	return abc;
}
int h = 12;
void Windows_mgr2::clear() const {
	//only inside class can use <class name>::value, otherwise only static members can.
	int ccc = ::h * Windows_mgr2::h *w;
	//same to : int ccc = ::h * this->h *w;

	Screen2 Screen_val = screens[0]; 
	/*wrong due to func is const ->Screen_val.pri_val0 = 17;*/
       	//ok due to static and mutable are all canbe changed even func is const.
	Screen_val.pri_val1 = 198; 
	Screen_val.pri_val2 = 19;

	cout<<"clear in Windows_mgr2:"<<Screen_val.pri_val1<<" "<<Screen_val.pri_val2<<endl;
}

void hello(Windows_mgr2 & obj){
	cout<<"hello"<<":"<<(void*)&obj.screens[0]<<endl;
}
		
Screen::pos Screen::size() const {
			return height * width;

}

Type initval() {
	cout<<"global initval"<<endl;
	return 100;
}

Type Excercise::setVal(Type parm) {
	val = parm + initval();
	cout<<"parm:"<<parm<<", initval:"<<initval()<<", val:"<<val<<endl;
	return val;
}
