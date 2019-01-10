#pragma once
#include <cassert>
#include <iostream>

// #undef assert

// template <typename T>
bool aassert(const char * testName, bool expression) { // "Alexi Assert"

	if (expression) {
		std::cout << "[PASS] ";
	}
	else {
		std::cout << "[FAIL] ";
		#ifdef ENABLE_HALT_ON_FAILURE
			std::abort();
		#endif
	}

	std::cout << testName << std::endl;

	return expression;
}

template <typename T>
bool aassert(const char * testName, T expected, T actual) {

	std::cout << testName;

	bool expression = expected == actual;
	if (expression) {
		std::cout << "[PASS] " << std::endl;
	}
	else {
		std::cout << "[FAIL] " << std::endl;
		#ifdef ENABLE_HALT_ON_FAILURE
				std::abort();
		#endif
	}

	return expression;
}

template <typename T>
bool aassert(const char * testName, T expected, T actual, T tolerance) {

	bool expression = actual - expected <= tolerance && actual - expected >= -tolerance;

	if (expression) {
		std::cout << "[PASS] ";
	}
	else {
		std::cout << "[FAIL] ";
		#ifdef ENABLE_HALT_ON_FAILURE
				std::abort();
		#endif
	}

	std::cout << testName << std::endl;

	return expression;
}
