//ÔÚMSP430ÖÐµÄLongÐÍµÄÊý×éÊÇµÍ×ÖÔÚÇ°£¬¸ß×ÖÔÚºó

#ifndef _CONSTANT_H
#define _CONSTANT_H 

#define DEBUG
#define GETSOEFROMRAM     //·¢ËÍµÄSOE´ÓÍâ²¿FLASHÈ¡£¬»¹ÊÇ´ÓÄÚ²¿È¡¡£
//#define ZT_SOE_IN_FLASH //SOE´æÄÚ²¿FLASH
//#define ZDSENDADDR //Ö÷¶¯¸øÖÐÐÄÕ¾¶¨Ê±·¢ËÍ×ÔÉíÕ¾µØÖ·(ÌØÊâÓ¦ÓÃ) 
//#define YN_101S      //¶¨Òå=ÔÆÄÏ101¹æÔ¼£»²»¶¨Òå=±ê×¼101¹æÔ¼
//#define CQ_101S      //¶¨Òå=ÖØÇì101¹æÔ¼£»²»¶¨Òå=±ê×¼101¹æÔ¼
//#define INT_NEST      //ÕÅ|²âÊÔÖÐ¶ÏÇ¶Ì×       0//1=GPRS;0=SMS
//#define DH_101S      //¶¨Òå=µ¤»ªê»²©101¹æÔ¼£»²»¶¨Òå=±ê×¼101¹æÔ¼
#define SD_101S      //¶¨Òå=µ¤»ªê»²©101¹æÔ¼£»²»¶¨Òå=±ê×¼101¹æÔ¼

#define CONDIN_3      //½Ó´¥Æ÷Êä³ö3Â·¿ªºÏÐÅºÅ  È¡ÏûÐÅºÅÔ´Òì³£Ò£ÐÅ(¸¨Öú¿ª¹ØÌø¿ª)
//#define TWOP_CALB      //Two-point calibration methodÁ½µãÐ£×¼))

#define         TYPE_EQU                0x1111  //Éè±¸´úÂë

#define        INVALIDYC  0xD8F0//-9999
#define        INVALTEYC  0xFF9D//-99
#define        INITYC     0xDD47//-8888
#define        ODUINITYC     0xFFFF//ODU³õÊ¼»¯Öµ


 
#define         YES                     0x55
#define         NO                      0xAA
#define         ON                      0x5F
#define         OFF                     0x50
#define         CLOSE                   0x55
#define         TRIP                    0xAA

#define         LuboType_XH      0x55
#define         LuboType_ACT      0xAA

/*-------------------------------------------------------------------------
 *   Standard Bits
 *-------------------------------------------------------------------------*/
#define NBIT0                (0xFFFE)
#define NBIT1                (0xFFFD)
#define NBIT2                (0xFFFB)
#define NBIT3                (0xFFF7)
#define NBIT4                (0xFFEF)
#define NBIT5                (0xFFDF)
#define NBIT6                (0xFFBF)
#define NBIT7                (0xFF7F)
#define NBIT8                (0xFEFF)
#define NBIT9                (0xFDFF)
#define NBITA                (0xFBFF)
#define NBITB                (0xF7FF)
#define NBITC                (0xEFFF)
#define NBITD                (0xDFFF)
#define NBITE                (0xBFFF)
#define NBITF                (0x7FFF)

#define KJa1                (P4IN&0x08)//a½Ó´¥Æ÷¿ª¹ØÎ»ÖÃÐÅºÅ
#define KJb1                (P4IN&0x10)//
#define KJc1                (P4IN&0x20)//
#define KJ4                (P4IN&0x01)//Ò£ÐÅDIN4
#define KJ5                (P4IN&0x02)//Ò£ÐÅDIN5
#define KJ6                (P4IN&0x04)//Ò£ÐÅDIN6

#define KMP_S           (P3IN&0x80)//P3.7½Ó´¥Æ÷¶ÌÂ·

//===================Êý¾ÝÀàÐÍ¶¨Òå============================
typedef unsigned char  INT8U;       //ÎÞ·ûºÅ8Î»Êý
typedef          char  INT8S;       //ÓÐ·ûºÅ8Î»Êý
typedef unsigned int   INT16U;      //ÎÞ·ûºÅ16Î»Êý
typedef signed   int   INT16S;      //ÓÐ·ûºÅ16Î»Êý
typedef unsigned long  INT32U;      //ÎÞ·ûºÅ32Î»Êý
typedef signed   long  INT32S;      //ÓÐ·ûºÅ32Î»Êý
typedef float          FP32;        //µ¥¾«¶È¸¡µãÊý
typedef double         FP64;            //Ë«¾«¶È¸¡µãÊý

#define  GETBIT(p,i)   ((p[(i>>4)] & BIT[(i&0x0F)]) && 1)
#define  SETBIT(p,i,v) p[(i>>4)] = (v) ? (p[(i>>4)]|BIT[(i&0x0F)]) : (p[(i>>4)]&~BIT[(i&0x0F)])

//==============================IEC 101Ïà¹Ø²ÎÊý======================================
#define GPRS_SMS      //       0//1  =GPRS;0=SMS

#define IECP_LINKADDR_NUM    0//Á´Â·µØÖ·³¤¶È 1-2    
#define IECP_TRANSRSN_NUM    1//´«ÊäÔ­Òò³¤¶È 1-2   
#define IECP_COMNADDR_NUM    2 //¹«¹²µØÖ·³¤¶È 1-2  
#define IECP_INFO_NUM        3//ÐÅÏ¢ÌåµØÖ·³¤¶È 1-3 
#define IECP_COM_MODE        4//0Îª²»Æ½ºâÊ±£¬1ÎªÆ½ºâÊ½  Ä¬ÈÏÎª1
#define IECP_AUT_MODE        5//Ö÷¶¯ÉÏ´«Ä£Ê½£¬0=Ö÷Õ¾·¢ËÍ³õÊ¼»¯ºó·½¿ÉÖ÷¶¯ÉÏ´«ºÍ×ÜÕÙ
                              //1=ÊÕµ½Ö÷Õ¾ÈÎºÎÃüÁîºó·½¿ÉÖ÷¶¯ÉÏ´«£¬ÈÎºÎÊ±ºò¶¼ÏìÓ¦×ÜÕÙÃüÁî¡£
                              //2=Ö÷¶¯ÉÏ´«²»ÊÜÈÎºÎÔ¼Êø
#define IECP_OBJ_COM0        6 //µ÷ÊÔ´®¿Ú²¨ÌØÂÊ£¬0=9600£,19200£,38400£,57600£,115200
#define IECP_OBJ_COM1        7
#define IECP_OBJ_COM2        8
#define IECP_OBJ_COM3        9

#define IECP_CRC             10//crcÐ£Ñé

#define IEC_PARA_NUM    11  //IECÔËÐÐµÄ²ÎÊý¸öÊý

#define IEC_YC_NUM   16  //ÔÊÐí´«¸øÖ÷Õ¾µÄÒ£²â¸öÊýÉÏÏÞ
#define IEC_YX_NUM   64          //RMT_INFO_NUMÔÊÐí´«¸øÖ÷Õ¾µÄÒ£ÐÅ¸öÊýÉÏÏÞ
#define IEC_YK_NUM  OUT_TYPE_NUM  //ÔÊÐí´«¸øÖ÷Õ¾µÄÒ£¿Ø¸öÊýÉÏÏÞ
#define FRM_MAX_COS_NUM   70 //Ã¿Ö¡±¨ÎÄ×î¶à´«ÊäCOS¸öÊý£¬¹æ¶¨Îª70¸ö
#define IEC_ZJ_NUM   3  //ÔÊÐí´«¸øÖ÷Õ¾µÄ×Ô¼ì¸öÊýÉÏÏÞ
//Ë«µã
#define RI_ZD_DYX1  		512

//#define RMT_INFO_NUM           524         //×ÜÒ£ÐÅ¸öÊý
#define RMT_WORD_NUM           RMT_INFO_NUM/8+1          //×ÜÒ£ÐÅÕ¼ÓÃWORD¸öÊý Ã¿¸öÒ£ÐÅÕ¼2¸öbit£¬Ò»¸öWORD±£´æ8¸öÒ£ÐÅ
#define RMT_WDYX_NUM            2                        // 12 Ë«µãÒ£ÐÅÕ¼µÄ×Ö 12/8+1
#define RMT_WSYX_NUM            1          //RMT_INFO_NUM - 12 µ¥µãÒ£ÐÅ×Ö¸öÊý (RMT_INFO_NUM - 12)/8 +1

#define RMT_ZSQST_NUM          LINE_NUM * PHASE_NUM    //ÏßÂ·Í¨ÐÅ×´Ì¬¸öÊý  12*4
#define RI_ZSQST_H             RI_12O_ZSQST           //Ö¸Ê¾Æ÷×´Ì¬Ò£ÐÅÉÏÏÞ
#define DYX_ADDR               RI_ZD_DYX1             //Ë«µãÒ£ÐÅÆðÊ¼ºÅ
#define RI_FTINFO_NUM           LINE_NUM * PHASE_NUM * FTTPYE_NUM//ÐèÒª±ÕËøµÄÒ£ÐÅ¸öÊý ¶ÌÂ·(5*12)+½ÓµØ(5*12)+ÎÂ¶È(5*12)

//============================  AD²É¼¯  =============================================
#define AC_AD_CHAN_NUM                          6            //½»Á÷AD²ÉÑùÍ¨µÀÊý£¬ÈýÏàµçÁ÷**Ôö¼Ó1Â·ÁãÐòµçÑ¹  Ôö¼ÓÒ»Í¨µÀ¶Ô²àµçÑ¹UX
#define AC_SAMPLE_DOTS                          16      //Ã¿ÖÜ²¨²ÉÑùµÄµãÊýÎª32µã
#define AC_BUFF_LEN                             32             //½»Á÷²É¼¯»º³åÇø±£´æ2¸öÖÜ²¨£¬32¸öµã

#define AC_SAM_TAIL_OFFSET                      2               //½»Á÷²É¼¯·ÅÖÃÆ«ÒÆ  ÓÉÓÚÄ¿Ç°·¢ÏÖÓÐÎó±¨µÄÇé¿ö£¬°ÑÊý¾Ý²É¼¯ÏÂÀ´²»Á¢¿ÌËÍµ½CPU²É¼¯

//½»Á÷ADC²ÉÑùÍ¨µÀºÅ¶¨Òå
#define CHAN_UA                               0
#define CHAN_UB                               1
#define CHAN_UC                               2
#define CHAN_U0                               3
#define CHAN_I0                               4
#define CHAN_Upt                               5

