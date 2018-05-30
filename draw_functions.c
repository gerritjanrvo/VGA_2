/*
 * draw_functions.c
 *
 * Gemaakt door: Joost Kouijzer & Gerrit Jan Rijken van Olst
 */

#include "draw_functions.h"

/**
 * 		@brief \n Pijl naar rechts
 */
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

/**
 * 		@brief \n Pijl naar boven
 */
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

/**
 * 		@brief \n Pijl naar links
 */
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

/**
 * 		@brief \n Pijl naar beneden
 */
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

/**
 * 		@brief \n Smiley blij
 */
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

/**
 * 		@brief \n Smiley boos
 */
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

/**
 * 		\n Letter A
 */
int bitmap_A[10][10] = {
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,1,1,0,0,0,0},
	{0,0,0,1,0,0,1,0,0,0},
	{0,0,1,0,0,0,0,1,0,0},
	{0,1,0,0,0,0,0,0,1,0},
	{0,1,1,1,1,1,1,1,1,0},
	{0,1,0,0,0,0,0,0,1,0},
	{0,1,0,0,0,0,0,0,1,0},
	{0,1,0,0,0,0,0,0,1,0},
	{0,0,0,0,0,0,0,0,0,0}
};

/**
 * 		\n Letter B
 */
int bitmap_B[10][10] = {
	{0,0,0,0,0,0,0,0,0,0},
	{0,1,1,1,1,1,0,0,0,0},
	{0,1,0,0,0,0,1,0,0,0},
	{0,1,0,0,0,0,1,0,0,0},
	{0,1,1,1,1,1,0,0,0,0},
	{0,1,0,0,0,0,1,1,0,0},
	{0,1,0,0,0,0,0,1,0,0},
	{0,1,0,0,0,0,1,1,0,0},
	{0,1,1,1,1,1,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0}
};

/**
 * 		\n Letter C
 */
int bitmap_C[10][10] = {
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,1,1,1,1,0,0,0},
	{0,0,1,0,0,0,0,1,0,0},
	{0,1,0,0,0,0,0,0,1,0},
	{0,1,0,0,0,0,0,0,0,0},
	{0,1,0,0,0,0,0,0,0,0},
	{0,1,0,0,0,0,0,0,1,0},
	{0,0,1,0,0,0,0,1,0,0},
	{0,0,0,1,1,1,1,0,0,0},
	{0,0,0,0,0,0,0,0,0,0}
};

/**
 * 		\n Letter D
 */
int bitmap_D[10][10] = {
	{0,0,0,0,0,0,0,0,0,0},
	{0,1,1,1,1,1,1,0,0,0},
	{0,1,0,0,0,0,0,1,0,0},
	{0,1,0,0,0,0,0,0,1,0},
	{0,1,0,0,0,0,0,0,1,0},
	{0,1,0,0,0,0,0,0,1,0},
	{0,1,0,0,0,0,0,0,1,0},
	{0,1,0,0,0,0,0,1,0,0},
	{0,1,1,1,1,1,1,0,0,0},
	{0,0,0,0,0,0,0,0,0,0}
};

/**
 * 		\n Letter E
 */
int bitmap_E[10][10] = {
	{0,0,0,0,0,0,0,0,0,0},
	{0,1,1,1,1,1,1,1,1,0},
	{0,1,0,0,0,0,0,0,0,0},
	{0,1,0,0,0,0,0,0,0,0},
	{0,1,1,1,1,0,0,0,0,0},
	{0,1,0,0,0,0,0,0,0,0},
	{0,1,0,0,0,0,0,0,0,0},
	{0,1,0,0,0,0,0,0,0,0},
	{0,1,1,1,1,1,1,1,1,0},
	{0,0,0,0,0,0,0,0,0,0}
};

/**
 * 		\n Letter F
 */
int bitmap_F[10][10] = {
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,1,1,1,1,1,1,0,0},
	{0,0,1,0,0,0,0,0,0,0},
	{0,0,1,0,0,0,0,0,0,0},
	{0,0,1,1,1,0,0,0,0,0},
	{0,0,1,0,0,0,0,0,0,0},
	{0,0,1,0,0,0,0,0,0,0},
	{0,0,1,0,0,0,0,0,0,0},
	{0,0,1,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0}
};

