#include "main.hpp"
#include "test2.hpp"

int testval = 1;
initializer_list<int> g_init_l = {1,test_val,3,4,test_val};

template <class T>
vector_test::vector_test(initializer_list<T> & il) {

	//for auto & v: il {..}
	initializer_list<T>::iterator it; 
	
	lil = il;

	for(it = il.begin(); it != il.end(); it{		
		iter_list_func(it);
	}
}

vec_child::iter_list_func(initializer_list<int>::iterator it) {
	cout<<*it<<endl;

	abc.push_back(*it); //also ok for--> abc = {*it, *it};
}
