#include "vec_size.hpp"
#include "string"

//wrong: 'explicit' only allows to be appear at class declarsion
/*explicit*/ K::K(int k){
}

int main(void) {
	
	T2 *pt2 = new T2; //will call T2 destroctor, then father's
	
	T1 *pt_2 = new T2; // the destructor is real func, so in this case, father pointer will not destructor child's destructor func T2, but only call father destructor T1.
	
	TT2 *ptt2 = new TT2; //child's pointer, call child's destructor, and child call father's destructor
	TT1 *ptt_2 = new TT2; //due to father's destructor is virtual, so the destructor use child's destructor, then in child's destructor, call father's destructor then.

	delete pt2;
	cout<<"---------"<<endl;
	delete pt_2;

	cout << "++++++++++++"<<endl;

	delete ptt2;
	cout<<"---------"<<endl;
	delete ptt_2;
	
	cout<<"+++++++++++++++++++"<<endl;

	T2 t2; // normal object, will destructor child's and child call father desctructor.

	//return 0;


	//TMP2 tmp12(12); //wrong. explicit donot allow convertor.
	TMP2 tmp12(TMP(12)); //ok
	TMP2 tmp2(static_cast<TMP>(12));//ok, static cast allow even explicit convertor; also allow convert if not explicit

	//TMP2 tmp2(TMP(1));
	tmp2.echo_val();

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
	
	vector<VEC> vecT{10}; //ok.
	cout<<vecT.size()<<endl;
	//wrong: vector<VEC> vecVec(10); -->vector<int> vecT(10);ok->10 * value: 0

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
	
	vector<VEC> vecT2{10}; //ok.size is 1，隐式构造
	cout<<"vecT2.size: "<<vecT2.size()<<endl;
	
	//vector<VEC> vecT29(10); //wrong.小括号不支持隐式构造
	
	VEC valTest(10);

	vector<VEC> vecT220{10,valTest}; //ok. size is 2，隐式构造
	cout<<"vecT220.size:"<<vecT220.size()<<endl;
	
	vector<VEC> vecT2202{static_cast<VEC>(10),valTest}; //ok. size is 2.　static_cast隐式构造，static_cast甚至支持explict的构造函数隐转。
	cout<<"vecT2202.size:"<<vecT2202.size()<<endl;
	
	vector<VEC> vecT221(10,valTest); //ok. size is 10, 10*value: valTest
	//vector<VEC> vecT221{10,valTest}; //ok. size is 2, value: 隐式转换对象，以及valTest;
	cout<<"vecT221.size: "<<vecT221.size()<<endl;
	vector<int> vecComp1{10, 2}; //区别：size is 2, 元素: 10, 2.
	cout<<"vecComp1.size: "<<vecComp1.size()<<endl;
	vector<string> vecComp12{10, "2a"}; //区别：size is 10, 元素: 10个"2a".
	cout<<"vecComp12.size: "<<vecComp12.size()<<endl;
	vector<int> vecComp2(10, 2); //区别：size is 10, 10个元素2.
	cout<<"vecComp2.size: "<<vecComp2.size()<<endl;
	vector<int> vecComp3(10); //size: 10
	cout<<"vecComp3.size:"<<vecComp3.size()<<endl;
	vector<int> vecComp4{10}; //size: 1
	cout<<"vecComp4.size: "<<vecComp4.size()<<endl;

	vector<TT1> vecComp5{10}; //size: 10
	cout<<"vecComp5.size: "<<vecComp5.size()<<endl;

	//总结： 
	//       vector<int> abc(10)  //ok, 10个0
	//       vector<int> abc(10, 3) //ok, 10个3
	//       vector<int> abc(10,3,5) //wrong.小括号元素不可以超过２个
	//       vector<classType> abc(10) 不支持隐转，编译出错，必须给初始化值
	//　　　 vector<classType> abc(10, one_class_obj)//ok, 10个one_class_obj
	//       vector<int>  abc{10} // 1个元素: 10
	//       vector<int>  abc{19, 1} //2个元素: 19, 1
	//       vector<string> abc{10}//ok, 10个空串
	//       vector<string> abc{10, "abc"} //ok, 10个"abc"
	//       vector<classType> abc{10}:　分两种情况，如果classType的构造函数包含int，且不是explict的，那么这里abc.size() = 1,采用隐式构造的1个元素 abc(10); 另一种如果classType构造函数不包含int入参，或者是explict的，那么这里 abc.size() = 10, 构造了10个元素
	//       vector<classType> abc{static_cast<classType>(10), one_class_obj} 这种要求classType要有一个int入参的构造函数，哪怕是explicit的，static_cast都可以构造且隐转成classType对象，所以这种abc.size() = 2, 元素为：一个是构造了一个入参是10的classType构造对象，另一个是one_class_obj
	
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
