#include "sf-types.h"
#include "sh7708.h"
#include "devscc.h"
#include "print.h"
#include "bsort-input.h"
#include "softwareblink.h"

int
main(void)
{
	int i;
	int maxindex = bsort_input_len - 1;

	//printf("\n\n[%s]\n", bsort_input);
	while (maxindex > 0)
	{	
		*gDebugLedsMemoryMappedRegister = 0xFF;

		for (i = 0; i < maxindex; i++)
		{
			if (bsort_input[i] > bsort_input[i+1])
			{
				/*		swap		*/
				bsort_input[i] ^= bsort_input[i+1];
				bsort_input[i+1] ^= bsort_input[i];
				bsort_input[i] ^= bsort_input[i+1];
			}
		}
		*gDebugLedsMemoryMappedRegister = 0x00;

		maxindex--;
	}

	//printf("[%s]\n", bsort_input);

	return 0;

	/*
	 *	Reading from the special address pointed to by
	 *	kDebugLedsMemoryMappedRegister will cause the processor to
	 *	set the value of 8 of the FPGA's pins to the byte written
	 *	to the address. See the PCF file for how those 8 pins are
	 *	mapped.
	 */
}
