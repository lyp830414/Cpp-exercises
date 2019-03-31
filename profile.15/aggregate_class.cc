#include "aggregate_class.hpp"


Data val1 = {0, "Anna"};
Data val2 = {0}; //则第二成员将为默认初始化，空串。
//Data val2 = {"Anna", 0}; //wrong, sequence is not match to Data declarsion.

//ABC abc = {1, "c"}; //wrong, must use constructor func parameters, but not like struct init.

ABC abc = {}; //ok

//constexpr int getval2(struct Data2 data) {
//	return 12;
//}

int getval(){
	static int mm = 0;
	mm++;
	return mm;
}

//for c++11, constexpr function (not constexpr constructor func) only can take one return ... , and cannot take any other codes. For c++14, can take more code lines in costexpr func.
//sample:
//
//
//// C++11
/*constexpr int factorial(int n)
{
    return n == 0 ? 1 : n * factorial(n - 1);
}*/
// C++14
/*constexpr int factorial2(int n)
{
    int result = 1;
    for (int i = 1; i <= n; ++i)
        result *= i;
    return result;
}*/
//
//
//
constexpr int getvar(int b){
	//wrong: constexpr func can only take one return sentance.
	//
	/*	if(1) return b+3;
		else  return b+2;
	*/

	//ok, only one return
	//return b+2;
	
	//wrong: not a return statement->int z = 2;

	//wrong: not a return statement->z= 3; 
	//wrong: not a return statement->constexpr int z = 3;
	return b+2 == 0? b+3: b-2;
}

constexpr int sz()
{
return 47;
};

constexpr size_t scale(size_t cnt)
{
return sz() * cnt;
}


int main(void) {
	string ss= "aaaaa";
	//wrong: string and its usage cannot be constexpr
	//constexpr int ass = ss.size();
	
	int abccc[ss.size()] = {1,2};//compile ok
	const int abccc2[ss.size()] = {1,2};//compile ok
	constexpr int abccc3[ss.size()] = {12};//compile ok
	//wrong: constexpr cannot set non-constexpr value
	//constexpr int abccc4[ss.size()] = {ss.size()};//compile ok
	constexpr Debug io_sub(false, true, false);
	//wrong: abcccc3 is read-only
	//abccc3[ss.size() - 3] = ss.size();

	//wrong
	//Data2 datav;
	//constexpr Debug newvalue(datav);	
	
	ss = ss + "5";
	const int ccjccj = ss.size(); //compile ok
	//wrong: constexpr cannot use compile unknown value
	//constexpr int ccjccj2 = ss.size(); //compile wrong

	//wrng if Data2 has no construct func.for constexpr, must init all values, like const Data2 datav1 must init, too.
	constexpr Data2 datav1;
	//ok
	constexpr Data2 datav = {1,12};
	
	//wrong: datav is read only.
	//datav.val2 = 15;
	//wrong: datav is read only.
	//datav = {1, 12};
	//constexpr Debug newvalue(datav);

	if(io_sub.any()) {
		cerr<<"Print appropriate error mesaages"<<endl;
	}

	constexpr Debug prod(false);
	if(prod.any()) {
		cerr<<"print an error message"<<endl;
	}
	int test_try = getval();
	int cccm[test_try] = {0};

	for(auto &v : cccm){
		v= 17;
		cout<<v<<endl;
	}
	return 0;
	//wrong, getval() is not constexpr func
	//constexpr int zz = getval();
	
	//ok, getvar is constexpr func
	constexpr int i = getvar(3); //ok
	int j = getvar(i); //ok
	
	constexpr int a = i+5;
	const int b = i + 6;
	const int b2=getvar(b);
	//wrong: a is read-only
	//a += 1;
	
	//wrong for following 2 lines
	//int mm = 2;
	//constexpr int ccc = mm;
	
	//ok for following 2 lines
	constexpr int mm = 2; //or const int mm = 2;
	constexpr int ccc = mm;
	
	int jc = 2;
	const int jccc = j;
	//wrong
	//constexpr int cccll = jccc;
	
	//ok
	constexpr int cccll = i + 5; //ok. i is constexpr.
	int abc[cccll] = {0}; //ok. cccll is constexpr
	int test100;

	int trytest = test100*12 == 0? 123:test100/65;
	int abc2[trytest] = {0};//ok
	test100 = getval();
	int abc3[test100]; //ok
	int valtmp;
	int abc4[scale(valtmp)]; //ok
	int arr1[scale(valtmp)];
	abc[scale(valtmp)] = scale(valtmp);
	abc[b2] = 12;
	const int iloop = 3;

	int arr2[scale(iloop)]; // OK

	//ok-->int jloop = iloop > trytest ? trytest*12: 23;
	int jloop = iloop > abc[3] ? trytest*12+abc[1]: abc[2];
	
	//ok
	string cmm[abc[2]]; //编译期间可以获得
	
	//wrong
	//string cmm[b2]; //运行时才可获得

	//wrong scale(joop) 无法在编译期间知道,但编译通过
	int arr3[scale(jloop)]; //ok
	return 0;
}
