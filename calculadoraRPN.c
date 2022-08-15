// Se usa la implementación de Stack de: https://www.techiedelight.com/es/stack-implementation/
#include <stdio.h>
#include <math.h>
float stack[8];

void printStack(void)
{
    printf("---CALCULADORA RPN by Julian Gómez---\n");
    printf("           Pila Actual: \n");
    for (int i = 0; i < 8; ++i)
    {
        printf("      %d)", 8 - i);
        printf("      %f\n", stack[i]);
    }
}

void moveStackUp(void)
{
    int i = 0;
    for (i = 1; i < 8; ++i)
    {
        stack[i + 1] = stack[i];
    }
}

void moveStackDown(void)
{
    int i = 0;
    for (i = 8; i > 1; --i)
    {
        stack[i - 1] = stack[i];
    }
}

void addToStack(float num_to_add)
{
    stack[0] = num_to_add;
    moveStackDown();
    // moveStackUp();
    printf("\n");
    printStack();
    printf("\n");
    printf("\n");
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
    printf("-------------------------------------\n");
    printf("\n");
    printf("\n");
}

void printMenuNum(void) // int numero
{
    float num;
    printf("Ingrese el número: \n");
    scanf("%f", &num);
    addToStack(num);
    printf("Hola");
    printf("\n");
    printf("\n");
    // printMenuPpal();
}

// void printMenuOps(void)
// {
//     printf("Menu Operaciones");
// }

int main()
{
    int opcion_ingresada;

    printMenuPpal();
    scanf("%d", &opcion_ingresada);

    if (opcion_ingresada == 1)
    {
        // float num;
        printMenuNum();
        // scanf("%f", &num);

        // printf("El número ingresado fue de: %f", num);

        // Estructura base:
        //  printMenuNum(num);
        //  scanf("%f", &num);
    }
    else if (opcion_ingresada == 2)
    {
        printf("Ingrese una opción válida\n");
        printMenuPpal();
    }
}