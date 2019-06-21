#pragma once
#include <random>
#include <chrono>

class PseudoRandomNumberGenerator
{
	static PseudoRandomNumberGenerator* instance;

private: 
	std::mt19937 *pseudoRNG;
public:
	static PseudoRandomNumberGenerator* Instance();
	static void Release();
	PseudoRandomNumberGenerator();
	~PseudoRandomNumberGenerator();
	std::mt19937 &get_prng();
	unsigned int random();
	unsigned int random(unsigned int maxExclusive);
};

