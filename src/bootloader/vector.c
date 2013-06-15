#include "defines.h"

/* Start up */
extern void start(void);

/*
* Setup the interrupt vector.
* It has placed to starting-address, by defined on linker script.
*/
void (*vectors[])(void) = {
	start, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 
};

/*
	It is also called the "Reset vector".
	It defines the address at processing in first. (The "start()" function is processing in first. )
*/