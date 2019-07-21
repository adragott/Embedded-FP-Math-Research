#include "pextint.h"

__attribute__ ((optimize("s")))
__attribute__ ((section(".ramfunc")))
static void pextint_cb(struct tcc_module* const mod)
{
	bool pin_state = port_pin_get_input_level(TIMING_TEST_PIN);
	port_pin_set_output_level(LED_0_PIN, pin_state);
}

void pextint_init(void)
{

	struct extint_chan_conf config_extint_chan;

	extint_chan_get_config_defaults(&config_extint_chan);

	config_extint_chan.gpio_pin           = TIMING_TEST_PIN;
	config_extint_chan.gpio_pin_mux       = TIMING_TEST_PIN_MUX;
	config_extint_chan.gpio_pin_pull      = EXTINT_PULL_DOWN;
	config_extint_chan.detection_criteria = EXTINT_DETECT_BOTH;

	extint_chan_set_config(TIMING_TEST_EIC_LINE, &config_extint_chan);

}

void pextint_init_callbacks(void)
{

	extint_register_callback(pextint_cb, TIMING_TEST_EIC_LINE, EXTINT_CALLBACK_TYPE_DETECT);

	extint_chan_enable_callback(TIMING_TEST_EIC_LINE,
	EXTINT_CALLBACK_TYPE_DETECT);
	
}

