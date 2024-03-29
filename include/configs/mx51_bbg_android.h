/*
 * Copyright (C) 2007, Guennadi Liakhovetski <lg@denx.de>
 *
 * (C) Copyright 2009-2011 Freescale Semiconductor, Inc.
 *
 * Configuration settings for the MX51-3Stack Freescale board.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#ifndef __CONFIG_H
#define __CONFIG_H

#include <asm/arch/mx51.h>

 /* High Level Configuration Options */
#define CONFIG_ARMV7		1	/* This is armv7 Cortex-A8 CPU core */
#define CONFIG_SYS_APCS_GNU

#define CONFIG_MXC		1
#define CONFIG_MX51_BBG		1	/* in a mx51 */
#define CONFIG_FLASH_HEADER	1
#define CONFIG_FLASH_HEADER_OFFSET 0x400
#define CONFIG_FLASH_HEADER_BARKER 0xB1

#define CONFIG_ARCH_CPU_INIT
#define CONFIG_ARCH_MMU

#define CONFIG_SKIP_RELOCATE_UBOOT

#define CONFIG_MX51_HCLK_FREQ	24000000	/* RedBoot says 26MHz */

#define CONFIG_DISPLAY_CPUINFO
#define CONFIG_DISPLAY_BOARDINFO

#define CONFIG_SYS_64BIT_VSPRINTF

#define BOARD_LATE_INIT
/*
 * Disabled for now due to build problems under Debian and a significant
 * increase in the final file size: 144260 vs. 109536 Bytes.
 */

#define CONFIG_CMDLINE_TAG		1	/* enable passing of ATAGs */
#define CONFIG_REVISION_TAG		1
#define CONFIG_SETUP_MEMORY_TAGS	1
#define CONFIG_INITRD_TAG		1

/*
 * Size of malloc() pool
 */
#define CONFIG_SYS_MALLOC_LEN		(CONFIG_ENV_SIZE + 2 * 1024 * 1024)
/* size in bytes reserved for initial data */
#define CONFIG_SYS_GBL_DATA_SIZE	128

/*
 * Hardware drivers
 */
#define CONFIG_MXC_UART 1
#define CONFIG_UART_BASE_ADDR   UART1_BASE_ADDR


#define CONFIG_CMD_PING
#define CONFIG_CMD_DHCP
#define CONFIG_BOOTP_SUBNETMASK
#define CONFIG_BOOTP_GATEWAY
#define CONFIG_BOOTP_DNS
#define CONFIG_CMD_MII
#define CONFIG_CMD_NET
#define CONFIG_NET_RETRY_COUNT	100
#define CONFIG_CMD_I2C

/*
 * Android support Configs
 */
#include <asm/mxc_key_defs.h>

#define CONFIG_USB_DEVICE
#define CONFIG_FASTBOOT		1
#define CONFIG_IMX_UDC		1
#define CONFIG_FASTBOOT_STORAGE_EMMC_SATA
#define CONFIG_FASTBOOT_VENDOR_ID	0xbb4
#define CONFIG_FASTBOOT_PRODUCT_ID	0xc01
#define CONFIG_FASTBOOT_BCD_DEVICE	0x311
#define CONFIG_FASTBOOT_MANUFACTURER_STR  "Freescale"
#define CONFIG_FASTBOOT_PRODUCT_NAME_STR "i.mx51"
#define CONFIG_FASTBOOT_CONFIGURATION_STR  "Android fastboot"
#define CONFIG_FASTBOOT_INTERFACE_STR    "Android fastboot"
#define CONFIG_FASTBOOT_SERIAL_NUM	 "12345"
#define CONFIG_FASTBOOT_TRANSFER_BUF	 0xA0000000
#define CONFIG_FASTBOOT_TRANSFER_BUF_SIZE 0x8000000 /* 128M byte */

#define CONFIG_ANDROID_RECOVERY
#define CONFIG_POWER_KEY	KEY_F3
#define CONFIG_HOME_KEY	KEY_F1

#define CONFIG_MTD_DEVICE
#define CONFIG_MTD_PARTITIONS


