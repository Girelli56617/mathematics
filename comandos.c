#pragma once
#include "Cabeçalho.h"

int eventos(SDL_Window* janela, Jogo* jogo) {
	SDL_Event evento;
	int done = 0;
	int x, y;

	//loop de eventos

	while (SDL_PollEvent(&evento)) {// toda vez que um ponteiro for solicitado, pode ser colocado um endereço de memória direto
		SDL_GetMouseState(&x, &y);
		switch (evento.type)
		{
		case SDL_WINDOWEVENT_CLOSE:
		{
			if (janela) { // caso simples, então utilizado IF ao invez do switch, condição "janela" == "janela"
				SDL_DestroyWindow(janela);
				janela = NULL;
				done = 1;
			}
		}
		break;
		case SDL_KEYDOWN:
		{
			switch (evento.key.keysym.sym)
			{
			case SDLK_ESCAPE: // se a informação do case for simples, não há necessidade de chaves
				done = 1;
				break;
			case SDLK_0:
			{
				jogo->digitado[jogo->m] = 0;
				jogo->m += 1;
			}
			break;
			case SDLK_1:
			{
				jogo->digitado[jogo->m] = 1;
				jogo->m += 1;
			}
			break;
			case SDLK_2:
			{
				jogo->digitado[jogo->m] = 2;
				jogo->m += 1;
			}
			break;
			case SDLK_3:
			{
				jogo->digitado[jogo->m] = 3;
				jogo->m += 1;
			}
			break;
			case SDLK_4:
			{
				jogo->digitado[jogo->m] = 4;
				jogo->m += 1;
			}
			break;
			case SDLK_5:
			{
				jogo->digitado[jogo->m] = 5;
				jogo->m += 1;
			}
			break;
			case SDLK_6:
			{
				jogo->digitado[jogo->m] = 6;
				jogo->m += 1;
			}
			break;
			case SDLK_7:
			{
				jogo->digitado[jogo->m] = 7;
				jogo->m += 1;
			}
			break;
			case SDLK_8:
			{
				jogo->digitado[jogo->m] = 8;
				jogo->m += 1;
			}
			break;
			case SDLK_9:
			{
				jogo->digitado[jogo->m] = 9;
				jogo->m += 1;
			}
			break;
			case SDLK_MINUS:
			{
				if (jogo->m > 0) {
					jogo->digitado[jogo->m - 1] = jogo->digitado[jogo->m - 1] * -1;
				}
			}
			}
		} 
		break;
		case SDL_QUIT:
			done = 1;
			break;
		case SDL_MOUSEBUTTONDOWN:
			if(evento.button.button == SDL_BUTTON_LEFT && evento.button.state == SDL_PRESSED){
				for (int i = 0; i < 4; i++) {
					if (x > jogo->retangulo[0].x && x < jogo->retangulo[0].x + jogo->retangulo[0].w
						&& y > jogo->retangulo[0].y && y < jogo->retangulo[0].y + jogo->retangulo[0].h) {
						jogo->geo = 0;
					}
					else if (x > jogo->retangulo[1].x && x < jogo->retangulo[1].x + jogo->retangulo[1].w
						&& y > jogo->retangulo[1].y && y < jogo->retangulo[1].y + jogo->retangulo[1].h) {
						jogo->geo = 1;
					}
					else if (x > jogo->retangulo[2].x && x < jogo->retangulo[2].x + jogo->retangulo[2].w
						&& y > jogo->retangulo[2].y && y < jogo->retangulo[2].y + jogo->retangulo[2].h) {
						jogo->geo = 2;
					}
					else if (x > jogo->retangulo[3].x && x < jogo->retangulo[3].x + jogo->retangulo[3].w
						&& y > jogo->retangulo[3].y && y < jogo->retangulo[3].y + jogo->retangulo[3].h) {
						jogo->geo = 3;
					}
				}
			/*	for (int i = 0; i < 11; i++) {
					if (x > jogo->numeros[i].x && jogo->numeros[i].x + jogo->numeros[i].w > x
						&& y > jogo->numeros[i].y && y < jogo->numeros[i].y + jogo->numeros[i].h) {
							if (jogo->n == 1) {
								if (i == 0) jogo->digitado[1 + jogo->m] = '1';
								if (i == 1) jogo->digitado[1 + jogo->m] = '2';
								if (i == 2) jogo->digitado[1 + jogo->m] = '3';
								if (i == 3) jogo->digitado[1 + jogo->m] = '4';
								if (i == 4) jogo->digitado[1 + jogo->m] = '5';
								if (i == 5) jogo->digitado[1 + jogo->m] = '6';
								if (i == 6) jogo->digitado[1 + jogo->m] = '7';
								if (i == 7) jogo->digitado[1 + jogo->m] = '8';
								if (i == 8) jogo->digitado[1 + jogo->m] = '9';
								if (i == 9) jogo->digitado[1 + jogo->m] = '0';
								if (i == 10) jogo->apertado = 2;

								if (jogo->apertado == 2) {
									if (jogo->contadorCord == 0) {
										int aux = jogo->digitado[0] - '0';
										jogo->coordenadasX = (aux * 10) + (jogo->digitado[1] - '0');
										int aux2 = jogo->digitado[2] - '0';
										jogo->coordenadasY = (aux2 * 10) + (jogo->digitado[3] - '0');
										int aux3 = jogo->digitado[4] - '0';
										jogo->coordenadasZ = (aux3 * 10) + (jogo->digitado[5] - '0');
										int aux4 = jogo->digitado[6] - '0';
										jogo->coordenadasA = (aux4 * 10) + (jogo->digitado[7] - '0');
										int aux5 = jogo->digitado[8] - '0';
										jogo->coordenadasB = (aux5 * 10) + (jogo->digitado[9] - '0');
										int aux6 = jogo->digitado[10] - '0';
										jogo->coordenadasC = (aux6 * 10) + (jogo->digitado[11] - '0');
										int aux7 = jogo->digitado[12] - '0';
										jogo->coordenadasD = (aux7 * 10) + (jogo->digitado[13] - '0');
										int aux8 = jogo->digitado[14] - '0';
										jogo->coordenadasE = (aux8 * 10) + (jogo->digitado[15] - '0');
										int aux9 = jogo->digitado[16] - '0';
										jogo->coordenadasF = (aux9 * 10) + (jogo->digitado[17] - '0');
										int aux10 = jogo->digitado[18] - '0';
										jogo->coordenadasG = (aux10 * 10) + (jogo->digitado[19] - '0');
										int aux11 = jogo->digitado[20] - '0';
										jogo->coordenadasH = (aux11 * 10) + (jogo->digitado[21] - '0');
										int aux12 = jogo->digitado[22] - '0';
										jogo->coordenadasI = (aux12 * 10) + (jogo->digitado[23] - '0');
										jogo->apertado = 0;
										jogo->n = 0;
										jogo->m += 1;
									}
								}
							}

							if (jogo->n == 0) {
								if (i == 0) jogo->digitado[0+jogo->m] = '1';
								if (i == 1) jogo->digitado[0 + jogo->m] = '2';
								if (i == 2) jogo->digitado[0 + jogo->m] = '3';
								if (i == 3) jogo->digitado[0 + jogo->m] = '4';
								if (i == 4) jogo->digitado[0 + jogo->m] = '5';
								if (i == 5) jogo->digitado[0 + jogo->m] = '6';
								if (i == 6) jogo->digitado[0 + jogo->m] = '7';
								if (i == 7) jogo->digitado[0 + jogo->m] = '8';
								if (i == 8) jogo->digitado[0 + jogo->m] = '9';
								if (i == 9) jogo->digitado[0 + jogo->m] = '0';
								if (i == 10) jogo->apertado = 1;
								if (jogo->apertado == 1) {
									jogo->n = 1;
								}
							}
						}

					}*/
				
			}
		break;
			case SDL_MOUSEBUTTONUP:
		break;
		}
	}
	jogo->coordenadasX = (jogo->digitado[0] * 10) + (jogo->digitado[1]);
	jogo->coordenadasY = (jogo->digitado[2] * 10) + (jogo->digitado[3]);
	jogo->coordenadasZ = (jogo->digitado[4] * 10) + (jogo->digitado[5]);
	jogo->coordenadasA = (jogo->digitado[6] * 10) + (jogo->digitado[7]);
	jogo->coordenadasB = (jogo->digitado[8] * 10) + (jogo->digitado[9]);
	jogo->coordenadasC = (jogo->digitado[10] * 10) + (jogo->digitado[11]);
	jogo->coordenadasD = (jogo->digitado[12] * 10) + (jogo->digitado[13]);
	jogo->coordenadasE = (jogo->digitado[14] * 10) + (jogo->digitado[15]);
	jogo->coordenadasF = (jogo->digitado[16] * 10) + (jogo->digitado[17]);
	jogo->coordenadasG = (jogo->digitado[18] * 10) + (jogo->digitado[19]);
	jogo->coordenadasH = (jogo->digitado[20] * 10) + (jogo->digitado[21]);
	jogo->coordenadasI = (jogo->digitado[22] * 10) + (jogo->digitado[23]);
	return done;
}