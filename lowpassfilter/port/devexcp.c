#include <stdint.h>
#include "sf-types.h"
#include "sh7708.h"

ulong
devexcp_getintevt(void)
{
	return	*(EXCP_INTEVT);
}
