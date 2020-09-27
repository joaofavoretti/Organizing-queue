#include <main.h>

/**
 * Function can be used to print all the current stage of the queue [f]
*/
void printEstadoAtualFila(fila_t *f)
{
	printf("\n+++++++++++++++++++++++++++++++++++++++++++");
	for (int i = 0; i < f->totalItems; i++)
		if (f->filaItems[i] != NULL)
			printf("[%d] %s %d %d\n", i, f->filaItems[i], f->filaPersonAge[i], f->filaPersonHealthStage[i]);

	printf("\n");
	printf("lastIndex: %d\t|\t firstIndex: %d\n", f->lastIndex, f->firstIndex);
	printf("totalItems: %d\t|\tTamanho fila: %d\n", f->totalItems, TAM_FILA);
	printf("+++++++++++++++++++++++++++++++++++++++++++\n ");

		return;
}
