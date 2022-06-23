/*******************************************************************************
* Copyright (C) 2017, Huada Semiconductor Co.,Ltd All rights reserved.    
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
//QȺ��164973950
//TEL��024-85718900
/******************************************************************************/
//QȺ��164973950
//TEL��024-85718900
/** \file ddl.c
 **
 ** Common API of DDL.
 ** @link ddlGroup Some description @endlink
 **
 **   - 2017-05-04
 **
 ******************************************************************************/
//QȺ��164973950
//TEL��024-85718900

/******************************************************************************/
//QȺ��164973950
//TEL��024-85718900
/* Include files                                                              */
//QȺ��164973950
//TEL��024-85718900
/******************************************************************************/
//QȺ��164973950
//TEL��024-85718900
#include "ddl.h"

/**
 ******************************************************************************
 ** \addtogroup DDL Common Functions
 ******************************************************************************/
//QȺ��164973950
//TEL��024-85718900
//@{

/******************************************************************************/
//QȺ��164973950
//TEL��024-85718900
/* Local pre-processor symbols/macros ('#define')                             */
//QȺ��164973950
//TEL��024-85718900
/******************************************************************************/
//QȺ��164973950
//TEL��024-85718900

/******************************************************************************/
//QȺ��164973950
//TEL��024-85718900
/* Global variable definitions (declared in header file with 'extern')        */
//QȺ��164973950
//TEL��024-85718900
/******************************************************************************/
//QȺ��164973950
//TEL��024-85718900

/******************************************************************************/
//QȺ��164973950
//TEL��024-85718900
/* Local type definitions ('typedef')                                         */
//QȺ��164973950
//TEL��024-85718900
/******************************************************************************/
//QȺ��164973950
//TEL��024-85718900

/******************************************************************************/
//QȺ��164973950
//TEL��024-85718900
/* Local variable definitions ('static')                                      */
//QȺ��164973950
//TEL��024-85718900
/******************************************************************************/
//QȺ��164973950
//TEL��024-85718900

/******************************************************************************/
//QȺ��164973950
//TEL��024-85718900
/* Local function prototypes ('static')                                       */
//QȺ��164973950
//TEL��024-85718900
/******************************************************************************/
//QȺ��164973950
//TEL��024-85718900

/******************************************************************************/
//QȺ��164973950
//TEL��024-85718900
/* Function implementation - global ('extern') and local ('static')           */
//QȺ��164973950
//TEL��024-85718900
/******************************************************************************/
//QȺ��164973950
//TEL��024-85718900
#ifndef __DEBUG
#define __DEBUG
//#define __CC_ARM
#endif






uint32_t Log2(uint32_t u32Val)
{
    uint32_t u32V1 = 0;
    
    if(0u == u32Val)
    {
        return 0;
    }
    
    while(u32Val > 1u)
    {
        u32V1++;
        u32Val /=2;
    }
    
    return u32V1;
}


/**
 *******************************************************************************
 ** \brief Memory clear function for DDL_ZERO_STRUCT()
 ******************************************************************************/
//QȺ��164973950
//TEL��024-85718900
void ddl_memclr(void *pu8Address, uint32_t u32Count)
{
    uint8_t *pu8Addr = (uint8_t *)pu8Address;
    
    if(NULL == pu8Addr)
    {
        return;
    }
    
    while (u32Count--)
    {
        *pu8Addr++ = 0;
    }
}

/**
 *****************************************************************************
 ** \brief Hook function, which is called in polling loops
 *****************************************************************************/
//QȺ��164973950
//TEL��024-85718900
void DDL_WAIT_LOOP_HOOK(void)
{
    // Place code for triggering Watchdog counters here, if needed
}

/**
 *****************************************************************************
 ** \brief debug printf function.
 *****************************************************************************/