/**
 * 		\n Letter G
 */
int bitmap_G[10][10] = {
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,1,1,1,1,0,0,0},
	{0,0,1,0,0,0,0,1,0,0},
	{0,1,0,0,0,0,0,0,0,0},
	{0,1,0,0,0,0,0,0,0,0},
	{0,1,0,0,0,0,1,1,1,0},
	{0,1,0,0,0,0,0,1,0,0},
	{0,0,1,0,0,0,1,0,0,0},
	{0,0,0,1,1,1,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0}
};

/**
 * 		\n Letter H
 */
int bitmap_H[10][10] = {
	{0,0,0,0,0,0,0,0,0,0},
	{0,1,0,0,0,0,0,0,1,0},
	{0,1,0,0,0,0,0,0,1,0},
	{0,1,0,0,0,0,0,0,1,0},
	{0,1,0,0,0,0,0,0,1,0},
	{0,1,1,1,1,1,1,1,1,0},
	{0,1,0,0,0,0,0,0,1,0},
	{0,1,0,0,0,0,0,0,1,0},
	{0,1,0,0,0,0,0,0,1,0},
	{0,0,0,0,0,0,0,0,0,0}
};

/**
 * 		\n Letter I
 */
int bitmap_I[10][10] = {
	{0,0,0,0,0,0,0,0,0,0},
	{0,1,1,1,1,1,1,1,0,0},
	{0,0,0,0,1,0,0,0,0,0},
	{0,0,0,0,1,0,0,0,0,0},
	{0,0,0,0,1,0,0,0,0,0},
	{0,0,0,0,1,0,0,0,0,0},
	{0,0,0,0,1,0,0,0,0,0},
	{0,0,0,0,1,0,0,0,0,0},
	{0,1,1,1,1,1,1,1,0,0},
	{0,0,0,0,0,0,0,0,0,0}
};

/**
 * 		\n Letter J
 */
int bitmap_J[10][10] = {
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,1,1,1,1,1,0},
	{0,0,0,0,0,0,0,0,1,0},
	{0,0,0,0,0,0,0,0,1,0},
	{0,0,0,0,0,0,0,0,1,0},
	{0,0,0,0,0,0,0,0,1,0},
	{0,0,1,0,0,0,0,0,1,0},
	{0,0,0,1,0,0,0,1,0,0},
	{0,0,0,0,1,1,1,0,0,0},
	{0,0,0,0,0,0,0,0,0,0}
};

/**
 * 		\n Letter K
 */
int bitmap_K[10][10] = {
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,1,0,0,0,0,1,0,0},
	{0,0,1,0,0,0,1,0,0,0},
	{0,0,1,0,0,1,0,0,0,0},
	{0,0,1,1,1,0,0,0,0,0},
	{0,0,1,1,0,0,0,0,0,0},
	{0,0,1,0,1,1,0,0,0,0},
	{0,0,1,0,0,0,1,0,0,0},
	{0,0,1,0,0,0,0,1,0,0},
	{0,0,0,0,0,0,0,0,0,0}
};

/**
 * 		\n Letter L
 */
int bitmap_L[10][10] = {
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,1,0,0,0,0,0,0,0},
	{0,0,1,0,0,0,0,0,0,0},
	{0,0,1,0,0,0,0,0,0,0},
	{0,0,1,0,0,0,0,0,0,0},
	{0,0,1,0,0,0,0,0,0,0},
	{0,0,1,0,0,0,0,0,0,0},
	{0,0,1,0,0,0,0,0,0,0},
	{0,0,1,1,1,1,1,1,0,0},
	{0,0,0,0,0,0,0,0,0,0}
};

/**
 * 		\n Letter M
 */
