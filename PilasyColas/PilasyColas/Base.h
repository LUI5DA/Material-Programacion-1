#pragma once
#include <iostream>
#include <sstream>

using namespace std;
class Base
{
private:
	int id;
public:
	Base(int id) {
		this->id = id;
	}

	virtual int getId() { return id; }
	virtual string toString() {
		stringstream ss;
		ss << "Base: " << id;
		return ss.str();
	}
};

