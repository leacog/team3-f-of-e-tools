#include "sf-types.h"
#include "bsort-input.h"
#include "string.h"
#include "softwareblink.h"




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
		*gDebugLedsMemoryMappedRegister = bsort_input[maxindex];

		maxindex--;
	}
	

	return 0;
}