//============================ ·ûºÏÀúÊ·¼ÇÂ¼  =============================================
#define FLOADINFONUM                    4           //
#define FLOAD_TOTALNUM                0            //¼ÇÂ¼×ÜÌõÊý
#define FLOAD_NEW                          1             //¼´½«´æ´¢µÄ¼ÇÂ¼ÓëµÚÒ»Ìõ¼ÇÂ¼µÄÆ«ÒÆÎ»ÖÃ(²»ÊÇÒÑ´æ´¢µÄ×îÐÂÒ»Ìõ¼ÇÂ¼µÄÎ»ÖÃ)
#define FLOAD_OLD                           2             //×îÀÏÒ»Ìõ¼ÇÂ¼µÄÎ»ÖÃ
#define FLOAD_CS                             3
#define FLASH_LOAD_MAXNUM        8192
#define FADDR_LOAD_START           0x750000//750000-790000
#define FLASH_PLOAD_LEN              32//Ã¿Ìõ¸ººÉ¼ÇÂ¼32×Ö½Ú

//============================  SMS-µç»°ºÅÂë        =======================================

#define PHONE_CHARNUM         16//15     //Ã¿¸öµç»°ºÅÂëÕ¼µÄ×Ö½ÚÊý/×Ö·ûÊý ×î´ó×Ö·ûÊý//ÕÅ| 0328 ( 1×Ö½Úµç»°ºÅÂë³¤¶È +15×Ö½Úµç»°)
//#define PHONE_NUM             4//3      //Ö§³ÖµÄµç»°ºÅÂë¸öÊý//ÕÅ| 0328 (N×î´óÎª8£¬Ä¿Ç°³ÌÐò¶¨ËÀÎª4¸ö)

#define PHONE_ENCTL           0 //µç»°ºÅÂëÊ¹ÄÜ¿ØÖÆ×Ö
#define PHONE1_CHARLEN        1 //ºÅÂë1³¤¶È
#define PHONE1                2
#define PHONE2_CHARLEN        PHONE1 + PHONE_CHARNUM
#define PHONE2                PHONE2_CHARLEN + 1
#define PHONE3_CHARLEN        PHONE2 + PHONE_CHARNUM
#define PHONE3                PHONE3_CHARLEN + 1

#define PHONE_CS              68////ÕÅ| 0328 ¹²68×Ö½Ú, 4¸öµç»°ºÅÂëPHONE3 + PHONE_CHARNUM         
#define PHONE_PA_NUM          69//PHONE_CS + 1  //ÕÅ| 0328 ¹²69×Ö½Ú, 4¸öµç»°ºÅÂë+4BYTE¿ØÖÆ×Ö+1BYTE CSÐ§Ñé

//N(N×î´óÎª8£¬Ä¿Ç°³ÌÐò¶¨ËÀÎª4¸ö)¸öµç»°ºÅÂë( 1×Ö½Úµç»°ºÅÂë³¤¶È +15×Ö½Úµç»°)£¬N×Ö½Ú¶ÌÐÅ·¢ËÍ¿ØÖÆ×Ö//ÕÅ| 0328 
//¹²136×Ö½Ú//ÕÅ| 0328
#define MAX_SMS_NUM 16
#define CnName_NUM   20//ÕÅ| ¶ÌÐÅÓÃºº×ÖÕ¾ÃûµØÖ·
#define LBName_NUM   20//ÕÅ| Â¼²¨ÎÄ¼þÓÃÓ¢ÎÄÕ¾ÃûµØÖ·
//============================  Â¼²¨Êý¾Ý        =======================================
#define  REC_AC_CHAN_NUM        5               //Â¼²¨½»Á÷µçÑ¹µçÁ÷µÄÍ¨µÀÊý£¬ÖÇÄÜÓÀ´ÅÇý¶¯Æ÷Ö÷ÒªÊÇÈýÏàµçÁ÷ºÍÁãÐòµçÁ÷

#define RECAC_UA                               0
#define RECAC_UB                               1
#define RECAC_UC                               2
#define RECAC_U0                               3
#define RECAC_I0                               4
#define REC_AC_BEF_LEN          128              //¶¯×öÖ®Ç°±£´æ3¸öÖÜ²¨µÄÊý¾Ý
#define REC_AC_LEN              640             //¶¯×÷ºó±£´æ5¸öÖÜ²¨µÄÊý¾Ý£¬¶¯×÷Ç°3¸öÖÜ²¨µÄÊý¾Ý£¬¹²8ÖÜ²¨   

#define         REC_DATA_LEN            10       //Ã¿ÌõÂ¼²¨Êý¾ÝµÄ³¤¶È

//Â¼²¨Êý¾ÝµÄ¶¨Òå 
#define         REC_MSL           0 
#define         REC_MSH           1
#define         REC_MINU          2 
#define         REC_HOUR          3
#define         REC_DAY           4
#define         REC_MONTH         5  
#define         REC_YEAR          6 
#define         REC_TYPE          7
#define         REC_TOTAL_LENL     8
#define         REC_TOTAL_LENH     9

//#define         FADDR_REC_START    0   //FlashµØÖ·
//============================  SST25 FLASHµØÖ··ÖÅä        =======================================
#define         FADDR_REC_START    20480   //Â¼²¨Êý¾ÝFlashµØÖ·ÆðÊ¼µØÖ·//ÕÅ| SOE´æFLASH
#define         REC_LEAF_NUM       16   //Ã¿ÌõÂ¼²¨Ò³Êý Õ¼16Ò³ 16*256
#define         MAX_REC_NUM       50 //Â¼²¨ÊýÎÄ¼þ×î¶à32¸ö  
#define         MAX_ACTREC_NUM       10 //Â¼²¨ÊýÎÄ¼þ×î¶à32¸ö  
#define         MAX_XHREC_NUM       10 //Â¼²¨ÊýÎÄ¼þ×î¶à32¸ö  
#define         MAX_ALLREC_NUM       73 //È«²¿Â¼²¨ÊýÎÄ¼þ×î¶à73¸öMAX_REC_NUM+1+MAX_ACTREC_NUM+1+MAX_XHREC_NUM+1 

#define         FADDR_SOE_START    0   //SOEÊý¾ÝFlashµØÖ·ÆðÊ¼µØÖ·//ÕÅ| SOE´æFLASH
#define         MAX_SOE_NUM       512   //SOE×î¶à´æ512Ìõ£¬Ã¿Ìõ11×Ö½Ú£¬Õ¼16×Ö½Ú//ÕÅ| SOE´æE2ROM
#define         MAX_SOE_BYTE       0x3000 //768*16   //SOE×î¶à´æ1024Ìõ£¬Ã¿Ìõ11×Ö½Ú£¬Õ¼16×Ö½Ú//ÕÅ| SOE´æFLASH

//#define         REC_LEAF_NUM      9//8       //Â¼²¨Êý¾ÝÕ¼ÓÃFLASHÒ³Êý ÓÉÓÚ¼ÓÁËÈý¸öÍ¨µÀUA,UBºÍUC£¬ËùÒÔ¶àÕ¼ÁËÒ»Ò³
//#define         REC_DISPLAY_NUM      512  //ÌáÈ¡¸øÏÔÊ¾µÄÂ¼²¨ÌõÊý
//±£´æÔÚEEPROMÖÐµÄ²ÎÊý¸üÐÂ±êÖ¾
#define PARA_NUM        7

#define CHNG_INFO       0       //ÔËÐÐÐÅÏ¢
#define CHNG_ADJ        1       //Ð£ÕýÐÅÏ¢
#define CHNG_PC         2       //±£»¤¶¨Öµ
#define CHNG_MUBIAO     3       //±£»¤¶¨Öµ×é×éºÅ
#define CHNG_TEL        4       //ÔËÐÐ²ÎÊý
#define CHNG_GPRS       5       //GPRS²ÎÊý
#define CHNG_CODE       6       //Òº¾§²Ù×÷ÃÜÂë

//=================    ÐÅÏ¢¶ÔÏóµØÖ·¶¨Òå£¬²Î¿¼101Ð­Òé£¬¼æ¹ËModbusÐ­Òé =============================
/*#define         EQU_BASE                                0x0001          //×´Ì¬Á¿ÐÅÏ¢ÆðÊ¼µØÖ·
#define         PC_BASE                                 0x1001          //±£»¤¶¨ÖµÆðÊ¼µØÖ·
#define         RI_BASE                                 0x2001          //Ò£ÐÅÁ¿ÐÅÏ¢ÆðÊ¼µØÖ·
#define         RM_BASE                                 0x4001          //Ò£²âÁ¿ÆðÊ¼µØÖ·
#define         ADJ_BASE                                0x5001          //Ð£Õý²ÎÊýÆðÊ¼µØÖ·
#define         RC_BASE                                 0x6000          //Ò£¿ØÆðÊ¼µØÖ·
#define         RP_BASE                                 0x7000          //ÔËÐÐ²ÎÊýÆðÊ¼µØÖ·
#define         RUN_BASE                                0x7200          //ÔËÐÐÐÅÏ¢ÆðÊ¼µØÖ·*/



//============================  Ò£²âÁ¿          =======================================
#define RMT_MEAS_NUM            10


#define RM_U0                   0
#define RM_UA                   1
#define RM_UB                   2
#define RM_UC                   3
#define RM_UAB                 4       //ÁãÐòµçÑ¹
#define RM_UBC                 5
#define RM_UCA                 6
#define RM_I0                   	7       //ÁãÐòµçÁ÷
#define RM_ACT_NUM    	8
#define RM_UPt                	9

#define RM_CSQ                	10
#define RM_UCAP               	11
#define RM_bk1               	12
#define RM_bk2                	13
#define RM_bk3                	14
#define RM_bk4                	15

#define RM_FILTER_NUM           10      //Ò£²âÁ¿µÄÂË²¨»º³åÇøÉî¶È
/*
#define RMT_INFO_NUM            14

#define YX_A_ACTION             BIT0
#define YX_B_ACTION             BIT1
#define YX_C_ACTION             BIT2
#define YX_EFS_OFF              BIT3

#define YX_EFS_ABNORMAL         BIT4
#define YX_EFS_LATCH            BIT5 
#define YX_EIGHT_PULSE          BIT6
#define YX_PHASEA_FAULT         BIT7 

#define YX_PHASEB_FAULT         BIT8 
#define YX_PHASEC_FAULT         BIT9
#define YX_EARTH_FAULT          BITA
#define YX_PHASEA_OFF           BITB 

#define YX_PHASEB_OFF           BITC 
#define YX_PHASEC_OFF           BITD 
*/
#define RMT_INFO_NUM            64//42

