#include <main.h>

int main(int argc, char **argv)
{
	int nEntries, personAge, personHealthStage, personLeftAge, personLeftHealthStage;
	char listAction[20], *personName, *personLeftName;

	fila_t *idosos_problema_saude;
	fila_t *jovens_problema_saude;
	fila_t *idosos_normal;
	fila_t *jovens_normal;

	idosos_problema_saude = createFila();
	jovens_problema_saude = createFila();
	idosos_normal = createFila();
	jovens_normal = createFila();

	scanf("%d", &nEntries);

	for (int i = 0; i < nEntries; i++)	// Main loop
	{
		scanf("%s ", listAction);
		if (!command_ENTRY(listAction)) // condition for the "ENTRA" command read
		{

			personName = allocStringInMemory(stdin);
			scanf("%d %d", &personAge, &personHealthStage);

			if (personAge < 60)
			{
				if (personHealthStage == 0) // HealthStage == normal
				{ 
					pushItem(jovens_normal, personName);
					pushAge(jovens_normal, personAge);
					pushHealthStage(jovens_normal, personHealthStage);
				}
				else 						// HealthStage == disease
				{
					pushItem(jovens_problema_saude, personName);
					pushAge(jovens_problema_saude, personAge);
					pushHealthStage(jovens_problema_saude, personHealthStage);
				}
			}
			else
			{
				if (personHealthStage == 0) // HealthStage == normal
				{
					pushItem(idosos_normal, personName);
					pushAge(idosos_normal, personAge);
					pushHealthStage(idosos_normal, personHealthStage);
				}
				else 						// HealthStage == disease
				{
					pushItem(idosos_problema_saude, personName);
					pushAge(idosos_problema_saude, personAge);
					pushHealthStage(idosos_problema_saude, personHealthStage);
				}
			}
		}
		else if (!command_EXIT(listAction)) // condition for the "SAI" command read
		{
			// Order of the if statements follow the priority given
			if (idosos_problema_saude->totalItems != 0)
			{
				personLeftName = popItem(idosos_problema_saude);
				personLeftAge = popAge(idosos_problema_saude);
				personLeftHealthStage = popHealthStage(idosos_problema_saude);

				printf("%s %d %d\n", personLeftName, personLeftAge, personLeftHealthStage);
				free(personLeftName);
			}
			else if (jovens_problema_saude->totalItems != 0)
			{
				personLeftName = popItem(jovens_problema_saude);
				personLeftAge = popAge(jovens_problema_saude);
				personLeftHealthStage = popHealthStage(jovens_problema_saude);

				printf("%s %d %d\n", personLeftName, personLeftAge, personLeftHealthStage);
				free(personLeftName);
			}
			else if (idosos_normal->totalItems != 0)
			{
				personLeftName = popItem(idosos_normal);
				personLeftAge = popAge(idosos_normal);
				personLeftHealthStage = popHealthStage(idosos_normal);

				printf("%s %d %d\n", personLeftName, personLeftAge, personLeftHealthStage);
				free(personLeftName);
			}
			else if (jovens_normal->totalItems != 0)
			{
				personLeftName = popItem(jovens_normal);
				personLeftAge = popAge(jovens_normal);
				personLeftHealthStage = popHealthStage(jovens_normal);

				printf("%s %d %d\n", personLeftName, personLeftAge, personLeftHealthStage);
				free(personLeftName);
			}
			else
			{
				printf("FILA VAZIA\n");
			}
		}
	}

	freeFila(idosos_problema_saude);
	freeFila(jovens_problema_saude);
	freeFila(idosos_normal);
	freeFila(jovens_normal);
	return 0;
}
