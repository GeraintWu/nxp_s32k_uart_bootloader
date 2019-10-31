/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*!
 * @file fsl_flash_driver_c90tfs.c
 *
 * @page misra_violations MISRA-C:2012 violations
 *
 * @section [global]
 * Violates MISRA 2012 Required Rule 1.3, Taking address of near auto variable.
 * The code is not dynamically linked. An absolute stack address is obtained
 * when taking the address of the near auto variable. A source of error in
 * writing dynamic code is that the stack segment may be different from the data
 * segment.
 *
 * @section [global]
 * Violates MISRA 2012 Required Rule 10.3, Expression assigned to a narrower or
 * different essential type.
 * This is required by the conversion of a bit-field of a register into a enum type.
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 10.5, Impermissible cast; cannot cast from
 * 'essentially unsigned' type to 'essentially enum<i>'.
 * This is required by the conversion of a bit-field of a register into a enum type.
 *
 * @section [global]
 * Violates MISRA 2012 Required Rule 10.8, Impermissible cast of composite
 * expression (different essential type categories).
 * This is required by the conversion of a bit-field of a register into enum type.
 *
 * @section [global]
 * Violates MISRA 2012 Required Rule 11.1, Conversion between a pointer
 * to function and another type.
 * The cast is required to define a callback function.
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 11.4, Conversion between a pointer and
 * integer type.
 * The cast is required to initialize a pointer with an unsigned long define,
 * representing an address.
 *
 * @section [global]
 * Violates MISRA 2012 Required Rule 11.6, Cast from unsigned int to pointer.
 * The cast is required to initialize a pointer with an unsigned long define,
 * representing an address.
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 18.4, Pointer arithmetic other than array
 * indexing used.
 * This is required to increment the source address.
 */

#include "fsl_flash_driver_c90tfs.h"

/*******************************************************************************
 * Code
 ******************************************************************************/

/*FUNCTION**********************************************************************
 *
 * Function Name : FlashGetDEPartitionCode
 * Description   : Gets DFlash size from FlexNVM Partition Code.
 *
 * Implements    : FlashGetDEPartitionCode_Activity
 *END**************************************************************************/
static void FlashGetDEPartitionCode(flash_ssd_config_t * const pSSDConfig, \
                                    uint8_t DEPartitionCode)
{
    /* Select D-Flash size */
    if      (0x00U == DEPartitionCode) {pSSDConfig->DFlashSize = (uint32_t)FEATURE_FLS_DF_SIZE_0000;}
    else if (0x01U == DEPartitionCode) {pSSDConfig->DFlashSize = (uint32_t)FEATURE_FLS_DF_SIZE_0001;}
    else if (0x02U == DEPartitionCode) {pSSDConfig->DFlashSize = (uint32_t)FEATURE_FLS_DF_SIZE_0010;}
    else if (0x03U == DEPartitionCode) {pSSDConfig->DFlashSize = (uint32_t)FEATURE_FLS_DF_SIZE_0011;}
    else if (0x04U == DEPartitionCode) {pSSDConfig->DFlashSize = (uint32_t)FEATURE_FLS_DF_SIZE_0100;}
    else if (0x05U == DEPartitionCode) {pSSDConfig->DFlashSize = (uint32_t)FEATURE_FLS_DF_SIZE_0101;}
    else if (0x06U == DEPartitionCode) {pSSDConfig->DFlashSize = (uint32_t)FEATURE_FLS_DF_SIZE_0110;}
    else if (0x07U == DEPartitionCode) {pSSDConfig->DFlashSize = (uint32_t)FEATURE_FLS_DF_SIZE_0111;}
    else if (0x08U == DEPartitionCode) {pSSDConfig->DFlashSize = (uint32_t)FEATURE_FLS_DF_SIZE_1000;}
    else if (0x09U == DEPartitionCode) {pSSDConfig->DFlashSize = (uint32_t)FEATURE_FLS_DF_SIZE_1001;}
    else if (0x0AU == DEPartitionCode) {pSSDConfig->DFlashSize = (uint32_t)FEATURE_FLS_DF_SIZE_1010;}
    else if (0x0BU == DEPartitionCode) {pSSDConfig->DFlashSize = (uint32_t)FEATURE_FLS_DF_SIZE_1011;}
    else if (0x0CU == DEPartitionCode) {pSSDConfig->DFlashSize = (uint32_t)FEATURE_FLS_DF_SIZE_1100;}
    else if (0x0DU == DEPartitionCode) {pSSDConfig->DFlashSize = (uint32_t)FEATURE_FLS_DF_SIZE_1101;}
    else if (0x0EU == DEPartitionCode) {pSSDConfig->DFlashSize = (uint32_t)FEATURE_FLS_DF_SIZE_1110;}
    else if (0x0FU == DEPartitionCode) {pSSDConfig->DFlashSize = (uint32_t)FEATURE_FLS_DF_SIZE_1111;}
    else {/* Undefined value */}
}

#if (FEATURE_FLS_IS_FTFC == 0U)
/*FUNCTION**********************************************************************
 *
 * Function Name : FlashGetEEEDataSetSize
 * Description   : Gets EEPROM size from EEPROM Data Set Size.
 *
 * Implements    : FlashGetEEEDataSetSize_Activity
 *END**************************************************************************/
static void FlashGetEEEDataSetSize(flash_ssd_config_t * const pSSDConfig, \
                                   uint8_t EEEDataSetSize)
{
    /* Select EEPROM size */
    if      (0x00U == EEEDataSetSize) {pSSDConfig->EEESize = (uint32_t)FSL_FEATURE_FLS_EE_SIZE_0000;}
    else if (0x01U == EEEDataSetSize) {pSSDConfig->EEESize = (uint32_t)FSL_FEATURE_FLS_EE_SIZE_0001;}
    else if (0x02U == EEEDataSetSize) {pSSDConfig->EEESize = (uint32_t)FSL_FEATURE_FLS_EE_SIZE_0010;}
    else if (0x03U == EEEDataSetSize) {pSSDConfig->EEESize = (uint32_t)FSL_FEATURE_FLS_EE_SIZE_0011;}
    else if (0x04U == EEEDataSetSize) {pSSDConfig->EEESize = (uint32_t)FSL_FEATURE_FLS_EE_SIZE_0100;}
    else if (0x05U == EEEDataSetSize) {pSSDConfig->EEESize = (uint32_t)FSL_FEATURE_FLS_EE_SIZE_0101;}
    else if (0x06U == EEEDataSetSize) {pSSDConfig->EEESize = (uint32_t)FSL_FEATURE_FLS_EE_SIZE_0110;}
    else if (0x07U == EEEDataSetSize) {pSSDConfig->EEESize = (uint32_t)FSL_FEATURE_FLS_EE_SIZE_0111;}
    else if (0x08U == EEEDataSetSize) {pSSDConfig->EEESize = (uint32_t)FSL_FEATURE_FLS_EE_SIZE_1000;}
    else if (0x09U == EEEDataSetSize) {pSSDConfig->EEESize = (uint32_t)FSL_FEATURE_FLS_EE_SIZE_1001;}
    else if (0x0AU == EEEDataSetSize) {pSSDConfig->EEESize = (uint32_t)FSL_FEATURE_FLS_EE_SIZE_1010;}
    else if (0x0BU == EEEDataSetSize) {pSSDConfig->EEESize = (uint32_t)FSL_FEATURE_FLS_EE_SIZE_1011;}
    else if (0x0CU == EEEDataSetSize) {pSSDConfig->EEESize = (uint32_t)FSL_FEATURE_FLS_EE_SIZE_1100;}
    else if (0x0DU == EEEDataSetSize) {pSSDConfig->EEESize = (uint32_t)FSL_FEATURE_FLS_EE_SIZE_1101;}
    else if (0x0EU == EEEDataSetSize) {pSSDConfig->EEESize = (uint32_t)FSL_FEATURE_FLS_EE_SIZE_1110;}
    else if (0x0FU == EEEDataSetSize) {pSSDConfig->EEESize = (uint32_t)FSL_FEATURE_FLS_EE_SIZE_1111;}
    else {/* Undefined value */}
}
#endif

/*FUNCTION**********************************************************************
 *
 * Function Name : FlashInit
 * Description   : Initializes Flash module by clearing status error bit
 * and reporting the memory configuration via SSD configuration structure.
 *
 * Implements    : FlashInit_Activity
 *END**************************************************************************/
