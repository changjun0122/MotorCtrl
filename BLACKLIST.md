# 黑名单（不上传 / 不同步清单）

给人看的说明文件。真正生效的忽略规则在 `.gitignore`；每天 06:00 的自动同步任务也内置了同样的排除逻辑。

## 一、不进 Git 仓库的文件

**目录**：`Debug/`、`Release/`、`build/`、`cmake-build-*/`、`Objects/`、`Listings/`、`Output/`、`.vscode/`、`.idea/`、`.workbuddy/`、`__pycache__/`

**后缀**：`.o .obj .d .su .elf .hex .bin .map .axf .lst .crf .dep .lnp .sct .a .lib .uvguix.* .bak .tmp .log`

**其他**：`Thumbs.db`、`.DS_Store`；单个文件大于 20MB 的不提交（报告里会点名提示）。

**明确保留**：`.pdf` / `.docx` / `.xlsx` 等资料、`MotorCtrl.ioc`、`*.ld`、`.project` / `.cproject` / `.mxproject` / `.settings`，以及 `Core/`、`Drivers/` 下全部源码。

## 二、不参与每日自动同步的本地目录（已移除）

- `D:\git-start`
- `D:\stm32\HAL`
- `D:\stm32\FreeRTOS`
- `D:\study\Network Programming\StudentManager`

这四个目录已从每日 06:00 的任务中移除。任务不监控、不提交、不推送，也不要再加回去。

## 三、当前参与同步的 3 个仓库（对照）

| 本地目录 | GitHub 仓库 |
|---|---|
| `D:\study\low-power-wireless-alarm` | `changjun0122/low-power-wireless-alarm` |
| `D:\study\EDA\docking-station` | `changjun0122/docking-station` |
| `D:\study\MotorCtrl\MotorCtrl` | `changjun0122/MotorCtrl` |

## 四、任务不会做的事

不自行解决冲突、不 force push、不删除或改动源码、不在仓库里另建说明或日志文件；远端有冲突时只报告，等人工处理。
