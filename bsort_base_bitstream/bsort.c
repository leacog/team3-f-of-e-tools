#include "sf-types.h"
#include "bsort.h"
#include "bsort-input.h"
#include "string.h"
#include "softwareblink.h"

uchar bsort_input_copied[bsort_input_len];
void run(void)
{
        int i;
        int maxindex = bsort_input_len - 1;

       
        memcpy(&bsort_input_copied, &bsort_input, bsort_input_len);

        while (maxindex > 0)
        {
                for (i = 0; i < maxindex; i++)
                {
                        if (bsort_input_copied[i] > bsort_input_copied[i+1])
                        {
                                /*              swap            */
                                bsort_input_copied[i] ^= bsort_input_copied[i+1];
                                bsort_input_copied[i+1] ^= bsort_input_copied[i];
                                bsort_input_copied[i] ^= bsort_input_copied[i+1];
                        }
                }

                maxindex--;
        }
}

void blink(void)
{
	*gDebugLedsMemoryMappedRegister = 0xFF;

	/*
	 *	Spin
	 */
	for (int j = 0; j < kSpinDelay; j++);

	*gDebugLedsMemoryMappedRegister = 0x00;

	/*
	 *	Spin
	 */
	for (int j = 0; j < kSpinDelay; j++);
}

int main(void)
{
        while (1)
        {
                *gDebugLedsMemoryMappedRegister = 0xFF;
                run();
                *gDebugLedsMemoryMappedRegister = 0x00;
				for (int j = 0; j < kSpinDelay*5; j++);

				for (int i = 0; i < 20; i++) {
					for (int j = 0; j < kSpinDelay*2; j++);

					for (int j = 0; j < bsort_input_copied[i]; j++) {
						blink();
					}
				}
        }
        return 0;
}