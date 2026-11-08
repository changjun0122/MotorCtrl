# MotorCtrl — STM32 电机控制工程

基于 STM32F103C8T6 与 TB6612 驱动芯片的直流电机控制工程，由 STM32CubeMX 生成、STM32CubeIDE（GCC）构建。

> 当前状态：引脚与外设配置已完成，控制逻辑尚未实现（`Core/Src/main.c` 的 USER CODE 区、`Core/Inc/TB6612.h` 仍为空）。

## 硬件与外设配置

| 项 | 配置 |
|---|---|
| MCU | STM32F103C8Tx（STM32F1 系列） |
| 电机驱动 | TB6612：PB0 = AIN1、PB1 = AIN2、PB5 = STBY |
| 编码器 / PWM | TIM3_CH1 = PA6、TIM3_CH2 = PA7（带上拉）；TIM4_CH3 = PB8 |
| 定时器 | TIM3、TIM4（TIM4 用内部时钟） |
| 串口 | USART2：PA2 = TX、PA3 = RX |
| 其他 | I2C1、NVIC、RCC、SYS |

引脚与时钟的完整配置见 `MotorCtrl.ioc`。

## 目录结构

- `Core/Inc`、`Core/Src`：初始化代码与应用代码（main、gpio、tim、usart、i2c、TB6612、中断处理、MSP）
- `Core/Startup`：启动文件 `startup_stm32f103c8tx.s`
- `Drivers/CMSIS`、`Drivers/STM32F1xx_HAL_Driver`：CMSIS 与 HAL 库，随工程一起纳入版本管理
- `MotorCtrl.ioc`：STM32CubeMX 配置文件，改引脚/时钟后用 CubeMX 打开重新生成
- `STM32F103C8TX_FLASH.ld`：链接脚本
- `.project` / `.cproject` / `.mxproject` / `.settings`：STM32CubeIDE 工程文件
- `BLACKLIST.md`：不上传 / 不同步清单

## 打开与编译

1. STM32CubeIDE → File → Import → Existing Projects into Workspace → 选择本目录。
2. 需要改外设时，用 STM32CubeMX 打开 `MotorCtrl.ioc`，Toolchain 保持 STM32CubeIDE，再 Generate Code。
3. Build Project。编译产物落在 `Debug/` 或 `Release/`，已被 `.gitignore` 排除。

自己写的代码只放在 `/* USER CODE BEGIN ... */` 与 `/* USER CODE END ... */` 之间，重新生成时不会被 CubeMX 覆盖。

## Git 与自动同步

- 远端：`git@github.com:changjun0122/MotorCtrl.git`，分支 `main`。
- 每天 06:00 的本地自动同步任务会检查本目录，有改动时生成中文提交说明并推送。
- 不进仓库的文件、不参与同步的目录，见 `BLACKLIST.md`。