#define YX_FUN_ON               0  //¹¦ÄÜÍ¶ÍË
#define YX_MANUAL_ACTION        1  //ÊÖ¶¯Í¶ÇÐ
#define YX_ACTION_SUCCESS       2 //×îÖÕÍ¶ÇÐ³É¹¦
#define YX_EARTH_FAULT          3  //½ÓµØ¸æ¾¯
#define YX_PHASE_OFF            4  //PT¶ÏÏß¸æ¾¯

#define YX_EFS_OFF              5  //¿ØÖÆÆ÷Ê§µç
#define YX_U0_HIGH             6 //ÁãÐò¹ýÑ¹±¨¾¯
#define YX_UAB_HIGH             7 //ÏßµçÑ¹¹ýÑ¹±¨¾¯
#define YX_U_HIGH              8  //ÏàµçÑ¹¹ýÑ¹¸æ¾¯

#define YX_U_LOW               9 //ÏàµçÑ¹Ç·Ñ¹¸æ¾¯
#define YX_EFS_ABNORMAL         10//¿ØÖÆÆ÷Òì³£¸æ¾¯
#define YX_PHASEA_ACT           11 //AÏàÍ¶ÇÐ
#define YX_PHASEB_ACT           12  //BÏàÍ¶ÇÐ
#define YX_PHASEC_ACT           13 //CÏàÏàÍ¶ÇÐ
//#define YX_PHASEC_OFF           BITD  //×îÖÕÍ¶ÇÐ³É¹¦
#define YX_EFS_LATCH            14//±ÕËø 1=±ÕËø 0=½âËø
#define YX_UA_HIGH              15  //AÏàµçÑ¹¹ýÑ¹¸æ¾¯
#define YX_UA_LOW               16 //AÏàµçÑ¹Ç·Ñ¹¸æ¾¯
#define YX_UB_HIGH              17  //BÏàµçÑ¹¹ýÑ¹¸æ¾¯
#define YX_UB_LOW               18  //BÏàµçÑ¹Ç·Ñ¹¸æ¾¯
#define YX_UC_HIGH              19  //CÏàµçÑ¹¹ýÑ¹¸æ¾¯
#define YX_UC_LOW               20  //CÏàµçÑ¹Ç·Ñ¹¸æ¾¯
#define YX_PHASEA_OFF       21  //PT¶ÏÏß¸æ¾¯
#define YX_PHASEB_OFF       22  //PT¶ÏÏß¸æ¾¯
#define YX_PHASEC_OFF       23  //PT¶ÏÏß¸æ¾¯
#define YX_AEARTH_FAULT          24  //½ÓµØ¸æ¾¯
#define YX_BEARTH_FAULT          25 //½ÓµØ¸æ¾¯
#define YX_CEARTH_FAULT          26 //½ÓµØ¸æ¾¯
#define YX_KJC         31 //Ó²Ò£ÐÅ1
#define YX_KJA          32 //Ó²Ò£ÐÅ1
#define YX_KJB          33 //Ó²Ò£ÐÅ2
#define YX_RH_SUCCESS          34 //È¼»¡³É¹¦
#define YX_RH_FAIL         35 //È¼»¡Ê§°Ü
#define YX_BREAK            36 //¶ÏÏß
#define YX_LBOK              37 //Â¼²¨Íê³É
#define YX_SBP_OFF        38 //ºó±¸µçÔ´stand-by power 0£ººó±¸µçÔ´Õý³££¬1£ººó±¸µçÔ´Òì³£
#define YX_RH_ACT          39//×°ÖÃÏ¨»¡¶¯×÷	1£ºÏ¨»¡¿ª¹ØÍ¶Èë£¬0£ºÏ¨»¡¿ª¹ØÍ¶Èë½áÊø
#define YX_EFS_ACT        40//×°ÖÃÌØÕ÷ÐÅºÅÍ¶Èë	1£º´¦ÓÚÍ¶ÇÐ¹¤×÷×´Ì¬£»0£º×°ÖÃ¿ª¹ØÍ¶ÇÐ¹¤×÷×´Ì¬½áÊø
#define YX_I0_ACT           41//½ÓµØµçÁ÷·´À¡	   1£ºI0>0 £»0£ºI0=0
#define YX_PHASEA_ERR  42//AÏà¿ª¹ØÎ»ÖÃÒì³£	1£ºÒì³£×´Ì¬£»0£º
#define YX_PHASEB_ERR  43//BÏà¿ª¹ØÎ»ÖÃÒì³£	1£ºÒì³£×´Ì¬£»0£º
#define YX_PHASEC_ERR  44//CÏà¿ª¹ØÎ»ÖÃÒì³£	1£ºÒì³£×´Ì¬£»0£º
#define YX_I0_HIGH         45//I0¹ýÁ÷	1£º¹ýÁ÷×´Ì¬£»0£º
#define YX_KJ_TIMEOVER 46//¿ª¹Ø±ÕºÏ³¬Ê±	1£º³¬Ê±£»0£º
#define YX_I0_TIMEOVER 47//I0³¬Ê±	1£º³¬Ê±£»0£º
//#define YX_I0_HIGH         48//I0¹ýÁ÷	1£º¹ýÁ÷×´Ì¬£»0£º
//#define YX_I0_HIGH         49//I0¹ýÁ÷	1£º¹ýÁ÷×´Ì¬£»0£º

//µ±µçÁ÷Îª5AÊ±£¬±£Áô1¸öÐ¡Êýµã£¬¼´Êµ¼ÊÖµÎª50£¬Ôò»¥¸ÐÆ÷ºÍÔË·Åºó½øÈëADÎª0.8V£¬¶ÔÓ¦µÄ²ÉÑùÖµÎª993  1311
#define COEF_AD_I_0                       1562     //5.00/993*4096 =  2062
//#define COEF_AD_I_0                     1100       //5.00/1862*4096 = 
#define COEF_I_0_AD2                    39110    //ÁãÐòµçÁ÷µÄ·´µÄÏµÊýµÄÆ½·½,ÓÉ²½³¤Îª0.01AµÄÊµ¼ÊÖµ»»Ëã³É²ÉÑùÖµµÄÏµÊýµÄÆ½·½ ¶¨±êQ10£¬ÐèÒªÔÚ³ÌÐòÖÐÍùÓÒÒÆÎ»10 1.986*1.986*1024*10000/225

//µçÈÝÆ÷µçÑ¹»»ËãÏµÊý¼ÆËã

#define COEF_AD_U                        33328  //µçÑ¹ÏµÊý44000   100.0V/931*4096    100.0V»¥¸ÐÆ÷ºÍÔË·Åºó½øÈëADÎª0.750V£¬¶ÔÓ¦µÄ²ÉÑùÖµÎª931 1229
#define COEF_U_AD2                      677    //2741=1.157*1.157*2048  0.5748*0.5748*2048= 677

//============================  ±£»¤µçÁ¿        =======================================
#define PROC_MEAS_NUM           8


#define PM_U0                   0
#define PM_UA                   1
#define PM_UB                   2
#define PM_UC                   3
#define PM_UAB                  4       //ÁãÐòµçÑ¹
#define PM_UBC                  5
#define PM_UCA                  6
#define PM_I0                   7       //ÁãÐòµçÁ÷



//============================  Ð£Õý²ÎÊý        =======================================
#define ADJ_PARA_NUM                            7//13   //Ð£Õý²ÎÊý°üÀ¨Ã¿¸öÍ¨µÀµÄ»ù×¼Ô´Ð£ÕýºÍÄ¿±êÖµÐ£Õý£¬½«À´ÓÐ¹¦ÂÊ¼ÆËãµÄ»°»¹ÓÐÏàÎ»Ð£Õý



#define ADJ_REF_CHNUA                         0       //Í¨µÀ5»ù×¼Ô´Ð£ÕýÖµ 
#define ADJ_REF_CHNUB                         1       //Í¨µÀ6»ù×¼Ô´Ð£ÕýÖµ  
#define ADJ_REF_CHNUC                         2       //Í¨µÀ7»ù×¼Ô´Ð£ÕýÖµ  
#define ADJ_REF_CHNU0                         3       //Í¨µÀ4»ù×¼Ô´Ð£ÕýÖµ  
#define ADJ_REF_CHNI0                         4       //Í¨µÀ4»ù×¼Ô´Ð£ÕýÖµ  
#define ADJ_REF_CHNUPt                       5       //Í¨µÀ4»ù×¼Ô´Ð£ÕýÖµ  
#define ADJ_REF_UAX1                       6       //Í¨µÀ4»ù×¼Ô´Ð£ÕýÖµ  
#define ADJ_REF_UAX2                       7       //Í¨µÀ4»ù×¼Ô´Ð£ÕýÖµ  
#define ADJ_REF_UAY1                       8       //Í¨µÀ4»ù×¼Ô´Ð£ÕýÖµ  
#define ADJ_REF_UAY2                       9       //Í¨µÀ4»ù×¼Ô´Ð£ÕýÖµ  
#define ADJ_REF_UA_A                       10       //Í¨µÀ4»ù×¼Ô´Ð£ÕýÖµ  
#define ADJ_REF_UA_B                       11     //Í¨µÀ4»ù×¼Ô´Ð£ÕýÖµ  
#define ADJ_REF_UBX1                      12       //Í¨µÀ4»ù×¼Ô´Ð£ÕýÖµ  
#define ADJ_REF_UBX2                       13       //Í¨µÀ4»ù×¼Ô´Ð£ÕýÖµ  
#define ADJ_REF_UBY1                       14     //Í¨µÀ4»ù×¼Ô´Ð£ÕýÖµ  
#define ADJ_REF_UBY2                       15     //Í¨µÀ4»ù×¼Ô´Ð£ÕýÖµ  
#define ADJ_REF_UB_A                       16     //Í¨µÀ4»ù×¼Ô´Ð£ÕýÖµ  
#define ADJ_REF_UB_B                       17     //Í¨µÀ4»ù×¼Ô´Ð£ÕýÖµ  
#define ADJ_REF_UCX1                       18     //Í¨µÀ4»ù×¼Ô´Ð£ÕýÖµ  
#define ADJ_REF_UCX2                       19   //Í¨µÀ4»ù×¼Ô´Ð£ÕýÖµ  
#define ADJ_REF_UCY1                       20     //Í¨µÀ4»ù×¼Ô´Ð£ÕýÖµ  
#define ADJ_REF_UCY2                       21     //Í¨µÀ4»ù×¼Ô´Ð£ÕýÖµ  
#define ADJ_REF_UC_A                       22     //Í¨µÀ4»ù×¼Ô´Ð£ÕýÖµ  
#define ADJ_REF_UC_B                       23     //Í¨µÀ4»ù×¼Ô´Ð£ÕýÖµ  

#define ADJ_CRC                               6

