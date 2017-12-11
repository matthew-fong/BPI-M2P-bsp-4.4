/*
 * drivers/usb/sunxi_usb/include/sunxi_usb_debug.h
 * (C) Copyright 2010-2015
 * Allwinner Technology Co., Ltd. <www.allwinnertech.com>
 * javen, 2010-12-20, create this file
 *
 * usb debug head file.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 */

#ifndef __SUNXI_USB_DEBUG_H__
#define __SUNXI_USB_DEBUG_H__

#ifdef CONFIG_USB_SUNXI_USB_DEBUG
#define  DMSG_PRINT(stuff...)		printk(stuff)
#define  DMSG_PR(fmt, stuff...)	pr_debug(fmt, ##stuff)
#define  DMSG_INFO_UDC(fmt, ...)	DMSG_PR("[udc]: "fmt, ##__VA_ARGS__)
#define  DMSG_INFO_HCD0(fmt, ...)	DMSG_PR("[hcd0]: "fmt, ##__VA_ARGS__)
#define  DMSG_INFO_MANAGER(fmt, ...)	DMSG_PR("[magr]: "fmt, ##__VA_ARGS__)
#else
#define  DMSG_PRINT(stuff...)
#define  DMSG_PR(fmt, ...)
#define  DMSG_INFO_UDC(fmt, ...)
#define  DMSG_INFO_HCD0(fmt, ...)
#define  DMSG_INFO_MANAGER(fmt, ...)
#endif

/* test */
#if 0
#define DMSG_TEST			DMSG_PRINT
#else
#define DMSG_TEST(...)
#endif

/* code debug */
#if 0
#define DMSG_MANAGER_DEBUG		DMSG_PRINT
#else
#define DMSG_MANAGER_DEBUG(...)
#endif

#if 0
#define DMSG_DEBUG			DMSG_PRINT
#else
#define DMSG_DEBUG(...)
#endif

/* normal print */
#if 1
#define DMSG_INFO			DMSG_PRINT
#else
#define DMSG_INFO(...)
#endif

/* serious warn */
#if 1
#define DMSG_PANIC			DMSG_PRINT
#else
#define DMSG_PANIC(...)
#endif

/* normal warn */
#if 0
#define DMSG_WRN			DMSG_ERR
#else
#define DMSG_WRN(...)
#endif

/* dma debug print */
#if	0
#define DMSG_DBG_DMA			DMSG_PRINT
#else
#define DMSG_DBG_DMA(...)
#endif

void print_usb_reg_by_ep(spinlock_t *lock,
				void __iomem *usbc_base,
				__s32 ep_index,
				char *str);
void print_all_usb_reg(spinlock_t *lock,
				void __iomem *usbc_base,
				__s32 ep_start,
				__u32 ep_end,
				char *str);

void clear_usb_reg(void __iomem *usb_base);
void fpga_config_use_otg(void __iomem *sram_vbase);

#endif /* __SUNXI_USB_DEBUG_H__ */
