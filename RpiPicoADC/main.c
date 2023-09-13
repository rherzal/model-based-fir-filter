#include <stdio.h>
#include "pico/stdlib.h"

#include "hardware/adc.h"
#include "hardware/dma.h"
#include "hardware/pwm.h"

#include "Filter0.h"
#include "rtwtypes.h"
#include "Filter0_private.h"
#include "Filter0_types.h"


int main()
{
  // Initialize the standard I/O
  stdio_init_all();

  // settings for the adc
  adc_init();
  adc_gpio_init(26);
  adc_select_input(0);
  adc_set_clkdiv(1);
  adc_irq_set_enabled(true);
  adc_fifo_setup(1, // enable conversion result to fifo
                 1, // enable dma request when fifo contans data
                 1, // 1 sample treshold for dma request
                 0, // no error bit
                 0  // no byte shift
  );

  uint transfer_count = 1;
  // settings for the dma

  uint16_t current_sample = 0;

  int dma_channel = 0;
  int dma_ctrl_channel = 1;

  dma_channel_config dma_ctrl_channel_config = dma_channel_get_default_config(dma_ctrl_channel);

  channel_config_set_transfer_data_size(&dma_ctrl_channel_config, DMA_SIZE_32);
  channel_config_set_read_increment(&dma_ctrl_channel_config, false);
  channel_config_set_write_increment(&dma_ctrl_channel_config, false);

  dma_channel_configure(dma_ctrl_channel, &dma_ctrl_channel_config, &dma_hw->ch[dma_channel].al1_transfer_count_trig, &transfer_count, 1, false);

  dma_channel_config dma_config = dma_channel_get_default_config(dma_channel);

  channel_config_set_transfer_data_size(&dma_config, DMA_SIZE_16);

  channel_config_set_read_increment(&dma_config, false);
  channel_config_set_write_increment(&dma_config, false);

  channel_config_set_dreq(&dma_config, DREQ_ADC);
  channel_config_set_chain_to(&dma_config, dma_ctrl_channel);

  channel_config_set_ring(&dma_config, false, 9);

  dma_channel_configure(dma_channel, &dma_config, &current_sample, &adc_hw->fifo, 1, true);

  adc_run(true);

  // pwm configuration
  const uint pwm_gpio = 0;
  gpio_set_function(pwm_gpio, GPIO_FUNC_PWM);
  uint slice_num = pwm_gpio_to_slice_num(pwm_gpio);

  pwm_set_wrap(slice_num, 0x0FFF);
  pwm_set_chan_level(slice_num, PWM_CHAN_A, 0x07FF);

  pwm_set_enabled(slice_num, true);



  uint16_T output = 0; 

  while (true) {
  Filter0_U.inputFilter = current_sample;
  Filter0_step();
  output = Filter0_Y.outputFilter;
  pwm_set_chan_level(slice_num, PWM_CHAN_A, output);
  sleep_ms(1);
  }

  return 0;
}
