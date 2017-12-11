/*
 * drivers/thermal/sunxi_ths_driver.h
 *
 * Copyright (C) 2013-2024 allwinner.
 *	JiaRui Xiao<xiaojiarui@allwinnertech.com>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 */

#ifndef THERMAL_SENSOR_DRIVER_H
#define THERMAL_SENSOR_DRIVER_H

#if defined(CONFIG_ARCH_SUN8IW5)
#define THERMAL_VERSION 1
#elif defined(CONFIG_ARCH_SUN8IW10) || defined(CONFIG_ARCH_SUN8IW11) || \
defined(CONFIG_ARCH_SUN50IW1) || defined(CONFIG_ARCH_SUN50IW2) || \
defined(CONFIG_ARCH_SUN8IW7)
#define THERMAL_VERSION 2
#elif defined(CONFIG_ARCH_SUN50IW3) || defined(CONFIG_ARCH_SUN50IW6) || \
defined(CONFIG_ARCH_SUN8IW12)
#define THERMAL_VERSION 3
#endif

#if defined(CONFIG_ARCH_SUN8IW7)

#define ENABLE_CLK		(true)


/* temperature = -0.118*sensor + 256
 *	= (256000 - 118*sensor)/1000
 *	= (262144 - 120.832*sensor)/1024
 *	= (268435456 - 123732*sensor)/1024/1024
 *	= ( MINUPA - reg * MULPA) / 2^DIVPA
 *	sensor value range:
 *				= 0 - 0xffff,ffff/2/123732
 *				= 0 - 17355
 */

char *id_name_mapping[] = {
	"cpuc0"
};

struct temp_calculate_coefficent thermal_cal_coefficent[] = {
	[0] = {
		.down_limit = {(-227), (0xfff)},
		.up_limit = {(256), (0x000)},
		.nt_para = {
				/* MUL_PARA DIV_PARA MINU_PARA */
				{(1000), (8253), (1794000)},
				{(1000), (8253), (1794000)}
		}
	}
};

struct thermal_reg thermal_reg_init[] = {
	/* name			        address		value	    reg_type*/
	{"THS_CTRL_REG",		(0x00),		(0x0000003f),	(NORMAL_REG)},
	{"THS_CTRL2_REG",		(0x40),		(0x003f0001),	(ENABLE_REG)},
	{"THS_INT_CTRL_REG",		(0x44),		(0x3a030),	(NORMAL_REG)},
	{"THS_INT_STA_REG",		(0x48),		(0x333),	(INT_STA_REG)},
	{"THS_INT_ALM_TH_REG",		(0x50),		(0x0),		(NO_INIT)},
	{"THS_INT_SHUT_TH_REG",		(0x60),		(0x0),		(SHT_TMP_REG)},
	{"THS_FILT_CTRL_REG",		(0x70),		(0x06),		(NORMAL_REG)},
	{"THS_CDATA_REG",		(0x74),		(0x0),		(CDATA_REG)},
	{"THS_0_DATA_REG",		(0x80),		(0x0),		(TDATA_REG)},
	{"", (0), (0), (0)}
};

#endif /* CONFIG_ARCH_SUN8IW7 */

#if defined(CONFIG_ARCH_SUN8IW10)

#define ENABLE_CLK		(true)


/* temperature = -0.118*sensor + 256
 *	= (256000 - 118*sensor)/1000
 *	= (262144 - 120.832*sensor)/1024
 *	= (268435456 - 123732*sensor)/1024/1024
 *	= ( MINUPA - reg * MULPA) / 2^DIVPA
 *	sensor value range:
 *				= 0 - 0xffff,ffff/2/123732
 *				= 0 - 17355
 */

char *id_name_mapping[] = {
	"cpuc0",
	"dram"
};

struct temp_calculate_coefficent thermal_cal_coefficent[] = {
	[0] = {
		.down_limit = {(-227), (0xfff)},
		.up_limit = {(256), (0x000)},
		.nt_para = {
				/* MUL_PARA DIV_PARA MINU_PARA */
				{(1180), (10000), (2560000)},
				{(1180), (10000), (2560000)}
		}
	}
};

