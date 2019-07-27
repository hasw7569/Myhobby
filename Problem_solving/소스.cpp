#include<iostream>
#include<bitset>
using namespace std;
int main()
{
	union {
		double f;
		uint64_t i;
	} u;
	//u.f = 1.0e-60;
	u.f = -1.0e60;

	cout << bitset<64>(u.f) << "\n";
	cout << bitset<64>(u.i) << "\n\n";

	uint32_t ix = u.i >> 32 & 0x7fffffff;

	cout << bitset<32>(ix) << "\n";
	cout << bitset<32>(0x7ff00000) << "\n";
	cout << bitset<32>((0x3ff - 54) << 20) << "\n\n";

	cout << bitset<32>(0x40670000) << "\n";
	return 0;
}