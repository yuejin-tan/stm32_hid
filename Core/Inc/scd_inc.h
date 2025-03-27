/**
 * @file scd_inc.h
 * @brief SCD��ͷ�ļ�����Ҫ���ݽṹ�ͽӿڵ�����
 * @author Tangent (498339337@qq.com)
 * @date 2022-04-07
 * 
 * @copyright Copyright (c) 2022 @Tangent
 */

#ifndef INC_SCD_INC_H_
#define INC_SCD_INC_H_

#include "stdint.h"

#include "scd_cfg.h"

#ifdef __cplusplus
extern "C"
{
#endif

#define TYJ_uint16_t 0x02u
#define TYJ_int16_t 0x12u
#define TYJ_uint32_t 0x04u
#define TYJ_int32_t 0x14u
#define TYJ_float 0x24u
#define TYJ_function 0x32u
// MCU����ͬ��Ӧ��uint���ͣ���λ����ʾ��ͬ
#define TYJ_bin16 0x02u
#define TYJ_hex16 0x02u
#define TYJ_bin32 0x04u
#define TYJ_hex32 0x04u

   /**
 * @brief scd������¼��Ԫ
 */
   struct TYJ_UNIT_STRUCT
   {
      /// ��ַ
      void *_addr;
      /// ��������
      int16_t _type;
   };

   /**
 * @brief scd���ƽṹ����¼��������״̬��
 */
   struct SCD_CTRL_STRUCT
   {
      /// Ҫ�������ݵı�
      volatile int16_t structToSendTab[SCD_SEND_TAB_SIZE];
      /// ���ܻ�����ָ��
      volatile unsigned char (*_recBuff)[SCD_REVBUFF_SIZE];
      /// print������
      volatile unsigned char *_printBuff;
      /// 1��Э���βֵ
      volatile unsigned char *_endbyte1;
      /// DUMPЭ���βֵ
      volatile unsigned char *_endbyte2;
      /// PRINTЭ���βֵ
      volatile unsigned char *_endbyte3;
      /// ʹ���ĸ����ݼ�¼
      const struct TYJ_UNIT_STRUCT *_unit_struct;
      /// SCO ����buffer
      volatile float tempBuff;
      /// �ܹ��Ľṹ��
      volatile int16_t structNum;
      /// ˫���壬ʹ���ĸ�����
      volatile int16_t bufNum;
      /// ���յ����ֽ���
      volatile int16_t bytesRec;
      /// ���͵��ֽں�
      volatile int16_t byteToSend;
      /// ���ڷ��͵�֡��0��ʾ��ʼ��־λ��������һ��ʾ������־λ
      volatile int16_t structToSend;
      /// ʹ�õķ���Э�����
      volatile int16_t sco_protocol_num;
      /// ��Ҫʹ�õķ���Э�����
      volatile int16_t sco_protocol_num_next;
      /// ���͵��ֽں�,����varЭ��
      volatile int16_t byteToSend2;
      /// ���ڷ��͵�֡��0��ʾ��ʼ��־λ��������һ��ʾ������־λ������varЭ��
      volatile int16_t structToSend2;
      /// ���͵��ֽںţ�����dumpЭ��
      volatile int16_t byteToSend3;
      /// ���ڷ��͵�֡��0��ʾ��ʼ��־λ������dumpЭ��
      volatile int16_t structToSend3;
      /// ��Ҫdump�Ķ����
      volatile int16_t dumpTarget;
      /// ��Ҫdump������
      volatile int16_t dumpNumCnt;
      /// ��������
      volatile int16_t dumpPkgCnt;
      /// �Ƿ�����
      volatile int16_t ifContPkg;
      /// �Ƿ����ڴ�ӡ
      volatile int16_t isPrintBusyFlg;
      /// ��ӡ���ֽں�
      volatile int16_t byteToPrint;
      /// ֡���ֽڱ��
      volatile int16_t byteToSend4;
   };

   /**
 * @brief scd�յ�1���ֽڣ���pc�������ġ���sci�����յ���һ���ֽڷ���data����
 */
   void SCD_Rev1Byte(struct SCD_CTRL_STRUCT *scd, uint16_t data);

   /**
 * @brief scd����һ���ֽڣ�������ֵ����sci���跢������
 * @return uint16_t Ҫ���͸�pc���ֽ�
 */
   uint16_t scd_send1Byte(struct SCD_CTRL_STRUCT *scd);

   /**
 * @brief ͨ��scd����dbg�ַ�������\0��ʾ��β
 * @return uint16_t 0����ɹ���1����ʧ��
 */
   uint16_t scd_print(struct SCD_CTRL_STRUCT *scd, const char *printDataPtr);

/**
 * @brief �����꣬����β׺���ɶ�Ӧ�ĳ�ʼ�������ͽṹ�������
 */
#define SCD_REG_DECLEAR(TYJ_SUFFIX) \
   void scd_init##TYJ_SUFFIX(void); \
   extern struct SCD_CTRL_STRUCT scd##TYJ_SUFFIX

   /// ����_1��scdʵ��
   SCD_REG_DECLEAR(_1);

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif /* INC_SCD_INC_H_ */
