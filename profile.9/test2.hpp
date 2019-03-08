
template <class T>
class vector_test {
	public:
		vector_test()=default;
		vevtor_test(initializer_list<T> &il);

		vector<int> abc = {1,2,3}; /*initializer_list init*/
		
		virtual iter_list_func()=0;
	private:

		initializer_list<T> lil = {};//NOte: initializer_list always be const values, cannot change and modify. but we can do this : lil = {val1, val2, varialble3}. but they will be const value in the list then.
}


class vec_child : public vector_test<int> {
	public:
		iter_list_func();
	private:

}

