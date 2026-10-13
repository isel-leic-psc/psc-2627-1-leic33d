#include <stdio.h>

#if 0

union Float {
	float f;
	unsigned i;
};

union Float number = {.f = 3.5 };

int main()
{
	printf("number = %032b\n", number.i);
}

#endif

#if 1

union Float {
	float f;
	unsigned i;
	struct {
		unsigned mantissa: 23;
		unsigned exponent: 8;
		unsigned signal: 1;
	};
};

union Float number = {.f = 3.5 };

int main()
{
	printf("number = %032b\n", number.i);
	printf("mantissa = %023b, exponent = %08b, signal = %d\n",
		number.mantissa, number.exponent, number.signal);
}

#endif
