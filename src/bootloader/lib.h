/**
*	Standard library
**/

#ifndef _LIB_H_INCLUDED_
#define _LIB_H_INCLUDED_

/* Function to transmit single character */
int putc(unsigned char c);

/* Function to transmit a string */
int puts(unsigned char *str);

/* Write a byte to the memory */
void *memset(void *b, int c, long len);
/* This memory-size is defined as 'long' (32bit).
 Because, H8 is 16bit-CPU, that is 'int' is 16bit. However it's too short, as memory-size. */

/* Copy the memory */
void *memcpy(void *dst, const void *src, long len);

/* Compare the memory */
int memcmp(const void *b1, const void *b2, long len);

/* Get length of the string */
int strlen(const char *s);

/* Copy the string */
char *strcpy(char *dst, const char *src);

/* Compare the string */
int strcmp(const char *s1, const char *s2);

/* Compare the string (with specified length) */
int strncmp(const char *s1, const char *s2, int len);

/* Function to transmit a value with HEX. (column = number of digit) */
int putxval(unsigned long value, int column);

#endif