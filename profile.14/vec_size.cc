#include "vec_size.hpp"
#include "string"

//wrong: 'explicit' only allows to be appear at class declarsion
/*explicit*/ K::K(int k){
}

int main(void) {
	vector<string> vec(10, "2"); //ok, size is 10, 10 * value 2
	vector<string> vec1{12, "2"}; //ok, size is 12, 12 * value 2
	//wrong  vector<string> vec1{12, 13};
	//wrong  vector<string> vec1{12, "2", "4"}; 
	vector<int> vecA(4,2); /*size: 4, values: 2*/
	//wrong: vector<int> vecA(4,2,3,5); /*size: 4, values: 2*/
	vector<int> vecA2{4,2}; /*size: 2, values: 4, 2*/
	vector<int> vec100(19, 2); //ok, size is 19, 19 * value 2
	vector<int> vec101{19, 2}; //ok, size is 2, value 19 and 2
	//wrong-->vector<int> vec100(19, 2, 3); //wrong, only 2 items: number, value allowed
	
	vector<int> vecInt(10); //size: 10, values: 0
	vector<int> vecInt2{10}; //size: 1, values: 10
	
	cout<<vecInt.size()<<endl;
	
	for (auto & item : vecInt) cout<<item<<endl;
	cout<<"+++++++++++"<<endl;
	cout<<vecInt2.size()<<endl;


	cout<<vecA.size()<<endl;
	cout<<vecA2.size()<<endl;
	cout<<vec.size()<<endl;
	cout<<vec1.size()<<endl;
	cout<<vec100.size()<<endl;
	cout<<vec101.size()<<endl;
	return 0;
	

	for(auto & v :  vec100) {
		cout<<v<<endl;
	}
	
	//wrong: 隐式转换只允许直接初始化，不允许=号拷贝初始化
	//K ks = 123;
	
	K ks(123); //ok
	J j(cin); //if no explicit on Sales_data, will be ok, otherwise wrong.
	J j2("abc");
	string a = "aaa"; //不属于隐式转换，重载了=号操作符
	K k1("123");  // 隐式转换  ok->construct K(const char*-->string)
	//K k2 = "123"; //不允许=号做隐式转换，除非做=号操作符重载
	//K k2 = string("def"); //ok,but if with explicit in K, will wrong
	//K k3 = "ddd";//wrong 不允许等号做隐式转换  隐式1次 const char *-->string ->K(string), 还不到explicit隐式检查 
	//K km(cin with explicit will be wrong, otherwise ok
	//K k2 = "def"; //wrong 不允许等号做隐式转换 隐式转换1次: const char*->string-->K(string)，还不到explicit隐式检查
	//K kms("aaa"); wrong: 同上。
	
	//K k(string("123")); ok, same
	K mm("123"); //ok, same
	
	//if K has no CONSTRUCT K(string), then following are wrong
	
	
	
	//K k(string("aaa")); //ok
	K k(string("cc"));
	//wrong: k.combine(123);//有explicit, 所以隐式构造Y对象wrong; otherwise ok
	//wrong: k.combine("abc"); //wrong: "abc" is const char* -->string, string->Y(string),隐式转换超过1层了
	//H ttt(string("ccc")); //ccc to M
	//wrong H ttta("ccc"); //ccc to M
	H ttt2(M("ccc"));     //M(ccc const char * to string-->M,no way. )
	H ttt(string("ccc")); //ccc to M
	//H ttt3(cin); //ok
	//H ttt4(M(cin)); //ok


	B tet(A(123)); // A(123) is a temp object.
	//B tet(A a(123)); //syntax wrong for param of function.
	//should be B tet(A(123)) or A a(123);B tet(a);
	B tet2(A("abc"));

	C test(B(A(123))); // B (A(123)) --> 1. A obj => B obj(A(123))-->3. C test obj

	cout<<vec.size()<<endl; //len is 10 
	
	vector<string>  vec2{10, "2"}; //10 * "2"
	cout<<vec.size()<<endl; //len is 10 
	
	vector<string>  vec3{10,"2"}; 
	vector<string>  vec4(19); //len is 19

	//wrong: vector<int>     vec3(19, 2);

	cout<<"vec3,size: "<<vec3.size()<<endl;

	string null_book = "9-9999-99";

	B b(123); //ok: 123--->A(123)-->const A&
	A aa(123);
	C c(aa); //ok
	//C d(123); //wrong 隐式转换不能做多层，只能做一层。
	C d(aa); //ok --->隐式转换 -->C d( B(A(123)))
	C d2(B(A(123))); //ok --->隐式转换 -->C d( B(A(123)))


}
