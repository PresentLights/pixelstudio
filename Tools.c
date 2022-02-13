/**********************************************************************************************************************
    ___________    *                                                                                                  *
   /          /|   *   CREATIVE COMMONS : [CC BY-NC]                                                                  *
  /__________/ |   *   This license allows you to remix, adapt and develop my work for your personal use              *
  |________ |  |   *   as long as you credit me and license your new creations under the same conditions.             *
  /_______/||  |   *                                                                                                  *
  |LICENCE|||  |   *                                                                                                  *
  |_______|/|  |   *   More informations -> https://creativecommons.org/                                              *
  || .___."||  /   *   Licence -> https://creativecommons.org/licenses/by-nc/4.0/                                     *
  ||_______|| /    *                                                                                                  *
  |__________/     *                                                                                                  *
***********************************************************O***********************************************************

          _________________________________________________________________________________________
        / \                                                                                        \ 
       |   |                                                                                        | 
        \_ |                                                                                        | 
           |            _____                          _     _      _       _     _                 |
           |           |  __ \                        | |   | |    (_)     | |   | |                |
           |           | |__) | __ ___  ___  ___ _ __ | |_  | |     _  __ _| |__ | |_ ___           |
           |           |  ___/ '__/ _ \/ __|/ _ \ '_ \| __| | |    | |/ _` | '_ \| __/ __|          |
           |           | |   | | |  __/\__ \  __/ | | | |_  | |____| | (_| | | | | |_\__ \          |
           |           |_|   |_|  \___||___/\___|_| |_|\__| |______|_|\__, |_| |_|\__|___/          |
           |                                                           __/ |                        | 
           |                                                          |___/                         |
           |                                                                                        |
           |           THE ART OF RHYTHM                                                            |  
           |           More informations and documentations -> www.presentlights.fr                 |
           |                                                                                        |
            ----------------------------------------------------------------------------------------
           |                                                                                        |
           |                       ______________________________________                           |
           |              ________|                                      |_______                   |
           |              \       |                Tools.c               |      /                   |
           |               \      |                                      |     /                    |
           |               /      |______________________________________|     \                    |
           |              /__________)                                (_________\                   |
           |                                                                                        |
           |           This librairy provide few usefull mathematical functions                     |
           |   _____________________________________________________________________________________|___
           |  /                                                                                        / 
           \_/dc______________________________________________________________________________________/ 


***********************************************************************************************************************
***********************************************************************************************************************
**  _______________  **************************************************************************************************
** |  DEBUT CODE   | **************************************************************************************************
          _.-"\               *   ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ 
      _.-"     \              * _|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|
   ,-"          \             *|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|_
  ( \            \            * _|___|___|___|                           |___|___|___|___|___|___|___|___|___|___|___|     
   \ \            \           *|___|___|___|_| Version : 1.32            |_|___|___|___|___|___|___|___|___|___|___|_     
    \ \            \          * _|___|___|___| Release : March 2022      |___|___|___|___|___|___|___|___|___|___|___|     
     \ \         _.-;         *|___|___|___|_| Author  : Basile HUARD    |_|___|___|___|___|___|___|___|___|___|___|_ 
      \ \    _.-"   :         * _|___|___|___|_ ___ ___ ___ ___ ___ ___ _|___|___|___|___|___|___|___|___|___|___|___| 
       \ \,-"    _.-"         *|___|___|___|___|___|___|___|___|___|___|___|__|___|___|___|___|___|___|___|___|___|_ 
        \(   _.-"  -shimrod   * _|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___| 
         `--"                 *|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|
***********************************************************O**********************************************************/  


#include "Arduino.h"
#include "Tools.h"


/********************************************************************
                                MATHS
+------+.      +------+       +------+       +------+      .+------+
|`.    | `.    |\     |\      |      |      /|     /|    .' |    .'|
|  `+--+---+   | +----+-+     +------+     +-+----+ |   +---+--+'  |
|   |  |   |   | |    | |     |      |     | |    | |   |   |  |   |
+---+--+.  |   +-+----+ |     +------+     | +----+-+   |  .+--+---+
 `. |    `.|    \|     \|     |      |     |/     |/    |.'    | .'
   `+------+     +------+     +------+     +------+     +------+'
**********************************O*********************************/

//######### BOUND ##########
//--------------------------
float BoundFloat(float value, float valMin, float valMax)
{
 if (value < valMin)
  return valMin;
 if (value > valMax)
  return valMax;
 return value;
}

