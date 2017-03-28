/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 */
/* MediaTek Inc. (C) 2010. All rights reserved.
 *
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER ON
 * AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
 * NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
 * SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
 * SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
 * THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
 * THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
 * CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
 * SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
 * CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
 * AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
 * OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
 * MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 * The following software/firmware and/or related documentation ("MediaTek Software")
 * have been modified by MediaTek Inc. All revisions are subject to any receiver's
 * applicable license agreements with MediaTek Inc.
 */

/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

#ifndef BUILD_LK
#include <linux/string.h>
#endif
#include "lcm_drv.h"

#ifdef BUILD_LK
	#include <platform/mt_gpio.h>
#elif defined(BUILD_UBOOT)
	#include <asm/arch/mt_gpio.h>
#else
	#include <mach/mt_gpio.h>
#endif
// ---------------------------------------------------------------------------
//  Local Constants
// ---------------------------------------------------------------------------
#define LCM_ID										0x9881

#define LCM_DSI_CMD_MODE								0

#define FRAME_WIDTH									(720)
#define FRAME_HEIGHT									(1280)
#define REGFLAG_DELAY             							0XAA
#define REGFLAG_END_OF_TABLE      						0xAB   // END OF REGISTERS MARKER

static LCM_UTIL_FUNCS lcm_util = {0};

#define SET_RESET_PIN(v)									(lcm_util.set_reset_pin((v)))

#define UDELAY(n) 											(lcm_util.udelay(n))
#define MDELAY(n) 											(lcm_util.mdelay(n))


// ---------------------------------------------------------------------------
//  Local Functions
// ---------------------------------------------------------------------------

#define dsi_set_cmdq_V2(cmd, count, ppara, force_update)				lcm_util.dsi_set_cmdq_V2(cmd, count, ppara, force_update)
#define dsi_set_cmdq(pdata, queue_size, force_update)					lcm_util.dsi_set_cmdq(pdata, queue_size, force_update)
#define wrtie_cmd(cmd)												lcm_util.dsi_write_cmd(cmd)
#define write_regs(addr, pdata, byte_nums)								lcm_util.dsi_write_regs(addr, pdata, byte_nums)
#define read_reg(cmd)												lcm_util.dsi_dcs_read_lcm_reg(cmd)
#define read_reg_v2(cmd, buffer, buffer_size)							lcm_util.dsi_dcs_read_lcm_reg_v2(cmd, buffer, buffer_size)    

struct LCM_setting_table {
    unsigned cmd;
    unsigned char count;
    unsigned char para_list[64];
};



