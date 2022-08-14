// Se usa la implementación de Stack de: https://www.techiedelight.com/es/stack-implementation/
#include <stdio.h>
#include <math.h>
float stack[8];

void printStack(void)
{
    printf("---CALCULADORA RPN by Julian Gómez---\n");
    printf("           Pila Actual: \n");
    for (int i = 1; i < 9; ++i)
    {
        printf("      %d)", i);
        printf("      %f\n", stack[i]);
    }
}

void moveStackUp(void)
{
    for (int i = 1; i < 9; ++i)
    {
        stack[i - 1] = stack[i];
    }
}

void printMenuPpal(void)
{
    printStack();
    printf("\n");
    printf("-------------------------------------");
    printf("\n");
    printf("¿Ingrese el número\n de lo que Qué desea hacer?: \n");
    printf("1. Ingresar un número\n");
    printf("2. Realizar una operación\n");
    printf("3. Limpiar último valor\n");
    printf("4. Limpiar toda la pila\n");
    printf("5. Salir\n");
}

// void printMenuNum(void)
// {
//     printf("Menu Numeros");
// }

// void printMenuOps(void)
{
    printf("Menu Operaciones");
}

int main()
{
    int opcion_ingresada;

    printMenuPpal();
    scanf(" %d", opcion_ingresada);

    if (opcion_ingresada == 1)
    {
        printf("La opción ingresada fue: \n");
        printf("%d", opcion_ingresada);
        // printMenuNum();
    }
    else if (opcion_ingresada == "2")
    {
        printf("Ingrese una opción válida\n");
        printMenuPpal();
    }
}