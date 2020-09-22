/* CODIGO BASE PARA EL SHELL A REALIZARSE
   PARA EL TRABAJO DE PROGRAMACION 1.
   ESTE CODIGO ES SOLO COMO GUIA DE LA ESTRUCTURA QUE TENDRIA EL SHELL
   NO ES OBLIGATORIO QUE LO IMPLEMENTE EN C, O USE ESTO COMO CODIGO INICIAL
   Autor: Dr. Roberto Solis Robles
   
*/
   
#include <stdio.h>
//#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>

#define NUM_VARS_AMBIENTE 4
#define FALSE 0
#define TRUE 1

/* Constantes para representar el indice de cada una de las 
variables de ambiente que el shell debe manejar */
enum vars_ambiente {
	SHELL,
	PATH,
	HOME,
	PWD
};
/* Variable que contiene el valor de cada una de las
variables de ambiente del shell */
char valores_vars_ambiente[NUM_VARS_AMBIENTE][1000];

/* Esta funcion deberia recibir el nombre del programa
que se esta ejecutando y su trabajo debe ser
inicializar las variables de ambiente que el shell
debe de manejar */
void inicializa(char *nombreprograma);

/*En esta variable quedan los elementos encontrados
por la funcion separa */
char elementos[10][40];

/* Esta funcion hace la separacion de una cadena en los
elementos que la componen indicando cual es el caracter
delimitador, se asume que el resultado de la separacion
quedara en la variable global elementos */
void separa(char *cad, char delim);

/* 
TODO 
Completar el codigo de las funciones para realizar el trabajo que  se
requiere para cada uno de los comandos internos del shell */
void clr(void);
void printenviron(void);
void dir(char *args);
void cd(char *args);
void echo(char *args);
void pwd(void);

int main(int argc, char *argv[]) {
	int salir = FALSE, pid,i;
	char linea_comando[200];
	char comando[40],argumentos[160];

	/* Se manda llamar a inicializa con el nombre del programa
	   que se esta ejecutando */
    inicializa(argv[0]);

	/* Se entra en un ciclo para esperar que el usuario
	   teclee un comando, el cual es guardado en linea_comando */
	do {
		/* Se muestra el indicador del sistema */
		printf("%s> ",valores_vars_ambiente[PWD]);
		gets(linea_comando);

		separa(linea_comando,' ');

		strcpy(comando,elementos[0]);

		i = 1;
		strcpy(argumentos,"");
		while(elementos[i][0]) {
			strcat(argumentos,elementos[i++]);
			strcat(argumentos," ");
		}
		argumentos[strlen(argumentos)-1]=0;

		if (!strcmp(comando,"cd")) {
			cd(argumentos);
		}
		else if (!strcmp(comando,"dir")) {
			dir(argumentos);
		}
		else if (!strcmp(comando,"clr")) {
			clr();
		}
		else if (!strcmp(comando,"environ")) {
			printenviron();
		}
		else if (!strcmp(comando,"echo")) {
			echo(argumentos);
		}
		else if (!strcmp(comando,"pwd")) {
			pwd();
		}
		else if (!strcmp(comando,"quit")) {
		 	// TODO
		 	// Codigo para que el ciclo termine
		}
		else { // COMANDO EXTERNO
			/* TODO
			   CODIGO PARA CREAR UN NUEVO PROCESO Y EJECUTAR EL COMANDO EXTERNO 
			   AL CUAL SE  LE DEBEN PASAR LOS ARGUMENTOS/PARAMETROS QUE
			   SE HAYAN TECLEADO POR PARTE DEL USUARIO 
			*/
		}
	} while (!salir);
	return 0;
}
