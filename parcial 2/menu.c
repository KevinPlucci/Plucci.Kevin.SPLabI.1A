#include <stdio.h>
#include <stdlib.h>
#include "Linkedlist.h"
#include "utn.h"
#include "Bicicleta.h"
#include "parser.h"
#include <time.h>// incluir la libreria time.h


//Menu de opciones
int main()
{
srand (time(NULL));  // esta linea va al inicio de main

    int opcion = 0;
    char salir[3];
    char aux;

    int opcionBici;
    int retornoFilter;

    //Linkelist que utilizo para el menu
    LinkedList* listaPrincipal = ll_newLinkedList();
    LinkedList* listaOrdenada= NULL;
    LinkedList* listaMapeada = NULL;
    LinkedList* listaTipo = NULL;
    do
    {   strcpy(salir,"no");


        getInt("\n\n-----------Menu----------\n\n1) Cargar archivo bici.csv \n2) Imprimir lista de bicis\n3) Asignar tiempos de bicis\n4) Filtrar por tipo de bicis \n5) Mostrar posiciones\n6) Guardar posiciones \n7) Salir\n\n >","Error\n", 1, 3, 0, &opcion);
        printf("\n\n");
        switch(opcion)
        {
        case 1:
                if(cargarTexto("bicicletas.csv", listaPrincipal) == 1)
                    {
                        printf("Archivo cargado con exito\n");
                    }
                else
                    {
                        printf("hay quilombo");
                    }


            system("pause");
            break;
        case 2:
                if(listarBicis(listaPrincipal))
                    {
                        printf("Lista cargada con exito\n");
                    }
                else
                    {
                        printf("hay quilombo");
                    }

            system("pause");
            break;
        case 3:

            listaMapeada = ll_map(listaPrincipal, datosRandom);
            listarBicis(listaMapeada);
            system("pause");

            break;
        case 4:



            getInt("- Elija el tipo de bicicleta a filtrar.\n1. BMX\n2. PLAYERA\n3. MTB\n4. PASEo\n>","Error, escriba un numero del 1 al 4", 1,4,4, &opcionBici);

            char temp[20];

            switch(opcionBici)
            {
                case 1:
                    strcpy(temp,"BMX");
                break;
                case 2:
                    strcpy(temp,"PLAYERA");
                break;
                case 3:
                    strcpy(temp, "MTB");
                break;
                case 4:
                    strcpy(temp, "PASEO");
                break;
            }

            listaTipo= ll_filter_parametro(listaPrincipal, filterTipo, temp);

            listarBicis(listaTipo);
            guardarComoTexto("bicicletasTipo.csv", listaTipo);

            system("pause");
            break;
        case 5:

            listaOrdenada= ll_clone(listaPrincipal);

            if(listaOrdenada!=NULL)
            {
                ll_sort(listaOrdenada, ordenarPorTipoXTiempo, 1);
            }
            //guardarComoTexto("bicicletasOrdenadas.csv", listaOrdenada);
            listarBicis(listaOrdenada);

            system("pause");
            break;
        case 6:

            guardarComoTexto("bicicletasOrdenadas.csv", listaOrdenada);

            system("pause");
            break;
        case 7:
            printf("Los datos no seran guardados\n Seguro que desea salir? ");
            fflush(stdin);
            scanf("%c", &aux);
            while(aux != 's' && aux != 'n')
            {
                printf("Opcion incorrecta. Reingrese 's'(si) o 'n'(no)");
                printf(" s/n : \n");
                fflush(stdin);
                scanf("%c", &aux);
            }

            if(aux == 's')
            {
                printf("Gracias. Vuelva pronto!!!\n");
                return 0;
            }


            system("pause");
            break;;
        default:
            printf("Opcion incorrecta. Reingrese\n");
            system("pause");
        }

        system("cls");
    }
    while(strcmp(salir,"si")!= 0);

    ll_deleteLinkedList(listaMapeada);
    ll_deleteLinkedList(listaOrdenada);
    ll_deleteLinkedList(listaPrincipal);
    ll_deleteLinkedList(listaTipo);
    return 0;
}
