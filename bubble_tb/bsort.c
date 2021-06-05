#include "sf-types.h"
#include "bsort-input.h"
#include "string.h"
#include "softwareblink.h"




int
main(void)
{
	int i;
	int maxindex = bsort_input_len - 1;
	*gDebugLedsMemoryMappedRegister = 0x00;

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
		//for (int j = 0; j < kSpinDelay; j++);
		//for (int j = 0; j < kSpinDelay; j++);
		//for (int j = 0; j < kSpinDelay; j++);

		//for (int j = 1; j < 0x100; j++) {

		if (bsort_input[maxindex] == bsorted[maxindex]) { *gDebugLedsMemoryMappedRegister = 0xFF; }
		else {*gDebugLedsMemoryMappedRegister = 0x00; };	
		//for (int m = 0; m < kSpinDelay; m++);
		//*gDebugLedsMemoryMappedRegister = bsort_input[maxindex];
		
		maxindex--;
	}
	

	return 0;
	for (int j = 0; j < kSpinDelay; j++);
	for (int j = 0; j < kSpinDelay; j++);
	for (int j = 0; j < kSpinDelay; j++);
	for (int j = 0; j < kSpinDelay; j++);
        for (int j = 0; j < kSpinDelay; j++);
        for (int j = 0; j < kSpinDelay; j++);
	for (int j = 0; j < kSpinDelay; j++);
        for (int j = 0; j < kSpinDelay; j++);
        for (int j = 0; j < kSpinDelay; j++);
}
