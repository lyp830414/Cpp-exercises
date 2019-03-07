#include "main.hpp"

bool ISSales_data::Read(istream & is, ISSales_data & trans) {
	cout<<"input the book_no  price";
	istream & obj = cin>>trans.bookno>>trans.price;
	cout<<trans.bookno<<trans.price<<endl;
	
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

void ISSales_data::combine(const ISSales_data & trans) {
	total += trans.price;
}

ISSales_data::ISSales_data(istream is):total(0) {	
	cout<<"Construct here!"<<endl;
	if(Read(is, *this)) {
		
		ISSales_data trans{"abc"};
		while (Read(is, trans)) {
			if (this->bookno == trans.bookno) {
				combine(trans);
			} else {
				cout<<"prev total is:"<<total<<endl;
				total = trans;
			}
		}
		Prompt();
	} else {
		EPrompt(NO_INPUT);
	}
}

