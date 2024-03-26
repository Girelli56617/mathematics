#pragma once
#include "Cabeçalho.h"

void renderizar(Jogo* jogo) {
	if (jogo->STATUS == STATUSPLANOCARTESIANO) {
		SDL_SetRenderDrawColor(jogo->renderer, 0, 0, 0, 0);
		SDL_RenderClear(jogo->renderer);
		SDL_SetRenderDrawColor(jogo->renderer, 255, 255, 255, 255);
		SDL_Color branco = { 255, 255, 255, 255 };

		SDL_Surface* mensagem11 = TTF_RenderText_Solid(jogo->fonte, "T", branco);
		SDL_Texture* textoH3 = SDL_CreateTextureFromSurface(jogo->renderer, mensagem11);
		SDL_FreeSurface(mensagem11);

		SDL_Surface* mensagem12 = TTF_RenderText_Solid(jogo->fonte, "Q", branco);
		SDL_Texture* textoH4 = SDL_CreateTextureFromSurface(jogo->renderer, mensagem12);
		SDL_FreeSurface(mensagem12);

		SDL_Surface* mensagem13 = TTF_RenderText_Solid(jogo->fonte, "P", branco);
		SDL_Texture* textoH5 = SDL_CreateTextureFromSurface(jogo->renderer, mensagem13);
		SDL_FreeSurface(mensagem13);

		SDL_Surface* mensagem14 = TTF_RenderText_Solid(jogo->fonte, "H", branco);
		SDL_Texture* textoH6 = SDL_CreateTextureFromSurface(jogo->renderer, mensagem14);
		SDL_FreeSurface(mensagem14);

		SDL_SetRenderDrawColor(jogo->renderer, 210, 234, 22, 255);
		SDL_Rect rect2 = { 960 + (jogo->coordenadasX * 9.6), 540 + (jogo->coordenadasY * -5.4), 10, 10 };
		SDL_RenderFillRect(jogo->renderer, &rect2);
		SDL_Rect rect3 = { 960 + (jogo->coordenadasZ * 9.6), 540 + (jogo->coordenadasA * -5.4), 10, 10 };
		SDL_RenderFillRect(jogo->renderer, &rect3);
		SDL_Rect rect4 = { 960 + (jogo->coordenadasB * 9.6), 540 + (jogo->coordenadasC * -5.4), 10, 10 };
		SDL_RenderFillRect(jogo->renderer, &rect4);
		SDL_Rect rect5 = { 960 + (jogo->coordenadasD * 9.6), 540 + (jogo->coordenadasE * -5.4), 10, 10 };
		SDL_RenderFillRect(jogo->renderer, &rect5);
		SDL_Rect rect6 = { 960 + (jogo->coordenadasF * 9.6), 540 + (jogo->coordenadasG * -5.4), 10, 10 };
		SDL_RenderFillRect(jogo->renderer, &rect6);
		SDL_Rect rect7 = { 960 + (jogo->coordenadasH * 9.6), 540 + (jogo->coordenadasI * -5.4), 10, 10 };
		SDL_RenderFillRect(jogo->renderer, &rect7);
		SDL_SetRenderDrawColor(jogo->renderer, 255, 255, 255, 255);

		SDL_Surface* mensagem15 = TTF_RenderText_Solid(jogo->fonte, "Area total: ", branco);
		SDL_Texture* textoH2 = SDL_CreateTextureFromSurface(jogo->renderer, mensagem15);
		SDL_FreeSurface(mensagem15);

		if (jogo->geo == 0) {
			double X[] = { jogo->coordenadasX, jogo->coordenadasZ, jogo->coordenadasB };
			double Y[] = { jogo->coordenadasY, jogo->coordenadasA, jogo->coordenadasC };
			int n = sizeof(X) / sizeof(X[0]);

			jogo->area = AreaPoligono(X, Y, n);
		}
		else if (jogo->geo == 1) {
			double X[] = { jogo->coordenadasX, jogo->coordenadasZ, jogo->coordenadasB, jogo->coordenadasD };
			double Y[] = { jogo->coordenadasY, jogo->coordenadasA, jogo->coordenadasC, jogo->coordenadasE };
			int n = sizeof(X) / sizeof(X[0]);
			jogo->area = AreaPoligono(X, Y, n);
		}
		else if (jogo->geo == 2) {
			double X[] = { jogo->coordenadasX, jogo->coordenadasZ, jogo->coordenadasB, jogo->coordenadasD, jogo->coordenadasF };
			double Y[] = { jogo->coordenadasY, jogo->coordenadasA, jogo->coordenadasC, jogo->coordenadasE, jogo->coordenadasG };
			int n = sizeof(X) / sizeof(X[0]);
			jogo->area = AreaPoligono(X, Y, n);
		}
		else if (jogo->geo == 3) {
			double X[] = { jogo->coordenadasX, jogo->coordenadasZ, jogo->coordenadasB, jogo->coordenadasD, jogo->coordenadasF, jogo->coordenadasH };
			double Y[] = { jogo->coordenadasY, jogo->coordenadasA, jogo->coordenadasC, jogo->coordenadasE, jogo->coordenadasG, jogo->coordenadasI };
			int n = sizeof(X) / sizeof(X[0]);
			jogo->area = AreaPoligono(X, Y, n);
		}
		char tara[127];
		sprintf(tara, "%d", jogo->area);
		char* area2[] = { (char)(jogo->area + '0') };
		SDL_Surface* mensagem22 = TTF_RenderText_Solid(jogo->fonte, tara, branco);
		SDL_Texture* textoH7 = SDL_CreateTextureFromSurface(jogo->renderer, mensagem22);
		SDL_FreeSurface(mensagem22);

		SDL_Rect textoArea = { 50, 600, 500, 200 };
		SDL_RenderCopy(jogo->renderer, textoH2, NULL, &textoArea);

		SDL_Rect textoArea2 = { 600, 600, 200, 200 };
		SDL_RenderCopy(jogo->renderer, textoH7, NULL, &textoArea2);

		SDL_Rect T = { jogo->retangulo[0].x, jogo->retangulo[0].y, jogo->retangulo[0].w, jogo->retangulo[0].h };
		SDL_RenderCopy(jogo->renderer, textoH3, NULL, &T);

		SDL_Rect Q = { jogo->retangulo[1].x, jogo->retangulo[1].y, jogo->retangulo[1].w, jogo->retangulo[1].h };
		SDL_RenderCopy(jogo->renderer, textoH4, NULL, &Q);

		SDL_Rect P = { jogo->retangulo[2].x, jogo->retangulo[2].y, jogo->retangulo[2].w, jogo->retangulo[2].h };
		SDL_RenderCopy(jogo->renderer, textoH5, NULL, &P);

		SDL_Rect H = { jogo->retangulo[3].x, jogo->retangulo[3].y, jogo->retangulo[3].w, jogo->retangulo[3].h };
		SDL_RenderCopy(jogo->renderer, textoH6, NULL, &H);

		SDL_RenderDrawLine(jogo->renderer, 0, 540, 1920, 540);
		SDL_RenderDrawLine(jogo->renderer, 960, 0, 960, 1080);
		SDL_RenderPresent(jogo->renderer);
		
		SDL_DestroyTexture(textoH2);
		SDL_DestroyTexture(textoH3);
		SDL_DestroyTexture(textoH4);
		SDL_DestroyTexture(textoH5);
		SDL_DestroyTexture(textoH6);
	}
/*	else if (jogo->STATUS == STATUSMATRIZ) {
		SDL_Color branco = { 255, 255, 255, 255 };
		SDL_Texture* text1, * text2, * text3;
		char tara[20] = "";
		char tara2[20] = "";
		char tara3[20] = "";
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				sprintf(tara, "%d", jogo->MatrizA[i][j]);
				SDL_Surface* Smatriz = TTF_RenderText_Solid(jogo->fonte, tara, branco);
				text1 = SDL_CreateTextureFromSurface(jogo->renderer, Smatriz);
				SDL_Rect rect1 = { jogo->retanguloA[i][j].x, jogo->retanguloA[i][j].y,
					jogo->retanguloA[i][j].w, jogo->retanguloA[i][j].h };
				SDL_RenderCopy(jogo->renderer, text1, NULL, &rect1);
			}
		}

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				sprintf(tara2, "%d", jogo->MatrizB[i][j]);
				SDL_Surface* Smatriz = TTF_RenderText_Solid(jogo->fonte, tara2, branco);
				text2 = SDL_CreateTextureFromSurface(jogo->renderer, Smatriz);
				SDL_Rect rect2 = { jogo->retanguloB[i][j].x, jogo->retanguloB[i][j].y,
				jogo->retanguloB[i][j].w, jogo->retanguloB[i][j].h };
				SDL_RenderCopy(jogo->renderer, text1, NULL, &rect2);
			}
		}

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				sprintf(tara3, "%d", jogo->MatrizC[i][j]);
				SDL_Surface* Smatriz = TTF_RenderText_Solid(jogo->fonte, tara3, branco);
				text3 = SDL_CreateTextureFromSurface(jogo->renderer, Smatriz);
				SDL_Rect rect3 = { jogo->retanguloC[i][j].x, jogo->retanguloC[i][j].y,
				jogo->retanguloC[i][j].w, jogo->retanguloC[i][j].h };
				SDL_RenderCopy(jogo->renderer, text1, NULL, &rect3);
			}
		}

		SDL_RenderPresent(jogo->renderer);
		SDL_DestroyTexture(text1);
		SDL_DestroyTexture(text2);
		SDL_DestroyTexture(text3);
	}
	*/
}