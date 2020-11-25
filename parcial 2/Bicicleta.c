#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Linkedlist.h"
#include "Bicicleta.h"

//Nueva bici
eBici* bici_New()
{
    eBici* pBici;
    pBici = (eBici*) malloc(sizeof(eBici));

return pBici;
}
//Borrar bici
void bicis_borrar(eBici* this)
{
    if(this != NULL)
        {
            free(this);
        }
}

//Nuevos parametros para la bici
eBici* bici_NewParametros(char* id_bici, char* nombre, char* tipo, char* tiempo)
{
    eBici* pBici = NULL;
	pBici = bici_New();

	if(id_bici != NULL && nombre != NULL && tipo != NULL && tiempo != NULL)
	{

		if(bici_SetId(pBici, atoi(id_bici)) == -1 || bici_SetNombre(pBici, nombre) == -1 || bici_SetTipo(pBici, tipo) == -1 || bici_SetTiempo(pBici, atoi(tiempo)) == -1)
            {
                bicis_borrar(pBici);
                pBici = NULL;
            }
            else
            {
                bici_SetId(pBici, atoi(id_bici));
                bici_SetNombre(pBici, nombre);
                bici_SetTipo(pBici, tipo);
                bici_SetTiempo(pBici, atoi(tiempo));
            }
	}
return pBici;
}

//Le hago cargar los datos de la ID
int bici_SetId(eBici* this, int id)
{
    int retorno = 0;
    if(this != NULL && id > 0)
        {
            this->id_bici = id;
            retorno = 1;
        }
return retorno;
}
//le hago obtener los datos de ID
int bici_GetId(eBici* this, int* id)
{
    int retorno = 0;

    if(this != NULL && id != NULL)
        {
            *id = this->id_bici;
            retorno = 1;
        }

return retorno;
}
//Le hago cargar los datos del Nombre
int bici_SetNombre(eBici* this, char* nombre)
{
    int retorno = 0;
    if (this != NULL && nombre != NULL)
    {
        strcpy(this->nombre, nombre);
        retorno = 1;
    }
return retorno;
}
//le hago obtener los Noombres
int bici_GetNombre(eBici* this, char* nombre)
{
    int retorno = 0;
    if (this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        retorno = 1;
    }

    return retorno;
}
//Le hago cargar los datos del Tipo
int bici_SetTipo(eBici* this, char* tipo)
{
    int retorno = 0;
    if(this != NULL && tipo != NULL)
    {
        strcpy(this->tipo, tipo);
        retorno = 1;
    }
    return retorno;
}
//Le hago obtener los datos del Tipo
int bici_GetTipo(eBici* this, char* tipo)
{
    int retorno = 0;

    if(this != NULL && tipo != NULL)
    {
        strcpy(tipo, this->tipo);
        retorno = 1;
    }

    return retorno;
}
//Cargo los datos del tiempo
int bici_SetTiempo(eBici* this, int tiempo)
{
    int retorno = 0;
    if(this != NULL)
    {
        this->tiempo = tiempo;
        retorno = 1;
    }

    return retorno;
}
//Le hago obtener los datos del tiempo
int bici_GetTiempo(eBici* this, int* tiempo)
{
    int retorno = 0;
    if(this != NULL)
        {
            *tiempo = this->tiempo;
            retorno = 1;
        }
return retorno;
}

//Filtro el tipo de bici
int filterTipo(void* pFilter, char* temp)
{
    int retorno= 0;


    if(pFilter!=NULL)
    {
        eBici* pBici = (eBici*)pFilter;

        if(strcmp(pBici->tipo, temp)==0)
        {
            retorno=1;
        }
    }
    return retorno;
}
//Listo las bicis segun su categoria
int listarBicis(LinkedList* listaBicis)
{
    eBici* pBici;
    int retorno = 0;

    int auxId;
    char auxNombre[100];
    char auxTipo[100];
    int auxTiempo;

    int tamLista;
    int i;

    tamLista= ll_len(listaBicis);

    if(listaBicis != NULL)
    {

        if(tamLista>0)
        {
            printf(" Id          Nombre          Tipo        Tiempo\n");

            for(i = 0; i < tamLista; i++)
            {
                pBici = (eBici*)ll_get(listaBicis, i);

                bici_GetId(pBici, &auxId);
                bici_GetNombre(pBici, auxNombre);
                bici_GetTipo(pBici, auxTipo);
                bici_GetTiempo(pBici, &auxTiempo);

                printf("%3d  %13s   %13s  %d\n",auxId, auxNombre, auxTipo, auxTiempo);
                //printf("%3d  %13s   %13s\n",auxId, auxNombre, auxTipo);
            }
            retorno = 1;
        }
    }
return retorno;
}

//Ordeno Tipo y Tiempo a la vez en un listado
int ordenarPorTipoXTiempo(void* tipo1, void* tipo2)
{
    int retorno=0;

    int compararPorTipo;

    eBici* aux1;
    eBici* aux2;

    if(tipo1!=NULL && tipo2!=NULL)
    {
        aux1=(eBici*)tipo1;
        aux2=(eBici*)tipo2;

        compararPorTipo=strcmp(aux1->tipo,aux2->tipo);

        if(compararPorTipo!=0)
        {
            retorno=compararPorTipo;
        }
        else if(compararPorTipo==0 && aux1->tiempo<aux2->tiempo)
        {
            retorno=-1;
        }
        else if(compararPorTipo==0 && aux1->tiempo>aux2->tiempo)
        {
            retorno=1;
        }
    }

    return retorno;
}
//Ordeno por tipo la bici
int ordenarPorTipo(void* tipo1, void* tipo2)
{
    int retorno=0;

    eBici* auxTipo1=tipo1;
    eBici* auxTipo2=tipo2;

    retorno = strcmp(auxTipo1->tipo, auxTipo2->tipo);

    return retorno;
}
//Ordena por tiempo
int ordenarPorTiempo(void* tiempo1, void* tiempo2)
{
    int retorno=0;
    eBici* p1=(eBici*)tiempo1;
    eBici* p2=(eBici*)tiempo2;

    if(p1->tiempo == p2->tiempo)
    {
        retorno=0;
    }

    else if(p1->tiempo > p2->tiempo)
    {
        retorno=1;
    }
    else
    {
        retorno=-1;
    }

    return retorno;
}

//Ordena en listado completo las bicis
int ordenarBicis(LinkedList* listaBicis)
{

    system("cls");
	int retorno = 0;
	LinkedList* pLista = ll_newLinkedList();


	if((pLista = ll_clone(pLista)) != NULL)
    {
        system("cls");
        ll_sort(pLista, ordenarPorTipo, 0);
    }

    printf("***** Listado de Bicis *****\n");
    printf("\n ID \tNombre \t       Tipo   \t          Tiempo\n\n");
    listarBicis(pLista);

    ll_deleteLinkedList(pLista);

    return retorno;
}

//Tiempo pedido por el profe
void* cambiarTiempo(void* this)
{

    void * retorno = NULL;
    int aleatorio;
    if( this != NULL)
    {
       eBici*auxBicicleta = (eBici*)this;
        aleatorio = rand()%(71)+50;
        bici_SetTiempo(auxBicicleta, aleatorio);
        retorno = (void*) auxBicicleta;
    }
    return retorno;
}
