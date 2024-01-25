#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*Structures*/

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/*
 * enum bool - defining new boolean type
 *
 */
typedef enum bool
{
	false = 0,
	true
} bool;

/*Function Prototype*/

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void swap(int *x, int *y);
void swapnode(listint_t **h, listint_t **n1, listint_t *n2);
void insertion_sort_list(listint_t **list);
int lomutosplit(int *array, size_t size, int left, int right);
void lomutosort(int *array, size_t size, int left, int right);

#endif
