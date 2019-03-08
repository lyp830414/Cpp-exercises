#include "main.hpp"

bool ISSales_data::Read(istream & is, ISSales_data & trans) {
	cout<<"input the book_no  price";
	istream & obj = cin>>trans.bookno>>trans.price;
	cout<<trans.bookno<<trans.price<<endl;
	total = this->price;
	cout<<"this->bookno: "<<this->bookno<<", price: "<<this->price<<", total: "<<this->total<<endl;
	return obj? true: false;
}


void ISSales_data::Prompt() const {
	cout<<"my total is:"<<this->total<<endl;
}

void ISSales_data::EPrompt(ERROR_NUMBER) const {
	cout<<"Error: ";
	switch(bookno) {
		case NO_INPUT:
			cout<<"NO INPUT"<<endl;
		break;
		default:
		break;
	}

	return;
}

void ISSales_data::combine(int new_price) {
	cout<<"combine!!!!!"<<endl;
	total += new_price;
	cout<<"combine:"<<new_price<<", total: "<<total<<endl;
}

/* ---> endless loop HERE */
/* ISSales_data::ISSales_data(istream & is):total(0) {
	cout<<"Construct here!"<<endl;
	if(Read(is, *this)) {
		
		ISSales_data trans(std::cin); -->endless loop constructor,,,
		while (Read(is, trans)) {
			if (this->bookno == trans.bookno) {
				combine(trans);
			} else {
				cout<<"prev total is:"<<total<<endl;
				total = trans.price;
			}
		}
		Prompt();
	} else {
		EPrompt(NO_INPUT);
	}
}
*/

ISSales_data::ISSales_data(istream &is):l_prices({bookno, price}) {
	if(Read(is, *this)) {
		while(true) {
			cout<<"Input bookno price";
			int new_bookno = 0;
		        int new_price = 0;

			if (!(cin>>new_bookno>>new_price)) {
				break;
			}

			l_prices = {new_bookno, new_price};
			
			if (this->bookno == new_bookno) {
				cout<<"call comnbine."<<endl;
				combine(new_price);
			} else {
				cout<<"sum: bookno: "<<this->bookno<<", total price: "<<total<<endl;
				this->bookno = new_bookno;
				total = new_price;
			}
			
			//int new_bookno = 0;
			//cout<<"Input your price LIST";
			/*wrong--->if (!cin>>l_prices) {
				      break;
			}*/
			//cout<<endl;
		        //initializer_list<int>::const_iterator it;
	
			//wrong-->cout<<l_prices<<endl;
		
		
		/*	
		 *	for (it = l_prices.begin(); it != l_prices.end(); it++)
			{

			cout<<" | input:"<<*it<<", size:"<<l_prices.size();
			}
			cout<<endl;
			*/

		}
		cout<<"DONE"<<endl;
		cout<<"sum2: bookno: "<<this->bookno<<", total: "<<this->total<<endl;
	} else {
		cout<<"NO DATA!"<<endl;
	}	

//	for auto & it := l_prices {
/*	for ( initializer_list<int>::const_iterator it = l_prices.begin(); it != end; it ++ ) {
		cout<<*it<<endl;
	}

	cout<<l_prices.size()<<endl;
*/
}

void test() {

	ISSales_data trans(cin);
}
