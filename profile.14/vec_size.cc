#include "vec_size.hpp"
#include "string"

int main(void) {
	vector<string> vec(10, "2"); //ok, size is 10, 10 * 2
	vector<int> vec100(19, 2); //ok, size is 10, 10 * 1

	for(auto & v :  vec100) {
		cout<<v<<endl;
	}

	J j(cin); //if no explicit on Sales_data, will be ok, otherwise wrong.
	J j2("abc");
	string a = "aaa"; //隐式转换
	K k1("123");  // 隐式转换  ok->construct K(const char*-->string)
	//K k2 = string("def"); //ok,but if with explicit in K, will wrong
	//K k3 = "ddd";//wrong 隐式转换超了1次 const char *-->string ->K(string), 还不到explicit隐式检查 
	//K km(cin with explicit will be wrong, otherwise ok
	//K k2 = "def"; //wrong 隐式转换超过1次了: const char*->string-->K(string)，还不到explicit隐式检查
	//K kms("aaa"); wrong: 同上。
	
	//K k(string("123")); ok, same
	K mm("123"); //ok, same
	
	//if K has no CONSTRUCT K(string), then following are wrong
	
	
	
	//K k(string("aaa")); //ok
	K k(string("cc"));
	//k.combine(123);//有explicit, 所以隐式构造Y对象wrong; otherwise ok
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
