/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_hal.h"

#include "stm32h7xx_ll_dma.h"
#include "stm32h7xx_ll_rcc.h"
#include "stm32h7xx_ll_crs.h"
#include "stm32h7xx_ll_bus.h"
#include "stm32h7xx_ll_system.h"
#include "stm32h7xx_ll_exti.h"
#include "stm32h7xx_ll_cortex.h"
#include "stm32h7xx_ll_utils.h"
#include "stm32h7xx_ll_pwr.h"
#include "stm32h7xx_ll_spi.h"
#include "stm32h7xx_ll_usart.h"
#include "stm32h7xx_ll_gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define ETH_RST_Pin LL_GPIO_PIN_5
#define ETH_RST_GPIO_Port GPIOA
#define LED_0_Pin LL_GPIO_PIN_0
#define LED_0_GPIO_Port GPIOB
#define OLED_RST_Pin LL_GPIO_PIN_9
#define OLED_RST_GPIO_Port GPIOE
#define OLED_DC_Pin LL_GPIO_PIN_10
#define OLED_DC_GPIO_Port GPIOE
#define LED_1_Pin LL_GPIO_PIN_13
#define LED_1_GPIO_Port GPIOE
#define EEPROM_SCL_Pin LL_GPIO_PIN_10
#define EEPROM_SCL_GPIO_Port GPIOB
#define FLASH_CS_Pin LL_GPIO_PIN_3
#define FLASH_CS_GPIO_Port GPIOD

/* USER CODE BEGIN Private defines */

extern int16_t test1 ;
extern int32_t test2 ;
extern uint16_t test3 ;
extern uint32_t test4 ;
extern float test5 ;

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
