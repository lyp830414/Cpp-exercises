#include <memory>
#include <iostream>
#include "main.hpp"

int main(int argc, char *argv) {
 auto_ptr<int> ap(new int[4]);
 auto_ptr<int> ap2(new int[4]);
 //wrong-->int *p;  ap = p ;  p = ap --> not allowed to convert between normal pointer and intellgent pointer.
 cout<<"a.hello:ap is: "<<ap.get()<<endl;
 ap2 = ap; //we can see, ap free its authority-->ap.release()
  
 cout<<"b.hello:ap is: "<<ap.get()<<endl;

}
