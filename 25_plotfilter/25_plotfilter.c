//----------------------------------------------------------------------
// 25_plotfilter.c
//----------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

SDL_Renderer *initializeSDL(SDL_Window **window) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        exit(1);
    }

    *window = SDL_CreateWindow("Plot Filter", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                               SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (!*window) {
        fprintf(stderr, "Window could not be created! SDL_Error: %s\n", SDL_GetError());
        exit(1);
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    return renderer;
}

void cleanupSDL(SDL_Window *window, SDL_Renderer *renderer) {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void plotPoint(SDL_Renderer *renderer, int x, int y) {
    SDL_RenderDrawPoint(renderer, x, y);
}

void transformAndPlot(SDL_Renderer *renderer, float x, float y, float x0, float y0, float x1, float y1) {
    int px = (int)((x - x0) / (x1 - x0) * SCREEN_WIDTH);
    int py = SCREEN_HEIGHT - (int)((y - y0) / (y1 - y0) * SCREEN_HEIGHT);
    plotPoint(renderer, px, py);
    SDL_RenderPresent(renderer);
}

void handleEvents() {
    SDL_Event event;
    int quit = 0;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = 1;
            }
        }
    }
}

int main(void) {
    float x0, y0, x1, y1, x, y;
    scanf("%f %f %f %f", &x0, &y0, &x1, &y1);

    SDL_Window *window = NULL;
    SDL_Renderer *renderer = initializeSDL(&window);

    while (scanf("%f %f", &x, &y) == 2) {
        transformAndPlot(renderer, x, y, x0, y0, x1, y1);
        SDL_Delay(1);
    }

    handleEvents();
    cleanupSDL(window, renderer);
    return 0;
}

//----------------------------------------------------------------------

// Compile and run:
// gcc -o 25_plotfilter 25_plotfilter.c -lSDL2
// cat usa.txt | ./25_plotfilter
