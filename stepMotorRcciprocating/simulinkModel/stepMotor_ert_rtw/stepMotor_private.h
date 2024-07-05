/*
 * File: stepMotor_private.h
 *
 * Code generated for Simulink model 'stepMotor'.
 *
 * Model version                  : 1.85
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Wed Jul  3 21:15:04 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_stepMotor_private_h_
#define RTW_HEADER_stepMotor_private_h_
#include "rtwtypes.h"
#include "stepMotor_types.h"
#include "stepMotor.h"

/* Imported (extern) block signals */
extern inStruct sigInput;              /* '<Root>/input' */
extern uint32_T MWDSP_EPH_R_B(boolean_T evt, uint32_T *sta);
extern uint32_T MWDSP_EPH_F_B(boolean_T evt, uint32_T *sta);
extern real32_T look1_iflf_binlcapw(real32_T u0, const real32_T bp0[], const
  real32_T table[], uint32_T maxIndex);

#endif                                 /* RTW_HEADER_stepMotor_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