static struct LCM_setting_table lcm_initialization_setting[] = {
	//CMD_Page 7
//JD9367 initial code
//Page0
{0xE0,1,{0x00}},
//--- PASSWORD  ----//
{0xE1,1,{0x93}},
{0xE2,1,{0x65}},
{0xE3,1,{0xF8}},

//--- Page1  ----//
{0xE0,1,{0x01}},

//Set VCOM
{0x00,1,{0x00}},
{0x01,1,{0xD6}},
//Set VCOM_Reverse
{0x03,1,{0x00}},
{0x04,1,{0xD6}},

//Set Gamma Power,1,{ VGMP,1,{VGMN,1,{VGSP,1,{VGSN
{0x17,1,{0x00}},
{0x18,1,{0xC7}},
{0x19,1,{0x01}},
{0x1A,1,{0x00}},
{0x1B,1,{0xC7}},
{0x1C,1,{0x01}},

//Set Gate Power
{0x1F,1,{0x69}},
{0x20,1,{0x2D}},
{0x21,1,{0x2D}},
{0x22,1,{0x0E}},
{0x26,1,{0xF1}},

//SetPanel
{0x37,1,{0x09}},

//SET RGBCYC
{0x38,1,{0x04}},
{0x39,1,{0x0C}},
{0x3A,1,{0x18}},
{0x3C,1,{0x78}},

//Set TCON
{0x40,1,{0x04}},
{0x41,1,{0xA0}},

//--- power voltage  ----//
{0x55,1,{0x01}},	//JD5001
{0x56,1,{0x01}},
{0x57,1,{0xA9}},
{0x58,1,{0x0A}},
{0x59,1,{0x2A}},
{0x5A,1,{0x1B}},	//VGH = 12.61V
{0x5B,1,{0x18}},	//VGL = -11.6V
{0x5C,1,{0x16}},	

//--- Gamma  ----//    g2.5
{0x5D,1,{0x7F}},//0x7F
{0x5E,1,{0x71}},//0x70
{0x5F,1,{0x65}},//0x63
{0x60,1,{0x5B}},//0x58
{0x61,1,{0x59}},//0x54
{0x62,1,{0x4A}},//0x43
{0x63,1,{0x4C}},//0x45
{0x64,1,{0x34}},//0x2C
{0x65,1,{0x48}},//0x40
{0x66,1,{0x44}},//0x3B
{0x67,1,{0x40}},//0x38
{0x68,1,{0x5D}},//0x52
{0x69,1,{0x48}},//0x40
{0x6A,1,{0x4D}},//0x44
{0x6B,1,{0x3F}},//0x37
{0x6C,1,{0x37}},//0x31
{0x6D,1,{0x29}},//0x25
{0x6E,1,{0x18}},//0x16
{0x6F,1,{0x00}},//0x00
{0x70,1,{0x7F}},//0x7F
{0x71,1,{0x71}},//0x70
{0x72,1,{0x65}},//0x63
{0x73,1,{0x5B}},//0x58
{0x74,1,{0x59}},//0x54
{0x75,1,{0x4A}},//0x43
{0x76,1,{0x4C}},//0x45
{0x77,1,{0x34}},//0x2C
{0x78,1,{0x48}},//0x40
{0x79,1,{0x44}},//0x3B
{0x7A,1,{0x40}},//0x38
{0x7B,1,{0x5D}},//0x52
{0x7C,1,{0x48}},//0x40
{0x7D,1,{0x4D}},//0x44
{0x7E,1,{0x3F}},//0x37
{0x7F,1,{0x37}},//0x31
{0x80,1,{0x29}},//0x25
{0x81,1,{0x18}},//0x16
{0x82,1,{0x00}},//0x00

//Page2,1,{ for GIP
{0xE0,1,{0x02}},

//GIP_L Pin mapping
{0x00,1,{0x1F}},
{0x01,1,{0x1F}},
{0x02,1,{0x1F}},
{0x03,1,{0x1F}},
{0x04,1,{0x1F}},
{0x05,1,{0x1F}},
{0x06,1,{0x1F}},
{0x07,1,{0x1F}},
{0x08,1,{0x1F}},
{0x09,1,{0x1F}},
{0x0A,1,{0x1F}},
{0x0B,1,{0x04}},
{0x0C,1,{0x1F}},
{0x0D,1,{0x0A}},
{0x0E,1,{0x08}},
{0x0F,1,{0x06}},
{0x10,1,{0x00}},
{0x11,1,{0x02}},
{0x12,1,{0x1F}},
{0x13,1,{0x1F}},
{0x14,1,{0x1F}},
{0x15,1,{0x1F}},

//GIP_R Pin mapping
{0x16,1,{0x1F}},
{0x17,1,{0x1F}},
{0x18,1,{0x1F}},
{0x19,1,{0x1F}},
{0x1A,1,{0x1F}},
{0x1B,1,{0x1F}},
{0x1C,1,{0x1F}},
{0x1D,1,{0x1F}},
{0x1E,1,{0x1F}},
{0x1F,1,{0x1F}},
{0x20,1,{0x1F}},
{0x21,1,{0x05}},
{0x22,1,{0x1F}},
{0x23,1,{0x0B}},
{0x24,1,{0x09}},
{0x25,1,{0x07}},
{0x26,1,{0x01}},
{0x27,1,{0x03}},
{0x28,1,{0x1F}},
{0x29,1,{0x1F}},
{0x2A,1,{0x1F}},
{0x2B,1,{0x1F}},

//GIP Timing
{0x58,1,{0x40}},
{0x59,1,{0x00}},
{0x5A,1,{0x00}},
{0x5B,1,{0x30}},
{0x5C,1,{0x05}},
{0x5D,1,{0x30}},
{0x5E,1,{0x01}},
{0x5F,1,{0x02}},
{0x60,1,{0x00}},
{0x61,1,{0x01}},
{0x62,1,{0x02}},
{0x63,1,{0x03}},
{0x64,1,{0x6B}},
{0x65,1,{0x00}},
{0x66,1,{0x00}},
{0x67,1,{0x73}},
{0x68,1,{0x07}},
{0x69,1,{0x03}},
{0x6A,1,{0x6B}},
{0x6B,1,{0x05}},
{0x6C,1,{0x00}},
{0x6D,1,{0x04}},
{0x6E,1,{0x04}},
{0x6F,1,{0x88}},
{0x70,1,{0x00}},
{0x71,1,{0x00}},
{0x72,1,{0x06}},
{0x73,1,{0x7B}},
{0x74,1,{0x00}},
{0x75,1,{0x00}},
{0x76,1,{0x00}},
{0x77,1,{0x5D}},
{0x78,1,{0x17}},
{0x79,1,{0x1F}},
{0x7A,1,{0x00}},
{0x7B,1,{0x00}},
{0x7C,1,{0x00}},
{0x7D,1,{0x03}},
{0x7E,1,{0x7B}},

//Page4
{0xE0,1,{0x04}},
{0x2B,1,{0x2B}},
{0x2E,1,{0x44}},

//Page0
{0xE0,1,{0x00}},
{0xE6,1,{0x02}},
{0xE7,1,{0x02}},
{0x11,1,{0x00}},                 // Sleep-Out

{REGFLAG_DELAY,120,{}},

{0x29,1,{0x00}},                 // Display On

{REGFLAG_DELAY,10,{}},

//--- PASSWORD  ----//
{0xE0,1,{0x00}},
{0xE1,1,{0x09}},
{0xE2,1,{0xB1}},
{0xE3,1,{0x7F}},

{REGFLAG_END_OF_TABLE,0x00,{}}
};

