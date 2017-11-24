#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<conio.h>

#include "lib.h"
#define Peli 5

char menu()
{
    char c;
    system("cls");
    printf("MENU\n1. Agregar pelicula\n2. Borrar pelicula\n3. Modificar datos de pelicula\n4. Generar pagina web\n5. Crear lista\n6. Salir\n");
    printf("Elija una opcion: ");
    c=getche();
    return c;
}

int buscarLibre(Epeli *pelicula)
{
    int index=-1;
    int i;
    for( i=0; i < Peli; i++)
        if(pelicula[i].legajo==0)
        {
            index=i;
            break;
        }
    return index;
}

int agregarPelicula(Epeli *pelicula)
{
    int index, i, legajo;
    char titulo[20];
    char genero[20];
    char descripcion[51];
    char auxDuracion[20];
    char auxPuntaje[10];
    char auxLegajo[10];
    int encontro=0;


    index=buscarLibre(pelicula);
    if(index!=-1)
    {

		printf("Ingrese legajo: ");
		scanf("%d", &legajo);
        for(i=0; i<Peli; i++)
        {
            if(legajo==pelicula[i].legajo)
            {
                encontro=1;
                break;
            }
        }
        if(!encontro)
        {
            system("cls");
            printf("\nEl legajo esta permitido\n");
            if(!getStringLetras("Ingresar titulo de la pelicula: ", titulo))
            {
                printf("\nEl titulo debe contener solo letras.\n");
            }
            fflush(stdin);
            strcpy(pelicula[index].titulo,titulo);

            if(!getStringLetras("Ingresar el genero de la pelicula: ", genero))
            {
                printf("\nEl genero debe contener solo letras.\n");
            }
            fflush(stdin);
            strcpy(pelicula[index].genero,genero);

            if(!getStringNumeros("Ingrese Duracion: ", auxDuracion))
            {
                printf("\nLa informacion de la duracion de la pelicula debe contener solo numeros.\n");
            }
            pelicula[index].duracion = atoi(auxDuracion);

            if(!getStringLetras("Ingresar la descripcion de la pelicula: ", descripcion))
            {
                printf("\nLa descripcion debe contener solo letras.\n");
            }
            fflush(stdin);
            strcpy(pelicula[index].descripcion,descripcion);

            if(!getStringNumerosFlotantes("Ingresar el puntaje de la pelicula: ", auxPuntaje))
            {
                printf("\nEl puntaje debe contener solo numeros.\n");
            }
            pelicula[index].puntaje = atof(auxPuntaje);

            if(!getStringNumeros("Ingrese Legajo: ", auxLegajo))
            {
                printf("\nEl legajo debe contener solo numeros.\n");
            }
            pelicula[index].legajo = atoi(auxLegajo);

            system("cls");
        }
        else
        {
            printf("\nLa pelicula ya existe!!\n");
            getch();
        }
    }
    else
    {
        printf("\nNo queda espacio\n");
        getch();
    }
    return 0;
}

