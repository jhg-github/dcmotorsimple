/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
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
#include "adc.h"
#include "opamp.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

#include "../../Com/com.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

//static volatile uint16_t val = 3599;
//static uint16_t buffer[1000];
//__IO uint16_t uhADCxConvertedValue = 0;
//void test_Test1(void){
//	TIM_HandleTypeDef    TimHandle;
//	TIM_OC_InitTypeDef sConfig;
//	static uint16_t diff;
//	static uint16_t old = 0;
//	static uint16_t new;
//	uint16_t diff_array[100];
//	uint32_t i;
//
//	/* Run the ADC calibration in single-ended mode */
//	  if (HAL_ADCEx_Calibration_Start(&hadc2, ADC_SINGLE_ENDED) != HAL_OK)
//	  {
//	    /* Calibration Error */
//	    Error_Handler();
//	  }
//	  /* Infinite loop */
//	    while (1)
//	    {
//
//	      /*##-3- Start the conversion process #######################################*/
//	      if (HAL_ADC_Start(&hadc2) != HAL_OK)
//	      {
//	        /* Start Conversation Error */
//	        Error_Handler();
//	      }
//
//	      /*##-4- Wait for the end of conversion #####################################*/
//	      /*  For simplicity reasons, this example is just waiting till the end of the
//	      conversion, but application may perform other tasks while conversion
//	      operation is ongoing. */
//	      if (HAL_ADC_PollForConversion(&hadc2, 10) != HAL_OK)
//	      {
//	        /* End Of Conversion flag not set on time */
//	        Error_Handler();
//	      }
//	      else
//	      {
//	        /* ADC conversion completed */
//	        /*##-5- Get the converted value of regular channel  ######################*/
//	        uhADCxConvertedValue = HAL_ADC_GetValue(&hadc2);
//	      }
//	    }
//
//
//	  com_Test_SendBuffer( (uint8_t *)buffer, 2000);
//
//	  HAL_TIM_PWM_Start(&htim16, TIM_CHANNEL_1);
//	  LL_GPIO_SetOutputPin(EN_A_GPIO_Port, EN_A_Pin);
//
//	  __HAL_TIM_SET_COMPARE(&htim16, TIM_CHANNEL_1, val);
//	  HAL_TIM_Encoder_Start(&htim1,TIM_CHANNEL_ALL);
//	  while (1)
//	  {
//	//	  __HAL_TIM_SET_COMPARE(&htim16, TIM_CHANNEL_1, 900-1);
//	//	  HAL_Delay(1000);
//	//	  __HAL_TIM_SET_COMPARE(&htim16, TIM_CHANNEL_1, 1800-1);
//	//	  HAL_Delay(1000);
//	//	  __HAL_TIM_SET_COMPARE(&htim16, TIM_CHANNEL_1, 2700-1);
//	//	  HAL_Delay(1000);
//	//	  __HAL_TIM_SET_COMPARE(&htim16, TIM_CHANNEL_1, val);
//	//	   HAL_Delay(1000);
//
//		  old = TIM1->CNT;
//		  for(i=0;i<100;i++){
//			  HAL_Delay(10);
//			  new = TIM1->CNT;
//			  diff_array[i] = new - old;
//			  old = new;
//		  }
//
//		  LL_GPIO_ResetOutputPin(EN_A_GPIO_Port, EN_A_Pin);
//		  __HAL_TIM_SET_COMPARE(&htim16, TIM_CHANNEL_1, 0);
//		  while(1);
//}

//void test_ContinuousSingleDirection(void){
//	LL_GPIO_SetOutputPin(IN1_B_GPIO_Port, IN1_B_Pin);
//	LL_GPIO_ResetOutputPin(IN2_B_GPIO_Port, IN2_B_Pin);
//	LL_GPIO_SetOutputPin(EN_B_GPIO_Port, EN_B_Pin);
//	while(1);
//}
//
//__IO uint16_t adcValue = 0;
//__IO float adcValue_mV = 0;
//__IO float adcValue_mA = 0;
//void test_ContinuousSingleDirectionADC(void){
//	LL_GPIO_SetOutputPin(IN1_B_GPIO_Port, IN1_B_Pin);
//	LL_GPIO_ResetOutputPin(IN2_B_GPIO_Port, IN2_B_Pin);
//	LL_GPIO_SetOutputPin(EN_B_GPIO_Port, EN_B_Pin);
//	HAL_ADCEx_Calibration_Start(&hadc2, ADC_SINGLE_ENDED);
//	while(1){
//		HAL_ADC_Start(&hadc2);
//		HAL_ADC_PollForConversion(&hadc2, 10);
//		adcValue = HAL_ADC_GetValue(&hadc2);
//		adcValue_mV = adcValue * 0.805664F;
//		adcValue_mA = (adcValue_mV-40) / (31*0.05F);
//	}
//}

