#include "sf-types.h"
#include "bsort-input.h"
#include "string.h"
#include "softwareblink.h"

void run(void)
{
        int i;
        int maxindex = bsort_input_len - 1;


        while (maxindex > 0)
        {
                for (i = 0; i < maxindex; i++)
                {
					if (bsort_input[i] > bsort_input[i+1])
                        {
                                /*              swap            */
                                bsort_input[i] ^= bsort_input[i+1];
                                bsort_input[i+1] ^= bsort_input[i];
                                bsort_input[i] ^= bsort_input[i+1];
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

				for (int i = 20; i < 40; i++) {

					*gDebugLedsMemoryMappedRegister = bsort_input[i];

				}
        }
        return 0;
}