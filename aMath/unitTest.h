#pragma once

#include <cassert>
#include <string>
#include <iostream>

template <typename T>
void TEST(std::string test, T val1, T val2)
{
	if (val1 == val2)
	{
		std::cout << test << ": passed" << std::endl;
	}
	else {
		std::cout << test << ": failed" << std::endl;
	}
	assert(val1 == val2);
}