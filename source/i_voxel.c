#include <stdint.h>
#include <math.h>
#include "dos.h"

#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 200

int main(int argc, char* args[]) {
    setvideomode(videomode_320x200);
    setdoublebuffer(1);
    uint8_t* framebuffer = screenbuffer();
    
    while (!shuttingdown()) {
        waitvbl();
        clearscreen();
        
        framebuffer = swapbuffers();
        
        if(keystate(KEY_ESCAPE))
            break;
    }
    return 0;
}