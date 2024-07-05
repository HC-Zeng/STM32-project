/*
 * File: stepMotor_data.c
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

#include "stepMotor.h"

/* Invariant block signals (default storage) */
const ConstB_stepMotor_T stepMotor_ConstB = {
  149.0                                /* '<S5>/Gain' */
};

/* Constant parameters (default storage) */
const ConstP_stepMotor_T stepMotor_ConstP = {
  /* Computed Parameter: uDLookupTable_tableData
   * Referenced by: '<S2>/1-D Lookup Table'
   */
  { 10.0250139F, 4.320117F, 2.22140265F, 1.44932902F, 1.16529894F, 1.06081009F,
    1.02237082F, 1.02237082F, 1.06081009F, 1.16529894F, 1.44932902F, 2.22140265F,
    4.320117F, 10.0250139F },

  /* Computed Parameter: uDLookupTable_bp01Data
   * Referenced by: '<S2>/1-D Lookup Table'
   */
  { 0.0F, 1.0F, 2.0F, 3.0F, 4.0F, 5.0F, 6.0F, 94.0F, 95.0F, 96.0F, 97.0F, 98.0F,
    99.0F, 100.0F },

  /* Computed Parameter: uDLookupTable1_tableData
   * Referenced by: '<S2>/1-D Lookup Table1'
   */
  { 10.0F, 9.1F, 7.6F, 5.8F, 4.0F, 2.3F, 1.0F, 1.0F, 2.3F, 4.0F, 5.8F, 7.6F,
    9.1F, 10.0F },

  /* Computed Parameter: uDLookupTable1_bp01Data
   * Referenced by: '<S2>/1-D Lookup Table1'
   */
  { 0.0F, 1.0F, 3.0F, 6.0F, 10.0F, 16.0F, 25.0F, 74.0F, 85.0F, 91.0F, 95.0F,
    98.0F, 99.0F, 100.0F }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
