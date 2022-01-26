
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct VECT
{
    int DIMENSION;
    double ELEMENTS[1000];
};
typedef struct VECT VECTOR;
void CREATE_VECTOR(VECTOR *my_vector_temp)
{
    int i;
    for (i = 0; i < my_vector_temp->DIMENSION; i++)
    {
        printf("Enter the element %d : ", (i + 1));
        scanf("%lf", &my_vector_temp->ELEMENTS[i]);
    }
}
void MODIFY_VECTOR(VECTOR *my_vector_temp)
{
    int i;
START_OVER:
    printf("Enter the position number of the vector to be modified : ");
    scanf("%d", &i);
    if ((i <= 0) || (i > ((my_vector_temp->DIMENSION) + 1)))
    {
        printf("\nEntered invalid position number!\n");
        goto START_OVER;
    }
    double new_term;
    printf("Enter the new value of the vector element : ");
    scanf("%lf", &new_term);
    my_vector_temp->ELEMENTS[i - 1] = new_term;
}
void PRINT_VECTOR(VECTOR *my_vector_temp)
{
    int i;
    printf("Vector is : ");
    for (i = 0; i < my_vector_temp->DIMENSION; i++)
    {
        if (i == 0)
        {
            printf("(%.2lf ", my_vector_temp->ELEMENTS[i]);
        }
        else
        {
            printf(", %.2lf", my_vector_temp->ELEMENTS[i]);
        }
    }
    printf(")\n");
}
void MULTIPLY_VECTOR(VECTOR *my_vector_temp)
{
    double scalar_mult;
    int i;
    printf("Enter the scalar to be multiplied to the vector : ");
    scanf("%lf", &scalar_mult);
    for (i = 0; i < my_vector_temp->DIMENSION; i++)
    {
        my_vector_temp->ELEMENTS[i] *= scalar_mult;
    }
}
void ADD_VECTOR(VECTOR *my_vector_temp)
{
    VECTOR add_my_vector;
    add_my_vector.DIMENSION = my_vector_temp->DIMENSION;
    printf("Enter the other vector \n");
    CREATE_VECTOR(&add_my_vector);
    /*PRINT_VECTOR(&add_my_vector);*/
    int k;
    VECTOR sum_vector;
    sum_vector.DIMENSION = my_vector_temp->DIMENSION;
    for (k = 0; k < add_my_vector.DIMENSION; k++)
    {
        sum_vector.ELEMENTS[k] = (add_my_vector.ELEMENTS[k] + my_vector_temp->ELEMENTS[k]);
    }
    printf("\nSum-up ");
    PRINT_VECTOR(&sum_vector);
}

int main()
{
    VECTOR my_vector;
    int choice_1;
    printf("\n----------------------------");
    printf("\n1. Create a vector");
    /*printf("\n2. Modify the entered vector");
    printf("\n3. Multiply a scalar value");
    printf("\n4. Display the vector.");*/
    printf("\n2. Exit");
    printf("\n----------------------------");
    printf("\nEnter your choice : ");
    scanf("%d", &choice_1);
    int count, j;
    count = 0;
    if (choice_1 != 2)
    {
        system("cls");
        printf("\nEnter the dimension : ");
        scanf("%d", &my_vector.DIMENSION);
        printf("\n");
        CREATE_VECTOR(&my_vector);
    }
    else if (choice_1 == 2)
    {
        goto END;
    }
    int choice;
AGAIN:

    printf("\n----------------------------");
    /*printf("\n1. Create a vector");*/
    printf("\n1. Modify the entered vector");
    printf("\n2. Multiply a scalar value");
    printf("\n3. Display the vector");
    printf("\n4. Add another vector");
    printf("\n5. Exit");
    printf("\n----------------------------");
    printf("\nEnter your choice : ");
    scanf("%d", &choice);
    if (choice != 5)
    {
        system("cls");
        if (choice == 1)
        {
            printf("\n");
            MODIFY_VECTOR(&my_vector);
        }
        else if (choice == 2)
        {
            printf("\n");
            MULTIPLY_VECTOR(&my_vector);
        }
        else if (choice == 3)
        {
            printf("\n");
            PRINT_VECTOR(&my_vector);
        }
        else if (choice == 4)
        {
            printf("\n");
            ADD_VECTOR(&my_vector);
        }
        goto AGAIN;
    }
    else if (choice == 5)
    {
        goto END;
    }
END:
    printf("\n\npress any key to exit.....");
    getch();
    printf("\n\n");
    return 0;
}