int bitmap_M[10][10] = {
	{0,0,0,0,0,0,0,0,0,0},
	{0,1,1,0,0,0,0,1,1,0},
	{0,1,0,1,0,0,1,0,1,0},
	{0,1,0,1,0,0,1,0,1,0},
	{0,1,0,0,1,1,0,0,1,0},
	{0,1,0,0,0,0,0,0,1,0},
	{0,1,0,0,0,0,0,0,1,0},
	{0,1,0,0,0,0,0,0,1,0},
	{0,1,0,0,0,0,0,0,1,0},
	{0,0,0,0,0,0,0,0,0,0}
};

/**
 * 		\n Letter N
 */
int bitmap_N[10][10] = {
	{0,0,0,0,0,0,0,0,0,0},
	{0,1,0,0,0,0,0,0,1,0},
	{0,1,1,0,0,0,0,0,1,0},
	{0,1,0,1,0,0,0,0,1,0},
	{0,1,0,0,1,0,0,0,1,0},
	{0,1,0,0,0,1,0,0,1,0},
	{0,1,0,0,0,0,1,0,1,0},
	{0,1,0,0,0,0,0,1,1,0},
	{0,1,0,0,0,0,0,0,1,0},
	{0,0,0,0,0,0,0,0,0,0}
};

/**
 * 		\n Letter O
 */
int bitmap_O[10][10] = {
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,1,1,1,1,0,0,0},
	{0,0,1,0,0,0,0,1,0,0},
	{0,1,0,0,0,0,0,0,1,0},
	{0,1,0,0,0,0,0,0,1,0},
	{0,1,0,0,0,0,0,0,1,0},
	{0,1,0,0,0,0,0,0,1,0},
	{0,0,1,0,0,0,0,1,0,0},
	{0,0,0,1,1,1,1,0,0,0},
	{0,0,0,0,0,0,0,0,0,0}
};

/**
 * 		\n Letter P
 */
int bitmap_P[10][10] = {
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,1,1,1,1,1,0,0,0},
	{0,0,1,0,0,0,0,1,0,0},
	{0,0,1,0,0,0,0,1,0,0},
	{0,0,1,1,1,1,1,0,0,0},
	{0,0,1,0,0,0,0,0,0,0},
	{0,0,1,0,0,0,0,0,0,0},
	{0,0,1,0,0,0,0,0,0,0},
	{0,0,1,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0}
};

/**
 * 		\n Letter Q
 */
int bitmap_Q[10][10] = {
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,1,1,1,1,0,0,0},
	{0,0,1,0,0,0,0,1,0,0},
	{0,1,0,0,0,0,0,0,1,0},
	{0,1,0,0,0,0,0,0,1,0},
	{0,1,0,0,0,0,0,0,1,0},
	{0,1,0,0,0,0,1,0,1,0},
	{0,0,1,0,0,0,0,1,0,0},
	{0,0,0,1,1,1,1,0,1,0},
	{0,0,0,0,0,0,0,0,0,0}
};

/**
 * 		\n Letter R
 */
int bitmap_R[10][10] = {
	{0,0,0,0,0,0,0,0,0,0},
	{0,1,1,1,1,1,1,0,0,0},
	{0,1,0,0,0,0,0,1,0,0},
	{0,1,0,0,0,0,0,1,0,0},
	{0,1,1,1,1,1,1,0,0,0},
	{0,1,1,1,0,0,0,0,0,0},
	{0,1,0,1,1,1,0,0,0,0},
	{0,1,0,0,0,1,1,0,0,0},
	{0,1,0,0,0,0,1,1,0,0},
	{0,0,0,0,0,0,0,0,0,0}
};

/**
* 		\n Letter S
*/
int bitmap_S[10][10] = {
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,1,1,1,1,1,0,0},
	{0,0,1,0,0,0,0,0,0,0},
	{0,0,1,0,0,0,0,0,0,0},
	{0,0,0,1,1,1,1,0,0,0},
	{0,0,0,0,0,0,0,1,0,0},
	{0,0,0,0,0,0,0,1,0,0},
	{0,0,1,1,1,1,1,0,0,0},
	{0,0,0,0,0,0,0,0,0,0}
};

