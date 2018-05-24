#include "front_Layer.h"
#include "stm32_ub_vga_screen.h"
#include "draw_functions.h"





void maak_lijn(char *charx1, char *chary1, char *charx2, char *chary2, char *chardikte, int kleur)
{
	int x1 = atoi(charx1);
	int y1 = atoi(chary1);
	int x2 = atoi(charx2);
	int y2 = atoi(chary2);
	int dikte = atoi(chardikte);
	//int kleur = atoi(charkleur);

	int a, b;
	int steep = 0;

	if((abs(x1-x2)) < (abs(y1-y2)))	{
		int swit1, swit2;
		swit1 = x1;
		x1 = y1;
		y1 = swit1;

		swit2 = x2;
		x2 = y2;
		y2 = swit2;

		steep = 1;
	}

	if( x1 > x2) {
			int switx, swity;
			switx = x1;
			x1 = x2;
			x2 = switx;

			swity = y1;
			y1 = y2;
			y2 = swity;
	}

	for(b = 0; b < dikte; b++)
	{
		int x1a = x1+b;
		int x2a = x2+b;

		for(a = x1a; a < x2a; a++)
		{
			float t = (a-x1a)/(float)(x2a-x1a);
			int Coor2 = y1*(1.-t) +y2*t;

			if (steep == 1) {
				UB_VGA_SetPixel(Coor2, a, kleur);
			}
			else {
				UB_VGA_SetPixel(a, Coor2, kleur);
			}
		}
	}
}

void maak_ellips(char *charx_mp, char *chary_mp, char *charradius_x, char *charradius_y, int kleur)
{
	int x_mp = atoi(charx_mp);
	int y_mp = atoi(chary_mp);
	int radius_x = atoi(charradius_x);
	int radius_y = atoi(charradius_y);
	//int kleur = atoi(charkleur);

	int y, x;

	for(y =-radius_y; y<=radius_y; y++)
	{
	    for(x = -radius_x; x<=radius_x; x++)
	    {
	        if(x*x*radius_y*radius_y + y*y*radius_x*radius_x <= radius_y*radius_y*radius_x*radius_x){
	        	UB_VGA_SetPixel(x_mp+x, y_mp +y, kleur);
	        }
	    }
	}
}

void maak_rechthoek(char *charxlo, char *charylo, char *charxrb, char *charyrb, int kleur)
{
	int xlo = atoi(charxlo);
	int ylo = atoi(charylo);
	int xrb = atoi(charxrb);
	int yrb = atoi(charyrb);
//	int kleur = atoi(charkleur);

	int i;
	int j;

	for(i=xlo;i<xrb;i++)
	{
		for (j = yrb; j < ylo; j++)
		{
			UB_VGA_SetPixel(i , j, kleur);
		}
	}
}

void maak_driehoek (char *charx0, char *chary0, char *charx1, char *chary1, char *charx2, char *chary2, int kleur){

	int x0 = atoi(charx0);
	int y0 = atoi(chary0);
	int x1 = atoi(charx1);
	int y1 = atoi(chary1);
	int x2 = atoi(charx2);
	int y2 = atoi(chary2);
	//int kleur = atoi(charkleur);

	maak_lijndriehoek(x0,y0,x1,y1,1,kleur);
	maak_lijndriehoek(x1,y1,x2,y2,1,kleur);
	maak_lijndriehoek(x2,y2,x0,y0,1,kleur);
}

void maak_lijndriehoek(int x1, int y1, int x2, int y2, int dikte, int kleur)
{
	int a, b;
	int steep = 0;

	if((abs(x1-x2)) < (abs(y1-y2)))	{
		int swit1, swit2;
		swit1 = x1;
		x1 = y1;
		y1 = swit1;

		swit2 = x2;
		x2 = y2;
		y2 = swit2;

		steep = 1;
	}

	if( x1 > x2) {
			int switx, swity;
			switx = x1;
			x1 = x2;
			x2 = switx;

			swity = y1;
			y1 = y2;
			y2 = swity;
	}

	for(b = 0; b < dikte; b++)
	{
		int x1a = x1+b;
		int x2a = x2+b;

		for(a = x1a; a < x2a; a++)
		{
			float t = (a-x1a)/(float)(x2a-x1a);
			int Coor2 = y1*(1.-t) +y2*t;

			if (steep == 1) {
				UB_VGA_SetPixel(Coor2, a, kleur);
			}
			else {
				UB_VGA_SetPixel(a, Coor2, kleur);
			}
		}
	}
}


