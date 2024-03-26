#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_Image.h>
#include <SDL_ttf.h>
#include <math.h>

#define STATUSPLANOCARTESIANO 0
#define STATUSMATRIZ 1

typedef struct {
	float x, y, w, h;
	short digitado;
}Numero;

typedef struct {
	float x, y, w, h;
}Retangulo;

typedef struct {
	Retangulo retangulo[4];
	Retangulo retanguloA[2][2], retanguloB[2][2], retanguloC[2][2];
	Numero numeros[11];
	SDL_Renderer* renderer;
	TTF_Font* fonte;
	int digitado[25];
	char* digitadoY[2];
	int n, m, tempo, coordenadasX, coordenadasY, coordenadasZ, coordenadasA, coordenadasB, coordenadasC, coordenadasD, coordenadasE, coordenadasF,
	coordenadasG, coordenadasH, coordenadasI, area, MatrizA[2][2], MatrizB[2][2], MatrizC[2][2];
	short contadorCord, apertado, geo, STATUS;
}Jogo;

int eventos(SDL_Window* janela, Jogo* jogo);
void inicializacaoTermos(Jogo* jogo);
void renderizar(Jogo* jogo);
double AreaPoligono(double X[], double Y[], int n);
	