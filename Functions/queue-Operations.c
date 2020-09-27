#include <main.h>

/**
 * Check if the fila_t pointer has a vector fully completed with values.
 * 
 * Based on the "TAM_FILA" value pre-setted.
 * 
 * Return:
 *  0 if the fila_t vectors are not full
 *  1 if the fila_t vectors are full 
*/
int filaIsFull(fila_t *f)
{
    if (f == NULL)
    {
        return -1;
    }

    return (f->totalItems == TAM_FILA);
}

/**
 * Push [string] on the fila_t (filaItems)vector of strings.
 * 
 * Return:
 *  1 if successfully done
 *  -1 if [f] vector is full
 * 
*/
int pushItem(fila_t *f, char *string)
{
    if (!filaIsFull(f))
    {
        f->filaItems[f->lastIndex] = string;
        f->lastIndex = (f->lastIndex + 1) % TAM_FILA;
        f->totalItems++;
        return 1;
    }

    return -1;
}

/**
 * Push [age] on the fila_t (filaPersonAge)vector of 32bit integers.
 * 
 * Return:
 *  1 if successfully done
 *  -1 if [f] vector is full
 * 
*/
int pushAge(fila_t *f, int age)
{
    if (!filaIsFull(f))
    {
        f->filaPersonAge[f->lastIndex - 1] = age;
        return 1;
    }

    return -1;
}

/**
 * Push [age] on the fila_t (filaPersonHealthStage)vector of 32bit integers.
 * 
 * Return:
 *  1 if successfully done
 *  -1 if [f] vector is full
 * 
*/
int pushHealthStage(fila_t *f, int type)
{
    if (!filaIsFull(f))
    {
        f->filaPersonHealthStage[f->lastIndex - 1] = type;
        return 1;
    }

    return -1;
}

/**
 * Pop item from the fila_t[f] pointer (filaItems)vector of strings
 * After the operations, the string is removed from the queue.
 * 
 * Return:
 *  Pointer to string popped 
 *  -1 if [f] is NULL
*/
char *popItem(fila_t *f)
{
    if (f == NULL)
    {
        return (char *)-1;
    }

    char *retString;

    retString = f->filaItems[f->firstIndex];
    f->filaItems[f->firstIndex] = NULL;
    f->firstIndex = (f->firstIndex + 1) % TAM_FILA;
    f->totalItems--;

    return retString;
}

/**
 * Pop item from the fila_t[f] pointer (filaPersonAge)vector of 32bit integers
 * 
 * 
 * Return:
 *  integer popped from the queue 
 *  -1 if [f] is NULL
*/
int popAge(fila_t *f)
{
    if (f == NULL)
    {
        return -1;
    }

    return f->filaPersonAge[f->firstIndex - 1];
}

/**
 * Pop item from the fila_t[f] pointer (filaPersonHealthStage)vector of 32bit integers
 * 
 * 
 * Return:
 *  integer popped from the queue 
 *  -1 if [f] is NULL
*/
int popHealthStage(fila_t *f)
{
    if (f == NULL)
    {
        return -1;
    }
    return f->filaPersonHealthStage[f->firstIndex - 1];
}