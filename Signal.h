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
           |              \       |               Signal.h               |      /                   |
           |               \      |                                      |     /                    |
           |               /      |______________________________________|     \                    |
           |              /__________)                                (_________\                   |
           |                                                                                        |
           |           This librairy provide various rhythmical signals for yours programs          |
            ---------------------------------------------------------------------------------------- 
           |                                                                                        |
           |                                THEORY OF OPERATION                                     |
           |                                -------------------                                     |
           |                         Example for a two staged signal                                |
           |                                                                                        |
           |     x axis input        Stage 1            Stage 2          y axis output              |
           |                          y->x               y->x                                       |
           |                                                                                        |
           |                 /         /\                     _ _            ____                   |
           |               /          /  \                 _ /              /    \                  |
           |             /           /    \              /                 |      |                 |
           |           /            /      \           /                  /        \                |
           |         /             /        \         |                  |          |               |
           |       /              /          \       /                  /            \              |
           |     /               /            \     |                   |            |              |
           |                                                                                        |
           |    Source Sync   +       Trip        +    Compress    =     "Bounce Effect"            |
           |                        Function           Function              Signal                 |
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
#include "BTP.h"
/********************************************************************
                             DEFINITIONS
                              .----.-.
                             /    ( o \
                            '|  __ ` ||
                             |||  ||| -'
**********************************O*********************************/
//Rhythmical values
#define QUARTER          1
#define EIGHT            2
#define SIXTEEN          3
#define SIXTEEN_TRIPLET  4
#define HALF             5
#define WHOLE            6
#define QUARTER_CHORUS   7
#define HALF_CHORUS      8
#define CHORUS           9 

//French rhythmical values
#define NOIRE           QUARTER
#define CROCHE          EIGHT
#define DOUBLE_CROCHE   SIXTEEN
#define TRIPLE_CROCHE   SIXTEEN_TRIPLET
#define BLANCHE         HALF
#define RONDE           WHOLE
#define PHRASE          QUARTER_CHORUS
#define DEMI_PAGE       HALF_CHORUS
#define PAGE            CHORUS


//Signal stage functions
#define TRIP       1    //Come & Go
#define SINUS      2    //Sinus
#define COMPRESS   3    //Compression of signal
#define EXPAND     4    //Expansion of signal
#define CONCAV     5    //Deceleration on center
#define CONVEX     6    //Acceleration on center

/********************************************************************
                               STRUCTURES
                         __(.)< __(.)> __(.)=
                         \___)  \___)  \___) hjw
**********************************O*********************************/
//Each signal is composed by a number of cascade stages
typedef struct 
{
  uint8_t function;   //type of function
  uint8_t order;      //number of occurence it is calculated
  uint8_t invert;     //Y inverted (after function)
  uint8_t mirror;     //X inverted (before function
  uint8_t phase;      //X phase (before function)
}SignalStage;

//The signal object is a complex argument that is initialized just before the execution
typedef struct Signal
{
  uint8_t solfege;        //Rhythmical value
  uint8_t nbStages;       //Number of defined stages 
  SignalStage stages[5];  //Stages array
  uint8_t val;            //Exchange value (either input and output)
}Signal;

/********************************************************************
                              DECLARATIONS
                            ,_     ,     .'<_
                           _> `'-,'(__.-' __<
                           >_.--(.. )  =;`
                     jgs        `V-'`'\/``
**********************************O*********************************/
uint8_t Signal_Expand(uint8_t x);
uint8_t Signal_Compress(uint8_t x, bool invert);

uint8_t Signal_Function(Signal *sig, uint8_t x);
void Signal_ExecuteSolfege(Signal *sig);

void SignalPreset_Cloud(Signal *signals);

uint8_t SignalPlay_Bounce(uint8_t solfege,uint8_t phase);
uint8_t SignalPlay_Bounce4(uint8_t solfege,uint8_t phase); 
uint8_t SignalPlay_Sinus(uint8_t solfege,uint8_t phase);
uint8_t SignalPlay_Compress(uint8_t solfege,uint8_t phase);
uint8_t SignalPlay_Expand(uint8_t solfege,uint8_t phase);
uint8_t SignalPlay_SinusConvex(uint8_t solfege,uint8_t phase);

//New
uint8_t SignalPlay_Explode(uint8_t solfege,uint8_t phase);
uint8_t SignalPlay_Trip(uint8_t solfege,uint8_t phase);
uint8_t SignalPlay_TripConcave(uint8_t solfege, uint8_t order,uint8_t phase);
uint8_t SignalPlay_ConcavOrder(uint8_t solfege, uint8_t order,uint8_t phase);

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
