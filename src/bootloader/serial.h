/**
*	Serial device driver
**/

#ifndef _SERIAL_H_INCLUDED_
#define _SERIAL_H_INCLUDED_

/* Initialize the device */
int serial_init(int index);

/* Can a serial-port transmit a message ? */
int serial_is_send_enable(int index);

/* Function to transmit single character */
int serial_send_byte(int index, unsigned char b);

#endif