//============================  ÔËÐÐ²ÎÊý        =======================================

#define RP_CFG_KEY               0      //ÅäÖÃ¿ØÖÆ×Ö1

#define RP_BEAT_T                1    //¶¨Ê±ÉÏ´«ÐÄÌø ²½³¤1S
#define RP_SENDYC_T              2    //¶¨Ê±ÉÏ´«Ò£²âÊ±¼ä¼ä¸ô
#define RP_SENDYX_T               3   //¶¨Ê±ÉÏ´«Ò£ÐÅÊ±¼ä¼ä¸ô
//#define RP_STATUSRP_INTERVAL     4   //×´Ì¬»ã±¨¼ä¸ô
#define RP_FLOAD_T 			 4   //¸ººÉ¼ÇÂ¼´æ´¢Ê±¼ä¼ä¸ô
#define RP_COMM_ADDR        	 5   //×ÓÕ¾Õ¾µØÖ· 
#define RP_SYX_INFADDR    	 6    //µ¥µãÒ£ÐÅÆðÊ¼ÐÅÏ¢ÌåµØÖ·
#define RP_DYX_INFADDR     	7    //Ë«µãÒ£ÐÅÆðÊ¼ÐÅÏ¢Ìå?
#define RP_YCLIMIT              	 8   //Ò£²â¾ø¶ÔÔ½ÏÞÖµ
#define RP_YCCAP                	 9   //Ò£²âÏà¶ÔÔ½ÏÞÖµ Ïà¶ÔÖ¸°Ù·Ö±È
#define RP_PLUSE_MODFK	   	10  //Âö³å¿í¶ÈÐÞÕý£¬Êµ¼ÊÂö³å¿í¶ÈÎª10msÎª RP_PLUSE_TIME -RP_PLUSE_MODFK µ¥Î»10ms Ä¬ÈÏ0
#define RP_PLUSEXH_MODFK	11  //Âö³å¿í¶ÈÐÞÕý£¬Êµ¼ÊÂö³å¿í¶ÈÎª10msÎª RP_PLUSE_TIME -RP_PLUSE_MODFK µ¥Î»10ms 
//#define RP_DEVICE_TYPE		11     //Éè±¸ÀàÐÍ 0 = Ò»Ò££» 1 = ¶þÒ£ £»2=ÐÅºÅÔ´
#define RP_YXRSD_T               12   //Ò£ÐÅÖØ·¢¼ä¸ô²½³¤
#define YX_delay                 13   //·À¶¶Ê±¼ä¼ä¸ô

#define RP_UA_ADJ           14       //UAÐ£×¼ÏµÊýÖµ
#define RP_UB_ADJ           15       //UBÐ£×¼ÏµÊýÖµ
#define RP_UC_ADJ           16               //UCÐ£×¼ÏµÊýÖµ
#define RP_U0_ADJ           17               //U0Ð£×¼ÏµÊýÖµ
#define RP_I0_ADJ           18               //I0Ð£×¼ÏµÊýÖµ
#define RP_I0_START         19              //ÏßµçÑ¹¹ýÑ¹¸æ¾¯¶¨Öµ //ÁãÐòµçÁ÷ÃÅ¼÷Öµ
#define RP_HIGH_P           20               //ÏàµçÑ¹¸ß¶¨Öµ
#define RP_LOW_P            21               //ÏàµçÑ¹µÍ¶¨Öµ
#define RP_HIGH_Z           22         //ÁãÐòµçÑ¹¸ß¶¨Öµ
#define RP_LOW_Z            23          //ÁãÐòµçÑ¹µÍ¶¨Öµ
#define RP_NO_V            24      //ÎÞÑ¹ÃÅ¼÷Öµ
#define RP_T_DELAY         25              //¹ÊÕÏÑÓÊ±Ê±¼ä
#define RP_JAG_P           26      //ÏàÅÐ¾Ý±êÖ¾
#define RP_JAG_Z           27      //ÁãÐòÅÐ¾Ý±êÖ¾
#define RP_EFS_MODEL       28      //ÐÅºÅÔ´ÐÍºÅ±êÊ¶
#define RP_JAG_ACT         29      //¶¯×÷ÏàÐòÅÐ¾Ý
#define RP_PULSE_VALID     30      //8Âö³åÓÐÐ§¶¨Öµ
#define RP_GPRS_MODEL      31      //GPRS·½Ê½¶¨Öµ
#define RP_REV_CURRENT     32      //·­×ªµçÁ÷¶¨Öµ
#define RP_U0_CAL          33      //U0²úÉú·½Ê½
/*
#define RP_ETH_MODEL            20      //ÒÔÌ«Íø·½Ê½ 0£ºSERVER   1£ºCLIENT
#define	RP_G_IP_1               21		//Íø¹ØIP1~4
#define	RP_G_IP_2		22
#define	RP_G_IP_3		23
#define	RP_G_IP_4		24
#define	RP_SUB_MASK_1		25       //×ÓÍøÑÚÂë1~4
#define	RP_SUB_MASK_2		26
#define	RP_SUB_MASK_3		27
#define	RP_SUB_MASK_4		28
#define	RP_MAC_ADDR_1		29       //W5500 MACµØÖ·1~6
#define	RP_MAC_ADDR_2		30
#define	RP_MAC_ADDR_3		31
#define	RP_MAC_ADDR_4		32
#define	RP_MAC_ADDR_5		33
#define	RP_MAC_ADDR_6		34
#define	RP_W_IP_1		35        //W5500IP1~4
#define	RP_W_IP_2		36
#define	RP_W_IP_3		37
#define	RP_W_IP_4		38
#define	RP_D_IP_1		39        //W5500IP1~4
#define	RP_D_IP_2		40
#define	RP_D_IP_3		41
#define	RP_D_IP_4		42
#define	RP_S0_PORT		43        //Socket0 ¶Ë¿ÚºÅ 
*/
#define RP_CNL_MODEL	        34		//½ÓµØ¹¦ÄÜÍ¶ÍË
#define RP_LACTH_TIME           35//ÐÅºÅÔ´±ÕËøÊ±¼ä£¬ÒÔ·ÖÖÓÎªµ¥Î»£¬Ä¬ÈÏ18·ÖÖÓ
#define RP_PLUSE_TIME           36//Âö³å¿í¶È£¬10msÎªµ¥Î» Ä¬ÈÏ25
#define RP_SEND_TIME1           37//Âö³å·¢ËÍ¼ä¸ôÊ±¼ä1 £¬10msÎªµ¥Î» Ä¬ÈÏ100
#define RP_SEND_TIME2           38//Âö³å·¢ËÍ¼ä¸ôÊ±¼ä2 £¬10msÎªµ¥Î» Ä¬ÈÏ125

#define RP_OVERLOAD_CNT       39//Âö³å¿í¶ÈÐÞÕý£¬Êµ¼ÊÂö³å¿í¶ÈÎª10msÎª RP_PLUSE_TIME -RP_PLUSE_MODFK µ¥Î»10ms Ä¬ÈÏ0
#define RP_OVERLOAD_I            40
#define RP_OVERLOAD_T           41
#define RP_SENDSMS_T             42//ÕÅ| Ò£²âÆðÊ¼µØÖ·ÐÞ¸ÄÔËÐÐ²ÎÊý
#define RP_YC_INFADDR            43//ÕÅ| Ò£²âÆðÊ¼µØÖ·ÐÞ¸ÄÔËÐÐ²ÎÊý
#define RP_SENDZJ_T                    44      //¶¨Ê±ÉÏ´«×Ô¼ìÊ±¼ä¼ä¸ô
#define RP_RHSEND_TIME1           45//È¼»¡Âö³å·¢ËÍ¼ä¸ôÊ±¼ä1 £¬10msÎªµ¥Î» Ä¬ÈÏ500
#define RP_RHPLUSE_TIME2           46//È¼»¡Âö³å¿í¶È£¬10msÎªµ¥Î» Ä¬ÈÏ20
#define RP_RHT_DELAY           47//È¼»¡Ò£ÐÅÑÓÊ±Ê±¼ä
#define RP_CT_TRANS           48//ct±ä±È
#define RP_KM_TIME           49//½Ó´¥Æ÷¿ª¹Ø±ÕºÏ³¬Ê±Ê±¼ä£¬10msÎªµ¥Î» Ä¬ÈÏ100
#define RP_PLUSE_AMODFK	   	50  //Âö³å¿í¶ÈÐÞÕý£¬Êµ¼ÊÂö³å¿í¶ÈÎª10msÎª RP_PLUSE_TIME -RP_PLUSE_MODFK µ¥Î»10ms Ä¬ÈÏ0
#define RP_PLUSE_BMODFK	   	51  //Âö³å¿í¶ÈÐÞÕý£¬Êµ¼ÊÂö³å¿í¶ÈÎª10msÎª RP_PLUSE_TIME -RP_PLUSE_MODFK µ¥Î»10ms Ä¬ÈÏ0
#define RP_PLUSE_CMODFK	   	52  //Âö³å¿í¶ÈÐÞÕý£¬Êµ¼ÊÂö³å¿í¶ÈÎª10msÎª RP_PLUSE_TIME -RP_PLUSE_MODFK µ¥Î»10ms Ä¬ÈÏ0

#define RP_CRC                   53      //crcÐ£ÑéÂë//ÕÅ| Ò£²âÆðÊ¼µØÖ·ÐÞ¸ÄÔËÐÐ²ÎÊý
#define RUN_PARA_NUM             54//ÕÅ| Ò£²âÆðÊ¼µØÖ·ÐÞ¸ÄÔËÐÐ²ÎÊý