static struct LCM_setting_table lcm_sleep_out_setting[] = {
	// Sleep Out
	{0x11, 1, {0x00}},
	{REGFLAG_DELAY, 20, {}},

	// Display ON
	{0x29, 1, {0x00}},
	{REGFLAG_DELAY, 120, {}},
	{REGFLAG_END_OF_TABLE, 0x00, {}}
};


static struct LCM_setting_table lcm_sleep_mode_in_setting[] = {
	// Display off sequence
	{0x28, 1, {0x00}},
	{REGFLAG_DELAY, 200, {}},

	// Sleep Mode On
	{0x10, 1, {0x00}},
	{REGFLAG_DELAY, 120, {}},
	{REGFLAG_END_OF_TABLE, 0x00, {}}
};
static struct LCM_setting_table lcm_compare_id_setting[] = {
	// Display off sequence
	{0xF0,	5,	{0x55, 0xaa, 0x52,0x08,0x00}},
	{REGFLAG_DELAY, 10, {}},

	{REGFLAG_END_OF_TABLE, 0x00, {}}
};

static struct LCM_setting_table page1_select[] = {
	//CMD_Page 1
	{0xFF, 3,{0x98,0x81,0x01}},
	{REGFLAG_END_OF_TABLE, 0x00, {}}
};

static void push_table(struct LCM_setting_table *table, unsigned int count, unsigned char force_update)
{
	unsigned int i;

	for(i = 0; i < count; i++) {
		
		unsigned cmd;
		cmd = table[i].cmd;
		
	switch (cmd) {
			
		case REGFLAG_DELAY :
 			MDELAY(table[i].count);
   			break;
				
		case REGFLAG_END_OF_TABLE :
   			break;
				
		default:
			dsi_set_cmdq_V2(cmd, table[i].count, table[i].para_list, force_update);
			MDELAY(2);
		}
	}
	
}


static void init_lcm_registers(void)
{
	unsigned int data_array[16];
}
// ---------------------------------------------------------------------------
//  LCM Driver Implementations
// ---------------------------------------------------------------------------

static void lcm_set_util_funcs(const LCM_UTIL_FUNCS *util)
{
	memcpy(&lcm_util, util, sizeof(LCM_UTIL_FUNCS));
}

