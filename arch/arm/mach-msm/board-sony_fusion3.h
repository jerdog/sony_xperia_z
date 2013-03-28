/* Copyright (C) 2012 Sony Mobile Communications AB.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#ifndef _ARCH_ARM_MACH_MSM_BOARD_SONY_FUSION3
#define _ARCH_ARM_MACH_MSM_BOARD_SONY_FUSION3

struct device;
struct regulator;

/*
 * sensor_power() should be used for powering the devices
 * connected to L9 (Vdd) and LVS4 (Vio). It takes care of
 * HW restrictions.
 */
extern int sensor_power(bool enable, struct device *dev,
		struct regulator **vdd, struct regulator **vio,
		const char *id_vdd, const char *id_vio);

enum sony_hw {
	HW_UNKNOWN,
	HW_YUGA_MAKI,
};

#define HW_REV_FUTURE	INT_MAX

enum yuga_hw_rev {
	HW_REV_YUGA_MAKI_DP0,
	HW_REV_YUGA_MAKI_DP1,
	HW_REV_YUGA_MAKI_DP11,
	HW_REV_YUGA_MAKI_SP1,
	HW_REV_YUGA_MAKI_SP11,
	HW_REV_YUGA_MAKI_AP1,
	HW_REV_YUGA_MAKI_AP11,
	HW_REV_YUGA_MAKI_TP1,
	HW_REV_YUGA_MAKI_PQ,
	HW_REV_YUGA_MAKI_PQ_HVM,
	HW_REV_YUGA_FUTURE = HW_REV_FUTURE,
};

void __init sony_set_hw_revision(void);
int sony_hw_rev(void);
int sony_hw(void);

#ifdef CONFIG_LEDS_LM3533
#include <linux/leds-lm3533_ng.h>
extern struct lm3533_platform_data lm3533_pdata;
#endif

extern int usb_phy_init_seq_host[];

#endif