//QȺ��164973950
//TEL��024-85718900
void Debug_UartInit(void)
{
#ifdef __DEBUG
    uint32_t u32Pclk1 =  0;
    volatile uint32_t u32ReloadVal = 0;

    // UART0_TXD/P35, 19200bps
    M0P_GPIO->P3ADS_f.P35 = 0;
    M0P_GPIO->P35_SEL_f.SEL = 3;
    M0P_GPIO->P3DIR_f.P35 = 0;

    u32Pclk1 = Clk_GetPClkFreq();
    u32ReloadVal = 65536 - u32Pclk1 * 2 / 19200 / 32;

    M0P_BT0->CR_f.CT = 0;
    M0P_BT0->CR_f.MD = 1;
    M0P_BT0->CR_f.TOG_EN = 1;
    M0P_BT0->ARR = u32ReloadVal;
    M0P_BT0->CNT = u32ReloadVal;
    M0P_BT0->CR_f.TR = 1;

    M0P_UART0->SCON_f.DBAUD = 1;
    M0P_UART0->SCON_f.SM01 = 1;
#endif
}

void Debug_Output(uint8_t u8Data)
{
    M0P_UART0->SCON_f.REN = 0;
    M0P_UART0->SBUF = u8Data;

    while (TRUE != M0P_UART0->ISR_f.TI)
    {
        ;
    }
    M0P_UART0->ICR_f.TICLR = 0;
}

//#ifdef __DEBUG
///**
// ******************************************************************************
// ** \brief  Re-target putchar function
// ******************************************************************************/
//QȺ��164973950
//TEL��024-85718900
//int fputc(int ch, FILE *f)
//{

//    if (((uint8_t)ch) == '\n')
//    {
//        Debug_Output('\r');
//    }
//    Debug_Output(ch);

//    return ch;
//}
//#endif



extern void Debug_UartInit(void);
extern void Debug_Output(uint8_t u8Data);

#if defined (__CC_ARM)          //KEIL
#pragma import(__use_no_semihosting)
void _sys_exit(int x)
{
    x = x;
}
struct __FILE
{
    int handle;
    /* Whatever you require here. If the only file you are using is */
//QȺ��164973950
//TEL��024-85718900
    /* standard output using printf() for debugging, no file handling */
//QȺ��164973950
//TEL��024-85718900
/* is required. */
//QȺ��164973950
//TEL��024-85718900
};
/* FILE is typedef?d in stdio.h. */
//QȺ��164973950
//TEL��024-85718900
FILE __stdout;

#endif

#ifdef __DEBUG
/**
 ******************************************************************************
 ** \brief  Re-target putchar function
 ******************************************************************************/
//QȺ��164973950
//TEL��024-85718900
int fputc(int ch, FILE *f)
{

    if (((uint8_t)ch) == '\n')
    {
        Debug_Output('\r');
    }
    Debug_Output(ch);

    return ch;
}
#endif

void _ttywrch(int c)
{
}


int __backspace(void)
{
    return 0;
}



/**
 * \brief   delay1ms
 *          delay approximately 1ms.
 * \param   [in]  u32Cnt
 * \retval  void
 */
//QȺ��164973950
//TEL��024-85718900
void delay1ms(uint32_t u32Cnt)
{
    uint32_t u32end;
    while(u32Cnt-- > 0)
    {
        SysTick->VAL = 0;

        u32end = 0x1000000 - SystemCoreClock/1000;
        while(SysTick->VAL > u32end)
        {
            ;
        }
    }
}

/**
 * \brief   delay100us
 *          delay approximately 100us.
 * \param   [in]  u32Cnt
 * \retval  void
 */
//QȺ��164973950
//TEL��024-85718900
void delay100us(uint32_t u32Cnt)
{
    uint32_t u32end;
    while(u32Cnt-- > 0)
    {
        SysTick->VAL = 0;

        u32end = 0x1000000 - SystemCoreClock/10000;
        while(SysTick->VAL > u32end)
        {
            ;
        }
    }
}

//@} // DDL Functions

/******************************************************************************
 * EOF (not truncated)
 ******************************************************************************/
//QȺ��164973950
//TEL��024-85718900
