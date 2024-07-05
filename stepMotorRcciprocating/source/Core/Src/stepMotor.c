/*
 * File: stepMotor.c
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
#include "stepMotor_private.h"
#include "rtwtypes.h"
#include "stepMotor_types.h"

/* Exported block signals */
outStruct sigOutput;                   /* '<S1>/Bus Assignment' */

/* Block signals (default storage) */
B_stepMotor_T stepMotor_B;

/* Block states (default storage) */
DW_stepMotor_T stepMotor_DW;

/* Real-time model */
static RT_MODEL_stepMotor_T stepMotor_M_;
RT_MODEL_stepMotor_T *const stepMotor_M = &stepMotor_M_;
real32_T look1_iflf_binlcapw(real32_T u0, const real32_T bp0[], const real32_T
  table[], uint32_T maxIndex)
{
  real32_T frac;
  real32_T y;
  uint32_T iLeft;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = 0.0F;
  } else if (u0 < bp0[maxIndex]) {
    uint32_T bpIdx;
    uint32_T iRght;

    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex;
    frac = 0.0F;
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'on'
     Overflow mode: 'portable wrapping'
   */
  if (iLeft == maxIndex) {
    y = table[iLeft];
  } else {
    real32_T yL_0d0;
    yL_0d0 = table[iLeft];
    y = (table[iLeft + 1U] - yL_0d0) * frac + yL_0d0;
  }

  return y;
}

uint32_T MWDSP_EPH_R_B(boolean_T evt, uint32_T *sta)
{
  int32_T curState;
  int32_T lastzcevent;
  int32_T newState;
  int32_T newStateR;
  uint32_T previousState;
  uint32_T retVal;

  /* S-Function (sdspcount2): '<S4>/Counter' */
  /* Detect rising edge events */
  previousState = *sta;
  retVal = 0U;
  lastzcevent = 0;
  newState = 5;
  newStateR = 5;
  if (evt) {
    curState = 2;
  } else {
    curState = 1;
  }

  if (*sta == 5U) {
    newStateR = curState;
  } else if ((uint32_T)curState != *sta) {
    if (*sta == 3U) {
      if ((uint32_T)curState == 1U) {
        newStateR = 1;
      } else {
        lastzcevent = 2;
        previousState = 1U;
      }
    }

    if (previousState == 4U) {
      if ((uint32_T)curState == 1U) {
        newStateR = 1;
      } else {
        lastzcevent = 3;
        previousState = 1U;
      }
    }

    if ((previousState == 1U) && ((uint32_T)curState == 2U)) {
      retVal = 2U;
    }

    if (previousState == 0U) {
      retVal = 2U;
    }

    if (retVal == (uint32_T)lastzcevent) {
      retVal = 0U;
    }

    if (((uint32_T)curState == 1U) && (retVal == 2U)) {
      newState = 3;
    } else {
      newState = curState;
    }
  }

  if ((uint32_T)newStateR != 5U) {
    *sta = (uint32_T)newStateR;
    retVal = 0U;
  }

  if ((uint32_T)newState != 5U) {
    *sta = (uint32_T)newState;
  }

  /* End of S-Function (sdspcount2): '<S4>/Counter' */
  return retVal;
}

uint32_T MWDSP_EPH_F_B(boolean_T evt, uint32_T *sta)
{
  int32_T curState;
  int32_T lastzcevent;
  int32_T newState;
  int32_T newStateR;
  uint32_T previousState;
  uint32_T retVal;

  /* S-Function (sdspcount2): '<S2>/Counter' */
  /* Detect falling edge events */
  previousState = *sta;
  retVal = 0U;
  lastzcevent = 0;
  newState = 5;
  newStateR = 5;
  if (evt) {
    curState = 2;
  } else {
    curState = 1;
  }

  if (*sta == 5U) {
    newStateR = curState;
  } else if ((uint32_T)curState != *sta) {
    if (*sta == 3U) {
      if ((uint32_T)curState == 1U) {
        newStateR = 1;
      } else {
        lastzcevent = 2;
        previousState = 1U;
      }
    }

    if (previousState == 4U) {
      if ((uint32_T)curState == 1U) {
        newStateR = 1;
      } else {
        lastzcevent = 3;
        previousState = 1U;
      }
    }

    if (previousState == 2U) {
      retVal = 3U;
    }

    if (retVal == (uint32_T)lastzcevent) {
      retVal = 0U;
    }

    if (((uint32_T)curState == 1U) && (retVal == 3U)) {
      newState = 4;
    } else {
      newState = curState;
    }
  }

  if ((uint32_T)newStateR != 5U) {
    *sta = (uint32_T)newStateR;
    retVal = 0U;
  }

  if ((uint32_T)newState != 5U) {
    *sta = (uint32_T)newState;
  }

  /* End of S-Function (sdspcount2): '<S2>/Counter' */
  return retVal;
}

