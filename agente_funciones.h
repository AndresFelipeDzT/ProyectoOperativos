/******************************************************
* Fecha 11/11/2025
* Pontificia Universidad Javeriana
* Profesor: J. Corredor, PhD
* Autor(es): Alejandro Beltran, Mauricio Beltran & Andres Diaz
* Materia: Sistemas opertivos
* Temas: Proyecto agente_funciones.h
******************************************************/

#ifndef AGENTE_FUNCIONES_H
#define AGENTE_FUNCIONES_H

#include <stdio.h> //Libreria para mostrar informacion por pantalla
#include <stdlib.h> //Libreria de memoria dinamica
#include <string.h> //libreria para cadenas de caracteres
#include <unistd.h> //Libreria para funciones relacionadas con posix
#include <fcntl.h> // Libreria para constantes y flags para open
#include <sys/stat.h> //Libreria para archivos y permisos
#include <sys/types.h> //Libreria para syscalls
#include <errno.h> //Libreria para manejo de errores

#define MAX_NOMBRE 50 //Cantidad maxima de caracteres en un nombre
#define MAX_BUFFER 256 //Cantidad maxima de caracteres para el buffer (lectura y escritura)

//Prototipos de las funciones 

// Recibe los argumentos, guarda el nombre del agente, el nombre del archivo de las solicitudes y el nombre del pipe
void parsear_argumentos(int argc, char* argv[], char* nombre_agente, char* archivo_solicitudes, char* pipe_entrada);

// Crea un pipe para que el controlador envia los datos
void crear_pipe_propio(char* pipe_propio, char* nombre_agente);
// Le indica al controlador un mensaje con el nombre del agente y el pipe a utilizar
int registrar_agente_controlador(char* nombre_agente, char* pipe_propio, char* pipe_entrada);
//Abre el pipe ya sea para lectura o escritura
int abrir_pipe_propio(char* pipe_propio);
//recibe la hora inicial y verifica que el mensaje sea para ese agente
int recibir_hora_inicial(int fd_propio, char* nombre_agente);
//Recibe todos los datos de la solictud y espera las respuestas que les va a devolver
void procesar_solicitudes(int fd_entrada, int fd_propio, char* archivo_solicitudes, char* nombre_agente, int hora_actual);
// Cierre los pipes que esten abiertos y los elimina de ser necesario
void cerrar_y_limpiar(int fd_entrada, int fd_propio, char* pipe_propio, char* nombre_agente);

#endif