//¿ØÖÆ×Ö¾ßÌå¶¨Òå
#define RPCFG_CON_NC              0      //½Ó´¥Æ÷Î»ÖÃ0=³£¿ªno 1=³£±Õnc
//AD²É¼¯Á¢¼´ÉÏ´«È«Ò£²â
#define RPCFG_SENDLUBOML         1 //ÔÆÄÏ ÊÇ·ñÖ÷¶¯ÉÏ´«Â¼²¥Ä¿Â¼
#define RPCFG_SEND_FTYC             2      //³õÊ¼»¯¹ý³Ì·¢ËÍÁ´½Ó 1=²»·¢ËÍ0=·¢ËÍ
#define RPCFG_SEND_CHANGEYC         3     //ÊÇ·ñ·¢ËÍÒ£²âÔ½ÏÞÖµ 0=²»´« 1=ÉÏ´«
#define RPCFG_YC_FLOAT             4      //Ò£²âÖµÎª¸¡µãÊý 0=ÕûÊý 1=¸¡µãÊý(ÀàÐÍ±êÊ¾)
#define RPCFG_AUTOLINK    5     //ÊÇ·ñ1=ÉÏµçºóGPRS×Ô¶¯Á¬½Ó101
#define RPCFG_DEL_LUBO              6      //ÊÇ·ñÉ¾³ýÂ¼²¨Êý¾Ý 
#define RPCFG_ISSENDINITFIN         7     //0=²»·¢ËÍ³õÊ¼»¯³¤Ö¡£¬1=·¢ËÍ Ä¬ÈÏ·¢ËÍ
#define RP_COMTRADE_TYPE             8     //0=Â¼²¨Êý¾ÝÎªASCII,1=Â¼²¨Êý¾Ý¶þ½øÖÆ£¬
#define RPCFG_PT_LATCH                        9     // 1=ÆôÓÃPT¶ÏÏß±ÕËø£¬
#define RPCFG_I0_LATCH                        10     // 1=ÆôÓÃI0¹ýÁ÷±ÕËø
#define RPCFG_CON_LATCH                     11     // 1=ÆôÓÃ¿ª¹Ø±ÕºÏ³¬Ê±±ÕËø?#define RPCFG_SEND_RHPLUSE         12     //0=²»Æô¶¯È¼»¡Âö³å£¬1=·¢ËÍÈ¼»¡Âö³å 
#define RPCFG_BREAK_STOP8PUL     13     //0=¶ÏÏßºó²»Í£Ö¹8Âö³å£¬1=¶ÏÏßºóÍ£Ö¹8Âö³å 
#define RPCFG_CURRENT_PRIMARY   14     //0=µçÁ÷Îª2´ÎÖµ£¬1=µçÁ÷Îª1´ÎÖµ£¬2´ÎÖµ*CT±ä±È

//================================  ¶¨Ê±Æ÷±äÁ¿  ==========================

#define TIMER_NUM            19  //¶¨Ê±Æ÷¸öÊý 1sÎªµ¥Î»
#define TM_BEAT               0     //¶¨Ê±ÉÏ´«ÐÄÌø GPRSÍ¨ÐÅÐÄÌøÊ±¼ä ²½³¤1S
#define TM_ADCOLT             1   //AD²É¼¯Ê±¼ä¼ä¸ô ´ËÊ±ÖÃAD²É¼¯Î»£¬1sºóÊ¹ÄÜAD²É¼¯
#define TM_SENDYC             2   //¶¨Ê±ÉÏ´«Ò£²âÊ±¼ä¼ä¸ô
#define TM_CLOSECHARGE        3   //¹Ø±Õ³äµçÊ±¼ä
#define TM_GPRSPWOERDOWN      4   //GPRSµôµçÊ±¼ä£¬ÓÃÓÚ×¼ÊµÊ±ÔÚÏßÄ£Ê½
#define TM_SAVELOAD           5   //±£´æ¸ººÉµçÁ÷
#define TM_ODU_call2          6   //ÕÙ»½ODUµÄ¶þ¼¶Êý¾Ý
#define TM_ODU_call           7   //ÕÙ»½ODUÊý¾Ý
#define TM_BATPWOERDOWN       8   //ï®µç³Ø¹Ø¶ÏÊ±¼ä
#define TM_SMSSENDALLOW       9  //¶ÌÐÅ·¢ËÍÑÓ³Ù
#define TM_WAITXINHAO         10  //¶ÌÐÅ·¢ËÍÖÁÐÅºÅÔ´µÄµÈ´ýÊ±¼ä
#define TM_ADBAT              11  //ï®µç³Ø²ÉÑùÊ±¼ä?#define TM_ADBATTEN      11  //ï®µç³ØµÄÊ¹ÄÜA£Ä²ÉÑù
#define TM_Volt               12  //µçÑ¹²»ÎÈÊ±£¬¼ì²âµçÔ´Ä£Ê½µÄÊ±¼ä¼ä¸ô
#define TM_SENDSTATUSDELAY    13  //×´Ì¬»ã±¨ÑÓÊ±
#define TM_SENDADDR           14  //×ÓÕ¾µØÖ··¢ËÍÑÓÊ±
#define TM_SENDFAULTDELAY     15  //¹ÊÕÏÖ÷¶¯·¢ËÍÑÓ³Ù ÓÃÓÚÎÞÏÞÖÆÄ£Ê½
#define TM_SENDSTATE          16  // ·¢ËÍODUµÄ×´Ì¬»ã±¨ÖÜÆÚ
#define TM_SNTP_TIME          17  //¶¨Ê±SNTP¶ÔÊ±¼ä¸ô
#define TM_GPRS_RW            18  //GPRS¶ÁÐ´³¬Ê±
                                    

//============================  Ð£×¼ÏµÊý¼°²ÎÊý       =======================================
#define PROC_CNT_NUM            28

#define PC_UA_ADJ           0       //UAÐ£×¼ÏµÊýÖµ
#define PC_UB_ADJ           1       //UBÐ£×¼ÏµÊýÖµ
#define PC_UC_ADJ           2               //UCÐ£×¼ÏµÊýÖµ
#define PC_U0_ADJ           3               //U0Ð£×¼ÏµÊýÖµ
#define PC_I0_ADJ           4               //I0Ð£×¼ÏµÊýÖµ
#define PC_I0_START         5               //ÏßµçÑ¹¸ß¶¨Öµ//ÁãÐòµçÁ÷ÃÅ¼÷Öµ
#define PC_HIGH_P           6               //ÏàµçÑ¹¸ß¶¨Öµ
#define PC_LOW_P            7               //ÏàµçÑ¹µÍ¶¨Öµ
#define PC_HIGH_Z           8         //ÁãÐòµçÑ¹¸ß¶¨Öµ
#define PC_LOW_Z            9          //ÁãÐòµçÑ¹µÍ¶¨Öµ
#define PC_NO_V            10      //ÎÞÑ¹ÃÅ¼÷Öµ
#define PC_T_DELAY         11              //¹ÊÕÏÑÓÊ±Ê±¼ä
#define PC_JAG_P           12      //ÏàÅÐ¾Ý±êÖ¾
#define PC_JAG_Z           13      //ÁãÐòÅÐ¾Ý±êÖ¾
#define PC_EFS_MODEL       14      //ÐÅºÅÔ´ÐÍºÅ±êÊ¶
#define PC_JAG_ACT         15      //¶¯×÷ÏàÐòÅÐ¾Ý
#define PC_PULSE_VALID     16      //8Âö³åÓÐÐ§¶¨Öµ
#define PC_GPRS_MODEL      17      //GPRS·½Ê½¶¨Öµ
#define PC_REV_CURRENT     18      //·­×ªµçÁ÷¶¨Öµ
#define PC_U0_CAL          19      //U0²úÉú·½Ê½

#define PC_CNL_MODEL	        20		//¿ØÖÆ·½Ê½
#define PC_LACTH_TIME           21//ÐÅºÅÔ´±ÕËøÊ±¼ä£¬ÒÔ·ÖÖÓÎªµ¥Î»£¬Ä¬ÈÏ18·ÖÖÓ
#define PC_PLUSE_TIME           22//Âö³å¿í¶È£¬10msÎªµ¥Î» Ä¬ÈÏ25 
#define PC_SEND_TIME1           23//Âö³å·¢ËÍ¼ä¸ôÊ±¼ä1 £¬10msÎªµ¥Î» Ä¬ÈÏ100
#define PC_SEND_TIME2           24//Âö³å·¢ËÍ¼ä¸ôÊ±¼ä2 £¬10msÎªµ¥Î» Ä¬ÈÏ125

#define PC_OVERLOAD_CNT         25
#define PC_OVERLOAD_I           26
#define PC_OVERLOAD_T           27

/*
#define RP_ETH_MODEL            20      //ÒÔÌ«Íø·½Ê½ 0£ºSERVER   1£ºCLIENT
#define	RP_G_IP_1               21		//Íø¹ØIP1~4
#define	RP_G_IP_2		22
#define	RP_G_IP_3		23
#define	RP_G_IP_4		24
#define	RP_SUB_MASK_1		25       //×ÓÍøÑÚÂë1~4
#define	RP_SUB_MASK_2		26
#define	RP_SUB_MASK_3		27
#define	RP_SUB_MASK_4		28
#define	RP_MAC_ADDR_1		29       //W5500 MACµØÖ·1~6
#define	RP_MAC_ADDR_2		30
#define	RP_MAC_ADDR_3		31
#define	RP_MAC_ADDR_4		32
#define	RP_MAC_ADDR_5		33
#define	RP_MAC_ADDR_6		34
#define	RP_W_IP_1		35        //W5500IP1~4
#define	RP_W_IP_2		36
#define	RP_W_IP_3		37
#define	RP_W_IP_4		38
#define	RP_D_IP_1		39        //W5500IP1~4
#define	RP_D_IP_2		40
#define	RP_D_IP_3		41
#define	RP_D_IP_4		42
#define	RP_S0_PORT		43        //Socket0 ¶Ë¿ÚºÅ 
*/


//#define RUN_INFO_NUM            22        //°üÀ¨Õ¾Ãû³ÆÓëÕ¾µØÖ·¹²21¸ö×Ö
#define RUN_INFO_NUM            20        //°üÀ¨Õ¾Ãû³ÆÓëÕ¾µØÖ·¹²20¸ö×Ö
#define INF_CRC                 20
//============================  ¿ª¹ØÁ¿ÊäÈë  ==================================
#define DIN_NUM                 3     //×Ü¹²µÄ¿ª¹ØÁ¿ÊäÈë¸öÊý

#define DIN_CON_TIME           160     //Ò£ÐÅÈ·ÈÏÊ±¼ä£¬ÔÝ¶¨200ms 
//============================  ÊµÊ±Ê±ÖÓ        ==================================
#define RTC_NUM                         7

#define RTC_YEAR                        0       //Äê
#define RTC_MONTH                       1       //ÔÂ
#define RTC_DATE                        2       //ÈÕ
#define RTC_HOUR                        3       //Ê±
#define RTC_MINUT                       4       //·Ö
#define RTC_SEC                         5       //Ãë
#define RTC_MICROSEC                    6       //ºÁÃë

//=============================   Ò£¿ØÎïÀí³ö¿ÚÀàÐÍ =========================

#define TYPE_RMTDO_NUM		5      //Í¨ÐÅµã±íµÄÅäÖÃ

#define RMTDO_MONI_A			0   //Ä£ÄâAÏà¹ÊÕÏ
#define RMTDO_MONI_B		        1   //Ä£ÄâBÏà¹ÊÕÏ
#define RMTDO_MONI_C			2   //Ä£ÄâCÏà¹ÊÕÏ
     
#define RMTDO_CLEAR_SOE			3    //Çå³ýSOE¼ÇÂ¼