struct thermal_reg thermal_reg_init[] = {
	/* name			        address		value	    reg_type*/
	{"THS_CTRL2_REG",		(0x40),		(0x01df0000),	(ENABLE_REG)},
	{"THS_INT_CTRL_REG",		(0x44),		(0x3a030),	(NORMAL_REG)},
	{"THS_INT_STA_REG",		(0x48),		(0x333),	(INT_STA_REG)},
	{"THS_0_INT_ALM_TH_REG",	(0x50),		(0x0),		(NO_INIT)},
	{"THS_1_INT_ALM_TH_REG",	(0x54),		(0x0),		(NO_INIT)},
	{"THS_0_INT_SHUT_TH_REG",	(0x60),		(0x0),		(SHT_TMP_REG)},
	{"THS_1_INT_SHUT_TH_REG",	(0x64),		(0x0),		(SHT_TMP_REG)},
	{"THS_FILT_CTRL_REG",		(0x70),		(0x06),		(NORMAL_REG)},
	{"THS_0_1_CDATA_REG",		(0x74),		(0x0),		(CDATA_REG)},
	{"THS_0_DATA_REG",		(0x80),		(0x0),		(TDATA_REG)},
	{"THS_1_DATA_REG",		(0x84),		(0x0),		(TDATA_REG)},
	{"", (0), (0), (0)}
};

#endif /* CONFIG_ARCH_SUN8IW10 */

#if defined(CONFIG_ARCH_SUN8IW11)

#define ENABLE_CLK		(true)



/* temperature = -0.1125*sensor + 250
 *	= (2500000 - 1125*sensor)/10000
 *	= (xxx - 117964.8*sensor)/1024/1024
 *	= ( MINUPA - reg * MULPA) / 2^DIVPA
 *	sensor value range:
 *				= 0 - 0xffff,ffff/2/117964
 *				= 0 - 18204
 */
char *id_name_mapping[] = {
	"cpuc0",
	"gpu"
};

struct temp_calculate_coefficent thermal_cal_coefficent[] = {
	[0] = {
		.down_limit = {(-210), (0xfff)},
		.up_limit = {(250), (0x000)},
		/*MUL_PARA DIV_PARA MINU_PARA */
		.nt_para = {
				{(1125), (10000), (2500000)},
				{(1125), (10000), (2500000)}
		}
	}
};

/**	@THS_INT_CTRL_VALUE:per sampling takes: 10ms
 *	@THS_CTRL0_VALUE:acq time = 20us
 *	@THS_FILT_CTRL_REG :got 1 data for per 8 sampling,
 *	 time = 10ms * 8 = 80ms
 */
struct thermal_reg thermal_reg_init[] = {
	/* name			        address		value	    reg_type*/
	{"THS_CTRL0_REG",		(0x00),		(0x1df),	(NORMAL_REG)},
	{"THS_CTRL1_REG",		(0x04),		(0x1<<17),	(NORMAL_REG)},
	{"ADC_CDAT_REG",		(0x14),		(0x0),		(NO_INIT)},
	{"THS_CTRL2_REG",		(0x40),		(0x01df0000),	(ENABLE_REG)},
	{"THS_INT_CTRL_REG",		(0x44),		(0x3a030),	(NORMAL_REG)},
	{"THS_INT_STA_REG",		(0x48),		(0x333),	(INT_STA_REG)},
	{"THS_0_INT_ALM_TH_REG",	(0x50),		(0x0),		(NO_INIT)},
	{"THS_1_INT_ALM_TH_REG",	(0x54),		(0x0),		(NO_INIT)},
	{"THS_0_INT_SHUT_TH_REG",	(0x60),		(0x0),		(SHT_TMP_REG)},
	{"THS_1_INT_SHUT_TH_REG",	(0x64),		(0x0),		(SHT_TMP_REG)},
	{"THS_FILT_CTRL_REG",		(0x70),		(0x06),		(NORMAL_REG)},
	{"THS_0_1_CDATA_REG",		(0x74),		(0x0),		(CDATA_REG)},
	{"THS_0_DATA_REG",		(0x80),		(0x0),		(TDATA_REG)},
	{"THS_1_DATA_REG",		(0x84),		(0x0),		(TDATA_REG)},
	{"", (0), (0), (0)}
};

