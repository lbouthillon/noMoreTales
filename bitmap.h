#ifndef _BITMAP_H
#define _BITMAP_H

#include <allegro.h>

extern BITMAP * bonhomme[4][9];
extern BITMAP * horlogeBas[7];
extern BITMAP * horlogeHaut[16];
extern BITMAP * fondBlanc;
extern BITMAP * lit;
extern BITMAP * murs;
extern BITMAP * murs2;
extern BITMAP * porteSang;
extern BITMAP * goutteSang;
extern BITMAP * menu;
extern BITMAP * sac;

void init_bitmap(BITMAP * page);



#endif
