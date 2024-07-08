/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "tim.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
const uint32_t addr_base = 0x0800fc00;
const uint32_t T_map[150] = {1333, 1324, 1316, 1307, 1298, 1289, 1281, 1272, 1263, 1254, 1246, 1237, 1228, 1219, 1211, 1202, 1193, 1184, 1176, 1167, 1158, 1149, 1141, 1132, 1123, 1114, 1106, 1097, 1088, 1079, 1071, 1062, 1053, 1044, 1036, 1027, 1018, 1009, 1001, 992, 983, 974, 966, 957, 948, 939, 931, 922, 913, 904, 896, 887, 878, 870, 861, 852, 843, 835, 826, 817, 808, 800, 791, 782, 773, 765, 756, 747, 738, 730, 721, 712, 703, 695, 686, 677, 668, 660, 651, 642, 633, 625, 616, 607, 598, 590, 581, 572, 563, 555, 546, 537, 528, 520, 511, 502, 493, 485, 476, 467, 459, 450, 441, 432, 424, 415, 406, 397, 389, 380, 371, 362, 354, 345, 336, 327, 319, 310, 301, 292, 284, 275, 266, 257, 249, 240, 231, 222, 214, 205, 196, 187, 179, 170, 161, 152, 144, 135, 126, 117, 109, 100, 91, 82, 74, 65, 56, 47, 39, 30};
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

static void readVal(uint32_t *val)
{
    uint32_t addr = addr_base;
    *val = *(__IO uint32_t *) (addr);
}

static void saveValue(uint32_t val)
{
    HAL_FLASH_Unlock();
    FLASH_EraseInitTypeDef f;
    f.TypeErase = FLASH_TYPEERASE_PAGES;
    f.PageAddress = addr_base;
    f.NbPages = 1;
    uint32_t PageError = 0;
    HAL_FLASHEx_Erase(&f, &PageError);
    HAL_FLASH_Program(TYPEPROGRAM_WORD, addr_base, val);
    HAL_FLASH_Lock();
}
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
static int32_t pos1;
static int32_t pos2;

static uint8_t movedFlag; // moved:1, never moved:0
static uint8_t direction; // Up:1, Down: 0
static uint8_t moving; // moving:1, station: 0
static uint8_t userControl; // control:1
static uint8_t waitingMoveUp; // waiting:1

static int32_t gCnt;
static uint32_t gNum;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

static uint32_t GetTimeStampUS()
{
    // get ms
    uint32_t m = HAL_GetTick();
    // get tick reload value
    const uint32_t tms = SysTick->LOAD + 1;
    // get tick value
    __IO uint32_t u = tms - SysTick->VAL;
    // return value
    return(m*1000+(u*1000)/tms);
}

void addPos(int32_t val)
{
    pos1 = pos2;
    pos2 = val;
}

uint32_t getT(uint32_t num)
{
    return T_map[num];
}

void sendPulse(uint32_t nums)
{
    gNum = nums;
    HAL_TIM_PWM_Start_IT(&htim1, TIM_CHANNEL_1);
}

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM1_Init();
  /* USER CODE BEGIN 2 */
  static uint32_t timestamp;
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
      if(1 != moving)
      {
          if(timestamp + 300000 < GetTimeStampUS())
          {
              // check user button
              uint8_t clickUp = 1-HAL_GPIO_ReadPin(Up_GPIO_Port, Up_Pin);
              uint8_t clickDw = 1- HAL_GPIO_ReadPin(Down_GPIO_Port, Down_Pin);
              uint8_t clickTrg = 1 - HAL_GPIO_ReadPin(Trig_GPIO_Port, Trig_Pin);

              if(clickUp)
              {
                  userControl = 1;
                  direction = 1;
                  movedFlag = 1;
                  HAL_GPIO_WritePin(Dir_GPIO_Port, Dir_Pin, direction);
                  HAL_GPIO_WritePin(En_GPIO_Port, En_Pin, 1);
                  sendPulse(1);
              }

              if(clickDw)
              {
                  userControl = 1;
                  direction = 0;
                  movedFlag = 1;
                  HAL_GPIO_WritePin(Dir_GPIO_Port, Dir_Pin, direction);
                  HAL_GPIO_WritePin(En_GPIO_Port, En_Pin, 1);
                  sendPulse(1);
              }

              if(clickTrg)
              {
                  if(movedFlag)
                  {
                      addPos(gCnt);
                      movedFlag = 0;
                  }
                  else
                  {
                      int32_t moveRange = pos2 - pos1;
                      if( moveRange < 0)
                      {
                          // just move up
                          direction = 1;
                          HAL_GPIO_WritePin(Dir_GPIO_Port, Dir_Pin, direction);
                          HAL_GPIO_WritePin(En_GPIO_Port, En_Pin, 1);
                          saveValue(-moveRange);
                          sendPulse(-moveRange);
                          pos1 = 0;
                          pos2 = 0;
                          gCnt = 0;
                      }
                      else if( moveRange > 0)
                      {
                          // move down and up
                          direction = 0;
                          HAL_GPIO_WritePin(Dir_GPIO_Port, Dir_Pin, direction);
                          HAL_GPIO_WritePin(En_GPIO_Port, En_Pin, 1);
                          saveValue(moveRange);
                          waitingMoveUp = 1;
                          sendPulse(moveRange);
                          pos1 = 0;
                          pos2 = 0;
                          gCnt = 0;

                      }
                      else
                      {
                          // send NVM value
                          uint32_t temMoveRange=0;
                          readVal(&temMoveRange);
                          direction = 0;
                          HAL_GPIO_WritePin(Dir_GPIO_Port, Dir_Pin, direction);
                          HAL_GPIO_WritePin(En_GPIO_Port, En_Pin, 1);
                          waitingMoveUp = 1;
                          sendPulse(temMoveRange);
                      }

                  }
                  timestamp = GetTimeStampUS();

              }
          }
      }
      else
      {
          // moving, do nothing
          timestamp = GetTimeStampUS();
      }
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
static uint32_t pulse;
void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim)
{
    if(userControl)
    {
        if(direction)
        {
            gCnt ++;
        }
        else
        {
            gCnt --;
        }
    }

    pulse ++;

    uint32_t centerNum = gNum/2;

    if(centerNum >= 150)
    {
        centerNum = 150;
    }

    if(pulse < centerNum)
    {
        htim1.Instance->PSC = T_map[pulse];
    }
    else
    {
        uint32_t tem_pulse = gNum - pulse;
        if(tem_pulse < centerNum)
        {
            htim1.Instance->PSC = T_map[tem_pulse];
        }
    }

    if(pulse >= gNum)
    {
        HAL_TIM_PWM_Stop_IT(&htim1, TIM_CHANNEL_1);
        htim1.Instance->PSC = T_map[0];
        pulse = 0;
        moving = 0;
        userControl = 0;
        direction = 0;

        HAL_GPIO_WritePin(Dir_GPIO_Port, Dir_Pin, 0);
        HAL_GPIO_WritePin(En_GPIO_Port, En_Pin, 0);

        if(waitingMoveUp)
        {
            waitingMoveUp = 0;
            direction = 1;
            HAL_GPIO_WritePin(Dir_GPIO_Port, Dir_Pin, direction);
            HAL_GPIO_WritePin(En_GPIO_Port, En_Pin, 1);
            htim1.Instance->PSC = T_map[0];
            sendPulse(gNum);
        }
    }
    else
    {
        moving = 1;
    }
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