static void lcm_get_params(LCM_PARAMS *params)
{
	memset(params, 0, sizeof(LCM_PARAMS));

	params->type   = LCM_TYPE_DSI;

	params->width  = FRAME_WIDTH;
	params->height = FRAME_HEIGHT;

#if (LCM_DSI_CMD_MODE)
	params->dsi.mode   = CMD_MODE;
	params->dsi.switch_mode = SYNC_PULSE_VDO_MODE;//SYNC_EVENT_VDO_MODE;
#else
    params->dsi.mode   = SYNC_PULSE_VDO_MODE;//SYNC_EVENT_VDO_MODE;
	params->dsi.switch_mode = CMD_MODE;
#endif
	params->dsi.switch_mode_enable = 0;

	// DSI
	/* Command mode setting */
	params->dsi.LANE_NUM				= LCM_FOUR_LANE;
	//The following defined the fomat for data coming from LCD engine.
	params->dsi.data_format.color_order 	= LCM_COLOR_ORDER_RGB;
	params->dsi.data_format.trans_seq   	= LCM_DSI_TRANS_SEQ_MSB_FIRST;
	params->dsi.data_format.padding     	= LCM_DSI_PADDING_ON_LSB;
	params->dsi.data_format.format      		= LCM_DSI_FORMAT_RGB888;

	// Highly depends on LCD driver capability.
	params->dsi.packet_size=256;
	//video mode timing

	params->dsi.PS=LCM_PACKED_PS_24BIT_RGB888;

	params->dsi.vertical_sync_active				= 4;
	params->dsi.vertical_backporch					= 8;
	params->dsi.vertical_frontporch 				= 12;
	params->dsi.vertical_active_line				= FRAME_HEIGHT; 

	params->dsi.horizontal_sync_active				= 10;
	params->dsi.horizontal_backporch				= 50;
	params->dsi.horizontal_frontporch				= 50;
	params->dsi.horizontal_active_pixel 				= FRAME_WIDTH;
    	//params->dsi.ssc_disable							= 1;
#ifndef FPGA_EARLY_PORTING
#if (LCM_DSI_CMD_MODE)
	params->dsi.PLL_CLOCK = 200; //this value must be in MTK suggested table
#else
	params->dsi.PLL_CLOCK = 205; //this value must be in MTK suggested table
#endif
#else
	params->dsi.pll_div1 = 0;
	params->dsi.pll_div2 = 0;
	params->dsi.fbk_div = 0x1;
	/*
	params->dsi.pll_div1=1;		// div1=0,1,2,3;div1_real=1,2,4,4 ----0: 546Mbps  1:273Mbps
	params->dsi.pll_div2=0; 		// div2=0,1,2,3;div1_real=1,2,4,4	
	params->dsi.fbk_div =15;   	 // fref=26MHz, fvco=fref*(fbk_div+1)*2/(div1_real*div2_real)
	*/
#endif

	params->dsi.clk_lp_per_line_enable = 0;
	params->dsi.esd_check_enable = 0;// 1;
	params->dsi.customization_esd_check_enable = 0;
	params->dsi.lcm_esd_check_table[0].cmd          = 0;//0x53;
	params->dsi.lcm_esd_check_table[0].count        = 0;// 1;
	params->dsi.lcm_esd_check_table[0].para_list[0] = 0x24;

}

static void lcm_init(void)
{
	unsigned int data_array[16];
	static int count = 0;

	SET_RESET_PIN(1);
	MDELAY(1);
	SET_RESET_PIN(0);
	MDELAY(20);
	SET_RESET_PIN(1);
	MDELAY(20);
	
//	lcm_initialization_setting[6].para_list[0]++;
//	lcm_initialization_setting[8].para_list[0]++;
//#ifdef BUILD_LK
//#else
//	printk("sky lcm_initialization_setting[6].para_list[0] = 0x%08x\n", lcm_initialization_setting[6].para_list[0]);
//#endif	
	push_table(lcm_initialization_setting, sizeof(lcm_initialization_setting) / sizeof(struct LCM_setting_table), 1);
 
}



