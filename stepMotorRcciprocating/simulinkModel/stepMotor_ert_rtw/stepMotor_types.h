/*
 * File: stepMotor_types.h
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

#ifndef RTW_HEADER_stepMotor_types_h_
#define RTW_HEADER_stepMotor_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_inStruct_
#define DEFINED_TYPEDEF_FOR_inStruct_

typedef struct {
  uint32_T timeStamp;
  uint8_T moveUp;
  uint8_T moveDown;
  uint8_T trig;
  uint32_T steps;
} inStruct;

#endif

#ifndef DEFINED_TYPEDEF_FOR_outStruct_
#define DEFINED_TYPEDEF_FOR_outStruct_

typedef struct {
  uint8_T enable;
  uint8_T step;
  uint8_T direction;
  int32_T moveRange;
  uint8_T enSave;
} outStruct;

#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_stepMotor_T RT_MODEL_stepMotor_T;

#endif                                 /* RTW_HEADER_stepMotor_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
