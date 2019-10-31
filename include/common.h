/*
 * common.h
 *
 *  Created on: Nov 2, 2016
 *      Author: B52932
 */

#ifndef SOURCES_DRIVERS_INC_COMMON_H_
#define SOURCES_DRIVERS_INC_COMMON_H_

#include "S32K118.h"
#include <stdint.h>

#define MAX_ADDRESS_BP	4
#define MAX_DATA_BP		32
#define MAX_PHSIZE_BP	37

typedef union
{
	uint8_t Byte[MAX_PHSIZE_BP]; 												/* Byte level access to the Phrase */
	struct
	{
		char PhraseType;														/* Type of received record (e.g. S0, S1, S5, S9...) */
		uint8_t PhraseSize; 													/* Phrase size (address + data + checksum) */
		uint8_t PhraseAddress[MAX_ADDRESS_BP]__attribute__ ((aligned (32))); 	/* Address, depending on the type of record it might vary */
		uint8_t PhraseData[MAX_DATA_BP]__attribute__ ((aligned (32))); 			/* Maximum 32 data bytes */
		uint8_t PhraseCRC;														/* Checksum of size + address + data */
	}F;
}BootPhraseStruct;


/* Little Endian to Big Endian macro */
#define LE2BE_32(c)	(((c & 0xFF) << 24) | ((c & 0xFF00) << 8) | ((c & 0xFF0000) >> 8) | ((c & 0xFF000000) >> 24))

#endif /* SOURCES_DRIVERS_INC_COMMON_H_ */
