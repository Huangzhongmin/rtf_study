#ifndef _EAST_RFM_INDEX_H__
#define _EAST_RFM_INDEX_H_

#include <string>
#include <unordered_map>
#define OFFSET_1 0x0
#define OFFSET_2 0x2000
std::unordered_map<std::string,int> east_rfm_index = {
//OFFSET1
	{"stoptime",OFFSET1+0},
	{"current_time",OFFSET1+1},
	{"IC1",OFFSET1+2},	
	{"IC2",OFFSET1+3},	
	{"PS1",OFFSET1+4},	
	{"PS2",OFFSET1+5},	
	{"PS3",OFFSET1+6},	
	{"PS4",OFFSET1+7},	
	{"PS5",OFFSET1+8},	
	{"PS6",OFFSET1+9},	
	{"PS7",OFFSET1+10},	
	{"PS8",OFFSET1+11},	
	{"PS9",OFFSET1+12},	
	{"PS10",OFFSET1+13},	
	{"PS11",OFFSET1+14},	
	{"PS12",OFFSET1+15},	
	{"power_trip_flag",OFFSET1+16},	
	{"IC_mode",OFFSET1+17},	
	{"RMP_mode",OFFSET1+18},	
	{"RMP_PS1",OFFSET1+19},	
	{"RMP_PS2",OFFSET1+20},	
	{"RMP_PS3",OFFSET1+21},	
	{"RMP_PS4",OFFSET1+22},	
	{"RMP_PS5",OFFSET1+23},	
	{"RMP_PS6",OFFSET1+24},	
	{"RMP_PS7",OFFSET1+25},	
	{"RMP_PS8",OFFSET1+26},	
//puffing command
	{"VJHPEV2",OFFSET1+27},	
	{"VJHPEV3",OFFSET1+28},	
	{"VOUPEV1",OFFSET1+29},	
	{"VOUPEV2",OFFSET1+30},	
	{"VOUPEV3",OFFSET1+31},	
	{"VOUPEV4",OFFSET1+32},	
	{"VODPEV1",OFFSET1+33},	
	{"VODPEV2",OFFSET1+34},	
	{"VODPEV3",OFFSET1+35},	
	{"VCDPEV1",OFFSET1+36},	
	{"VCDPEV2",OFFSET1+37},	
	{"VSMBI1",OFFSET1+38},	
	{"VSMBI2",OFFSET1+39},	
	{"VSMBI3",OFFSET1+40},	
	{"VJHPEV4",OFFSET1+41},	
	{"VJHPEV5",OFFSET1+42},	
	{"VJHPEV6",OFFSET1+43},	
	{"VJHPEV7",OFFSET1+44},	
	{"VPI20",OFFSET1+45},	
	{"VPI50L",OFFSET1+46},	
	{"VPI50R",OFFSET1+47},	
	{"VKHPEV1",OFFSET1+48},	
	{"VKHPEV2",OFFSET1+49},	
	{"VDHPEV1",OFFSET1+50},	
	{"VDHPEV2",OFFSET1+51},	
	{"VDMV",OFFSET1+52},	
	{"VLDL1",OFFSET1+53},	
	{"VLDL2",OFFSET1+54},	
	{"VLDH1",OFFSET1+55},	
	{"VLDH2",OFFSET1+56},	
	{"VLPD",OFFSET1+57},	
	{"VLDT1",OFFSET1+58},	
	{"VLDT2",OFFSET1+59},	
	{"VLPT",OFFSET1+60},	
	{"UO1",OFFSET1+61},	
	{"UO2",OFFSET1+62},	
	{"UO3",OFFSET1+63},	
	{"LO1",OFFSET1+64},	
	{"LO2",OFFSET1+65},	
	{"LO3",OFFSET1+66},	
	{"LH3",OFFSET1+67},	
	{"LC3",OFFSET1+68},	
//heating system
	//NBI
	{"ip_current",OFFSET1+69},	
	{"ne",OFFSET1+70},	
	{"ip_protection_L",OFFSET1+71},	
	{"ip_protection_R",OFFSET1+72},	
	{"ne_protection_L",OFFSET1+73},	
	{"ne_protection_R",OFFSET1+74},	
	//NBI_1
	{"NBI_ONOFF_L_1",OFFSET1+75},	
	{"NBI_ONOFF_R_1",OFFSET1+76},	
	//LHW 2.45GHz
	{"power_2.45",OFFSET1+77},	
	{"ip_protection_2.45",OFFSET1+78},	
	{"ne_protection_2.45",OFFSET1+79},	
	//LHW 4.6GHz
	{"power_4.6",OFFSET1+80},	
	{"ip_protection_4.6",OFFSET1+81},	
	{"ip_protection_4.6",OFFSET1+82},	
	//ICRF
	{"ICRF1_power",OFFSET1+83},	
	{"ICRF2_power",OFFSET1+84},	
	{"ip_protection_ICRF",OFFSET1+85},	
	{"ne_protection_ICRF",OFFSET1+86},	
	//LHW4.6GHz
	{"IC_enable",OFFSET1+87},	
	{"NBI_ONOFF_L_2",OFFSET1+88},	
	{"NBI_ONOFF_R_2",OFFSET1+89},	
//remote display
	{"PF1",OFFSET1+90},	
	{"PF2",OFFSET1+91},	
	{"PF3",OFFSET1+92},	
	{"PF4",OFFSET1+93},	
	{"PF5",OFFSET1+94},	
	{"PF6",OFFSET1+95},	
	{"PF7",OFFSET1+96},	
	{"PF8",OFFSET1+97},	
	{"PF11",OFFSET1+98},	
	{"PF12",OFFSET1+99},	
	{"PF13",OFFSET1+100},	
	{"PF14",OFFSET1+101},	
	{"IC1_display",OFFSET1+102},	
	{"plasma_current",OFFSET1+103},	
	{"avflux",OFFSET1+104},	
	{"Lmsz",OFFSET1+105},	
	{"Lmszx1",OFFSET1+106},	
/*
//XUV channel selection data
	{"",OFFSET1+107},	
	{"",OFFSET1+108},	
	{"",OFFSET1+109},	
	{"",OFFSET1+110},	
	{"",OFFSET1+111},	
	{"",OFFSET1+112},	
	{"",OFFSET1+113},	
	{"",OFFSET1+114},	
	{"",OFFSET1+115},	
	{"",OFFSET1+116},	
	{"",OFFSET1+117},	
	{"",OFFSET1+118},	
	{"",OFFSET1+119},	
	{"",OFFSET1+120},	
	{"",OFFSET1+121},	
	{"",OFFSET1+122},	
	{"",OFFSET1+123},	
	{"",OFFSET1+124},	
	{"",OFFSET1+125},	
	{"",OFFSET1+126},	
	{"",OFFSET1+127},	
	{"",OFFSET1+128},	
	{"",OFFSET1+129},	
	{"",OFFSET1+130},	
	{"",OFFSET1+131},	
	{"",OFFSET1+132},	
	{"",OFFSET1+133},	
	{"",OFFSET1+134},	
	{"",OFFSET1+135},	
	{"",OFFSET1+136},	
	{"",OFFSET1+137},	
	{"",OFFSET1+138},	
	{"",OFFSET1+139},	
	{"",OFFSET1+140},	
	{"",OFFSET1+141},	
	{"",OFFSET1+142},	
	{"",OFFSET1+143},	
	{"",OFFSET1+144},	
	{"",OFFSET1+145},	
	{"",OFFSET1+146},	
	{"",OFFSET1+147},	
	{"",OFFSET1+148},	
	{"",OFFSET1+149},	
*/
//commands data for ECRH
	{"mirror_1_t",OFFSET1+150},	
	{"mirror_1_p",OFFSET1+151},	
	{"mirror_2_t",OFFSET1+152},	
	{"mirror_2_p",OFFSET1+153},	
	{"mirror_3_t",OFFSET1+154},	
	{"mirror_3_p",OFFSET1+155},	
	{"mirror_4_t",OFFSET1+156},	
	{"mirror_4_p",OFFSET1+157},	
	{"mirror_1_flag",OFFSET1+158},	
	{"mirror_2_flag",OFFSET1+159},	
	{"mirror_3_flag",OFFSET1+160},	
	{"mirror_4_flag",OFFSET1+161},	
/*
	{"",OFFSET1+162},	
	{"",OFFSET1+163},	
	{"",OFFSET1+164},	
	{"",OFFSET1+165},	
	{"",OFFSET1+166},	
	{"",OFFSET1+167},	
	{"",OFFSET1+168},	
	{"",OFFSET1+169},	
	{"",OFFSET1+170},	
	{"",OFFSET1+171},	  
	{"",OFFSET1+172},	
	{"",OFFSET1+173},	
	{"",OFFSET1+174},	
	{"",OFFSET1+175},	
	{"",OFFSET1+176},	
	{"",OFFSET1+177},	
	{"",OFFSET1+178},	
	{"",OFFSET1+179},	
	{"",OFFSET1+180},	
*/
//OFFSET2
//	{"",OFFSET2+0},
};
#endif

