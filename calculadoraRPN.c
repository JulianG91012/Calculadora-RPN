#include <stdio.h>
#include <math.h>
float stack[8];


void printStack(void)
{
    //Método para imprimir la Pila, tener en cuenta que la posición que muestra como (8) es 
    //la posición [0] de la fila
    printf("---👨‍💻CALCULADORA RPN by Julian Gómez👨‍💻---\n");
    printf("           Pila Actual: \n");
    for (int i = 0; i < 8; i++)
    {
        printf("      %d)", 8 - i);
        printf("      %f\n", stack[i]);
    }
}

void moveStackUp(void)
{
    //Método para 
    int i = 0;
    for (i = 1; i < 8; i++)
    {
        stack[i + 1] = stack[i];
    }
}

void moveStackDown(void)
{
    int i = 0;
    // if(stack[0] == 0)
    // {
        do
        {
            stack[i - 1] = stack[i];
            i++;
        } while (i < 8);
    // }
    // else
    // {
    //     printf("La pila está llena\n");
    //     printf("Elimine un valor o realice una operación para continuar\n");
    // }
}

void addToStack(float num_to_add)
{
    moveStackDown();
    stack[7] = num_to_add;
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



//Por añadir: 
//Verificar si la pila está llena para "no borrar datos de ella" 
//Opción para Guardar Historial de la pila

int main()
{
    int opcion_ingresada;

    do
    {
        printMenuPpal();
        scanf("%d", &opcion_ingresada);

        if (opcion_ingresada == 1)
        {
            float num;
            if (stack[0] == 0)
            {
                printf("\n\n");
                printf("Ingrese el número: \n");
                scanf("%f", &num);
                addToStack(num);
                printf("\n");
                printf("\n");
            }
            else
            {
                printf("\n\n");
                printf("🚧🚧 La pila está llena 🚧🚧\n");
                printf("🚧🚧 Elimine un valor o realice una operación para continuar 🚧🚧\n");
            }     
        }
        if (opcion_ingresada == 2)
        {
            
        }
        if (opcion_ingresada == 3)
        {
        }
        if (opcion_ingresada == 4)
        {
        }
        if (opcion_ingresada == 5)
        {
            break;
        }
    } while (opcion_ingresada != 5);
}