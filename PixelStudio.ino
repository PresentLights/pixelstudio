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
           |           _____                          _     _      _       _     _                  |
           |          |  __ \                        | |   | |    (_)     | |   | |                 |
           |          | |__) | __ ___  ___  ___ _ __ | |_  | |     _  __ _| |__ | |_ ___            |
           |          |  ___/ '__/ _ \/ __|/ _ \ '_ \| __| | |    | |/ _` | '_ \| __/ __|           |
           |          | |   | | |  __/\__ \  __/ | | | |_  | |____| | (_| | | | | |_\__ \           |
           |          |_|   |_|  \___||___/\___|_| |_|\__| |______|_|\__, |_| |_|\__|___/           |
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
           |              \       |             PIXEL STUDIO             |      /                   |
           |               \      |                                      |     /                    |
           |               /      |______________________________________|     \                    |
           |              /__________)                                (_________\                   |
           |                                                                                        |
           |           Example of Pixel LED framework for using Beat Tracker Pro on Arduino DUE     |
           |           GitHub repositories -> https://github.com/PresentLights/pixelstudio          |
           |                                                                                        |
            ----------------------------------------------------------------------------------------               
           |                                                                                        |
           |                                  FRAMEWORK SYNOPTIC                                    |
           |                                  ------------------                                    |
           |                                _________________________________________________       |
           |                               |    Arduino DUE                 _______________   |     |
           |              ___________      |                        -----> /    Signal.c   \  |     |
           |             |           |     |________________       |       \_______|_______/  |     |
           |             |  Beat     |     |      BTP.c     |    rhythme    _______v_______   |     |
           |   Audio --> |   Tracker | --> |  Beat Tracker  | -> volume -> /   Program.c   \  |     |
           |             |      Pro  |     |   Pro driver   |    modes     \_______|_______/  |     |
           |             |___________|     |----------------     colors     _______v_______   |     |
           |                               |                               /   Mapping.c   \  |     |
           |                               |                               \_______|_______/  |     |
           |                               |_______________________________________|__________|     |
           |                                                                       v                |
           |                                                                   Led Strip            |
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
#include "Arduino.h"
#include "ArduinoLog.h"
#include <FastLED.h>
#include "BTP.h"
#include "PixelStudio.h"
#include "Program.h"
#include "Mapping.h"

/********************************************************************
                             DEFINITIONS
                              .----.-.
                             /    ( o \
                            '|  __ ` ||
                             |||  ||| -'
**********************************O*********************************/
//Debuging tools
#define LOG_LEVEL LOG_LEVEL_VERBOSE

//External FastLED library
#define FASTLED_INTERNAL  //make the compilation silent

/********************************************************************
                               GLOBAL VAR
                         __(.)< __(.)> __(.)=
                         \___)  \___)  \___) hjw
**********************************O*********************************/
//for translation buffer form Color Type to CRGB Type
CRGB leds_BAR_A[STRIP_BAR_NB_LEDS_MAX];
CRGB leds_BAR_B[STRIP_BAR_NB_LEDS_MAX];
CRGB leds_BAR_C[STRIP_BAR_NB_LEDS_MAX];

//Global shared objets
PixelStudio ps;
extern BTP btp;
extern ProgramManager pm;
extern MappingManager mm;
/**********************************************************************************************************************
***********************************************************************************************************************
**  ________  *********************************************************************************************************
** |  SETUP | *********************************************************************************************************
   _________    *  _|_     _|_     _|_     _|_     _|_     _|_     _|_     _|_     _|_     _|_     _|_     _|_     _|_   
  /  .....  |   *   |       |       |       |       |       |       |       |       |       |       |       |       |     
  |  INIT   |   *      _|_     _|_     _|_     _|_     _|_     _|_     _|_     _|_     _|_     _|_     _|_     _|_      
  |  .....  |   *       |       |       |       |       |       |       |       |       |       |       |       |           
  |  .....  |   *  _|_     _|_     _|_     _|_     _|_     _|_     _|_     _|_     _|_     _|_     _|_     _|_     _|_   
  |_________|   *   |       |       |       |       |       |       |       |       |       |       |       |       |     
***********************************************************O**********************************************************/
void InitPreset()
{
  ps.programPreset = 0;
  ps.programPreset += digitalRead(PIN_ROTARY_ENCODER_PROGRAM_PRESET_1);
  ps.programPreset += digitalRead(PIN_ROTARY_ENCODER_PROGRAM_PRESET_2) << 1;
  ps.programPreset += digitalRead(PIN_ROTARY_ENCODER_PROGRAM_PRESET_4) << 2;
  ps.programPreset += digitalRead(PIN_ROTARY_ENCODER_PROGRAM_PRESET_8) << 3;
  ps.programPreset ^= 0xF;

  ps.mappingPreset = 0;
  ps.mappingPreset += digitalRead(PIN_ROTARY_ENCODER_MAPPING_PRESET_1);
  ps.mappingPreset += digitalRead(PIN_ROTARY_ENCODER_MAPPING_PRESET_2) << 1;
  ps.mappingPreset += digitalRead(PIN_ROTARY_ENCODER_MAPPING_PRESET_4) << 2;
  ps.mappingPreset += digitalRead(PIN_ROTARY_ENCODER_MAPPING_PRESET_8) << 3;
  ps.mappingPreset ^= 0xF;

  ps.strip1Active=false;
  ps.strip2Active=false;
  ps.strip3Active=false;
  
  switch(ps.programPreset)
  {
    case 0:
      ps.strip1Active=true;
      u0.programPreset=PROGRAM_PRESET_VERTICAL;
      break;    
      
    case 1:
      ps.strip1Active=true;
      u0.programPreset=PROGRAM_PRESET_HORIZONTAL;
      break;  
        
    case 2:
      ps.strip1Active=true;
      ps.strip2Active=true;
      u0.programPreset=PROGRAM_PRESET_VERTICAL;
      u1.programPreset=PROGRAM_PRESET_HORIZONTAL;
      break;    
  }
}

