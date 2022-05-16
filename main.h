#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef struct {
    long target;
    long *set;
    size_t set_size;
    long *sub_multiset;
    size_t sub_multiset_size;
} info;

/* Wrapper for recursive algorithm. */
void algorithm(info *);

/*
 * Recursive method to find a subset of a multiset whose elements sum to a target integer.
 * Flag == 0 means no solution was found, flag == 1 means solution found.
 */
info recurse(info, int *);

/* Add an element to the subset of an info struct, update the target long, and return the struct. */
void add_element(info *, long);

/* Returns 1 if the string contains only numbers and commas, 0 otherwise. */
int is_valid(char *);