void maak_tekst(char *charx, char *chary, char *chartekst, char *charfontnaam , int kleur, char *charstijl)
{
	int x = atoi(charx);
	int y = atoi(chary);
	//int kleur = atoi(charkleur);
	char tekst[40];
	char fontnaam[40];
	char stijl[40];

	for (int i=0;i<40;i++){
		tekst[i]=chartekst[i];
		//fontnaam[i]=charfontnaam[i];
		//stijl[i]=charstijl[i];
	}

		int bitmap_A[10][10] = {
						{0,0,0,0,kleur,kleur,0,0,0,0},
						{0,0,0,kleur,0,0,kleur,0,0,0},
						{0,0,kleur,0,0,0,0,kleur,0,0},
						{0,0,kleur,0,0,0,0,kleur,0,0},
						{0,kleur,0,0,0,0,0,0,kleur,0},
						{0,kleur,kleur,kleur,kleur,kleur,kleur,kleur,kleur,0},
						{0,kleur,0,0,0,0,0,0,kleur,0},
						{0,kleur,0,0,0,0,0,0,kleur,0},
						{0,kleur,0,0,0,0,0,0,kleur,0},
						{0,0,0,0,0,0,0,0,0,0}
		};
		int bitmap_B[10][10] = {
						{0,0,0,0,0,0,0,0,0,0},
						{0,kleur,kleur,kleur,kleur,kleur,0,0,0,0},
						{0,kleur,0,0,0,0,kleur,0,0,0},
						{0,kleur,0,0,0,0,kleur,0,0,0},
						{0,kleur,kleur,kleur,kleur,kleur,0,0,0,0},
						{0,kleur,0,0,0,0,kleur,kleur,0,0},
						{0,kleur,0,0,0,0,0,kleur,0,0},
						{0,kleur,0,0,0,0,kleur,kleur,0,0},
						{0,kleur,kleur,kleur,kleur,kleur,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0}
		};
		int bitmap_C[10][10] = {
						{0,0,0,0,0,0,0,0,0,0},
						{0,0,0,kleur,kleur,kleur,kleur,0,0,0},
						{0,0,kleur,0,0,0,0,kleur,0,0},
						{0,kleur,0,0,0,0,0,0,kleur,0},
						{0,kleur,0,0,0,0,0,0,0,0},
						{0,kleur,0,0,0,0,0,0,0,0},
						{0,kleur,0,0,0,0,0,0,kleur,0},
						{0,0,kleur,0,0,0,0,kleur,0,0},
						{0,0,0,kleur,kleur,kleur,kleur,0,0,0},
						{0,0,0,0,0,0,0,0,0,0}
		};
		int bitmap_D[10][10] = {
						{0,0,0,0,0,0,0,0,0,0},
						{0,kleur,kleur,kleur,kleur,kleur,kleur,0,0,0},
						{0,kleur,0,0,0,0,0,kleur,0,0},
						{0,kleur,0,0,0,0,0,0,kleur,0},
						{0,kleur,0,0,0,0,0,0,kleur,0},
						{0,kleur,0,0,0,0,0,0,kleur,0},
						{0,kleur,0,0,0,0,0,0,kleur,0},
						{0,kleur,0,0,0,0,0,kleur,0,0},
						{0,kleur,kleur,kleur,kleur,kleur,kleur,0,0,0},
						{0,0,0,0,0,0,0,0,0,0}
		};
		int bitmap_E[10][10] = {
						{0,0,0,0,0,0,0,0,0,0},
						{0,kleur,kleur,kleur,kleur,kleur,kleur,kleur,kleur,0},
						{0,kleur,0,0,0,0,0,0,0,0},
						{0,kleur,0,0,0,0,0,0,0,0},
						{0,kleur,kleur,kleur,kleur,0,0,0,0,0},
						{0,kleur,0,0,0,0,0,0,0,0},
						{0,kleur,0,0,0,0,0,0,0,0},
						{0,kleur,0,0,0,0,0,0,0,0},
						{0,kleur,kleur,kleur,kleur,kleur,kleur,kleur,kleur,0},
						{0,0,0,0,0,0,0,0,0,0}
		};

		int bitmap_F[10][10] = {
						{0,0,0,0,0,0,0,0,0,0},
						{0,0,kleur,kleur,kleur,kleur,kleur,kleur,0,0},
						{0,0,kleur,0,0,0,0,0,0,0},
						{0,0,kleur,0,0,0,0,0,0,0},
						{0,0,kleur,kleur,kleur,0,0,0,0,0},
						{0,0,kleur,0,0,0,0,0,0,0},
						{0,0,kleur,0,0,0,0,0,0,0},
						{0,0,kleur,0,0,0,0,0,0,0},
						{0,0,kleur,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0}
		};

		int bitmap_G[10][10] = {
						{0,0,0,0,0,0,0,0,0,0},
						{0,0,0,kleur,kleur,kleur,kleur,0,0,0},
						{0,0,kleur,0,0,0,0,kleur,0,0},
						{0,kleur,0,0,0,0,0,0,0,0},
						{0,kleur,0,0,0,0,0,0,0,0},
						{0,kleur,0,0,0,0,kleur,kleur,kleur,0},
						{0,kleur,0,0,0,0,0,kleur,0,0},
						{0,0,kleur,0,0,0,kleur,0,0,0},
						{0,0,0,kleur,kleur,kleur,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0}
		};

		int bitmap_H[10][10] = {
						{0,0,0,0,0,0,0,0,0,0},
						{0,kleur,0,0,0,0,0,0,kleur,0},
						{0,kleur,0,0,0,0,0,0,kleur,0},
						{0,kleur,0,0,0,0,0,0,kleur,0},
						{0,kleur,0,0,0,0,0,0,kleur,0},
						{0,kleur,kleur,kleur,kleur,kleur,kleur,kleur,kleur,0},
						{0,kleur,0,0,0,0,0,0,kleur,0},
						{0,kleur,0,0,0,0,0,0,kleur,0},
						{0,kleur,0,0,0,0,0,0,kleur,0},
						{0,0,0,0,0,0,0,0,0,0}
		};

		int bitmap_I[10][10] = {
						{0,0,0,0,0,0,0,0,0,0},
						{0,kleur,kleur,kleur,kleur,kleur,kleur,kleur,0,0},
						{0,0,0,0,kleur,0,0,0,0,0},
						{0,0,0,0,kleur,0,0,0,0,0},
						{0,0,0,0,kleur,0,0,0,0,0},
						{0,0,0,0,kleur,0,0,0,0,0},
						{0,0,0,0,kleur,0,0,0,0,0},
						{0,0,0,0,kleur,0,0,0,0,0},
						{0,kleur,kleur,kleur,kleur,kleur,kleur,kleur,0,0},
						{0,0,0,0,0,0,0,0,0,0}
		};

		int bitmap_J[10][10] = {
						{0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,kleur,kleur,kleur,kleur,kleur,0},
						{0,0,0,0,0,0,0,0,kleur,0},
						{0,0,0,0,0,0,0,0,kleur,0},
						{0,0,0,0,0,0,0,0,kleur,0},
						{0,0,0,0,0,0,0,0,kleur,0},
						{0,0,kleur,0,0,0,0,0,kleur,0},
						{0,0,0,kleur,0,0,0,kleur,0,0},
						{0,0,0,0,kleur,kleur,kleur,0,0,0},
						{0,0,0,0,0,0,0,0,0,0}

		};

		int bitmap_K[10][10] = {
						{0,0,0,0,0,0,0,0,0,0},
						{0,0,kleur,0,0,0,0,kleur,0,0},
						{0,0,kleur,0,0,0,kleur,0,0,0},
						{0,0,kleur,0,0,kleur,0,0,0,0},
						{0,0,kleur,kleur,kleur,0,0,0,0,0},
						{0,0,kleur,kleur,0,0,0,0,0,0},
						{0,0,kleur,0,kleur,kleur,0,0,0,0},
						{0,0,kleur,0,0,0,kleur,0,0,0},
						{0,0,kleur,0,0,0,0,kleur,0,0},
						{0,0,0,0,0,0,0,0,0,0}

		};

		int bitmap_L[10][10] = {
						{0,0,0,0,0,0,0,0,0,0},
						{0,0,kleur,0,0,0,0,0,0,0},
						{0,0,kleur,0,0,0,0,0,0,0},
						{0,0,kleur,0,0,0,0,0,0,0},
						{0,0,kleur,0,0,0,0,0,0,0},
						{0,0,kleur,0,0,0,0,0,0,0},
						{0,0,kleur,0,0,0,0,0,0,0},
						{0,0,kleur,0,0,0,0,0,0,0},
						{0,0,kleur,kleur,kleur,kleur,kleur,kleur,0,0},
						{0,0,0,0,0,0,0,0,0,0}
		};

		int bitmap_M[10][10] = {
						{0,0,0,0,0,0,0,0,0,0},
						{0,kleur,kleur,0,0,0,0,kleur,kleur,0},
						{0,kleur,0,kleur,0,0,kleur,0,kleur,0},
						{0,kleur,0,kleur,0,0,kleur,0,kleur,0},
						{0,kleur,0,0,kleur,kleur,0,0,kleur,0},
						{0,kleur,0,0,0,0,0,0,kleur,0},
						{0,kleur,0,0,0,0,0,0,kleur,0},
						{0,kleur,0,0,0,0,0,0,kleur,0},
						{0,kleur,0,0,0,0,0,0,kleur,0},
						{0,0,0,0,0,0,0,0,0,0}
		};

		int bitmap_N[10][10] = {
						{0,0,0,0,0,0,0,0,0,0},
						{0,kleur,0,0,0,0,0,0,kleur,0},
						{0,kleur,kleur,0,0,0,0,0,kleur,0},
						{0,kleur,0,kleur,0,0,0,0,kleur,0},
						{0,kleur,0,0,kleur,0,0,0,kleur,0},
						{0,kleur,0,0,0,kleur,0,0,kleur,0},
						{0,kleur,0,0,0,0,kleur,0,kleur,0},
						{0,kleur,0,0,0,0,0,kleur,kleur,0},
						{0,kleur,0,0,0,0,0,0,kleur,0},
						{0,0,0,0,0,0,0,0,0,0}
		};

		int bitmap_O[10][10] = {
						{0,0,0,0,0,0,0,0,0,0},
						{0,0,0,kleur,kleur,kleur,kleur,0,0,0},
						{0,0,kleur,0,0,0,0,kleur,0,0},
						{0,kleur,0,0,0,0,0,0,kleur,0},
						{0,kleur,0,0,0,0,0,0,kleur,0},
						{0,kleur,0,0,0,0,0,0,kleur,0},
						{0,kleur,0,0,0,0,0,0,kleur,0},
						{0,0,kleur,0,0,0,0,kleur,0,0},
						{0,0,0,kleur,kleur,kleur,kleur,0,0,0},
						{0,0,0,0,0,0,0,0,0,0}

		};

		int bitmap_P[10][10] = {
						{0,0,0,0,0,0,0,0,0,0},
						{0,0,kleur,kleur,kleur,kleur,kleur,0,0,0},
						{0,0,kleur,0,0,0,0,kleur,0,0},
						{0,0,kleur,0,0,0,0,kleur,0,0},
						{0,0,kleur,kleur,kleur,kleur,kleur,0,0,0},
						{0,0,kleur,0,0,0,0,0,0,0},
						{0,0,kleur,0,0,0,0,0,0,0},
						{0,0,kleur,0,0,0,0,0,0,0},
						{0,0,kleur,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0}

		};

		int bitmap_Q[10][10] = {
						{0,0,0,0,0,0,0,0,0,0},
						{0,0,0,kleur,kleur,kleur,kleur,0,0,0},
						{0,0,kleur,0,0,0,0,kleur,0,0},
						{0,kleur,0,0,0,0,0,0,kleur,0},
						{0,kleur,0,0,0,0,0,0,kleur,0},
						{0,kleur,0,0,0,0,0,0,kleur,0},
						{0,kleur,0,0,0,0,kleur,0,kleur,0},
						{0,0,kleur,0,0,0,0,kleur,0,0},
						{0,0,0,kleur,kleur,kleur,kleur,0,kleur,0},
						{0,0,0,0,0,0,0,0,0,0}
		};

		int bitmap_R[10][10] = {
						{0,0,0,0,0,0,0,0,0,0},
						{0,kleur,kleur,kleur,kleur,kleur,kleur,0,0,0},
						{0,kleur,0,0,0,0,0,kleur,0,0},
						{0,kleur,0,0,0,0,0,kleur,0,0},
						{0,kleur,kleur,kleur,kleur,kleur,kleur,0,0,0},
						{0,kleur,kleur,kleur,0,0,0,0,0,0},
						{0,kleur,0,kleur,kleur,kleur,0,0,0,0},
						{0,kleur,0,0,0,kleur,kleur,0,0,0},
						{0,kleur,0,0,0,0,kleur,kleur,0,0},
						{0,0,0,0,0,0,0,0,0,0}
		};
		int bitmap_S[10][10] = {
						{0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0},
						{0,0,0,kleur,kleur,kleur,kleur,kleur,0,0},
						{0,0,kleur,0,0,0,0,0,0,0},
						{0,0,kleur,0,0,0,0,0,0,0},
						{0,0,0,kleur,kleur,kleur,kleur,0,0,0},
						{0,0,0,0,0,0,0,kleur,0,0},
						{0,0,0,0,0,0,0,kleur,0,0},
						{0,0,kleur,kleur,kleur,kleur,kleur,0,0,0},
						{0,0,0,0,0,0,0,0,0,0}
		};

		int bitmap_T[10][10] = {
						{0,0,0,0,0,0,0,0,0,0},
						{0,kleur,kleur,kleur,kleur,kleur,kleur,kleur,0,0},
						{0,0,0,0,kleur,0,0,0,0,0},
						{0,0,0,0,kleur,0,0,0,0,0},
						{0,0,0,0,kleur,0,0,0,0,0},
						{0,0,0,0,kleur,0,0,0,0,0},
						{0,0,0,0,kleur,0,0,0,0,0},
						{0,0,0,0,kleur,0,0,0,0,0},
						{0,0,0,0,kleur,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0}
		};

		int bitmap_U[10][10] = {
						{0,0,0,0,0,0,0,0,0,0},
						{0,kleur,0,0,0,0,0,kleur,0,0},
						{0,kleur,0,0,0,0,0,kleur,0,0},
						{0,kleur,0,0,0,0,0,kleur,0,0},
						{0,kleur,0,0,0,0,0,kleur,0,0},
						{0,kleur,0,0,0,0,0,kleur,0,0},
						{0,kleur,0,0,0,0,0,kleur,0,0},
						{0,0,kleur,0,0,0,kleur,0,0,0},
						{0,0,0,kleur,kleur,kleur,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0}
		};

		int bitmap_V[10][10] = {
						{0,0,0,0,0,0,0,0,0,0},
						{0,kleur,0,0,0,0,0,0,kleur,0},
						{0,kleur,0,0,0,0,0,0,kleur,0},
						{0,kleur,0,0,0,0,0,0,kleur,0},
						{0,0,kleur,0,0,0,0,kleur,0,0},
						{0,0,kleur,0,0,0,0,kleur,0,0},
						{0,0,0,kleur,0,0,kleur,0,0,0},
						{0,0,0,kleur,0,0,kleur,0,0,0},
						{0,0,0,0,kleur,kleur,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0}
		};

		int bitmap_W[10][10] = {
						{0,0,0,0,0,0,0,0,0,0},
						{0,kleur,0,0,kleur,0,0,kleur,0,0},
						{0,kleur,0,0,kleur,0,0,kleur,0,0},
						{0,kleur,0,0,kleur,0,0,kleur,0,0},
						{0,kleur,0,kleur,0,kleur,0,kleur,0,0},
						{0,kleur,0,kleur,0,kleur,0,kleur,0,0},
						{0,kleur,0,kleur,0,kleur,0,kleur,0,0},
						{0,kleur,0,kleur,0,kleur,0,kleur,0,0},
						{0,0,kleur,0,0,0,kleur,0,0,0},
						{0,0,0,0,0,0,0,0,0,0}
		};

		int bitmap_X[10][10] = {
						{0,0,0,0,0,0,0,0,0,0},
						{0,kleur,0,0,0,0,0,0,kleur,0},
						{0,0,kleur,0,0,0,0,kleur,0,0},
						{0,0,0,kleur,0,0,kleur,0,0,0},
						{0,0,0,0,kleur,kleur,0,0,0,0},
						{0,0,0,0,kleur,kleur,0,0,0,0},
						{0,0,0,kleur,0,0,kleur,0,0,0},
						{0,0,kleur,0,0,0,0,kleur,0,0},
						{0,kleur,0,0,0,0,0,0,kleur,0},
						{0,0,0,0,0,0,0,0,0,0}
		};

		int bitmap_Y[10][10] = {
						{0,0,0,0,0,0,0,0,0,0},
						{0,kleur,0,0,0,0,0,0,kleur,0},
						{0,0,kleur,0,0,0,0,kleur,0,0},
						{0,0,0,kleur,0,0,kleur,0,0,0},
						{0,0,0,0,kleur,kleur,0,0,0,0},
						{0,0,0,0,kleur,kleur,0,0,0,0},
						{0,0,0,0,kleur,kleur,0,0,0,0},
						{0,0,0,0,kleur,kleur,0,0,0,0},
						{0,0,0,0,kleur,kleur,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0}
		};

		int bitmap_Z[10][10] = {
						{0,0,0,0,0,0,0,0,0,0},
						{0,kleur,kleur,kleur,kleur,kleur,kleur,kleur,kleur,0},
						{0,0,0,0,0,0,0,kleur,0,0},
						{0,0,0,0,0,0,kleur,0,0,0},
						{0,0,0,0,0,kleur,0,0,0,0},
						{0,0,0,0,kleur,0,0,0,0,0},
						{0,0,0,kleur,0,0,0,0,0,0},
						{0,0,kleur,0,0,0,0,0,0,0},
						{0,kleur,kleur,kleur,kleur,kleur,kleur,kleur,kleur,0},
						{0,0,0,0,0,0,0,0,0,0}
		};

	char h = 0;
	int length = 0;
	int v,w,i;
	length = (strlen(tekst));

	for(i=0; i<length; i++, x=x+10)
	{
		h = tekst[i];
		for(w=0; w < 10; w++){
			for(v=0; v < 10;v++){

				switch(h){
				case 'a':	UB_VGA_SetPixel(v+x, w+ y+10, bitmap_A[w][v]);	break;
				case 'b':	UB_VGA_SetPixel(v+x, w+ y+10, bitmap_B[w][v]);	break;
				case 'c':	UB_VGA_SetPixel(v+x, w+ y+10, bitmap_C[w][v]);	break;
				case 'd' :	UB_VGA_SetPixel(v+x, w+ y+10, bitmap_D[w][v]);	break;
				case 'e' :	UB_VGA_SetPixel(v+x, w+ y+10, bitmap_E[w][v]);	break;
				case 'f' :	UB_VGA_SetPixel(v+x, w+ y+10, bitmap_F[w][v]);	break;
				case 'g' :	UB_VGA_SetPixel(v+x, w+ y+10, bitmap_G[w][v]);	break;
				case 'h' :	UB_VGA_SetPixel(v+x, w+ y+10, bitmap_H[w][v]); 	break;
				case 'i' :	UB_VGA_SetPixel(v+x, w+ y+10, bitmap_I[w][v]);	break;
				case 'j' :	UB_VGA_SetPixel(v+x, w+ y+10, bitmap_J[w][v]);	break;
				case 'k' :	UB_VGA_SetPixel(v+x, w+ y+10, bitmap_K[w][v]);	break;
				case 'l' :	UB_VGA_SetPixel(v+x, w+ y+10, bitmap_L[w][v]);	break;
				case 'm' :	UB_VGA_SetPixel(v+x, w+ y+10, bitmap_M[w][v]);	break;
				case 'n' :	UB_VGA_SetPixel(v+x, w+ y+10, bitmap_N[w][v]);	break;
				case 'o' :	UB_VGA_SetPixel(v+x, w+ y+10, bitmap_O[w][v]);	break;
				case 'p' :	UB_VGA_SetPixel(v+x, w+ y+10, bitmap_P[w][v]);	break;
				case 'q' :	UB_VGA_SetPixel(v+x, w+ y+10, bitmap_Q[w][v]);	break;
				case 'r' :	UB_VGA_SetPixel(v+x, w+ y+10, bitmap_R[w][v]); 	break;
				case 's' :	UB_VGA_SetPixel(v+x, w+ y+10, bitmap_S[w][v]);	break;
				case 't' :	UB_VGA_SetPixel(v+x, w+ y+10, bitmap_T[w][v]);	break;
				case 'u' :	UB_VGA_SetPixel(v+x, w+ y+10, bitmap_U[w][v]);	break;
				case 'v' :	UB_VGA_SetPixel(v+x, w+ y+10, bitmap_V[w][v]);	break;
				case 'w' :	UB_VGA_SetPixel(v+x, w+ y+10, bitmap_W[w][v]);	break;
				case 'x' :	UB_VGA_SetPixel(v+x, w+ y+10, bitmap_X[w][v]);	break;
				case 'y' :	UB_VGA_SetPixel(v+x, w+ y+10, bitmap_Y[w][v]);	break;
				case 'z' :	UB_VGA_SetPixel(v+x, w+ y+10, bitmap_Z[w][v]);	break;

				default :	UB_VGA_SetPixel(v+x, w+y+10, VGA_COL_BLACK);
				}
			}
		}
	}
}