/**
* 		\n Letter T
*/
int bitmap_T[10][10] = {
	{0,0,0,0,0,0,0,0,0,0},
	{0,1,1,1,1,1,1,1,0,0},
	{0,0,0,0,1,0,0,0,0,0},
	{0,0,0,0,1,0,0,0,0,0},
	{0,0,0,0,1,0,0,0,0,0},
	{0,0,0,0,1,0,0,0,0,0},
	{0,0,0,0,1,0,0,0,0,0},
	{0,0,0,0,1,0,0,0,0,0},
	{0,0,0,0,1,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0}
};

/**
* 		\n Letter U
*/
int bitmap_U[10][10] = {
	{0,0,0,0,0,0,0,0,0,0},
	{0,1,0,0,0,0,0,1,0,0},
	{0,1,0,0,0,0,0,1,0,0},
	{0,1,0,0,0,0,0,1,0,0},
	{0,1,0,0,0,0,0,1,0,0},
	{0,1,0,0,0,0,0,1,0,0},
	{0,1,0,0,0,0,0,1,0,0},
	{0,0,1,0,0,0,1,0,0,0},
	{0,0,0,1,1,1,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0}
};

/**
* 		\n Letter V
*/
int bitmap_V[10][10] = {
	{0,0,0,0,0,0,0,0,0,0},
	{0,1,0,0,0,0,0,0,1,0},
	{0,1,0,0,0,0,0,0,1,0},
	{0,1,0,0,0,0,0,0,1,0},
	{0,0,1,0,0,0,0,1,0,0},
	{0,0,1,0,0,0,0,1,0,0},
	{0,0,0,1,0,0,1,0,0,0},
	{0,0,0,1,0,0,1,0,0,0},
	{0,0,0,0,1,1,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0}
};

/**
* 		\n Letter W
*/
int bitmap_W[10][10] = {
	{0,0,0,0,0,0,0,0,0,0},
	{0,1,0,0,1,0,0,1,0,0},
	{0,1,0,0,1,0,0,1,0,0},
	{0,1,0,0,1,0,0,1,0,0},
	{0,1,0,1,0,1,0,1,0,0},
	{0,1,0,1,0,1,0,1,0,0},
	{0,1,0,1,0,1,0,1,0,0},
	{0,1,0,1,0,1,0,1,0,0},
	{0,0,1,0,0,0,1,0,0,0},
	{0,0,0,0,0,0,0,0,0,0}
};

/**
* 		\n Letter X
*/
int bitmap_X[10][10] = {
	{0,0,0,0,0,0,0,0,0,0},
	{0,1,0,0,0,0,0,0,1,0},
	{0,0,1,0,0,0,0,1,0,0},
	{0,0,0,1,0,0,1,0,0,0},
	{0,0,0,0,1,1,0,0,0,0},
	{0,0,0,0,1,1,0,0,0,0},
	{0,0,0,1,0,0,1,0,0,0},
	{0,0,1,0,0,0,0,1,0,0},
	{0,1,0,0,0,0,0,0,1,0},
	{0,0,0,0,0,0,0,0,0,0}
};

/**
* 		\n Letter Y
*/
int bitmap_Y[10][10] = {
	{0,0,0,0,0,0,0,0,0,0},
	{0,1,0,0,0,0,0,0,1,0},
	{0,0,1,0,0,0,0,1,0,0},
	{0,0,0,1,0,0,1,0,0,0},
	{0,0,0,0,1,1,0,0,0,0},
	{0,0,0,0,1,1,0,0,0,0},
	{0,0,0,0,1,1,0,0,0,0},
	{0,0,0,0,1,1,0,0,0,0},
	{0,0,0,0,1,1,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0}
};

/**
* 		\n Letter Z
*/
int bitmap_Z[10][10] = {
	{0,0,0,0,0,0,0,0,0,0},
	{0,1,1,1,1,1,1,1,1,0},
	{0,0,0,0,0,0,0,1,0,0},
	{0,0,0,0,0,0,1,0,0,0},
	{0,0,0,0,0,1,0,0,0,0},
	{0,0,0,0,1,0,0,0,0,0},
	{0,0,0,1,0,0,0,0,0,0},
	{0,0,1,0,0,0,0,0,0,0},
	{0,1,1,1,1,1,1,1,1,0},
	{0,0,0,0,0,0,0,0,0,0}
};

