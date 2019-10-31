/* ###################################################################
**     Filename    : main.c
**     Processor   : S32K1xx
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file main.c
** @version 01.00
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup main_module main module documentation
**  @{
*/         
/* MODULE main */


/* Including necessary module. Cpu.h contains other modules needed for compiling.*/
#include "Cpu.h"
#include "pin_mux.h"
#include "dmaController1.h"
#include "clockMan1.h"
#include "lpuart0.h"
#include "comm.h"
#include "lpit_user_if.h"

volatile int exit_code = 0;

/* User includes (#include below this line is not maintained by Processor Expert) */

#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define welcomeMsg "The system is now in the bootloader mode\r\n\
and waiting for data in from host:\r\n"

#define APP_START_ADDRESS	MEM_APP_START

extern uint8_t   wait_timeout;


typedef void(*user_app_fnptr)(void);
user_app_fnptr      *p_jump_to_app;             // Function pointer to the user application.

static void JumpToUserApplication(void);
//static void reset_clock(void);
static void MSR_MSP(uint32_t addr);

/*! 
  \brief The main function for the project.
  \details The startup initialization sequence is the following:
 * - startup asm routine
 * - main()
*/
int main(void)
{
  uint8_t status = 0;

  /* Write your local variable definition here */
  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  #ifdef PEX_RTOS_INIT
    PEX_RTOS_INIT();                   /* Initialization of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  /* For example: for(;;) { } */
  CLOCK_SYS_Init(g_clockManConfigsArr,
	  	         CLOCK_MANAGER_CONFIG_CNT,
				 g_clockManCallbacksArr,
				 CLOCK_MANAGER_CALLBACK_CNT);
  CLOCK_SYS_UpdateConfiguration(0U, CLOCK_MANAGER_POLICY_AGREEMENT);
  /* Initialize and configure pins */
  PINS_DRV_Init(NUM_OF_CONFIGURED_PINS, g_pin_mux_InitConfigArr);

  /* Initialize timer */
  init_lipt();

  /* Initialize communication interfaces */
  init_comm();

  /* Send a welcome message */
  //LPUART_DRV_SendDataBlocking(INST_LPUART0, (uint8_t *)welcomeMsg, strlen(welcomeMsg), TIMEOUT);

  while (1)
  {

	  do {
		  status = comm_status_rx();
		  if(status)
		  {
			  LPIT_DRV_StopTimerChannels(INST_LPIT0, 0x01U);
			  LPIT_DRV_ClearInterruptFlagTimerChannels(INST_LPIT0, 0x01U);
			  LPIT_DRV_Deinit(INST_LPIT0);
			  comm_download_app();
			  //Reset immediately after updated
			  //	__asm__ ("NOP");
			  SystemSoftwareReset();
		  }
	  } while((!status) && (!wait_timeout));

#if 0
	  JumpToUserApplication(*((uint32_t*)APP_START_ADDRESS), *((uint32_t*)(APP_START_ADDRESS + 4)));
#else
	  JumpToUserApplication();
#endif
	  /* Stop here since the user program is not valid!!! */
	  for(;;);

  }


  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;) {
    if(exit_code != 0) {
      break;
    }
  }
  return exit_code;
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */


void JumpToUserApplication(void)
{
	/* Check if Entry address is erased and return if erased */
	if(*(uint32_t*)APP_START_ADDRESS == 0xFFFFFFFF){
		return;
	}
	//reset_clock();
	//p_jump_to_app = ((user_app_fnptr*)APP_START_ADDRESS) + 1U; // Point to the start reset vector for the  application.
	__asm("cpsid i");                                            // Disable interrupts
	p_jump_to_app = ((uint32_t)APP_START_ADDRESS+4);             // Point to the start reset vector for the  application.
	S32_SCB->VTOR = (uint32_t)APP_START_ADDRESS;                 // Update the vector table to the reset vector of the application.
	// __asm("dsb");                                             //Complete all explicit memory accesses.
	MSR_MSP(*(volatile uint32_t*)APP_START_ADDRESS); ;           //Set stack for the application
	(*p_jump_to_app)();                                          //Jump to application
}


//static void reset_clock(void)
//{
//  SCG->FIRCDIV |= SCG_FIRCDIV_FIRCDIV2(0b000); 	/* Disable FIRC divider  */
//}

static void MSR_MSP(uint32_t addr)
{
  __asm("msr msp, r0");
}



/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.1 [05.21]
**     for the NXP S32K series of microcontrollers.
**
** ###################################################################
*/
