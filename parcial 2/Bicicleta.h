#ifndef PAIS_H_INCLUDED
#define PAIS_H_INCLUDED

typedef struct
{
    int id_bici;
    char nombre[128];
    char tipo[128];
    int tiempo;

}eBici;

#endif // PAIS_H_INCLUDED

eBici* bici_New();
eBici* bici_NewParametros(char* id_bici, char* nombre, char* tipo, char* tiempo);

void bicis_borrar(eBici* this);
//FUNCIONES SETTER
int bici_SetId(eBici* this, int id);
int bici_SetNombre(eBici* this, char* nombre);
int bici_SetTipo(eBici* this, char* tipo);
int bici_SetTiempo(eBici* this, int tiempo);
//FUNCIONES GETTER
int bici_GetId(eBici* this, int* id);
int bici_GetNombre(eBici* this, char* nombre);
int bici_GetTipo(eBici* this, char* tipo);
int bici_GetTiempo(eBici* this, int* tiempo);

int listarBicis(LinkedList* listaBicis);

int ordenarPorTipo(void* tipo1, void* tipo2);
int ordenarPorTiempo(void* tiempo1, void* tiempo2);


int ordenarBicis(LinkedList* listaBicis);


int datosRandom(void* a);

int filterTipo(void* pFilter, char* temp);


int ordenarPorTipoXTiempo(void* tipo1, void* tipo2);

void* cambiarTiempo(void* this);
