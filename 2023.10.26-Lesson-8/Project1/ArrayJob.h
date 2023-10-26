#pragma once
#ifndef ARRAYJOB_H
#define ARRAYJOB_H

int** initMatrix(int n, int m);
void randomizeMatrix(int** matr, int n, int m, int mn = 0, int mx = 9);
void printMatrix(int** matr, int n, int m);
void deleteMatrix(int** matr, int n);

#endif
