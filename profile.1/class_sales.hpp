using namespace std;

class sales_data {
public:	
	
	sales_data();
	~sales_data();
	
	string isbn() const {return booksNo;}// in fact the 'this' pointer is injected, so : return  this->booksBo
	sales_data & combine (const sales_data &);

	double avg_price() const;
	
	
	
	sales_data add (const sales_data &, const sales_data &);
	ostream & print (ostream &, const sales_data &) const;
	istream & read (istream &, sales_data &);
	
private: 
	string booksNo;// This can be compiled ok even it is behind isbn() in the class.
	unsigned int units_sold = 0;
	double revenue = 0.0;
	//Note: 'this' pointer is :  sales_data *const this;
	
	
};



