#include "sf-types.h"
#include "lowpass-input.h"
#include "string.h"


void sendSerial(uchar inputByte)
{
	*gDebugLedsMemoryMappedRegister = 0xFF;
	for (int j = 0; j < kSpinDelay*8; j++);

	uchar bits = inputByte;
	for(int i = 0; i < 8; i++) {
		*gDebugLedsMemoryMappedRegister = 0x0F; //Value to indicate new read for verilator
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

int main(void)
{
	uchar testChar = 0x69;
	sendSerial(testChar);
	int output[lowpass_input_len - NUM_TAPS];

	for (int i = 0; i < lowpass_input_len - NUM_TAPS; i++) {
		for(int j = 0; j < NUM_TAPS; j++){
			output[i] += (lowpass_input_1kHz[i-j] + lowpass_input_16kHz[i-j]);
			sendSerial( (uchar)output[i] );
		} 
	}
	return 0;
}
