//----------------------------------------------------------------------
// plotfilter.c
//----------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

// Define screen dimensions
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

// Plot a point on the SDL renderer
void plotPoint(SDL_Renderer *renderer, float x, float y) {
    int px = (int)x;
    int py = (int)y;
    SDL_RenderDrawPoint(renderer, px, py);
}

// Main function: Reads scale and points from stdin and plots them
int main(void) {
    float x0, y0, x1, y1;
    float x, y;

    scanf("%f %f %f %f", &x0, &y0, &x1, &y1);

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow("Plot Filter", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                          SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (!window) {
        fprintf(stderr, "Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black background
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Red points

    // Read and plot the points until EOF
    while (scanf("%f %f", &x, &y) == 2) {
        // Transform the points to fit the screen
        int px = (int)((x - x0) / (x1 - x0) * SCREEN_WIDTH);
        int py = SCREEN_HEIGHT - (int)((y - y0) / (y1 - y0) * SCREEN_HEIGHT);
        plotPoint(renderer, px, py);
        SDL_RenderPresent(renderer);
        SDL_Delay(1); // Small delay for better visualization
    }

    // Keep the window open until closed by the user
    SDL_Event event;
    int quit = 0;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = 1;
            }
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

//----------------------------------------------------------------------

// Compile and run:
// gcc -o 25_plotfilter 25_plotfilter.c -lSDL2
// cat usa.txt | ./25_plotfilter
