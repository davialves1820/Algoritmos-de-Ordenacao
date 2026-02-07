# Variáveis
CC = gcc
CFLAGS = -Wall -Iinclude
SRC_DIR = src
INCLUDE_DIR = include
BIN_DIR = bin
OBJ_DIR = obj

# Nome do executável
TARGET = $(BIN_DIR)/programa

# Obtém todos os arquivos .c na pasta src
SRCS = $(wildcard $(SRC_DIR)/*.c)

# Converte os arquivos .c para .o na pasta obj
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Regras principais
all: setup $(TARGET)

# Cria os diretórios necessários
setup:
	@mkdir -p "$(BIN_DIR)"
	@mkdir -p "$(OBJ_DIR)"

# Gera o executável
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Compila os arquivos .c para .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpeza
clean:
	@rm -rf "$(BIN_DIR)"
	@rm -rf "$(OBJ_DIR)"

.PHONY: all setup clean