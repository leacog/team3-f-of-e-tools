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


int main(void)
{
        while (1)
        {
                 *gDebugLedsMemoryMappedRegister = 0xFF;
                run();
                *gDebugLedsMemoryMappedRegister = 0x00;

				for (int i = 0; i < 20; i++) {

					/* to verify the bubble sort in a simply way */
					if (bsort_input_copied[i] = 10) {
						*gDebugLedsMemoryMappedRegister = 0x0A;
					}
					if (bsort_input_copied[i] = 11) {
						*gDebugLedsMemoryMappedRegister = 0x0B;
					}
					if (bsort_input_copied[i] = 15) {
						*gDebugLedsMemoryMappedRegister = 0x0F;
					}
					if (bsort_input_copied[i] = 16) {
						*gDebugLedsMemoryMappedRegister = 0x10;
					}
					/* output the sorted numbers (not working correctly)*/
					*gDebugLedsMemoryMappedRegister = bsort_input_copied[i];

				}
        }
        return 0;
}