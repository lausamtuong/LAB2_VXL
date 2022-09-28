/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
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

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "SOFTWARE_TIMER.h"
#include "BUTTON.h"
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
TIM_HandleTypeDef htim2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void display7SEG(int count_time){
		  switch(count_time){
		  case 0:{
			  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_6,1);
			  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,0);
			  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,0);
			  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_2,0);
			  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_3,0);
			  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_4,0);
			  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,0);


			  break ;
		  	  };
		  case 1:{
			  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_6,1);
			  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,1);
			  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,0);
			  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_2,0);
			  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_3,1);
			  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_4,1);
			  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,1);
			  break ;
		  	  };
		  case 2:{
			  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,0);
			   HAL_GPIO_WritePin(GPIOB,GPIO_PIN_2,1);
			   HAL_GPIO_WritePin(GPIOB,GPIO_PIN_3,0);
			   HAL_GPIO_WritePin(GPIOB,GPIO_PIN_4,0);
			   HAL_GPIO_WritePin(GPIOB,GPIO_PIN_6,0);
			   HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,0);
			   HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,1);
			   break ;
		  };
		  case 3: {
			  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,0);
			  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,0);
			  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_2,0);
			  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_3,0);
			  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_4,1);
			  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,1);
			  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_6,0);
			  break;
		  };
		  case 4:{
			  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,1);
			  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,0);
			  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_2,0);
			  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_3,1);
			  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_4,1);
			  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,0);
			  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_6,0);
			  break;
		  };
		  case 5:{
			  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,0);
			  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,1);
			  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_2,0);
			  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_3,0);
			  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_4,1);
			  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,0);
			  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_6,0);

			  break;
		  };
		  case 6:{
			  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,0);
			  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,1);
			  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_2,0);
			  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_3,0);
			  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_4,0);
			  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,0);
			  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_6,0);
			  break;
		  };
		  case 7:{
			  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,0);
			  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,0);
			  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_2,0);
			  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_3,1);
			  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_4,1);
			  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,1);
			  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_6,1);

			  break;
		  };
		  case 8:{
			  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,0);
			  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,0);
			  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_2,0);
			  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_3,0);
			  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_4,0);
			  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,0);
			  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_6,0);
			 		  break;
		  };
		  case 9:{
			  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_4,1);
			  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,0);
			  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,0);
			  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_2,0);
			  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_3,0);
			  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,0);
			  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_6,0);
			  count_time=-1;
			  break;
		  };

		  };



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
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
	HAL_TIM_Base_Start_IT (& htim2 ) ;
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

	setTimer1(50);
	setTimer2(50);
	int status= 0;
	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin,1);
	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin,1);
	while (1) {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
		if (timer1_flag == 1) {
			setTimer1(50);
			switch (status){
				case 0:{
					display7SEG(1);
					HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin,0);
					HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin,1);
					status++;
					break;
				};
				case 1:{
					display7SEG(2);
					HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin,1);
					HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin,0);
					status=0;
					break;
				};
				default:break;
			}

		}

  /* USER CODE END 3 */
}
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
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 7999;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 9;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, led_green_Pin|LED_REDD_Pin|LED_GREENN_Pin|led_red_Pin
                          |LED_RED_Pin|EN0_Pin|EN1_Pin|LED_5_Pin
                          |LED_6_Pin|LED_7_Pin|LED_8_Pin|LED_9_Pin
                          |LED_10_Pin|LED_11_Pin|LED_12_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_10
                          |GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7
                          |GPIO_PIN_8|GPIO_PIN_9, GPIO_PIN_RESET);

  /*Configure GPIO pin : Button1_Pin */
  GPIO_InitStruct.Pin = Button1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(Button1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : led_green_Pin LED_REDD_Pin LED_GREENN_Pin led_red_Pin
                           LED_RED_Pin EN0_Pin EN1_Pin LED_5_Pin
                           LED_6_Pin LED_7_Pin LED_8_Pin LED_9_Pin
                           LED_10_Pin LED_11_Pin LED_12_Pin */
  GPIO_InitStruct.Pin = led_green_Pin|LED_REDD_Pin|LED_GREENN_Pin|led_red_Pin
                          |LED_RED_Pin|EN0_Pin|EN1_Pin|LED_5_Pin
                          |LED_6_Pin|LED_7_Pin|LED_8_Pin|LED_9_Pin
                          |LED_10_Pin|LED_11_Pin|LED_12_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PB0 PB1 PB2 PB10
                           PB11 PB12 PB13 PB3
                           PB4 PB5 PB6 PB7
                           PB8 PB9 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_10
                          |GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7
                          |GPIO_PIN_8|GPIO_PIN_9;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
		void HAL_TIM_PeriodElapsedCallback ( TIM_HandleTypeDef * htim )
		{

			 if (htim->Instance == TIM2) {
				timerRun();
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
		while (1) {
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
