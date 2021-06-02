#include "lowpass-input.h"

int
main(void)
{
	int i;
	int tailLenght = 1;
	int output[lowpass_input_len];
	for (i = 0; i < lowpass_input_len; i++) {
		for(int j = 0; j < tailLenght; j++){
			output[i] += lowpass_input[i-j];
		} 
		if(tailLenght < maxTailLenght) {
			tailLenght++;
		}
	}
	return 0;
}
