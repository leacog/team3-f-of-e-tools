#include "sf-types.h"
#include "bsort-input.h"
#include "string.h"
#include "softwareblink.h"

void run()
{
	int i;
	int maxindex = bsort_input_len - 1;
	*gDebugLedsMemoryMappedRegister = 0x00;
	uchar* input = bsort_input;

	while (maxindex > 0)
	{
		for (i = 0; i < maxindex; i++)
		{
			if (input[i] > input[i + 1])
			{
				/*		swap		*/
				input[i] ^= input[i + 1];
				input[i + 1] ^= input[i];
				input[i] ^= input[i + 1];
			}
		}
		//for (int j = 0; j < kSpinDelay; j++);
		//for (int j = 0; j < kSpinDelay; j++);
		//for (int j = 0; j < kSpinDelay; j++);
		//for (int j = 1; j < 0x100; j++) {

		if (input[maxindex] == bsorted[maxindex]) { *gDebugLedsMemoryMappedRegister = 0xFF; }
		else {*gDebugLedsMemoryMappedRegister = 0x00; };	
		//for (int m = 0; m < kSpinDelay; m++);
		//*gDebugLedsMemoryMappedRegister = bsort_input[maxindex];
		
		maxindex--;
	}
	for (int j = 0; j < kSpinDelay; j++);
	for (int j = 0; j < kSpinDelay; j++);
}

int main(void)
{
	while (1)
	{
		*gDebugLedsMemoryMappedRegister = 0x00;
		run();
	}
	return 0;
}