#define CONFIG_MXC_KPD
#define CONFIG_MXC_KEYMAPPING \
	{	\
		KEY_1, KEY_2, KEY_3, KEY_F1, KEY_UP, KEY_F2, \
		KEY_4, KEY_5, KEY_6, KEY_LEFT, KEY_SELECT, KEY_RIGHT, \
		KEY_7, KEY_8, KEY_9, KEY_F3, KEY_DOWN, KEY_F4, \
		KEY_0, KEY_OK, KEY_ESC, KEY_ENTER, KEY_MENU, KEY_BACK, \
	}
#define CONFIG_MXC_KPD_COLMAX 6
#define CONFIG_MXC_KPD_ROWMAX 4
#define CONFIG_ANDROID_RECOVERY_BOOTARGS_MMC \
	"setenv bootargs ${bootargs} init=/init root=/dev/mmcblk0p4 " \
	"rootfs=ext4 di1_primary"
#define CONFIG_ANDROID_RECOVERY_BOOTCMD_MMC  \
	"run bootargs_base bootargs_android_recovery;"	\
	"mmc read 0 ${loadaddr} 0x800 0x2000;bootm"
#define CONFIG_ANDROID_RECOVERY_CMD_FILE "/recovery/command"

#define CONFIG_ANDROID_SYSTEM_PARTITION_MMC 2
#define CONFIG_ANDROID_RECOVERY_PARTITION_MMC 4
#define CONFIG_ANDROID_CACHE_PARTITION_MMC 6

/* allow to overwrite serial and ethaddr */
#define CONFIG_ENV_OVERWRITE
#define CONFIG_CONS_INDEX		1
#define CONFIG_BAUDRATE			115200
#define CONFIG_SYS_BAUDRATE_TABLE	{9600, 19200, 38400, 57600, 115200}

/***********************************************************
 * Command definition
 ***********************************************************/

#include <config_cmd_default.h>

#define CONFIG_CMD_PING
#define CONFIG_CMD_DHCP
/* Enable below configure when supporting nand */
/* #define CONFIG_CMD_NAND */
#define CONFIG_CMD_MMC
#define CONFIG_CMD_ENV

#undef CONFIG_CMD_IMLS

#define CONFIG_BOOTDELAY	1

#define CONFIG_PRIME	"FEC0"

#define CONFIG_LOADADDR		0x90800000	/* loadaddr env var */
#define CONFIG_RD_LOADADDR	(CONFIG_LOADADDR + 0x400000)

#define	CONFIG_EXTRA_ENV_SETTINGS					\
		"netdev=eth0\0"						\
		"ethprime=FEC0\0"					\
		"uboot_addr=0xa0000000\0"				\
		"uboot=u-boot.bin\0"			\
		"kernel=uImage\0"				\
		"rd_loadaddr=0x90C00000\0"	\
		"nfsroot=/opt/eldk/arm\0"				\
		"bootargs_base=setenv bootargs console=ttymxc0,115200 video=mxcdi0fb:LVDS666 gpu_memory=16M\0"\
		"bootargs_nfs=setenv bootargs ${bootargs} root=/dev/nfs " \
			"ip=dhcp nfsroot=${serverip}:${nfsroot},v3,tcp\0"\
		"bootcmd_net=run bootargs_base bootargs_nfs; "		\
			"tftpboot ${loadaddr} ${kernel}; bootm\0"	\
		"prg_uboot=tftpboot ${loadaddr} ${uboot}; "		\
			"protect off ${uboot_addr} 0xa003ffff; "	\
			"erase ${uboot_addr} 0xa003ffff; "		\
			"cp.b ${loadaddr} ${uboot_addr} ${filesize}; "	\
			"setenv filesize; saveenv\0"			\
		"bootcmd=run bootcmd_SD \0"				\
		"bootcmd_SD=run bootargs_base bootargs_android;"	\
		     "mmc read 0 ${loadaddr} 0x800 0x2000;"		\
		     "mmc read 0 ${rd_loadaddr} 0x2800 0x258;"		\
		     "bootm ${loadaddr} ${rd_loadaddr}\0"		\
		"bootargs_android=setenv bootargs ${bootargs}  "	\
		     "androidboot.console=ttymxc0 init=/init "		\
		     " \0"			\
		"bootcmd_android_recovery=run bootargs_base"		\
		     " bootargs_android_recovery;"			\
		     "mmc read 0 ${loadaddr} 0x800 0x2000;bootm\0"	\
		"bootargs_android_recovery=setenv bootargs ${bootargs}" \
		     " init=/init root=/dev/mmcblk0p4 rootfs=ext4"	\
		     " di1_primary \0"					\




