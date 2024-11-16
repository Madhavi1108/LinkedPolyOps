# LinkedPolyOps
Overview
This C program demonstrates how to represent and add two polynomials using linked lists. Each polynomial is represented as a linked list of nodes where each node contains the coefficient and exponent of a term. The program provides functions for creating, printing, and adding polynomials together.

Features:
Polynomial Representation: Each polynomial is stored in a linked list structure with terms stored in order of decreasing exponents.
Polynomial Addition: The program performs addition of two polynomials by comparing their exponents and combining the coefficients where exponents match.
User Input: Allows the user to input the coefficients and exponents for the terms of two polynomials.
Result Output: Prints the sum of two polynomials in a human-readable form.

This project consists of a single C file that includes functions for:

Creating a Polynomial
Printing a Polynomial
Adding Two Polynomials
Utility Functions for Linked List Operations

The main C file includes the following functions:

getNode(): Allocates memory for a new node in the linked list.
attach(int coef, int expon, polyPointer *ptr): Attaches a new term with a given coefficient and exponent to the polynomial.
COMPARE(int a, int b): Compares two exponents to help in polynomial addition.
cpadd(polyPointer a, polyPointer b): Adds two polynomials represented as linked lists.
createPolynomial(): Creates a polynomial by taking user input for coefficients and exponents.
printPolynomial(polyPointer p): Prints the polynomial in the format "coef x^expon".
