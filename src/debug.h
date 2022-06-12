#ifndef DEBUG_H
#define DEBUG_H
#include <stdio.h>
#include <unistd.h>
#define TEST printf("[(%s/%d) %s ]\n", __FILE__, __LINE__, __func__); fflush(stdin);
#define TEST_ printf("---------------------------------------------[(%s/%d) %s ]\n", __FILE__, __LINE__, __func__); fflush(stdin);
#define TESTn(i) printf("[(%s/%d) %s ]%s:%d\n", __FILE__, __LINE__, __func__, #i, (int)(i)); fflush(stdin);
#define TESTp(i) printf("[(%s/%d) %s ]%s:%p\n", __FILE__, __LINE__, __func__, #i, (i)); fflush(stdin);
#define STOP {char c; read(STDIN_FILENO, &c, sizeof(char));}
//#ifndef _H /* ヘッダーファイル名 */
//#include ""/* ヘッダーファイル名 */
//#endif

/* テストに使うしたい関数 */


#endif

/* 一定回数でプログラムを強制終了 */

//* test */static	size_t stc = 0;
//* test */const int stc_max = 10000;
//* test */const int onoff = 1;
//* test */stc++;
//* test */if (stc > stc_max && onoff)
//* test */{
//* test */	printf("the number is too big"); TEST
//* test */	exit(0);
//* test */}


/*ショートカット

#include "debug.h"

TESTn("s->len", s->len)
TESTn("s->grd", s->grd)
TESTn("s->udr", s->udr)



 */
