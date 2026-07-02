#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_video.h>
#include <SDL3/SDL_pixels.h>
#include <SDL3/SDL_stdinc.h>
#include <stdio.h>
#include <SDL2/SDL.h>

int main(){
    const int width = 800;
    const int height = 800;

    printf("Hello world\n");
    SDL_Window *pwindow = SDL_CreateWindow("¡LOL!",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,width,height,0);
    SDL_Surface *psurface = SDL_GetWindowSurface(pwindow);

    Uint8 r,g,b;
    r=0x00;
    g=0x00;
    b=0xFF;

    Uint32 color = SDL_MapRGB(psurface->format,r,g,b);
    Uint32 color_inner = SDL_MapRGB(psurface->format,0xFF,0x00,0x00);
    
    for (int x = 0; x < width;x++){
        for (int y = 0; y < height; y++){
        if (x % 2 == 0){
            SDL_Rect pixel = (SDL_Rect){x,y,1,1};
            SDL_FillRect(psurface, &pixel, color);
        }else {
            SDL_Rect pixel = (SDL_Rect){x,y,1,1};
            SDL_FillRect(psurface, &pixel, color_inner);
        }
        }
    }
    SDL_UpdateWindowSurface(pwindow);
    SDL_Delay(3000);
    return 1;
}
