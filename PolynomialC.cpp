// Polynomial (i) Representation (ii) Evaluation (iii) Addition
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>   // For pow() function

using namespace std;

/* Structure to represent a single term of a polynomial
   Each term has a coefficient and a power */
struct term
{
    int coeff;
    int power;
};

/* Structure to represent a polynomial
   n  → number of terms
   t  → dynamic array of polynomial terms */
struct poly
{
    int n;
    struct term *t;
};

/* Function to read a polynomial
   It accepts number of terms and each term's coefficient and power */
void read(struct poly *p)
{
    printf("Enter no. of terms: ");
    scanf("%d", &p->n);

    p->t = (struct term *)malloc(p->n * sizeof(struct term));

    for (int i = 0; i < p->n; i++)
    {
        printf("Enter Polynomial Term %d: ", i + 1);
        scanf("%d%d", &p->t[i].coeff, &p->t[i].power);
    }
}

/* Function to evaluate a polynomial for a given value of x
   Uses the formula: coeff * x^power for each term */
long int PolyEval(struct poly p, int x)
{
    int eval = 0;
    for (int i = 0; i < p.n; i++)
    {
        eval = eval + (p.t[i].coeff * (long int)pow(x, p.t[i].power));
    }

    return eval;
}

/* Function to display a polynomial in readable mathematical form */
void display(struct poly p)
{
    printf("Polynomial: ");
    for (int i = 0; i < p.n; i++)
    {
        printf("%dx^%d", p.t[i].coeff, p.t[i].power);

        if (i < p.n - 1)
        {
            printf(" + ");
        }
    }
    printf("\n");
}

/* Function to add two polynomials
   Assumes both polynomials are sorted in descending order of power */
struct poly add(struct poly p1, struct poly p2)
{
    struct poly p3;
    p3.t = (struct term *)malloc((p1.n + p2.n) * sizeof(struct term));

    int i = 0, j = 0, k = 0;

    while (i < p1.n && j < p2.n)
    {
        if (p1.t[i].power > p2.t[j].power)
        {
            p3.t[k++] = p1.t[i++];
        }
        else if (p1.t[i].power < p2.t[j].power)
        {
            p3.t[k++] = p2.t[j++];
        }
        else
        {
            p3.t[k].coeff = p1.t[i].coeff + p2.t[j].coeff;
            p3.t[k++].power = p1.t[i].power;
            i++;
            j++;
        }
    }

    /* Copy remaining terms of p1 */
    while (i < p1.n)
        p3.t[k++] = p1.t[i++];

    /* Copy remaining terms of p2 */
    while (j < p2.n)
        p3.t[k++] = p2.t[j++];

    p3.n = k;
    return p3;
}

/* Main function
   Reads two polynomials, displays them, and prints their sum */
int main()
{
    struct poly p1, p2, p3;

    read(&p1);
    read(&p2);

    display(p1);
    display(p2);

    printf("Addition ");
    display(add(p1, p2));

    return 0;
}
