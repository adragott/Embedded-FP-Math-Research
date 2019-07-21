#ifndef _PTCC_H_
#define _PTCC_H_

#include <asf.h>

struct tcc_module tcc_mod;



uint64_t get_micros(void);
void ptcc_init(void);
#endif