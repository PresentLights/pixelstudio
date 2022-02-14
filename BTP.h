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
           |              \       |                 BTP.h                |      /                   |
           |               \      |                                      |     /                    |
           |               /      |______________________________________|     \                    |
           |              /__________)                                (_________\                   |
           |                                                                                        |
           |           This file is the Beat Tracker Pro driver                                     |
           |           It permit you to get the rhythmic synchro, sound reactive shape and modes    |
           |           It also generate palettes of colors and program change                       |
            ---------------------------------------------------------------------------------------- 
           |                                                                                        |
           |                             BEAT TRACKER PRO DATASHEET                                 |
           |                             --------------------------                                 |
           |                                                                                        |
           |                                      audio in                                          |
           |                                          |                                             |
           |                                        __v_                                            |
           |                           ____________| rca|___________                                |
           |                          / |     |   _|    |_        on\                               |
           |                         |  |     |  |        |        o |                              |
           |                         |  |     |  |        |          |                              |
           |                         |O |_____|   ________           |                              |
           |                         |.          |   __   |         O|                              |
           |                         |.          |  /  \  |         .| SYNC -> D13                  |
           |                         |.          |  \__/  |         .| M1   -> D12                  |
           |                         |.          |________|         .| M0   -> D11                  |
           |                         |.             gain            .|                              |
           |                         |.                             .|                              |
           |                         |.    o Peak                   .|                              |
           |                         |     o Signal                 .|                              |
           |            A0 <-    SAW |.                             .|                              |
           |            A1 <-  SHAPE |.    o Calm                   .|                              |
           |                         |.    o Scan                   .|                              |
           |                         |.    o Math                   .|                              |
           |                         |.                             .|                              |
           |                         |     o Sync          _________/                               |
           |                          \O_________________O/                                         |
           |                                                                                        |
           |                                                                                        |
           |    POWER:                                                                              |
           |       -Needs 12V, 5V & 3.3V                                                            |
           |                                                                                        |
           |    AUDIO INPUT                                                                         |
           |       -Galvanic Isolated asymetrical line 600 ohms                                     |
           |                                                                                        |
           |    INDICATORS                                                                          |
           |       - LED 1 (Blue)   : Power ON                                                      |
           |       - LED 2 (Red)    : Peak (audio saturation)                                       |
           |       - LED 3 (Yellow) : Signal (audio present)                                        |
           |       - LED 4 (Green)  : Calm (not enough volume)                                      |
           |       - LED 5 (Orange) : Scan (volume present but ryhthme not synchronised)            |
           |       - LED 6 (Blue)   : Math (rhytmicaly synchronized)                                |
           |       - LED 7 (Blue)   : Sync (beat pulsation)                                         |
           |                                                                                        |
           |    TUNING                                                                              |
           |       - When audio is present, turn the gain potentiometer until the yellow            |
           |         "Signal indicator" start blinking but the red "Peak indicator" must stays off. |
           |         (It still works even if it shortly lights)                                     |
           |                                                                                        |
           |    SIGNALS                                                                             |
           |       o M0, M1 (Digital outputs)                                                       |
           |            -These outputs serve user applications to switch over 3 differents          |
           |            groups of programs                                                          |
           |             ___________________________________________________________________        |
           |            |_M1_|_M0_|__MODE__|________________DESCRIPTION_____________________|       |
           |            |  0 |  0 |  CALM  |  music is quiet, better to use slow programs   |       |
           |            |  0 |  1 |  SCAN  |  music is present but no rhythme, better to use|       |
           |            |    |    |        |  sound reactive programs                       |       |
           |            |  1 |  0 |  MATH  |  rhythme is present, so we can accentuate the  |       |
           |            |    |    |        |  pulsation to bring joy at dancing             |       |
           |            |    |    |        |  this mode is a "world first" algorithm        |       |
           |            |  1 |  1 |    -   |  not implemented                               |       |
           |             -------------------------------------------------------------------        |                                                                   |
           |                                                                                        |
           |       o SYNC (Digital output)                                                          |
           |            -This ouput may not be used, it equals to the Sync Indicator Led Signal     |
           |                                                                                        |
           |                |<--------------------------->|                                         |
           |                 __          BPM               __                                       |
           |             ___|  |__________________________|  |__________________  Not MATH          |
           |                                                                                        |
           |                 _____                         _____                                    |
           |             ___|     |_______________________|     |_______________  MATH ok           |
           |                                                                                        |
           |            NOTE : This signal can be use for incremental actions, but if your          |
           |            application need transition counters, you will need to read the delay       |
           |            and thus code your own tapsync, what becomes very difficult to              |
           |            phase synchronize without glitchs on BPM variations                         |
           |                                                                                        |
           |                                                                                        |
           |       o SHAPE (Analog output 0->3.3V)                                                  |
           |            -This signal represent the shape of the volume amplitude, it is very        |
           |            usefull when we don't have yet the rhythme. It is widely used in standart   |
           |            lighting applications as sound reactive blinking                            |
           |                                                                                        |
           |                                                                                        |
           |                 .-.                                   .-.                              |
           |                /   \                                 /   \                             |
           |               /     \                               /     \                            |
           |              /       \       .-.                   /       \       .-.                 |
           |             /         \     /   \                 /         \     /   \                |
           |            /           \___/     \_______________/           \___/     \               |
           |                                                                                        |
           |                                                                                        |
           |       o SAW (Analog output 0->3.3V)                                                    |
           |            -This signal is the big one, it permit you a new experience of lightings.   |
           |            Instead of common sound reactive application, this one stays perfectly      |
           |            in phase & BPM.                                                             |
           |            -The saw shaped signal drives your program whithout the necessity of        |
           |            counting delay, thus every slaves systems becomes perfectly synchronized    |
           |            -Each new pulsation are detected by the falling edge                        |
           |                                                                                        |
           |                                     phase sync                                         |
           |                         BPM         highlight            new beat                      |
           |                      <------->          o                    |                         |
           |                    /|        /|        /|        /|        /|v       /|                |
           |                  /  |      /  |      /  |      /  |      /  |     /  |                 |
           |                /    |    /    |    /    |    /    |    /    |    /    |    /           |
           |              /      |  / .    |  /      |  /      |  /      |  /      |  /             |
           |            /        |/   |    |/        |/        |/        |/        |/               |
           |                          |                                                             |
           |                      <--> Incremental counter (64 steps)                               |
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

/********************************************************************
                    BEAT TRAKCER PRO PINMAP
                               _ _ /--\
                      \/_ _ _/(_(_(_o o)
                       (_(_(_(/      ^
**********************************O*********************************/
//#define DEVICE_ID       1


/*
#define SAW_PIN         A0 
#define SHAPE_PIN       A1
#define M1_PIN          12
#define M0_PIN          11
#define PIN_STRIP_1     39
#define PIN_STRIP_2     41
#define PIN_STRIP_3     43
#define PIN_ANALOG_ENABLED     45
*/
/********************************************************************
                             DEFINITIONS
                              .----.-.
                             /    ( o \
                            '|  __ ` ||
                             |||  ||| -'
**********************************O*********************************/
#define MODE_CALM   0
#define MODE_SCAN   1
#define MODE_MATH   2
#define MODE_LOST   3


//Calibration (non full range AOP outputs)
#define VOLUME_CALIB_MIN  150
#define VOLUME_CALIB_MAX  1023
#define SAW_CALIB_MIN  0
#define SAW_CALIB_MAX  945

//Speed of dynamic decrease
#define DYNAMIC_DECREMENT  20

//MEMORY
#define PALETTE_SIZE       9
#define INPUT_BUFFER_SIZE  256
#define INPUT_FILTER_SIZE  8
#define SYNC_FILTER_SIZE   4
#define PROMPT_NB_CAR_MAX   50
#define PROMPT_NB_FIELDS  3

//PROTOCOL
#define AD_MODE         0
#define AD_PROGRAM      1
#define AD_TIME         2
#define AD_COLOR        3
#define AD_BLACKLIGHT   4
#define AD_STROBE       5
#define AD_BLACKOUT     7
#define AD_MANUAL_INDEX  8
#define AD_CONTROL_MODE  9
#define AD_DICES_4       10
#define AD_DICES_16      11


//APPLICATION CONTROL
#define CONTROL_MODE_AUTO     0
#define CONTROL_MODE_MANUAL   1


/********************************************************************
                               STRUCTURES
                         __(.)< __(.)> __(.)=
                         \___)  \___)  \___) hjw
**********************************O*********************************/
//Contain global variables, buffers and array for the BTP driver
//One implementation only
typedef struct 
{
    //PINMAP
    int16_t pinSaw;
    int16_t pinShape;
    int16_t pinM0;
    int16_t pinM1;
    
    //SYNCHRO
    //Extract usefull data for rhythmic synchronisation
    uint8_t sync;             //saw signal input
    uint8_t lastSync;         //last saw signal input for tick detection
    uint8_t lastHalfSync;         //last saw signal input for tick detection
    uint8_t volume;           //volume shape
    uint8_t lastVolume;       //last volume shape for dynamic detection
    uint8_t onset;            //onset detection ->1 when dynamic
    uint8_t dynamic;          //max volume time decreased
    uint8_t dynamicStrength;  //volume derivation for onset intensity
    uint8_t dynamicHysterisis;  //volume minimal diference for onset detection
    
    //SYNC FILTER
    //Clean Sync Analog Input
    uint32_t syncFilterTimer;               //Timer
    uint8_t syncFilter[SYNC_FILTER_SIZE];   //Buffer
    uint8_t syncFilterPtr;                  //Ptr
    uint8_t syncFilterNb;                   //For Restart

    //VOLUME FILTER
    //Clean Volume Analog Input
    uint32_t volumeFilterTimer;               //Timer
    uint8_t volumeFilter[INPUT_FILTER_SIZE];  //Buffer
    uint8_t volumeFilterPtr;                  //Ptr

    //VOLUME RECORDS
    //Fifo chart
    uint32_t inputTimer;                //Timer
    uint8_t input[INPUT_BUFFER_SIZE];   //Buffer
    uint8_t inputPtr;                   //Ptr

    //VOLUME SCALE
    //Records bounds for scaled input when low dynamics
    uint8_t volumeRangeMin;    //Min value inside input buffer (input[INPUT_BUFFER_SIZE])
    uint8_t volumeRangeMax;    //Max value inside input buffer (input[INPUT_BUFFER_SIZE])
    uint8_t scaledVolume;      //expanded volume from 0 to 255 instead of volumeRangeMin to volumeRangeMax

    //SOLFEGE TIME
    //pulsation counters
    uint8_t t,t2,t4,t8,t16;

    //MODES
    //musical mood management
    uint8_t newMode;    //mode has just changed
    uint8_t mode;       //current mode
 
    
    //PALETTES
    //Colors management
    Palette palettes[PALETTE_SIZE];   //palettes collections
    uint8_t paletteIndex;             //palette theme
    Palette palette;                  //current palette (here are composed degraded transitions)
    uint32_t paletteTransitionTimer;  //timer for transitions
    float paletteTransitionRatio;     //increment for transition  
    uint8_t lastPaletteTransitionTime;  //one time each cycle
    
    //PROGRAMS
    //program change
    uint8_t lastProgramTransitionTime; //one time each cycle
    

    //DISORDERED
    uint8_t dices4[4];
    uint8_t dices16[16];
    uint8_t hexDices4[4];
    uint8_t hexDices16[16];
    
    uint8_t lastPathOnset;

    //PROGRAM CONTROL
    uint8_t controlMode;
    uint8_t masterControlMode;
    uint8_t masterManualIndex;
    uint8_t blackout;

    
    uint8_t currentProgram;

    //MASTER SLAVE
    uint8_t slave;
    uint32_t slaveTimer;  //Slave mode autodetection
  


}BTP;


typedef struct 
{
  uint8_t nb;
  uint8_t chain[PROMPT_NB_CAR_MAX];
}PromptField;


typedef struct 
{
  uint8_t txNbCar;
  uint8_t txBuffer[PROMPT_NB_CAR_MAX];
  uint8_t rxNbCar;
  uint8_t rxBuffer[PROMPT_NB_CAR_MAX];

  //Parser
  uint8_t valid;
  uint8_t cmd;
  uint8_t value;

  PromptField fields[PROMPT_NB_FIELDS];
  
}Prompt;


/********************************************************************
                              DECLARATIONS
                            ,_     ,     .'<_
                           _> `'-,'(__.-' __<
                           >_.--(.. )  =;`
                     jgs        `V-'`'\/``
**********************************O*********************************/
void BTP_Setup(int16_t pinSaw,int16_t pinShape,int16_t pinM0,int16_t pinM1);
void AD_Loop();
void BTP_InitPalette();

void BTP_Prompt_SendBlackout();
void BTP_Prompt_SendManualIndex();
void BTP_Prompt_SendControlMode();
void BTP_Prompt_SendDices();

Color AD_GetColor(uint8_t index);
uint8_t AD_GetRollColorID_4To2(uint8_t index);
Color AD_GetRollColor_4To2(uint8_t index);
Color AD_GetDynamicColor(uint8_t index);
uint8_t BTP_ReadInput(uint8_t x);
uint8_t AD_ReadRangedInput(uint8_t x);

void AD_ProgramRandomReload();

//PROMPT
void BTP_Prompt_FurnishByte(uint8_t car);

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
