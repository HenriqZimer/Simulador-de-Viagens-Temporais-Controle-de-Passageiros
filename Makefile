# Nome do executável final
EXEC = simulador

# Compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall -g

# Arquivos fonte
SRCS = main.c estruturas.c

# Objetos gerados
OBJS = $(SRCS:.c=.o)

# Regra principal
all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)

# Regra para limpar arquivos gerados
clean:
	rm -f *.o $(EXEC)

# Rodar o programa
run: $(EXEC)
	./$(EXEC)
