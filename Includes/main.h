/**
 * Header file for "queue-Operations.c", "queue-Setup.c" and "state-functions.c" files
 */

#ifndef _MAIN_H_
#define _MAIN_H_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <IO-Operations.h>

/**
 * Struct fila_t to store the items for a single queue
 * 
 * - Array of strings
 * - Array of 32bit integer
 * - Array of 32bit integer
 * 
 * All arrays are sized "TAM_FILA"
 */
#define TAM_FILA 100	// Variable size of the fila_t arrays
struct fila
{
	int firstIndex, lastIndex, totalItems;
	char *filaItems[TAM_FILA];
	int filaPersonAge[TAM_FILA];
	int filaPersonHealthStage[TAM_FILA];
};
typedef struct fila fila_t;

/**
 * queue-Operations.c
 */
int filaIsFull(fila_t *f);
int pushItem(fila_t *f, char *string);
char *popItem(fila_t *f);

int pushAge(fila_t *f, int age);
int pushHealthStage(fila_t *f, int age);
int popAge(fila_t *f);
int popHealthStage(fila_t *f);

/**
 * queue-Setup.c
 */
fila_t *createFila();
void freeFila(fila_t *f);

/**
 * state-functions.c
 */
void printEstadoAtualFila(fila_t *f);

#endif
