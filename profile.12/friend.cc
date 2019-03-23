#include "friend.hpp"

std::istream &read(std::istream & is, Sales_data & sobj) {
	double price = 0;
	cout<<"input--> bookNo units_sold price"<<endl;
	is>>sobj.bookNo>>sobj.units_sold>>price;
	sobj.revenue = sobj.units_sold * price;
	return is;
}

Sales_data & Sales_data::combine(const Sales_data& obj) {

	units_sold += obj.units_sold;
	revenue    += obj.revenue;
	
	return *this;
}

Sales_data add(const Sales_data & obj1, const Sales_data & obj2) {
	
	Sales_data combine_obj = obj1;

	if (obj1.isbn() != obj2.isbn()) {
		return obj1;
	}
	
	return combine_obj.combine(obj2);
}

std::ostream & print(std::ostream & os, const Sales_data sobj) {
	os<<"total---> isbn units_sold revenue AVG "<<endl;
	os<<sobj.isbn()<<" "<< sobj.units_sold<<" "<<sobj.revenue<<" "<<sobj.avg_prices()<<endl;
	return os;
}

Sales_data::Sales_data(istream & is) {
	double price = 0;
	cout<<"input--> bookNo  units_sold price"<<endl;
	is>>bookNo>>units_sold>>price;
	revenue = units_sold * price;
}


inline double Sales_data::avg_prices() const {

	if (units_sold) {
		return revenue/units_sold;
	}
	
	return 0;
}

int main(int argc, char *argv[]) {

	A a;
	A b(a);
	A c;
	c = a;
	a.a_vec[2] = 100;
	b.a_vec[2]=103;
	a.echo_value();

	b.echo_value();
	c.echo_value();
	
	istream & is = cin;
	ostream & os = cout;
	Sales_data total(is);
	
	//print(os, total);
	
	Sales_data tmpobj{"A"};
	
	while(read(is, tmpobj)) {
		if(tmpobj.is_same_bn(total, tmpobj)) {
			total = add(total, tmpobj);
		} else {
			print(os, total);
			total = tmpobj;
		}
	}

	print(os, total);
}

