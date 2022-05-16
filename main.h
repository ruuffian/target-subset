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
 * Flag == 0 means no solution was found, flag == 1 means a solution found.
 */
info recurse(info, int *);

/* Copy fields from a to b */
void copy_info(info *a, info *b);

/* Add an element to the subset of an info struct and update the target long. */
void add_element(info *, long);

/* Resets the fields in an info struct */
void reset(info *);

/* Returns 1 if the string contains only numbers and commas, 0 otherwise. */
int is_valid(char *);