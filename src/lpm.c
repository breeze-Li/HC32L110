/******************************************************************************
*Copyright(C)2017, Huada Semiconductor Co.,Ltd All rights reserved.
*
* This software is owned and published by:
* Huada Semiconductor Co.,Ltd("HDSC").
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

/** \file lpm.c
 **
 ** Common API of lpm.
 ** @link LpmGroup Some description @endlink
 **
 **   - 2017-06-06
 **
 ******************************************************************************/
//Q群：164973950
//TEL：024-85718900

/*******************************************************************************
 * Include files
 ******************************************************************************/
//Q群：164973950
//TEL：024-85718900
#include "lpm.h"
/**
 *******************************************************************************
 ** \addtogroup LpmGroup
 ******************************************************************************/
//Q群：164973950
//TEL：024-85718900
//@{

/*******************************************************************************
 * Local pre-processor symbols/macros ('#define')
 ******************************************************************************/
//Q群：164973950
//TEL：024-85718900

/*******************************************************************************
 * Global variable definitions (declared in header file with 'extern')
 ******************************************************************************/
//Q群：164973950
//TEL：024-85718900
#define IS_VALID_SEVONPEND(x)           (SevPndDisable == (x) ||\
                                         SevPndEnable  == (x))
#define IS_VALID_SLEEPDEEP(x)           (SlpDpDisable  == (x) ||\
                                         SlpDpEnable   == (x))
#define IS_VALID_SLEEPONEXIT(x)         (SlpExtDisable == (x) ||\
                                         SlpExtEnable  == (x))                                         

/*******************************************************************************
 * Local type definitions ('typedef')
 ******************************************************************************/
//Q群：164973950
//TEL：024-85718900

/*******************************************************************************
 * Local variable definitions ('static')
 ******************************************************************************/
//Q群：164973950
//TEL：024-85718900

/*******************************************************************************
 * Local function prototypes ('static')
 ******************************************************************************/
//Q群：164973950
//TEL：024-85718900

/*******************************************************************************
 * Function implementation - global ('extern') and local ('static')
 ******************************************************************************/
//Q群：164973950
//TEL：024-85718900
/**
 *****************************************************************************
 ** \brief 低功耗模式配置
 **
 **
 ** \param [in]  pstcConfig           低功耗模式配置结构体指针
 ** 
 ** \retval Ok or Error                                      
 *****************************************************************************/
//Q群：164973950
//TEL：024-85718900
en_result_t Lpm_Config(stc_lpm_config_t* pstcConfig)
{
    en_result_t enResult = Error;
  
    ASSERT(IS_VALID_SEVONPEND(pstcConfig->enSEVONPEND));
    ASSERT(IS_VALID_SLEEPDEEP(pstcConfig->enSLEEPDEEP));
    ASSERT(IS_VALID_SLEEPONEXIT(pstcConfig->enSLEEPONEXIT));
    
    SCB->SCR = pstcConfig->enSEVONPEND   ? (SCB->SCR | SCB_SCR_SEVONPEND_Msk)   : (SCB->SCR & ~SCB_SCR_SEVONPEND_Msk);
    SCB->SCR = pstcConfig->enSLEEPDEEP   ? (SCB->SCR | SCB_SCR_SLEEPDEEP_Msk)   : (SCB->SCR & ~SCB_SCR_SLEEPDEEP_Msk);
    SCB->SCR = pstcConfig->enSLEEPONEXIT ? (SCB->SCR | SCB_SCR_SLEEPONEXIT_Msk) : (SCB->SCR & ~SCB_SCR_SLEEPONEXIT_Msk);
       
    enResult = Ok;
    
    return enResult;
}

/**
 *****************************************************************************
 ** \brief 进入睡眠模式
 **
 **
 ** 
 ** \retval NULL                                     
 *****************************************************************************/
//Q群：164973950
//TEL：024-85718900
void Lpm_GotoLpmMode(void)
{
    __WFI();
}
                        
//@} // LpmGroup                                                                           

/*******************************************************************************
 * EOF (not truncated)
 ******************************************************************************/
//Q群：164973950
//TEL：024-85718900