int16_t BoundInt16(int16_t value, int16_t valMin, int16_t valMax)
{
 if (value < valMin)
  return valMin;
 if (value > valMax)
  return valMax;
 return value;
}

//######### MAP ##########
//------------------------
int16_t MapInt16(int16_t x, int16_t in_min, int16_t in_max, int16_t out_min, int16_t out_max)
{
  if ((in_max - in_min) == 0)
    return out_min;
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

int16_t MapBoundInt16(int16_t x, int16_t in_min, int16_t in_max, int16_t out_min, int16_t out_max)
{
  int16_t val = MapInt16(x, in_min, in_max, out_min, out_max);
  return BoundInt16(val, out_min, out_max);
}

float MapFloat(float x, float in_min, float in_max, float out_min, float out_max)
{
  if ((in_max - in_min) == 0)
    return out_min;
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

float MapBoundFloat(float x, float in_min, float in_max, float out_min, float out_max)
{
  float val = MapFloat(x, in_min, in_max, out_min, out_max);
  return BoundFloat(val, out_min, out_max);
}
//####### RANDOM #########
//------------------------
uint16_t Rnd;
void GenerateRandom()
{
  uint8_t a = (Rnd & 0x8000)>>15;
  uint8_t b = (Rnd & 0x4000)>>14;
  uint8_t c = (Rnd & 0x1000)>>12;
  uint8_t d = (Rnd & 0x0080)>>3;
  uint8_t e = !(a^b);
  uint8_t f = !(c^d);
  uint8_t g = !(e^f);
  Rnd =( Rnd<<1) + g;
}

uint16_t GetRandom(uint16_t max)
{
  GenerateRandom();
  return Rnd % max;
}


//nbMax = 16
void SetDisorderChain(uint8_t *buffer, uint8_t nb)
{
  uint8_t writePtr = 0;
  DisorderItem items[16];
  int i;
  for (i=0;i<nb;i++)
  {
    items[i].tsup = 0;
    items[i].value = i;
  }
  for (i=0;i<nb;i++)
  {
    uint16_t rnd = GetRandom(nb);
    while (items[rnd].tsup == 1)
    {
      rnd++;
      rnd %= nb;
    }
    buffer[writePtr++] = items[rnd].value;
    items[rnd].tsup = 1;
  }
}

uint8_t ByteToAsciiHex(uint8_t value)
{
  if (value>=0 && value<=9)
    return value +'0';
  if (value>=10 && value<=15)
    return value -10 +'A';
  return '0';
}

uint8_t AsciiHexToByte(uint8_t value)
{
  if (value>='0' && value<='9')
    return value - '0';
  if (value>='A' && value<='F')
    return value - 'A' + 10;
  return 0;
}

void ByteChainToAsciiHexChain(uint8_t *in, uint8_t *out, uint8_t nb)
{
  int i;
  for (i=0;i<nb;i++)
    out[i] = ByteToAsciiHex(in[i]);
}

void AsciiHexChainToByteChain(uint8_t *in, uint8_t *out, uint8_t nb)
{
  int i;
  for (i=0;i<nb;i++)
    out[i] = AsciiHexToByte(in[i]);
}

/******************************************************************
                                COLORS
                                _____          /|
                             .-'@ & #`'-.     //
                            / %        8 \   //
                           | m   () _     | //
                            \  0   ( '-._/ //
                      jgs    '-.____'.     y 
**********************************O*********************************/
Color Color_FromInt(uint32_t color)
{
  Color result;
  result.r = (uint8_t)(color >> 16);
  result.g = (uint8_t)(color >> 8);
  result.b = (uint8_t)color;
  return result;
}

Color Color_Brightness(Color Base, float intens)
{
  Color result;
  intens = BoundFloat(intens,0,1);
  result.r = Base.r * intens;
  result.g = Base.g * intens;
  result.b = Base.b * intens;
  return result;
}

void Color_Decrease(Color *color, uint8_t intens)
{
  
  int16_t r = color->r - intens;
  int16_t g = color->g - intens;
  int16_t b = color->b - intens;
  if (r<0)
    r=0;
  if (g<0)
    g=0;
  if (b<0)
    b=0;
  color->r = r;
  color->g = g;
  color->b = b;
}

Color Color_Degrade(Color c1, Color c2, float ratio)
{
  ratio = BoundFloat(ratio,0,1);
  Color c;
  c.r = (uint8_t)MapFloat(ratio,0,1,(float)c1.r,(float)c2.r);
  c.g = (uint8_t)MapFloat(ratio,0,1,(float)c1.g,(float)c2.g);
  c.b = (uint8_t)MapFloat(ratio,0,1,(float)c1.b,(float)c2.b);
  return c;
}

char ColorIsBlack(Color c)
{
  if (c.r > 0)
    return false;
  if (c.g > 0)
    return false;
  if (c.b > 0)
    return false;
  return true;
}

Color Color_RandomMove(Color base, uint8_t rndMove)
{
  int8_t rm = GetRandom(rndMove<<1) - rndMove;
  int8_t gm = GetRandom(rndMove<<1) - rndMove;
  int8_t bm = GetRandom(rndMove<<1) - rndMove;
  
  Color color;
  int16_t r = base.r + rm;
  int16_t g = base.g + gm;
  int16_t b = base.b + bm;
  if (r<0)
    r=0;
  if (g<0)
    g=0;
  if (b<0)
    b=0;
  if (r>255)
    r=255;
  if (g>255)
    g=255;
  if (b>255)
    b=255;
  color.r = r;
  color.g = g;
  color.b = b;
  return color;
}

/*    FIN CODE    *****************************************************************************************************
***********************************************************************************************************************
***********************************************************************************************************************
***********************************************************************************************************************
/ /  \ \____/ /  \ \____/ /  \ \____/ /  \ \____/ /  \ \____/ /  \ \____/ /  \ \____/ /  \ \____/ /  \ \____/ /  \ \__
\ \__/ / __ \ \__/ / __ \ \__/ / __ \ \__/ / __ \ \__/ / __ \ \__/ / __ \ \__/ / __ \ \__/ /    \ \__/ / __ \ \__/ / _
 \____/ /  \ \____/ /  \ \____/ /  \ \____/ /  \ \____/ /  \ \____/ /  \ \____/ /  \ \____/      \____/ /  \ \____/ / 
 / __ \ \__/ / __ \ \__/ / __ \ \__/ / __ \ \__/ / __ \ \__/ / __ \ \__/ /      \__/                  \ \__/ / __ \ \_
/ /  \ \____/ /  \ \____/ /  \ \____/ /  \ \____/ /  \ \____/ /  \ \____/                 -----        \____/ /  \ \__
\ \__/ / __ \ \__/ / __ \ \__/ / __ \ \__/ / __ \ \__/ / __ \ \__/ / __ \                ( o o )              \__/ / _
 \____/ /  \ \____/ /  \ \____/ /  \ \____/ /  \ \____/ /  \ \____/ /  \ \   +-----.oooO--(_)--Oooo.-------+      / / 
 / __ \ \__/ / __ \ \__/ / __ \ \__/ / __ \ \__/ / __ \ \__/ / __ \ \__/ /   |                             |   __ \ \_
/ /  \ \____/ /  \ \____/ /  \ \____/ /  \ \____/ /  \ \____/ /  \ \____/    |  By Basile HUARD            |  /  \ \__
\ \__/ / __ \ \__/ / __ \ \__/ / __ \ \__/ / __ \ \__/ / __ \ \__/ / __ \    |        www.PresentLights.fr |  \__/ / _
 \____/ /  \ \____/ /  \ \____/ /  \ \____/ /  \ \____/ /  \ \____/ /  \ \   |       .oooO            2022 |      / / 
 / __ \ \__/ / __ \ \__/ / __ \ \__/ / __ \ \__/ / __ \ \__/ / __ \ \__/ /   |       (   )   Oooo.         |   __ \ \_
/ /  \ \____/ /  \ \____/ /  \ \____/ /  \ \____/ /  \ \____/ /  \ \____/    +--------\ (----(   )---------+  /  \ \__
\ \__/ / __ \ \__/ / __ \ \__/ / __ \ \__/ / __ \ \__/ / __ \ \__/ / __ \        __    \_)    ) /        __   \__/ / _
 \____/ /  \ \____/ /  \ \____/ /  \ \____/ /  \ \____/ /  \ \____/ /  \ \____  /  \  ____   (_/  ____  /  \  ____/ / 
 / __ \ \__/ / __ \ \__/ / __ \ \__/ / __ \ \__/ / __ \ \__/ / __ \ \__/ / __ \ \__/ / __ \      / __ \ \__/ / __ \ \_
/ /  \ \____/ /  \ \____/ /  \ \____/ /  \ \____/ /  \ \____/ /  \ \____/ /  \ \____/ /  \ \____/ /  \ \____/ /  \ \__
\ \__/ / __ \ \__/ / __ \ \__/ / __ \ \__/ / __ \ \__/ / __ \ \__/ / __ \ \__/ / __ \ \__/ / __ \ \__/ / __ \ \__/ / */