//#define N (10000)
//void test_mANoise(void){
//	uint16_t adcValue = 0;
//	float adcValue_mV = 0;
//	float adcValue_mA[N];
//	unsigned int index = N;
//
//	LL_GPIO_SetOutputPin(IN1_B_GPIO_Port, IN1_B_Pin);
//	LL_GPIO_ResetOutputPin(IN2_B_GPIO_Port, IN2_B_Pin);
//	LL_GPIO_SetOutputPin(EN_B_GPIO_Port, EN_B_Pin);
//	HAL_Delay(1000);
//	HAL_ADCEx_Calibration_Start(&hadc2, ADC_SINGLE_ENDED);
//	while(index--){
//		HAL_Delay(1);
//		HAL_ADC_Start(&hadc2);
//		HAL_ADC_PollForConversion(&hadc2, 10);
//		adcValue = HAL_ADC_GetValue(&hadc2);
//		adcValue_mV = adcValue * 0.805664F;
//		adcValue_mA[index] = (adcValue_mV-40) / (31*0.05F);
//	}
//	com_Test_SendBuffer( (uint8_t *)&adcValue_mA[0] , 4*N);
//	while(1);
//}

//void test_PwmSimple(void){
//	LL_GPIO_ResetOutputPin(IN2_B_GPIO_Port, IN2_B_Pin);
//	LL_GPIO_SetOutputPin(EN_B_GPIO_Port, EN_B_Pin);
//	__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, 0);
//	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
//	LL_GPIO_SetOutputPin(EN_B_GPIO_Port, EN_B_Pin);
//	while(1){
//		HAL_Delay(5000);
//		LL_GPIO_SetOutputPin(DEBUG_PIN_GPIO_Port, DEBUG_PIN_Pin);
//		__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, 500);
//		HAL_Delay(500);
//		LL_GPIO_ResetOutputPin(DEBUG_PIN_GPIO_Port, DEBUG_PIN_Pin);
//		__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, 0);
//		LL_GPIO_ResetOutputPin(IN1_B_PWM_GPIO_Port, IN1_B_PWM_Pin);
//	}
//	HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_1);
//}

//__IO uint16_t adcValue = 0;
//#define N 1000
//float mA_Array[N];
//void test_PwmADCSimple(void){
//	uint16_t counter = 0;
//	HAL_ADCEx_Calibration_Start(&hadc2, ADC_SINGLE_ENDED);
//
//	LL_GPIO_ResetOutputPin(IN2_B_GPIO_Port, IN2_B_Pin);
//	LL_GPIO_SetOutputPin(EN_B_GPIO_Port, EN_B_Pin);
//	__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, 2000);
//	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
//
//	while(counter < N){
//		HAL_ADC_Start(&hadc2);
//		HAL_ADC_PollForConversion(&hadc2, 10);
//		adcValue = HAL_ADC_GetValue(&hadc2);
//		adcValue = adcValue >> 2;
//		mA_Array[counter]=((adcValue * 3.22265625F)-43)/(31*0.05);
//		//mA_Array[counter]=((adcValue * 0.805664063F)-43)/(31*0.05);
//		counter++;
//	}
//	com_Test_SendBuffer( (uint8_t *)&mA_Array[0] , 4*N);
//	while(1);
//}

//static volatile float pid_setpoint = 0;
////__IO float pid_Kp = 6.9F;
////__IO float pid_KixTs = 0.7256F;
////__IO float pid_lastError = 0;
////__IO float pid_lastIntegral = 0;
////__IO float pid_volts2pwm = 7199/3.3F;
//void test_pid(){
//	HAL_ADCEx_Calibration_Start(&hadc2, ADC_SINGLE_ENDED);
//	HAL_ADC_Start_IT(&hadc2);
//	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
//	__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, 4500);
//}
//void pid(uint16_t adc){
//}

//static volatile uint16_t duty = 300;
//void test_PWMBipolar(){
//	LL_GPIO_SetOutputPin(EN_B_GPIO_Port, EN_B_Pin);
//	LL_GPIO_ResetOutputPin(IN1_B_GPIO_Port, IN1_B_Pin);
//	LL_GPIO_ResetOutputPin(IN2_B_GPIO_Port, IN2_B_Pin);
//	HAL_Delay(500);
//	__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, duty);
//	__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, duty);
//	LL_GPIO_SetOutputPin(DEBUG_PIN_GPIO_Port,DEBUG_PIN_Pin);
//	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
//	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2);
//	HAL_Delay(1);
//	LL_GPIO_ResetOutputPin(DEBUG_PIN_GPIO_Port,DEBUG_PIN_Pin);
//	LL_GPIO_ResetOutputPin(EN_B_GPIO_Port, EN_B_Pin);
//	while(1){
//		__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, duty);
//		__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, duty);
//	}
//
//}

