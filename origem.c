#include <stdio.h>
#include <sdl.h>
#include <SDL_Image.h>
#include <SDL_ttf.h>
#include "Cabeçalho.h"
#include <time.h>
#include <stdlib.h>

int main(int argc, char* argv []) 
{
	SDL_Window* janela = NULL;
	SDL_Renderer* renderizador = NULL;
	Jogo jogo;

	SDL_Init(SDL_INIT_EVERYTHING);

	srand((int)time(NULL));

	janela = SDL_CreateWindow("matematica", 0, 0, 1768, 992, SDL_WINDOW_FULLSCREEN_DESKTOP);

	renderizador = SDL_CreateRenderer(janela, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	jogo.renderer = renderizador;

	TTF_Init();

	inicializacaoTermos(&jogo);

	int done = 0;

	while (!done) {
		done = eventos(janela, &jogo);

		renderizar(&jogo);
	}

	SDL_DestroyWindow(janela);

	SDL_DestroyRenderer(jogo.renderer);
	SDL_DestroyRenderer(renderizador);

	TTF_CloseFont(jogo.fonte);

	TTF_Quit();
	SDL_Quit();
	return(0);
}