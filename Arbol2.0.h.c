//Main.c

#ifndef stdio_h
#include<stdio.h>
#define stdio_h
#endif

#ifndef stdlib_h
#include <stdlib.h>
#define stdlib_h
#endif

#ifndef Arbol.h
#include "Arbol.h"
#define arbol_h
#endif

int main()
{
	Abb *a;
//	a=inicio;   problema con inicio, no asigna el valor de NULL(preguntar)
	a=NULL;
	a=Inselem(a,8);
	a=Inselem(a,4);
	a=Inselem(a,9);
	a=Inselem(a,10);
	a=Inselem(a,2);
	a=Inselem(a,6);
	a=Inselem(a,5);
	a=Inselem(a,7);
	ImprimirInorden(a);
	ImprimirPostorden(a);
	ImprimirPreorden(a);
}

//Main.c


//Arbol.h

#ifndef stdio_h
#include<stdio.h>
#define stdio_h
#endif

#ifndef stdlib_h
#include <stdlib.h>
#define stdlib_h
#endif

//Estructura de nuestro arbol, tendra punteros a izquierda y dercha, para cada arbol o subarbol.
//nos referiremos al arbol como Abb *nombre.
typedef struct nodo
{
	int dato;
	struct nodo *izq,*der;
}Abb;
//Inicializa el arbol como NULL, donde no hay nada, no hay raiz aun.
Abb *inicio()
{
	return (0);	
}
//Este modulo pregunta si el arbol esta vacio.
int esvacio(Abb *a)
{
	if(a==NULL)
	{
		return 1;
	}
	return 0;
}
//Preguntal si esta o no un elemento especifico en el arbol. 
int estaelem(Abb *a, int elem)
{
	if(a==NULL)
	{
		return 0;
	}
	else if(a->dato > elem)
	{
		return (estaelem(a->izq,elem));
	}
	else if(a->dato < elem)
	{
		return (estaelem(a->der,elem));
	}
	else
	{
		return 1;
	}
}
//Modulo en donde se agrega elementos al arbol.
Abb *Inselem(Abb *a,int elem)
{
	if(a==NULL)
	{
		a=malloc(sizeof(Abb));
		a->dato=elem;
		a->izq = a->der = NULL;
	}
	else if(a->dato >elem)
	{
		a->izq=Inselem(a->izq,elem);
	}
	else if(a->dato < elem)
	{
		a->der=Inselem(a->der, elem);
	}
	return a;
}

Abb *Eliminavalor(Abb *a,int elem)
{
	Abb *p;
	int mayor;
	if(a->dato==elem)
	{
		if(a->izq==NULL && a->der==NULL)
		{
			free(a);
			return NULL;
		}
		else if(a->izq==NULL)
		{
			p=a->der;
			free(a);
			return p;
		}
		else
		{
			mayor=MayorElemento(a->izq);
			a->dato=mayor;
			a->izq=Eliminavalor(a->izq,mayor);
		}
	}
	else if(a->dato>elem)
	{
		a->izq=Eliminavalor(a->izq,elem);
	}
	else
	{
		a->der=Eliminavalor(a->der,elem);
	}
	return (a);
}


//Arbol.h