/*Support LAN9217*/
/*
#define CONFIG_SMC911X	1
#define CONFIG_SMC911X_16_BIT 1
#define CONFIG_SMC911X_BASE mx51_io_base_addr
*/

/*
 * The MX51 3stack board seems to have a hardware "peculiarity" confirmed under
 * U-Boot, RedBoot and Linux: the ethernet Rx signal is reaching the CS8900A
 * controller inverted. The controller is capable of detecting and correcting
 * this, but it needs 4 network packets for that. Which means, at startup, you
 * will not receive answers to the first 4 packest, unless there have been some
 * broadcasts on the network, or your board is on a hub. Reducing the ARP
 * timeout from default 5 seconds to 200ms we speed up the initial TFTP
 * transfer, should the user wish one, significantly.
 */
#define CONFIG_ARP_TIMEOUT	200UL

/*
 * Miscellaneous configurable options
 */
#define CONFIG_SYS_LONGHELP		/* undef to save memory */
#define CONFIG_SYS_PROMPT		"BBG U-Boot > "
#define CONFIG_AUTO_COMPLETE
#define CONFIG_SYS_CBSIZE		256	/* Console I/O Buffer Size */
/* Print Buffer Size */
#define CONFIG_SYS_PBSIZE (CONFIG_SYS_CBSIZE + sizeof(CONFIG_SYS_PROMPT) + 16)
#define CONFIG_SYS_MAXARGS	16	/* max number of command args */
#define CONFIG_SYS_BARGSIZE CONFIG_SYS_CBSIZE /* Boot Argument Buffer Size */

#define CONFIG_SYS_MEMTEST_START	0	/* memtest works on */
#define CONFIG_SYS_MEMTEST_END		0x10000

#undef	CONFIG_SYS_CLKS_IN_HZ		/* everything, incl board info, in Hz */

#define CONFIG_SYS_LOAD_ADDR		CONFIG_LOADADDR

#define CONFIG_SYS_HZ				1000

#define CONFIG_CMDLINE_EDITING	1

/*
 * Eth Configs
 */
#define CONFIG_HAS_ETH1
#define CONFIG_NET_MULTI 1
#define CONFIG_MXC_FEC
#define CONFIG_MII
#define CONFIG_DISCOVER_PHY

#define CONFIG_FEC0_IOBASE	FEC_BASE_ADDR
#define CONFIG_FEC0_PINMUX	-1
#define CONFIG_FEC0_PHY_ADDR	0x1F
#define CONFIG_FEC0_MIIBASE 	-1

/*
 * SPI Configs
 * */
#define CONFIG_FSL_SF		1
#define CONFIG_CMD_SPI
#define CONFIG_CMD_SF
#define CONFIG_SPI_FLASH_IMX_ATMEL	1
#define CONFIG_SPI_FLASH_CS	1
#define CONFIG_IMX_ECSPI
#define CONFIG_IMX_SPI_PMIC
#define CONFIG_IMX_SPI_PMIC_CS 0
#define IMX_CSPI_VER_2_3        1

#define MAX_SPI_BYTES		(64 * 4)

/*
 * MMC Configs
 * */
