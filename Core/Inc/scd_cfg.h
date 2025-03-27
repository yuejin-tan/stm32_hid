/**
 * @file scd_cfg.h
 * @brief SCD�������ļ��������ֶ��������޸ĺ�ֵ���޸ľ�������
 * @author Tangent (498339337@qq.com)
 * @date 2022-04-07
 * 
 * @copyright Copyright (c) 2022 @Tangent
 */

#ifndef INC_SCD_CFG_H_
#define INC_SCD_CFG_H_

#include "stdint.h"

#ifdef __cplusplus
extern "C"
{
#endif

#define SCD_VERSION "V0.2.2"

/// �����ַ�������Ļ�������С���������39�ַ�
#define SCD_REVBUFF_SIZE 40
/// ���ͱ���������б�����1֡��෢��16������(ȡ������λ����MCU���ʵ��)
#define SCD_SEND_TAB_SIZE 20
/// ֧�ֵ�Э������
#define SCD_PROTOCOL_NUM 5
/// ֧�ֵ��ַ�����������
#define SCD_CMD_NUM 5
/// ÿ֡������ݳ���
#define SCD_MAX_NUMS_PER_FRAME 1001
/// ���DUMP����
#define SCD_MAX_DUMP_COUNT 32000
/// print�����Ļ�������С���������39�ַ�
#define SCD_PRINTBUFF_SIZE 40

/// �Ƿ�������TI DSP��ramfuncs����
#define SCD_IF_USE_RAM_FUNCS 0
#define SCD_IF_USE_HIGH_VER_TI_COMPLIER 1

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif /* INC_SCD_CFG_H_ */
