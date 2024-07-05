/*
 * File: stepMotor.h
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

#ifndef RTW_HEADER_stepMotor_h_
#define RTW_HEADER_stepMotor_h_
#ifndef stepMotor_COMMON_INCLUDES_
#define stepMotor_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* stepMotor_COMMON_INCLUDES_ */

#include "stepMotor_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  boolean_T LogicalOperator4;          /* '<S4>/Logical Operator4' */
  boolean_T FixPtRelationalOperator;   /* '<S10>/FixPt Relational Operator' */
} B_stepMotor_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T UnitDelay_DSTATE;           /* '<S12>/Unit Delay' */
  int32_T UnitDelay2_DSTATE;           /* '<S3>/Unit Delay2' */
  int32_T UnitDelay2_DSTATE_b;         /* '<S6>/Unit Delay2' */
  int32_T UnitDelay3_DSTATE;           /* '<S6>/Unit Delay3' */
  uint32_T UnitDelay_DSTATE_l;         /* '<S5>/Unit Delay' */
  uint32_T UnitDelay1_DSTATE;          /* '<S12>/Unit Delay1' */
  uint32_T Counter_ClkEphState;        /* '<S4>/Counter' */
  uint32_T Counter_RstEphState;        /* '<S4>/Counter' */
  uint32_T Counter1_ClkEphState;       /* '<S4>/Counter1' */
  uint32_T Counter1_RstEphState;       /* '<S4>/Counter1' */
  uint32_T Counter_Count;              /* '<S2>/Counter' */
  uint32_T Counter_ClkEphState_i;      /* '<S2>/Counter' */
  uint32_T Counter_RstEphState_f;      /* '<S2>/Counter' */
  uint8_T DelayInput1_DSTATE;          /* '<S23>/Delay Input1' */
  uint8_T DelayInput1_DSTATE_h;        /* '<S14>/Delay Input1' */
  uint8_T DelayInput1_DSTATE_m;        /* '<S21>/Delay Input1' */
  boolean_T UnitDelay1_DSTATE_f;       /* '<S2>/Unit Delay1' */
  boolean_T UnitDelay_DSTATE_p;        /* '<S7>/Unit Delay' */
  boolean_T UnitDelay2_DSTATE_j;       /* '<S8>/Unit Delay2' */
  boolean_T UnitDelay_DSTATE_b;        /* '<S1>/Unit Delay' */
  boolean_T DelayInput1_DSTATE_c;      /* '<S22>/Delay Input1' */
  boolean_T UnitDelay_DSTATE_i;        /* '<S11>/Unit Delay' */
  boolean_T DelayInput1_DSTATE_h1;     /* '<S13>/Delay Input1' */
  boolean_T UnitDelay_DSTATE_f;        /* '<S2>/Unit Delay' */
  boolean_T Delay_DSTATE[1000];        /* '<S4>/Delay' */
  boolean_T DelayInput1_DSTATE_ca;     /* '<S17>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_g;      /* '<S10>/Delay Input1' */
  boolean_T UnitDelay2_DSTATE_i;       /* '<S18>/Unit Delay2' */
  boolean_T DelayInput1_DSTATE_go;     /* '<S19>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_f;      /* '<S20>/Delay Input1' */
  uint8_T Counter_Count_o;             /* '<S4>/Counter' */
  uint8_T Counter1_Count;              /* '<S4>/Counter1' */
} DW_stepMotor_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T Gain;                   /* '<S5>/Gain' */
} ConstB_stepMotor_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Computed Parameter: uDLookupTable_tableData
   * Referenced by: '<S2>/1-D Lookup Table'
   */
  real32_T uDLookupTable_tableData[14];

  /* Computed Parameter: uDLookupTable_bp01Data
   * Referenced by: '<S2>/1-D Lookup Table'
   */
  real32_T uDLookupTable_bp01Data[14];

  /* Computed Parameter: uDLookupTable1_tableData
   * Referenced by: '<S2>/1-D Lookup Table1'
   */
  real32_T uDLookupTable1_tableData[14];

  /* Computed Parameter: uDLookupTable1_bp01Data
   * Referenced by: '<S2>/1-D Lookup Table1'
   */
  real32_T uDLookupTable1_bp01Data[14];
} ConstP_stepMotor_T;

/* Real-time Model Data Structure */
struct tag_RTM_stepMotor_T {
  const char_T * volatile errorStatus;
};

/* Block signals (default storage) */
extern B_stepMotor_T stepMotor_B;

/* Block states (default storage) */
extern DW_stepMotor_T stepMotor_DW;
extern const ConstB_stepMotor_T stepMotor_ConstB;/* constant block i/o */

/* Constant parameters (default storage) */
extern const ConstP_stepMotor_T stepMotor_ConstP;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern outStruct sigOutput;            /* '<S1>/Bus Assignment' */

/* Model entry point functions */
extern void stepMotor_initialize(void);
extern void stepMotor_step(void);
extern void stepMotor_terminate(void);

/* Real-time Model object */
extern RT_MODEL_stepMotor_T *const stepMotor_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Data Type Conversion1' : Eliminate redundant data type conversion
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'stepMotor'
 * '<S1>'   : 'stepMotor/Subsystem1'
 * '<S2>'   : 'stepMotor/Subsystem1/S step generator'
 * '<S3>'   : 'stepMotor/Subsystem1/Subsystem'
 * '<S4>'   : 'stepMotor/Subsystem1/Subsystem1'
 * '<S5>'   : 'stepMotor/Subsystem1/normal step generator'
 * '<S6>'   : 'stepMotor/Subsystem1/position Stack'
 * '<S7>'   : 'stepMotor/Subsystem1/priority'
 * '<S8>'   : 'stepMotor/Subsystem1/trig dispatch'
 * '<S9>'   : 'stepMotor/Subsystem1/S step generator/Compare To Constant'
 * '<S10>'  : 'stepMotor/Subsystem1/S step generator/Detect Increase'
 * '<S11>'  : 'stepMotor/Subsystem1/S step generator/Subsystem'
 * '<S12>'  : 'stepMotor/Subsystem1/S step generator/Subsystem/one step generator'
 * '<S13>'  : 'stepMotor/Subsystem1/S step generator/Subsystem/one step generator/Detect Increase'
 * '<S14>'  : 'stepMotor/Subsystem1/Subsystem/Detect Increase'
 * '<S15>'  : 'stepMotor/Subsystem1/Subsystem1/Compare To Constant'
 * '<S16>'  : 'stepMotor/Subsystem1/Subsystem1/Compare To Constant1'
 * '<S17>'  : 'stepMotor/Subsystem1/Subsystem1/Detect Decrease'
 * '<S18>'  : 'stepMotor/Subsystem1/Subsystem1/Subsystem'
 * '<S19>'  : 'stepMotor/Subsystem1/normal step generator/Detect Increase'
 * '<S20>'  : 'stepMotor/Subsystem1/normal step generator/Detect Increase1'
 * '<S21>'  : 'stepMotor/Subsystem1/position Stack/Detect Increase'
 * '<S22>'  : 'stepMotor/Subsystem1/position Stack/Detect Increase1'
 * '<S23>'  : 'stepMotor/Subsystem1/priority/Detect Increase'
 */
#endif                                 /* RTW_HEADER_stepMotor_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
