#include <math.h>
#include <stdio.h>
#include <ctype.h> //para cuando se use el isdigit(c)
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
    // Método para subir elementos en la pila: Stack[0] -> Stack [7]
    // Tener en cuenta que visualmente funciona inverso a como funciona por dentro
    for (int i = 7; i >= 0; i--)
    {
        stack[i] = stack[i - 1];
    }
}

void moveStackDown(void)
{
    //Función para bajar elementos en la pila: Stack[7] -> Stack[0]
    //Tener en cuenta que visualmente funciona inverso a como funciona por dentro
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
    printf("\n\n");
}

void clearStack(void)
{
    //Método para vaciar toda la pila
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

// Por añadir:
// Verificar que el valor ingresado sea un número
// Comentar

int main()
{
    int opcion_ingresada, auxiliar;
    char operacion;
    float num, resultado = 0;
    char c;
    //Ciclo para imprimir el menú principal
    printf("Nota: Sólo para la primera ejecución ingrese la opción que quiera realizar después de usar la tecla Enter\n");
    do
    {
        printMenuPpal();
        //Validación que el valor ingresado al menú principal sea un número entre las opciones
        //Ciclo para volver al menú en caso de que no sea un número en vez de terminar la ejecución del programa
        while((c = getchar()) != '\n' && c != EOF);
        if (scanf("%d", &auxiliar) != 1 ||  auxiliar > 5 || auxiliar < 0)
        {
            printf("  🚨🚨El valor que ingresó no está en las opciones.🚨🚨\n");
            printf("  Inténtelo nuevamente con una de las opciones disponibles\n");
        }
        else
        {
            opcion_ingresada = auxiliar;
            if (opcion_ingresada == 1)
            {
                //Se evalúa que el tope de la esté vacío para ingresar más valores
                if (stack[0] == 0)
                {
                    printf("\n\n");
                    printf("Ingrese el número: \n\n");
                    if(scanf("%f", &num) != 1)
                    {
                        printf("  🚨🚨El valor ingresado no es un número🚨🚨\n");
                    }
                    else 
                    {
                        moveStackDown();
                        addToStack(num);
                        printf("\n\n");
                    }
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
                //Menú con las operaciones
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
                printf("Ingrese su respuesta a continuación: \n\n");
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
                    if(stack[7] == 0)
                    {
                        //Se calculan las excepciones con las diviones por cero
                        printf("\n");
                        printf("   🚨🚨Error Matemático🚨🚨\n");
                        break; 
                    }
                    else
                    {   
                        resultado = stack[6] / stack[7];
                        moveStackUp();
                        addToStack(resultado);
                        printf("\n\n");
                        break;
                    }
                case '^':
                    resultado = pow(stack[6], stack[7]);
                    moveStackUp();
                    addToStack(resultado);
                    printf("\n\n");
                    break;
                // Operaciones Unitarias:
                case 'r':
                    if(stack[7] > 0)
                    {
                        resultado = sqrt(stack[7]);
                        moveStackUp();
                        addToStack(resultado);
                        printf("\n\n");
                        break;
                    }
                    else if(stack[7] < 0)
                    //Se calculan las excepciones con las raices negativas
                    {
                        printf("\n");
                        printf("   🚨🚨Error Matemático🚨🚨\n");
                        break;
                    }
                case 's':
                    resultado = sin(stack[7]);
                    moveStackUp();
                    addToStack(resultado);
                    printf("\n\n");
                    break;
                case 'c':
                    resultado = cos(stack[7]);
                    moveStackUp();
                    addToStack(resultado);
                    printf("\n\n");
                    break;
                case 't':
                //Se calcula la excepción de los múltiplos de 90 con la Tangente
                if((int)stack[7]%90 == 0)
                {
                    printf("\n");
                    printf("   🚨🚨Error Matemático🚨🚨\n");
                    break;
                }
                else
                {
                    resultado = tan(stack[7]);
                    moveStackUp();
                    addToStack(resultado);
                    printf("\n\n");
                    break;
                }
                default:
                    printf("  🚨🚨La operación ingresada no está soportada por la calculadora o es inexistente🚨🚨\n");
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
