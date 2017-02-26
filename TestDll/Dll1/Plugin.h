#pragma once
#include <InterFace.h>
#include <memory>
#include <iostream>
class Plugin:public InterFace
{
public:
	Plugin(std::string);
	void eval(const char*);
	~Plugin();
private:
	std::string data;
};