#endif /* CONFIG_ARCH_SUN8IW11 */

#if defined(CONFIG_ARCH_SUN8IW12)

#define ENABLE_CLK		(true)

struct temp_calculate_coefficent thermal_cal_coefficent[] = {

	[0] = {
		.down_limit = {(-210), (0xfff)},
		.up_limit = {(250), (0x000)},
		/*MUL_PARA DIV_PARA MINU_PARA */
		.nt_para = {
				{(1000), (14882), (2794000)},
				{(1000), (14882), (2794000)},
				{(1000), (14882), (2794000)}
		}
	}
};


/**
 *       SUN8IW12P1  Thermal Sensor Register
 */
char *id_name_mapping[] = {
	"cpu",
	"ve",
	"isp",
};


struct thermal_reg thermal_reg_init[] = {
/* name			        address		value	    reg_type*/
{"THS_CTRL_REG",		(0x00),		(0x1df002f),	(NORMAL_REG)},
{"THS_EN_REG",			(0x04),		(0x7),		(ENABLE_REG)},
{"THS_PER_REG",			(0x08),		(0x3a000),	(NORMAL_REG)},
{"THS_DATA_INTC_REG",		(0x10),		(0x0),		(NO_INIT)},
{"THS_SHUT_INTC_REG",		(0x14),		(0x7),		(NORMAL_REG)},
{"THS_ALARM_INTC_REG",		(0x18),		(0x0),		(NO_INIT)},
{"THS_DATA_INTS_REG",		(0x20),		(0x7),		(INT_STA_REG)},
{"THS_SHUT_INTS_REG",		(0x24),		(0x7),		(INT_STA_REG)},
{"THS_ALARMO_INTS_REG",		(0x28),		(0x7),		(INT_STA_REG)},
{"THS_ALARM_INTS_REG",		(0x2C),		(0x7),		(INT_STA_REG)},
{"THS_FILT_CTRL_REG",		(0x30),		(0x06),		(NORMAL_REG)},
{"THS_0_ALARM_CTRL_REG",	(0x40),		(0x0),		(NO_INIT)},
{"THS_1_ALARM_CTRL_REG",	(0x44),		(0x0),		(NO_INIT)},
{"THS_2_ALARM_CTRL_REG",	(0x48),		(0x0),		(NO_INIT)},
{"THS_0_1_SHUT_CTRL_REG",	(0x80),		(0x0),		(SHT_TMP_REG)},
{"THS_2_SHUT_CTRL_REG",		(0x84),		(0x0),		(SHT_TMP_REG)},
{"THS_0_1_CDATA_REG",		(0xA0),		(0x0),		(CDATA_REG)},
{"THS_2_CDATA_REG",		(0xA4),		(0x0),		(CDATA_REG)},
{"THS_0_DATA_REG",		(0xC0),		(0x0),		(TDATA_REG)},
{"THS_1_DATA_REG",		(0xC4),		(0x0),		(TDATA_REG)},
{"THS_2_DATA_REG",		(0xC8),		(0x0),		(TDATA_REG)},
{"", (0), (0), (0)}
};

#endif /* CONFIG_ARCH_SUN8IW12 */

#if defined(CONFIG_ARCH_SUN50IW1)

#define ENABLE_CLK		(true)

/* temperature = ( MINUPA - reg * MULPA) / DIVPA */

char *id_name_mapping[] = {
	"cpuc0",
	"cpuc1",
	"gpu"
};

struct temp_calculate_coefficent thermal_cal_coefficent[] = {
	[0] = {
		.down_limit = {(-210), (0xfff)},
		.up_limit = {(250), (0x000)},
		.nt_para = {
				{(1000), (8560), (2170000)},
				{(1000), (8560), (2170000)},
				{(1000), (8560), (2170000)}
		}
	}
};

