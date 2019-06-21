#include "PseudoRandomNumberGenerator.h"

PseudoRandomNumberGenerator* PseudoRandomNumberGenerator::instance = 0;

PseudoRandomNumberGenerator::PseudoRandomNumberGenerator(){
	auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
	pseudoRNG = new std::mt19937((unsigned int)seed);
}

PseudoRandomNumberGenerator::~PseudoRandomNumberGenerator(){
	delete pseudoRNG;
}

PseudoRandomNumberGenerator* PseudoRandomNumberGenerator::Instance(){
	
	if(instance == 0) {
		instance = new PseudoRandomNumberGenerator();
	}
	return instance;
}

void PseudoRandomNumberGenerator::Release(){
	
	if(instance) {
		delete instance;
	}
	instance = 0;
}


unsigned int PseudoRandomNumberGenerator::random() {
	return (*pseudoRNG)();
}

unsigned int PseudoRandomNumberGenerator::random(unsigned int maxExclusive) {
	return (*pseudoRNG)() % maxExclusive;
}

std::mt19937 &PseudoRandomNumberGenerator::get_prng() {
	return *pseudoRNG;
}

