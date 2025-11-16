# ******************************************************
# Fecha: 11/11/2025
# Pontificia Universidad Javeriana
# Profesor: J. Corredor, PhD
# Autor(es): Alejandro Beltran, Mauricio Beltran & Andres Diaz
# Materia: Sistemas Operativos
# Temas: Makefile
# ******************************************************
#Indica que se compila con gcc
CC = gcc
#Flags para mostrar adeveretencias y habilitar posix
CFLAGS = -Wall -Wextra -pthread
#Que se quiere compilar tanto el agente como el controlador
TARGETS = controlador agente
#Que compile todos los objetivos
all: $(TARGETS)
#Adicional al principal le incluye sus funciones a controlador
controlador: controlador.c controlador_funciones.c
	$(CC) $(CFLAGS) -o controlador controlador.c controlador_funciones.c
#Adicional al principal le incluye sus funciones a agente
agente: agente.c agente_funciones.c
	$(CC) $(CFLAGS) -o agente agente.c agente_funciones.c
#Elimina los ejecutables y residuos de pipe y/o fifo
clean:
	rm -f $(TARGETS) Pipe* *.fifo

.PHONY: all clean