struct thermal_reg thermal_reg_init[] = {
	/* name			        address		value	    reg_type*/
	{"THS_CTRL0_REG",		(0x00),		(0x190),	(NORMAL_REG)},
	{"THS_CTRL1_REG",		(0x04),		(0x1<<17),	(NORMAL_REG)},
	{"ADC_CDAT_REG",		(0x14),		(0x0),		(NO_INIT)},
	{"THS_CTRL2_REG",		(0x40),		(0x01900000),	(ENABLE_REG)},
	{"THS_INT_CTRL_REG",		(0x44),		(0x18070),	(NORMAL_REG)},
	{"THS_INT_STA_REG",		(0x48),		(0x777),	(INT_STA_REG)},
	{"THS_0_INT_ALM_TH_REG",	(0x50),		(0x0),		(NO_INIT)},
	{"THS_1_INT_ALM_TH_REG",	(0x54),		(0x0),		(NO_INIT)},
	{"THS_2_INT_ALM_TH_REG",	(0x58),		(0x0),		(NO_INIT)},
	{"THS_0_INT_SHUT_TH_REG",	(0x60),		(0x0),		(SHT_TMP_REG)},
	{"THS_1_INT_SHUT_TH_REG",	(0x64),		(0x0),		(SHT_TMP_REG)},
	{"THS_2_INT_SHUT_TH_REG",	(0x68),		(0x0),		(SHT_TMP_REG)},
	{"THS_FILT_CTRL_REG",		(0x70),		(0x06),		(NORMAL_REG)},
	{"THS_0_1_CDATA_REG",		(0x74),		(0x0),		(CDATA_REG)},
	{"THS_2_CDATA_REG",		(0x78),		(0x0),		(CDATA_REG)},
	{"THS_0_DATA_REG",		(0x80),		(0x0),		(TDATA_REG)},
	{"THS_1_DATA_REG",		(0x84),		(0x0),		(TDATA_REG)},
	{"THS_2_DATA_REG",		(0x88),		(0x0),		(TDATA_REG)},
	{"", (0), (0), (0)}
};


#endif /*CONFIG_ARCH_SUN50IW1 */

#if defined(CONFIG_ARCH_SUN50IW2)

#define ENABLE_CLK		(true)


/* when  temperature <= 70C (sample_data >= 0x500)
 *	temperature = -0.1191*sensor + 223
 *		= (2230000 - 1191*sensor)/10000
 *		= (233832448 - 124885.4016*sensor)/1024/1024
 *		= (233832448 - 124885*sensor)/1024/1024
 *		= ( MINUPA - reg * MULPA) / 2^DIVPA
 *		sensor value range:
 *				= 0 - 0xffff,ffff/2/124885
 *				= 0 - 17195
 */
char *id_name_mapping[] = {
	"cpuc0",
	"gpu"
};

struct temp_calculate_coefficent thermal_cal_coefficent[] = {
	[0] = {
		.down_limit = {(-268), (0xfff)},
		.up_limit = {(70), (0x500)},
		.nt_para = {
				{(1191), (10000), (2230000)},
				{(1191), (10000), (2230000)}
		}
	},
	[1] = {
		.down_limit = {(70), (0x500)},
		.up_limit = {(223), (0x000)},
		.nt_para = {
				{(1452), (10000), (2590000)},
				{(1590), (10000), (2760000)}
		}
	}
};



/* when  temperature > 70C (sample_data < 0x500)
 *	cpu_temperature = -0.1452*sensor + 259
 *		= (2590000 - 1452*sensor)/10000
 *		= (271581184 - 152253.2352*sensor)/1024/1024
 *		= (271581184 - 152253*sensor)/1024/1024
 *		= ( MINUPA - reg * MULPA) / 2^DIVPA
 *		sensor value range:
 *				= 0 - 0xffff,ffff/2/152253
 *				= 0 - 14104
 *
 *	gpu_temperature = -0.159*sensor + 276
 *		= (2760000 - 1590*sensor)/10000
 *		= (289406976 - 166723.5840*sensor)/1024/1024
 *		= (289406976 - 166724*sensor)/1024/1024
 *		= ( MINUPA - reg * MULPA) / 2^DIVPA
 *		sensor value range:
 *				= 0 - 0xffff,ffff/2/166724
 *				= 0 - 2047
 */

