#include <main.h>

/**
 * Functions responsable to return a fila_t usable pointer
 * 
 * Return:
 *  fila_t calloced pointer;
 * 
*/
fila_t *createFila()
{
    fila_t *f;
    f = (fila_t *)calloc(sizeof(fila_t), 1 * sizeof(fila_t));

    return f;
}

/**
 * Void functions responsable to free all the elements that was previously
 * alloced by the fila_t functions.
 * 
*/
void freeFila(fila_t *f)
{
    for (int i = f->firstIndex; f->totalItems == 0; ++i)
    {
        free(f->filaItems[i]);
        f->filaItems[i] = NULL;
        f->totalItems--;
    }

    free(f);
    f = NULL;

    return;
}