#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <stdio.h>
#include <stdlib.h>
int main() {
  FILE *in = stdin;
  char *ps = calloc(1000, sizeof(char));

  // read the first line
  fgets(ps, 1000, in);

  // read the second line

  fgets(ps, 1000, in);
  free(ps);
  // read the third line

  char *pdimen = calloc(1000, sizeof(char));

  int width = -1;
  int height = -1;
  fgets(pdimen, 1000, in);
  sscanf(pdimen, "%d %d\n", &width, &height);
  free(pdimen);

  // printf("hello bhai");

  SDL_Window *pwindow =
      SDL_CreateWindow("image viewer", SDL_WINDOWPOS_CENTERED,
                       SDL_WINDOWPOS_CENTERED, width, height, 0);

  SDL_Surface *psurface = SDL_GetWindowSurface(pwindow);
  Uint32 color = 0;

  SDL_Rect pixel = (SDL_Rect){0, 0, 1, 1};
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {

      Uint8 r, g, b;
      r = (char)getchar();
      g = (char)getchar();
      b = (char)getchar();

      color = SDL_MapRGB(psurface->format, r, g, b);
      pixel.x = x;
      pixel.y = y;
      SDL_FillRect(psurface, &pixel, color);
    }
  }

  SDL_UpdateWindowSurface(pwindow);
  int app_running = 1;

  while (app_running) {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        app_running = 0;
      }
    }
  }
  return 0;
}
