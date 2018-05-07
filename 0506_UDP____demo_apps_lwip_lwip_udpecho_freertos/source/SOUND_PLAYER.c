/*
 * SOUND_PLAYER.c
 *
 *  Created on: May 6, 2018
 *      Author: edson
 */

#include "SOUND_PLAYER.h"



void PITconfig()
{
    pit_config_t pit_config;
    PIT_GetDefaultConfig(&pit_config);
    //CLOCK_EnableClock(kCLOCK_Pit0);
    //MCR
    PIT_Init(PIT, &pit_config);
//    PIT_SetTimerPeriod(PIT, kPIT_Chnl_0, CLOCK_GetBusClkFreq()*(1.5));
    /* Set timer period for channel 0 */
    PIT_SetTimerPeriod(PIT, kPIT_Chnl_0, USEC_TO_COUNT(1000000U, CLOCK_GetFreq(kCLOCK_BusClk)));
//    PIT_SetTimerPeriod(PIT, kPIT_Chnl_0, CLOCK_GetBusClkFreq());
    PIT_GetStatusFlags(PIT, kPIT_Chnl_0);
    PIT_EnableInterrupts(PIT, kPIT_Chnl_0, kPIT_TimerInterruptEnable);
    NVIC_EnableIRQ(PIT0_IRQn);
    NVIC_SetPriority(PIT0_IRQn,5);
    PIT_StartTimer(PIT, kPIT_Chnl_0);

}

void DAC_config(void)
{
        dac_config_t dacConfigStruct;

        /* Configure the DAC. */
        /*
         * dacConfigStruct.referenceVoltageSource = kDAC_ReferenceVoltageSourceVref2;
         * dacConfigStruct.enableLowPowerMode = false;
         */
        DAC_GetDefaultConfig(&dacConfigStruct);
        DAC_Init(DEMO_DAC_BASEADDR, &dacConfigStruct);
//        NVIC_SetPriority(DAC0_IRQn);
        DAC_Enable(DEMO_DAC_BASEADDR, true); /* Enable output. */

}
void LED_config(void)
{
	CLOCK_EnableClock(kCLOCK_PortB);//B
	port_pin_config_t config_led =
	 	 	{
	 	 			kPORT_PullDisable, kPORT_SlowSlewRate, kPORT_PassiveFilterDisable,
	 	 			kPORT_OpenDrainDisable, kPORT_LowDriveStrength, kPORT_MuxAsGpio,
	 	 			kPORT_UnlockRegister,
	 	 	};
	PORT_SetPinConfig(PORTB, 21, &config_led);    //B
	gpio_pin_config_t led_config_gpio = { kGPIO_DigitalOutput, 1 };
	GPIO_PinInit(GPIOB, 21, &led_config_gpio);//B
}

 static void audio_player(void*arg)
{
//	event = xEventGroupCreate();

	/* This handler that is originally shared in this module is now pointing to the binarySemaphore created */
	/* the creation of the semaphore happens only one single time*/
	PITconfig();
	DAC_config();
	LED_config();

//	vTaskDelete(NULL);

	while (1)
	{
		xSemaphoreTake(pitToogleSemaphore,portMAX_DELAY);
		GPIO_TogglePinsOutput(GPIOB, 1 << 21);

		//	if (EVENT_BIT & xEventGroupGetBits(event)) {
		//		netbuf_copy(buf, pingBuffer, N_SIZE);
		//		xEventGroupClearBits(event, EVENT_BIT);
		//	} else {
		//		netbuf_copy(buf, pongBuffer, N_SIZE);
		//		xEventGroupSetBits(event, EVENT_BIT);
		//	}
//		DAC_SetBufferValue(DEMO_DAC_BASEADDR, 0U, DAC_1_0_VOLTS);
	}



}


 void audio_player_init(void)
{
	pitToogleSemaphore = xSemaphoreCreateBinary();
	xTaskCreate(audio_player, "audio_player", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
}



uint8_t counter = 0;
void PIT0_IRQHandler()
{
	BaseType_t xHigherPriorityTaskWoken;

	PIT_ClearStatusFlags(PIT, kPIT_Chnl_0, kPIT_TimerFlag);
//	GPIO_TogglePinsOutput(GPIOB, 1 << 21);
//	counter++;
//	PRINTF("\r\n%d\r\n", counter);
//en lugar de poner logica del DAC aqui, se pondra una bandera o semaforo
	xHigherPriorityTaskWoken = pdFALSE;
	xSemaphoreGiveFromISR(pitToogleSemaphore, &xHigherPriorityTaskWoken );
	portYIELD_FROM_ISR( xHigherPriorityTaskWoken );
}
