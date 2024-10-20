#include <REGX52.H>
#ifndef __XPT2026_H__
#define __XPT2026_H__

#define XPT2026_XP_8   0x9C  //����
#define XPT2026_YP_8   0xdC  //��������
#define XPT2026_VBAT_8 0xAC  //��������
#define XPT2026_AUX_8  0xEC

#define XPT2026_XP_12   0x94  //����
#define XPT2026_YP_12   0xd4  //��������
#define XPT2026_VBAT_12 0xA4  //��������
#define XPT2026_AUX_12  0xE4

unsigned int XPT2026_readAD(unsigned char command);

#endif