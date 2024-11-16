#include <stdio.h>
#include <stdlib.h>

typedef struct polyNode *polyPointer;
typedef struct polyNode
{
    int coef;
    int expon;
    polyPointer link;
} polyNode;

polyPointer getNode()
{
    polyPointer temp;
    temp = (polyPointer) malloc(sizeof(polyNode));
    if(!temp)
    {
        printf("Memory allocation error\n");
        exit(1);
    }
    return temp;
}


void attach(int coef, int expon, polyPointer *ptr)
{
    polyPointer temp = getNode();
    temp -> coef = coef;
    temp -> expon = expon;
    temp -> link = NULL;
    (*ptr) -> link = temp;
    *ptr = temp;
}


int COMPARE(int a , int b)
{
    if(a<b)
    return -1;
    else if(a==b)
    return 0;
    else
    return 1;
}


polyPointer cpadd(polyPointer a , polyPointer b)
{
    polyPointer startA,c, lastC;
    int sum, done = 0;
    startA = a;
    a = a-> link;
    b = b->link;
    c = getNode();
    c-> expon = -1;
    lastC = c;
    do{
        switch(COMPARE(a->expon, b->expon))
        {
            case -1 : attach(b->coef, b->expon, &lastC);
            b = b->link;
            break;
            
            case 0 : if (startA == a)
            {
                done == 1;
            }
            else
            {
                sum = a->coef + b->coef;
                if (sum)
                {
                    attach(sum, a->expon, &lastC);
                }
                a = a->link;
                b = b->link;
            }
            
            case 1 : attach(a->coef, a->expon, &lastC);
            a = a->link;
            break;
        }
    }while(!done);
    lastC ->link = c;
    return c;
}

polyPointer createPolynomial()
{
    polyPointer start, last, temp;
    int n, i, coef, expon;
    start = getNode();
    start->expon = -1;
    last = start;
    printf("Enter no.of terms in polynomial are \n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Coefficient:\n");
        scanf("%d",&coef);
        printf("Expon:\n");
        scanf("%d",&expon);
        attach(coef,expon,&last);
    }
    last->link = start;
    return start;
}

void printPolynomial(polyPointer p)
{
    polyPointer temp = p->link;
    int first =1;
    while (temp!=p)
    {
        if(!first)
        {
            printf("+");
        }
        printf("%d x^%d", temp->coef, temp->expon);
        temp =temp->link;
        first=0;
    }
    printf("\n");
}

int main()
{
    polyPointer poly1, poly2, sum;
    printf("Create the first polynomial:\n");
    poly1 = createPolynomial();
    printf("Create the second polynomial:\n");
    poly2 = createPolynomial();
    sum = cpadd(poly1, poly2);
    printf("First polynomial:\n");
    printPolynomial(poly1);
    printf("Second polynomial:\n");
    printPolynomial(poly2);
    printf("Sum of the two polynomials:\n");
    printPolynomial(sum);
    return 0;
}
