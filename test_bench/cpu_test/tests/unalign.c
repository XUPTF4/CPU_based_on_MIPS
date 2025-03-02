#include "trap.h"

unsigned x = 0xffffffff;

int main() {
	 unsigned char buf[16];

	for(int i = 0; i < 4; i++) {
		*((unsigned*)(buf + 3)) = 0xaabbccdd;

		x = *((unsigned*)(buf + 3));
		check(x == 0xaabbccdd);

		buf[0] = buf[1] = 0;
	}

	return 0;
}