void setup()
{
  //Beat Tracker Pro Interface
  //Logic Mode Input (CALM=0 / SYNC=1 / MATH=2 / LOST=3)
  pinMode(M0_PIN, INPUT_PULLUP);
  pinMode(M1_PIN, INPUT_PULLUP);
  pinMode(PIN_ANALOG_ENABLED, OUTPUT); //Analog Switch for master / slave operation

  //Rotary Encoders Presets
  pinMode(PIN_ROTARY_ENCODER_PROGRAM_PRESET_1, INPUT_PULLUP);
  pinMode(PIN_ROTARY_ENCODER_PROGRAM_PRESET_2, INPUT_PULLUP);
  pinMode(PIN_ROTARY_ENCODER_PROGRAM_PRESET_4, INPUT_PULLUP);
  pinMode(PIN_ROTARY_ENCODER_PROGRAM_PRESET_8, INPUT_PULLUP);
  pinMode(PIN_ROTARY_ENCODER_MAPPING_PRESET_1, INPUT_PULLUP);
  pinMode(PIN_ROTARY_ENCODER_MAPPING_PRESET_2, INPUT_PULLUP);
  pinMode(PIN_ROTARY_ENCODER_MAPPING_PRESET_4, INPUT_PULLUP);
  pinMode(PIN_ROTARY_ENCODER_MAPPING_PRESET_8, INPUT_PULLUP);

  //Push Buttons & Leds
  pinMode(PIN_BP1, INPUT_PULLUP);
  pinMode(PIN_BP2, INPUT_PULLUP);
  pinMode(PIN_BP3, INPUT_PULLUP);
  pinMode(PIN_BP4, INPUT_PULLUP);

  pinMode(PIN_LED1, OUTPUT);
  pinMode(PIN_LED2, OUTPUT);
  pinMode(PIN_LED3, OUTPUT);
  pinMode(PIN_LED4, OUTPUT);

  InitPreset(); //Defines initial configuration (program & universe)

  //FastLED library initialization
  if (ps.strip1Active)
    FastLED.addLeds<NEOPIXEL, PIN_STRIP_1>(leds_BAR_A, STRIP_BAR_NB_LEDS_MAX);
  if (ps.strip2Active)
    FastLED.addLeds<NEOPIXEL, PIN_STRIP_2>(leds_BAR_B, STRIP_BAR_NB_LEDS_MAX);
  if (ps.strip3Active)
    FastLED.addLeds<NEOPIXEL, PIN_STRIP_3>(leds_BAR_C, STRIP_BAR_NB_LEDS_MAX);


  //Beat Tracker Pro Initialization
  BTP_Setup(SAW_PIN,SHAPE_PIN,M0_PIN,M1_PIN);

  //Mapping initialization
  Mapping_Setup();



  //Serial Initialization (not used in the example / ready for debug)
  while (!Serial);
  Serial.begin(115200);
  Serial1.begin(115200);
  delay(100);
  Log.begin   (LOG_LEVEL, &Serial);
  Log.notice("Program started\n");
  Debug("Program Preset =" , ps.programPreset);
  Debug("Mapping Preset =" , ps.mappingPreset);
}

