#include "Screen.hpp"

ostream & storeOn(ostream & os, M0 & m0){
	
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
	
}

void Windows_mgr2::clear() const {
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
