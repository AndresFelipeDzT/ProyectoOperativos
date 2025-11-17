# Proyecto Sistemas Operativos
# Objetivos del proyecto
Resolver un problema real mediante el uso de procesos e hilos de la biblioteca POSIX.


Emplear mecanismos de sincronización y comunicación entre procesos usando pipes.


Utilizar correctamente las llamadas al sistema relacionadas con la creación y manejo de hilos y procesos
# Funcionalidad
La aplicación simula un día completo de funcionamiento del parque, donde diferentes familias intentan reservar una hora para poder entrar.
# Estructura de archivos
No se maneja una estructura de carpetas interna, esto se debe a que los archivos hacen parte de un mismo objetivo, ya sean partes que simulan el cliente (agente) y servidor (controlador) o los archivos de entrada en formato .csv, la única excepción es el documento en formato pdf pero se ópto por dejarlo todo en una carpeta.

Dicho documento cuenta con su introducción, objetivos, descripción, diagrama con el modelado del programa, plan de pruebas con su respectiva razón en cada y conclusiones.
# Código
Por otra parte, en cuanto a código tiene los siguientes archivos todos con su fichero y respectivos comentarios:
controlador.c    Contiene el programa principal del controlador del sistema. Se encarga de iniciar los hilos, configurar el pipe principal, administrar el aforo del parque, gestionar las solicitudes recibidas y controlar el paso del tiempo simulado. Estas dos últimas mediante el uso de hilos.


controlador_funciones.c:	    Implementa todas las funciones auxiliares utilizadas por el controlador, como el procesamiento de mensajes, el registro de agentes, validación de reservas, reprogramación, envío de respuestas y generación del reporte final.


controlador_funciones.h:	    Declara las funciones y estructuras utilizadas por el controlador


agente.c:    Programa principal de un agente de reservas. Se encarga de leer las solicitudes desde un archivo CSV, enviarlas al controlador, recibir respuestas y mostrar resultados.


agente_funciones.c:    Implementa las funciones para el agente, como el manejo del pipe propio, lectura de datos del archivo CSV y comunicación con el controlador.


agente_funciones.h:	    Declara las funciones utilizadas por el agente.


Makefile:    Para la compilación del proyecto.
