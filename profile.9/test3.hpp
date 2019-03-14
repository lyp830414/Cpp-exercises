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

#pragma once

using namespace std;

class A {
	public:
		A()=default;
		virtual void test(){}
};

class B : public A {
	public:
		B()=default;
};