/********************************************************************
                            C++ TOOLS
                                    ____________________________
   _____                          ,\\    ___________________    \
  |     `------------------------'  ||  (___________________)   `|
  |_____.------------------------._ ||  ____________________     |
          jgs                     `//__(____________________)___/

**********************************O*********************************/
//Traduce Color Type to CRGB Type (FastLED librairy)
CRGB ColorToCRGB(Color color)
{
  CRGB result;
  result.red = color.r;
  result.green = color.g;
  result.blue = color.b;
  return result;
}

/********************************************************************
//              WRAPPER C -> C ++
//       ¸.·´¯`·.´¯`·.¸¸.·´¯`·.¸><(((º> 
**********************************O*********************************/
//All my code is written in C for better portability
//This wrapper allows to call C++ Functions from C code
extern "C"
{
  //Serial Debug 
  void Serial_Write(uint8_t car){Serial.write(car);}
  void Serial1_Write(uint8_t car){Serial1.write(car);}
  
  void Debug(const char *text, int value){Log.notice("%s%d\n",text,value);}
  void Ici() {Log.notice("ICI\n");}
  void La()  {Log.notice("LA\n");}

  //Traduction & Redirection of final buffer
  //Color -> CRGB
  void FastLED_StripOut(LedStrip *strip)
  {
    CRGB *leds;
    switch (strip->address)
    {
      case 0: leds = leds_BAR_A;break;
      case 1: leds = leds_BAR_B;break;
      case 2: leds = leds_BAR_C;break;
    }
    int i;
    for(i=0;i<strip->nb;i++)
      leds[i] = ColorToCRGB(strip->buffer[i]);
  }

  //Tells the library to output an LED data signal
  //Writen in assembly and not DMA, it stops the program
  //So the more leds there are, the slower the program
  //For giant compositions, it is preferable to use several 
  //Arduino DUEs in master slave operation
  void FastLED_Show(){FastLED.show();}
}

/**********************************************************************************************************************
***********************************************************************************************************************
**  _____________________  ********************************************************************************************
** |  APPLICATION CODE   | ********************************************************************************************
          _.-"\               *   ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ 
      _.-"     \              * _|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|
   ,-"          \             *|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|_
  ( \            \            * _|___|___|___|                           |___|___|___|___|___|___|___|___|___|___|___|     
   \ \            \           *|___|___|___|_| Version : 1.0             |_|___|___|___|___|___|___|___|___|___|___|_     
    \ \            \          * _|___|___|___| Release : October 2021    |___|___|___|___|___|___|___|___|___|___|___|     
     \ \         _.-;         *|___|___|___|_| Author  : Basile HUARD    |_|___|___|___|___|___|___|___|___|___|___|_ 
      \ \    _.-"   :         * _|___|___|___|_ ___ ___ ___ ___ ___ ___ _|___|___|___|___|___|___|___|___|___|___|___| 
       \ \,-"    _.-"         *|___|___|___|___|___|___|___|___|___|___|___|__|___|___|___|___|___|___|___|___|___|_ 
        \(   _.-"  -shimrod   * _|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___| 
         `--"                 *|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|
***********************************************************O**********************************************************/
//Local Variables for user interface operation
char lastBp1,lastBp2,lastBp3,lastBp4;
uint32_t rebounceTimer;
uint32_t blinkTimer;
char blinkState;

void UI_ClearBPLeds()
{
  digitalWrite(PIN_LED1,0);
  digitalWrite(PIN_LED2,0);
  digitalWrite(PIN_LED3,0);
  digitalWrite(PIN_LED4,0);
}


void UI_DisplayBinary(uint8_t value)
{
  digitalWrite(PIN_LED1,value & 1);
  digitalWrite(PIN_LED2,(value & 2)>>1);
  digitalWrite(PIN_LED3,(value & 4)>>2);
  digitalWrite(PIN_LED4,(value & 8)>>3);
}


void UI_Update()
{
  uint16_t blinkDelay;
  
      switch(btp.controlMode)
      {
        case CONTROL_MODE_AUTO: 
          if (btp.slave)
          {
            switch (btp.masterControlMode)
            {
              case CONTROL_MODE_AUTO:
                UI_ClearBPLeds();
                digitalWrite(PIN_LED1,1); 
                break;
                
              case CONTROL_MODE_MANUAL:
                if (millis() - blinkTimer > 50)
                {
                  blinkTimer = millis();
                  if (blinkState)
                  {
                    blinkState=false;
                    UI_ClearBPLeds();
                  }
                  else
                  {
                    blinkState=true;
                    UI_DisplayBinary(pm.prgIndexMANUAL);
                  }
                }
                break;
            }
            
          }
          else
          {
            UI_ClearBPLeds();
            digitalWrite(PIN_LED1,1); 
          }
          
          break;
          
        case CONTROL_MODE_MANUAL: 
        
          blinkDelay = 50;
          if (btp.slave)
            blinkDelay = 100; //Indique que l'on ne suit pas le master
            
          if (millis() - blinkTimer > blinkDelay)
          {
            blinkTimer = millis();
            if (blinkState)
            {
              blinkState=false;
              UI_ClearBPLeds();
            }
            else
            {
              blinkState=true;
              UI_DisplayBinary(pm.prgIndexMANUAL);
            }
          }
          
          break;
      }
 
  
  if (btp.blackout)
    digitalWrite(PIN_LED4,1);
  
}


