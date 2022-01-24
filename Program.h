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
           |              \       |               Program.h              |      /                   |
           |               \      |                                      |     /                    |
           |               /      |______________________________________|     \                    |
           |              /__________)                                (_________\                   |
           |                                                                                        |
           |           Here reside your artistic compositions                                       |
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
//#include <stdint.h>
#include "Tools.h"
#include "Signal.h"
#include "Mapping.h"
#include "BTP.h"

/********************************************************************
                             DEFINITIONS
                              .----.-.
                             /    ( o \
                            '|  __ ` ||
                             |||  ||| -'
**********************************O*********************************/
//MEMORY
//Static objetcs collections sizes
#define NB_FLASHS_MAX     20
#define NB_SHUTTLE_MAX    20

//CONFIG
#define FLASH_DURATION    500     //ms before shutdown


#define PROGRAM_MODE_CALM     0
#define PROGRAM_MODE_SCAN     1
#define PROGRAM_MODE_MATH     2
#define PROGRAM_MODE_LOST     3
#define PROGRAM_MODE_MANUAL   4


#define PROGRAM_BLACKOUT  0
#define PROGRAM_PRIDE     1
#define PROGRAM_REACTIVE  2
#define PROGRAM_PATTERN   3
#define PROGRAM_DANCE_1   4
#define PROGRAM_DANCE_2   5
#define PROGRAM_DANCE_3   6
#define PROGRAM_DANCE_4   7
#define PROGRAM_DISTRIB   8
#define PROGRAM_BUBBLE    9
#define PROGRAM_PULSE     10
#define PROGRAM_CROSS     11
#define PROGRAM_CLAP      12
#define PROGRAM_FLASH     13
#define PROGRAM_STARS     14

//New
#define PROGRAM_EXPLODE    15
#define PROGRAM_HAMMER     16
#define PROGRAM_BOUNCE     17
#define PROGRAM_SNAKES     18
#define PROGRAM_LINEAR     19
#define PROGRAM_DROPS      20
#define PROGRAM_SPARKS     21



//STARTUP CONFIGURATION PRESET
#define PROGRAM_PRESET_VERTICAL      0
#define PROGRAM_PRESET_HORIZONTAL    1
/********************************************************************
                               STRUCTURES
                         __(.)< __(.)> __(.)=
                         \___)  \___)  \___) hjw
**********************************O*********************************/

//Object that is used for sound reactive programs
typedef struct 
{
  char active;        //in use (out of the shelve)
  uint32_t timer;     //for decreasing intensity
  float intensity;    //intensity of light or width, or other application
}OnsetFlash;

typedef struct 
{
  char active;            //in use (out of the shelve)
  OnsetFlash *flash;      //Connected flash used by this shuttle
  uint8_t mappingPreset;  //the random output is defined one time at the creation
  uint8_t colorId;        //the random color is defined one time at the creation
  uint16_t pos;           //random position
  uint8_t width;          //current decreasing width

  //EffectScale
  uint32_t effectStart;
  uint32_t effectStop;
  uint16_t effectStep;  //ms per scale Unit
  uint8_t scale;        //Start Amplitude
  uint8_t sync;         //Proportional execution 0-255 for maths
  
  //Snakes
  uint8_t direction;          //current direction of snake
  float speed;          //decreasing snake speed (negative for direction)
  float posOffset;      //fine increment for snakes animation
}Shuttle;

//Contain collection information for the execution
typedef struct 
{
  uint8_t nbPrograms;     //Number of programs in this group
  uint8_t programIndex;   //Current selected program
}ProgramGroup;

//Contain global variables and collections for the runtime
//One implementation only
typedef struct 
{
  uint8_t prgMode;
  uint8_t prgIndexCALM,prgIndexSCAN,prgIndexMATH,prgIndexLOST,prgIndexMANUAL;
  
  ProgramGroup groups[4];
  OnsetFlash flashs[NB_FLASHS_MAX];
  Shuttle shuttles[NB_SHUTTLE_MAX];

  uint32_t programFreeTimer;
 // Layer layers[NB_LAYERS];
}ProgramManager;

/********************************************************************
                              DECLARATIONS
                            ,_     ,     .'<_
                           _> `'-,'(__.-' __<
                           >_.--(.. )  =;`
                     jgs        `V-'`'\/``
**********************************O*********************************/
void Program_Setup();
void Program_Loop();
void Program_Increment(uint8_t programGroup, uint8_t up);
void Program_IncrementCurrent();

//TOOLS
OnsetFlash *NewFlash();
Shuttle *NewShuttle();

void Layers_Clear();

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
