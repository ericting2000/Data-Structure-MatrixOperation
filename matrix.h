#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    int row, col, value;
    char name[100];
} Matrix;

Matrix m[100][100]={};
Matrix t[100][100]={};
Matrix a[100][100]={};
Matrix x[100][100]={};


int insert_matrix(int index);
void read_matrix(int numbs);
void print_matrix(char name[100], char type,  int numbs);
void submatrix(int numbs);
void transposition(int numbs);
void addition(int numbs);
void expo();