void UI_ChangeManualProgram(uint8_t up)
{
  btp.controlMode = CONTROL_MODE_MANUAL;
  Program_Increment(PROGRAM_MODE_MANUAL, up);
  BTP_ProgramRandomReload();
  Layers_Clear(); //Clear all persist color
}

void UI_Click_1()
{
  btp.controlMode = CONTROL_MODE_AUTO;
  pm.prgIndexMANUAL = btp.masterManualIndex; //on se replace sur le programme manuel du maitre
  BTP_Prompt_SendControlMode();
}

void UI_Click_2()
{
  UI_ChangeManualProgram(true);
  BTP_Prompt_SendManualIndex();
  BTP_Prompt_SendControlMode();
}


void UI_Click_3()
{
  UI_ChangeManualProgram(false);
  BTP_Prompt_SendManualIndex();
  BTP_Prompt_SendControlMode();
}


void UI_Click_4()
{
  if (btp.blackout == 1)
    btp.blackout = 0;
  else
    btp.blackout = 1;

  BTP_Prompt_SendBlackout();
}





void UI_Process()
{
  
  if (millis() - rebounceTimer > 50)
  {
    //***************** BP 1 ***********************
    char bp1 = digitalRead(PIN_BP1);
    if (bp1 != lastBp1 && bp1==0)
    {
      rebounceTimer = millis();
      UI_Click_1();
    }
    lastBp1 = bp1;

    //***************** BP 2 ***********************
    char bp2 = digitalRead(PIN_BP2);
    if (bp2 != lastBp2 && bp2==0)
    {
      rebounceTimer = millis();
      UI_Click_2();
    }
    lastBp2 = bp2;

    //*****************  BP 3 ***********************
    char bp3 = digitalRead(PIN_BP3);
    if (bp3 != lastBp3 && bp3==0)
    {
      rebounceTimer = millis();
      UI_Click_3();
    }
    lastBp3 = bp3;

    //*****************  BP 4 ***********************
    char bp4 = digitalRead(PIN_BP4);
    if (bp4 != lastBp4 && bp4==0)
    {
      rebounceTimer = millis();
      UI_Click_4();
    }
    lastBp4 = bp4;
  }
 


}




/**********************************************************************************************************************
***********************************************************************************************************************
**  ________  *********************************************************************************************************
** |  LOOP  | *********************************************************************************************************
                 *   _( )__ _( )__ _( )__ _( )__ _( )__ _( )__ _( )__ _( )__ _( )__ _( )__ _( )__ _( )__ _( )__ _( )__
      ,~~.       * _|     _|     _|     _|     _|     _|     _|     _|     _|     _|     _|     _|     _|     _|     _| 
     (  9 )-_,   *(_   _ (_   _ (_   _ (_   _ (_   _ (_   _ (_   _ (_   _ (_   _ (_   _ (_   _ (_   _ (_   _ (_   _ (_ 
(\___ )=='-'     * |__( )_|__( )_|__( )_|__( )_|__( )_|__( )_|__( )_|__( )_|__( )_|__( )_|__( )_|__( )_|__( )_|__( )_|
 \ .   ) )       * |_     |_     |_     |_     |_     |_     |_     |_     |_     |_     |_     |_     |_     |_     |_  
  \ `-' /        *  _) _   _) _   _) _   _) _   _) _   _) _   _) _   _) _   _) _   _) _   _) _   _) _   _) _   _) _   _) 
   `~j-' hjw     * |__( )_|__( )_|__( )_|__( )_|__( )_|__( )_|__( )_|__( )_|__( )_|__( )_|__( )_|__( )_|__( )_|__( )_|
***********************************************************O**********************************************************/

void loop()
{
  BTP_Loop();      //Beat Tracker Pro driver runtime
  Program_Loop();  //User lighting programs

  //User Interface
  UI_Process();
  UI_Update();

  //Automatic analog switch for master/slave mode
  digitalWrite(PIN_ANALOG_ENABLED,btp.slave^1);
  
  while (Serial1.available())
  {
    uint8_t car = Serial1.read();
    BTP_Prompt_FurnishByte(car);
    Serial.write(car); //echo debug
  }
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
