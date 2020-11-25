#include <stdio.h>
#include <stdlib.h>
#include "Linkedlist.h"
#include "Bicicleta.h"
#include "parser.h"
//Pasar a texto
int parser_BiciFromText(FILE* miFile, LinkedList* pMiLista)
{
	eBici* pBici;
    int retorno = 0;
	char id[200];
	char nombre[200];
	char tipo[200];
	char tiempo[200];

	if(miFile != NULL && pMiLista != NULL)
	{
	    fscanf(miFile,"%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, tipo, tiempo);
		do
		{
			if(fscanf(miFile,"%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, tipo, tiempo) == 4)
			{
				pBici = bici_NewParametros(id, nombre, tipo, tiempo);

				if(pBici != NULL)
				{
					ll_add(pMiLista, pBici);
					retorno = 1;
				}
			}
			else
			{
				break;
			}

		}while(feof(miFile) == 0);
	}
return retorno;
}


int cargarTexto(char* path , LinkedList* pLista)
{
	FILE* pFile;
	int retorno = 1;

	pFile = fopen(path, "r"); //Abre el archivo para leerlo de texto, si es que existe.

	if(pFile != NULL)
	{
		if(parser_BiciFromText(pFile, pLista) == 1)
		{
		    //Si todo salio bien cambia a 0
		    retorno = 0;
			printf("\nLos datos de los paises en modo texto fueron cargados corretamente\n\n");
		}
	}

	fclose(pFile);

    return retorno;

}


int guardarComoTexto(char* path, LinkedList* pLista)
{
	FILE* pFile;
	eBici* pBici;

	int auxId;
	char auxNombre[25];
	char auxTipo[25];
	int auxTiempo;
	int retorno = 0;

	if(pLista!=NULL && path!=NULL)
	{
		pFile= fopen(path, "w");
		if(pFile!=NULL)
		{
			retorno = 1;
			for(int i = 0; i < ll_len(pLista); i++)
			{
				pBici = (eBici*)ll_get(pLista, i);
                bici_GetId(pBici, &auxId);
                bici_GetNombre(pBici, auxNombre);
                bici_GetTipo(pBici, auxTipo);
                bici_GetTiempo(pBici, &auxTiempo);

                fprintf(pFile, "%d,%s,%s,%d\n", auxId, auxNombre, auxTipo, auxTiempo);
			}

			fclose(pFile);

			printf("Archivo guardado correctamente\n");
		}
		else if(retorno == 0)
        {
            printf("Error\n");
        }
	}

    return retorno;
}
/*
int parser_PaisFromBinary(FILE* miFile, LinkedList* pMiLista)
{
    ePais* auxPais;
    int i = 0;

    fread(&auxPais, sizeof(ePais), 1, miFile);
    while(!feof(miFile))
        {
            ePais* paisNew = pais_New();
            pais_SetId(paisNew, auxPais->id);
            pais_SetNombre(paisNew, auxPais->nombre);
            pais_SetInfectados(paisNew, auxPais->infectados);
            pais_SetRecuperados(paisNew, auxPais->recuperados);
            pais_SetMuertos(paisNew, auxPais->muertos);
            i++;
            ll_add(pMiLista, paisNew);
            fread(&auxPais, sizeof(ePais), 1, miFile);
        }
return i;
}
*/