struct thermal_reg thermal_reg_init[] = {
	/* name			        address		value	    reg_type*/
	{"THS_CTRL0_REG",		(0x00),		(0x1df),	(NORMAL_REG)},
	{"THS_CTRL1_REG",		(0x04),		(0x1<<17),	(NORMAL_REG)},
	{"ADC_CDAT_REG",		(0x14),		(0x0),		(NO_INIT)},
	{"THS_CTRL2_REG",		(0x40),		(0x01df0000),	(ENABLE_REG)},
	{"THS_INT_CTRL_REG",		(0x44),		(0x3a030),	(NORMAL_REG)},
	{"THS_INT_STA_REG",		(0x48),		(0x333),	(INT_STA_REG)},
	{"THS_0_INT_ALM_TH_REG",	(0x50),		(0x0),		(NO_INIT)},
	{"THS_1_INT_ALM_TH_REG",	(0x54),		(0x0),		(NO_INIT)},
	{"THS_0_INT_SHUT_TH_REG",	(0x60),		(0x0),		(SHT_TMP_REG)},
	{"THS_1_INT_SHUT_TH_REG",	(0x64),		(0x0),		(SHT_TMP_REG)},
	{"THS_FILT_CTRL_REG",		(0x70),		(0x06),		(NORMAL_REG)},
	{"THS_0_1_CDATA_REG",		(0x74),		(0x0),		(CDATA_REG)},
	{"THS_0_DATA_REG",		(0x80),		(0x0),		(TDATA_REG)},
	{"THS_1_DATA_REG",		(0x84),		(0x0),		(TDATA_REG)},
	{"", (0), (0), (0)}
};

#endif /* CONFIG_ARCH_SUN50IW2 */

#if defined(CONFIG_ARCH_SUN50IW3)

#define ENABLE_CLK		(true)

struct temp_calculate_coefficent thermal_cal_coefficent[] = {
	[0] = {
		.down_limit = {(-210), (0xfff)},
		.up_limit = {(250), (0x000)},
		/*MUL_PARA DIV_PARA MINU_PARA */
		.nt_para = {
			{(1000), (14882), (2794000)},
			{(1000), (14882), (2794000)},
			{(1000), (14882), (2794000)},
		}
	}
};


/**
 *       SUN50IW3  Thermal Sensor Register
 */
char *id_name_mapping[] = {
	"gpu",
	"VE",
	"cpuc0",
};