#define RMTDO_RESET			4    //Ô¶¶¯¸´Î»

//============================  ¶ÏÏßÊ±¼ä¼ÇÂ¼ ===========================================
#define         BK_EEP_NUM              25      //ÔÚEEPROMÖÐ±£´æµÄÊýÁ¿ 25Ìõ
#define         BK_DATA_LEN_BYTE        9      //Ã¿ÌõSOEÊý¾ÝËùÕ¼µÄ×Ö½ÚÊý
//============================  µôµçÊ±¼ä¼ÇÂ¼ ===========================================
#define         OFF_EEP_NUM              30      //ÔÚEEPROMÖÐ±£´æµÄÊýÁ¿ 30Ìõ
#define         OFF_DATA_LEN_BYTE        7      //Ã¿ÌõSOEÊý¾ÝËùÕ¼µÄ×Ö½ÚÊý
//============================  ×´Ì¬Òì³£Ê±¼ä¼ÇÂ¼ ===========================================
#define         ABN_EEP_NUM              30      //ÔÚEEPROMÖÐ±£´æµÄÊýÁ¿ 30Ìõ
#define         ABN_DATA_LEN_BYTE        7      //Ã¿ÌõSOEÊý¾ÝËùÕ¼µÄ×Ö½ÚÊý
//============================  ¹ÊÕÏ¼ÇÂ¼ ===========================================
#define         SOE_EEP_NUM              30      //ÔÚEEPROMÖÐ±£´æµÄÊýÁ¿ 30Ìõ
#define         SOE_DATA_LEN_BYTE        12     //Ã¿ÌõSOEÊý¾ÝËùÕ¼µÄ×Ö½ÚÊý
//============================  Â¼²¨Êý¾Ý¼ÇÂ¼ ===========================================
#define         WAVE_EEP_NUM              30      //ÔÚEEPROMÖÐ±£´æµÄÊýÁ¿ 30Ìõ
#define         WAVE_DATA_LEN_BYTE        1     //Ã¿ÌõSOEÊý¾ÝËùÕ¼µÄ×Ö½ÚÊý

//SOEÊý¾ÝµÄ¶¨Òå

//===============================  COMMÄ£¿é  =============================
#define COMM_PORT_NUM           3//ÎïÀíÍ¨ÐÅ¶Ë¿Ú¸öÊý


#define COMM_INDEX_000          0
#define COMM_INDEX_232          1
#define COMM_INDEX_GPRS         2



//#define MAX_TXBUFF_LEN       128//ÎÞÂÛÊ¹ÓÃÄÄÒ»ÖÖÐ­Òé£¬×îºó·¢ËÍÊ±Ê¹ÓÃµÄ»º³åÇøÏàÍ¬£¬Òò´Ë»º³åÇø³¤¶ÈÈ¡×î´óÖµ¡£
#define MAX_RXBUFF_LEN       256//ÎÞÂÛÊ¹ÓÃÄÄÒ»ÖÖÐ­Òé£¬×îºó·¢ËÍÊ±Ê¹ÓÃµÄ»º³åÇøÏàÍ¬£¬Òò´Ë»º³åÇø³¤¶ÈÈ¡×î´óÖµ¡£

#define MAX_TXBUFF_101_LEN       256//101Ð­Òé·¢ËÍ»º³åÇø³¤¶È
#define MAX_SOE_TXNUM            8//16//µ¥´ÎÉÏËÍSOEÌõÊý

//============================  SOE¼ÇÂ¼ ===========================================
#define         SOE_BUFF_NUM            32      //SOEÄÚ´æ»º³åÇøÖÐSOEµÄÌõÊý

#define         SOE_DATA_LEN            11       //Ã¿ÌõSOEÊý¾ÝµÄ³¤¶È
#define         SOEVALID               0X55
#define         SOE_SENDDA_LEN         10//SOE_DATA_LEN-1
//SOEÊý¾ÝµÄ¶¨Òå
#define         SOE_FLAG    0  
#define         SOE_TYPEL   1 
#define         SOE_TYPEH   2 
#define         SOE_STVAL   3 
#define         SOE_MSL     4 
#define         SOE_MSH     5
#define         SOE_MINU    6 
#define         SOE_HOUR     7
#define         SOE_DAY     8
#define         SOE_MONTH   9  
#define         SOE_YEAR    10 
/*#define         SOE_UA      11
#define         SOE_UB      12
#define         SOE_UC      13
#define         SOE_U0      14*/

//============================  ÄÚ²¿flash´æ´¢  ===============================

#define SOE_RECORD_ADD   0x42000     //SOE¼ÇÂ¼µØÖ·Çø

#define SOE_NUM_SEG   42
#define SOE_SEG       24 

#define SOE_RECORD_LEN  0x10        //Ã¿Ìõ¼ÇÂ¼16×Ö½Ú
#define SOE_RECORD_NUM  32          //32Ìõ¼ÇÂ¼

//====================  EEPROM µØÖ··ÖÅä  CAT25C128 (0~0x3FFF ×Ö½Ú) 16K×Ö½Ú ======================
//ÓÉÓÚCAT25128µÄÒ³Îª64×Ö½Ú£¬Ôò·ÖÅä¿Õ¼äµÄÆðÊ¼µØÖ·×îºÃÎªÒ³ÆðÊ¼
//EEPROMÖÐ±£´æÅäÖÃÇøµÄ²ÎÊý      ·ÖÅä1K×Ö½ÚµÄ¿Õ¼ä
#define EEPADD_BIAS_V               0x0000    //Æ«ÖÃµçÑ¹ÏµÊýµÈ10×Ö½Ú   Õ¼16×Ö½Ú
#define EEPADD_COM                  0x0010    //Õ¾Ãû³Æ¡¢Õ¾µØÖ·µÈ42×Ö½Ú Õ¼48×Ö½Ú
#define EEPADD_PHONE_NUM            0x0040    //4¸öÊÖ»úºÅÂë£¨Ã¿¸ö13Î»£©¼°ÊÖ»ú¶ÌÐÅÊôÐÔ57×Ö½Ú  Õ¼64×Ö½Ú
#define EEPADD_PHONE                0x0040	//ÕÅ| 0328 ÎªºÍÁÖÑ©ÇÙ³ÌÐò¼æÈÝ£¬==EEPADD_PHONE_NUM 
//N(N×î´óÎª8£¬Ä¿Ç°³ÌÐò¶¨ËÀÎª4¸ö)¸öµç»°ºÅÂë( 1×Ö½Úµç»°ºÅÂë³¤¶È +15×Ö½Úµç»°)£¬N×Ö½Ú¶ÌÐÅ·¢ËÍ¿ØÖÆ×Ö//ÕÅ| 0328 
//¹²136×Ö½Ú//ÕÅ| 0328 
#define EEPADD_SOE_E2ROMADR            0x0100//0x0080//ÕÅ| Í·4×Ö½Ú£¬Î²4×Ö½Ú ³¤¶È2×Ö½Ú
#define EEPADD_SOESEND_E2ROMADR   0x0110
#define EEPADD_CNNAME 			 0x0140//ÕÅ| ºº×ÖÕ¾Ãû42×Ö½Ú
#define EEPADD_ADJOBJ                   0x0180//ÕÅ| Ä¿±êÐ£×¼£¬ÉÏÎ»»úÏÂÔØ²ÎÊý10×Ö½Ú ³õÊ¼ÖµÎªµçÑ¹60V,µçÁ÷2A
#define EEPADD_VER_CPU                0x01a0          //³ÌÐò°æ±¾ºÅ 2×Ö½Ú
//EEPROMÖÐIEC²ÎÊý±£´æ
#define EEPADD_IECYXADDR        0x01b0 //Ò£ÐÅµØÖ·  32×Ö½Ú
#define EEPADD_IECPARA             0x0200 //IEC²ÎÊý   32byte
#define EEPADD_IECYCADDR        0x0240 //Ò£²â²ÎÊý  100byte 
#define EEPADD_IECYKADDR        0x0280 //Ò£¿Ø²ÎÊý  100byte
#define EEPADD_RP                      0x02c0
#define EEPADD_LBNAME             0x03c0
#define EEPADD_LBNAMELEN       0x03e0
//EEPROMÖÐ²ÎÊýµÄ±¸·ÝÇø  ·ÖÅä1K×Ö½ÚµÄ¿Õ¼ä
#define EEPADDBK_BIAS_V               0x0400    //Æ«ÖÃµçÑ¹ÏµÊýµÈ10×Ö½Ú   Õ¼16×Ö½Ú
#define EEPADDBK_COM                    0x0410    //Õ¾Ãû³Æ¡¢Õ¾µØÖ·µÈ42×Ö½Ú Õ¼48×Ö½Ú
#define EEPADDBK_PHONE_NUM       0x0440    //4¸öÊÖ»úºÅÂë£¨Ã¿¸ö13Î»£©¼°ÊÖ»ú¶ÌÐÅÊôÐÔ57×Ö½Ú  Õ¼64×Ö½Ú
#define EEPADDBK_PHONE                0x0440
#define EEPADDBK_SOE_E2ROMADR         0x0500//0x0080//ÕÅ| Í·4×Ö½Ú£¬Î²4×Ö½Ú ³¤¶È2×Ö½Ú 
#define EEPADDBK_CNNAME 		  0x540//ÕÅ| ºº×ÖÕ¾Ãû42×Ö½Ú
#define EEPADDBK_ADJOBJ               0x0580//ÕÅ| Ä¿±êÐ£×¼£¬ÉÏÎ»»úÏÂÔØ²ÎÊý10×Ö½Ú ³õÊ¼ÖµÎªµçÑ¹60V,µçÁ÷2A
#define EEPADDBK_IECYXADDR        0x05b0
#define EEPADDBK_IECPARA            0x0600
#define EEPADDBK_IECYCADDR        0x0640
#define EEPADDBK_IECYKADDR        0x0680
#define EEPADDBK_RP                      0x06c0

#define EEPADD_LOADNUM               0x0720   
#define EEPADDBK_LOADNUM           0x0730 

