#include <math.h>
#include <stdio.h>

//#include <ctype.h> para cuando se use el isdigit(c)
float stack[8];

void printStack(void)
{
    // Método para imprimir la Pila, tener en cuenta que la posición que muestra como (8) es
    // la posición [0] de la fila
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
    // Método para
    for (int i = 7; i >= 0; i--)
    {
        stack[i] = stack[i - 1];
    }
}

void moveStackDown(void)
{
    int i = 0;
    do
    {
        stack[i - 1] = stack[i];
        i++;
    } while (i < 8);
}

void addToStack(float num_to_add)
{
    // Método para agregar a la pila el número ingresado
    stack[7] = num_to_add;
    printf("\n");
    printf("\n");
}

void clearStack(void)
{
    for(int i = 0; i < 8; i++)
    {
        stack[i] = 0;
    }
}

void printMenuPpal(void)
{
    // Método para mostrar el menú principal con las opciones a elegir
    printStack();
    printf("-------------------------------------");
    printf("\n");
    printf("1. Ingresar un número\n");
    printf("2. Realizar una operación\n");
    printf("3. Limpiar último valor\n");
    printf("4. Limpiar toda la pila\n");
    printf("5. Salir\n");
    printf("Ingrese su respuesta a continuación: \n");
    printf("-------------------------------------\n");
    printf("\n");
}

// void calculadora(int opcion_ingresada)
// {

// }

// Por añadir:
// Verificar que el valor ingresado sea un número
// Verificar si la pila está llena para "no borrar datos de ella" 👍
// Validar casos espceciales
// Comentar
// Mejorar apariencia
// Opción para Guardar Historial de la pila

int main()
{
    int opcion_ingresada;
    char operacion;
    float num, resultado = 0;
    do
    {
        printMenuPpal();
        if (scanf("%d", &opcion_ingresada) != 1)
        {
            printf("El valor que ingresó no era un número, abortando...");
            break;
        }
        else
        {
            if (opcion_ingresada == 1)
            {

                if (stack[0] == 0)
                {
                    printf("\n\n");
                    printf("Ingrese el número: \n");
                    scanf("%f", &num);
                    moveStackDown();
                    addToStack(num);
                    printf("\n");
                    printf("\n");
                }
                else
                {
                    printf("\n\n");
                    printf("🚧🚧 La pila está llena 🚧🚧\n");
                    printf("🚧🚧 Elimine un valor o realice una operación para continuar 🚧🚧\n\n");
                }
            }
            if (opcion_ingresada == 2)
            {
                printf("\n");
                printf("-------------------------------------\n");
                printf("¿Qué operación desea hacer?\n");
                printf("+ : Suma\n");
                printf("- : Resta\n");
                printf("* : Multiplicación\n");
                printf("/ : División\n");
                printf("^ : Potencia\n");
                printf("r : Raiz\n");
                printf("s: Seno\n");
                printf("c: Coseno\n");
                printf("t: Tangente\n");
                printf("-------------------------------------\n");
                printf("Ingrese su respuesta a continuación: \n");
                scanf("%s", &operacion);

                switch (operacion)
                {
                case '+':
                    resultado = stack[6] + stack[7];
                    moveStackUp();
                    addToStack(resultado);
                    printf("\n\n");
                    break;
                case '-':
                    resultado = stack[6] - stack[7];
                    moveStackUp();
                    addToStack(resultado);
                    printf("\n\n");
                    break;
                case '*':
                    resultado = stack[6] * stack[7];
                    moveStackUp();
                    addToStack(resultado);
                    printf("\n\n");
                    break;
                case '/':
                    resultado = stack[6] / stack[7];
                    moveStackUp();
                    addToStack(resultado);
                    printf("\n\n");
                    break;
                // case '^':
                //     resultado = pow(stack[6], stack[7]);
                //     moveStackUp();
                //     addToStack(resultado);
                //     printf("\n\n");
                //     break;
                // // Operaciones Unitarias:
                // case 'r':
                //     resultado = sqrt(stack[7]);
                //     moveStackUp();
                //     addToStack(resultado);
                //     printf("\n\n");
                //     break;
                // case 's':
                //     resultado = sin(stack[7]);
                //     moveStackUp();
                //     addToStack(resultado);
                //     printf("\n\n");
                //     break;
                // case 'c':
                //     resultado = cos(stack[7]);
                //     moveStackUp();
                //     addToStack(resultado);
                //     printf("\n\n");
                //     break;
                // case 't':
                //     resultado = tan(stack[7]);
                //     moveStackUp();
                //     addToStack(resultado);
                //     printf("\n\n");
                //     break;
                default:
                    printf("La operación ingresada no está soportada por la calculadora o es inexistente\n");
                    break;
                }
            }
            if (opcion_ingresada == 3)
            {
                moveStackUp();
                printf("\n");
            }
            if (opcion_ingresada == 4)
            {
                clearStack();
            }
            if (opcion_ingresada == 5)
            {
                printf("Apagando...");
            }
        }

    } while (opcion_ingresada != 5);
}