/* Model step function */
void stepMotor_step(void)
{
  int32_T rtb_Abs;
  int32_T rtb_UnitDelay2_b;
  real32_T rtb_Switch_k;
  uint32_T rtb_Subtract_mm;
  uint32_T rtb_Switch1;
  uint32_T rtb_dt;
  uint8_T rtb_DataTypeConversion;
  boolean_T rtb_FixPtRelationalOperator_j;
  boolean_T rtb_LogicalOperator;
  boolean_T rtb_LogicalOperator1;
  boolean_T rtb_LogicalOperator1_kl;
  boolean_T rtb_LogicalOperator1_m;
  boolean_T rtb_LogicalOperator5;
  boolean_T rtb_LogicalOperator6_l;
  boolean_T rtb_LogicalOperator_j;
  boolean_T rtb_UnitDelay1;
  boolean_T rtb_UnitDelay_h;
  boolean_T rtb_UnitDelay_j;

  /* UnitDelay: '<S2>/Unit Delay1' */
  rtb_UnitDelay1 = stepMotor_DW.UnitDelay1_DSTATE_f;

  /* RelationalOperator: '<S23>/FixPt Relational Operator' incorporates:
   *  Inport: '<Root>/input'
   *  UnitDelay: '<S23>/Delay Input1'
   *
   * Block description for '<S23>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_LogicalOperator6_l = (sigInput.trig > stepMotor_DW.DelayInput1_DSTATE);

  /* Logic: '<S7>/Logical Operator9' incorporates:
   *  UnitDelay: '<S7>/Unit Delay'
   */
  rtb_UnitDelay_j = !stepMotor_DW.UnitDelay_DSTATE_p;

  /* Logic: '<S7>/Logical Operator2' incorporates:
   *  Logic: '<S7>/Logical Operator4'
   */
  rtb_LogicalOperator1_kl = !rtb_LogicalOperator6_l;

  /* Logic: '<S7>/Logical Operator1' incorporates:
   *  Inport: '<Root>/input'
   *  Logic: '<S7>/Logical Operator2'
   *  Logic: '<S7>/Logical Operator3'
   */
  rtb_LogicalOperator1 = ((sigInput.moveUp != 0) && (rtb_LogicalOperator1_kl &&
    (sigInput.moveDown == 0)) && rtb_UnitDelay_j);

  /* Logic: '<S1>/Logical Operator1' incorporates:
   *  Inport: '<Root>/input'
   *  Logic: '<S7>/Logical Operator'
   *  Logic: '<S7>/Logical Operator4'
   *  Logic: '<S7>/Logical Operator5'
   */
  rtb_LogicalOperator1_kl = (rtb_LogicalOperator1 || ((sigInput.moveDown != 0) &&
    ((sigInput.moveUp == 0) && rtb_LogicalOperator1_kl) && rtb_UnitDelay_j));

  /* DataTypeConversion: '<S1>/Data Type Conversion2' incorporates:
   *  Logic: '<S1>/Logical Operator'
   *  UnitDelay: '<S23>/Delay Input1'
   *  UnitDelay: '<S2>/Unit Delay1'
   *
   * Block description for '<S23>/Delay Input1':
   *
   *  Store in Global RAM
   */
  stepMotor_DW.DelayInput1_DSTATE = (uint8_T)(stepMotor_DW.UnitDelay1_DSTATE_f ||
    rtb_LogicalOperator1_kl);

  /* Logic: '<S7>/Logical Operator6' incorporates:
   *  Inport: '<Root>/input'
   *  Logic: '<S7>/Logical Operator7'
   *  Logic: '<S7>/Logical Operator8'
   */
  rtb_LogicalOperator6_l = (rtb_LogicalOperator6_l && ((sigInput.moveUp == 0) &&
    (sigInput.moveDown == 0)) && rtb_UnitDelay_j);

  /* DataTypeConversion: '<S8>/Data Type Conversion' incorporates:
   *  Logic: '<S8>/Logical Operator'
   *  UnitDelay: '<S8>/Unit Delay2'
   */
  rtb_DataTypeConversion = (uint8_T)(rtb_LogicalOperator6_l &&
    stepMotor_DW.UnitDelay2_DSTATE_j);

  /* UnitDelay: '<S1>/Unit Delay' */
  rtb_UnitDelay_h = stepMotor_DW.UnitDelay_DSTATE_b;

  /* Sum: '<S5>/Subtract' incorporates:
   *  Inport: '<Root>/input'
   *  UnitDelay: '<S5>/Unit Delay'
   */
  rtb_Subtract_mm = sigInput.timeStamp - stepMotor_DW.UnitDelay_DSTATE_l;

  /* Switch: '<S5>/Switch1' incorporates:
   *  Constant: '<S5>/Constant'
   *  RelationalOperator: '<S5>/Relational Operator'
   */
  if (rtb_LogicalOperator1_kl) {
    rtb_UnitDelay_j = (rtb_Subtract_mm < stepMotor_ConstB.Gain);
  } else {
    rtb_UnitDelay_j = false;
  }

  /* End of Switch: '<S5>/Switch1' */

  /* Switch: '<S3>/Switch1' incorporates:
   *  Constant: '<S3>/Constant'
   *  Switch: '<S3>/Switch'
   *  UnitDelay: '<S1>/Unit Delay'
   *  UnitDelay: '<S3>/Unit Delay2'
   */
  if (stepMotor_DW.UnitDelay_DSTATE_b) {
    stepMotor_DW.UnitDelay2_DSTATE = 0;
  } else if (rtb_LogicalOperator1) {
    /* Switch: '<S3>/Switch' incorporates:
     *  DataTypeConversion: '<S5>/Data Type Conversion'
     *  RelationalOperator: '<S14>/FixPt Relational Operator'
     *  Sum: '<S3>/Add'
     *  UnitDelay: '<S14>/Delay Input1'
     *  UnitDelay: '<S3>/Unit Delay2'
     *
     * Block description for '<S14>/Delay Input1':
     *
     *  Store in Global RAM
     */
    stepMotor_DW.UnitDelay2_DSTATE += ((int32_T)rtb_UnitDelay_j >
      stepMotor_DW.DelayInput1_DSTATE_h);
  } else {
    /* UnitDelay: '<S3>/Unit Delay2' incorporates:
     *  DataTypeConversion: '<S5>/Data Type Conversion'
     *  RelationalOperator: '<S14>/FixPt Relational Operator'
     *  Sum: '<S3>/Subtract'
     *  Switch: '<S3>/Switch'
     *  UnitDelay: '<S14>/Delay Input1'
     *
     * Block description for '<S14>/Delay Input1':
     *
     *  Store in Global RAM
     */
    stepMotor_DW.UnitDelay2_DSTATE -= ((int32_T)rtb_UnitDelay_j >
      stepMotor_DW.DelayInput1_DSTATE_h);
  }

  /* End of Switch: '<S3>/Switch1' */

  /* UnitDelay: '<S6>/Unit Delay2' */
  rtb_UnitDelay2_b = stepMotor_DW.UnitDelay2_DSTATE_b;

  /* Switch: '<S6>/Switch' incorporates:
   *  Constant: '<S6>/Constant'
   *  Constant: '<S6>/Constant1'
   *  RelationalOperator: '<S21>/FixPt Relational Operator'
   *  RelationalOperator: '<S22>/FixPt Relational Operator'
   *  Switch: '<S6>/Switch1'
   *  Switch: '<S6>/Switch2'
   *  Switch: '<S6>/Switch3'
   *  UnitDelay: '<S1>/Unit Delay'
   *  UnitDelay: '<S21>/Delay Input1'
   *  UnitDelay: '<S22>/Delay Input1'
   *  UnitDelay: '<S6>/Unit Delay2'
   *  UnitDelay: '<S6>/Unit Delay3'
   *
   * Block description for '<S21>/Delay Input1':
   *
   *  Store in Global RAM
   *
   * Block description for '<S22>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if ((int32_T)stepMotor_DW.UnitDelay_DSTATE_b > (int32_T)
      stepMotor_DW.DelayInput1_DSTATE_c) {
    stepMotor_DW.UnitDelay2_DSTATE_b = 0;
    stepMotor_DW.UnitDelay3_DSTATE = 0;
  } else if (rtb_DataTypeConversion > stepMotor_DW.DelayInput1_DSTATE_m) {
    /* Switch: '<S6>/Switch1' incorporates:
     *  UnitDelay: '<S3>/Unit Delay2'
     *  UnitDelay: '<S6>/Unit Delay2'
     */
    stepMotor_DW.UnitDelay2_DSTATE_b = stepMotor_DW.UnitDelay2_DSTATE;

    /* Switch: '<S6>/Switch2' incorporates:
     *  UnitDelay: '<S6>/Unit Delay3'
     */
    stepMotor_DW.UnitDelay3_DSTATE = rtb_UnitDelay2_b;
  }

  /* End of Switch: '<S6>/Switch' */

  /* Sum: '<S1>/Subtract' incorporates:
   *  UnitDelay: '<S6>/Unit Delay2'
   *  UnitDelay: '<S6>/Unit Delay3'
   */
  rtb_UnitDelay2_b = stepMotor_DW.UnitDelay2_DSTATE_b -
    stepMotor_DW.UnitDelay3_DSTATE;

  /* Abs: '<S1>/Abs' */
  if (rtb_UnitDelay2_b < 0) {
    rtb_Abs = -rtb_UnitDelay2_b;
  } else {
    rtb_Abs = rtb_UnitDelay2_b;
  }

  /* End of Abs: '<S1>/Abs' */

  /* Switch: '<S1>/Switch1' incorporates:
   *  Inport: '<Root>/input'
   */
  if (sigInput.steps > 0U) {
    rtb_Switch1 = sigInput.steps;
  } else {
    rtb_Switch1 = (uint32_T)rtb_Abs;
  }

  /* End of Switch: '<S1>/Switch1' */

  /* Logic: '<S11>/Logical Operator' incorporates:
   *  Constant: '<S9>/Constant'
   *  Logic: '<S11>/Logical Operator1'
   *  Logic: '<S2>/Logical Operator2'
   *  RelationalOperator: '<S9>/Compare'
   *  UnitDelay: '<S11>/Unit Delay'
   *  UnitDelay: '<S2>/Unit Delay1'
   */
  rtb_LogicalOperator = (stepMotor_DW.UnitDelay1_DSTATE_f && (rtb_Switch1 > 0U) &&
    (!stepMotor_DW.UnitDelay_DSTATE_i));

  /* RelationalOperator: '<S13>/FixPt Relational Operator' incorporates:
   *  UnitDelay: '<S13>/Delay Input1'
   *
   * Block description for '<S13>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_FixPtRelationalOperator_j = ((int32_T)rtb_LogicalOperator > (int32_T)
    stepMotor_DW.DelayInput1_DSTATE_h1);

  /* Switch: '<S12>/Switch1' incorporates:
   *  Inport: '<Root>/input'
   *  UnitDelay: '<S12>/Unit Delay1'
   */
  if (rtb_FixPtRelationalOperator_j) {
    stepMotor_DW.UnitDelay1_DSTATE = sigInput.timeStamp;
  }

  /* End of Switch: '<S12>/Switch1' */

  /* Sum: '<S12>/Subtract' incorporates:
   *  Inport: '<Root>/input'
   *  UnitDelay: '<S12>/Unit Delay1'
   */
  rtb_dt = sigInput.timeStamp - stepMotor_DW.UnitDelay1_DSTATE;

  /* Logic: '<S8>/Logical Operator1' incorporates:
   *  Logic: '<S8>/Logical Operator3'
   *  UnitDelay: '<S8>/Unit Delay2'
   */
  rtb_LogicalOperator1_m = (rtb_LogicalOperator6_l &&
    (!stepMotor_DW.UnitDelay2_DSTATE_j));

  /* RelationalOperator: '<S15>/Compare' incorporates:
   *  Constant: '<S15>/Constant'
   */
  rtb_LogicalOperator5 = (rtb_UnitDelay2_b < 0);

  /* Logic: '<S4>/Logical Operator2' */
  rtb_LogicalOperator_j = (rtb_LogicalOperator1_m && rtb_LogicalOperator5);

  /* Logic: '<S4>/Logical Operator4' incorporates:
   *  Logic: '<S4>/Logical Operator3'
   */
  stepMotor_B.LogicalOperator4 = (rtb_LogicalOperator1_m &&
    (!rtb_LogicalOperator5));

  /* Delay: '<S4>/Delay' */
  rtb_LogicalOperator1_m = stepMotor_DW.Delay_DSTATE[0];

  /* RelationalOperator: '<S17>/FixPt Relational Operator' incorporates:
   *  Delay: '<S4>/Delay'
   *  UnitDelay: '<S17>/Delay Input1'
   *
   * Block description for '<S17>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_LogicalOperator5 = ((int32_T)stepMotor_DW.Delay_DSTATE[0] < (int32_T)
    stepMotor_DW.DelayInput1_DSTATE_ca);

  /* S-Function (sdspcount2): '<S4>/Counter' */
  if (MWDSP_EPH_R_B(stepMotor_B.LogicalOperator4,
                    &stepMotor_DW.Counter_RstEphState) != 0U) {
    stepMotor_DW.Counter_Count_o = 0U;
  }

  if (MWDSP_EPH_R_B(rtb_LogicalOperator5, &stepMotor_DW.Counter_ClkEphState) !=
      0U) {
    stepMotor_DW.Counter_Count_o++;
  }

  /* S-Function (sdspcount2): '<S4>/Counter1' */
  if (MWDSP_EPH_R_B(stepMotor_B.LogicalOperator4,
                    &stepMotor_DW.Counter1_RstEphState) != 0U) {
    stepMotor_DW.Counter1_Count = 0U;
  }

  if (MWDSP_EPH_R_B(rtb_LogicalOperator_j, &stepMotor_DW.Counter1_ClkEphState)
      != 0U) {
    stepMotor_DW.Counter1_Count++;
  }

  /* Logic: '<S4>/Logical Operator1' incorporates:
   *  Constant: '<S16>/Constant'
   *  RelationalOperator: '<S16>/Compare'
   *  S-Function (sdspcount2): '<S4>/Counter'
   *  S-Function (sdspcount2): '<S4>/Counter1'
   *  Sum: '<S4>/Add'
   */
  rtb_LogicalOperator5 = (rtb_LogicalOperator5 && ((uint8_T)((uint32_T)
    stepMotor_DW.Counter_Count_o + stepMotor_DW.Counter1_Count) < 2));

  /* Logic: '<S4>/Logical Operator7' incorporates:
   *  Logic: '<S4>/Logical Operator9'
   *  UnitDelay: '<S1>/Unit Delay'
   */
  stepMotor_DW.UnitDelay_DSTATE_b = (rtb_LogicalOperator_j ||
    (stepMotor_B.LogicalOperator4 || rtb_LogicalOperator5));

  /* RelationalOperator: '<S10>/FixPt Relational Operator' incorporates:
   *  UnitDelay: '<S10>/Delay Input1'
   *  UnitDelay: '<S1>/Unit Delay'
   *
   * Block description for '<S10>/Delay Input1':
   *
   *  Store in Global RAM
   */
  stepMotor_B.FixPtRelationalOperator = ((int32_T)
    stepMotor_DW.UnitDelay_DSTATE_b > (int32_T)stepMotor_DW.DelayInput1_DSTATE_g);

  /* S-Function (sdspcount2): '<S2>/Counter' incorporates:
   *  UnitDelay: '<S2>/Unit Delay'
   */
  if (MWDSP_EPH_F_B(stepMotor_B.FixPtRelationalOperator,
                    &stepMotor_DW.Counter_RstEphState_f) != 0U) {
    stepMotor_DW.Counter_Count = 0U;
  }

  if (MWDSP_EPH_F_B(stepMotor_DW.UnitDelay_DSTATE_f,
                    &stepMotor_DW.Counter_ClkEphState_i) != 0U) {
    stepMotor_DW.Counter_Count++;
  }

  /* Switch: '<S12>/Switch' incorporates:
   *  Gain: '<S2>/Gain'
   *  UnitDelay: '<S12>/Unit Delay'
   */
  if (rtb_FixPtRelationalOperator_j) {
    /* Switch: '<S2>/Switch' incorporates:
     *  Constant: '<S2>/Constant'
     *  Gain: '<S2>/Gain2'
     *  Lookup_n-D: '<S2>/1-D Lookup Table'
     *  Lookup_n-D: '<S2>/1-D Lookup Table1'
     *  Product: '<S2>/Divide'
     *  S-Function (sdspcount2): '<S2>/Counter'
     *  Sum: '<S2>/Subtract'
     */
    if (rtb_Switch1 > 200U) {
      rtb_Switch_k = look1_iflf_binlcapw((real32_T)((real_T)
        stepMotor_DW.Counter_Count / ((real_T)rtb_Switch1 - 1.0)) * 100.0F,
        stepMotor_ConstP.uDLookupTable_bp01Data,
        stepMotor_ConstP.uDLookupTable_tableData, 13U);
    } else {
      rtb_Switch_k = look1_iflf_binlcapw((real32_T)((real_T)
        stepMotor_DW.Counter_Count / ((real_T)rtb_Switch1 - 1.0)) * 100.0F,
        stepMotor_ConstP.uDLookupTable1_bp01Data,
        stepMotor_ConstP.uDLookupTable1_tableData, 13U);
    }

    /* End of Switch: '<S2>/Switch' */
    stepMotor_DW.UnitDelay_DSTATE = 29.8F * rtb_Switch_k;
  }

  /* End of Switch: '<S12>/Switch' */

  /* RelationalOperator: '<S12>/Relational Operator' incorporates:
   *  Gain: '<S12>/Gain'
   *  UnitDelay: '<S12>/Unit Delay'
   *  UnitDelay: '<S2>/Unit Delay'
   */
  stepMotor_DW.UnitDelay_DSTATE_f = (rtb_dt < 0.5F *
    stepMotor_DW.UnitDelay_DSTATE);

  /* Logic: '<S4>/Logical Operator5' */
  rtb_LogicalOperator5 = (rtb_LogicalOperator5 || rtb_LogicalOperator_j);

  /* Switch: '<S18>/Switch1' incorporates:
   *  Logic: '<S18>/Logical Operator6'
   *  Logic: '<S18>/Logical Operator8'
   *  UnitDelay: '<S18>/Unit Delay2'
   *  UnitDelay: '<S2>/Unit Delay1'
   */
  if ((!stepMotor_DW.UnitDelay1_DSTATE_f) || rtb_LogicalOperator5) {
    stepMotor_DW.UnitDelay2_DSTATE_i = rtb_LogicalOperator5;
  }

  /* End of Switch: '<S18>/Switch1' */

  /* BusAssignment: '<S1>/Bus Assignment' incorporates:
   *  UnitDelay: '<S23>/Delay Input1'
   *
   * Block description for '<S23>/Delay Input1':
   *
   *  Store in Global RAM
   */
  sigOutput.enable = stepMotor_DW.DelayInput1_DSTATE;

  /* Switch: '<S1>/Switch' incorporates:
   *  UnitDelay: '<S2>/Unit Delay1'
   */
  if (stepMotor_DW.UnitDelay1_DSTATE_f) {
    /* BusAssignment: '<S1>/Bus Assignment' incorporates:
     *  UnitDelay: '<S2>/Unit Delay'
     */
    sigOutput.step = stepMotor_DW.UnitDelay_DSTATE_f;
  } else {
    /* BusAssignment: '<S1>/Bus Assignment' incorporates:
     *  DataTypeConversion: '<S5>/Data Type Conversion'
     */
    sigOutput.step = rtb_UnitDelay_j;
  }

  /* End of Switch: '<S1>/Switch' */

  /* BusAssignment: '<S1>/Bus Assignment' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion'
   *  Logic: '<S1>/Logical Operator2'
   *  UnitDelay: '<S18>/Unit Delay2'
   */
  sigOutput.direction = (uint8_T)(rtb_LogicalOperator1 ||
    stepMotor_DW.UnitDelay2_DSTATE_i);
  sigOutput.moveRange = rtb_Abs;
  sigOutput.enSave = rtb_DataTypeConversion;

  /* RelationalOperator: '<S12>/Relational Operator1' incorporates:
   *  UnitDelay: '<S11>/Unit Delay'
   *  UnitDelay: '<S12>/Unit Delay'
   */
  stepMotor_DW.UnitDelay_DSTATE_i = (rtb_dt < stepMotor_DW.UnitDelay_DSTATE);

  /* RelationalOperator: '<S5>/Relational Operator1' */
  rtb_LogicalOperator1 = (rtb_Subtract_mm >= 298U);

  /* Switch: '<S5>/Switch' incorporates:
   *  Inport: '<Root>/input'
   *  Logic: '<S5>/Logical Operator'
   *  RelationalOperator: '<S19>/FixPt Relational Operator'
   *  RelationalOperator: '<S20>/FixPt Relational Operator'
   *  UnitDelay: '<S19>/Delay Input1'
   *  UnitDelay: '<S20>/Delay Input1'
   *  UnitDelay: '<S5>/Unit Delay'
   *
   * Block description for '<S19>/Delay Input1':
   *
   *  Store in Global RAM
   *
   * Block description for '<S20>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (((int32_T)rtb_LogicalOperator1 > (int32_T)
       stepMotor_DW.DelayInput1_DSTATE_go) || ((int32_T)rtb_LogicalOperator1_kl >
       (int32_T)stepMotor_DW.DelayInput1_DSTATE_f)) {
    stepMotor_DW.UnitDelay_DSTATE_l = sigInput.timeStamp;
  }

  /* End of Switch: '<S5>/Switch' */

  /* Switch: '<S8>/Switch1' incorporates:
   *  Constant: '<S8>/Constant1'
   *  Logic: '<S8>/Logical Operator2'
   *  UnitDelay: '<S8>/Unit Delay2'
   */
  if (rtb_LogicalOperator6_l) {
    stepMotor_DW.UnitDelay2_DSTATE_j = false;
  } else {
    stepMotor_DW.UnitDelay2_DSTATE_j = (rtb_LogicalOperator1_kl ||
      stepMotor_DW.UnitDelay2_DSTATE_j);
  }

  /* End of Switch: '<S8>/Switch1' */

  /* Update for UnitDelay: '<S2>/Unit Delay1' incorporates:
   *  Logic: '<S2>/Logical Operator'
   *  Logic: '<S2>/Logical Operator1'
   *  RelationalOperator: '<S2>/Relational Operator'
   *  S-Function (sdspcount2): '<S2>/Counter'
   */
  stepMotor_DW.UnitDelay1_DSTATE_f = (stepMotor_B.FixPtRelationalOperator ||
    (stepMotor_DW.UnitDelay1_DSTATE_f && (stepMotor_DW.Counter_Count <
    rtb_Switch1)));

  /* Update for UnitDelay: '<S23>/Delay Input1' incorporates:
   *  Inport: '<Root>/input'
   *
   * Block description for '<S23>/Delay Input1':
   *
   *  Store in Global RAM
   */
  stepMotor_DW.DelayInput1_DSTATE = sigInput.trig;

  /* Update for UnitDelay: '<S7>/Unit Delay' */
  stepMotor_DW.UnitDelay_DSTATE_p = rtb_UnitDelay1;

  /* Update for UnitDelay: '<S22>/Delay Input1'
   *
   * Block description for '<S22>/Delay Input1':
   *
   *  Store in Global RAM
   */
  stepMotor_DW.DelayInput1_DSTATE_c = rtb_UnitDelay_h;

  /* Update for UnitDelay: '<S14>/Delay Input1' incorporates:
   *  DataTypeConversion: '<S5>/Data Type Conversion'
   *
   * Block description for '<S14>/Delay Input1':
   *
   *  Store in Global RAM
   */
  stepMotor_DW.DelayInput1_DSTATE_h = rtb_UnitDelay_j;

  /* Update for UnitDelay: '<S21>/Delay Input1'
   *
   * Block description for '<S21>/Delay Input1':
   *
   *  Store in Global RAM
   */
  stepMotor_DW.DelayInput1_DSTATE_m = rtb_DataTypeConversion;

  /* Update for UnitDelay: '<S13>/Delay Input1'
   *
   * Block description for '<S13>/Delay Input1':
   *
   *  Store in Global RAM
   */
  stepMotor_DW.DelayInput1_DSTATE_h1 = rtb_LogicalOperator;

  /* Update for Delay: '<S4>/Delay' */
  for (rtb_UnitDelay2_b = 0; rtb_UnitDelay2_b < 999; rtb_UnitDelay2_b++) {
    stepMotor_DW.Delay_DSTATE[rtb_UnitDelay2_b] =
      stepMotor_DW.Delay_DSTATE[rtb_UnitDelay2_b + 1];
  }

  stepMotor_DW.Delay_DSTATE[999] = rtb_UnitDelay1;

  /* End of Update for Delay: '<S4>/Delay' */

  /* Update for UnitDelay: '<S17>/Delay Input1'
   *
   * Block description for '<S17>/Delay Input1':
   *
   *  Store in Global RAM
   */
  stepMotor_DW.DelayInput1_DSTATE_ca = rtb_LogicalOperator1_m;

  /* Update for UnitDelay: '<S10>/Delay Input1' incorporates:
   *  UnitDelay: '<S1>/Unit Delay'
   *
   * Block description for '<S10>/Delay Input1':
   *
   *  Store in Global RAM
   */
  stepMotor_DW.DelayInput1_DSTATE_g = stepMotor_DW.UnitDelay_DSTATE_b;

  /* Update for UnitDelay: '<S19>/Delay Input1'
   *
   * Block description for '<S19>/Delay Input1':
   *
   *  Store in Global RAM
   */
  stepMotor_DW.DelayInput1_DSTATE_go = rtb_LogicalOperator1;

  /* Update for UnitDelay: '<S20>/Delay Input1'
   *
   * Block description for '<S20>/Delay Input1':
   *
   *  Store in Global RAM
   */
  stepMotor_DW.DelayInput1_DSTATE_f = rtb_LogicalOperator1_kl;
}

/* Model initialize function */
void stepMotor_initialize(void)
{
  /* InitializeConditions for S-Function (sdspcount2): '<S4>/Counter' */
  stepMotor_DW.Counter_ClkEphState = 5U;
  stepMotor_DW.Counter_RstEphState = 5U;

  /* InitializeConditions for S-Function (sdspcount2): '<S4>/Counter1' */
  stepMotor_DW.Counter1_ClkEphState = 5U;
  stepMotor_DW.Counter1_RstEphState = 5U;

  /* InitializeConditions for S-Function (sdspcount2): '<S2>/Counter' */
  stepMotor_DW.Counter_ClkEphState_i = 5U;
  stepMotor_DW.Counter_RstEphState_f = 5U;
}

/* Model terminate function */
void stepMotor_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