//EEPROMÖÐ¶ÏÏß¡¢µôµç¡¢Òì³££¨±£»¤¿ª¹ØÌø¿ª£©Ê±¼ä¼ÇÂ¼  ·ÖÅä1K×Ö½ÚµÄ¿Õ¼ä
#define EEPADD_TIME_BK_NUM        0x0800          //¶ÏÏßÊ±¼ä×ÜÌõÊý  1
#define EEPADD_TIME_BK_POS        0x0801          //¶ÏÏßÊ±¼äÎ»ÖÃÊý  1
#define EEPADD_TIME_BK            0x0802          //¶ÏÏßÊ±¼äÖµ     225 ×Ö½Ú  Õ¼256×Ö½Ú
#define EEPADD_TIME_OFF_NUM       0x0900          //µôµçÊ±¼ä×ÜÌõÊý  1
#define EEPADD_TIME_OFF_POS       0x0901          //µôµçÊ±¼äÎ»ÖÃÊý  1
#define EEPADD_TIME_OFF           0x0902          //µôµçÊ±¼äÖµ 212 ×Ö½Ú  Õ¼256×Ö½Ú
#define EEPADD_TIME_ABN_NUM       0x0a00          //×´Ì¬Òì³£Ê±¼ä×ÜÌõÊý  1
#define EEPADD_TIME_ABN_POS       0x0a01          //×´Ì¬Òì³£Ê±¼äÎ»ÖÃÊý  1
#define EEPADD_TIME_ABN           0x0a02          //×´Ì¬Òì³£Ê±¼äÖµ 212 ×Ö½Ú  Õ¼256×Ö½Ú

//EEPROMÖÐ¹ÊÕÏ¼ÇÂ¼  ·ÖÅä1K×Ö½ÚµÄ¿Õ¼ä
#define EEPADD_SOE_NUM          0x0c00          //¹ÊÕÏ¼ÇÂ¼×ÜÌõÊý  1
#define EEPADD_SOE_POS          0x0c01          //¹ÊÕÏ¼ÇÂ¼Î»ÖÃÊý  1
#define EEPADD_SOE_DATA         0x0c02          //¹ÊÕÏ¼ÇÂ¼ 360×Ö½Ú


//EEPROMÖÐÂ¼²¨Êý¾Ý  ·ÖÅä8K×Ö½Ú¿Õ¼ä
#define EEPADD_REC_NUM          0x0d00           //Â¼²¨Êý¾ÝµÄ×ÜÌõÊý
#define EEPADD_REC_POS          0x0d02           //×îÐÂÂ¼²¨Êý¾ÝËùÔÚµÄÏà¶ÔÎ»ÖÃ
#define EEPADD_REC_DATA         0x0d04           //Â¼²¨Êý¾ÝÐ£Ñé


//E2ÖÐ±£´æÂ¼²¨µÄ¸öÊý
#define EEPADD_LUBONUM          0x0E98 
#define EEPADD_ALEN             0x0E9A //AÏàµÄÆ«ÒÆÁ¿
#define EEPADD_BLEN             0x0E9C //BÏàµÄÆ«ÒÆÁ¿
#define EEPADD_CLEN             0x0E9E //CÏàµÄÆ«ÒÆÁ¿
#define EEPADD_COMLEN           0x0EA0 //×î´óÆ«ÒÆÁ¿

#define EEPADD_SOESTARTADR       0x2000 //×î´óÆ«ÒÆÁ¿
#define EEPADD_SOEENDADR       0x4000
//============================   GPIO¶ÔÓ¦LED¶¨Òå  ===============================
#define WDG_SET         (P5OUT |= BIT3)         //¿´ÃÅ¹·ÖÃÎ»    Í¬Ê±Ö¸Ê¾ÔËÐÐµÆÉÁË¸
#define WDG_CLR         (P5OUT &= NBIT3)        //¿´ÃÅ¹·ÇåÁã

#define LED_RUN_ON      (P6OUT |= BIT0)        //LED00 ÔËÐÐµÆ P6.0
#define LED_RUN_OFF     (P6OUT &= NBIT0) 
#define LED_RUN_TOGG    (P6OUT ^= BIT0)
//============================   GPIO¶ÔÓ¦½Ó´¥Æ÷¹©µç  ===============================
#define KMP_SET         (P5OUT |= BIT5)         //Îª½Ó´¥Æ÷¹©µç
#define KMP_CLR         (P5OUT &= NBIT5)        //½Ó´¥Æ÷¶Ïµç
//============================   GPIO¶ÔÓ¦WiFi¸´Î»  ===============================
#define WIFIR_SET         (P9OUT |= BIT6)         //
#define WIFIR_CLR         (P9OUT &= NBIT6)        //WiFiÄ£¿é¸´Î»

//============================   GPIO¶ÔÓ¦DO¶¨Òå  ===============================
#define KA1_OFF     (P4OUT &= NBIT6)                        //Òì³£×´Ì¬»Ö¸´
#define KA1_ON      (P4OUT |= BIT6)                         //Òì³£×´Ì¬±¨¾¯
#define KB1_OFF     (P4OUT &= NBIT7)                        //ÐÅºÅÔ´µôµç»Ö¸´
#define KB1_ON      (P4OUT |= BIT7)                         //ÐÅºÅÔ´µôµç±¨¾¯
#define KC1_OFF     (P5OUT &= NBIT4)                        //Ã»ÓÐÓÐÐ§8Âö³å
#define KC1_ON      (P5OUT |= BIT4)                         //·¢³öÓÐÐ§8Âö³å

#define KA0_OFF     (P7OUT &= NBIT2)                        //AÏà½Ó´¥Æ÷½ØÖ¹
#define KA0_ON      (P7OUT |= BIT2)                         //AÏà½Ó´¥Æ÷µ¼Í¨
#define KB0_OFF     (P7OUT &= NBIT3)                        //BÏà½Ó´¥Æ÷½ØÖ¹
#define KB0_ON      (P7OUT |= BIT3)                         //BÏà½Ó´¥Æ÷µ¼Í¨
#define KC0_OFF     (P8OUT &= NBIT0)                        //CÏà½Ó´¥Æ÷½ØÖ¹
#define KC0_ON      (P8OUT |= BIT0)                         //CÏà½Ó´¥Æ÷µ¼Í¨

#define   ABN_CHECK           BIT0          //abnormal self checked
#define   POWER_OFF           BIT1          //power down
#define   EIGHT_PULSE         BIT2          //eight pulse omit    
#define   SEND_AUTO           BIT3          //upload regulary
#define   FAULT_RST           BIT5          //fault recovery
#define   FAULT_OCCUR         BIT4          //fault occcur
#define   PHASE_BREAK         BIT6          //¶ÏÏß·¢Éú
#define   ZIZHAN_XUN          0x80          //×ÓÕ¾Ñ¯ÎÊ
#define   PHONE_XUN          0xc0          //×ÓÕ¾Ñ¯ÎÊ

#define NUM_10H  0x10
#define NUM_68H  0x68

#define   FEED_WATCH_DOG()            P5OUT ^= BIT3;

#define   LIGHT_RUN_UP()              P6OUT |= BIT0;
#define   LIGHT_RUN_DOWN()            P6OUT &= NBIT0;
#define   LIGHT_RUN_FLASH()           P6OUT ^= BIT0;

#pragma location=0xFF00
const unsigned char ucVerNum[]="Ver02.02";

//****************** command_flag *************************
//************* ÖÕ¶ËÖ÷¶¯·¢ËÍÊý¾ÝÊ± µÄ·¢ËÍÔ­Òò*****************//>0x68:¿É±äÖ¡¡£>0x10£º¹Ì¶¨Ö¡
#define ZONGZHAO_CONFIRM  0x71    //    ×ÜÕÙ-È·ÈÏ
#define ZUZHAO_CONFIRM    0x72    //    ×éÕÐ-È·ÈÏ
#define ZONGZHAO_STOP     0x73    //    ×ÜÕÙ-Í£Ö¹
#define ZUZHAO_STOP       0x74    //    ×éÕÐ-È·ÈÏ
#define CESHI_CONFIRM     0x75    //    ²âÊÔ-È·ÈÏ
#define FUWEI_CONFIRM     0x76    //    ¸´Î»-È·ÈÏ
#define FUWEI_STOP        0x77    //    ¸´Î»-Í£Ö¹

#define YANSHI_CONFIRM    0x79    //    ÑÓÊ±-È·ÈÏ
#define TONGBU_CONFIRM    0x7A    //    Ê±ÖÓÍ¬²½-È·ÈÏ
#define TONGBU_STOP       0X7B    //    ·¢ËÍ¶ÔÊ±Ö®Ç°µÄÊ±ÖÓ

#define CHUSHIHUA_FINISH  0xA0    //    ³õÊ¼»¯-Íê³É

#define YAOXIN_DAN_ALL    0X7C    //    ÒÔÈ«²¿ µ¥µã-Ò£ÐÅ ÏìÓ¦
#define YAOCE_ALL         0X7D    //    ÒÔ È«²¿Ò£²â ÏìÓ¦
#define YAOXIN_SHUANG_ALL 0x7E    //    ÒÔÈ«²¿ Ë«µã-Ò£ÐÅ ÏìÓ¦

#define CHUSHIHUA_JIESHU  0x8E    //    ³õÊ¼»¯½áÊø-È·ÈÏ
#define GGDIZHI_RONGCUO   0x90    //    ¹«¹²µØÖ·ÈÝ´í
#define COT_RONGCUO       0x91    //    Î´Öª ´«ËÍÔ­Òò
#define TYP_RONGCUO       0x92    //    Î´Öª ÀàÐÍ±ê¼Ç

#define QINGQIULIANLU     0x11    //    ÇëÇóÁ´Â·
#define FUWEIYUANFANG     0x12    //    ¸´Î»Ô¶·½

#define LINK_START      0x13    //    Á´Â·Æô¶¯
#define LINK_TEST       0x14    //    Á´Â·²âÊÔ
#define LINK_STOP       0x15    //    Á´Â·Í£Ö¹
#define LINK_ACK        0x16    //    ¿Ï¶¨È·ÈÏ
#define LINK_TEST_SEND  0x18    //    Á´Â·²âÊÔ ·¢ËÍ
#define LINK_STOP_SEND  0x19    //    Á´Â·Í£Ö¹ ·¢ËÍ
#define LINK_START_SEND 0x17    //    Á´Â·Æô¶¯ ·¢ËÍ

//****************** process_type *************************
//************** ÖÕ¶ËÓëÖ÷Õ¾Ö®¼ä ¹¦ÄÜÀàÐÍ ******************
#define CHUSHIHUA         0X01    //  ³õÊ¼»¯
#define ZONGZHAO_INIT     0X02    //  ×ÜÕÙ£¨³õÊ¼»¯£©
#define YANSHI            0X03    //  ÑÓÊ±
#define ZONGZHAO          0X04    //  ×ÜÕÙ
#define TONGBU            0X05    //  Ê±ÖÓÍ¬²½
#define CESHI             0X06    //  ²âÊÔ
#define FUWEI             0X07    //  ¸´Î»  
#define ZUZHAO_YX         0X08    //  ×éÕÐ_Ò£ÐÅ
#define ZUZHAO_YC         0X09    //  ×éÕÐ_Ò£²â
#define ZUZHAO_YXD        0X0A    //  ×éÕÐ_Ë«µãÒ£ÐÅ


