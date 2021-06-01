#include "sf-types.h"
#include "bsort-input.h"
#include "string.h"
#include "softwareblink.h"

uint bsort_input_copied[20];
void run(void)
{
        int i;
        int maxindex = bsort_input_len - 1;

       
        memcpy(&bsort_input_copied, &bsort_input, bsort_input_len);

        while (maxindex > 0)
        {
				*gDebugLedsMemoryMappedRegister = 0xF0;
                for (i = 0; i < maxindex; i++)
                {
					*gDebugLedsMemoryMappedRegister = 0x60;
					*gDebugLedsMemoryMappedRegister = 0xFF & bsort_input_copied[i];
					if (bsort_input_copied[i] > bsort_input_copied[i+1])
                        {
                                /*              swap            */
                                bsort_input_copied[i] ^= bsort_input_copied[i+1];
                                bsort_input_copied[i+1] ^= bsort_input_copied[i];
                                bsort_input_copied[i] ^= bsort_input_copied[i+1];
                        }
					*gDebugLedsMemoryMappedRegister = 0xFF & bsort_input_copied[i];
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

				/*for (int i = 0; i < 20; i++) {

					if (bsort_input_copied[i] > 10) {
						*gDebugLedsMemoryMappedRegister = 0x03;
					}
					if (bsort_input_copied[i] < 11) {
						*gDebugLedsMemoryMappedRegister = 0x02;
					}
					*gDebugLedsMemoryMappedRegister = 0xFF & bsort_input_copied[i];

				}*/
        }
        return 0;
}