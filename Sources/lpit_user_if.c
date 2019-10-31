/*
 * lpit_user_if.c
 *
 *  Created on: 2019¦~10¤ë25¤é
 *      Author: Jingtai_Wu
 */

#include "lpit_user_if.h"

static void lpit_callback(void);
static uint16_t lpit_cnt;

void init_lipt(void)
{
  LPIT_DRV_Init(INST_LPIT0, &lpit0_InitConfig);
  LPIT_DRV_InitChannel(INST_LPIT0, 0, &lpit0_ChnConfig0);
  INT_SYS_InstallHandler(LPIT0_IRQn, &lpit_callback, (isr_t*)NULL );
  lpit_cnt = 0 ;
  wait_timeout = 0;
  LPIT_DRV_StartTimerChannels(INST_LPIT0, 0x01U);
}


/* 1ms-periodic interrupt */
static void lpit_callback(void)
{
	LPIT_DRV_ClearInterruptFlagTimerChannels(INST_LPIT0, 0x01U);
	if(++lpit_cnt == TIMEOUT_SECONDS*1000)
	{
		lpit_cnt = 0;
		wait_timeout = 1;
		LPIT_DRV_StopTimerChannels(INST_LPIT0, 0x01U);
	}
}