struct thermal_reg thermal_reg_init[] = {
	/* name			        address		value	    reg_type*/
	{"THS_CTRL_REG",		(0x00),		(0x01df002f),	(NORMAL_REG)},
	{"THS_EN_REG",			(0x04),		(0x7),		(ENABLE_REG)},
	{"THS_PER_REG",			(0x08),		(0x3a000),	(NORMAL_REG)},
	{"THS_DATA_INTC_REG",		(0x10),		(0x0),		(NO_INIT)},
	{"THS_SHUT_INTC_REG",		(0x14),		(0x7),		(NORMAL_REG)},
	{"THS_ALARM_INTC_REG",		(0x18),		(0x0),		(NO_INIT)},
	{"THS_DATA_INTS_REG",		(0x20),		(0x7),		(INT_STA_REG)},
	{"THS_SHUT_INTS_REG",		(0x24),		(0x7),		(INT_STA_REG)},
	{"THS_ALARMO_INTS_REG",		(0x28),		(0x7),		(INT_STA_REG)},
	{"THS_ALARM_INTS_REG",		(0x2C),		(0x7),		(INT_STA_REG)},
	{"THS_FILT_CTRL_REG",		(0x30),		(0x06),		(NORMAL_REG)},
	{"THS_0_ALARM_CTRL_REG",	(0x40),		(0x0),		(NO_INIT)},
	{"THS_1_ALARM_CTRL_REG",	(0x44),		(0x0),		(NO_INIT)},
	{"THS_2_ALARM_CTRL_REG",	(0x48),		(0x0),		(NO_INIT)},
	{"THS_0_1_SHUT_CTRL_REG",	(0x80),		(0x0),		(SHT_TMP_REG)},
	{"THS_2_SHUT_CTRL_REG",		(0x84),		(0x0),		(SHT_TMP_REG)},
	{"THS_0_1_CDATA_REG",		(0xA0),		(0x0),		(CDATA_REG)},
	{"THS_2_CDATA_REG",		(0xA4),		(0x0),		(CDATA_REG)},
	{"THS_0_DATA_REG",		(0xC0),		(0x0),		(TDATA_REG)},
	{"THS_1_DATA_REG",		(0xC4),		(0x0),		(TDATA_REG)},
	{"THS_2_DATA_REG",		(0xC8),		(0x0),		(TDATA_REG)},
	{"", (0), (0), (0)}
};

#endif /* defined(CONFIG_ARCH_SUN50IW3P1)*/


#if defined(CONFIG_ARCH_SUN50IW6)

#define ENABLE_CLK		(true)

struct temp_calculate_coefficent thermal_cal_coefficent[] = {
	[0] = {
		.down_limit = {(-210), (0xfff)},
		.up_limit = {(250), (0x000)},
		/*MUL_PARA DIV_PARA MINU_PARA */
		.nt_para = {
				{(1000), (14882), (2794000)},
				{(1000), (14882), (2794000)}
		}
	}
};

/**
 *       SUN50IW3  Thermal Sensor Register
 */
char *id_name_mapping[] = {
	"cpuc0",
	"gpu",
};

struct thermal_reg thermal_reg_init[] = {
	/* name			        address		value	    reg_type*/
	{"THS_CTRL_REG",		(0x00),		(0x01df002f),	(NORMAL_REG)},
	{"THS_EN_REG",			(0x04),		(0x3),		(ENABLE_REG)},
	{"THS_PER_REG",			(0x08),		(0x3a000),	(NORMAL_REG)},
	{"THS_DATA_INTC_REG",		(0x10),		(0x0),		(NO_INIT)},
	{"THS_SHUT_INTC_REG",		(0x14),		(0x3),		(NORMAL_REG)},
	{"THS_ALARM_INTC_REG",		(0x18),		(0x0),		(NO_INIT)},
	{"THS_DATA_INTS_REG",		(0x20),		(0x3),		(INT_STA_REG)},
	{"THS_SHUT_INTS_REG",		(0x24),		(0x3),		(INT_STA_REG)},
	{"THS_ALARMO_INTS_REG",		(0x28),		(0x3),		(INT_STA_REG)},
	{"THS_ALARM_INTS_REG",		(0x2C),		(0x3),		(INT_STA_REG)},
	{"THS_FILT_CTRL_REG",		(0x30),		(0x06),		(NORMAL_REG)},
	{"THS_0_ALARM_CTRL_REG",	(0x40),		(0x0),		(NO_INIT)},
	{"THS_1_ALARM_CTRL_REG",	(0x44),		(0x0),		(NO_INIT)},
	{"THS_0_1_SHUT_CTRL_REG",	(0x80),		(0x0),		(SHT_TMP_REG)},
	{"THS_0_1_CDATA_REG",		(0xA0),		(0x0),		(CDATA_REG)},
	{"THS_0_DATA_REG",		(0xC0),		(0x0),		(TDATA_REG)},
	{"THS_1_DATA_REG",		(0xC4),		(0x0),		(TDATA_REG)},
	{"", (0), (0), (0)}
};

#endif /* defined(CONFIG_ARCH_SUN50IW6P1)*/

#endif /* THERMAL_SENSOR_DRIVER_H */
