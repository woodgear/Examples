#include "stdafx.h"
#include "Plugin.h"
#define Log printf

Plugin::Plugin(std::string data)
{
	this->data = data;
}

void Plugin::eval(const char *msg)
{
	Log("msg is %s and the outer is %s \n", msg,data.c_str());
}


Plugin::~Plugin()
{
}