#ifndef __DRAW_FUNCTIONS_H
#define __DRAW_FUNCTIONS_H

#include "main.h"

void maak_lijn(char *charx1, char *chary1, char *charx2, char *chary2, char *chardikte, int kleur);
void maak_ellips(char *charx_mp, char *chary_mp, char *charradius_x, char *charradius_y, int kleur);
void maak_rechthoek(char *charxlo, char *charylo, char *charxrb, char *charyrb, int kleur);
void maak_driehoek (char *charx0, char *chary0, char *charx1, char *chary1, char *charx2, char *chary2, int kleur);
void maak_lijndriehoek(int x1, int y1, int x2, int y2, int dikte, int kleur);
void maak_tekst(char *charx, char *chary, char *chartekst, char *charfontnaam , int kleur, char *charstijl);
void maak_bitmap (char *charnummer, char *charx_lo, char *chary_lo);
void maak_clearscherm (int kleur);
void wacht (char *charmsecs);

#endif		//__DRAW_FUNCTIONS_H