static void lcm_suspend(void)
{
    unsigned int data_array[16];
    MDELAY(20);
    data_array[0]=0x00E01500;
    dsi_set_cmdq(&data_array,1,1);
    
    data_array[0]=0x93E11500;
    dsi_set_cmdq(&data_array,1,1);
    
    data_array[0]=0x65E21500;
    dsi_set_cmdq(&data_array,1,1); 
    
    data_array[0]=0xF8E31500;
    dsi_set_cmdq(&data_array,1,1);
    
    data_array[0]=0x00280500;
    dsi_set_cmdq(&data_array,1,1);
    MDELAY(20);
    data_array[0]=0x00100500;
    dsi_set_cmdq(&data_array,1,1);
    MDELAY(150);
    

    data_array[0]=0x00E01500;
    dsi_set_cmdq(&data_array,1,1);
    
    data_array[0]=0x09E11500;
    dsi_set_cmdq(&data_array,1,1);
    
    data_array[0]=0xB1E21500;
    dsi_set_cmdq(&data_array,1,1); 
    
    data_array[0]=0x7FE31500;
    dsi_set_cmdq(&data_array,1,1);

	SET_RESET_PIN(1);	
	SET_RESET_PIN(0);
	MDELAY(10); // 1ms

	SET_RESET_PIN(1);
    MDELAY(120);

}

static unsigned int lcm_compare_id(void)
{
    int array[4];
    char buffer[5];
    char id_high=0;
    char id_low=0;
    int id=0;
    
    SET_RESET_PIN(1);
    MDELAY(10);
	  SET_RESET_PIN(0);
    MDELAY(20);
	  SET_RESET_PIN(1);
    MDELAY(50);

    array[0] = 0x00023700;// read id return two byte,version and id
    dsi_set_cmdq(array, 1, 1);
    read_reg_v2(0x04,buffer, 2);

    id_high = buffer[0]; 
    id_low = buffer[1];
    id = (id_high<<8)|id_low; 

    #ifdef BUILD_LK
    printf("luke: jd9367 %s %d, id = 0x%08x\n", __func__,__LINE__, id);
    #else

    printk("luke: jd9367 %s %d, id = 0x%08x\n", __func__,__LINE__, id);
    #endif
  
    return (id == 0x9367) ?1:0;
}


static void lcm_resume(void)
{
	lcm_init();

	//push_table(lcm_sleep_out_setting, sizeof(lcm_sleep_out_setting) / sizeof(struct LCM_setting_table), 1);

}


static void lcm_update(unsigned int x, unsigned int y,
                       unsigned int width, unsigned int height)
{
	unsigned int x0 = x;
	unsigned int y0 = y;
	unsigned int x1 = x0 + width - 1;
	unsigned int y1 = y0 + height - 1;

	unsigned char x0_MSB = ((x0>>8)&0xFF);
	unsigned char x0_LSB = (x0&0xFF);
	unsigned char x1_MSB = ((x1>>8)&0xFF);
	unsigned char x1_LSB = (x1&0xFF);
	unsigned char y0_MSB = ((y0>>8)&0xFF);
	unsigned char y0_LSB = (y0&0xFF);
	unsigned char y1_MSB = ((y1>>8)&0xFF);
	unsigned char y1_LSB = (y1&0xFF);

	unsigned int data_array[16];

	data_array[0]= 0x00053902;
	data_array[1]= (x1_MSB<<24)|(x0_LSB<<16)|(x0_MSB<<8)|0x2a;
	data_array[2]= (x1_LSB);
	dsi_set_cmdq(data_array, 3, 1);
	
	data_array[0]= 0x00053902;
	data_array[1]= (y1_MSB<<24)|(y0_LSB<<16)|(y0_MSB<<8)|0x2b;
	data_array[2]= (y1_LSB);
	dsi_set_cmdq(data_array, 3, 1);

	data_array[0]= 0x002c3909;
	dsi_set_cmdq(data_array, 1, 0);

}

LCM_DRIVER jd9367_hd720_dsi_vdo_lcm_drv = 
{
	.name				= "jd9367_hd720_dsi_vdo",
	.set_util_funcs			= lcm_set_util_funcs,
	.compare_id			= lcm_compare_id,
	.get_params			= lcm_get_params,
	.init				= lcm_init,
	.suspend			= lcm_suspend,
	.resume         		= lcm_resume,
#if (LCM_DSI_CMD_MODE)
	.update				= lcm_update,
#endif
};
