#ifndef _DATASTRUCT_H

    #define _DATASTRUCT_H
#ifdef __cplusplus
extern "C"
{
#endif  
  
    #include <string.h>
    #include "stdio.h"
    #include <math.h>
    #include "msp430x54xA.h"
    #include "PUBLIC\mytypes.h"
    #include "Constant.h"
    #include "FuncDef.h"
    #include "RemoteUpdata.h"
    #include "RecorderWave.h"  
//	#include "SMS\PrtcSms.h"
     
// #pragma location=0x0FF00 
 const unsigned char VerNum[]="Ver10.00";
const unsigned char VerNum_INLCD=10;
 
 
//================================== AD²É¼¯Ä£¿é ============================================
struct sSAMPLE_DATA
  {
    int m_gAcAdcData[AC_AD_CHAN_NUM][AC_BUFF_LEN];//½»Á÷µçÑ¹µçÁ÷µÄAD²É¼¯»º³åÇø£¬Ò»ÖÜ²¨²É16¸öµã£¬±£´æ2¸öÖÜ²¨µÄÊı¾İ»º³å£¬ÓÃÓÚÓÀ´ÅÇı¶¯½áÊøµÄ¹ÊÕÏÅĞ¶Ï 
    unsigned int m_unAcDataTail;
  };


#ifdef _DRIVER_AD
  unsigned int g_gRunInfo[RUN_INFO_NUM+1];//ÔËĞĞĞÅÏ¢£¬±£´æ×°ÖÃÔËĞĞµÄ²¿·ÖĞÅÏ¢£¬±ÈÈçºÏ·ÖÕ¢´ÎÊı__no_init 
  struct sSAMPLE_DATA g_sSampleData;//AD²É¼¯Êı¾İ


#else
  extern unsigned int g_gRunInfo[RUN_INFO_NUM+1];//ÔËĞĞĞÅÏ¢£¬±£´æ×°ÖÃÔËĞĞµÄ²¿·ÖĞÅÏ¢£¬±ÈÈçºÏ·ÖÕ¢´ÎÊı
  extern struct sSAMPLE_DATA g_sSampleData;
#endif
//================================== Êı¾İ´¦ÀíÄ£¿é ============================================
  struct sRMT_BACK
 {
   unsigned long m_RmtInfoBackNew;//ÓĞÒ£ĞÅ±ä»¯Ê±
   unsigned int m_Year;
   unsigned int m_Month;
   unsigned int m_Day;
   unsigned int m_Hour;
   unsigned int m_Minute;
   unsigned int m_Milisecond; 
 };
 struct sSOE_DATA  //È«²¿¹ÊÕÏÊı¾İ
  {
    unsigned char m_gSoeBuff[SOE_DATA_LEN_BYTE];//»º³åÇøÖĞµÄÊı¾İ£¬ÔÚRAMÖĞ±£´æ1Ìõ
    unsigned char m_gSoeRSTBuff[SOE_DATA_LEN_BYTE];
    unsigned char m_ucSoePos;   //¹ÊÕÏ¼ÇÂ¼ÔÚEEPÖĞµÄÎ»ÖÃ;
    unsigned char m_ucSoeNum;	//¹ÊÕÏ¼ÇÂ¼×ÜÌõÊı
    							
    unsigned char m_gAbnBuff[ABN_DATA_LEN_BYTE];//»º³åÇøÖĞµÄÊı¾İ£¬ÔÚRAMÖĞ±£´æ1Ìõ
    unsigned char m_gAbnOFFBuff[ABN_DATA_LEN_BYTE];
    unsigned char m_ucAbnPos;    //
    unsigned char m_ucAbnNum;
    
    unsigned char m_gPowerOFFBuff[OFF_DATA_LEN_BYTE];//»º³åÇøÖĞµÄÊı¾İ£¬ÔÚRAMÖĞ±£´æ1Ìõ
    unsigned char m_gPowerONBuff[OFF_DATA_LEN_BYTE];
    unsigned char m_ucPowerOFFPos;//
    unsigned char m_ucPowerOFFNum;
       
    unsigned char m_gBreakBuff[BK_DATA_LEN_BYTE];//»º³åÇøÖĞµÄÊı¾İ£¬ÔÚRAMÖĞ±£´æ1Ìõ
    unsigned char m_gBreakRSTBuff[BK_DATA_LEN_BYTE];
    unsigned char m_ucBreakPos;//
    unsigned char m_ucBreakNum;
    
    unsigned char m_gRecBuff[WAVE_DATA_LEN_BYTE];//»º³åÇøÖĞµÄÂ¼²¨Êı¾İ£¬ÔÚRAMÖĞ±£´æ1Ìõ
    unsigned char m_ucRecPos;//
    unsigned char m_ucRecNum;
  };
  struct sREC_DATA  //Â¼²¨Êı¾İ½á¹¹Ìå¶¨Òå
  {

    int m_gRecAc[REC_AC_LEN][REC_AC_CHAN_NUM];//¹ÊÕÏ¶¯×÷µÄ½»Á÷µçÑ¹µçÁ÷²¨ĞÎ£¬±£´æ¹ÊÕÏ¶¯×÷Ç°10¸öÖÜ²¨£¬¹ÊÕÏ¶¯×÷ºó6¸öÖÜ²¨¡£²Ù×÷Â¼²¨Ê±Ö»ĞèÒª±£´æ¶¯×÷Ö®Ç°10¸öÖÜ²¨£¬¶¯×÷Ö®ºó6¸öÖÜ²¨
    //unsigned char m_gRecD[REC_AC_LEN];
    unsigned int m_gFaultRecSOE[REC_DATA_LEN];//Æô¶¯¸Ã¹ÊÕÏÂ¼²¨¶ÔÓ¦µÄ¹ÊÕÏSOE£¬ÄÚÈİ°üÀ¨Ê±¼ä£¬²»ĞèÒª×îºóµÄCRCĞ£Ñé
    unsigned int m_gFaultRecOver[7]; //²ÉÑù½áÊøÊ±¼ä
	
    //±£»¤¶¨ÖµÔÚĞ´½øFLASHÊ±´Ó¶¨ÖµÖĞµ÷³öĞ´ÈëFLASH
    //ÒÔÏÂ±êÊ¶×¢ÒâÔÚÂ¼²¨±£´æ½áÊøºóÇå0


//¹ÊÕÏÂ¼²¨ 
    unsigned char m_ucRecSavingFlag;//Â¼²¨Êı¾İÍùFlash±£´æ¹ı³ÌÖĞ //¹ÊÕÏÑÓÊ±µ½fault_save=0x55Ôò  YES ¿ªÊ¼´æ´¢//´æ´¢½áÊøÔò OFF 
    unsigned char m_ucFaultRecStart;     //¹ÊÕÏÂ¼²¨¿ªÊ¼±êÖ¾//fault_begin ÔòON //fault_end Ôò OFF//´æ´¢½áÊøÔò OFF
    unsigned int m_unRecAcTail;//Êı¾İ»º´æµÄÎ²²¿Ë÷Òı,ÊÕµ½Ò»¸öÊı¾İ¼Ó¼Ó
    unsigned int m_unRecAcLockCnt;//m_ucFaultRecStart=ON£¬Ôò¸Ã±äÁ¿ÀÛ¼Ó£¬´ïµ½5¸öÖÜ²¨ºó£¬Í£Ö¹¼ÌĞø´æÊı   
    unsigned int m_gRecANum;          //¹ÊÕÏ×î¶à´æ10Ìõ 
    unsigned int m_gRecCNum; 	         //¹ÊÕÏµ±Ç°Â¼²¨Î»ÖÃ 
    
    unsigned int m_gACTRecANum;          //¶¯×÷×î¶à´æ10Ìõ 
    unsigned int m_gACTRecCNum; 	         //¶¯×÷µ±Ç°Â¼²¨Î»ÖÃ
    
    unsigned int m_gXHRecANum;          //Ï¨»¡×î¶à´æ10Ìõ 
    unsigned int m_gXHRecCNum; 	         //Ï¨»¡µ±Ç°Â¼²¨Î»ÖÃ    
//¶¯×÷Â¼²¨
    unsigned int m_gActRecCNum; 	    //µ±Ç°Â¼²¨Î»ÖÃ
    unsigned int m_gActRecANum; 	    //×î¶à´æ10Ìõ    
    unsigned char m_ucActRecStart;     //¶¯×÷Â¼²¨¿ªÊ¼±êÖ¾  ON¿ªÊ¼ OFF½áÊøÂ¼²¨´æ´¢Êı¾İ  CLOSE ´æ´¢½áÊø£¬²»ÔÙÂ¼²¨ 
    unsigned long m_gActRecLen;         //²»¶¨³¤Â¼²¨£¬Ã¿ÌõÂ¼²¨´æµÄµãÊı£¬Ã¿µã5¸öÄ£ÄâÁ¿£¬Ã¿¸öÄ£ÄâÁ¿2×Ö½Ú	
    unsigned long m_gActRecAdr;           //¶¯×÷Â¼²¨¶à´Î´æ´¢£¬FLASHÖĞµÄµØÖ·
    unsigned char m_ucActRecSavingFlag;//Â¼²¨Êı¾İÍùFlash±£´æ¹ı³ÌÖĞ ?    									//YES´æ´¢»º´æÖĞÇ°320µã 
    									//ON´æ´¢»º´æÖĞÇ°320µã 
    									//OFF 320µã´æ´¢Íê
    unsigned char m_EraseBlock;//¶¯×÷Â¼²¨´æ´¢½áÊø£¬²Á³ıÏÂÒ»¸ö´æ´¢¿Õ¼ä ON
    unsigned char m_LuboType;//Â¼²¨ÀàĞÍ 
    
    unsigned int m_CurWritePageCom;           //ÓÃÓÚÍ¨ĞÅµÄÒ³Êı
    unsigned int m_gRecNumCom;              //ÓÃÓÚÍ¨ĞÅµÄÂ¼²¨´ÎÊı
    unsigned char m_gACTDelay;    //8Âö³å½áÊøºó£¬ÑÓÊ±2Ãë£¬ÔÙÍ£Ö¹Â¼²¨
    unsigned int m_gXHDelay;    //Ï¨»¡ÑÓÊ± ÓÃÓÚÏ¨»¡¶¯×÷µÄ¿ªÊ¼ºÍ½áÊø ¼°Ï¨»¡Â¼²¨µÄ½áÊø
    unsigned char m_ucRecStart;     //¶¯×÷Â¼²¨¿ªÊ¼±êÖ¾     
  }; 

#ifdef _DATA_PROCESS
    __no_init struct sREC_DATA g_sRecData;//Â¼²¨Êı¾İ
    unsigned char g_SendZJDingshi = 0; 
    unsigned char 	g_YXLBOKCounter;
    unsigned char g_TQBSCounter = 0; //Í¶ÇĞ¡¢±ÕËøÖ¸Ê¾µÆ¼ÆÊıÆ÷  =0 ÊÇÃğ =0x55 ±ÕËø³£ÁÁ  >=1Í¶ÇĞÉÁË¸	
    unsigned char FlashReading;	// 1=ÕıÔÚ¶Áflash£¬²»ÄÜÂ¼²¨£¬²»ÄÜĞ´soe
    unsigned int g_unAdcData[7]; //ADCMEMµÄÊı¾İ´æ·Åµ½¸ÃÊı×éÖĞ
    unsigned int g_test;
    //unsigned char g_gFaF[256];//
    unsigned char g_gKON;//¼ÌµçÆ÷×´Ì¬
    unsigned char g_gKONBK;//¼ÌµçÆ÷×´Ì¬
    unsigned char g_gVErrTimer[10];	      //µçÑ¹³¬¹ıãĞÖµÈ·ÈÏÊ±¼ä¼ÆÊ±	    
    unsigned int g_gRmtMeas[IEC_YC_NUM/*RMT_MEAS_NUM + 4*/];//Ò£²âÁ¿£¬
    unsigned int g_gRmtMeasPJ[3][32];
    unsigned int g_gRmtMeasBak[IEC_YC_NUM/*RMT_MEAS_NUM*/]; //±¸·İÒ£²âÁ¿
    unsigned int g_gYCYueXian;//ÕÅ| Ò£²âÔ½ÏŞ	
    unsigned int g_gYCchangData[20];
    unsigned int g_gChangeYCNum = 0; //Í»±äÒ£²âÊıÁ¿ 
    unsigned int g_SendChgYcFlag = 0;  //Í»±äÒ£²â±êÖ¾
    unsigned int g_CosSoeDely = 0;  //Í»±äÒ£²â±êÖ¾
    unsigned int g_gWeekNum = 0;
    unsigned long g_gsendYCTimeNum = 0;
    unsigned long g_gsendZJTimeNum = 0;	
    unsigned char g_SendYcDingshi = 0;
    unsigned long g_gsendYXTimeNum = 0;
    unsigned char g_SendYXDingshi = 0;
    unsigned long g_gBeatNum = 0;
    unsigned char g_SendBeat = 0;
    unsigned char g_SendBeatFailureNum = 0;
    unsigned int g_NolinkReset = 0;	
    unsigned int g_NolinkWifi = 0;		
    unsigned char g_GPRSSendLink = 0;// 1·ÖÖÓÖØÁ·Ò»´Î101
    unsigned char g_RenZLink = 0;	//ÖØÇì ÈÏÖ¤±êÖ¾	
    unsigned int g_gRmtInfo[RMT_INFO_NUM];//Ò£ĞÅÁ¿ Ò»¸öÒ£ĞÅĞÅÏ¢Õ¼1¸öbitÎ»
    unsigned int g_gRmtInfoBak[RMT_INFO_NUM];//Ò£ĞÅÁ¿±¸·İ Ò»¸öÒ£ĞÅĞÅÏ¢Õ¼1¸öbitÎ»
    //unsigned char g_gSCosBuff[SOE_BUFF_NUM][SOE_DATA_LEN];
    unsigned char g_gSCosBuff[1][SOE_DATA_LEN];
    unsigned char g_MaichongNum = 0;           //Âö³å¼ÆÊı
    unsigned char g_I0RmtNum = 0;               //µçÁ÷¼ÆÊı
    unsigned char g_I0RmtZeroNum=0;	//¶ÏÏß¼ì²âÓÃµçÁ÷¼ÆÊı	
    unsigned char g_FirstACTFlag = 0;           //Ê×´Î¶¯×÷±êÖ¾
    unsigned char g_FinishACTFlag = 0;
    
    unsigned char g_ChaxunSOE_STATTime[7];
    unsigned char g_ChaxunSOE_OVERTime[7];
    unsigned int g_gSaveload;//Ã¿xÃë´æ´¢1´Î¸ººÉ¼ÇÂ¼
    //unsigned char g_SendLuboNum = 0;
  
    unsigned int g_unSCosBuffTail;
	unsigned int g_unSSoeInFlashTail;//±£´æÔÚÍâ²¿flashÖĞµÄSOEÎ²Ö¸Õë
    unsigned int g_gSmsHeadPt;       //¶ÌĞÅÍ·Ö¸Õë
    unsigned int g_gSmsHeadPtrBk;    //¶ÌĞÅÍ·Ö¸Õë±¸·İ
    //unsigned int g_gSmsStartPtr;     //¶ÌĞÅ·¢ËÍ¿ªÊ¼Ö¸Õë
   // unsigned int g_RecFaultNum;      //¶ÌĞÅ·¢ËÍÌõÊı±¸·İ
  //  unsigned int g_unGroundBuffTail;
    unsigned int g_unDSoeSavePtr;//´ı±£´æµÄË«µãSOEÖ¸Õë
    unsigned int g_unSSoeSavePtr;//´ı±£´æµÄµ¥µãSOEÖ¸Õë
    unsigned long g_unSSoeSaveFlashHead;//±£´æµ½Íâ²¿flashµÄµ¥µãSOEÍ·µØÖ·
    unsigned int g_unSSoeSaveE2ROMPtr;//´ı±£´æµ½Íâ²¿flashµÄµ¥µãSOEÖ¸Õë
    unsigned char   soe_ptr; //×îĞÂSOEÔÚflashÖĞµÄ¶ÎÎ»ÖÃ
    unsigned char   soe_area;//×îĞÂSOEÔÚflash¶ÎÖĞÎ»ÖÃ
    unsigned int    soe_num;//SOE×Ü¸öÊı
    unsigned int g_unSoeSendNum;
    unsigned int  g_yxChangeflag;//Ò£ĞÅ±äÎ»±êÊ¶ BITF±êÊ¶ÓĞĞÂ±¨ÎÄÉÏ´«(Ò£ĞÅ¼°Ò£²â) BIT0-5,6-11·Ö±ğ±êÊ¶µ÷ÊÔ¿ÚºÍgprs¿Ú¶ÔÓ¦µÄSYX,DYX,SSOE,DSOE,SSMS,DSMS;
   // char g_AdChgSdYc;//±êÊ¶AD²É¼¯ÊÇ·ñÁ¢¼´ÉÏ´«ON=Á¢¼´ÉÏ´«
   // char g_FltChgSdYc;//±êÊ¶¹ÊÕÏÒ£²âÊÇ·ñÁ¢¼´ÉÏ´« 1=Á¢¼´ÉÏ´«
   // char g_PtLoseFlag;//ptÊ§Ñ¹±êÊ¶ 0=Î´Ê§Ñ¹ 1=Ê§Ñ¹ 2=µçÑ¹»Ø¸´ÖĞ
  //  char g_BatLoseFlag;//µç³ØÊ§Ñ¹±êÊ¶ 0=Î´Ê§Ñ¹ 1=Ê§Ñ¹ 2=µçÑ¹»Ø¸´ÖĞ   
  //  unsigned int g_PtMonitorCnt;//ptµçÑ¹»Ö¸´¼ÆÊı
  //  unsigned int g_BatMonitorCnt;//µç³ØµçÑ¹»Ö¸´¼ÆÊı
   // char g_SendYc;//0=ËùÓĞÒ£²â¾ù²»·¢ËÍ£¬1=Õı³£·¢ËÍ(¶¨Ê±ÉÏ±¨µÄÒ£²â£¬¹ÊÕÏÒ£²â£¬AD²É¼¯Öµ±ä»¯µÄÒ£²â£¬Ô½ÏŞÒ£²â)
  //  unsigned char  g_Soenum;
  //  unsigned int  g_ZsqCmdRBit = 0;
  //  unsigned int  g_ZsqCmdWBit = 0;
  //  unsigned int  g_JdgPwMode = 0;
    
    __no_init struct sSOE_DATA g_sSoeData;//SOEÔÚRAMÖĞµÄ»º³åÇøÊı¾İ

  	//IAR»á¶Ô·ÖÅäµÄÄÚ´æÔÚ½øÈëmainº¯ÊıÖ®Ç°½øĞĞÇå0£¬ĞèÒªÕ¼ÓÃ½Ï¶àµÄÊ±¼ä£¬µ¼ÖÂ¿´ÃÅ¹·Æô¶¯£¬Òò´Ë¶ÔÕ¼ÓÃ½Ï´óÄÚ´æµÄÊı×éÓÃ"__no_init"½ûÖ¹Çå0£¬·Åµ½³ÌĞòÖĞ×¢Òâ¶ÔËü½øĞĞ³õÊ¼»¯

	//unsigned int g_gRmtMeas[RMT_MEAS_NUM];//Ò£²âÁ¿£¬±£´æĞèÒªÉÏ´«µ½ºóÌ¨µÄÒ£²âÊı¾İ = ¿ª·½(g_gProcMeas/16) * 0.6944
  	unsigned int g_gRmAcFilt[RMT_MEAS_NUM][RM_FILTER_NUM];//Ò£²âÁ¿ÖĞµÄ½»Á÷²âÁ¿Êı¾İÂË²¨ Ìí¼ÓÁË3¸öÏßµçÑ¹£¬µ«ADÍ¨µÀÊı²»±ä£¬ËùÒÔ´Ë´¦AC_AD_CHAN_NUM + 3
        unsigned int g_unFilterIndex = 0;   //½»Á÷²âÁ¿Êı¾İÂË²¨Êı¾İ±£´æµÄÎ»ÖÃ
        volatile unsigned int g_unRmCaluFlag;    //Ò£²âÔËËã±êÖ¾, ÔÚÖĞ¶ÏÖĞÖÃON£¬ÔÚ´óÑ­»·ÖĞÖÃOFF£¬ÔÚ½øĞĞÒ£²âÔËËã£¬Èç¹û¸Ã±êÖ¾ÎªON£¬ËµÃ÷Ò£²âÊı¾İ¸üĞÂÁË£¬¿ÉÒÔ½øĞĞÒ£²âÁ¿ÔËËã
        volatile unsigned int g_unTESTFlag;  
  	unsigned long g_gProcMeas[PROC_MEAS_NUM];//±£»¤ÓÃ²âÁ¿Á¿£¬ÓÃÓÚ±£»¤Âß¼­ÅĞ¶ÏµÄ²âÁ¿Á¿£¬Îª²ÉÑùÖµµÄÆ½·½*16 ×î´óÖµÎª(2048*2048/2*16)
        //unsigned int g_gRmtInfo[RMT_INFO_NUM];//Ò£ĞÅÁ¿£¬°üÀ¨ÄÚ²¿Ò£ĞÅÁ¿

	unsigned int  g_SendLuboNum;
	unsigned int  g_SendLuboPage;
     WORD wCfgTotalNum =0;//×Ü³¤¶È
#ifdef YN_101S     
     WORD section_current=0;//µ±Ç°½Ú*/
#else
     WORD section_current=1;//µ±Ç°½Ú*/
#endif
#else
extern unsigned int g_test;
    extern unsigned int g_gSaveload;//Ã¿xÃë´æ´¢1´Î¸ººÉ¼ÇÂ¼
    //extern unsigned char g_gFaF[256];//
    extern unsigned char g_YXLBOKCounter;
    extern unsigned char g_SendZJDingshi; 
    extern unsigned char g_TQBSCounter; 
    extern unsigned char FlashReading;		
    extern struct sREC_DATA g_sRecData;
    extern unsigned int g_unAdcData[7]; //ADCMEMµÄÊı¾İ´æ·Åµ½¸ÃÊı×éÖĞ
    extern unsigned char g_gKON;//¼ÌµçÆ÷×´Ì¬
    extern unsigned char g_gKONBK;//¼ÌµçÆ÷×´Ì¬
    extern unsigned int g_gRmtMeas[IEC_YC_NUM/*RMT_MEAS_NUM + 4*/];//Ò£²âÁ¿£¬±£´æĞèÒªÉÏ´«µ½ºóÌ¨µÄÒ£²âÊı¾İ  
    extern unsigned int g_gRmtMeasPJ[3][32];
    extern unsigned int g_gRmtMeasBak[IEC_YC_NUM/*RMT_MEAS_NUM */]; //±¸·İÒ£²âÁ¿
    extern unsigned int g_gYCYueXian;//ÕÅ| Ò£²âÔ½ÏŞ	
    extern unsigned int g_gYCchangData[20];
    extern unsigned int g_gChangeYCNum; //Í»±äÒ£²âÊıÁ¿
    extern unsigned int g_SendChgYcFlag;  //Í»±äÒ£²â±êÖ¾
    extern unsigned int g_CosSoeDely;  //Í»±äÒ£²â±êÖ¾
    extern unsigned int g_gWeekNum;
    extern unsigned long g_gsendYCTimeNum ;
    extern unsigned char g_SendYcDingshi;
    extern unsigned long g_gsendZJTimeNum ;	 		
    extern unsigned long g_gsendYXTimeNum ;
    extern unsigned char g_SendYXDingshi;
    extern unsigned char g_GPRSSendLink ;
    extern unsigned char g_RenZLink;	//ÖØÇì ÈÏÖ¤±êÖ¾
    
    extern unsigned int g_gRmtInfo[RMT_INFO_NUM];//Ò£ĞÅÁ¿ Ò»¸öÒ£ĞÅĞÅÏ¢Õ¼2¸öbitÎ»
    extern unsigned int g_gRmtInfoBak[RMT_INFO_NUM];
    //extern unsigned char g_gSCosBuff[SOE_BUFF_NUM][SOE_DATA_LEN];
    extern unsigned char g_gSCosBuff[1][SOE_DATA_LEN];    
   // extern unsigned char g_gGroundBuff[SOE_BUFF_NUM];
    extern unsigned int g_unSCosBuffTail;
    
    extern unsigned char g_MaichongNum;           //Âö³å¼ÆÊı
    extern unsigned char g_I0RmtNum;               //µçÁ÷¼ÆÊı
    extern unsigned char g_I0RmtZeroNum;	//¶ÏÏß¼ì²âÓÃµçÁ÷¼ÆÊı	
    extern unsigned char g_FirstACTFlag;           //Ê×´Î¶¯×÷±êÖ¾
    extern unsigned char g_FinishACTFlag;

    extern unsigned int g_unSSoeInFlashTail;//±£´æÔÚÍâ²¿flashÖĞµÄSOEÎ²Ö¸Õë
    extern unsigned int g_gSmsHeadPt;       //¶ÌĞÅÍ·Ö¸Õë
    extern unsigned int g_gSmsHeadPtrBk;    //¶ÌĞÅÍ·Ö¸Õë±¸·İ
   // extern unsigned int g_gSmsStartPtr;     //¶ÌĞÅ·¢ËÍ¿ªÊ¼Ö¸Õë
   // extern unsigned int g_RecFaultNum;      //¶ÌĞÅ·¢ËÍÌõÊı±¸·İ
    extern unsigned int g_unDSoeSavePtr;//´ı±£´æµÄË«µãSOEÖ¸Õë
    extern long g_unSSoeSavePtr;//´ı±£´æµÄµ¥µãSOEÖ¸Õë
    extern unsigned long g_unSSoeSaveFlashHead;//±£´æµ½Íâ²¿flashµÄµ¥µãSOEÍ·µØÖ·
    extern unsigned int g_unSSoeSaveE2ROMPtr;//´ı±£´æµ½Íâ²¿flashµÄµ¥µãSOEÖ¸Õë
   // extern unsigned int g_unGroundBuffTail;
    extern unsigned char   soe_ptr; //×îĞÂSOEÔÚflashÖĞµÄ¶ÎÎ»ÖÃ
    extern unsigned char   soe_area;//×îĞÂSOEÔÚflash¶ÎÖĞÎ»ÖÃ
    extern unsigned int    soe_num;//SOE×Ü¸öÊı
    extern unsigned int g_unSoeSendNum;
    extern unsigned int  g_yxChangeflag;
    extern unsigned char g_ChaxunSOE_STATTime[7];
    extern unsigned char g_ChaxunSOE_OVERTime[7];
    //extern unsigned char g_SendLuboNum;
    extern unsigned long g_gBeatNum;
    extern unsigned char g_SendBeat;
    extern unsigned char g_SendBeatFailureNum;
    extern unsigned int g_NolinkReset;	
    extern unsigned int g_NolinkWifi;	
    //extern char g_AdChgSdYc;
   // extern char g_FltChgSdYc;
   // extern char g_PtLoseFlag;
   // extern unsigned int g_PtMonitorCnt;
   // extern char g_SendYc;
   // extern unsigned char  g_Soenum;
   // extern unsigned int  g_ZsqCmdRBit;
  //  extern unsigned int  g_ZsqCmdWBit;
   // extern unsigned int  g_JdgPwMode;
    extern struct sSOE_DATA g_sSoeData;      
  	//extern unsigned int g_gRmtMeas[RMT_MEAS_NUM];//Ò£²âÁ¿£¬±£´æĞèÒªÉÏ´«µ½ºóÌ¨µÄÒ£²âÊı¾İ
        extern unsigned int g_gRmAcFilt[RMT_MEAS_NUM][RM_FILTER_NUM];//Ò£²âÁ¿ÖĞµÄ½»Á÷²âÁ¿Êı¾İÂË²¨ Ìí¼ÓÁË3¸öÏßµçÑ¹£¬µ«ADÍ¨µÀÊı²»±ä£¬ËùÒÔ´Ë´¦AC_AD_CHAN_NUM + 3
	extern unsigned long g_gProcMeas[PROC_MEAS_NUM];//±£»¤ÓÃ²âÁ¿Á¿£¬ÓÃÓÚ±£»¤Âß¼­ÅĞ¶ÏµÄ²âÁ¿Á¿
       // extern unsigned int g_gRmtInfo[RMT_INFO_NUM];//Ò£ĞÅÁ¿£¬°üÀ¨ÄÚ²¿Ò£ĞÅÁ¿   
       extern volatile unsigned int g_unRmCaluFlag;    //Ò£²âÔËËã±êÖ¾, ÔÚÖĞ¶ÏÖĞÖÃON£¬ÔÚ´óÑ­»·ÖĞÖÃOFF£¬ÔÚ½øĞĞÒ£²âÔËËã£¬Èç¹û¸Ã±êÖ¾ÎªON£¬ËµÃ÷Ò£²âÊı¾İ¸üĞÂÁË£¬¿ÉÒÔ½øĞĞÒ£²âÁ¿ÔËËã
       extern volatile unsigned int g_unTESTFlag;
	extern unsigned int  g_SendLuboNum;
	extern unsigned int  g_SendLuboPage;
    extern WORD wCfgTotalNum ;//×Ü³¤¶È
    extern WORD section_current;//µ±Ç°½Ú*/
#endif

//=======================================  ²ÎÊıÅäÖÃÄ£¿é  ===================================
#ifdef _PARA_CFG

        unsigned int g_gRunParaYxRsdTTBk;//ÔËĞĞ²ÎÊıÖĞÒ£ĞÅÖØ·¢Ê±¼ä¼ä¸ô±¸·İ
        unsigned int g_unYxTrans[RMT_WSYX_NUM];  //¸ù¾İÒ£ĞÅµÄµã±í£¬ÖØĞÂÅäÖÃÉú³ÉµÄÒ£ĞÅÄÚÈİ
        //unsigned int g_unDYxTrans[RMT_WDYX_NUM];//ÉÏ´«µÄË«µãÒ£ĞÅ
        unsigned int g_unZJTrans[IEC_ZJ_NUM];    //ÉÏ´«µÄÒ£²âÊı¾İ£¬Èç¹û·¢ÉúÉÏ´«µÄ³¬¹ıË¢ĞÂËÀÇø£¬ÔòÉÏ´«        
        unsigned int g_unYcTrans[IEC_YC_NUM];    //ÉÏ´«µÄÒ£²âÊı¾İ£¬Èç¹û·¢ÉúÉÏ´«µÄ³¬¹ıË¢ĞÂËÀÇø£¬ÔòÉÏ´«
        unsigned char g_ucYcTransNum; //¼ÇÂ¼ĞèÒªÉÏ´«µÄÒ£²âµÄ¸öÊı
        unsigned int g_ucYxTransNum; //¼ÇÂ¼uĞèÒªÉÏ´«Ò£ĞÅµÄ×Ü¸öÊı(°üÀ¨µ¥µãºÍË«µã)

        unsigned int g_ucSYxTrsStartId;//ÉÏ´«µÄµ¥µãÒ£ĞÅÖĞµÚÒ»¸öµãµÄĞòºÅ(ÔÚg_ucYXAddrÊı×éÖĞ)
        unsigned int g_ucDYxTrsStartId;//ÉÏ´«µÄË«µãÒ£ĞÅÖĞµÚÒ»¸öµãµÄĞòºÅ(ÔÚg_ucYXAddrÊı×éÖĞ)
        unsigned char g_ucYkTransNum;
        unsigned char g_ucParaChang = 0; //101²ÎÊı·¢Éú±ä¸ü±êÖ¾  BIT0Îª 101²ÎÊı£¬BIT1ÎªÒ£²âµã±í£¬BIT2ÎªÒ£²âÏµÊı£¬BIT3ÎªÒ£²âÆ«ÒÆÁ¿£¬BIT4ÎªÒ£ĞÅµã±í BIT5ÎªÔËĞĞ²ÎÊı±í//ÕÅ| ¶Áºº×ÖÕ¾ÃûBIT6//
        unsigned char g_ucRefYxYcTs = 0;//Ò£ĞÅÒ£²âÊı¾İ±ä»¯±êÖ¾ BIT0ÎªÒ£ĞÅ BIT1ÎªÒ£²â
        unsigned char g_ZsqPara = 0;   //zx
        
        unsigned char  g_gSmsPhone[PHONE_PA_NUM];//¶ÌĞÅÖĞµç»°ºÅÂë
        unsigned int g_gCnName[CnName_NUM+1];//ÕÅ| ºº×ÖÕ¾ÃûµØÖ·
        unsigned char g_gLBNameLen;
	 unsigned char  g_gLBName[LBName_NUM+1];//ÕÅ| ºº×ÖÕ¾ÃûµØÖ·
     //   unsigned int g_gRunPara[RUN_PARA_NUM];//ÔËĞĞ²ÎÊı£¬±£´æ×°ÖÃµÄÒ»Ğ©ÅäÖÃĞÅÏ¢£¬°üÀ¨Í¨ĞÅ²ÎÊıµÈ
     	unsigned char g_ucPara101[IEC_PARA_NUM];    //IECÔËĞĞµÄÔËĞĞ²ÎÊı
     	//unsigned char g_unParaObjComBk[4];//IEC²ÎÊıÖĞµÄ¶Ë¿Ú¶ÔÏó4¸öÊı¾İ½øĞĞ±¸·İ£¬ÓĞ±ä»¯Ê±ÖØÓ³ÉäÀà¶ÔÏóÓë¶Ë¿ÚµÄ¶ÔÓ¦¹ØÏµ
        unsigned char g_ucYCAddr[IEC_YC_NUM + 1];   //Ò£²âµÄµã±í£¬¿ÉÒÔ°ÑÒ£²âÖĞµÄÊı¾İ°´ÕÕÆ«ÒÆÁ¿ÖØĞÂÅÅÁĞ£¬×î¶à°´ÕÕ20¸öÅäÖÃ£¬Îª0µÄ²»ÉÏ´«£¬µãºÅÎª1-255
        unsigned char g_ucYXAddr[IEC_YX_NUM + 1];   //Ò£ĞÅµÄµã±í£¬Îª0µÄ²»ÉÏ´«£¬µãºÅÎª1-255
    //    unsigned char g_ucYKPa[IEC_YK_NUM + 1];   //Ò£¿Ø²ÎÊı ±êÊ¶Ö¸Ê¾Æ÷µÄÏßÆ«ÏàÆ«
		
			
		//unsigned int g_gRunParaFltLkTBk;//ÔËĞĞ²ÎÊıÖĞ¹ÊÕÏ±ÕËøÊ±¼ä±¸·İ£¬ÓÃÓÚ²ÎÊı±ä»¯Ê±Ê¹ÆäÁ¢¼´ÉúĞ§
       // unsigned int g_gRunParaZsqStTBk;//ÔËĞĞ²ÎÊıÖĞÖ¸Ê¾Æ÷Í¨ĞÅ×´Ì¬¼ì²âÖÜÆÚ±¸·İ
       // unsigned int g_gRunParaYxRsdTTBk;//ÔËĞĞ²ÎÊıÖĞÒ£ĞÅÖØ·¢Ê±¼ä¼ä¸ô±¸·İ
        
       // unsigned char g_open_oducall;//³ÌĞòÉÏµçÊ±5SÕÙ»½Ò»´Î£¬µÈ´ı²É¼¯µÄCµÄµçÑ¹£¬ÒÔÅĞ¶ÏÊÇÓÃµç³Ø»¹ÊÇ³¬¼¶µçÈİ´ò¿ªååååGPRS
      //  unsigned int Before4HourSdYcTm;
		//unsigned char g_LineFlag[12];    //ODUËùÓĞÂ·ÊıµÄ×´Ì¬?0Îª²»ºÍÆäËüÂ·ºÏ³É1 ÎªºÏ³ÉµÄÇ°Ò»Â·2 ÎªºÏ³ÉµÄºóÒ»Â·
        
        extern const unsigned int BIT[16] =   //»ñµÃµÚ¼¸Î»Îª1µÄÖµ£¬BIT0~BIT15
    	{
                0x01,0x02,0x04,0x08,
        0x10,0x20,0x40,0x80,
        0x100,0x200,0x400,0x800,
        0x1000,0x2000,0x4000,0x8000
    	};
        
        unsigned int g_gRunPara[RUN_PARA_NUM];//ÔËĞĞ²ÎÊı£¬±£´æ×°ÖÃµÄÒ»Ğ©ÅäÖÃĞÅÏ¢£¬°üÀ¨Í¨ĞÅ²ÎÊıµÈ
        BYTE g_gIPPort[13];//  2¸öIP¼°¶Ë¿Ú£¬
        BYTE g_gAPN[20];
        BYTE g_gSMSR;//GPRSÄ£¿é½ÓÊÕ¶ÌĞÅ  0=²»½ÓÊÕ 1=½ÓÊÕ         
        unsigned int g_gProcCnt[PROC_CNT_NUM];//±£»¤¶¨Öµ£¬±£´æ±£»¤¶¯×÷ĞèÒªÓÃµ½µÄ¶¨Öµ
        //unsigned int g_gETHProcCnt[24];
        unsigned int g_gProcCntJug[27];       //ÓÃÓÚÅĞ¶ÏµÄ¼ÆËãºóµÄ±£»¤¶¨Öµ
        unsigned long g_gProcCntJug_I0[3];       //ÓÃÓÚ¹ıÔØÅĞ¶ÏµÄ¼ÆËãºóµÄ±£»¤¶¨Öµ
        unsigned int g_gOverLoadTimeNum;     //ÓÃÓÚ¹ıÔØ¼ÆÊ±£¬Ê±¼äÒÔ1.25ms»ù×¼
        unsigned int g_gOverLoadFlg;        //¹ıÔØ±êÖ¾ ON Îª¹ıÔØ
        unsigned int g_gAdjObj[ADJ_PARA_NUM];//ÕÅ| Ä¿±êĞ£×¼£¬ÉÏÎ»»úÏÂÔØ²ÎÊı ³õÊ¼ÖµÎªµçÑ¹60V,µçÁ÷2A    
        unsigned char g_gModfk[24];
	unsigned char kat,kbt,kct,Numk;	
  	int g_gAdjPara[ADJ_PARA_NUM];//Ğ£Õı²ÎÊı£¬±£´æ¸÷¸öÍ¨µÀµÄĞ£Õı²ÎÊı   
  	unsigned int g_gAdjAD[ADJ_PARA_NUM];//¸ù¾İĞ£Õı²ÎÊı£¬¼ÆËã³öµÄADÖµµÄÆ«ÒÆÁ¿
  	//unsigned int g_gRunInfo[RUN_INFO_NUM];//ÔËĞĞĞÅÏ¢£¬±£´æ×°ÖÃÔËĞĞµÄ²¿·ÖĞÅÏ¢£¬±ÈÈçºÏ·ÖÕ¢´ÎÊı  	
  	unsigned char g_gChangFlag[PARA_NUM];	//²ÎÊı±ä»¯±êÖ¾£¬Èç¹û·¢Éú²ÎÊı¸ü¸Ä£¬ÔòÖÃÎ»£¬°Ñ²ÎÊı±£´æµ½eepromÖĞ
        unsigned int g_gYXConformTime[2];       //Ò£ĞÅÈ·ÈÏÊ±¼ä£¬0£ºĞÅºÅÔ´¶ÏÏß 1£º
#else
        extern unsigned int g_gRunParaYxRsdTTBk;//ÔËĞĞ²ÎÊıÖĞÒ£ĞÅÖØ·¢Ê±¼ä¼ä¸ô±¸·İ
        extern unsigned int g_unYxTrans[RMT_WSYX_NUM];  //¸ù¾İÒ£ĞÅµÄµã±í£¬ÖØĞÂÅäÖÃÉú³ÉµÄÒ£ĞÅÄÚÈİ
        //extern unsigned int g_unDYxTrans[RMT_WDYX_NUM];//ÉÏ´«µÄË«µãÒ£ĞÅ
        extern unsigned int g_unZJTrans[IEC_ZJ_NUM];       
        extern unsigned int g_unYcTrans[IEC_YC_NUM];    //ÉÏ´«µÄÒ£²âÊı¾İ£¬Èç¹û·¢ÉúÉÏ´«µÄ³¬¹ıË¢ĞÂËÀÇø£¬ÔòÉÏ´«
        extern unsigned char g_ucYcTransNum; //¼ÇÂ¼ĞèÒªÉÏ´«µÄÒ£²âµÄ¸öÊı
        extern unsigned int g_ucYxTransNum; //¼ÇÂ¼uĞèÒªÉÏ´«Ò£ĞÅµÄ¸öÊı
        extern unsigned int g_ucSYxTrsStartId;//ÉÏ´«µÄµ¥µãÒ£ĞÅÖĞµÚÒ»¸öµãµÄĞòºÅ(ÔÚg_ucYXAddrÊı×éÖĞ)
        extern unsigned int g_ucDYxTrsStartId;//ÉÏ´«µÄË«µãÒ£ĞÅÖĞµÚÒ»¸öµãµÄĞòºÅ(ÔÚg_ucYXAddrÊı×éÖĞ)
      //  extern unsigned int g_ucDYxTransNum;
        extern unsigned char g_ucYkTransNum;
        extern unsigned char g_ucParaChang; //101²ÎÊı·¢Éú±ä¸ü±êÖ¾  BIT0Îª 101²ÎÊı£¬BIT1ÎªÒ£²âµã±í£¬BIT2ÎªÒ£²âÏµÊı£¬BIT3ÎªÒ£²âÆ«ÒÆÁ¿£¬BIT4ÎªÒ£ĞÅµã±í BIT5ÎªÔËĞĞ²ÎÊı±í
        extern unsigned char g_ucRefYxYcTs;//Ò£ĞÅÒ£²âÊı¾İ±ä»¯±êÖ¾ BIT0ÎªÒ£ĞÅ BIT1ÎªÒ£²â
                
		extern unsigned char  g_gSmsPhone[PHONE_PA_NUM];//¶ÌĞÅÖĞµç»°ºÅÂë  //ÕÅ| 0328
		extern unsigned int g_gCnName[CnName_NUM+1];//ÕÅ| ºº×ÖÕ¾ÃûµØÖ·
		extern unsigned char g_gLBName[LBName_NUM+1];//ÕÅ| ºº×ÖÕ¾ÃûµØÖ·	
		extern unsigned char g_gLBNameLen;
	//	extern unsigned int g_gRunPara[RUN_PARA_NUM];//ÔËĞĞ²ÎÊı£¬±£´æ×°ÖÃµÄÒ»Ğ©ÅäÖÃĞÅÏ¢£¬°üÀ¨Í¨ĞÅ²ÎÊıµÈ
    	extern unsigned char g_ucPara101[IEC_PARA_NUM];    //IECÔËĞĞµÄÔËĞĞ²ÎÊı
		//extern unsigned char g_unParaObjComBk[4];//IEC²ÎÊıÖĞµÄ¶Ë¿Ú¶ÔÏó4¸öÊı¾İ½øĞĞ±¸·İ£¬ÓĞ±ä»¯Ê±ÖØÓ³ÉäÀà¶ÔÏóÓë¶Ë¿ÚµÄ¶ÔÓ¦¹ØÏµ
		extern unsigned char g_ucYCAddr[IEC_YC_NUM + 1];   //Ò£²âµÄµã±í£¬¿ÉÒÔ°ÑÒ£²âÖĞµÄÊı¾İ°´ÕÕÆ«ÒÆÁ¿ÖØĞÂÅÅÁĞ£¬×î¶à°´ÕÕ20¸öÅäÖÃ£¬Îª0µÄ²»ÉÏ´«£¬µãºÅÎª1-255
        extern unsigned char g_ucYXAddr[IEC_YX_NUM + 1];   //Ò£ĞÅµÄµã±í£¬Îª0µÄ²»ÉÏ´«£¬µãºÅÎª1-255 
     //   extern unsigned char g_ucYKPa[IEC_YK_NUM + 1]; 
		
       //	extern unsigned int g_gRunParaFltLkTBk;//ÔËĞĞ²ÎÊıÖĞ¹ÊÕÏ±ÕËøÊ±¼ä±¸·İ£¬ÓÃÓÚ²ÎÊı±ä»¯Ê±Ê¹ÆäÁ¢¼´ÉúĞ§
		//extern unsigned int g_gRunParaZsqStTBk;//ÔËĞĞ²ÎÊıÖĞÖ¸Ê¾Æ÷Í¨ĞÅ×´Ì¬¼ì²âÖÜÆÚ±¸·İ
		//extern unsigned int g_gRunParaYxRsdTTBk;//ÔËĞĞ²ÎÊıÖĞÒ£ĞÅÖØ·¢Ê±¼ä¼ä¸ô±¸·İ
        extern const unsigned int BIT[16];
        
        extern unsigned int g_gRunPara[RUN_PARA_NUM];//ÔËĞĞ²ÎÊı£¬±£´æ×°ÖÃµÄÒ»Ğ©ÅäÖÃĞÅÏ¢£¬°üÀ¨Í¨ĞÅ²ÎÊıµÈ
        
		//extern unsigned char g_open_oducall;
		//extern unsigned int Before4HourSdYcTm;
		//extern unsigned char g_LineFlag[12];
                extern unsigned int g_gProcCnt[PROC_CNT_NUM];//±£»¤¶¨Öµ£¬±£´æ±£»¤¶¯×÷ĞèÒªÓÃµ½µÄ¶¨Öµ
        //extern unsigned int g_gETHProcCnt[24];
        extern unsigned int g_gProcCntJug[27];       //ÓÃÓÚÅĞ¶ÏµÄ¼ÆËãºóµÄ±£»¤¶¨Öµ
        extern unsigned long g_gProcCntJug_I0[3];       //ÓÃÓÚ¹ıÔØÅĞ¶ÏµÄ¼ÆËãºóµÄ±£»¤¶¨Öµ
        extern unsigned int g_gOverLoadTimeNum;     //ÓÃÓÚ¹ıÔØ¼ÆÊ±£¬Ê±¼äÒÔ1.25ms»ù×¼
        extern unsigned int g_gOverLoadFlg;        //¹ıÔØ±êÖ¾ ON Îª¹ıÔØ
        extern BYTE g_gIPPort[13];//  2¸öIP¼°¶Ë¿Ú
        extern BYTE g_gAPN[20];
        extern BYTE g_gSMSR;//GPRSÄ£¿é½ÓÊÕ¶ÌĞÅ  0=²»½ÓÊÕ 1=½ÓÊÕ         
	extern int g_gAdjPara[ADJ_PARA_NUM];//Ğ£Õı²ÎÊı£¬±£´æ¸÷¸öÍ¨µÀµÄĞ£Õı²ÎÊı
	extern unsigned int g_gAdjAD[ADJ_PARA_NUM];//¸ù¾İĞ£Õı²ÎÊı£¬¼ÆËã³öµÄADÖµµÄÆ«ÒÆÁ¿
	extern unsigned int g_gAdjObj[ADJ_PARA_NUM];//ÕÅ| Ä¿±êĞ£×¼£¬ÉÏÎ»»úÏÂÔØ²ÎÊı ³õÊ¼ÖµÎªµçÑ¹60V,µçÁ÷2A
	extern unsigned char g_gModfk[24];
	extern unsigned char kat,kbt,kct,Numk;	
        extern int g_gAdjParaBuf[ADJ_PARA_NUM];
	
	extern unsigned char g_gChangFlag[PARA_NUM];	//²ÎÊı±ä»¯±êÖ¾£¬Èç¹û·¢Éú²ÎÊı¸ü¸Ä£¬ÔòÖÃÎ»£¬°Ñ²ÎÊı±£´æµ½eepromÖĞ
	extern unsigned int g_gYXConformTime[2];       //Ò£ĞÅÈ·ÈÏÊ±¼ä£¬0£ºĞÅºÅÔ´¶ÏÏß 1£º
		
#endif

//=================================== Í¨ĞÅÄ£¿é ==========================================
  struct  sTX_BUFF		   //Í¨ĞÅ·¢ËÍ»º³å½á¹¹Ìå
	{
	  unsigned char m_gBuffer[MAX_RXBUFF_LEN];//·¢ËÍÊı¾İ»º³å
	  unsigned int m_ucTx_Head;//GPRS´®¿ÚÖĞ¶Ï·¢ËÍÊı¾İµÄ»º´æÍ·Ö¸Õë
      unsigned int m_ucTx_Tail;//GPRS´®¿ÚÖĞ¶Ï·¢ËÍÊı¾İµÄ»º´æÎ²Ö¸Õë
      unsigned char m_unSendFlag;
	};


  struct  sRX_BUFF         //Í¨ĞÅ½ÓÊÕ»º³å½á¹¹Ìå
  {
    unsigned char m_gBuf[MAX_RXBUFF_LEN];//½ÓÊÕÊı¾İ»º³å
    unsigned int m_iBufT;      //Êı¾İ»º³åÎ²Ö¸Õë
    unsigned int m_iBufH;      //Êı¾İ»º³åÍ·Ö¸Õë
    unsigned int m_iRcvCount; //½ÓÊÕ×Ö½ÚÊ±¼ä¼ä¸ô
    unsigned char m_iRcvFlag;
  };
/*  
    struct  sRX_BUFF_LED         //Í¨ĞÅ½ÓÊÕ»º³å½á¹¹Ìå
  {
    unsigned char m_gBuffer[MAX_RXBUFF_LEN];//½ÓÊÕÊı¾İ»º³å
    unsigned int m_iBufferTail;
    unsigned int m_iBufferHead;
  };
  */
#ifdef _COMM
    __no_init struct  sTX_BUFF g_sTxBuff[COMM_PORT_NUM];
    __no_init struct  sRX_BUFF g_sRxBuff[COMM_PORT_NUM];
             // struct  sRX_BUFF_LED  g_sRX_BUFF_LED;
       // unsigned int g_sCommStatCount[RMT_ZSQST_NUM];//ÅĞ¶ÏÖ¸Ê¾Æ÷Í¨ĞÅ×´Ì¬Ê±¼ä¼ÆÊı
        char g_YkOrderFlag;//±êÊ¶Ò£¿ØÊÇ·ñ³É¹¦

        unsigned char g_GprsPowerSt;//GPRSµçÔ´×´Ì¬ 0=¹Ø±Õ 1= ´ò?      
        unsigned char g_batPowerSt;//bat×´Ì¬ 0=¹Ø±Õ 1= ´ò?		

        unsigned char g_SmsWritePtr;
        unsigned char g_EnSmsSend;  //¶ÌĞÅ·¢ËÍÔÊĞí
        unsigned char g_SmsDataLen;
        unsigned char g_EnSendToXinhao;
		
        unsigned char g_SmsReSendWaitCount; //¶ÌĞÅÖØ·¢µÈ´ıÊ±¼ä
        unsigned char g_SmsReSendTime;   //¶ÌĞÅÖØ·¢´ÎÊı
    	unsigned char g_SmsSendBuf[55];
		unsigned char g_CmIdRF;//RF¶ÔÏóÊ¹ÓÃµÄ´®¿ÚºÅ
		unsigned char  g_CmIdGPRS;
		unsigned char g_CmIdEX;//À©Õ¹¿ÚÊ¹ÓÃµÄ´®¿ÚºÅ
		unsigned char g_CmIdDBG;//µ÷ÊÔ¿ÚÊ¹ÓÃµÄ´®¿ÚºÅ
		unsigned char g_CmIdODU1;//ODU1Ê¹ÓÃµÄ´®¿ÚºÅ
		unsigned char g_CmIdODU2;//ODU2Ê¹ÓÃµÄ´®¿ÚºÅ
		unsigned int g_RstartNum;//ÏµÍ³ÖØÆô´ÎÊı
                
        //unsigned char g_unTX_Buff[2][256];            //Êı¾İ·¢ËÍÊı×é
    
    unsigned char g_unSMS_Index[MAX_SMS_NUM];              //´æ´¢ĞÂ²úÉúµÄ¶ÌĞÅ±êÖ¾
    unsigned char g_unFrameFlag_Sms=0;             //²úÉú¶ÌĞÅÊıÁ¿
    unsigned char g_unFrameFlag_curSms=0;             //²úÉú¶ÌĞÅÊıÁ¿
    unsigned char g_unSms_s=0;             //  0=¿ÉÒÔ·¢ËÍ¶ÌĞÅ  >0Í£Ö¹·¢ËÍ,µÈ´ıÕıÈ·»Ø¸´
    unsigned char g_unPhoneNo=0;
    unsigned char g_unSms_Count=0;     //¶ÌĞÅ·¢ËÍºó¼ÆÊ±£¬Èô15ÃëºóÎŞ»Ø¸´£¬ÖØ·¢
    unsigned char g_unFailSms=0;//¶ÌĞÅ·¢ËÍÊ§°Ü´ÎÊı
   // unsigned char g_unGPRSTX_Buff[MAX_TXBUFF_101_LEN];          //GPRSÊı¾İ·¢ËÍÊı×é 
    unsigned char g_unRX_Buff[1][MAX_RXBUFF_LEN];            //Êı¾İ½ÓÊÕÊı×é
    //unsigned char g_unLEDTX_Buff[MAX_TXBUFF_101_LEN];         //Êı¾İ·¢ËÍÊı×é
    unsigned char g_uc101BuffHead;   //GPRSÍ¨ĞÅ½ÓÊÕ»º³åÇøÊı¾İÍ·
    unsigned char g_uc101BuffDataHead;   //GPRSÍ¨ĞÅ½ÓÊÕ»º³åÇøÊı¾İÍ·    
    unsigned char g_uc101BuffTail;   //GPRSÍ¨ĞÅ½ÓÊÕ»º³åÇøÊı¾İÎ²
    
    unsigned char bFrameReceived[COMM_PORT_NUM];   //»º³åÇø½ÓÊÕĞÂÊı¾İ±êÖ¾
    //unsigned int g_ucBuffHead[2];   //Í¨ĞÅ½ÓÊÕ»º³åÇøÊı¾İÍ·
    //unsigned int g_ucBuffTail[2];   //Í¨ĞÅ½ÓÊÕ»º³åÇøÊı¾İÎ²
    
    //unsigned char g_ucUpdateTemp[256];   //Éı¼¶×¨ÓÃÊı×é
   
    //unsigned int g_unFrameFlag_101[2];  //101Ğ­ÒéÊı¾İÖ¡±êÖ¾Î»


   // const unsigned char VerNum[2]={0,22};   //×¢:  ĞŞ¸ÄÉú²úĞÂµÄ°æ±¾  V21
    //unsigned char TEL_NUM[55]={0};   //4×éµç»°ºÅÂë
    //unsigned char g_ucphone_perm[5];         //µç»°¶ÌĞÅµÄ¹¦ÄÜÑ¡Ôñ
    unsigned char ucTempTEL_NUM[11] = {0};  //ÁÙÊ±´æ´¢ºÅÂë£¬ÓÃÓÚ×ÓÕ¾µÄ²éÑ¯

    unsigned int g_ucGPRSTxlen;         //·¢ËÍÖĞ¶ÏÊı¾İ³¤¶È
    unsigned int g_ucGPRSTxNum;         //

    unsigned int g_ucGPRSState=GPRSState_IDLE;					//GPRS×´Ì¬£¬0=IDLE,1=GPRS101£¬2=SMS//ÕÅ| 0330 
    unsigned int g_ucGPRSState_TCounter;		//GPRS×´Ì¬Ê±¼ä¼ÆÊıÆ÷£¬Èç¹û³¤Ê±¼ä²»´¦ÓÚ0=IDLE×´Ì¬£¬Ôò»Ö¸´0=IDLE×´Ì¬//ÕÅ| 0330
    
    unsigned int g_uc232Txlen;         //·¢ËÍÖĞ¶ÏÊı¾İ³¤¶È
    unsigned int g_uc232TxNum;         //
    
    unsigned char sign_RSSI_time[6];              ////year month day hour minute second 
    unsigned char pulse_flag=0;                  ////////°ËÂö³å¼ì²âµ½±êÖ¾   0x55
    unsigned char wave_counter=0;                //////// ¶Ô·¢ÏÖ8Âö³åºó£¬²É¼¯µÄÖÜ²¨½øĞĞ¼ÆÊı

    //unsigned char pulse_time_flag;             ////////µÚÒ»´Î·¢ÏÖ8Âö³åºó£¬ÖÃ±êÖ¾£¬ÎªÔÚ10ÃëÄÚÍê³ÉÌá¹©±êÖ¾
    unsigned char g_ucPara_stime;  //Ö÷¶¯ÉÏ´«¼ä¸ôÊ±¼ä
    unsigned char eight_pulse_counter;
    unsigned int unFrameNum = 0; //ÁÙÊ±´æ´¢´ı·¢ËÍ¶ÌĞÅÌõÊı
    unsigned char g_uc101Flg = 0;
    
    /*unsigned char g_ucRELConfirm;   //Í¨ĞÅÓÃÒ£¿ØÈ·ÈÏ±êÖ¾
    unsigned char g_ucRELUNM;       //Í¨ĞÅÓÃÒ£¿Ø¼ÌµçÆ÷µÄË³ĞòºÅ
    unsigned int g_unRELTimeFlg;    //Í¨ĞÅÓÃ¼ÌµçÆ÷Ñ¡ÔñÊ±¼ä±êÖ¾
    unsigned int g_unRELTimeFlg_101;
    
    unsigned int g_unOffset;    //ÎïÀíµØÖ·×ª»»Æ«ÒÆÁ¿*/
    char  ComtrderCfg1[310];
    char  ComtrderCfg_adj[50];

        unsigned char g_EncComNo;        //ÄÄ¸ö´®¿ÚÔÚÅÜ¼ÓÃÜÊı¾İ1==GPRS 2 ==DeBug£¬ ÆäÓàÎŞĞ§
		//WORD g_validity[64];
        unsigned char g_bEncCerTxt[1024];  //¼ÓÃÜCERÖ¤Êé
        unsigned char g_bHostRandom[8];  //Ö÷Õ¾Ëæ»úÊı
        unsigned char m_bUnitRandom[8];   //ÖÕ¶Ë×ÔÉíËæ»úÊı£¬ÓÃÓÚÓëÔËÎ¬¹¤¾ßÍ¨ĞÅ
        int g_wEncCerWPtr;                 //CerÖ¤Êé¼ÇÂ¼Î»Ö	
        char g_bUnitID[25];//ÖÕ¶ËID,24×Ö½ÚµÚÒ»¸ö×ÖÊÇ½Ú³¤¶È   
        unsigned char g_bAppType;//¼ÓÃÜ±¨ÎÄÓ¦ÓÃÀàĞÍ        
#else
    extern struct  sTX_BUFF g_sTxBuff[COMM_PORT_NUM];
    extern struct  sRX_BUFF g_sRxBuff[COMM_PORT_NUM];
    //extern struct  sRX_BUFF_LED  g_sRX_BUFF_LED;
    extern char g_YkOrderFlag;//±êÊ¶Ò£¿ØÊÇ·ñ³É¹¦
    extern unsigned char g_GprsPowerSt;//GPRSµçÔ´×´Ì¬ 0=¹Ø±Õ 1= ´ò¿ª
     extern unsigned char g_batPowerSt;//bat×´Ì¬ 0=¹Ø±Õ 1= ´ò?    extern int g_ODUYK;//

	extern unsigned char g_SmsWritePtr;
	extern unsigned char g_EnSmsSend;
	extern unsigned char g_SmsDataLen;
    extern unsigned char g_EnSendToXinhao;
    extern unsigned char g_SmsReSendWaitCount;
    extern unsigned char g_SmsReSendTime;
    extern unsigned char g_SmsSendBuf[55];
	extern unsigned char g_CmIdRF;//RF¶ÔÏóÊ¹ÓÃµÄ´®¿ÚºÅ
	extern unsigned char  g_CmIdGPRS;
	extern unsigned char g_CmIdEX;//À©Õ¹¿ÚÊ¹ÓÃµÄ´®¿ÚºÅ
	extern unsigned char g_CmIdDBG;//µ÷ÊÔ¿ÚÊ¹ÓÃµÄ´®¿ÚºÅ
	extern unsigned char g_CmIdODU1;//ODU1Ê¹ÓÃµÄ´®¿ÚºÅ
	extern unsigned char g_CmIdODU2;//ODU2Ê¹ÓÃµÄ´®¿ÚºÅ
	
    extern int g_pODU2WaitCount;//ODUµçÔ´¹Ø±ÕÇëÇóODU2µÄ½ÓÊÕ¼ÆÊ±
	extern int g_pODUWaitCount;//ODUµçÔ´¹Ø±ÕÇëÇó
	extern unsigned int g_RstartNum;//ÏµÍ³ÖØÆô´ÎÊı
        
    //extern unsigned char g_unTX_Buff[2][256];
    
    extern unsigned char g_unSMS_Index[MAX_SMS_NUM];              //´æ´¢ĞÂ²úÉúµÄ¶ÌĞÅ±êÖ¾; 
    extern unsigned char g_unFrameFlag_Sms;             //²úÉú¶ÌĞÅÊıÁ¿
    extern unsigned char g_unFrameFlag_curSms;             //²úÉú¶ÌĞÅÊıÁ¿     
    extern unsigned char g_unSms_s;             //  1=¿ÉÒÔ·¢ËÍ¶ÌĞÅ  0=Í£Ö¹·¢ËÍ    
    extern unsigned char g_unPhoneNo;
    extern unsigned char g_unSms_Count;	
    extern unsigned char g_unFailSms;//¶ÌĞÅ·¢ËÍÊ§°Ü´ÎÊı
    //extern unsigned char g_unGPRSTX_Buff[MAX_TXBUFF_101_LEN];          //GPRSÊı¾İ·¢ËÍÊı×é
    
    extern unsigned char g_unRX_Buff[1][MAX_RXBUFF_LEN];
    //extern unsigned char g_unLEDTX_Buff[MAX_TXBUFF_101_LEN];         //Êı¾İ·¢ËÍÊı×é
    

    extern unsigned char bFrameReceived[COMM_PORT_NUM];   //»º³åÇø½ÓÊÕĞÂÊı¾İ±êÖ¾

    //extern unsigned int g_ucBuffHead[2];         //Í¨ĞÅ½ÓÊÕ»º³åÇøÊı¾İÍ·
    //extern unsigned int g_ucBuffTail[2];         //Í¨ĞÅ½ÓÊÕ»º³åÇøÊı¾İÎ²
    extern unsigned char g_uc101BuffHead;
    extern unsigned char g_uc101BuffDataHead;   //GPRSÍ¨ĞÅ½ÓÊÕ»º³åÇøÊı¾İÍ·  	
    extern unsigned char g_uc101BuffTail;
    //extern unsigned char g_ucUpdateTemp[256];   //Éı¼¶×¨ÓÃÊı×é
 
    //extern unsigned int g_unFrameFlag_101[2];  //101Ğ­ÒéÊı¾İÖ¡±êÖ¾Î»
  //  extern const unsigned char VerNum[2];   //×¢:  ĞŞ¸ÄÉú²úĞÂµÄ°æ±¾  V21
    //extern unsigned char TEL_NUM[55];   //5×éµç»°ºÅÂë
    //extern unsigned char g_ucphone_perm[5];         //µç»°¶ÌĞÅµÄ¹¦ÄÜÑ¡Ôñ
    extern unsigned char ucTempTEL_NUM[11];  //ÁÙÊ±´æ´¢ºÅÂë£¬ÓÃÓÚ×ÓÕ¾µÄ²éÑ¯

    extern unsigned int g_ucGPRSTxlen;         //·¢ËÍÖĞ¶ÏÊı¾İ³¤¶È
    extern unsigned int g_ucGPRSTxNum;         //

    extern unsigned int g_ucGPRSState;         //GPRS×´Ì¬£¬0=IDLE,1=GPRS101£¬2=SMS//ÕÅ| 0330 
    extern unsigned int g_ucGPRSState_TCounter;         //GPRS×´Ì¬Ê±¼ä¼ÆÊıÆ÷£¬Èç¹û³¤Ê±¼ä²»´¦ÓÚ0=IDLE×´Ì¬£¬Ôò»Ö¸´0=IDLE×´Ì¬//ÕÅ| 0330
	
    
    extern unsigned int g_uc232Txlen;         //·¢ËÍÖĞ¶ÏÊı¾İ³¤¶È
    extern unsigned int g_uc232TxNum;         //
    
    extern unsigned char sign_RSSI_time[6];              ////year month day hour minute second
    extern unsigned char pulse_flag;                  ////////°ËÂö³å¼ì²âµ½±êÖ¾   0x55
    extern unsigned char wave_counter;                //////// ¶Ô·¢ÏÖ8Âö³åºó£¬²É¼¯µÄÖÜ²¨½øĞĞ¼ÆÊı
 
    extern unsigned char g_ucPara_stime;  //Ö÷¶¯ÉÏ´«¼ä¸ôÊ±¼ä
    extern unsigned char pulse_time_flag;             ////////µÚÒ»´Î·¢ÏÖ8Âö³åºó£¬ÖÃ±êÖ¾£¬ÎªÔÚ10ÃëÄÚÍê³ÉÌá¹©±êÖ¾
    extern unsigned char eight_pulse_counter;
    extern unsigned int unFrameNum; //ÁÙÊ±´æ´¢´ı·¢ËÍ¶ÌĞÅÌõÊı
    extern unsigned char g_uc101Flg;
    extern char  ComtrderCfg1[310];
    extern char  ComtrderCfg_adj[50];
   /* extern unsigned char g_ucRELConfirm;   //Í¨ĞÅÓÃÒ£¿ØÈ·ÈÏ±êÖ¾
    extern unsigned char g_ucRELUNM;       //Í¨ĞÅÓÃÒ£¿Ø¼ÌµçÆ÷µÄË³ĞòºÅ
    extern unsigned int g_unRELTimeFlg;    //Í¨ĞÅÓÃ¼ÌµçÆ÷Ñ¡ÔñÊ±¼ä±êÖ¾
    extern unsigned int g_unRELTimeFlg_101;
    
    extern unsigned int g_unOffset;    //ÎïÀíµØÖ·×ª»»Æ«ÒÆÁ¿ */
        extern unsigned char g_EncComNo;
	extern unsigned char g_bEncCerTxt[1024];
        extern unsigned char g_bHostRandom[8];  //Ö÷Õ¾Ëæ»úÊı
        extern unsigned char m_bUnitRandom[8];
        extern int g_wEncCerWPtr;   
        extern char g_bUnitID[25];//ÖÕ¶ËID,24×Ö½ÚµÚÒ»¸ö×ÖÊÇ½Ú³¤¶È   
        extern unsigned char g_bAppType;//¼ÓÃÜ±¨ÎÄÓ¦ÓÃÀàĞÍ 
#endif
    
//=======================DriverTimer.c--¶¨Ê±Æ÷Çı¶¯Ä£¿é===============================================
 struct sTIMER_MANAGER
  {
    unsigned int m_TmCount;
    unsigned char m_TmFlag;
	unsigned int m_TmCountBk;//±£´æÉÏÒ»´ÎÉèÖÃµÄ¶¨Ê±¼ä¸ô
  };
#ifdef _DRIVER_TIMER
        struct sTIMER_MANAGER g_sTimer[TIMER_NUM];
        unsigned int Time_10ms_T;
        unsigned int g_DateCount;  //×´Ì¬»ã±¨ÌìÊı¼ÆÊıÆ÷
        unsigned char g_StatusTime;
        unsigned char g_SendStatus;
        unsigned char g_SmsSendStatus; //¶ÌĞÅ»ã±¨×´Ì¬±êÖ¾Î»
        unsigned char g_SendFault;
        unsigned int TA1OffsetNum = 250;
        unsigned char Powerdown_counter;
#else
        extern struct sTIMER_MANAGER g_sTimer[TIMER_NUM];
        extern unsigned int g_DateCount;
        extern unsigned char g_StatusTime;
        extern unsigned char g_SendStatus;
        extern unsigned char g_SmsSendStatus;
	
        extern unsigned char g_SendFault;
        
        extern unsigned char Powerdown_counter;
#endif
//=================================== Ê±ÖÓÄ£¿é ==========================================

  struct sRTC_MANAGER
  {
    unsigned char m_ucRtcSynFlag;   //ÏµÍ³ÊµÊ±Ê±ÖÓ´ÓÊµÊ±Ğ¾Æ¬ÖĞ¶ÁÈ¡µÄ±êÖ¾£¬Ã¿5·ÖÖÓ¶ÁÈ¡Ò»´Î
    unsigned int m_unRtcSynCount;   //ÏµÍ³Í¬²½¼ä¸ôÊ±¼ä¼ÆÊ±£¬¼ÆÂú5·ÖÖÓ£¬ÖÃm_ucRtcSynFlag±êÖ¾
    unsigned int m_unStartCount;		//¿ª»ú¼ÆÊ±£¬ÔÚ¸Õ¿ª»úµÄ3SÄÚ°ÑÔËĞĞµÈ³£ÁÁ
    unsigned int m_gRealTimer[RTC_NUM]; //ÏµÍ³ÄÚ²¿ÊµÊ±Ê±ÖÓ£¬Äê¡¢ÔÂ¡¢ÈÕ¡¢Ê±¡¢·Ö¡¢Ãë¡¢ºÁÃë
    unsigned char m_ucCounter125;     ///1.25msÊ±¼ä¼ÆÊıÆ÷
    unsigned char m_ucCounter10;     ///10msÊ±¼ä¼ÆÊıÆ÷
  };
 
  
#ifdef _DRIVER_RTC
  
  struct sRTC_MANAGER g_sRtcManager;  //ÏµÍ³ÊµÊ±Ê±ÖÓ
  unsigned int g_gRealTimerbk[RTC_NUM];
#else
  extern struct sRTC_MANAGER g_sRtcManager;
  extern unsigned int g_gRealTimerbk[RTC_NUM];
  

#endif

//================================== IOÇı¶¯Ä£¿é ===========================================
#ifdef _DRIVER_IO

	unsigned int g_gExtDinStat[2];	//Íâ²¿¿ª¹ØÁ¿ÊäÈëÈ·ÈÏ×´Ì¬£¬µÚÒ»¸öÎªÉÏÒ»ÖÜÆÚ£¬µÚ¶ş¸öÎªµ±Ç°ÖÜÆÚ
        unsigned int g_gExtDinYesTimer[3];	//Íâ²¿DINÊäÈëÈ·ÈÏÊ±¼ä¼ÆÊ±
	unsigned int g_gExtDinNoTimer[3];		//Íâ²¿DINÊäÈëÇå³ıÊ±¼ä¼ÆÊ±
	unsigned char g_gPhasErrTimer[3];	      //¿ª¹ØÎ»ÖÃ´íÎóÈ·ÈÏÊ±¼ä¼ÆÊ±
	unsigned char g_gI0OverTimer;		//I0³¬Ê±È·ÈÏÊ±¼ä¼ÆÊ±
	//unsigned char g_gExtDinNoTimer[3];		//Íâ²¿DINÊäÈëÇå³ıÊ±¼ä¼ÆÊ±
        //unsigned int g_gDinRtcLock[2][RTC_NUM];
	
        unsigned char g_gucPhaseSQU[3];  //´æ´¢ÏàĞò¼ì²â¸÷Ïà¹ıÁã±êÖ¾Êı
        unsigned char g_gucPhaseSQUTestNum;  //ÏàĞò¼ì²â¸÷Ïà¹ıÁãµã¼ÆÊı
        unsigned int rh_counter=0;//È¼»¡³É¹¦Ò£ĞÅ ÑÓÊ±¼ÆÊıÆ÷
        unsigned int rh_send_ok=0;//È¼»¡Âö³å·¢ËÍÍê³É =0x55 ·¢³ö8Âö³å =0x85 ¹ÊÕÏÏûÊ§ =0        
        unsigned int fault_time=0;            ///////¹ÊÕÏ¼ÆÊıÖµ
        unsigned char fault_begin;               //¹ÊÕÏ³öÏÖÑÓÊ± 
        unsigned char fault_pluse;//¹ÊÕÏÏàÎ»
        unsigned char fault_end;                 //¹ÊÕÏ»Ö¸´ÑÓÊ±
        
        unsigned char fault_begin_first = 0;               //¹ÊÕÏÆô¶¯³öÏÖÑÓÊ±
        
        unsigned char abnormal_counter=0;              //////×°ÖÃÒì³£¼ÆÊıÆ÷£¬»ú¹¹5´Î±¨Òì³£
        
        unsigned char save_abnormal;
        unsigned char fault_save;             ///////¹ÊÕÏ´æ´¢±êÖ¾,Í¬Ê±×ö¹ÊÕÏ·¢Éú±êÖ¾£¬0£ºÎŞ¹ÊÕÏ£¬0x33£ºÓĞ¹ÊÕÏ

        unsigned char upload_GPRS;
        unsigned char upload_SMS;              ////Ã¿¸ô60ÃëÖÓ·¢ËÍÒ»Ìõ¶ÌĞÅ¡£
        unsigned int   km_timeout; 
        unsigned int   i0_timeout; 		
	 unsigned int   ptoff_timeout; 	
	 unsigned char soft_latch;	
       // unsigned char SMS_delay;               ////ÑÓÊ±¶ÌĞÅÑÓÊ±Ã¿¸ô2ÃëÖÓ·¢ËÍÒ»Ìõ¶ÌĞÅ¡£      
        unsigned char main_reset_flag = 0;//=0x00;            /////////Ö÷°å¸´Î»±êÖ¾
        unsigned char flash_write;                 ////////Ğ´Â¼²¨Êı¾İµ½FLASH

        unsigned char upload_flag;               ///the of upload                3           2         1           0
        unsigned char upload_interval[4];        ///self upload interval        ¶ÏÏß    eight_pulse power_down  abnormal  
        unsigned char upload_interval_set = 3;       ///transmit interval parameter default 3 minutes   the range is 3-15 minutes  
//=============================== µ÷ÓÃÍâ²¿²ÎÊı ===============================///
        
        unsigned char eight_ctl_flag=0;              ///////8Âö³åÒ£¿Ø±êÖ¾,ÓĞĞ§8Âö³åºó£¬Ò£¿ØÊä³ö5Ãë
        unsigned char power_ctl_flag=0;              ///////¶ÏµçÒ£¿Ø±êÖ¾
        unsigned char abnormal_ctl_flag=0;           ///////Òì³£Ò£¿Ø±êÖ¾
        
        unsigned char phase_off=0x07;               ////////////ÉÏµçÈÏÎª³öÏÖ¶ÏÏß
        unsigned char phase_copy=0x07;              ////////////ÉÏµçÈÏÎª³öÏÖ¶ÏÏß
        
        unsigned char save_power_off=0;             ////////////´æ´¢¶Ïµç±êÖ¾ 
        unsigned char power_off_flag=0;           ///////¶Ïµç±êÖ¾
        
        unsigned char save_phase_off=0;          //´æ´¢¶ÏÏß±êÖ¾
        unsigned char latch_upload_flag=0;         //////////±ÕËø»òÕß½âËøºóÖÃ±êÖ¾£¬Ö÷¶¯ÉÏ·¢Ò»Ö¡×´Ì¬Ö¡
        
        unsigned int state_counter = 0;             //ÉÏ´«Ê±¼ä¼ä¸ô¼ÆÊı£¬·ÖÖÓ¼ÆÊ±
        
        unsigned char eight_delay_flag=0;              ////////¹ÊÕÏºóÑÓÊ±8Ãë·¢8Âö³å±êÖ¾            
        unsigned char eight_delay_counter=0;           ////////¹ÊÕÏºóÑÓÊ±2Ãë·¢8Âö³å¼ÆÊıÆ÷
        
        unsigned char pulse_counter=0;               ////////¶Ô²É¼¯µÄÂö³åÊı½øĞĞÍ³¼Æ£¬ÓÃ×÷Êı¾İ´æ´¢¶¨Î»

        unsigned char comm_rec_flag;

        //unsigned char phone_perm[4];	//          5        4         3        2       1      0
						                    //      ¹ÊÕÏ¸´¹é  ·¢Éú¹ÊÕÏ Ö÷¶¯ÉÏ±¨ ÓĞĞ§8Âö³å µôµç  ×´Ì¬Òì³£
						//ÊÖ»úµÄÈ¨ÏŞ¿ØÖÆ×Ö
        unsigned char SMS_array;      /////////µÈ´ı·¢ËÍµÄ¹ÊÕÏ£¬ÁùÖÖÇé¿ö£¬4¸öÊÖ»úºÅ£¬¹²24¸ö£»					
    
        unsigned char send_phase;
        unsigned int yc[8];	// 8Âö³åÒ£²âÖµ

        //unsigned char yc1[8];	// 8Âö³åÒ£²âÖµ
        unsigned char sign_RSSI_time1[6];              ////year month day hour minute second 
        unsigned char eight_select;                  /////´«¶¯µÚ¼¸´Î8Âö³å

        //unsigned char yc2[8];	// 8Âö³åÒ£²âÖµ
        unsigned char sign_RSSI_time2[6];              ////year month day hour minute second
        
       // unsigned char bais_check;                    //¼ì²âÆ«ÖÃµçÑ¹


        unsigned char pulse_phase_flag=0;              ////////ÄÄÒ»Ïà·¢8Âö³åµÄ±êÖ¾
        unsigned int efslatch_flag;                   ////////±ÕËø17·ÖÖÓ±êÖ¾
       // unsigned char eight_delay_counter;           ////////¹ÊÕÏºóÑÓÊ±2Ãë·¢8Âö³å¼ÆÊıÆ÷
        unsigned char chongfa;                       ////////ÖØ·¢±êÖ¾ 
        unsigned char moniguzhang;                       ////////Ä£Äâ¹ÊÕÏ

        unsigned char phase_check_flag = 0x55;//=0x55;          /////////¼ì²âÏàÎ»Òì³£±êÖÂ    0x00 ²»¼ì²â£¬  0x55×¼±¸¼ì²â             
        unsigned char phase_check_time = 30;//=24;            /////////¹ÊÕÏÒÑ¾­¼ì²âÍê     Ã¿¸ôÁ½¸öĞ¡Ê±¼ì²âÒ»´Î£¬ÉÏµç¼ì²âÒ»´Î   
        unsigned char phase_seq_flag;//=0x00;                 ///////// ³õÊ¼»¯ÉèÖÃÎªÕıÏàĞò   0x00ÕıÏàĞí  0x55 ÄæÏàĞò

///////////////////////////Ğ´ÈëFLASHÖĞ


        unsigned char VerNumlcd[2]; 

        unsigned char sign_RSSI_delay; 
	 unsigned char newsms_8pluse; 
	 unsigned char newsms_abn; 
        unsigned char fault_point;                ////////ÓÃÀ´È·¶¨ÊÇ¶ÁÈ¡µÄÄÇ¸öÂ¼²¨»òÕß¹ÊÕÏ¼ÇÂ¼

        unsigned char fault_recovery_flag;//=0;      ///////¹ÊÕÏ¸´¹é±êÖ¾
        unsigned char fault_sms_type;            //////////¹ÊÕÏ×´Ì¬£¬µ±¹ÊÕÏ·¢ÉúÊ±£¬·ÅÔÚ×Ô¶¯ÉÏ´«µÄ¶ÌĞÅµÄ×îºó

        unsigned char pulse_success;                   ////////Âö³å·¢ËÍ³É¹¦,ÓÃÓÚÒº¾§ÏÔÊ¾Î¬³Ö17·ÖÖÓ
        unsigned char eight_pulse_flag;              ////////¿ªÊ¼·¢8Âö³åµÄ±êÖ¾

        unsigned char repeat_flag1;               //////////ÌúÂ·ĞÍĞÅºÅÔ´ÖØ·¢±êÖ¾£¬¼ì²âµ½µçÁ÷³¬¹ı35A£¬¾ÍÖØ·¢¡£

      //  unsigned char phase_copy;              ////////////ÉÏµçÈÏÎª³öÏÖ¶ÏÏß

 
        unsigned char recieve_confirm_flag;   //  ÓÃÓÚ¾ö¶¨²ÉÓÃºÎÖÖÓ¦´ğ·½Ê½
        unsigned char Process_68_flag;

        unsigned char process_type=0;     //  Ö÷Õ¾ÓëÖÕ¶ËÖ®¼äÍ¨ĞÅÊ±µÄ ¹¦ÄÜÀàĞÍ 
       // unsigned char process_step=0;     //  Ã¿ÖÖ¹¦ÄÜµÄ´¦Àí²½Öè
        unsigned char process_pro=0;      //  ¹¦ÄÜ²½Öè¶ÔÓ¦µÄÓÅÏÈ¼¶£¬Ö÷ÒªÓÃÓÚÓë¹ÊÕÏÖ÷¶¯ÉÏ´«×ö±È½Ï
        unsigned char command_flag=0;    // Ö÷¶¯·¢ËÍÊı¾İÊ±µÄ ·¢ËÍÔ­Òò
        unsigned char command_flag2=0;  // Ö÷¶¯·¢ËÍÊı¾İÊ±,Ôö¼ÓÒ»¸ö»º³å´¦ÀíÈÎÎñ
        unsigned char fault_num;
      //  unsigned char process_pro;
        unsigned char event_pro;
       // unsigned char self_chongfa_flag;
        unsigned char uart0_event_flag;
        unsigned char g_ucEarthFlg = 0;  //¹ÊÕÏÏà±êÊ¾
        unsigned char g_ucPowerOffFlg = 0;  //µôµç±êÊ¾
       // unsigned char g_ucPTabnormal = 0;  //µçÑ¹Òì³£±êÊ¾
        unsigned char g_ucDuanxianFlg = 0;
#else
 	//extern unsigned int g_gDinRtcLock[2][RTC_NUM];
        
        extern unsigned char g_gucPhaseSQU[3];  //´æ´¢ÏàĞò¼ì²â¸÷Ïà¹ıÁã±êÖ¾Êı
        extern unsigned char g_gucPhaseSQUTestNum;  //ÏàĞò¼ì²â¸÷Ïà¹ıÁãµã¼ÆÊı
        extern unsigned int rh_counter;//È¼»¡³É¹¦Ò£ĞÅ ÑÓÊ±¼ÆÊıÆ÷  
        extern unsigned int rh_send_ok;//È¼»¡Âö³å·¢ËÍÍê³É =1 ·¢³ö8Âö³å =0          
        extern unsigned int fault_time;            ///////¹ÊÕÏ¼ÆÊıÖµ
        extern unsigned char fault_begin;               //¹ÊÕÏ³öÏÖÑÓÊ±              
        extern unsigned char fault_end;                 //¹ÊÕÏ»Ö¸´ÑÓÊ±
        extern unsigned char fault_pluse;//¹ÊÕÏÏàÎ»        
        extern unsigned char fault_begin_first;
        
        extern unsigned char abnormal_counter;              //////×°ÖÃÒì³£¼ÆÊıÆ÷£¬»ú¹¹5´Î±¨Òì³£

        extern unsigned char save_abnormal;
        extern unsigned char fault_save;             ///////¹ÊÕÏ´æ´¢±êÖ¾,Í¬Ê±×ö¹ÊÕÏ·¢Éú±êÖ¾£¬0£ºÎŞ¹ÊÕÏ£¬0x33£ºÓĞ¹ÊÕÏ

        extern unsigned char upload_GPRS;
        extern  unsigned char upload_SMS;              ////Ã¿¸ô60ÃëÖÓ·¢ËÍÒ»Ìõ¶ÌĞÅ¡£
        extern unsigned char SMS_delay;               ////ÑÓÊ±¶ÌĞÅÑÓÊ±Ã¿¸ô2ÃëÖÓ·¢ËÍÒ»Ìõ¶ÌĞÅ¡£   
        extern unsigned int   km_timeout; 
        extern unsigned int   i0_timeout; 		
	 extern unsigned int   ptoff_timeout;	
	 extern unsigned char soft_latch;	
        extern unsigned char main_reset_flag;//=0x00;            /////////Ö÷°å¸´Î»±êÖ¾
        extern unsigned char flash_write;                 ////////Ğ´Â¼²¨Êı¾İµ½FLASH

        extern unsigned char upload_flag;               ///the of upload                3           2         1           0
        extern unsigned char upload_interval[4];        ///self upload interval        ¶ÏÏß    eight_pulse power_down  abnormal  
        extern unsigned char upload_interval_set;       ///transmit interval parameter default 3 minutes   the range is 3-15 minutes  

//×¢:2013-2-14 Ôö¼ÓÈ«¾Ö²ÎÊıÊı×é,·½±ãÍ¨ĞÅ
       // extern unsigned char g_ucNamePARA[44];

//=============================== µ÷ÓÃÍâ²¿²ÎÊı ===============================///
        
        extern unsigned char eight_ctl_flag;              ///////8Âö³åÒ£¿Ø±êÖ¾,ÓĞĞ§8Âö³åºó£¬Ò£¿ØÊä³ö5Ãë
        extern unsigned char power_ctl_flag;              ///////¶ÏµçÒ£¿Ø±êÖ¾
        extern unsigned char abnormal_ctl_flag;           ///////Òì³£Ò£¿Ø±êÖ¾
        
        extern unsigned char phase_off;               ////////////ÉÏµçÈÏÎª³öÏÖ¶ÏÏß
        extern unsigned char phase_copy;              ////////////ÉÏµçÈÏÎª³öÏÖ¶ÏÏß
        
        extern unsigned char save_power_off;             ////////////´æ´¢¶Ïµç±êÖ¾ 
        extern unsigned char power_off_flag;           ///////¶Ïµç±êÖ¾
        
        extern unsigned char save_phase_off;          //´æ´¢¶ÏÏß±êÖ¾
        extern unsigned char latch_upload_flag;         //////////±ÕËø»òÕß½âËøºóÖÃ±êÖ¾£¬Ö÷¶¯ÉÏ·¢Ò»Ö¡×´Ì¬Ö¡
        
        extern unsigned int state_counter;             //ÉÏ´«Ê±¼ä¼ä¸ô¼ÆÊı£¬·ÖÖÓ¼ÆÊ±
        
        extern unsigned char eight_delay_flag;              ////////¹ÊÕÏºóÑÓÊ±8Ãë·¢8Âö³å±êÖ¾            
        extern unsigned char eight_delay_counter;           ////////¹ÊÕÏºóÑÓÊ±2Ãë·¢8Âö³å¼ÆÊıÆ÷
        
        extern unsigned char pulse_counter;               ////////¶Ô²É¼¯µÄÂö³åÊı½øĞĞÍ³¼Æ£¬ÓÃ×÷Êı¾İ´æ´¢¶¨Î»
       
        extern unsigned char comm_rec_flag;
        //extern unsigned char phone_perm[4];	//          5        4         3        2       1      0						                    //      ¹ÊÕÏ¸´¹é  ·¢Éú¹ÊÕÏ Ö÷¶¯ÉÏ±¨ ÓĞĞ§8Âö³å µôµç  ×´Ì¬Òì						//ÊÖ»úµÄÈ¨ÏŞ¿ØÖÆ×Ö
        extern unsigned char SMS_array;
     
        extern unsigned char send_phase;
        extern unsigned int yc[8];	// 8Âö³åÒ£²âÖµ

        //extern unsigned char yc1[8];	// 8Âö³åÒ£²âÖµ
        extern unsigned char sign_RSSI_time1[6];              ////year month day hour minute second 
        extern unsigned char eight_select;                  /////´«¶¯µÚ¼¸´Î8Âö³å

        //extern unsigned char yc2[8];	// 8Âö³åÒ£²âÖµ
        extern unsigned char sign_RSSI_time2[6];              ////year month day hour minute second

        extern unsigned char pulse_phase_flag;              ////////ÄÄÒ»Ïà·¢8Âö³åµÄ±êÖ¾
        extern unsigned int efslatch_flag;                   ////////±ÕËø17·ÖÖÓ±êÖ¾
        extern unsigned char eight_delay_counter;           ////////¹ÊÕÏºóÑÓÊ±2Ãë·¢8Âö³å¼ÆÊıÆ÷
        extern unsigned char chongfa;                       ////////ÖØ·¢±êÖ¾ 
        extern unsigned char moniguzhang;                       ////////Ä£Äâ¹ÊÕÏ
        extern unsigned char phase_check_flag;//=0x55;          /////////¼ì²âÏàÎ»Òì³£±êÖÂ    0x00 ²»¼ì²â£¬  0x55×¼±¸¼ì²â             
        extern unsigned char phase_check_time;//=24;            /////////¹ÊÕÏÒÑ¾­¼ì²âÍê     Ã¿¸ôÁ½¸öĞ¡Ê±¼ì²âÒ»´Î£¬ÉÏµç¼ì²âÒ»´Î   
        extern unsigned char phase_seq_flag;//=0x00;                 ///////// ³õÊ¼»¯ÉèÖÃÎªÕıÏàĞò   0x00ÕıÏàĞí  0x55 ÄæÏàĞò

       // extern unsigned char lcd_ctl;                       /////////Òº¾§ÊÇ·ñÔÚ·¢ËÍÊı¾İ


///////////////////////////Ğ´ÈëFLASHÖĞ
       // extern unsigned char fault_delay_time;        //¹ÊÕÏÑÓÊ±Ê±¼ä    
        //extern unsigned int cal_value[5];

        extern unsigned char VerNumlcd[2]; 


        extern unsigned char sign_RSSI_delay; 
	 extern unsigned char newsms_8pluse; 
         extern unsigned char newsms_abn; 
        //extern unsigned char fault_point;                ////////ÓÃÀ´È·¶¨ÊÇ¶ÁÈ¡µÄÄÇ¸öÂ¼²¨»òÕß¹ÊÕÏ¼ÇÂ¼

        extern unsigned char fault_recovery_flag;//=0;      ///////¹ÊÕÏ¸´¹é±êÖ¾
        extern unsigned char fault_sms_type;            //////////¹ÊÕÏ×´Ì¬£¬µ±¹ÊÕÏ·¢ÉúÊ±£¬·ÅÔÚ×Ô¶¯ÉÏ´«µÄ¶ÌĞÅµÄ×îºó

        extern unsigned char pulse_success;                   ////////Âö³å·¢ËÍ³É¹¦,ÓÃÓÚÒº¾§ÏÔÊ¾Î¬³Ö17·ÖÖÓ
        extern unsigned char eight_pulse_flag;              ////////¿ªÊ¼·¢8Âö³åµÄ±êÖ¾


        extern unsigned char repeat_flag1;               //////////ÌúÂ·ĞÍĞÅºÅÔ´ÖØ·¢±êÖ¾£¬¼ì²âµ½µçÁ÷³¬¹ı35A£¬¾ÍÖØ·¢¡£

        extern unsigned char phase_copy;              ////////////ÉÏµçÈÏÎª³öÏÖ¶ÏÏß

 
        extern unsigned char recieve_confirm_flag;   //  ÓÃÓÚ¾ö¶¨²ÉÓÃºÎÖÖÓ¦´ğ·½Ê½
        extern unsigned char Process_68_flag;
       //extern  unsigned char Note_Flag;

       extern  unsigned char process_type;     //  Ö÷Õ¾ÓëÖÕ¶ËÖ®¼äÍ¨ĞÅÊ±µÄ ¹¦ÄÜÀàĞÍ 
        //extern unsigned char process_step;     //  Ã¿ÖÖ¹¦ÄÜµÄ´¦Àí²½Öè
        extern unsigned char process_pro;      //  ¹¦ÄÜ²½Öè¶ÔÓ¦µÄÓÅÏÈ¼¶£¬Ö÷ÒªÓÃÓÚÓë¹ÊÕÏÖ÷¶¯ÉÏ´«×ö±È½Ï
       extern  unsigned char command_flag;    // Ö÷¶¯·¢ËÍÊı¾İÊ±µÄ ·¢ËÍÔ­Òò
       extern  unsigned char command_flag2;  // Ö÷¶¯·¢ËÍÊı¾İÊ±,Ôö¼ÓÒ»¸ö»º³å´¦ÀíÈÎÎñ
       extern  unsigned char fault_num;
        extern unsigned char process_pro;
       extern  unsigned char event_pro;
      //extern  unsigned char self_chongfa_flag;
       extern  unsigned char uart0_event_flag;
       extern  unsigned char g_ucEarthFlg;  //¹ÊÕÏÏà±êÊ¾
       extern  unsigned char g_ucPowerOffFlg;  //µôµç±êÊ¾
      // extern  unsigned char g_ucPTabnormal;  //µçÑ¹Òì³£±êÊ¾
        extern unsigned char g_ucDuanxianFlg;
#endif


#ifdef __cplusplus
}
#endif

#endif  //end of file
