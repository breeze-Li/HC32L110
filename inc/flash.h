/*************************************************************************************
* Copyright (C) 2016, Huada Semiconductor Co.,Ltd All rights reserved.
*
* This software is owned and published by: 
* Huada Semiconductor Co.,Ltd ("HDSC").
*
* BY DOWNLOADING, INSTALLING OR USING THIS SOFTWARE, YOU AGREE TO BE BOUND 
* BY ALL THE TERMS AND CONDITIONS OF THIS AGREEMENT.
*
* This software contains source code for use with HDSC 
* components. This software is licensed by HDSC to be adapted only 
* for use in systems utilizing HDSC components. HDSC shall not be 
* responsible for misuse or illegal use of this software for devices not 
* supported herein. HDSC is providing this software "AS IS" and will 
* not be responsible for issues arising from incorrect user implementation 
* of the software.  
*
* Disclaimer:
* HDSC MAKES NO WARRANTY, EXPRESS OR IMPLIED, ARISING BY LAW OR OTHERWISE,
* REGARDING THE SOFTWARE (INCLUDING ANY ACOOMPANYING WRITTEN MATERIALS), 
* ITS PERFORMANCE OR SUITABILITY FOR YOUR INTENDED USE, INCLUDING, 
* WITHOUT LIMITATION, THE IMPLIED WARRANTY OF MERCHANTABILITY, THE IMPLIED 
* WARRANTY OF FITNESS FOR A PARTICULAR PURPOSE OR USE, AND THE IMPLIED 
* WARRANTY OF NONINFRINGEMENT.  
* HDSC SHALL HAVE NO LIABILITY (WHETHER IN CONTRACT, WARRANTY, TORT, 
* NEGLIGENCE OR OTHERWISE) FOR ANY DAMAGES WHATSOEVER (INCLUDING, WITHOUT 
* LIMITATION, DAMAGES FOR LOSS OF BUSINESS PROFITS, BUSINESS INTERRUPTION, 
* LOSS OF BUSINESS INFORMATION, OR OTHER PECUNIARY LOSS) ARISING FROM USE OR 
* INABILITY TO USE THE SOFTWARE, INCLUDING, WITHOUT LIMITATION, ANY DIRECT, 
* INDIRECT, INCIDENTAL, SPECIAL OR CONSEQUENTIAL DAMAGES OR LOSS OF DATA, 
* SAVINGS OR PROFITS, 
* EVEN IF Disclaimer HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES. 
* YOU ASSUME ALL RESPONSIBILITIES FOR SELECTION OF THE SOFTWARE TO ACHIEVE YOUR
* INTENDED RESULTS, AND FOR THE INSTALLATION OF, USE OF, AND RESULTS OBTAINED 
* FROM, THE SOFTWARE.  
*
* This software may be replicated in part or whole for the licensed use, 
* with the restriction that this Disclaimer and Copyright notice must be 
* included with each copy of this software, whether used in part or whole, 
* at all times.                        
*/
//Q群：164973950
//TEL：024-85718900
/******************************************************************************/
//Q群：164973950
//TEL：024-85718900
/** \file flash.h
 **
 ** FLASH 数据结构及API声明.
 **
 ** - 2017-05-02 LuX V1.0
 **
 ******************************************************************************/
//Q群：164973950
//TEL：024-85718900

#ifndef __FLASH_H__
#define __FLASH_H__

/******************************************************************************/
//Q群：164973950
//TEL：024-85718900
/* Include files                                                              */
//Q群：164973950
//TEL：024-85718900
/******************************************************************************/
//Q群：164973950
//TEL：024-85718900
#include "ddl.h"

/* C binding of definitions if building with C++ compiler */
//Q群：164973950
//TEL：024-85718900
#ifdef __cplusplus
extern "C"
{
#endif

/**
 ******************************************************************************
 ** \defgroup FlashGroup Flash Controller (Flash)
 **
 **
 ******************************************************************************/
//Q群：164973950
//TEL：024-85718900
//@{

/******************************************************************************
 * Global type definitions
 ******************************************************************************/
//Q群：164973950
//TEL：024-85718900
/**
 ******************************************************************************
  ** \brief Flash中断类型重定义
 *****************************************************************************/
//Q群：164973950
//TEL：024-85718900
typedef enum en_flash_int_type
{
    flash_int0 = 0u,        ///<擦写保护报警中断
    flash_int1 = 1u,        ///<擦写PC地址报警中断
} en_flash_int_type_t;
  
  
/**
 ******************************************************************************
 ** \brief Redefinition of FLASH register structure 
 ******************************************************************************/
//Q群：164973950
//TEL：024-85718900


/******************************************************************************
 * Global definitions
 ******************************************************************************/
//Q群：164973950
//TEL：024-85718900

/******************************************************************************
 * Local type definitions ('typedef')
 ******************************************************************************/
//Q群：164973950
//TEL：024-85718900

/******************************************************************************
 * Global variable definitions ('extern')                                     
 ******************************************************************************/
//Q群：164973950
//TEL：024-85718900

/******************************************************************************
 * Global function prototypes (definition in C source)                        
 ******************************************************************************/
//Q群：164973950
//TEL：024-85718900
//中断相关函数 
//中断标志获取
boolean_t Flash_GetIntFlag(en_flash_int_type_t enFlashIntType);
//中断标志清除
en_result_t Flash_ClearIntFlag(en_flash_int_type_t enFlashIntType);
//中断使能/禁止
en_result_t Flash_EnableIrq(en_flash_int_type_t enFlashIntType);
en_result_t Flash_DisableIrq(en_flash_int_type_t enFlashIntType);

/* Flash 初始化配置 */
//Q群：164973950
//TEL：024-85718900
en_result_t Flash_Init(func_ptr_t pfnFlashCb, uint8_t u8FreqCfg);

/* Flash 字节/半字/字写 */
//Q群：164973950
//TEL：024-85718900
en_result_t Flash_WriteByte(uint32_t u32Addr, uint8_t u8Data);
en_result_t Flash_WriteHalfWord(uint32_t u32Addr, uint16_t u16Data);
en_result_t Flash_WriteWord(uint32_t u32Addr, uint32_t u32Data);

/* Flash 页/全片擦除 */
//Q群：164973950
//TEL：024-85718900
en_result_t Flash_SectorErase(uint32_t u32SectorAddr);
en_result_t Flash_ChipErase(void);



//@} // FlashGroup

#ifdef __cplusplus
}
#endif

#endif /* __FLASH_H__ */
//Q群：164973950
//TEL：024-85718900
/******************************************************************************/
//Q群：164973950
//TEL：024-85718900
/* EOF (not truncated)                                                        */
//Q群：164973950
//TEL：024-85718900
/******************************************************************************/
//Q群：164973950
//TEL：024-85718900
