/*
****************************************************************
*      LINUX-KERNEL
* AllWinner Linux Platform Develop Kits
* Kernel Module
*
* (c) Copyright 2006-2011, kevin.z China
* All Rights Reserved
*
* File    : super_i.h
* By      : kevin.z
* Version : v1.0
* Date    : 2011-5-30 17:21
* Descript:
* Update  : date  auther ver notes
****************************************************************
*/
#ifndef __PM_RESUMES_H__
#define __PM_RESUMES_H__

#include "resumes_assembler.h"

typedef signed char           __s8;
typedef unsigned char         __u8;
typedef short int             __s16;
typedef unsigned short        __u16;
typedef int                   __s32;
typedef unsigned int          __u32;

#define RESUMEX_MAGIC               "eGON.BT0"
#define STAMP_VALUE                 0x5F0A6C39
#define RESUME_FILE_HEAD_VERSION    "1100"     /* X.X.XX */
#define RESUME_VERSION              "1100"     /* X.X.XX */
#define PLATFORM                    "1633"

#define NF_ALIGN_SIZE               1024
#define RESUMEX_ALIGN_SIZE          NF_ALIGN_SIZE
#define RESUME_PUB_HEAD_VERSION     "1100"    /* X.X.XX */
#define RESUMEX_FILE_HEAD_VERSION   "1230"    /* X.X.XX */
#define RESUMEX_VERSION             "1230"    /* X.X.XX */
#define EGON_VERSION                "1100"    /* X.X.XX */

/******************************************************************************/
/*                              file head of Resume                           */
/******************************************************************************/
typedef struct _Resume_file_head {
	__u32  jump_instruction;   /* one intruction jumping to real code */
	__u8   magic[8];           /* ="eGON.BT0" or "eGON.BT1". */
	__u32  check_sum;          /* generated by PC */
	__u32  length;             /* generated by PC */
	__u32  pub_head_size;      /* the size of resume_file_head_t */
	__u8   pub_head_vsn[4];    /* the version of resume_file_head_t */
	__u8   file_head_vsn[4];   /* the version of resume0_file_head_t */
	__u8   Resume_vsn[4];      /* Resume version */
	__u8   eGON_vsn[4];        /* eGON version */
	__u8   platform[8];        /* platform information */
} resume_file_head_t;

extern const resume_file_head_t  resume_head;

#define BEFORE_EARLY_SUSPEND    (0x00)
#define SUSPEND_BEGIN           (0x20)
#define SUSPEND_ENTER           (0x40)
#define BEFORE_LATE_RESUME      (0x60)
#define LATE_RESUME_START       (0x80)
#define CLK_RESUME_START        (0xA0)
#define AFTER_LATE_RESUME       (0xC0)
#define RESUME_COMPLETE_FLAG    (0xE0)
#define SUSPEND_FAIL_FLAG       (0xFF)
#define FIRST_BOOT_FLAG         (0x00)

/** NOTE: the resumes_assembler.h should be adjusted cressponding,
 * if these structs changed!
 */
struct mmu_state {
	__u32 cssr;     /* 00, CR0: Cache Size Selection            */
	__u32 cr;       /* 04, CR1: Control                         */
	__u32 cacr;     /* 08, Coprocessor Access Control           */
	__u32 ttb_0r;   /* 12, CR2: Translation Table Base 0        */
	__u32 ttb_1r;   /* 16, Translation Table Base 1             */
	__u32 ttbcr;    /* 20, Translation Talbe Base Control       */
	__u32 dacr;     /* 24, CR3: Domain Access Control           */
	__u32 prrr;	    /* 28, cr10: Primary Region Remap Register  */
	__u32 nrrr;	    /* 32, Normal Memory Remap Register         */
};

struct regs_restore {
	__u32 addr;     /* 00, CR0: Cache Size Selection            */
	__u32 value;    /* 04, CR1: Control                         */
};

struct sram_para {
	unsigned long resume_code_src;
	unsigned long monitor_vector;
	struct mmu_state saved_secure_mmu_state;
	unsigned long regs_num;
	struct regs_restore regs_back[20];
};

#endif  /* __PM_RESUMES_H__ */

