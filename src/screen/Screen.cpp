#include "Screen.h"
extern "C"{
#include <stdlib.h>
#include "GUI_Paint.h"
#include "LCD_1in44.h"
#include "Infrared.h"
}

const uint8_t SCREENWIDTH = 128;
const uint8_t SCREENHEIGHT = 128;

const int key0 = 15;
const int key1 = 17;
const int key2 = 2;
const int key3 = 3;

uint16_t *BlackImage = NULL;

void initDisplay(void)
{
    DEV_Delay_ms(100);
    if (DEV_Module_Init() != 0)
    {
        return;
    }

    /* LCD Init */
    LCD_1IN44_Init(0);
    LCD_1IN44_Clear(WHITE);

    // LCD_SetBacklight(1023);
    uint16_t Imagesize = SCREENWIDTH * SCREENHEIGHT * 2;
    if ((BlackImage = (UWORD *)malloc(Imagesize)) == NULL)
    {
        exit(0);
    }

    // /*1.Create a new image cache named IMAGE_RGB and fill it with white*/
    Paint_NewImage((uint8_t *)BlackImage, SCREENWIDTH, SCREENHEIGHT, 0, WHITE);
    Paint_SetScale(65);
    Paint_Clear(WHITE);
    Paint_SetRotate(ROTATE_270);
    Paint_Clear(WHITE);

    SET_Infrared_PIN(key0);
    SET_Infrared_PIN(key1);
    SET_Infrared_PIN(key2);
    SET_Infrared_PIN(key3);
}