#ifndef BINTREE_H
#define BINTREE_H
#include "boolean.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define nil NULL
#define morseMaxLength 6

/***************************/
/*        TYPE DATA        */
/***************************/
typedef char infotype;
typedef struct tNode *address;
typedef struct tNode {
	infotype info;
	address left;
	address right;
} Node;
typedef address BinTree;

/***************************/
/*  S P E S I F I K A S I  */
/***************************/
void createMorseTree(BinTree *T);
// Membentuk pohon morse sesuai standar internasional
boolean isEmpty(BinTree T);
// Mengirimkan true jika binary tree kosong

/***************************/
/*        TRAVERSAL        */
/***************************/
void PreOrder(BinTree T); 
// Traversal pr, fs, nb
void InOrder(BinTree T); 
// Traversal fs, pr, nb
void PostOrder(BinTree T); 
// Traversal fs, nb, pr
void LevelOrder(BinTree T); 
// Traversal level based node

/***************************/
/*       FUNGSI LAIN       */
/***************************/
void PrintTree(BinTree T, int space);
/* Menampilkan struktur pohon secara visual */
static void printRecursive(BinTree node, int level);
/* Deklarasi fungsi helper untuk rekursi */
boolean Search(BinTree T, infotype X);
/* Mencari node dengan info X */
int CountLeaves(BinTree T);
/* Menghitung jumlah daun */
int NodeLevel(BinTree T, infotype X, int level);
/* Mencari level node X */
int TreeDepth(BinTree T);
/* Menghitung kedalaman pohon */

/***************************/
/*      KONVERSI MORSE     */
/***************************/
void FindMorseCode(BinTree T, char c, char *path, int level, char *result);
/* Mencari kode morse yang sudah ada */
void StringToMorse(BinTree T, char *str);
/* Mengkonversi string ke sandi morse */
void MorseToChar(BinTree T, char *morse, char *result);
/* Mengkonversi morse ke charater */
void MorseToString(BinTree T, char *morseCode);
/* Mengkonversi sandi morse ke string */
void FileToMorse(BinTree T, char *inputFile, char *outputFile);
/* Mengkonversi isi file teks ke morse */

#endif
