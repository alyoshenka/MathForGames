#include "utils.h"



int min(int a, int b) {
	return a < b ? a : b;
	// return -1;
}

int min(int a, ...)
{
	// setup
	va_list args;
	va_start(args, a);
	int min = va_arg(args, int);
	int * temp = &min;

	// iterate through
	while (temp != nullptr) { // pointer stuff
		temp = &va_arg(args, int);
		if (temp < &min) {
			min = *temp;
		}
	}

	// stop
	va_end(args);
	return min;
}

int max(int a, int b)
{
	return a > b ? a : b;
}

int clamp(int value, int min, int max)
{
	if (value > max) {
		return max;
	}
	if (value < min) {
		return min;
	}
	return value;
}

int abs(int val)
{
	if (val < 0) {
		val *= -1;
	}
	return val;
}

int pow(int base, int power)
{
	if (power == 0) {
		return 1;
	}

	int temp = base;
	for (int i = 0; i < power - 1; i++) {
		temp *= base;
	}
	return temp;
}

bool isPowerOfTwo(int val)
{
	if (val == 0) {
		return false;
	}

	while (val != 1) {
		if (val % 2 != 0) {
			return true;
		}
		val /= 2;
	}

	return false;
}

int nextPowerOfTwo(int val)
{
	int test = 1;

	while (test < val) {
		test *= 2;
	}

	return test;
}

float moveTowards(float current, float target, float maxDelta)
{
	if (target - current > maxDelta) {
		current += maxDelta;
	}
	else {
		current = target;
	}
	return current;
}
