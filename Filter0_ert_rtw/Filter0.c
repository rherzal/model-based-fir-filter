/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Filter0.c
 *
 * Code generated for Simulink model 'Filter0'.
 *
 * Model version                  : 1.9
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed Sep 13 21:30:51 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-A
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Filter0.h"
#include "rtwtypes.h"
#include "Filter0_private.h"

/* Block states (default storage) */
DW_Filter0_T Filter0_DW;

/* External inputs (root inport signals with default storage) */
ExtU_Filter0_T Filter0_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Filter0_T Filter0_Y;

/* Real-time model */
static RT_MODEL_Filter0_T Filter0_M_;
RT_MODEL_Filter0_T *const Filter0_M = &Filter0_M_;
void mul_wide_su32(int32_T in0, uint32_T in1, uint32_T *ptrOutBitsHi, uint32_T
                   *ptrOutBitsLo)
{
  uint32_T absIn0;
  uint32_T in0Hi;
  uint32_T in1Hi;
  uint32_T in1Lo;
  uint32_T outBitsLo;
  uint32_T productHiLo;
  uint32_T productLoHi;
  absIn0 = in0 < 0 ? ~(uint32_T)in0 + 1U : (uint32_T)in0;
  in0Hi = absIn0 >> 16U;
  absIn0 &= 65535U;
  in1Hi = in1 >> 16U;
  in1Lo = in1 & 65535U;
  productHiLo = in0Hi * in1Lo;
  productLoHi = absIn0 * in1Hi;
  absIn0 *= in1Lo;
  in1Lo = 0U;
  outBitsLo = (productLoHi << /*MW:OvBitwiseOk*/ 16U) + /*MW:OvCarryOk*/ absIn0;
  if (outBitsLo < absIn0) {
    in1Lo = 1U;
  }

  absIn0 = outBitsLo;
  outBitsLo += /*MW:OvCarryOk*/ productHiLo << /*MW:OvBitwiseOk*/ 16U;
  if (outBitsLo < absIn0) {
    in1Lo++;
  }

  absIn0 = (((productLoHi >> 16U) + (productHiLo >> 16U)) + in0Hi * in1Hi) +
    in1Lo;
  if ((in1 != 0U) && (in0 < 0)) {
    absIn0 = ~absIn0;
    outBitsLo = ~outBitsLo;
    outBitsLo++;
    if (outBitsLo == 0U) {
      absIn0++;
    }
  }

  *ptrOutBitsHi = absIn0;
  *ptrOutBitsLo = outBitsLo;
}

int32_T mul_ssu32_loSR(int32_T a, uint32_T b, uint32_T aShift)
{
  uint32_T u32_chi;
  uint32_T u32_clo;
  mul_wide_su32(a, b, &u32_chi, &u32_clo);
  u32_clo = u32_chi << /*MW:OvBitwiseOk*/ (32U - aShift) | u32_clo >> aShift;
  return (int32_T)u32_clo;
}

/* Model step function */
void Filter0_step(void)
{
  int32_T cff;
  int32_T j;
  int32_T rtb_DiscreteFIRFilter;

  /* DiscreteFir: '<S1>/Discrete FIR Filter' incorporates:
   *  Inport: '<Root>/inputFilter'
   */
  rtb_DiscreteFIRFilter = mul_ssu32_loSR(-24632807, Filter0_U.inputFilter, 20U);
  cff = 1;
  for (j = Filter0_DW.DiscreteFIRFilter_circBuf; j < 18; j++) {
    rtb_DiscreteFIRFilter += mul_ssu32_loSR
      (Filter0_ConstP.DiscreteFIRFilter_Coefficients[cff],
       Filter0_DW.DiscreteFIRFilter_states[j], 20U);
    cff++;
  }

  for (j = 0; j < Filter0_DW.DiscreteFIRFilter_circBuf; j++) {
    rtb_DiscreteFIRFilter += mul_ssu32_loSR
      (Filter0_ConstP.DiscreteFIRFilter_Coefficients[cff],
       Filter0_DW.DiscreteFIRFilter_states[j], 20U);
    cff++;
  }

  rtb_DiscreteFIRFilter >>= 10;

  /* End of DiscreteFir: '<S1>/Discrete FIR Filter' */

  /* DataTypeConversion: '<S1>/Data Type Conversion' */
  if (rtb_DiscreteFIRFilter < 0) {
    rtb_DiscreteFIRFilter = 0;
  } else if (rtb_DiscreteFIRFilter > 4095) {
    rtb_DiscreteFIRFilter = 4095;
  }

  /* Outport: '<Root>/outputFilter' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion'
   */
  Filter0_Y.outputFilter = (uint16_T)rtb_DiscreteFIRFilter;

  /* Update for DiscreteFir: '<S1>/Discrete FIR Filter' incorporates:
   *  Inport: '<Root>/inputFilter'
   */
  /* Update circular buffer index */
  Filter0_DW.DiscreteFIRFilter_circBuf--;
  if (Filter0_DW.DiscreteFIRFilter_circBuf < 0) {
    Filter0_DW.DiscreteFIRFilter_circBuf = 17;
  }

  /* Update circular buffer */
  Filter0_DW.DiscreteFIRFilter_states[Filter0_DW.DiscreteFIRFilter_circBuf] =
    Filter0_U.inputFilter;

  /* End of Update for DiscreteFir: '<S1>/Discrete FIR Filter' */
}

/* Model initialize function */
void Filter0_initialize(void)
{
  /* (no initialization code required) */
}

/* Model terminate function */
void Filter0_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
