#pragma once
#include <chrono>
#include "lerp.h"

// seed first!
template <typename T>
class randGen {
	int seed;

	// middle square weyl sequence
	uint64_t w = 0;

	// Must be odd (least significant bit is "1"), and upper 64-bits non-zero
	const uint64_t s = 0xb5ad4eceda1ce2a9; // qualifying seed

public:
	randGen();
	~randGen();

	// rand min - max (incl)
	T rand(T min, T max);
	// rand dec min -0 max (incl)
	T randDecimal(T min, T max);
	// set seed
	void seedRand(int seedVal);
	// get seed
	int getSeed();
};

template <typename T>
randGen<T>::randGen()
{
	// seeds randomly, 6 digit num
	//auto timePoint = std::chrono::system_clock::now();
	//auto epoch = timePoint.time_since_epoch();
	//seed = epoch.count();
	//// seed = 0;
	//std::string s = std::to_string(seed);
	//int len = s.length();

	//// get middle 6 digits
	//s = s.substr(len / 2 + 3, 6);
	//seed = stoi(s);
}

template <typename T>
randGen<T>::~randGen()
{
}

template <typename T>
T randGen<T>::rand(T min, T max)
{
	//int seedCnt = std::to_string(seed).length();
	//// if odd
	//if (seedCnt % 2 != 0) {
	//	// make even
	//	seedCnt++;
	//}

	//T temp = seed * seed;

	//std::string tempS = std::to_string((int)temp);
	//int tempCnt = tempS.length();

	//// if odd
	//if (tempCnt % 2 != 0) {
	//	// make even
	//	tempS.insert(0, "0");
	//	tempCnt++;
	//}

	//int startIdx = (tempCnt - seedCnt) / 2;
	//// get substr
	//seed = stoi(tempS.substr(startIdx, startIdx + seedCnt));

	//// constrain
	//seed = (int)seed % (int)(max - min + 1) + min;

	//return seed;

	// middle square weyl sequence
	// uint64_t w = 0;

	// Must be odd (least significant bit is "1"), and upper 64-bits non-zero
	// const uint64_t s = 0xb5ad4eceda1ce2a9; // qualifying seed
	
	// return 32-bit number

	seed *= seed; // square the number
	w += s; // the weyl sequence
	seed += w; // apply to seed
	seed = abs(seed);
	seed = (seed >> 32) | (seed << 32); // return the middle 32-bits

	// constrain
	seed = seed % (int)(max - min + 1) + min;

	return seed;
}

template<typename T>
T randGen<T>::randDecimal(T min, T max)
{
	//// get number of digits (precision)
	//int numDecDigits = 0;
	//int numDecDigitsMin = 0;
	//int numDecDigitsMax = 0;
	//std::string minS = std::to_string(min);
	//std::string maxS = std::to_string(max);

	//for (int i = minS.length() - 1; minS[i] != '.' && i > 0; i--) { // "."
	//	numDecDigitsMin++;
	//}
	//for (int i = maxS.length() - 1; maxS[i] != '.' && i > 0; i--) {
	//	numDecDigitsMax++;
	//}

	//// set to more precise
	//numDecDigits = numDecDigitsMin < numDecDigitsMax ? numDecDigitsMin : numDecDigitsMax;

	//// get rid of decimal
	//min *= pow(10, numDecDigits);
	//max *= pow(10, numDecDigits);

	//T r = rand((int)min, (int)max);

	//// make normal again
	//r /= pow(10, numDecDigits);

	//return r;
	return min;
}

template<typename T>
void randGen<T>::seedRand(int seedVal)
{
	seed = seedVal;
}

template<typename T>
int randGen<T>::getSeed()
{
	return seed;
}
