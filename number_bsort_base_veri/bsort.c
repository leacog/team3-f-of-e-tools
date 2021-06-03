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
		for (int j = 0; j < kSpinDelay; j++);
		for (int j = 0; j < kSpinDelay; j++);
		for (int j = 0; j < kSpinDelay; j++);

		for (int j = 0; j < 8; j++) {
			if (bsort_input[maxindex][j]==1){ *gDebugLedsMemoryMappedRegister = 0xFF}
			for (int j = 0; j < kSpinDelay; j++);
			*gDebugLedsMemoryMappedRegister = 0x00;
		}


		maxindex--;
	}
	

	return 0;
}