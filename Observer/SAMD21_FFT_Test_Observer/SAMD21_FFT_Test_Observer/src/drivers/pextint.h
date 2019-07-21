#ifndef _PEXTINT_H_
#define _PEXTINT_H_

#include <asf.h>

#define TIMING_TEST_PIN_MUX		MUX_PA28A_EIC_EXTINT8
#define TIMING_TEST_PIN			PIN_PA28A_EIC_EXTINT8
#define TIMING_TEST_EIC_LINE	8

void pextint_init(void);
void pextint_init_callbacks(void);


#endif