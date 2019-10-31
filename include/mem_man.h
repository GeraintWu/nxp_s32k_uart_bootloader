/*
 * mem_man.h
 *
 *  Created on: Nov 2, 2016
 *      Author: B52932
 */

#ifndef SOURCES_DRIVERS_INC_MEM_MAN_H_
#define SOURCES_DRIVERS_INC_MEM_MAN_H_

#include "fsl_flash_driver_c90tfs.h"
#include "common.h"

/* Definitions */
#define MEM_APP_START		0x10000			/* Application starts at 64 kB */


/* Prototypes */
void mem_man_write(BootPhraseStruct *BP);
void mem_man_disable(void);

#endif /* SOURCES_DRIVERS_INC_MEM_MAN_H_ */
