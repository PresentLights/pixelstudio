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
           |              \       |               Mapping.h              |      /                   |
           |               \      |                                      |     /                    |
           |               /      |______________________________________|     \                    |
           |              /__________)                                (_________\                   |
           |                                                                                        |
           |           This section permit you to configure your own physical ledstrips structure   |
            ----------------------------------------------------------------------------------------
           |                                                                                        |
           |                                THEORY OF OPERATION                                     |
           |                                -------------------                                     |
           |                                                                                        |
           |                       19 18 17 16 15        39 38 37 36 35                             |
           |                     0               14    20              34                           |
           |                     1               13    21              33                           |
           |                     2 ^  zero       12    22 ^  zero      32                           |
           |                     3 | /           11    23 | /          31                           |
           |                     4 .  ->         10    24 .  ->        30                           |
           |                       5  6  7  8  9         25 26 27 28 29                             |
           |                                                                                        |
           |     -LedStrip Nb pixel = 40                                                            |
           |                                                                                        |
           |     -LedFragment LeftLeft   : start : 4  lenght : 5 reverse=true       backward            |
           |     -LedFragment LeftBot    : start=5  lenght=5 reverse=false                          |
           |     -LedFragment LeftRight  : start=10 lenght=5 reverse=false                          |
           |     -LedFragment LeftTop    : start=19 lenght=5 reverse=true                           |
           |                                                                                        |
           |     -LedFragment RightLeft  : start=24 lenght=5 reverse=true                           |
           |     -LedFragment RightBot   : start=25 lenght=5 reverse=false                          |
           |     -LedFragment RightRight : start=30 lenght=5 reverse=false                          |
           |     -LedFragment RightTop   : start=39 lenght=5 reverse=true                           |
           |                                                                                        |
           |     -LedMap Top         : LeftTop   , RightTop                                         |
           |     -LedMap Bot         : LeftBot   , RightBot                                         |
           |     -LedMap AllVertical : LeftLeft  , LeftRight , RightLeft , RightRight               |
           |     -LedMap LeftDiag    : LeftLeft , LeftBot                                           |
           |     -LedMap RightDiag   : RightLeft , RightBot                                         |
           |     -LedMap AllLeft     : LeftLeft  , LeftBot   , LeftRight , LeftTop                  |
           |     -Etc.                                                                              |
           |                                                                                        |
           |     -Mapping AllHorizontal : Top , Bot                                                 |
           |     -Mapping AllDiag : LeftDiag, RightDiag                                             |
           |                                                                                        |
            ----------------------------------------------------------------------------------------
           |                                                                                        |
           |                                  CURRENT EXAMPLE                                       |
           |                                  ---------------                                       |
           |                       Flat mapping of 4 x bar of 42 LEDs                               |
           |                                                                                        |
           |         data______       ________       ________       ________                        |
           |                   \     /        \     /        \     /        \                       |
           |           start -> 0   |          42  |          84  |         126                     |
           |                    1   |          43  |          85  |         127                     |
           |                    2   |          44  |          86  |         128                     |
           |                    3   |          45  |          87  |         129                     |
           |                    .   |           .  |           .  |           .                     |
           |                    .   |           .  |           .  |           .                     |
           |            zero -> 41  |          83  |         125  |         167 <- end              |
           |                    |   |          |   |          |   |                                 |
           |                     \_/            \_/            \_/                                  |
           |                                                                                        |
           |                  Frag_Bar1       Frag_Bar2      Frag_Bar3     Frag_Bar4                |
           |                  Map_Bar1        Map_Bar2       Map_Bar3      Map_Bar4                 |
           |                                                                                        |
           |                                                                                        |
           |                                                                                        |
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
           
#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include "Arduino.h"
#include <stdint.h>
#include "Tools.h"
#include "Signal.h"

/********************************************************************
                             DEFINITIONS
                              .----.-.
                             /    ( o \
                            '|  __ ` ||
                             |||  ||| -'
**********************************O*********************************/
//USER...
#define STRIP_BAR_NB_LEDS_MAX      168      //Size of the unique ledstrip

#define NB_UNIVERSES    3


//STARTUP MULTIPLE CONFIGURATIONS
#define MAPPING_PRESET_4_1000    0
#define MAPPING_PRESET_4_1500    1


//Mapping types
#define MAP_BAR_1  		        1
#define MAP_BAR_2  		        2
#define MAP_BAR_3  		        3
#define MAP_BAR_4  		        4
#define MAP_BAR_ODD           5
#define MAP_BAR_EVEN          6
#define MAP_BAR_LEFT          7
#define MAP_BAR_RIGHT         8
#define MAP_BAR_CENTER        9
#define MAP_BAR_EXT           10
#define MAP_BAR_ALL           11

//MEMORY
#define MAPPING_NB_MAX        4 //In this example we don't need more


//LAYERS
#define NB_LAYERS         4
#define LAYER_SIZE_MAX    50
#define LAYER_DEFAULT_SCALE    20

#define LAYER_EFFECT_PERSIST    0
#define LAYER_EFFECT_DEGRADE    1
#define LAYER_EFFECT_SPARKS     2



//MACROS UNIVERSE
#define u   mm.currentUniverse
#define u0  mm.universes[0]
#define u1  mm.universes[1]
#define u2  mm.universes[2]

#define U   &u
#define U0  &u0
#define U1  &u1
#define U2  &u2


//MACROS LAYER
#define l0  mm.currentUniverse->layers[0]
#define l1  mm.currentUniverse->layers[1]
#define l2  mm.currentUniverse->layers[2]
#define l3  mm.currentUniverse->layers[3]


#define L0  &l0
#define L1  &l1
#define L2  &l2
#define L3  &l3
/********************************************************************
                               STRUCTURES
                         __(.)< __(.)> __(.)=
                         \___)  \___)  \___) hjw
**********************************O*********************************/

//physical led strip
typedef struct 
{
  uint8_t address;    //redirect pin output via wrapper (cf. [Project].cpp)
  uint16_t nb;        //number of leds for this strip
  Color *buffer;      //pointer to static buffer (permit memory size management) 
}LedStrip;

//Subdivision of strip
typedef struct
{
  LedStrip *strip;    //parent
  uint16_t start;     //first pixel address (0-->n)
  uint16_t nbPixels;  //fragment lenght (nb leds)
  uint8_t reverse;    //mapping in reverse direction (placement of the zero position)
}LedFragment;

//Recomposition of fragmant to make a unique path
typedef struct
{
  uint16_t nbFragments;       //number of fragments composing this map
  LedFragment *fragments;     //pointeur to fragments array
  uint16_t nbPixels;          //total number of pixels for this map (calculated)
}LedMap;

//Group of maps
typedef struct 
{
  uint8_t nbMaps;                  //number of map composing this mapping
  LedMap *maps[MAPPING_NB_MAX];   //pointer array to each LedMap*
}Mapping;


//USER:
//Your physical structure...
//this example is very simple and doesn't demonstrate the complexity of possibles mappings (see others examples like "le prestige infini")
//Contain global objects, buffers and arrays
//One implementation only
typedef struct 
{
  //LedStrip stripBar;             
  LedStrip stripA;                      //Physical led strip
  LedStrip stripB;                      //Physical led strip
  LedStrip stripC;                      //Physical led strip
  Color stripBufferA[STRIP_BAR_NB_LEDS_MAX];   //Static buffer for this physical led strip
  Color stripBufferB[STRIP_BAR_NB_LEDS_MAX];   //Static buffer for this physical led strip
  Color stripBufferC[STRIP_BAR_NB_LEDS_MAX];   //Static buffer for this physical led strip

  LedFragment FragA_Bar1;  
  LedFragment FragA_Bar2;
  LedFragment FragA_Bar3;
  LedFragment FragA_Bar4;

  LedMap MapA_Bar1;  
  LedMap MapA_Bar2;
  LedMap MapA_Bar3;
  LedMap MapA_Bar4;

  
  LedFragment FragB_Bar1;  
  LedFragment FragB_Bar2;
  LedFragment FragB_Bar3;
  LedFragment FragB_Bar4;

  LedMap MapB_Bar1;  
  LedMap MapB_Bar2;
  LedMap MapB_Bar3;
  LedMap MapB_Bar4;

  LedFragment FragC_Bar1;  
  LedFragment FragC_Bar2;
  LedFragment FragC_Bar3;
  LedFragment FragC_Bar4;

  LedMap MapC_Bar1;  
  LedMap MapC_Bar2;
  LedMap MapC_Bar3;
  LedMap MapC_Bar4;
  
}MappingStructure;








typedef struct 
{
  Color stampColor;  
  Color color;  
  uint8_t sync;
  uint8_t scale;
  char active;

}LayerPixel;

typedef struct 
{
  LayerPixel pixels[LAYER_SIZE_MAX];  
  uint8_t nbPoints;
  int8_t lastPos; //-1 = first use (for transitions)
  uint8_t scale;
  uint8_t colorID;
  uint8_t effect;
  uint8_t rndScale;
  uint8_t rndFlash;
  uint8_t rndBurn;
  uint8_t rndColor;
}Layer;



typedef struct 
{
  LedStrip strip;                      //Physical led strip
  Color stripBuffer[STRIP_BAR_NB_LEDS_MAX];   //Static buffer for this physical led strip

  LedFragment Frag_Bar1;  
  LedFragment Frag_Bar2;
  LedFragment Frag_Bar3;
  LedFragment Frag_Bar4;

  LedMap Map_Bar1;  
  LedMap Map_Bar2;
  LedMap Map_Bar3;
  LedMap Map_Bar4;

  Layer layers[NB_LAYERS];
  char programPreset;
  
}Universe;



typedef struct 
{

  
  Universe universes[NB_UNIVERSES];
  Universe *currentUniverse;
  
}MappingManager;
/********************************************************************
                              DECLARATIONS
                            ,_     ,     .'<_
                           _> `'-,'(__.-' __<
                           >_.--(.. )  =;`
                     jgs        `V-'`'\/``
**********************************O*********************************/
void Mapping_Setup();
void Mapping_ClearStrip(LedStrip *strip);
void Mapping_Preset(Mapping *m, uint8_t preset);
uint8_t Mapping_GetRandomPreset();
uint8_t Mapping_FromID(uint8_t mappingID);
float Mapping_MapBound(uint8_t x, LedMap *map);

void Paint_Plot(uint8_t x, Color color, Mapping *m);
void Paint_Bean(uint8_t x0,uint8_t x1, Color color, Mapping *m);
void Paint_Degrade(Color c1,Color c2, Mapping *m);
void Paint_PlotPersist(uint8_t x, uint8_t colorID, Mapping *m, Layer *layer);
void Paint_PlotSparks(uint8_t x, uint8_t colorID, Mapping *m, Layer *layer);


void Layers_Clear();
void Layers_SetScale(uint8_t scale);
void Layers_SetSize(uint8_t nbPoints);
void Layers_SetRandomize(uint8_t rndScale, uint8_t rndFlash, uint8_t rndBurn, uint8_t rndColor);

void Layer_FeedPersist(Layer *layer, uint8_t x, Color color, char fill);
void Layer_PaintPersist(Layer *layer, Mapping *m);
void Layer_ExecutePersist(Layer *layer);


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

#ifdef __cplusplus
} // extern "C"
#endif
