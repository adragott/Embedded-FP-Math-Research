#include "ptcc.h"

static uint64_t usec = 0;

__attribute__ ((optimize("s")))
__attribute__ ((section(".ramfunc")))
static inline void ptimer_cb(struct tcc_module* const mod)
{
	usec+=10;
	
}

// Get Microseconds
uint64_t get_us(void)
{
	return usec;
}

void ptcc_init(void)
{
	// PER = Period
	// f = CPU Clock Frequency
	// S = Desired Output frequency. I've chosen 100khz for a 10us Accuracy timer. 1Mhz for 1us was too much for the cpu to handle for some reason
	// N = prescalar
	// PER = (f - S*N) / S*N
	// PER = (48005120 - 1e5 * 16) / (1e5 * 16)
	// PER = (48005120 - 1.6e6) / 1.6e6
	// PER = 47,845,120 / 1.6e6
	// PER = 29.0032
	// 29 is close enough
	// probably
	struct tcc_config tcc_conf;
	tcc_get_config_defaults(&tcc_conf, TCC0);
	tcc_conf.counter.period = 29;
	tcc_conf.counter.clock_prescaler = TCC_CLOCK_PRESCALER_DIV16;
	
	tcc_init(&tcc_mod, TCC0, &tcc_conf);
	tcc_enable(&tcc_mod);
	tcc_register_callback(&tcc_mod, ptimer_cb, TCC_CALLBACK_OVERFLOW);
	tcc_enable_callback(&tcc_mod, TCC_CALLBACK_OVERFLOW);
}

