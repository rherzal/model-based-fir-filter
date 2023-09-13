/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Filter0.h
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

#ifndef RTW_HEADER_Filter0_h_
#define RTW_HEADER_Filter0_h_
#ifndef Filter0_COMMON_INCLUDES_
#define Filter0_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Filter0_COMMON_INCLUDES_ */

#include "Filter0_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  int32_T DiscreteFIRFilter_circBuf;   /* '<S1>/Discrete FIR Filter' */
  uint16_T DiscreteFIRFilter_states[18];/* '<S1>/Discrete FIR Filter' */
} DW_Filter0_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Computed Parameter: DiscreteFIRFilter_Coefficients
   * Referenced by: '<S1>/Discrete FIR Filter'
   */
  int32_T DiscreteFIRFilter_Coefficients[19];
} ConstP_Filter0_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  uint16_T inputFilter;                /* '<Root>/inputFilter' */
} ExtU_Filter0_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  uint16_T outputFilter;               /* '<Root>/outputFilter' */
} ExtY_Filter0_T;

/* Real-time Model Data Structure */
struct tag_RTM_Filter0_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_Filter0_T Filter0_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_Filter0_T Filter0_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_Filter0_T Filter0_Y;

/* Constant parameters (default storage) */
extern const ConstP_Filter0_T Filter0_ConstP;

/* Model entry point functions */
extern void Filter0_initialize(void);
extern void Filter0_step(void);
extern void Filter0_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Filter0_T *const Filter0_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('fir_filter/Filter')    - opens subsystem fir_filter/Filter
 * hilite_system('fir_filter/Filter/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'fir_filter'
 * '<S1>'   : 'fir_filter/Filter'
 */
#endif                                 /* RTW_HEADER_Filter0_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