/**
 * 		@brief \n Functie waarmee de lijn wordt getekend.
 */
void maak_lijn(char *charx1, char *chary1, char *charx2, char *chary2, char *chardikte, int kleur)
{
	int x1 = atoi(charx1);
	int y1 = atoi(chary1);
	int x2 = atoi(charx2);
	int y2 = atoi(chary2);
	int dikte = atoi(chardikte);

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

/**
 * 		@brief \n Functie waarmee de ellips wordt getekend.
 */
void maak_ellips(char *charx_mp, char *chary_mp, char *charradius_x, char *charradius_y, int kleur)
{
	int x_mp = atoi(charx_mp);
	int y_mp = atoi(chary_mp);
	int radius_x = atoi(charradius_x);
	int radius_y = atoi(charradius_y);

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

/**
 * 		@brief \n Functie waarmee de rechthoek wordt getekend.
 */
void maak_rechthoek(char *charxlo, char *charylo, char *charxrb, char *charyrb, int kleur)
{
	int xlo = atoi(charxlo);
	int ylo = atoi(charylo);
	int xrb = atoi(charxrb);
	int yrb = atoi(charyrb);


	if(yrb > ylo)
	{
		int switchy = yrb;
		yrb = ylo;
		ylo = switchy;
	}

	if(xrb < xlo)
	{
		int switchx = xrb;
		xrb = xlo;
		xlo = switchx;
	}

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

/**
 * 		@brief \n Functie waarmee de driehoek wordt getekend.
 */
void maak_driehoek (char *charx0, char *chary0, char *charx1, char *chary1, char *charx2, char *chary2, int kleur)
{

	int x0 = atoi(charx0);
	int y0 = atoi(chary0);
	int x1 = atoi(charx1);
	int y1 = atoi(chary1);
	int x2 = atoi(charx2);
	int y2 = atoi(chary2);

	maak_lijndriehoek(x0,y0,x1,y1,1,kleur);
	maak_lijndriehoek(x1,y1,x2,y2,1,kleur);
	maak_lijndriehoek(x2,y2,x0,y0,1,kleur);
}

/**
 * 		@brief \n Functie waarmee de lijnen van de driehoek worden getekend.
 */
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

/**
 * 		@brief \n Functie waarmee de tekst wordt getekend.
 */
void maak_tekst(char *charx, char *chary, char *chartekst, char *charfontnaam , int kleur, char *charstijl)
{
	int x = atoi(charx);
	int y = atoi(chary);

	int x1 = x;
	char tekst[40];

	int i;

	for (i=0;i<40;i++){
		tekst[i]=chartekst[i];
	}

	char h = 0;
	int length = 0;
	int v,w,f;
	length = (strlen(tekst));

	for(f=0; f<length; f++, x=x+10)
	{
		if(x > 310)
				{
					x = x1;
					y = y + 10;
				}

		h = tekst[f];
		for(w=0; w < 10; w++){
			for(v=0; v < 10;v++){

				switch(h){
				case 'a':
					if(bitmap_A[w][v]==1){
						bitmap_A[w][v]= kleur;
					}
					if(bitmap_A[w][v]!=0){
						UB_VGA_SetPixel(v+x, w+ y+10, bitmap_A[w][v]);
						bitmap_A[w][v]=1;
					}
					break;
				case 'b':
					if(bitmap_B[w][v]==1){ bitmap_B[w][v]= kleur;
					}
					if(bitmap_B[w][v]!=0){
					UB_VGA_SetPixel(v+x, w+ y+10, bitmap_B[w][v]);
					bitmap_B[w][v]=1;
					}
					break;
				case 'c':
					if(bitmap_C[w][v]==1){ bitmap_C[w][v]= kleur;
					}
					if(bitmap_C[w][v]!=0){
					UB_VGA_SetPixel(v+x, w+ y+10, bitmap_C[w][v]);
					bitmap_C[w][v]=1;
					}
					break;
				case 'd' :
					if(bitmap_D[w][v]==1){ bitmap_D[w][v]= kleur;
					}
					if(bitmap_D[w][v]!=0){
					UB_VGA_SetPixel(v+x, w+ y+10, bitmap_D[w][v]);
					bitmap_D[w][v]=1;
					}
					break;
				case 'e' :
					if(bitmap_E[w][v]==1){ bitmap_E[w][v]= kleur;
					}
					if(bitmap_E[w][v]!=0){
					UB_VGA_SetPixel(v+x, w+ y+10, bitmap_E[w][v]);
					bitmap_E[w][v]=1;
					}
					break;
				case 'f' :
					if(bitmap_F[w][v]==1){ bitmap_F[w][v]= kleur;
					}
					if(bitmap_F[w][v]!=0){
					UB_VGA_SetPixel(v+x, w+ y+10, bitmap_F[w][v]);
					bitmap_F[w][v]=1;
					}
					break;
				case 'g' :
					if(bitmap_G[w][v]==1){ bitmap_G[w][v]= kleur;
					}
					if(bitmap_G[w][v]!=0){
					UB_VGA_SetPixel(v+x, w+ y+10, bitmap_G[w][v]);
					bitmap_G[w][v]=1;
					}
					break;
				case 'h' :
					if(bitmap_H[w][v]==1){ bitmap_H[w][v]= kleur;
					}
					if(bitmap_H[w][v]!=0){
					UB_VGA_SetPixel(v+x, w+ y+10, bitmap_H[w][v]);
					bitmap_H[w][v]=1;
					}
					break;
				case 'i' :
					if(bitmap_I[w][v]==1){ bitmap_I[w][v]= kleur;
					}
					if(bitmap_I[w][v]!=0){
					UB_VGA_SetPixel(v+x, w+ y+10, bitmap_I[w][v]);
					bitmap_I[w][v]=1;
					}
					break;
				case 'j' :
					if(bitmap_J[w][v]==1){ bitmap_J[w][v]= kleur;
					}
					if(bitmap_J[w][v]!=0){
					UB_VGA_SetPixel(v+x, w+ y+10, bitmap_J[w][v]);
					bitmap_J[w][v]=1;
					}
					break;
				case 'k' :
					if(bitmap_K[w][v]==1){ bitmap_K[w][v]= kleur;
					}
					if(bitmap_K[w][v]!=0){
					UB_VGA_SetPixel(v+x, w+ y+10, bitmap_K[w][v]);
					bitmap_K[w][v]=1;
					}
					break;
				case 'l' :
					if(bitmap_L[w][v]==1){ bitmap_L[w][v]= kleur;
					}
					if(bitmap_L[w][v]!=0){
					UB_VGA_SetPixel(v+x, w+ y+10, bitmap_L[w][v]);
					bitmap_L[w][v]=1;
					}
					break;
				case 'm' :
					if(bitmap_M[w][v]==1){ bitmap_M[w][v]= kleur;
					}
					if(bitmap_M[w][v]!=0){
					UB_VGA_SetPixel(v+x, w+ y+10, bitmap_M[w][v]);
					bitmap_M[w][v]=1;
					}
					break;
				case 'n' :
					if(bitmap_N[w][v]==1){ bitmap_N[w][v]= kleur;
					}
					if(bitmap_N[w][v]!=0){
					UB_VGA_SetPixel(v+x, w+ y+10, bitmap_N[w][v]);
					bitmap_N[w][v]=1;
					}
					break;
				case 'o' :
					if(bitmap_O[w][v]==1){ bitmap_O[w][v]= kleur;
					}
					if(bitmap_O[w][v]!=0){
					UB_VGA_SetPixel(v+x, w+ y+10, bitmap_O[w][v]);
					bitmap_O[w][v]=1;
					}
					break;
				case 'p' :
					if(bitmap_P[w][v]==1){ bitmap_P[w][v]= kleur;
					}
					if(bitmap_P[w][v]!=0){
					UB_VGA_SetPixel(v+x, w+ y+10, bitmap_P[w][v]);
					bitmap_P[w][v]=1;
					}
					break;
				case 'q' :
					if(bitmap_Q[w][v]==1){ bitmap_Q[w][v]= kleur;
					}
					if(bitmap_Q[w][v]!=0){
					UB_VGA_SetPixel(v+x, w+ y+10, bitmap_Q[w][v]);
					bitmap_Q[w][v]=1;
					}
					break;
				case 'r' :
					if(bitmap_R[w][v]==1){ bitmap_R[w][v]= kleur;
					}
					if(bitmap_R[w][v]!=0){
					UB_VGA_SetPixel(v+x, w+ y+10, bitmap_R[w][v]);
					bitmap_R[w][v]=1;
					}
					break;
				case 's' :
					if(bitmap_S[w][v]==1){ bitmap_S[w][v]= kleur;
					}
					if(bitmap_S[w][v]!=0){
					UB_VGA_SetPixel(v+x, w+ y+10, bitmap_S[w][v]);
					bitmap_S[w][v]=1;
					}
					break;
				case 't' :
					if(bitmap_T[w][v]==1){ bitmap_T[w][v]= kleur;
					}
					if(bitmap_T[w][v]!=0){
					UB_VGA_SetPixel(v+x, w+ y+10, bitmap_T[w][v]);
					bitmap_T[w][v]=1;
					}
					break;
				case 'u' :
					if(bitmap_U[w][v]==1){ bitmap_U[w][v]= kleur;
					}
					if(bitmap_U[w][v]!=0){
					UB_VGA_SetPixel(v+x, w+ y+10, bitmap_U[w][v]);
					bitmap_U[w][v]=1;
					}
					break;
				case 'v' :
					if(bitmap_V[w][v]==1){ bitmap_V[w][v]= kleur;
					}
					if(bitmap_V[w][v]!=0){
					UB_VGA_SetPixel(v+x, w+ y+10, bitmap_V[w][v]);
					bitmap_V[w][v]=1;
					}
					break;
				case 'w' :
					if(bitmap_W[w][v]==1){ bitmap_W[w][v]= kleur;
					}
					if(bitmap_W[w][v]!=0){
					UB_VGA_SetPixel(v+x, w+ y+10, bitmap_W[w][v]);
					bitmap_W[w][v]=1;
					}
					break;
				case 'x' :
					if(bitmap_X[w][v]==1){ bitmap_X[w][v]= kleur;
					}
					if(bitmap_X[w][v]!=0){
					UB_VGA_SetPixel(v+x, w+ y+10, bitmap_X[w][v]);
					bitmap_X[w][v]=1;
					}
					break;
				case 'y' :
					if(bitmap_Y[w][v]==1){ bitmap_Y[w][v]= kleur;
					}
					if(bitmap_Y[w][v]!=0){
					UB_VGA_SetPixel(v+x, w+ y+10, bitmap_Y[w][v]);
					bitmap_Y[w][v]=1;
					}
					break;
				case 'z' :
					if(bitmap_Z[w][v]==1){ bitmap_Z[w][v]= kleur;
					}
					if(bitmap_Z[w][v]!=0){
					UB_VGA_SetPixel(v+x, w+ y+10, bitmap_Z[w][v]);
					bitmap_Z[w][v]=1;
					}
					break;

				default :
						;
				}
			}
		}
	}
}

/**
 * 		@brief \n Functie waarmee de bitmap wordt getekend.
 */
void maak_bitmap (char *charnummer, char *charx_lo, char *chary_lo)
{
	int nummer = atoi(charnummer);
	int x_lo = atoi(charx_lo);
	int y_lo = atoi(chary_lo);

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

/**
 * 		@brief \n Functie waarmee het scherm schoon wordt gemaakt.
 */
void maak_clearscherm (int kleur)
{
	UB_VGA_FillScreen(kleur);
}

/**
 * 		@brief \n Functie waarmee er wordt gewacht.
 */
void wacht (char *charmsecs)
{
	int msecs = atoi(charmsecs);

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
