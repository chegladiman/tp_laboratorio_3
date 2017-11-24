#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<conio.h>
#include "lib.h"

#define Peli 5

int main()
{
    Epeli pelicula[Peli];
    char seguir='s';
    char guardar= 's';
    int i;

    for( i=0; i<Peli; i++)
		pelicula[i].legajo=0;

	if(cargarDesdeArchivo(pelicula))
	{
		printf("No se pudo abrir el fichero");
	}
	else
	{
		printf("Se cargaron las estructuras con exito\n");
	}

    system("cls");
    do
    {
        switch(menu())
        {
        case '1':
            system("cls");
            agregarPelicula(pelicula);
            break;
        case '2':
            system("cls");
            borrarPelicula(pelicula);
            break;
        case '3':
            system("cls");
            ModificarPelicula(pelicula);
            break;
        case '4':
            printf("\nGuardar cambios S/N ?: ");
            guardar = tolower(getche());

				if(guardar == 's')
				{
					if(guardarEnArchivo(pelicula))
					{
						printf("\nNo se pudo abrir el fichero\n");
					}
					else
					{
						printf("\nSe guardo la informacion con exito\n");
					}
                }
				seguir='n';
				break;
        case '5':
            system("cls");
            listar(pelicula);
            break;

        case '6':
            seguir = 'n';
            break;
        }
    }while(seguir == 's');

    return 0;
}