int borrarPelicula(Epeli *pelicula)
{
	int legajo, flag=0,i;
	char opcion;
	printf("Ingrese legajo de la pelicula a eliminar: ");
	scanf("%d", &legajo);

	for(i=0; i<Peli; i++)
	{
		if(legajo==pelicula[i].legajo)
		{
			printf("Pelicula a eliminar:\n");

			toString(pelicula + i);

			printf("\nPelicula encontrada. ¨Seguro desea dar de baja?");
			opcion=getche();
			if(opcion=='s')
			{
				pelicula[i].legajo=0;
				printf("Pelicula eliminada!!");
			}
			else
			{
				printf("La pelicula no fue eliminado!");
			}
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		printf("Legajo inexistente");
		getch();
	}
	return 0;
}

int ModificarPelicula(Epeli *pelicula)
{
	int legajo, flag=0,i;
	char opcion;
	char titulo[21];
    char genero[21];
    char descripcion[51];
    char auxDuracion[21];
    char auxPuntaje[21];
	system("cls");
	printf("Ingrese legajo de la pelicula a modificar: ");
	scanf("%d",& legajo);
	for( i=0; i<Peli; i++)
	{
		if(legajo==pelicula[i].legajo)
		{
			printf("Pelicula encontrada:\n");

			toString((pelicula + i));

			if(!getStringLetras("Ingrese nuevo Titulo: ",titulo))
            {
                printf("El titulo debe contener solo letras.\n");
                break;
            }

            if(!getStringLetras("Ingrese nuevo Genero: ",genero))
            {
                printf("El genero debe contener solo letras.\n");
                break;
            }

            if(!getStringLetras("Ingrese nueva Descripcion: ",descripcion))
            {
                printf("La descripcion debe contener solo letras.\n");
                break;
            }

            if(!getStringNumeros("Ingrese la nueva duracion: ",auxDuracion))
            {
                printf("La duracion debe contener solo numeros.\n");
            }

            if(!getStringNumerosFlotantes("Ingrese el nuevo Puntaje: ",auxPuntaje))
            {
                printf("El puntaje debe contener solo numeros.\n");
            }

			printf("Esta seguro que desea modificar? ");
			opcion=getche();
			if(opcion=='s')
			{
                strcpy(pelicula[i].titulo,titulo);
                strcpy(pelicula[i].genero,genero);
                strcpy(pelicula[i].descripcion,descripcion);
                pelicula[i].duracion = atoi(auxDuracion);
                pelicula[i].puntaje = atof(auxPuntaje);
				printf("Pelicula modificada");
			}
			else
			{
				printf("El registro no fue modificado");
			}
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		printf("Legajo inexistente");
		getch();
	}
	return 0;
}

void toString(Epeli *pelicula)
{
	printf("%d\t%s\t%s\t%.2f\t%s\t%d\n", pelicula->legajo, pelicula->titulo, pelicula->genero, pelicula->puntaje, pelicula->descripcion, pelicula->duracion);
}

void listar(Epeli *pelicula)
{
	int i,j;
	Epeli auxMovie;

	for(i=0; i<Peli-1;i++)
	{
		for(j=i+1; j<Peli; j++)
		{
			if(strcmp(pelicula[i].titulo,pelicula[j].titulo)>0)
			{
				auxMovie=pelicula[i];
				pelicula[i]=pelicula[j];
				pelicula[j]=auxMovie;
			}
		}
	}

	printf("Legajo\tTitulo\tGenero\tPuntaje\tDescripcion\tDuracion\n");
	for(i=0; i<Peli; i++)
	{
		if(pelicula[i].legajo!=0)
		   toString((pelicula + i));

	}
	getch();
}

int guardarEnArchivo(Epeli *x)
{

	FILE *f;

		f=fopen("bin.dat","wb");
		if(f == NULL)
		{
			return 1;
		}

	fwrite(x,sizeof(Epeli),Peli,f);

	fclose(f);

	return 0;
}

int cargarDesdeArchivo(Epeli *x)
{
    int flag = 0;
    FILE *f;

    f=fopen("bin.dat", "rb");
    if(f==NULL)
    {
        f= fopen("bin.dat", "wb");
        if(f==NULL)
        {
            return 1;
        }

        flag=1;

    }

    if(flag ==0)
    {
        fread(x, sizeof(Epeli), Peli, f);
    }

    fclose(f);
    return 0;

}

int esNumerico(char str[])
{
    int i = 0;
    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}

int esSoloLetras(char str[])
{
    int i = 0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return 0;
        i++;
    }
    return 1;
}

int esNumericoFlotante(char str[])
{
    int i=0;
    int cantidadPuntos=0;
    while(str[i] != '\0')
    {
        if (i == 0 && str[i] == '-')
        {
            i++;
            continue;

        }
        if (str[i] == '.' && cantidadPuntos == 0)
        {
            cantidadPuntos++;
            i++;
            continue;

        }
        if(str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}

void getString(char mensaje[], char input[])
{
    printf(mensaje);
    scanf("%s", input);
}

int getStringLetras(char mensaje[], char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}


int getStringNumeros(char mensaje[], char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int getStringNumerosFlotantes(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumericoFlotante(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}
