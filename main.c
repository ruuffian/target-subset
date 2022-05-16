#include "main.h"

/*
 * Need to scrap iterative method, recursion is much cleaner and allows for faster runtime.
 */
int main(int argc, char **argv)
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s target sorted_array\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /* Initialize algorithm variables and validate input */
    long target;
    char *target_err;
    size_t input_size = 0;

    target = strtol(argv[1], &target_err, 0);

    char *line;

    line = strdup(argv[2]);
    if (is_valid(line) == FALSE)
    {
        fprintf(stderr, "Input invalid.\n");
        return EXIT_FAILURE;
    }

    /* Creating Input Set */
    char *tok;
    char *save_ptr;
    long *input_set;

    input_set = calloc(1, sizeof(int));
    tok = strtok_r(line, ",", &save_ptr);
    while (tok != NULL)
    {
        input_set[input_size] = strtol(tok, NULL, 0);
        input_size++;
        input_set = realloc(input_set, sizeof(int) * (input_size + 1));
        tok = strtok_r(NULL, ",", &save_ptr);
    }
    printf("Input:: %s\n", line);

    /* Apply Recursive Algorithm */
    info state;
    state.set = input_set;
    state.set_size = 0;
    state.sub_multiset = calloc(1, sizeof(int));
    state.sub_multiset_size = 0;
    state.target = target;
    algorithm(&state);

    /* Print solution */
    long *tmp = state.sub_multiset;
    printf("Solution:: [");
    while (tmp != NULL)
    {
        printf("%lu", *tmp);
        tmp++;
    }
    printf("]\n");

    free(line);
    free(input_set);
    return 0;
}

void algorithm(info *state)
{
    int flag = 0;
    recurse(*state, &flag);
}

info recurse(info state, int *flag)
{
    if (state.target == 0)
    {
        *flag = 1;
        return state;
    }
    /* Find largest element that is less than the target. */
    int i = 0;
    while (state.set[i] < state.target)
    {
        i++;
    }
    i--;
    while (i > 0)
    {
        if (*flag == 0)
        {
            add_element(&state, state.set[i]);
            recurse(state, flag);
        } else
        {
            break;
        }
        i--;
    }
    return state;
}

void add_element(info *state, long element)
{
    int i = 0;
    long *tmp = state->sub_multiset;
    while (tmp != NULL)
    {
        i++;
        tmp++;
    }
    state->sub_multiset = realloc(state->sub_multiset, sizeof(long) * (i + 1));
    state->sub_multiset[i + 1] = element;
    state->target -= element;
}

int is_valid(char *str)
{
    while (*str != '\0')
    {
        if (*str != ',' && !(*str >= 48 && *str <= 57))
            return FALSE;
        str++;
    }
    return TRUE;
}
