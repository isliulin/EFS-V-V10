/*------------------------------------------------------------------------
 Module:			pcolsec.h
 Author:			linxueqin
 Project:			????
 State: 			V1.0
 Creation Date: 	2012-10-8
 Description:		??????????
------------------------------------------------------------------------*/

#ifndef _PSECONDARY_H
#define _PSECONDARY_H

#include "Protocol.h"

#define ADDR_YX_LO		0x0001
#define ADDR_YX_HI		0x1000

#define ADDR_YC_LO		0x4001
#define ADDR_YC_HI		0x5000

#define ADDR_YK_LO		0x6001//?????
#define ADDR_YK_HI		0x6200


struct VPtEqpInfo
{
    WORD    wLinkAddress;//????
    WORD    wAddress;  //??????
    WORD    wSYXNum;
    WORD    wDYXNum;
    WORD    wYCNum;
    WORD    wYTNum;
    WORD    wYKNum;
    WORD    wZJNum;	
   VYKInfo YKInfo;
   // VYTInfo YTInfo;
    WORD    OldYc[IEC_YC_NUM];

    WORD wYxType;  //????
    WORD wSoeType; //soe??

};
struct VProtocolBaseCfg
{

    WORD wMaxRetryCount;//?????????
    WORD wBroadcastAddr;
};



class CPSecondary : public CProtocol
{
	public:
		CPSecondary();
		virtual ~CPSecondary(){};
		BYTE ChkSum(BYTE *buf, WORD len);
                BOOL InitEqpInfo(WORD wMinEqpNum);
		BOOL SetEqpInfo(void);

		WORD GetOwnAddr(void);
		BOOL SwitchToAddress(WORD wAddress);
		virtual BOOL DoTimeOut(WORD wTimerID){return FALSE;};
		virtual void CloseTcp(BYTE byReason = 0){return;};
		WORD GetCosNum(WORD HeadPtr,WORD TailPtr,BYTE bSoeBufLen = SOE_EEP_NUM);
		WORD ReadSoeFromFlash(WORD *pHeadPtr,WORD TailPtr,BYTE bSoeMaxNum,BYTE *pSoeBuf);
                virtual void SetBaseCfg(void);
                VPtEqpInfo *pGetEqpInfo(WORD wEqpNo);
                
//			WORD ReadRangeSYXBit(WORD wBeginNo,WORD wNum,BYTE *buf);

		WORD ReadRangeYC(WORD wBeginNo,WORD wNum, short *buf);
		WORD ReadRangePara(BYTE byFlag,WORD wBeginNo,WORD wNum, short *buf);

		WORD SearchSCOS(WORD wNum,struct VDBCOS *buf);
		WORD SearchChangeYC(WORD wNum, VDBYCF *pBuf);
		void CheckChangeYC();
		
		WORD IsOrderFeedBack(DWORD RamBase,WORD wOffset,WORD wYTorYK);
                
                int WriteToComm(DWORD Flag);	
                WORD  GetBroadcastAddr(void);
                WORD  GetMaxRetryCount(void);
		BOOL  GetRetryFlag(void); //??????
		WORD GetRetryCount(void); //??????
		void ResetRetryCount(void);   //?????0
		void IncRetryCount(void);	  //?????1
		void DisableRetry(void);   //????
		BOOL SendRetry(void); //????
                /* Restart */
		void sysRestart(DWORD dwRestartType);
                BOOL SearchCos(WORD wBit,BYTE flag);
				BOOL Init(WORD wMinEqpNum);
public:
        VProtocolBaseCfg *m_pBaseCfg;
		VPtEqpInfo m_VPtEqpInfo;
        WORD m_wRetryCount;  //??????
        WORD m_wEqpNo;
        WORD m_wEqpNum;
        VPtEqpInfo *m_pEqpInfo;
        BYTE bySendAccidentFlag;
        BYTE byChangeYcInitFlag;
        BYTE byCosInitFlag;
        int m_SoePos;//??soe?????????
        VProtocolBaseCfg m_VProtocolBaseCfg;
//        VPtEqpInfo *m_pEqpInfo;        
        UINT m_SCosHeadPtr;
        UINT m_DCosHeadPtr;
        UINT m_SSoeHeadPtr;
        UINT m_DSoeHeadPtr;
        UINT m_SSoeHeadPtrBk;
        UINT m_DSoeHeadPtrBk;
	DWORD m_SendSoeAdr;//??SOE?????
        BYTE m_resendflag;//???????,???????
        BYTE m_SendYcFlag;//???????????,????
        BYTE m_SendChgYcFlag;//???????????,????
        WORD m_reSendDelay; //??????
        WORD m_gRmtChgFlag[RMT_WORD_NUM/2];//??????,?????1?bit?
	BYTE m_WaitConfTpId;//?????????ID	
	BYTE m_luok;//???? ??;
	BYTE m_luok_filename;//???? ??;
	BYTE m_TxNum_lubo;
	BYTE m_PaWaitflag_lubo;
	BYTE m_PaWaitCt_lubo;
	BYTE m_gprsSendBuf[1];
	BYTE m_gprsSendLen;
};

#endif