void maak_bitmap (char *charnummer, char *charx_lo, char *chary_lo)
{
	int nummer = atoi(charnummer);
	int x_lo = atoi(charx_lo);
	int y_lo = atoi(chary_lo);

	//pijl naar rechts
	int bitmap_1[10][10] = {
				{0xFF,0xFF,0xFF,0xFF,0x03,0x03,0xFF,0xFF,0xFF,0xFF},
				{0xFF,0xFF,0xFF,0xFF,0x03,0xFF,0x03,0xFF,0xFF,0xFF},
				{0xFF,0xFF,0xFF,0xFF,0x03,0xFF,0xFF,0x03,0xFF,0xFF},
				{0x03,0x03,0x03,0x03,0x03,0xFF,0xFF,0xFF,0x03,0xFF},
				{0x03,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x03},
				{0x03,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x03},
				{0x03,0x03,0x03,0x03,0x03,0xFF,0xFF,0xFF,0x03,0xFF},
				{0xFF,0xFF,0xFF,0xFF,0x03,0xFF,0xFF,0x03,0xFF,0xFF},
				{0xFF,0xFF,0xFF,0xFF,0x03,0xFF,0x03,0xFF,0xFF,0xFF},
				{0xFF,0xFF,0xFF,0xFF,0x03,0x03,0xFF,0xFF,0xFF,0xFF}
	};

	//pijl naar boven
	int bitmap_2[10][10] = {
				{0xFF,0xFF,0xFF,0xFF,0x03,0x03,0xFF,0xFF,0xFF,0xFF},
				{0xFF,0xFF,0xFF,0x03,0xFF,0xFF,0x03,0xFF,0xFF,0xFF},
				{0xFF,0xFF,0x03,0xFF,0xFF,0xFF,0xFF,0x03,0xFF,0xFF},
				{0xFF,0x03,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x03,0xFF},
				{0x03,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x03},
				{0x03,0x03,0x03,0x03,0xFF,0xFF,0x03,0x03,0x03,0x03},
				{0xFF,0xFF,0xFF,0x03,0xFF,0xFF,0x03,0xFF,0xFF,0xFF},
				{0xFF,0xFF,0xFF,0x03,0xFF,0xFF,0x03,0xFF,0xFF,0xFF},
				{0xFF,0xFF,0xFF,0x03,0xFF,0xFF,0x03,0xFF,0xFF,0xFF},
				{0xFF,0xFF,0xFF,0x03,0x03,0x03,0x03,0xFF,0xFF,0xFF}
	};

	//pijl naar links
	int bitmap_3[10][10] = {
				{0xFF,0xFF,0xFF,0xFF,0x03,0x03,0xFF,0xFF,0xFF,0xFF},
				{0xFF,0xFF,0xFF,0x03,0xFF,0x03,0xFF,0xFF,0xFF,0xFF},
				{0xFF,0xFF,0x03,0xFF,0xFF,0x03,0xFF,0xFF,0xFF,0xFF},
				{0xFF,0x03,0xFF,0xFF,0xFF,0x03,0x03,0x03,0x03,0x03},
				{0x03,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x03},
				{0x03,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x03},
				{0xFF,0x03,0xFF,0xFF,0xFF,0x03,0x03,0x03,0x03,0x03},
				{0xFF,0xFF,0x03,0xFF,0xFF,0x03,0xFF,0xFF,0xFF,0xFF},
				{0xFF,0xFF,0xFF,0x03,0xFF,0x03,0xFF,0xFF,0xFF,0xFF},
				{0xFF,0xFF,0xFF,0xFF,0x03,0x03,0xFF,0xFF,0xFF,0xFF}
	};

	// pijl naar beneden
	int bitmap_4[10][10] = {
				{0xFF,0xFF,0xFF,0x03,0x03,0x03,0x03,0xFF,0xFF,0xFF},
				{0xFF,0xFF,0xFF,0x03,0xFF,0xFF,0x03,0xFF,0xFF,0xFF},
				{0xFF,0xFF,0xFF,0x03,0xFF,0xFF,0x03,0xFF,0xFF,0xFF},
				{0xFF,0xFF,0xFF,0x03,0xFF,0xFF,0x03,0xFF,0xFF,0xFF},
				{0x03,0x03,0x03,0x03,0xFF,0xFF,0x03,0x03,0x03,0x03},
				{0x03,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x03},
				{0xFF,0x03,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x03,0xFF},
				{0xFF,0xFF,0x03,0xFF,0xFF,0xFF,0xFF,0x03,0xFF,0xFF},
				{0xFF,0xFF,0xFF,0x03,0xFF,0xFF,0x03,0xFF,0xFF,0xFF},
				{0xFF,0xFF,0xFF,0xFF,0x03,0x03,0xFF,0xFF,0xFF,0xFF}
	};

	//smiley blij
	int bitmap_5[10][10] = {
				{0xFF,0xFF,0xFF,0x03,0x03,0x03,0x03,0xFF,0xFF,0xFF},
				{0xFF,0xFF,0x03,0xFF,0xFF,0xFF,0xFF,0x03,0xFF,0xFF},
				{0xFF,0x03,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x03,0xFF},
				{0x03,0xFF,0xFF,0x03,0xFF,0xFF,0x03,0xFF,0xFF,0x03},
				{0x03,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x03},
				{0x03,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x03},
				{0x03,0xFF,0xFF,0x03,0xFF,0xFF,0x03,0xFF,0xFF,0x03},
				{0xFF,0x03,0xFF,0xFF,0x03,0x03,0xFF,0xFF,0x03,0xFF},
				{0xFF,0xFF,0x03,0xFF,0xFF,0xFF,0xFF,0x03,0xFF,0xFF},
				{0xFF,0xFF,0xFF,0x03,0x03,0x03,0x03,0xFF,0xFF,0xFF}
	};

	//smiley boos
	int bitmap_6[10][10] = {
				{0xFF,0xFF,0xFF,0x03,0x03,0x03,0x03,0xFF,0xFF,0xFF},
				{0xFF,0xFF,0x03,0xFF,0xFF,0xFF,0xFF,0x03,0xFF,0xFF},
				{0xFF,0x03,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x03,0xFF},
				{0x03,0xFF,0xFF,0x03,0xFF,0xFF,0x03,0xFF,0xFF,0x03},
				{0x03,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x03},
				{0x03,0xFF,0xFF,0xFF,0x03,0x03,0xFF,0xFF,0xFF,0x03},
				{0x03,0xFF,0xFF,0x03,0xFF,0xFF,0x03,0xFF,0xFF,0x03},
				{0xFF,0x03,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x03,0xFF},
				{0xFF,0xFF,0x03,0xFF,0xFF,0xFF,0xFF,0x03,0xFF,0xFF},
				{0xFF,0xFF,0xFF,0x03,0x03,0x03,0x03,0xFF,0xFF,0xFF}
	};

	int x,y;

	for(y=0; y < 10; y++){
		for(x=0; x < 10;x++){

			switch(nummer){

			case 0 :
				UB_VGA_SetPixel(x+x_lo, y+y_lo+10, bitmap_1[y][x]);
				break;
			case 1 :
				UB_VGA_SetPixel(x+x_lo, y+y_lo+10, bitmap_2[y][x]);
				break;
			case 2:
				UB_VGA_SetPixel(x+x_lo, y+y_lo+10, bitmap_3[y][x]);
				break;
			case 3:
				UB_VGA_SetPixel(x+x_lo, y+y_lo+10, bitmap_4[y][x]);
				break;
			case 4:
				UB_VGA_SetPixel(x+x_lo, y+y_lo+10, bitmap_5[y][x]);
				break;
			case 5:
				UB_VGA_SetPixel(x+x_lo, y+y_lo+10, bitmap_6[y][x]);
				break;
			default :
				UB_VGA_SetPixel(x+x_lo, y+y_lo+10, VGA_COL_RED);
			}
		}
	}
}

void maak_clearscherm (int kleur)
{
	UART_puts("\n hallo: ");
	UART_puts(kleur);
	//int intkleur = atoi(kleur);
	UB_VGA_FillScreen(kleur);
}

void wacht (int msecs)
{
	uint32_t G_CLK;
	uint32_t D_mS; // Global variable (ms)


	RCC_ClocksTypeDef Clocks;
	RCC_GetClocksFreq(&Clocks);
	G_CLK = Clocks.SYSCLK_Frequency;	// Read the systemclock
	G_CLK = 50000000;
	D_mS = (G_CLK*1.25)/9000/2; // Number of instructions in one millisecond

	 volatile unsigned int i;

    while(msecs>0)		// Run x times 1 millisecond
    {
        for(i=0;i<D_mS;i++);
        msecs--;
    }

}