//void test_pulse(){
//	LL_GPIO_SetOutputPin(EN_B_GPIO_Port, EN_B_Pin);
//	LL_GPIO_ResetOutputPin(IN1_B_GPIO_Port, IN1_B_Pin);
//	LL_GPIO_ResetOutputPin(IN2_B_GPIO_Port, IN2_B_Pin);
//	while(1){
//		HAL_Delay(5000);
//		LL_GPIO_SetOutputPin(DEBUG_PIN_GPIO_Port,DEBUG_PIN_Pin);
//		LL_GPIO_SetOutputPin(IN1_B_GPIO_Port, IN1_B_Pin);
//		HAL_Delay(5);
//		LL_GPIO_ResetOutputPin(DEBUG_PIN_GPIO_Port,DEBUG_PIN_Pin);
//		LL_GPIO_ResetOutputPin(IN1_B_GPIO_Port, IN1_B_Pin);
//	}
//}

//void test_pulsePWM(){
//	LL_GPIO_SetOutputPin(EN_B_GPIO_Port, EN_B_Pin);
//	LL_GPIO_ResetOutputPin(IN1_B_GPIO_Port, IN1_B_Pin);
//	LL_GPIO_ResetOutputPin(IN2_B_GPIO_Port, IN2_B_Pin);
//	__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, 0);
//	__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, 0);
//	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
//	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2);
//	__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, 1100);
//	__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, 1100);
//	LL_GPIO_SetOutputPin(DEBUG_PIN_GPIO_Port,DEBUG_PIN_Pin);
////	HAL_Delay(500);
////	while(1){
////		HAL_Delay(5000);
////		__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, 1550);
////		__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, 1550);
////		LL_GPIO_SetOutputPin(DEBUG_PIN_GPIO_Port,DEBUG_PIN_Pin);
////		HAL_Delay(5);
////		__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, 900);
////		__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, 900);
////		LL_GPIO_ResetOutputPin(IN1_B_GPIO_Port, IN1_B_Pin);
////		LL_GPIO_ResetOutputPin(IN2_B_GPIO_Port, IN2_B_Pin);
////		LL_GPIO_ResetOutputPin(DEBUG_PIN_GPIO_Port,DEBUG_PIN_Pin);
////	}
//}

static volatile uint16_t duty = 2000;
static volatile uint16_t duty_adc;
void test_SYNC_PWM_ADC(){
	HAL_ADCEx_Calibration_Start(&hadc2, ADC_SINGLE_ENDED);
	HAL_ADC_Start_IT(&hadc2);
	HAL_OPAMP_SelfCalibrate(&hopamp2);
	HAL_OPAMP_Start(&hopamp2);
	LL_GPIO_SetOutputPin(EN_B_GPIO_Port, EN_B_Pin);
	duty_adc = duty/2;
	__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, duty);
	__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, duty);
	__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_3, duty_adc);
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2);
	HAL_TIM_OC_Start(&htim2, TIM_CHANNEL_3);
//	HAL_TIM_OC_Start_IT(&htim2, TIM_CHANNEL_3);
	while(1){
		duty_adc = duty/2;
		__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, duty);
		__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, duty);
		__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_3, duty_adc);
	}
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
  MX_USART2_UART_Init();
  MX_ADC2_Init();
  MX_TIM2_Init();
  MX_OPAMP2_Init();
  /* USER CODE BEGIN 2 */

  //test_ContinuousSingleDirection();
  //test_ContinuousSingleDirectionADC();
  //test_mANoise();
  //test_PwmSimple();
  //test_PwmADCSimple();
//  test_pid();
//  test_PWMBipolar();
//  test_pulse();
//  test_pulsePWM();
  test_SYNC_PWM_ADC();

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
while(1){

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
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  RCC_OscInitStruct.PLL.PREDIV = RCC_PREDIV_DIV1;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
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
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART2|RCC_PERIPHCLK_TIM2;
  PeriphClkInit.Usart2ClockSelection = RCC_USART2CLKSOURCE_PCLK1;
  PeriphClkInit.Tim2ClockSelection = RCC_TIM2CLK_HCLK;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

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
void assert_failed(char *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
