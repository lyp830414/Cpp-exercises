#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <unistd.h>
#include <string.h>
#include <memory>

#pragma once

using namespace std;

class Sales_data {
	//friend func can place anywhere inside the class, all the same permission.
	friend std::istream &read(std::istream&, Sales_data&);
public:
	//friend func can place anywhere inside the class, all the same permission.
	friend Sales_data add (const Sales_data &, const Sales_data &);

	Sales_data() = default;
	Sales_data(const std::string &s, unsigned n, double p):bookNo(s), units_sold(n), revenue(p*n){}
	
	Sales_data(const std::string &s):bookNo(s){}

	Sales_data(std::istream&);

	std::string isbn() const {return bookNo;}

	Sales_data &combine(const Sales_data&);
	
	double avg_prices() const;

	bool is_same_bn(Sales_data & obj1, Sales_data & obj2) const {return obj1.isbn() == obj2.isbn(); }
private:
	//friend func can place anywhere inside the class, all the same permission.
	friend std::ostream & print(std::ostream&, const Sales_data);
	std::string bookNo;

	unsigned units_sold = 0;

	double revenue = 0.0;

};

Sales_data add(const Sales_data &, const Sales_data &);
std::istream &read(std::istream &, Sales_data&);
std::ostream &print(std::ostream&, const Sales_data);