flash_drv_status_t FlashInit(const flash_user_config_t * const pUserConf, \
                             flash_ssd_config_t * const pSSDConfig)
{
#ifdef DEV_ERROR_DETECT
    DEV_ASSERT(pUserConf != NULL);
    DEV_ASSERT(pSSDConfig != NULL);
#endif
    flash_drv_status_t ret = FTFx_OK;
#if FSL_FEATURE_FLS_HAS_FLEX_NVM
    uint8_t  DEPartitionCode;    /* store D/E-Flash Partition Code */
#endif

    pSSDConfig->PFlashBase = pUserConf->PFlashBase;
    pSSDConfig->PFlashSize = pUserConf->PFlashSize;
    pSSDConfig->DFlashBase = pUserConf->DFlashBase;
    pSSDConfig->EERAMBase = pUserConf->EERAMBase;
    pSSDConfig->CallBack = pUserConf->CallBack;

#if FSL_FEATURE_FLS_HAS_FLEX_NVM
    /* Temporary solution for FTFC and S32K144 CSEc part */
    /* Get DEPART from Flash Configuration Register 1 */
    DEPartitionCode = (SIM->FCFG1 & SIM_FCFG1_DEPART_MASK) >> SIM_FCFG1_DEPART_SHIFT;
    /* Get data flash size */
    FlashGetDEPartitionCode(pSSDConfig, DEPartitionCode);
    if (pSSDConfig->DFlashSize < FSL_FEATURE_FLS_DF_BLOCK_SIZE)
    {
        pSSDConfig->EEESize = FSL_FEATURE_FLS_FLEX_RAM_SIZE;
    }
    else
    {
        pSSDConfig->EEESize = 0U;
    }
#else /* FSL_FEATURE_FLS_HAS_FLEX_NVM == 0 */
    /* If size of D/E-Flash = 0 */
    pSSDConfig->DFlashSize = 0U;
    pSSDConfig->EEESize = 0U;
#endif /* End of FSL_FEATURE_FLS_HAS_FLEX_NVM */

    return (ret);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FlashCommandSequence
 * Description   : Perform command write sequence on Flash.
 * It is internal function, called by driver APIs only.
 *
 * Implements    : FlashCommandSequence_Activity
 *END**************************************************************************/
START_FUNCTION_DEFINITION_RAMSECTION
flash_drv_status_t FlashCommandSequence(const flash_ssd_config_t * pSSDConfig)
{
#ifdef DEV_ERROR_DETECT
    DEV_ASSERT(pSSDConfig != NULL);
#endif
    flash_drv_status_t ret;    /* Return code variable */
    __asm("cpsid i");

    /* Clear CCIF to launch command */
    FTFx_FSTAT |= FTFx_FSTAT_CCIF_MASK;

    while (0U == (FTFx_FSTAT & FTFx_FSTAT_CCIF_MASK))
    {
        /* Wait till CCIF bit is set
         * Serve callback function if counter reaches limitation
         */
        if (NULL_CALLBACK != pSSDConfig->CallBack)
        {
            (pSSDConfig->CallBack)();
        }
    }

    ret = (flash_drv_status_t)(FTFx_FSTAT & (FTFx_FSTAT_MGSTAT0_MASK | FTFx_FSTAT_FPVIOL_MASK \
                               | FTFx_FSTAT_ACCERR_MASK | FTFx_FSTAT_RDCOLERR_MASK));

    __asm("cpsie i");

    return (ret);
}
END_FUNCTION_DEFINITION_RAMSECTION

/*FUNCTION**********************************************************************
 *
 * Function Name : PFlashGetProtection
 * Description   : Retrieves the current P-Flash protection status.
 * Considering the time consumption for getting protection is very low and
 * even can be ignored. It is not necessary to utilize the Callback function to
 * support the time-critical events.
 *
 * Implements    : PFlashGetProtection_Activity
 *END**************************************************************************/
void PFlashGetProtection(uint32_t* protectStatus)
{
#ifdef DEV_ERROR_DETECT
    DEV_ASSERT(protectStatus != NULL);
#endif
    uint32_t reg0, reg1, reg2, reg3;

    reg0 = FTFx_FPROT0;
    reg1 = FTFx_FPROT1;
    reg2 = FTFx_FPROT2;
    reg3 = FTFx_FPROT3;

    *protectStatus = (uint32_t)((reg0 << 24U) | (reg1 << 16U) | (reg2 << 8U) | reg3);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : PFlashSetProtection
 * Description   : Sets the P-Flash protection to the intended protection status.
 * Setting P-Flash protection status is subject to a protection transition
 * restriction. If there is a setting violation, it returns an error code
 * and the current protection status will not be changed.
 *
 * Implements    : PFlashSetProtection_Activity
 *END**************************************************************************/
flash_drv_status_t PFlashSetProtection(uint32_t protectStatus)
{
    flash_drv_status_t ret = FTFx_OK;
    uint8_t reg0, reg1, reg2, reg3;
    bool flag0, flag1, flag2, flag3;

    /* Get register */
    reg0 = GET_BIT_24_31(protectStatus);
    reg1 = GET_BIT_16_23(protectStatus);
    reg2 = GET_BIT_8_15(protectStatus);
    reg3 = GET_BIT_0_7(protectStatus);

    /* Write to register */
    FTFx_FPROT0 = reg0;
    FTFx_FPROT1 = reg1;
    FTFx_FPROT2 = reg2;
    FTFx_FPROT3 = reg3;

    /* Compare changes */
    flag0 = (FTFx_FPROT0 != reg0);
    flag1 = (FTFx_FPROT1 != reg1);
    flag2 = (FTFx_FPROT2 != reg2);
    flag3 = (FTFx_FPROT3 != reg3);

    /* Read the value of FPPROT registers */
    if (flag0 || flag1 || flag2 || flag3)
    {
        ret = FTFx_ERR_CHANGEPROT;
    }

    return (ret);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FlashGetSecurityState
 * Description   : Retrieves the current Flash security status, including
 * the security enabling state and the back door key enabling state.
 *
 * Implements    : FlashGetSecurityState_Activity
 *END**************************************************************************/
void FlashGetSecurityState(uint8_t* securityState)
{
#ifdef DEV_ERROR_DETECT
    DEV_ASSERT(securityState != NULL);
#endif
    /* Store data read from flash register */
    uint8_t  regValue;

    /* Get flash security register value */
    regValue = FTFx_FSEC;

    /* Check the status of the flash security bits in the security register */
    if (FLASH_SECURITY_STATE_UNSECURED == (regValue & FTFx_FSEC_SEC_MASK))
    {
        /* Flash in unsecured state */
        *securityState = FLASH_NOT_SECURE;
    }
    else
    {
        /* Flash in secured state
         * Check for backdoor key security enable bit
         */
        if (0x80U == (regValue & FTFx_FSEC_KEYEN_MASK))
        {
            /* Backdoor key security enabled */
            *securityState = FLASH_SECURE_BACKDOOR_ENABLED;
        }
        else
        {
            /* Backdoor key security disabled */
            *securityState = FLASH_SECURE_BACKDOOR_DISABLED;
        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FlashSecurityBypass
 * Description   : Un-secures the device by comparing the user's provided back
 * door key with the ones in the Flash Configuration Field. If they are
 * matched, the security is released. Otherwise, an error code is returned.
 *
 * Implements    : FlashSecurityBypass_Activity
 *END**************************************************************************/
flash_drv_status_t FlashSecurityBypass(const flash_ssd_config_t * pSSDConfig, \
                                       const uint8_t* keyBuffer, \
                                       flash_command_sequence_t pFlashCommandSequence)
{
#ifdef DEV_ERROR_DETECT
    DEV_ASSERT(pSSDConfig != NULL);
    DEV_ASSERT(keyBuffer != NULL);
    DEV_ASSERT(pFlashCommandSequence != NULL);
#endif
    flash_drv_status_t ret;    /* Return code variable */
    uint32_t temp;             /* Temporary variable */
    uint8_t i;

    /* Clear RDCOLERR & ACCERR & FPVIOL flag in flash status register. Write 1 to clear */
    CLEAR_FTFx_FSTAT_ERROR_BITS;

    /* Passing parameter to the command */
    FTFx_FCCOB0 = FTFx_SECURITY_BY_PASS;
    for (i = 0U; i < 8U; i++)
    {
        temp = FTFx_BASE + i + 0x08U;
        *(uint8_t *)temp = keyBuffer[i];
    }
    ret = pFlashCommandSequence(pSSDConfig);

    return (ret);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FlashEraseAllBlock
 * Description   : Erases all Flash memory, initializes the FlexRAM, verifies
 * all memory contents, and then releases the MCU security.
 *
 * Implements    : FlashEraseAllBlock_Activity
 *END**************************************************************************/
flash_drv_status_t FlashEraseAllBlock(const flash_ssd_config_t * pSSDConfig, \
                                      flash_command_sequence_t pFlashCommandSequence)
{
#ifdef DEV_ERROR_DETECT
    DEV_ASSERT(pSSDConfig != NULL);
    DEV_ASSERT(pFlashCommandSequence != NULL);
#endif
    flash_drv_status_t ret;    /* Return code variable */

    /* Clear RDCOLERR & ACCERR & FPVIOL flag in flash status register. Write 1 to clear */
    CLEAR_FTFx_FSTAT_ERROR_BITS;

    /* Passing parameter to the command */
    FTFx_FCCOB0 = FTFx_ERASE_ALL_BLOCK;

    /* Calling flash command sequence function to execute the command */
    ret = pFlashCommandSequence(pSSDConfig);

    return (ret);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FlashVerifyAllBlock
 * Description   : Checks to see if the P-Flash and/or D-Flash, EEPROM
 * backup area, and D-Flash IFR have been erased to the specified read
 * margin level, if applicable, and releases security if the readout passes.
 *
 * Implements    : FlashVerifyAllBlock_Activity
 *END**************************************************************************/
flash_drv_status_t FlashVerifyAllBlock(const flash_ssd_config_t * pSSDConfig, \
                                       uint8_t marginLevel, \
                                       flash_command_sequence_t pFlashCommandSequence)
{
#ifdef DEV_ERROR_DETECT
    DEV_ASSERT(pSSDConfig != NULL);
    DEV_ASSERT(pFlashCommandSequence != NULL);
#endif
    flash_drv_status_t ret;    /* Return code variable */

    /* Clear RDCOLERR & ACCERR & FPVIOL flag in flash status register. Write 1 to clear */
    CLEAR_FTFx_FSTAT_ERROR_BITS;

    /* Passing parameter to the command */
    FTFx_FCCOB0 = FTFx_VERIFY_ALL_BLOCK;
    FTFx_FCCOB1 = marginLevel;

    /* Calling flash command sequence function to execute the command */
    ret = pFlashCommandSequence(pSSDConfig);

    return (ret);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FlashEraseSector
 * Description   : Erases one or more sectors in P-Flash or D-Flash memory.
 * This API always returns FTFx_OK if size provided by the user is
 * zero regardless of the input validation.
 *
 * Implements    : FlashEraseSector_Activity
 *END**************************************************************************/
flash_drv_status_t FlashEraseSector(const flash_ssd_config_t * pSSDConfig, \
                                    uint32_t dest, \
                                    uint32_t size, \
                                    flash_command_sequence_t pFlashCommandSequence)
{
#ifdef DEV_ERROR_DETECT
    DEV_ASSERT(pSSDConfig != NULL);
    DEV_ASSERT(pFlashCommandSequence != NULL);
#endif
    flash_drv_status_t ret = FTFx_OK;    /* Return code variable */
    uint32_t sectorSize;                 /* Size of one sector   */
    uint32_t temp;                       /* Temporary variable   */
    uint32_t tempSize = size;            /* Temporary of size variation */


#if FEATURE_FLS_HAS_FLEX_NVM
    temp = pSSDConfig->DFlashBase;
    if ((dest >= temp) && (dest < (temp + pSSDConfig->DFlashSize)))
    {
        dest += 0x800000U - temp;
        sectorSize = (uint32_t)FEATURE_FLS_DF_BLOCK_SECTOR_SIZE;
    }
    else
#endif
    {
        temp = pSSDConfig->PFlashBase;
        if ((dest >= temp) && (dest < (temp + pSSDConfig->PFlashSize)))
        {
            dest -= temp;
            sectorSize = (uint32_t)FEATURE_FLS_PF_BLOCK_SECTOR_SIZE;
        }
        else
        {
            ret = FTFx_ERR_ACCERR;
            tempSize = 0U;
            sectorSize = 0U;
        }
    }

    /* check if the size is sector alignment or not */
    if ((tempSize & (sectorSize - 1U)) != 0U)
    {
        /* return an error code FTFx_ERR_SIZE */
        ret = FTFx_ERR_SIZE;
    }

    while ((tempSize > 0U) && (FTFx_OK == ret))
    {
        /* Clear RDCOLERR & ACCERR & FPVIOL flag in flash status register. Write 1 to clear */
        CLEAR_FTFx_FSTAT_ERROR_BITS;

        /* Passing parameter to the command */
        FTFx_FCCOB0 = FTFx_ERASE_SECTOR;
        FTFx_FCCOB1 = GET_BIT_16_23(dest);
        FTFx_FCCOB2 = GET_BIT_8_15(dest);
        FTFx_FCCOB3 = GET_BIT_0_7(dest);

        /* Calling flash command sequence function to execute the command */
        ret = pFlashCommandSequence(pSSDConfig);

        /* Update size and destination address */
        tempSize -= sectorSize;
        dest += sectorSize;
    }

    return (ret);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FlashVerifySection
 * Description   : Checks if a section of the P-Flash or the D-Flash memory
 * is erased to the specified read margin level.
 *
 * Implements    : FlashVerifySection_Activity
 *END**************************************************************************/
flash_drv_status_t FlashVerifySection(const flash_ssd_config_t * pSSDConfig, \
                                      uint32_t dest, \
                                      uint16_t number, \
                                      uint8_t marginLevel, \
                                      flash_command_sequence_t pFlashCommandSequence)
{
#ifdef DEV_ERROR_DETECT
    DEV_ASSERT(pSSDConfig != NULL);
    DEV_ASSERT(pFlashCommandSequence != NULL);
#endif
    flash_drv_status_t ret = FTFx_OK;    /* Return code variable */
    uint32_t temp;

    /* Check if the destination is aligned or not */
#if FSL_FEATURE_FLS_HAS_FLEX_NVM
    temp = pSSDConfig->DFlashBase;
    if ((dest >= temp) && (dest < (temp + pSSDConfig->DFlashSize)))
    {
        dest += 0x800000U - temp;
    }
    else
#endif
    {
        temp = pSSDConfig->PFlashBase;
        if ((dest >= temp) && (dest < (temp + pSSDConfig->PFlashSize)))
        {
            dest -= temp;
        }
        else
        {
            ret = FTFx_ERR_ACCERR;
        }
    }
    if (FTFx_OK == ret)
    {
        /* Clear RDCOLERR & ACCERR & FPVIOL flag in flash status register. Write 1 to clear */
        CLEAR_FTFx_FSTAT_ERROR_BITS;

        /* Passing parameter to the command */
        FTFx_FCCOB0 = FTFx_VERIFY_SECTION;
        FTFx_FCCOB1 = GET_BIT_16_23(dest);
        FTFx_FCCOB2 = GET_BIT_8_15(dest);
        FTFx_FCCOB3 = GET_BIT_0_7(dest);
        FTFx_FCCOB4 = GET_BIT_8_15(number);
        FTFx_FCCOB5 = GET_BIT_0_7(number);
        FTFx_FCCOB6 = marginLevel;

        /* Calling flash command sequence function to execute the command */
        ret = pFlashCommandSequence(pSSDConfig);
    }

    return (ret);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FlashEraseSuspend
 * Description   : Suspend a current operation of Flash erase sector command.
 * This function must be located in RAM memory or different Flash blocks which are
 * targeted for writing to avoid the RWW error.
 *
 * Implements    : FlashEraseSuspend_Activity
 *END**************************************************************************/
void FlashEraseSuspend(void)
{
    if ((FTFx_FSTAT & FTFx_FSTAT_CCIF_MASK) == 0U)
    {
        FTFx_FCNFG |= FTFx_FCNFG_ERSSUSP_MASK;

        while ((FTFx_FSTAT & FTFx_FSTAT_CCIF_MASK) == 0U)
        {
            /* Wait till CCIF bit is set */
        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FlashEraseResume
 * Description   : Resume a previous suspended operation of Flash erase sector command
 * This function must be located in RAM memory or different Flash blocks which are targeted
 * for writing to avoid RWW error.
 *
 * Implements    : FlashEraseResume_Activity
 *END**************************************************************************/
void FlashEraseResume(void)
{
    uint16_t i = 0U;    /* Counter variable */

    /* Check ERSSUSP bit of the flash configuration register */
    if ((FTFx_FCNFG & FTFx_FCNFG_ERSSUSP_MASK) == FTFx_FCNFG_ERSSUSP_MASK)
    {
        /* Clear CCIF to launch command */
        FTFx_FSTAT |= FTFx_FSTAT_CCIF_MASK;
        /* Wait for completion of this command */
        while ((0U == (FTFx_FSTAT & FTFx_FSTAT_CCIF_MASK)) || (i < RESUME_WAIT_CNT))
        {
            i++;
        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FlashReadOnce
 * Description   : Read out a reserved 64 byte field located in the P-Flash IFR via given number
 * of record. See the corresponding reference manual to get the correct value of this number.
 *
 * Implements    : FlashReadOnce_Activity
 *END**************************************************************************/
flash_drv_status_t FlashReadOnce(const flash_ssd_config_t * pSSDConfig, \
                                 uint8_t recordIndex, \
                                 uint8_t* pDataArray, \
                                 flash_command_sequence_t pFlashCommandSequence)
{
#ifdef DEV_ERROR_DETECT
    DEV_ASSERT(pSSDConfig != NULL);
    DEV_ASSERT(pDataArray != NULL);
    DEV_ASSERT(pFlashCommandSequence != NULL);
#endif
    flash_drv_status_t ret;    /* Return code variable */
    uint32_t temp;             /* Temporary variable */
    uint8_t i;

    /* Clear RDCOLERR & ACCERR & FPVIOL flag in flash status register. Write 1 to clear */
    CLEAR_FTFx_FSTAT_ERROR_BITS;

    /* Passing parameter to the command */
    FTFx_FCCOB0 = FTFx_READ_ONCE;
    FTFx_FCCOB1 = recordIndex;

    /* Calling flash command sequence function to execute the command */
    ret = pFlashCommandSequence(pSSDConfig);

    /* Checking for the success of command execution */
    if (FTFx_OK == ret)
    {
        /* Read the data from the FCCOB registers into the pDataArray */
        for (i = 0U; i < FEATURE_FLS_PF_BLOCK_WRITE_UNIT_SIZE; i++)
        {
            temp = FTFx_BASE + i + 0x08U;
            pDataArray[i] = *(uint8_t *)temp;
        }
    }

    return (ret);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FlashProgramOnce
 * Description   : Program to a reserved 64 byte field located in the
 * P-Flash IFR via given number of record. See the corresponding reference manual
 * to get correct value of this number.
 *
 * Implements    : FlashProgramOnce_Activity
 *END**************************************************************************/
flash_drv_status_t FlashProgramOnce(const flash_ssd_config_t * pSSDConfig, \
                                    uint8_t recordIndex, \
                                    const uint8_t* pDataArray, \
                                    flash_command_sequence_t pFlashCommandSequence)
{
#ifdef DEV_ERROR_DETECT
    DEV_ASSERT(pSSDConfig != NULL);
    DEV_ASSERT(pDataArray != NULL);
    DEV_ASSERT(pFlashCommandSequence != NULL);
#endif
    flash_drv_status_t ret;    /* Return code variable */
    uint32_t temp;             /* Temporary variable */
    uint8_t i;

    /* Clear RDCOLERR & ACCERR & FPVIOL flag in flash status register. Write 1 to clear */
    CLEAR_FTFx_FSTAT_ERROR_BITS;

    /* Passing parameter to the command */
    FTFx_FCCOB0 = FTFx_PROGRAM_ONCE;
    FTFx_FCCOB1 = recordIndex;

    for (i = 0U; i < FEATURE_FLS_PF_BLOCK_WRITE_UNIT_SIZE; i++)
    {
        temp = FTFx_BASE + i + 0x08U;
        *(uint8_t *)temp = pDataArray[i];
    }

    /* Calling flash command sequence function to execute the command */
    ret = pFlashCommandSequence(pSSDConfig);

    return (ret);
}

#if FSL_FEATURE_FLS_HAS_READ_RESOURCE_CMD
/*FUNCTION**********************************************************************
 *
 * Function Name : FlashReadResource
 * Description   : Read data from special purpose memory in Flash memory module
 * including P-Flash IFR, swap IFR, D-Flash IFR space and version ID.
 *
 * Implements    : FlashReadResource_Activity
 *END**************************************************************************/
flash_drv_status_t FlashReadResource(const flash_ssd_config_t * pSSDConfig, \
                                     uint32_t dest, \
                                     uint8_t* pDataArray, \
                                     uint8_t resourceSelectCode, \
                                     flash_command_sequence_t pFlashCommandSequence)
{
#ifdef DEV_ERROR_DETECT
    DEV_ASSERT(pSSDConfig != NULL);
    DEV_ASSERT(pDataArray != NULL);
    DEV_ASSERT(pFlashCommandSequence != NULL);
#endif
    flash_drv_status_t ret = FTFx_OK;    /* Return code variable */
    uint32_t temp;
    uint8_t i;

    /* Check if the destination is aligned or not */
#if FSL_FEATURE_FLS_HAS_FLEX_NVM
    temp = pSSDConfig->DFlashBase;
    if ((dest >= temp) && (dest < (temp + pSSDConfig->DFlashSize)))
    {
        dest += 0x800000U - temp;
    }
    else
#endif
    {
        temp = pSSDConfig->PFlashBase;
        if ((dest >= temp) && (dest < (temp + pSSDConfig->PFlashSize)))
        {
            dest -= temp;
        }
        else
        {
            ret = FTFx_ERR_ACCERR;
        }
    }
    if (ret == FTFx_OK)
    {
        /* Clear RDCOLERR & ACCERR & FPVIOL flag in flash status register. Write 1 to clear */
        CLEAR_FTFx_FSTAT_ERROR_BITS;
        /* Passing parameter to the command */
        FTFx_FCCOB0 = FTFx_READ_RESOURCE;
        FTFx_FCCOB1 = GET_BIT_16_23(dest);
        FTFx_FCCOB2 = GET_BIT_8_15(dest);
        FTFx_FCCOB3 = GET_BIT_0_7(dest);
        FTFx_RSRC_CODE_REG = resourceSelectCode;
        /* Calling flash command sequence function to execute the command */
        ret = pFlashCommandSequence(pSSDConfig);

        if (FTFx_OK == ret)
        {
            /* Read the data from the FCCOB registers into the pDataArray */
            for (i = 0U; i < FSL_FEATURE_FLS_PF_BLOCK_WRITE_UNIT_SIZE; i++)
            {
                temp = FTFx_BASE + i + 0x08U;
                pDataArray[i] = *(uint8_t*)temp;
            }
        }
    }

    return (ret);
}

#endif

/*FUNCTION**********************************************************************
 *
 * Function Name : FlashProgram
 * Description   : Program 4 consecutive bytes (for program long word command)
 * and 8 consecutive bytes (for program phrase command) on P-Flash or D-Flash block.
 * This API always returns FTFx_OK if size provided by user is
 * zero regardless of the input validation.
 *
 * Implements    : FlashProgram_Activity
 *END**************************************************************************/
flash_drv_status_t FlashProgram(const flash_ssd_config_t * pSSDConfig, \
                                uint32_t dest, \
                                uint32_t size, \
                                const uint8_t* pData, \
                                flash_command_sequence_t pFlashCommandSequence)
{
#ifdef DEV_ERROR_DETECT
    DEV_ASSERT(pSSDConfig != NULL);
    DEV_ASSERT(pData != NULL);
    DEV_ASSERT(pFlashCommandSequence != NULL);
#endif
    flash_drv_status_t ret = FTFx_OK;    /* Return code variable */
    uint32_t temp;
    uint8_t i;

    if ((size & (FEATURE_FLS_PF_BLOCK_WRITE_UNIT_SIZE - 1U)) != 0U)
    {
        ret = FTFx_ERR_SIZE;
    }
    else
    {
    #if FEATURE_FLS_HAS_FLEX_NVM
        temp = pSSDConfig->DFlashBase;
        if ((dest >= temp) && (dest < (temp + pSSDConfig->DFlashSize)))
        {
            dest += 0x800000U - temp;
        }
        else
    #endif
        {
            temp = pSSDConfig->PFlashBase;
            if ((dest >= temp) && (dest < (temp + pSSDConfig->PFlashSize)))
            {
                dest -= temp;
            }
            else
            {
                ret = FTFx_ERR_ACCERR;
            }
        }
        while ((size > 0U) && (FTFx_OK == ret))
        {
            /* Clear RDCOLERR & ACCERR & FPVIOL flag in flash status register. Write 1 to clear */
            CLEAR_FTFx_FSTAT_ERROR_BITS;

            /* Passing parameter to the command */
        #if (FEATURE_FLS_DF_BLOCK_WRITE_UNIT_SIZE == FTFx_PHRASE_SIZE)
            FTFx_FCCOB0 = FTFx_PROGRAM_PHRASE;
        #else
            FTFx_FCCOB0 = FTFx_PROGRAM_LONGWORD;
            //FTFx_FCCOB0 = FTFx_PROGRAM_PHRASE;
        #endif
            FTFx_FCCOB1 = GET_BIT_16_23(dest);
            FTFx_FCCOB2 = GET_BIT_8_15(dest);
            FTFx_FCCOB3 = GET_BIT_0_7(dest);

            for (i = 0U; i < FEATURE_FLS_PF_BLOCK_WRITE_UNIT_SIZE; i++)
            {
                temp = FTFx_BASE + i + 0x08U;
                *(uint8_t *)(temp) = pData[i];
            }

            /* Calling flash command sequence function to execute the command */
            ret = pFlashCommandSequence(pSSDConfig);

            /* Update destination address for next iteration */
            dest += FEATURE_FLS_PF_BLOCK_WRITE_UNIT_SIZE;
            /* Update size for next iteration */
            size -= FEATURE_FLS_PF_BLOCK_WRITE_UNIT_SIZE;
            /* Increment the source address by 1 */
            pData += FEATURE_FLS_PF_BLOCK_WRITE_UNIT_SIZE;
        }
    }

    return (ret);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FlashProgramCheck
 * Description   : Tests a previously programmed P-Flash or D-Flash long word
 * to see if it reads correctly at the specified margin level. This
 * API always returns FTFx_OK if size provided by user is zero
 * regardless of the input validation
 *
 * Implements    : FlashProgramCheck_Activity
 *END**************************************************************************/
flash_drv_status_t FlashProgramCheck(const flash_ssd_config_t * pSSDConfig, \
                                     uint32_t dest, \
                                     uint32_t size, \
                                     const uint8_t* pExpectedData, \
                                     uint32_t* pFailAddr, \
                                     uint8_t marginLevel, \
                                     flash_command_sequence_t pFlashCommandSequence)
{
#ifdef DEV_ERROR_DETECT
    DEV_ASSERT(pSSDConfig != NULL);
    DEV_ASSERT(pExpectedData != NULL);
    DEV_ASSERT(pFailAddr != NULL);
    DEV_ASSERT(pFlashCommandSequence != NULL);
#endif
    flash_drv_status_t ret = FTFx_OK;   /* Return code variable                                 */
    uint32_t offsetAddr ;               /* Offset address to convert to internal memory address */
    uint32_t temp;                      /* Temporary variable                                   */
    uint32_t tempSize = size;           /* Temporary of size variation */
    uint8_t i;

    if ((tempSize & (FEATURE_FLS_PF_CHECK_CMD_ADDRESS_ALIGMENT - 1U)) != 0U)
    {
        ret = FTFx_ERR_SIZE;
    }
    else
    {
        /* Check if the destination is aligned or not */
    #if FSL_FEATURE_FLS_HAS_FLEX_NVM
        offsetAddr = pSSDConfig->DFlashBase;
        if ((dest >= offsetAddr) && (dest < (offsetAddr + pSSDConfig->DFlashSize)))
        {
            dest += 0x800000U - offsetAddr;
        }
        else
    #endif
        {
            offsetAddr = pSSDConfig->PFlashBase;
            if ((dest >= offsetAddr) && (dest < (offsetAddr + pSSDConfig->PFlashSize)))
            {
                dest -= offsetAddr;
            }
            else
            {
                ret = FTFx_ERR_ACCERR;
                tempSize = 0U;
            }
        }
        while (tempSize > 0U)
        {
            /* Clear RDCOLERR & ACCERR & FPVIOL flag in flash status register. Write 1 to clear */
            CLEAR_FTFx_FSTAT_ERROR_BITS;

            /* Passing parameter to the command */
            FTFx_FCCOB0 = FTFx_PROGRAM_CHECK;
            FTFx_FCCOB1 = GET_BIT_16_23(dest);
            FTFx_FCCOB2 = GET_BIT_8_15(dest);
            FTFx_FCCOB3 = GET_BIT_0_7(dest);
            FTFx_FCCOB4 = marginLevel;

            for (i = 0U; i < FEATURE_FLS_PF_CHECK_CMD_ADDRESS_ALIGMENT; i++)
            {
                temp = FTFx_BASE + i + 0x0CU;
                *(uint8_t *)(temp) = pExpectedData[i];
            }

            /* Calling flash command sequence function to execute the command */
            ret = pFlashCommandSequence(pSSDConfig);

            /* Checking for the success of command execution */
            if (FTFx_OK != ret)
            {
            #if FSL_FEATURE_FLS_HAS_FLEX_NVM
                if (dest >= 0x800000U)
                {
                    *pFailAddr = dest + offsetAddr - 0x800000U;
                }
                else
            #endif
                {
                    *pFailAddr = dest + offsetAddr;
                }
                tempSize = FEATURE_FLS_PF_CHECK_CMD_ADDRESS_ALIGMENT;
            }
            /* Update size for next iteration */
            tempSize -= FEATURE_FLS_PF_CHECK_CMD_ADDRESS_ALIGMENT;
            /* Increment the source address by 1 */
            pExpectedData += FEATURE_FLS_PF_CHECK_CMD_ADDRESS_ALIGMENT;
            /* Update destination address for next iteration */
            dest += FEATURE_FLS_PF_CHECK_CMD_ADDRESS_ALIGMENT;
        }
    }

    return (ret);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FlashCheckSum
 * Description   : Performs 32 bit sum of each byte data over a specified Flash
 * memory range without carry which provides rapid method for checking data integrity.
 * The callback time period of this API is determined via FLASH_CALLBACK_CS macro in the
 * SSD_FTFx_Common.h which is used as a counter value for the CallBack() function calling in
 * this API. This value can be changed as per the user requirement. User can change this value
 * to obtain the maximum permissible callback time period.
 * This API always returns FTFx_OK if size provided by user is zero regardless of the input
 * validation.
 *
 * Implements    : FlashCheckSum_Activity
 *END**************************************************************************/
flash_drv_status_t FlashCheckSum(const flash_ssd_config_t * pSSDConfig, \
                                 uint32_t dest, \
                                 uint32_t size, \
                                 uint32_t* pSum)
{
#ifdef DEV_ERROR_DETECT
    DEV_ASSERT(pSSDConfig != NULL);
    DEV_ASSERT(pSum != NULL);
#endif
    flash_drv_status_t ret = FTFx_OK;   /* Return code variable           */
    uint32_t counter = 0U;              /* Counter for callback operation */
    uint32_t data;                      /* Data read from Flash address   */
    uint32_t endAddress;                /* PFlash end address             */
    uint32_t tempSize = size;           /* Temporary of size variation    */

    /* Calculating Flash end address */
    endAddress = dest + tempSize;

    /* Check for valid range of the target addresses */
    if ((dest < pSSDConfig->PFlashBase) || (endAddress > (pSSDConfig->PFlashBase + pSSDConfig->PFlashSize)))
    {
    #if FSL_FEATURE_FLS_HAS_FLEX_NVM
        if ((dest < pSSDConfig->DFlashBase) || (endAddress > (pSSDConfig->DFlashBase + pSSDConfig->DFlashSize)))
        {
    #endif
            ret = FTFx_ERR_RANGE;
            tempSize = 0U;
    #if FSL_FEATURE_FLS_HAS_FLEX_NVM
        }
    #endif /* End of if FSL_FEATURE_FLS_HAS_FLEX_NVM */
    }
    *pSum = 0U;
    /* Doing sum operation */
    while (tempSize > 0U)
    {
        data = *(uint8_t *)(dest);
        *pSum += data;
        dest += 1U;
        tempSize -= 1U;
        ++counter;

        /* Check if need to serve callback function */
        if (counter >= FLASH_CALLBACK_CS)
        {
            /* Serve callback function if counter reaches limitation */
            if (NULL_CALLBACK != pSSDConfig->CallBack)
            {
                pSSDConfig->CallBack();
            }
            /* Reset counter */
            counter = 0U;
        }
    }

    return (ret);
}

#if FSL_FEATURE_FLS_HAS_PROGRAM_SECTION_CMD
/*FUNCTION**********************************************************************
 *
 * Function Name : FlashProgramSection
 * Description   : Program the data found in the Section Program Buffer
 * to previously erased locations in the Flash memory. Data is preloaded into
 * the Section Program Buffer by writing to the acceleration Ram and FlexRam
 * while it is set to function as a RAM. The Section Program Buffer is limited
 * to the value of FlexRam divides by a ratio. Refer to the associate reference
 * manual to get correct value of this ratio.
 * For derivatives including swap feature, the swap indicator address is encountered
 * during FlashProgramSection, it is bypassed without setting FPVIOL but the content
 * are not be programmed. In addition, the content of source data used to program to
 * swap indicator will be re-initialized to 0xFF after completion of this command.
 *
 * Implements    : FlashProgramSection_Activity
 *END**************************************************************************/
flash_drv_status_t FlashProgramSection(const flash_ssd_config_t * pSSDConfig, \
                                       uint32_t dest, \
                                       uint16_t number, \
                                       flash_command_sequence_t pFlashCommandSequence)
{
#ifdef DEV_ERROR_DETECT
    DEV_ASSERT(pSSDConfig != NULL);
    DEV_ASSERT(pFlashCommandSequence != NULL);
#endif
    flash_drv_status_t ret = FTFx_OK;    /* Return code variable */
    uint32_t temp;

    /* Check RAMRDY bit of the flash configuration register */
    if (0U == (FTFx_FCNFG & FTFx_FCNFG_RAMRDY_MASK))
    {
        /* Return an error code FTFx_ERR_RAMRDY */
        ret = FTFx_ERR_RAMRDY;
    }
    else
    {
    #if FSL_FEATURE_FLS_HAS_FLEX_NVM
        temp = pSSDConfig->DFlashBase;
        if ((dest >= temp) && (dest < (temp + pSSDConfig->DFlashSize)))
        {
            dest += 0x800000U - temp;
        }
        else
    #endif
        {
            temp = pSSDConfig->PFlashBase;
            if ((dest >= temp) && (dest < (temp + pSSDConfig->PFlashSize)))
            {
                dest -= temp;
            }
            else
            {
                ret = FTFx_ERR_ACCERR;
            }
        }

        if (ret == FTFx_OK)
        {
            /* Clear RDCOLERR & ACCERR & FPVIOL flag in flash status register.
             * Write 1 to clear
             */
            CLEAR_FTFx_FSTAT_ERROR_BITS;
            /* Passing parameter to command */
            FTFx_FCCOB0 = FTFx_PROGRAM_SECTION;
            FTFx_FCCOB1 = GET_BIT_16_23(dest);
            FTFx_FCCOB2 = GET_BIT_8_15(dest);
            FTFx_FCCOB3 = GET_BIT_0_7(dest);
            FTFx_FCCOB4 = GET_BIT_8_15(number);
            FTFx_FCCOB5 = GET_BIT_0_7(number);

            /* Calling flash command sequence function to execute the command */
            ret = pFlashCommandSequence(pSSDConfig);
        }
    }

    return (ret);
}

#endif

#if FSL_FEATURE_FLS_HAS_ERASE_BLOCK_CMD
/*FUNCTION**********************************************************************
 *
 * Function Name : FlashEraseBlock
 * Description   : Erases all addresses in an individual P-Flash or D-Flash block.
 * For the derivatives including multiply logical P-Flash or D-Flash blocks,
 * this API erases a single block in a single call.
 *
 * Implements    : FlashEraseBlock_Activity
 *END**************************************************************************/
flash_drv_status_t FlashEraseBlock (const flash_ssd_config_t * pSSDConfig, \
                                    uint32_t dest, \
                                    flash_command_sequence_t pFlashCommandSequence)
{
#ifdef DEV_ERROR_DETECT
    DEV_ASSERT(pSSDConfig != NULL);
    DEV_ASSERT(pFlashCommandSequence != NULL);
#endif
    flash_drv_status_t ret = FTFx_OK;    /* Return code variable */
    uint32_t temp;                       /* Temporary variable   */

    /* Check if the destination is aligned or not */
#if FSL_FEATURE_FLS_HAS_FLEX_NVM
    temp = pSSDConfig->DFlashBase;
    if ((dest >= temp) && (dest < (temp + pSSDConfig->DFlashSize)))
    {
        dest += 0x800000U - temp;
    }
    else
#endif
    {
        temp = pSSDConfig->PFlashBase;
        if ((dest >= temp) && (dest < (temp + pSSDConfig->PFlashSize)))
        {
            dest -= temp;
        }
        else
        {
            ret = FTFx_ERR_ACCERR;
        }
    }

    if (FTFx_OK == ret)
    {
        /* Clear RDCOLERR & ACCERR & FPVIOL flag in flash status register. Write 1 to clear */
        CLEAR_FTFx_FSTAT_ERROR_BITS;

        /* Passing parameter to the command */
        FTFx_FCCOB0 = FTFx_ERASE_BLOCK;
        FTFx_FCCOB1 = GET_BIT_16_23(dest);
        FTFx_FCCOB2 = GET_BIT_8_15(dest);
        FTFx_FCCOB3 = GET_BIT_0_7(dest);

        /* Calling flash command sequence function to execute the command */
        ret = pFlashCommandSequence(pSSDConfig);
    }

    return (ret);
}
#endif

#ifdef FSL_FEATURE_FLASH_HAS_READ_1S_BLOCK_CMD
/*FUNCTION**********************************************************************
 *
 * Function Name : FlashVerifyBlock
 * Description   : Checks to see if an entire P-Flash or D-Flash block has been
 * erased to the specified margin level. For the derivatives including multiply
 * logical P-Flash or D-Flash blocks, this API erases a single block in a single call.
 *
 * Implements    : FlashVerifyBlock_Activity
 *END**************************************************************************/
flash_drv_status_t FlashVerifyBlock(const flash_ssd_config_t * pSSDConfig, \
                                    uint32_t dest, \
                                    uint8_t marginLevel, \
                                    flash_command_sequence_t pFlashCommandSequence)
{
#ifdef DEV_ERROR_DETECT
    DEV_ASSERT(pSSDConfig != NULL);
    DEV_ASSERT(pFlashCommandSequence != NULL);
#endif
    flash_drv_status_t ret = FTFx_OK;    /* Return code variable */
    uint32_t temp;

    /* Check if the destination is aligned or not */
#if FSL_FEATURE_FLS_HAS_FLEX_NVM
    temp = pSSDConfig->DFlashBase;
    if ((dest >= temp) && (dest < (temp + pSSDConfig->DFlashSize)))
    {
        dest += 0x800000U - temp;
    }
    else
#endif
    {
        temp = pSSDConfig->PFlashBase;
        if ((dest >= temp) && (dest < (temp + pSSDConfig->PFlashSize)))
        {
            dest -= temp;
        }
        else
        {
            ret = FTFx_ERR_ACCERR;
        }
    }
    if (FTFx_OK == ret)
    {
        /* Clear RDCOLERR & ACCERR & FPVIOL flag in flash status register. Write 1 to clear */
        CLEAR_FTFx_FSTAT_ERROR_BITS;

        /* Passing parameter to the command */
        FTFx_FCCOB0 = FTFx_VERIFY_BLOCK;
        FTFx_FCCOB1 = GET_BIT_16_23(dest);
        FTFx_FCCOB2 = GET_BIT_8_15(dest);
        FTFx_FCCOB3 = GET_BIT_0_7(dest);
        FTFx_FCCOB4 = marginLevel;

        /* Calling flash command sequence function to execute the command */
        ret = pFlashCommandSequence(pSSDConfig);
    }

    return (ret);
}
#endif

#if FSL_FEATURE_FLS_HAS_FLEX_NVM
/*FUNCTION**********************************************************************
 *
 * Function Name : EERAMGetProtection
 * Description   : Retrieves which EEPROM sections of FlexRAM are protected
 * against program and erase operations. Considering the time consumption
 * for getting protection is very low and even can be ignored, it is not necessary
 * to utilize the Callback function to support the time-critical events
 *
 * Implements    : EERAMGetProtection_Activity
 *END**************************************************************************/
flash_drv_status_t EERAMGetProtection(uint8_t* protectStatus)
{
#ifdef DEV_ERROR_DETECT
    DEV_ASSERT(protectStatus != NULL);
#endif
    flash_drv_status_t ret = FTFx_OK;    /* Return code variable */

    /* Check if EERAM is set for EEPROM */
    if ((FTFx_FCNFG & FTFx_FCNFG_EEERDY_MASK) == FTFx_FCNFG_EEERDY_MASK)
    {
        *protectStatus = FTFx_FEPROT;
    }
    else
    {
        ret = FTFx_ERR_NOEEE;
    }

    return (ret);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : EERAMSetProtection
 * Description   : Sets protection to the intended protection status for EEPROM us
 * area of FlexRam. This is subject to a protection transition restriction.
 * If there is a setting violation, it returns failed information and
 * the current protection status will not be changed.
 *
 * Implements    : EERAMSetProtection_Activity
 *END**************************************************************************/
flash_drv_status_t EERAMSetProtection(uint8_t protectStatus)
{
    flash_drv_status_t ret = FTFx_OK;    /* Return code variable */

    /* Check if FlexRAM is set for EEPROM */
    if (0U == (FTFx_FCNFG & FTFx_FCNFG_EEERDY_MASK))
    {
        /* FlexRAM is not set for EEPROM */
        ret = FTFx_ERR_NOEEE;
    }
    else
    {
        FTFx_FEPROT = protectStatus;
        if (protectStatus != FTFx_FEPROT)
        {
            ret = FTFx_ERR_CHANGEPROT;
        }
        else
        {
            /* Do nothing */
        }
    }

    return (ret);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : SetFlexRamFunction
 * Description   : This function is used to change the function of the FlexRAM. When not partitioned for
 * emulated EEPROM, the FlexRAM is typically used as traditional RAM.
 * Otherwise, the FlexRam is typically used to store EEPROM data, the writing to EEPROM is normal write or
 * quick write.
 * In addition, this function may be used to get EEPROM status or complete interrupted EEPROM quick write process.
 * For example, after partitioning to have EEPROM backup, FlexRAM is used for EEPROM
 * use accordingly and if want to change FlexRAM to traditional RAM for FlashProgramSection() use, call this API
 * with the function control code is 0xFFU.
 *
 * Implements    : SetFlexRamFunction_Activity
 *END**************************************************************************/
flash_drv_status_t SetFlexRamFunction(const flash_ssd_config_t * pSSDConfig, \
                                      flash_flexRam_function_control_code_t flexRamFuncCode, \
                                      uint16_t byteOfQuickWrite, \
                                      flash_eeprom_status_t * const pEEPROMStatus, \
                                      flash_command_sequence_t pFlashCommandSequence)
{
#ifdef DEV_ERROR_DETECT
    DEV_ASSERT(pSSDConfig != NULL);
    DEV_ASSERT(pFlashCommandSequence != NULL);
#endif
    flash_drv_status_t ret;    /* Return code variable */

    /* Clear RDCOLERR & ACCERR & FPVIOL flag in flash status register. Write 1 to clear */
    CLEAR_FTFx_FSTAT_ERROR_BITS;

    /* Passing parameter to the command */
    FTFx_FCCOB0 = FTFx_SET_EERAM;
    FTFx_FCCOB1 = (uint8_t)flexRamFuncCode;

    if (flexRamFuncCode == EEE_QUICK_WRITE)
    {
        FTFx_FCCOB4 = (uint8_t)(byteOfQuickWrite >> 0x8U);
        FTFx_FCCOB5 = (uint8_t)(byteOfQuickWrite & 0xFFU);
    }

    /* Calling flash command sequence function to execute the command */
    ret = pFlashCommandSequence(pSSDConfig);

    if ((flexRamFuncCode == EEE_STATUS_QUERY) && (ret == FTFx_OK))
    {
        if (pEEPROMStatus == NULL)
        {
            ret = FTFx_ERR_PARAM;
        }
        else
        {
            pEEPROMStatus->brownOutCode = FTFx_FCCOB5;
            pEEPROMStatus->sectorEraseCount = (uint16_t)FTFx_FCCOB8 << 8U;
            pEEPROMStatus->sectorEraseCount |= (uint16_t)FTFx_FCCOB9;
            pEEPROMStatus->numOfRecordReqMaintain = (uint16_t)FTFx_FCCOB6 << 8U;
            pEEPROMStatus->numOfRecordReqMaintain |= (uint16_t)FTFx_FCCOB7;
        }
    }

    return (ret);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : WaitEEWriteToFinish
 * Description   : Write to EEPROM with data was aligned and wait until operation finish.
 *
 * Implements    : WaitEEWriteToFinish_Activity
 *END**************************************************************************/
static flash_drv_status_t WaitEEWriteToFinish(uint32_t dest, \
                                              const uint8_t* pData, \
                                              uint8_t step)
{
#ifdef DEV_ERROR_DETECT
    DEV_ASSERT(pData != NULL);
#endif
    flash_drv_status_t ret;    /* Return code variable */
    uint32_t temp;             /* Temporary variable   */

    if (0x01U == step)
    {
        *(uint8_t*)dest = *pData;
    }
    if (0x02U == step)
    {
        temp = (uint32_t)(pData[1]) << 8U;
        temp |= (uint32_t)(pData[0]);
        *(volatile uint16_t *)dest = (uint16_t)temp;
    }
    if (0x04U == step)
    {
        temp =  (uint32_t)(pData[3]) << 24U;
        temp |= (uint32_t)(pData[2]) << 16U;
        temp |= (uint32_t)(pData[1]) << 8U;
        temp |= (uint32_t)(pData[0]);
        *(volatile uint32_t *)dest = temp;
    }

    while (0U == (FTFx_FCNFG & FTFx_FCNFG_EEERDY_MASK))
    {
        /* Wait till EEERDY bit is set */
    }
    /* Check for protection violation error */
    ret = (flash_drv_status_t)(FTFx_FSTAT & (FTFx_FSTAT_MGSTAT0_MASK | FTFx_FSTAT_FPVIOL_MASK \
                               | FTFx_FSTAT_ACCERR_MASK | FTFx_FSTAT_RDCOLERR_MASK));

    return ret;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : EEEWrite
 * Description   : Write data to FlexRAM section which is partitioned
 * as EEPROM use for EEPROM operation. After data has been written to EEPROM
 * use section of FlexRAM, the EEPROM file system will create new data record
 * in EEPROM back-up area of FlexNVM in round-robin fashion.
 * There is no alignment constraint for destination and size parameters
 * provided by user. However, according to user's input provided, this
 * API will set priority to write to FlexRAM with following rules:
 * 32-bit writing is invoked if destination is 32 bit aligned and size
 * is not less than 32 bits.
 * 16-bit writing is invoked if destination is 16 bit aligned and size
 * is not less than 16 bits.
 * 8-bit writing is invoked if destination is 8 bit aligned and size
 * is not less than 8 bits.
 *
 * Implements    : EEEWrite_Activity
 *END**************************************************************************/
flash_drv_status_t EEEWrite(const flash_ssd_config_t * pSSDConfig, \
                            uint32_t dest, \
                            uint32_t size, \
                            const uint8_t* pData)
{
#ifdef DEV_ERROR_DETECT
    DEV_ASSERT(pSSDConfig != NULL);
    DEV_ASSERT(pData != NULL);
#endif
    flash_drv_status_t ret = FTFx_OK;    /* Return code variable */
    uint8_t i;

    /* Check if EEE is enabled */
    if ((FTFx_FCNFG & FTFx_FCNFG_EEERDY_MASK) == FTFx_FCNFG_EEERDY_MASK)
    {
        /* Check range */
        if ((dest < pSSDConfig->EERAMBase) || \
                ((dest + size) > (pSSDConfig->EERAMBase + pSSDConfig->EEESize)))
        {
            ret = FTFx_ERR_RANGE;
        }

        while ((size > 0U) && (ret == FTFx_OK))
        {
            /* Dest is 32bit-aligned and size is not less than 4 */
            if ((0U == (dest & 3U)) && (size >= 4U))
            {
                i = 4U;
            }
            else if ((0U == (dest & 1U)) && (size >= 2U))
            {
                i = 2U;
            }
            else
            {
                i = 1U;
            }
            ret = WaitEEWriteToFinish(dest, pData, i);
            /* Update destination address for next iteration */
            dest += i;
            /* Update size for next iteration */
            size -= i;
            /* Update data for next iteration */
            pData += i;
        }
    }
    else
    {
        ret = FTFx_ERR_NOEEE;
    }

    return (ret);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : DEFlashPartition
 * Description   : Prepares the FlexNVM block for use as D-Flash, EEPROM backup, or a combination
 * of both and initializes the FlexRAM.
 * The single partition choice should be used through entire life time of a given
 * application to guarantee the Flash endurance and data retention of Flash module.
 *
 * Implements    : DEFlashPartition_Activity
 *END**************************************************************************/
flash_drv_status_t DEFlashPartition(const flash_ssd_config_t * pSSDConfig, \
                                    uint8_t uEEEDataSizeCode, \
                                    uint8_t uDEPartitionCode, \
                                    uint8_t uCSEcKeySize,     \
                                    bool uSFE,             \
                                    flash_command_sequence_t pFlashCommandSequence)
{
#ifdef DEV_ERROR_DETECT
    DEV_ASSERT(pSSDConfig != NULL);
    DEV_ASSERT(pFlashCommandSequence != NULL);
    DEV_ASSERT(uCSEcKeySize <= CSE_KEY_SIZE_CODE_MAX);
#endif
    flash_drv_status_t ret;    /* Return code variable */

    /* Clear RDCOLERR & ACCERR & FPVIOL & MGSTAT0 flag in flash status register. Write 1 to clear */
    CLEAR_FTFx_FSTAT_ERROR_BITS;

    /* Passing parameter to the command */
    FTFx_FCCOB0 = FTFx_PROGRAM_PARTITION;
    FTFx_FCCOB1 = uCSEcKeySize;
    FTFx_FCCOB2 = (uSFE ? 1U : 0U);
    FTFx_FCCOB4 = uEEEDataSizeCode;
    FTFx_FCCOB5 = uDEPartitionCode;

    /* Calling flash command sequence function to execute the command */
    ret = pFlashCommandSequence(pSSDConfig);

    return (ret);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : DFlashGetProtection
 * Description   : Retrieves current P-Flash protection status. Considering the time consumption
 * for getting protection is very low and even can be ignored, it is not necessary to utilize
 * the Callback function to support the time-critical events.
 *
 * Implements    : DFlashGetProtection_Activity
 *END**************************************************************************/
flash_drv_status_t DFlashGetProtection(const flash_ssd_config_t * pSSDConfig, \
                                       uint8_t* protectStatus)
{
#ifdef DEV_ERROR_DETECT
    DEV_ASSERT(pSSDConfig != NULL);
    DEV_ASSERT(protectStatus != NULL);
#endif
    flash_drv_status_t ret = FTFx_OK;    /* Return code variable */

    /* Check if size of DFlash = 0 */
    if (pSSDConfig->DFlashSize == 0U)
    {
        ret = FTFx_ERR_EFLASHONLY;
    }
    else
    {
        *protectStatus = FTFx_FDPROT;
    }

    return (ret);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : DFlashSetProtection
 * Description   : Sets the D-Flash protection to the intended protection status.
 * Setting D-Flash protection status is subject to a protection transition restriction.
 * If there is a setting violation, it returns failed information
 * and the current protection status will not be changed.
 *
 * Implements    : DFlashSetProtection_Activity
 *END**************************************************************************/
flash_drv_status_t DFlashSetProtection(const flash_ssd_config_t * pSSDConfig, \
                                       uint8_t protectStatus)
{
#ifdef DEV_ERROR_DETECT
    DEV_ASSERT(pSSDConfig != NULL);
#endif
    flash_drv_status_t ret = FTFx_OK;    /* Return code variable */

    /* Check if size of DFlash = 0 */
    if (pSSDConfig->DFlashSize == 0U)
    {
        ret = FTFx_ERR_EFLASHONLY;
    }
    else
    {
        FTFx_FDPROT = protectStatus;
        if ( protectStatus != FTFx_FDPROT)
        {
            ret = FTFx_ERR_CHANGEPROT;
        }
        else
        {
            /* Do nothing */
        }
    }

    return (ret);
}
#endif /* End of FSL_FEATURE_FLS_HAS_FLEX_NVM */

#ifdef FSL_FEATURE_FLASH_HAS_PFLASH_BLOCK_SWAP
/*FUNCTION**********************************************************************
 *
 * Function Name : PFlashSwap
 * Description   : Provides to user with an ability to interfere in a swap progress by letting the
 * user code know about the swap state in each phase of the process. This is done via pSwapCallBack()
 * parameter. To stop at each intermediate swap state, set the return value of
 * this callback function to FALSE. To complete swap process within a single call,
 * set the return value of this function to TRUE.
 *
 * Erase the non-active swap indicator somewhere in the application code
 * or in the swap call back function when swap system is in UPDATE state.
 *
 * In addition, if user does not want to use the swap call back parameter, pass the NULL_SWAP_CALLBACK
 * as a null pointer. In this situation, the PFlashSwap() behaves in the same way as setting the return
 * value of pSwapCallBack to TRUE and the user does not need to erase the non-active swap
 * indicator when the swap system is in UPDATE state.
 * The swap indicator provided by the user must be within the lower half of P-Flash block but not in the
 * Flash configuration area. If P-Flash block has two logical blocks, the swap indicator must be
 * in P-Flash block 0. If the P-Flash block has four logical blocks, the swap indicator can be in block
 * 0 or block 1. It must not be in the Flash configuration field.
 * The user must use the same swap indicator for all swap control code except report swap status once
 * swap system has been initialized. To refresh swap system to un-initialization state,
 * use the FlashEraseAllBlock() to clean up the swap environment.
 *
 * Implements    : PFlashSwap_Activity
 *END**************************************************************************/
flash_drv_status_t PFlashSwap(const flash_ssd_config_t * pSSDConfig, \
                              uint32_t addr, \
                              flash_swap_callback_t pSwapCallback, \
                              flash_command_sequence_t pFlashCommandSequence)
{
#ifdef DEV_ERROR_DETECT
    DEV_ASSERT(pSSDConfig != NULL);
    DEV_ASSERT(pSwapCallback != NULL);
    DEV_ASSERT(pFlashCommandSequence != NULL);
#endif
    flash_drv_status_t ret = FTFx_OK;    /* Return code variable */
    uint8_t currentSwapMode, currentSwapBlockStatus, nextSwapBlockStatus;
    bool swapContinue;
    currentSwapMode = 0xFFU;
    currentSwapBlockStatus = 0xFFU;
    nextSwapBlockStatus = 0xFFU;
    swapContinue = false;

    /* Report current swap state */
    ret = PFlashSwapCtl(pSSDConfig, addr, FTFx_SWAP_REPORT_STATUS, &currentSwapMode, \
                        &currentSwapBlockStatus, &nextSwapBlockStatus, pFlashCommandSequence);

    if (FTFx_OK == ret)
    {
        if ((FTFx_SWAP_UNINIT == currentSwapMode) || (FTFx_SWAP_READY == currentSwapMode) || \
                (FTFx_SWAP_UPDATE == currentSwapMode))
        {
            /* If current swap mode is Uninitialized */
            if (FTFx_SWAP_UNINIT == currentSwapMode)
            {
                /* Initialize Swap to Initialized/READY state */
                ret = PFlashSwapCtl(pSSDConfig, addr, FTFx_SWAP_SET_INDICATOR_ADDR, &currentSwapMode, \
                                    &currentSwapBlockStatus, &nextSwapBlockStatus, pFlashCommandSequence);
            }
            /* If current swap mode is Initialized/Ready */
            else if (FTFx_SWAP_READY == currentSwapMode)
            {
                /* Initialize Swap to UPDATE state */
                ret = PFlashSwapCtl(pSSDConfig, addr, FTFx_SWAP_SET_IN_PREPARE, &currentSwapMode, \
                                    &currentSwapBlockStatus, &nextSwapBlockStatus, pFlashCommandSequence);
            }
            else
            {
                /* if (FTFx_SWAP_UPDATE == currentSwapMode) do nothing */
            }

            /* Check for the success of command execution
             * Report the current swap state to user via callback
             */
            if ((NULL_SWAP_CALLBACK != pSwapCallback) && (FTFx_OK == ret))
            {
                swapContinue = pSwapCallback(currentSwapMode);

                if (swapContinue == true)
                {
                    /* Report current swap state */
                    ret = PFlashSwapCtl(pSSDConfig, addr, FTFx_SWAP_REPORT_STATUS, &currentSwapMode, \
                                        &currentSwapBlockStatus, &nextSwapBlockStatus, pFlashCommandSequence);
                }
            }
        }
        else
        {
            /* Do nothing */
        }
        if ((NULL_SWAP_CALLBACK == pSwapCallback) && (FTFx_SWAP_UPDATE == currentSwapMode))
        {
            /* Erase indicator sector in non active block to proceed swap system to update-erased state */
            ret = FlashEraseSector(pSSDConfig, addr + (pSSDConfig->PFlashSize >> 1U), \
                                   (uint32_t)FSL_FEATURE_FLS_PF_BLOCK_SECTOR_SIZE, \
                                   pFlashCommandSequence);
            if (FTFx_OK == ret)
            {
                /* Now the swap state must be Update-Erased, so report current swap state */
                ret = PFlashSwapCtl(pSSDConfig, addr, FTFx_SWAP_REPORT_STATUS, &currentSwapMode, \
                                    &currentSwapBlockStatus, &nextSwapBlockStatus, pFlashCommandSequence);
            }
        }
        /* If current swap mode is Update or Update-Erased */
        if (FTFx_SWAP_UPDATE_ERASED == currentSwapMode)
        {
            if (NULL_SWAP_CALLBACK == pSwapCallback)
            {
                swapContinue = true;
            }
            else
            {
                swapContinue = pSwapCallback(currentSwapMode);
            }

            if (swapContinue == true)
            {
                /* Progress Swap to COMPLETE State */
                ret = PFlashSwapCtl(pSSDConfig, addr, FTFx_SWAP_SET_IN_COMPLETE, &currentSwapMode, \
                                    &currentSwapBlockStatus, &nextSwapBlockStatus, pFlashCommandSequence);
            }
        }
    }

    return (ret);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : PFlashSwapCtl
 * Description   : Performs swap control command corresponding with the swap
 * control code provided via the swapcmd parameter.
 *
 * Implements    : PFlashSwapCtl_Activity
 *END**************************************************************************/
flash_drv_status_t PFlashSwapCtl(const flash_ssd_config_t * pSSDConfig, \
                                 uint32_t addr, \
                                 uint8_t swapcmd, \
                                 uint8_t* pCurrentSwapMode, \
                                 uint8_t* pCurrentSwapBlockStatus, \
                                 uint8_t* pNextSwapBlockStatus, \
                                 flash_command_sequence_t pFlashCommandSequence)
{
#ifdef DEV_ERROR_DETECT
    DEV_ASSERT(pSSDConfig != NULL);
    DEV_ASSERT(pCurrentSwapMode != NULL);
    DEV_ASSERT(pCurrentSwapBlockStatus != NULL);
    DEV_ASSERT(pNextSwapBlockStatus != NULL);
    DEV_ASSERT(pFlashCommandSequence != NULL);
#endif
    flash_drv_status_t ret;    /* Return code variable */

    /* Clear RDCOLERR & ACCERR & FPVIOL flag in flash status register. Write 1 to clear */
    CLEAR_FTFx_FSTAT_ERROR_BITS;

    /* Passing parameter to the command */
    FTFx_FCCOB0 = FTFx_PFLASH_SWAP;
    FTFx_FCCOB1 = GET_BIT_16_23(addr);
    FTFx_FCCOB2 = GET_BIT_8_15(addr);
    FTFx_FCCOB3 = GET_BIT_0_7(addr);
    FTFx_FCCOB4 = swapcmd;
    FTFx_FCCOB5 = 0xFFU;
    FTFx_FCCOB6 = 0xFFU;
    FTFx_FCCOB7 = 0xFFU;

    /* Calling flash command sequence function to execute the command */
    ret = pFlashCommandSequence(pSSDConfig);

    if (FTFx_OK == ret)
    {
        *pCurrentSwapMode = FTFx_FCCOB5;
        *pCurrentSwapBlockStatus = FTFx_FCCOB6;
        *pNextSwapBlockStatus = FTFx_FCCOB7;
    }

    return (ret);
}
#endif /* End of FSL_FEATURE_FLASH_HAS_PFLASH_BLOCK_SWAP */

#if FSL_FEATURE_FLS_HAS_ERASE_ALL_BLOCKS_UNSECURE_CMD
/*FUNCTION**********************************************************************
 *
 * Function Name : FlashEraseAllBlockUnsecure
 * Description   : Erases all Flash memory, initializes the FlexRAM, verifies
 * all memory contents, and then releases the MCU security.
 *
 * Implements    : FlashEraseAllBlockUnsecure_Activity
 *END**************************************************************************/
flash_drv_status_t FlashEraseAllBlockUnsecure (const flash_ssd_config_t * pSSDConfig, \
                                               flash_command_sequence_t pFlashCommandSequence)
{
#ifdef DEV_ERROR_DETECT
    DEV_ASSERT(pSSDConfig != NULL);
    DEV_ASSERT(pFlashCommandSequence != NULL);
#endif
    flash_drv_status_t ret;    /* Return code variable */

    /* Clear RDCOLERR & ACCERR & FPVIOL flag in flash status register. Write 1 to clear */
    CLEAR_FTFx_FSTAT_ERROR_BITS;

    /* Passing parameter to the command */
    FTFx_FCCOB0 = FTFx_ERASE_ALL_BLOCK_UNSECURE;

    /* Calling flash command sequence function to execute the command */
    ret = pFlashCommandSequence(pSSDConfig);

    return (ret);
}
#endif /* End of FSL_FEATURE_FLS_HAS_ERASE_ALL_BLOCKS_UNSECURE_CMD */

/*******************************************************************************
 * EOF
 *******************************************************************************/
