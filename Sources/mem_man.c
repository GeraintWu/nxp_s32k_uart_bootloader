/*
 * mem_man.c
 *
 *  Created on: Nov 2, 2016
 *      Author: B52932
 */



#include "mem_man.h"

uint8_t is_mem_init = 0;						/* Variable used to flag is the memory has been initialized */
uint32_t flash_last_erased_sec = 0;				/* Last erased flash sector count */

#define CMD_LENGTH          0x80u
uint32_t cmd_sequence_in_ram[CMD_LENGTH];   /* FlashCommandSequence will be copied to this location */
#define CALLBACK_LENGTH     0x80u
uint32_t callback_in_ram[CALLBACK_LENGTH];  /* Callback function will be copied to this location */
uint8_t test_flag = 0;

/*! @brief Configuration structure flashCfg_0 */
const flash_user_config_t Flash_InitConfig0 = {
		/* for the S32K118 */
		.PFlashBase  = 0x00000000U,
		.PFlashSize  = 0x00040000U,
		.DFlashBase  = 0x10000000U,
		.EERAMBase   = 0x14000000U,
		.CallBack    = NULL_CALLBACK
};

/* Provide info about the flash blocks through an USER config structure */
flash_user_config_t flashUserConfig;

/* Declare a FLASH config struct which initialized by FlashInit, and will be used by all flash operations */
flash_ssd_config_t flashSSDConfig;



void mem_man_write(BootPhraseStruct *BP){
	uint16_t data_size;
	uint32_t flash_prog_address;
	flash_command_sequence_t pCmdSequence;
	uint8_t dummy_byte;
	uint8_t i;

	/* Check if memory is initialized */
	if(is_mem_init == 0){					/* Initialize memory */
		FlashInit(&Flash_InitConfig0, &flashSSDConfig);
		is_mem_init = 1;
	}

	/* Get size and address */
	if(BP->F.PhraseType == '3'){
		uint32_t *tmp;

		/* Data size minus address (4) and CRC (1)*/
		data_size = BP->F.PhraseSize - 5;

		/* Get 32-bit address out of array */
		tmp = (uint32_t *) BP->F.PhraseAddress;
		flash_prog_address = LE2BE_32(*tmp) & 0xFFFFFFFF;
	} else if(BP->F.PhraseType == '2'){
		uint32_t *tmp;

		/* Data size minus address (3) and CRC (1)*/
		data_size = BP->F.PhraseSize - 4;

		/* Get 24-bit address out of array */
		tmp = (uint32_t *) BP->F.PhraseAddress;
		flash_prog_address = (LE2BE_32(*tmp) >> 8) & 0xFFFFFF;
	} else{
		uint32_t *tmp;

		/* Data size minus address (2) and CRC (1)*/
		data_size = BP->F.PhraseSize - 3;

		/* Get 16-bit address out of array */
		tmp = (uint32_t *) BP->F.PhraseAddress;
		flash_prog_address = (LE2BE_32(*tmp) >> 16) & 0xFFFF;
	}

	/* Check overlap with bootloader */
	if(flash_prog_address >= MEM_APP_START){

		/* Check if block has been erased aligned addresses (first address is assumed to be 0x2000) */
		if((flash_prog_address % FEATURE_FLS_PF_BLOCK_SECTOR_SIZE) == 0){

			/* Erase sector */
			FlashEraseSector(&flashSSDConfig, flash_prog_address, FEATURE_FLS_DF_BLOCK_SECTOR_SIZE, FlashCommandSequence);

			/* Store the address of the erased sector */
			flash_last_erased_sec = flash_prog_address;

		/* Check that the address from the SREC is within the previously erased sector (check misaligned addresses) */
		} else if((flash_last_erased_sec + FEATURE_FLS_PF_BLOCK_SECTOR_SIZE) < flash_prog_address){
			uint32_t tmp_add;
			/* Obtain address of sector to be erased */
			tmp_add = flash_prog_address % FEATURE_FLS_PF_BLOCK_SECTOR_SIZE;
			tmp_add = flash_prog_address - tmp_add;

			/* Erase sector */
			FlashEraseSector(&flashSSDConfig, tmp_add, FEATURE_FLS_DF_BLOCK_SECTOR_SIZE, FlashCommandSequence);

			/* Store the address of the erased sector */
			flash_last_erased_sec = tmp_add;
		}

	    if(data_size % FEATURE_FLS_DF_BLOCK_WRITE_UNIT_SIZE) {

	    	dummy_byte = FEATURE_FLS_DF_BLOCK_WRITE_UNIT_SIZE - (data_size % FEATURE_FLS_DF_BLOCK_WRITE_UNIT_SIZE);

		    for(i = 0; i< dummy_byte; i++)
		  	  BP->F.PhraseData[data_size+i] = 0xFF;

		    data_size = data_size + dummy_byte;
	    }


		/* Program phrase */
		FlashProgram(&flashSSDConfig, flash_prog_address, data_size,  BP->F.PhraseData, FlashCommandSequence);
	}
}

/*
 * Checks if the memory was enabled and disables it
 **/
void mem_man_disable(void){

	if(is_mem_init){
		//FLASH_reset();
	}
}
