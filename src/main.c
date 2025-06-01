#include "common.h"

void
main(void)
{
	SHOW_BKG;
	DISPLAY_ON;
	printf("Hello World!");
	
	while (1) {
		vsync();
	}
}
