#include <stddef.h>
#include <stdint.h>
#include <math.h>
#include "dos.h"

#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 200

uint8_t* heightmap = NULL;
uint8_t* colormap = NULL;

int main(int argc, char* args[]) {
    setvideomode(videomode_320x200);
    
    uint8_t palatte[256*3];
    int map_width, map_height, pal_count;
    colormap = loadgif("files/C1W.gif", &map_width, &map_height, &pal_count, palatte);
    heightmap = loadgif("files/D1.gif", &map_width, &map_height, NULL, NULL);
    
    for(int i=0; i<pal_count; i++)
    {
        setpal(i, palatte[3*i + 0], palatte[3*i + 1], palatte[3*i + 2]);
    }
    setpal(0, 36, 36, 56);
    
    setdoublebuffer(1);
    uint8_t* framebuffer = screenbuffer();
    
    while (!shuttingdown()) {
        waitvbl();
        clearscreen();
        
        int x = 160;
        int y = 100;
        
        framebuffer[SCREEN_WIDTH * y + x] = 0x50;
        
        framebuffer = swapbuffers();
        
        if(keystate(KEY_ESCAPE))
            break;
    }
    return 0;
}