#ifdef CONFIG_CMD_MMC
	#define CONFIG_MMC				1
	#define CONFIG_GENERIC_MMC
	#define CONFIG_IMX_MMC
	#define CONFIG_SYS_FSL_ESDHC_NUM	2
	#define CONFIG_SYS_FSL_ESDHC_ADDR       0
	#define CONFIG_SYS_MMC_ENV_DEV	0
	#define CONFIG_DOS_PARTITION	1
	#define CONFIG_CMD_FAT		1
	#define CONFIG_CMD_EXT2		1
	#define CONFIG_DYNAMIC_MMC_DEVNO
#endif

/*
 * I2C Configs
 */
#define CONFIG_HARD_I2C         1
#define CONFIG_I2C_MXC          1
#define CONFIG_SYS_I2C_PORT             I2C1_BASE_ADDR
#define CONFIG_SYS_I2C_SPEED            400000
#define CONFIG_SYS_I2C_SLAVE            0xfe

/*-----------------------------------------------------------------------
 * Stack sizes
 *
 * The stack sizes are set up in start.S using the settings below
 */
#define CONFIG_STACKSIZE	(128 * 1024)	/* regular stack */

/*-----------------------------------------------------------------------
 * Physical Memory Map
 */
#define CONFIG_NR_DRAM_BANKS	1
#define PHYS_SDRAM_1		CSD0_BASE_ADDR
#define PHYS_SDRAM_1_SIZE	(512 * 1024 * 1024)
#define iomem_valid_addr(addr, size) \
	(addr >= PHYS_SDRAM_1 && addr <= (PHYS_SDRAM_1 + PHYS_SDRAM_1_SIZE))

/*-----------------------------------------------------------------------
 * FLASH and environment organization
 */
#define CONFIG_SYS_NO_FLASH

/*-----------------------------------------------------------------------
 * NAND FLASH driver setup
 */
#define NAND_MAX_CHIPS         8
#define CONFIG_SYS_MAX_NAND_DEVICE    1
#define CONFIG_SYS_NAND_BASE          0x40000000

/* Monitor at beginning of flash */
/* #define CONFIG_FSL_ENV_IN_SF */
#define CONFIG_FSL_ENV_IN_MMC
/* #define CONFIG_FSL_ENV_IN_NAND */

#define CONFIG_ENV_SECT_SIZE    (128 * 1024)
#define CONFIG_ENV_SIZE         CONFIG_ENV_SECT_SIZE

#if defined(CONFIG_FSL_ENV_IN_NAND)
	#define CONFIG_ENV_IS_IN_NAND 1
	#define CONFIG_ENV_OFFSET	0x100000
#elif defined(CONFIG_FSL_ENV_IN_MMC)
	#define CONFIG_ENV_IS_IN_MMC	1
	#define CONFIG_ENV_OFFSET	(768 * 1024)
#elif defined(CONFIG_FSL_ENV_IN_SF)
	#define CONFIG_ENV_IS_IN_SPI_FLASH	1
	#define CONFIG_ENV_SPI_CS		1
	#define CONFIG_ENV_OFFSET       (768 * 1024)
#else
	#define CONFIG_ENV_IS_NOWHERE	1
#endif
/*
 * JFFS2 partitions
 */
#undef CONFIG_JFFS2_CMDLINE
#define CONFIG_JFFS2_DEV	"nand0"

/*#ifdef CONFIG_SPLASH_SCREEN*/
	/*
	 * Framebuffer and LCD
	 */
	#define CONFIG_LCD
	#define CONFIG_VIDEO_MX5
	#define CONFIG_MXC_HSC
	#define CONFIG_IPU_CLKRATE	133000000
	#define CONFIG_SYS_CONSOLE_ENV_OVERWRITE
	#define CONFIG_SYS_CONSOLE_OVERWRITE_ROUTINE
	#define CONFIG_SYS_CONSOLE_IS_IN_ENV
	#define LCD_BPP		LCD_COLOR16
	#define CONFIG_CMD_BMP
	#define CONFIG_BMP_8BPP
	#define CONFIG_FB_BASE	(TEXT_BASE + 0x300000)
	#define CONFIG_SPLASH_SCREEN_ALIGN
	#define CONFIG_SYS_WHITE_ON_BLACK
/*#endif*/
#endif				/* __CONFIG_H */
