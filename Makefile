CFLAGS := -Wall -Werror
BIN := bin
OBJ := object
DBG := debug
CC := gcc

all: subset
debug: d_subset

# ------Linking------
subset: main.o
	${CC} ${OBJ}/$< -o ${BIN}/$@

# ------Main Object------
main.o: main.c
	${CC} -c ${CFLAGS} $< -o ${OBJ}/$@

# ------Debug Compilation------
d_subset: subset
	${CC} -g ${CFLAGS} main.c -o ${DBG}/debug

# ------Macros------
.PHONY: clean
clean:
	rm -f ${BIN}/* ${DBG}/* ${OBJ}/*