#pragma once
#include "Cabeçalho.h"

void inicializacaoTermos(Jogo* jogo) {
	jogo->fonte = TTF_OpenFont("teste.ttf", 24);
	if (jogo->fonte == NULL) {
		printf("nao foi possivel abrir o arquivo\n");
		SDL_Quit();
		exit(1);
	}

	for (int i = 0; i < 11; i++) {
		jogo->numeros[i].w = 100, jogo->numeros[i].h = 100;
		jogo->numeros[i].digitado = 0;
		if (i < 3) {
			jogo->numeros[i].x = i * 100 + 50;
			jogo->numeros[i].y = 50;
		}
		if (i < 6 && i >= 3) {
			jogo->numeros[i].x = (i-3) * 100 + 50;
			jogo->numeros[i].y = 150;
		}
		if (i < 9 && i >= 6) {
			jogo->numeros[i].x = (i - 6) * 100 + 50;
			jogo->numeros[i].y = 250;
		}
		if (i == 9) {
			jogo->numeros[i].x = (i - 8) * 100 + 50;
			jogo->numeros[i].y = 350;
		}
		if (i == 10) {
			jogo->numeros[i].x = (i - 8) * 100 + 150;
			jogo->numeros[i].y = 350;
		}
	}
	for (int i = 0; i < 24; i++) {
		jogo->digitado[i] = 0;
	}
	jogo->n = 0;
	jogo->m = 0;
	jogo->tempo = 0;
	jogo->apertado = 0;

	jogo->coordenadasX = 0;
	jogo->coordenadasY = 0;
	jogo->coordenadasA = 0;
	jogo->coordenadasB = 0;
	jogo->coordenadasC = 0;
	jogo->coordenadasD = 0;
	jogo->coordenadasE = 0;
	jogo->coordenadasF = 0;
	jogo->coordenadasG = 0;
	jogo->coordenadasH = 0;
	jogo->coordenadasI = 0;
	jogo->contadorCord = 0;

	jogo->STATUS = 0;

	for (int i = 0; i < 4; i++) {
		jogo->retangulo[i].x = i * 100 + 50;
		jogo->retangulo[i].y = 850;
		jogo->retangulo[i].w = 100;
		jogo->retangulo[i].h = 100;
	}

	jogo->geo = 0;

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			jogo->MatrizA[i][j] = rand() % 127;
			jogo->MatrizB[i][j] = rand() % 127;
			jogo->MatrizC[i][j] = rand() % 127;
			jogo->retanguloA[i][j].y = i * 100 + 500;
			jogo->retanguloB[i][j].y = i * 100 + 500;
			jogo->retanguloC[i][j].y = i * 100 + 500;
			jogo->retanguloA[i][j].w = 100;
			jogo->retanguloB[i][j].w = 100;
			jogo->retanguloC[i][j].w = 100;
			jogo->retanguloA[i][j].h = 100;
			jogo->retanguloB[i][j].h = 100;
			jogo->retanguloC[i][j].h = 100;
			if (j == 0) {
				jogo->retanguloA[i][j].x = 400;
				jogo->retanguloB[i][j].x = 900;
				jogo->retanguloC[i][j].x = 1400;
			}
			else if (j == 1) {
				jogo->retanguloA[i][j].x = 500;
				jogo->retanguloB[i][j].x = 1000;
				jogo->retanguloC[i][j].x = 1500;
			}
		}
	}
}