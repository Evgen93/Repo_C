#pragma once
void InArrInt(int arr[], int size);
void InArrDoub(double arr[], double size);
void OutArrInt(int arr[], int size);
void OutArrDoub(double arr[], double size);
int MinArrInt(int arr[], int size);
int MinArrDoub(double arr[], double size);
int MaxArrInt(int arr[], int size);
int MinArrDoub(double arr[], double size);
void SortArrInt(int arr[], int size);

#define INTEGER

#ifdef INTEGER
#define InArr(arr, size) InArrInt(arr, size)
#define OutArr(arr, size) OutArrInt(arr, size)
#define MinArr(arr, size) MinArrInt(arr, size)
#define MaxArr(arr, size) MaxArrInt(arr, size)
#define SortArr(arr, size) SortArrInt(arr, size)
#endif // INTEGER
#ifndef INTEGER
#define InArr(arr, size) InArrDoub(arr, size)
#define OutArr(arr, size) OutArrDoub(arr, size)
#define MinArr(arr, size) MinArrDoub(arr, size)
#define MaxArr(arr, size) MaxArrDoub(arr, size)
#endif // !INTEGER