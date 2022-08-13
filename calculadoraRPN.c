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
    char opcion_ingresada;
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
    opcion_ingresada = scanf("%c");

    switch (opcion_ingresada)
    {
    case "1":
        printMenuNum();
        break;
    case "2":
        
        break;    
    case "3":
        
        break;
    case "4":
        
        break;
    case "5":
        
        break;
    default:
        break;
    }
}

void printMenuNum(void)
{

}

void printMenuOps(void)
{

}

int main()
{
    
    printMenuPpal();
}