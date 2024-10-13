// myheader.h
#ifndef MYHEADER_H
#define MYHEADER_H

#include <setjmp.h>  // Required for setjmp() and longjmp()

// Global jump buffer
extern jmp_buf buf;

// Function prototypes
void first_jump(void);
void second_jump(void);

#endif // MYHEADER_H
