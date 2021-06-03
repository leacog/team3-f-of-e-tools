#include "sf-types.h"
#include "bsort-input.h"
#include "string.h"
#include "softwareblink.h"


void sendSerial(uchar inputByte)
{
	*gDebugLedsMemoryMappedRegister = 0xFF;
	for (int j = 0; j < kSpinDelay*4; j++);
	*gDebugLedsMemoryMappedRegister = 0x00;
	for (int j = 0; j < kSpinDelay*4; j++);

	uchar bits = inputByte;
	for(int i = 0; i < 8; i++) {
		if(bits & 0x01) {
			*gDebugLedsMemoryMappedRegister = 0xFF;
		} else {
			*gDebugLedsMemoryMappedRegister = 0x00;
		}
		bits = (bits >> 1);
		for (int j = 0; j < kSpinDelay; j++);
 	}

	*gDebugLedsMemoryMappedRegister = 0x00;

}


int
main(void)
{
	int i;
	int maxindex = bsort_input_len - 1;

	while (maxindex > 0)
	{
		for (i = 0; i < maxindex; i++)
		{
			if (bsort_input[i] > bsort_input[i + 1])
			{
				/*		swap		*/
				bsort_input[i] ^= bsort_input[i + 1];
				bsort_input[i + 1] ^= bsort_input[i];
				bsort_input[i] ^= bsort_input[i + 1];
			}
		}
		sendSerial(bsort_input[maxindex]);
		maxindex--;
	}
	

	return 0;
}