//****************** ÓÅÏÈ¼¶¶¨Òå *************************
#define INIT_PRIORITY         0x38  //  ³õÊ¼»¯
#define ZONGZHAO_I_PRIORITY   0x36  //  ×ÜÕÙ£¨³õÊ¼»¯£©

#define YAOXIN_PRIORITY       0x30  //  Ò£ÐÅ
#define YANSHI_PRIORITY       0x28  //  ÑÓÊ± »ñµÃ
#define ZONGZHAO_PRIORITY     0x26  //  ×ÜÕÙ

#define YXSOE_PRIORITY        0x20   // Ò£ÐÅSOE

#define YC_PRIORITY           0x10   // Ò£²âÖµ
#define TONGBU_PRIORITY       0x09  //  Ê±ÖÓÍ¬²½
#define CESHI_PRIORITY        0X08  //  ²âÊÔ

#define FUWEI_PRIORITY        0X06  //  ¸´Î»

#define ZUZHAO_YX_PRIORITY    0X04  //  ×éÕÐ Ò£ÐÅ
#define ZUZHAO_YC_PRIORITY    0x04  //  ×éÕÐ  Ò£²â

#define GGDIZHI_PRIORITY      0x02  //  ¹«¹²µØÖ·ÈÝ´í
#define COT_PRIORITY          0x02  //  Î´Öª ´«ËÍÔ­Òò
#define TYP_PRIORITY          0x02  //  Î´Öª ÀàÐÍ±ê¼Ç

//****************** GPRS101 ºÍ SMS ×´Ì¬ÇÐ»»*************************
#define GPRSState_IDLE           0x00
#define GPRSState_GPRS101    0x01
#define GPRSState_SMS            0x02
//FLASHÖÐÂ¼²¨Êý¾Ý        ´ÓµÚ1200Ò³¿ªÊ¼£¬±£´æ640Ò³ Ã¿16Ò³(3840)´æÒ»Ö»Ö¸Ê¾Æ÷µÄÒ»ÌõÂ¼²¨Êý¾Ý£¬16*4=64Ò³´æÒ»ÕûÌõÍêÕûµÄÂ¼²¨Êý¾Ý£¬¿É´æ10ÌõÍêÕûµÄÂ¼²¨Êý¾Ý

#define FADDR_RECORDER_START         0x4B000   //µçÁ÷Â¼²¨ÆðÊ¼µØÖ·         

#define FRECORDER_TOLNUM      21  //´æÈëÍâ²¿flashµÄÂ¼²¨×ÜÊý¡£20ÌõÍêÕûµÄÂ¼²¨
//#define FRECORDER_PNUM        16    //Ã¿16Ò³´æÒ»ÌõÂ¼²¨Êý¾Ý
#define WRITEPECORDER  228//Ð´Èë°üÊý¾Ý¸öÊý »ùµØÖ·£¨3£©+Æ«ÒÆµØÖ·£¨3£©+Êý¾ÝÁ¿£¨1£©+Êý¾ÝÄÚÈÝ£¨224£©+ÀÛ¼ÓºÍ£¨1£©
//#define FLINEADDR  (64*256)
#define FLINEADDR  (16*256)
#define FPHASEADDR (16*256)

#define FADDR_RECORDER_STARTV        0x9C000   //µçÑ¹Â¼²¨ÆðÊ¼ÖµµØÖ· 
#define RECORDER  (80*15)

#define FADDR_RECORDER_INFO       0x10000   //Â¼²¨Ä¿Â¼ÐÅÏ¢ A20*100A
#define FADDR_RECORDER_DATA      0x4000   //¹ÊÕÏÂ¼²¨Êý¾Ý0x4000
#define FADDR_RECORDER_ACTDATA      0x70000   //¶¯×÷Â¼²¨Êý¾Ý0x70000
#define FADDR_RECORDER_XHDATA      0x6C0000   //Ï¨»¡Â¼²¨Êý¾Ý0x6C0000
/*
³ÌÐòÉý¼¶7AF000
¸ººÉ¼ÇÂ¼//750000-790000   Ã¿Ìõ32×Ö½Ú ¹²8192Ìõ
Ï¨»¡Â¼²¨//6C0000-710000  Ã¿Ìõ2Íò×Ö½Ú¡¢0.5¸öBLOCK£¬¹²10Ìõ
¶¯×÷Â¼²¨//70000-6B0000  Ã¿Ìõ60Íò×Ö½Ú¡¢9¸öBLOCK£¬¹²10Ìõ
¹ÊÕÏÂ¼²¨//4000-68000  Ã¿Ìõ6400×Ö½Ú¡¢2¸öSector(0x2000)£¬¹²50Ìõ
soe//0-3000 Ã¿Ìõ16×Ö½Ú¹²768Ìõ
*/
/*
0x0         -  0x3000     ´æ´¢soe£¬Ã¿Ìõsoe16×Ö½Ú£¬´æ512Ìõ
0x10000  -  0x30000   ´ægRecorder_cfg£¬°üÀ¨Â¼²¨ÎÄ¼þÃû£¬Â¼²¨ÎÄ¼þ³¤¶È£¬Â¼²¨Ê±¼ä£¬Ã¿ÌõÕ¼1¸ö
sector-4096×Ö½Ú

0x100000-  0x300000   ´æ¹ÊÕÏÂ¼²¨£¬5¸öÒ£²â£¬8¸öÖÜ²¨£¬Ã¿ÖÜ²¨80µã£¬¹²640µã£¬6400×Ö½Ú£¬Ã¿ÌõÕ¼4¸öblock-0x10000×Ö½Ú
                                   ´æ¶¯×÷Â¼²¨£¬5¸öÒ£²â£¬10-25Ãë£¬Ã¿Ãë800µã£¬×î¶à20000µã£¬20Íò×Ö½Ú£¬Ã¿Ìõ4¸öblock-0x50000
*/
#define RECORDER_INFO_LENGTH      100      

//#define FADDR_RECORDER_VINFO       0xF4000   //Â¼²¨Ä¿Â¼ÐÅÏ¢ 20*100
//#define FADDR_RECORDER_VINFOB       0xF5000   //Â¼²¨Ä¿Â¼ÐÅÏ¢ 20*100
//#define FADDR_RECORDER_VINFOC       0xF6000   //Â¼²¨Ä¿Â¼ÐÅÏ¢ 20*100
//#define FADDR_RECORDER_VINFO0       0xF7000   //Â¼²¨Ä¿Â¼ÐÅÏ¢ 20*100



#define RECORDER_MULU_LENGTH      13  //»Ø¸´Ã¿ÌõÂ¼²¨Ä¿Â¼µÄ³¤¶È

#define FADDR_RECORDER_START_BK         0x100000   //µçÁ÷Â¼²¨ÆðÊ¼µØÖ· 
#define FADDR_RECORDER_STARTV_BK        0x151000   //µçÑ¹Â¼²¨ÆðÊ¼ÖµµØÖ· 


//#define FSOE_LEN         16    //Ã»ÌõSOEÕ¼16×Ö½Ú ÄÚ´æÖÐÃ¿ÌõÕ¼11×Ö½Ú£¬ÕâÀïÎªÁËflashÖÐÈÝÒ×´¦Àí²ÅÔ¤Áô³ö5×Ö½Ú

//===============================Èë¿Ú±êÖ¾Êý¾Ý¼°±¸·ÝÐ£Ñé´æ´¢Çø================
#define FLASH_UPDATE_COUNTER     0x7AF000 //°ü×ÜÊý
#define FLASH_UPDATE_CHECK       0x7AF002 //Ð£ÑéÖµ
#define FLASH_UPDATE_STATE       0x7AF004 //Éý¼¶×´Ì¬
#define FLASH_UPDATE_EARASE       0x7AF005//ÄÚ²¿flash²Á³ý±íÊ¾ÓÃÓÚ±íÊ¾Éý¼¶¹ý³ÌÖÐÊÇ·ñÒÑ¾­½«ÄÚ²¿flash²Á³ý£¬ÒÔ·ÀÖ¹ÔÚ²Á³öÒÔºó¸Ä±äÉý¼¶×´Ì¬¶øÖØÆôºóÈ¥Ñ°ÕÒÔ­ÓÐ³ÌÐòÈë¿Ú
#define FLASH_UPDATE_CCHECK       0x7AF006 //Ð£Ñé
//±¸·Ý
#define FLASH_UPDATEBK_COUNTER   0x7AF008 //°ü×ÜÊý
#define FLASH_UPDATEBK_CHECK     0x7AF00A //Ð£ÑéÖµ
#define FLASH_UPDATEBK_STATE     0x7AF00C //Éý¼¶×´Ì¬
#define FLASH_UPDATEBK_EARASE     0x7AF00C //flash²Á³ý±êÖ¾
#define FLASH_UPDATEBK_CCHECK     0x7AF00D //Ð£Ñé

//===================================Ó¦ÓÃ³ÌÐò´æ´¢Çø===========================
#define FLASH_UPDATE_START      0X7B0000       //
#define FLASH_UPDATE_END        0X7EFFFF       //
#define FLASH_UPCOUNTER          0x7F0000//ÎÞÐ§Éý¼¶´ÎÊý      


#define ERASE_DELAY 30000//²Á³ýÓëÐ´Èë¼ä¸ôÑÓÊ±£¬Ì«Ð¡Ôò»áÔì³ÉÐ´Èë´íÎó£¨È«1£©
#define ERASEFLAGADDR   0x45A00//ÄÚ²¿flashµØÖ·£¬jtagÉÕÐ´³ÌÐò±êÖ¾Ê×µØÖ·,Ê¹ÓÃ6¸ö×Ö½Ú±íÊ¾£¬ÔÚ³ÌÐòÏÂÔØÍê³ÉÖ®ºóÈ«²¿Ð´Îª0x55

#endif

/*
³ÌÐòÉý¼¶7AF000
¸ººÉ¼ÇÂ¼//750000-790000   Ã¿Ìõ32×Ö½Ú ¹²8192Ìõ
Ï¨»¡Â¼²¨//6C0000-710000  Ã¿Ìõ2Íò×Ö½Ú¡¢0.5¸öBLOCK£¬¹²10Ìõ
¶¯×÷Â¼²¨//70000-6B0000  Ã¿Ìõ60Íò×Ö½Ú¡¢9¸öBLOCK£¬¹²10Ìõ
¹ÊÕÏÂ¼²¨//4000-68000  Ã¿Ìõ6400×Ö½Ú¡¢2¸öSector£¬¹²50Ìõ
soe//0-3000 Ã¿Ìõ16×Ö½Ú¹²768Ìõ
*/

