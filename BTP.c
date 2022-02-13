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
           |              \       |                BTP.c                 |      /                   |
           |               \      |                                      |     /                    |
           |               /      |______________________________________|     \                    |
           |              /__________)                                (_________\                   |
           |                                                                                        |
           |           This file is the Beat Tracker Pro driver                                     |
           |           It permit you to get the rhythmic synchro, sound reactive shape and modes    |
           |           It also generate palettes of colors                                          |
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
#include <string.h>
#include "BTP.h"
#include "Program.h"
/********************************************************************
                               GLOBAL VAR
                         __(.)< __(.)> __(.)=
                         \___)  \___)  \___) hjw
**********************************O*********************************/
//Global shared objets
BTP btp;
extern ProgramManager pm;
Prompt prompt;

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
//Palette Initializer (cf. Tools.c)
void InitPalette4(Palette *p, uint32_t c1,uint32_t c2,uint32_t c3,uint32_t c4)
{
  p->colors[0] = Color_FromInt(c1);
  p->colors[1] = Color_FromInt(c2);
  p->colors[2] = Color_FromInt(c3);
  p->colors[3] = Color_FromInt(c4);
}

//Load current palette from current index
void BTP_InitPalette()
{
  int i;
  for(i=0;i<PALETTE_NB_COLORS;i++)
    btp.palette.colors[i] = btp.palettes[btp.paletteIndex].colors[i];
}

//BTP Driver Initializer
void BTP_Setup(int16_t pinSaw,int16_t pinShape,int16_t pinM0,int16_t pinM1) 
{
  btp.pinSaw = pinSaw;
  btp.pinShape = pinShape;
  btp.pinM0 = pinM0;
  btp.pinM1 = pinM1;
  
   //Palettes
  InitPalette4(&btp.palettes[0], 0x49006E,0x1D6C00,0xFF6600,0x6F7D00);//Candy
  InitPalette4(&btp.palettes[1], 0xB280FF,0x2ED388,0x00A01F,0x0D0074);//Azure
  InitPalette4(&btp.palettes[2], 0xC84D0B,0xFFD220,0xE46927,0xCC3C00);//Gold
  InitPalette4(&btp.palettes[3], 0xAE3D00,0xC91D00,0xD80000,0x408000);//Mexico
  InitPalette4(&btp.palettes[4], 0x65E0FF,0xCC00FF,0x4040FF,0x8FFF40);//Well Being
  InitPalette4(&btp.palettes[5], 0x00FF66,0x00FF00,0xCCFF00,0x00FF66);//Jungle
  InitPalette4(&btp.palettes[6], 0xFF2079,0x2020FF,0xFF2020,0xD2FF20);//Pastel
  InitPalette4(&btp.palettes[7], 0xFF1812,0xD15011,0xBC3D00,0xAB0400);//Love
  InitPalette4(&btp.palettes[8], 0xFFD840,0x40FFD8,0xFF6600,0xC6A0FF);//Sky
  btp.paletteIndex = 0;
  BTP_InitPalette();

  
  btp.controlMode = CONTROL_MODE_AUTO;
  btp.blackout = false;

  SetDisorderChain(&btp.dices4, 4);
  SetDisorderChain(&btp.dices16, 16);
}

/**********************************************************************************************************************
***********************************************************************************************************************
**  _______________  **************************************************************************************************
** |  DEBUT CODE   | **************************************************************************************************
          _.-"\               *
      _.-"     \              *
   ,-"          \             *
  ( \            \            *
   \ \    CODE    \           *
    \ \            \          *
     \ \         _.-;         *
      \ \    _.-"   :         *
       \ \,-"    _.-"         *
        \(   _.-"  -shimrod   *
         `--"                 *
**********************************************************************************************************************/



/********************************************************************
                         MASTER / SLAVE PROMPT
                               _________
                              / ======= \
                             / __________\
                            | ___________ |
                            | | -       | |
                            | |         | |
                            | |_________| |________________________
                            \=____________/   brian macdonald      )
                            / """"""""""" \                       /
                           / ::::::::::::: \                  =D-'
                          (_________________)
**********************************O*********************************/

/********************************************************************
                        TRANSMISSION
                        __     __------
                     __/o `\ ,~   _~~  
                     ~ -.   ,'   _~-----
                         `\     ~~~--_'__
                           `~-==-~~~~~---'
********************************************************************/
void BTP_DebugChain(uint8_t *chain, uint8_t len)
{
  int i;
  for(i=0;i<len;i++)
  {
    Serial_Write(chain[i]); //debug
  }
  
    Serial_Write(13); //debug
    Serial_Write(10); //debug
}

void BTP_Prompt_Send()
{
  int i;
  for(i=0;i<prompt.txNbCar;i++)
  {
    Serial_Write(prompt.txBuffer[i]); //debug
    Serial1_Write(prompt.txBuffer[i]);
  }
}


void BTP_Prompt_SendInt(uint8_t cmd, uint8_t value)
{
  char valStr[4];
  itoa(value,valStr,10);
  int i=0;
  int ptr=0;

  //TX ID
  prompt.txBuffer[ptr++] =  '0';
  prompt.txBuffer[ptr++] =  ',';

  //CMD ADDRESS
  prompt.txBuffer[ptr++] =  cmd;
  prompt.txBuffer[ptr++] =  ',';

  //VALUE
  while(valStr[i])
    prompt.txBuffer[ptr++] = valStr[i++];

  
  prompt.txBuffer[ptr++] =  13;
  prompt.txBuffer[ptr++] =  10;
  prompt.txNbCar = ptr;
  BTP_Prompt_Send();
}


void BTP_Prompt_SendChain(uint8_t cmd, uint8_t *chain, uint8_t len)
{
  int i=0;
  int ptr=0;

  //TX ID
  prompt.txBuffer[ptr++] =  '0';
  prompt.txBuffer[ptr++] =  ',';

  //CMD ADDRESS
  prompt.txBuffer[ptr++] =  cmd;
  prompt.txBuffer[ptr++] =  ',';

  //VALUE
  int j;
  for (j=0;j<len;j++)
    prompt.txBuffer[ptr++] = chain[j];

  
  prompt.txBuffer[ptr++] =  13;
  prompt.txBuffer[ptr++] =  10;
  prompt.txNbCar = ptr;
  BTP_Prompt_Send();
}



void BTP_Prompt_SendMode()
{
  BTP_Prompt_SendInt(ByteToAsciiHex(AD_MODE), btp.mode);
}


void BTP_Prompt_SendProgram()
{
  BTP_Prompt_SendInt(ByteToAsciiHex(AD_PROGRAM), btp.currentProgram);
}

void BTP_Prompt_SendTime() 
{
  BTP_Prompt_SendInt(ByteToAsciiHex(AD_TIME), btp.t);
}

void BTP_Prompt_SendColor()
{
  BTP_Prompt_SendInt(ByteToAsciiHex(AD_COLOR), btp.paletteIndex);
}

void BTP_Prompt_SendBlackout()
{
  BTP_Prompt_SendInt(ByteToAsciiHex(AD_BLACKOUT), btp.blackout);
}

void BTP_Prompt_SendManualIndex()
{
  BTP_Prompt_SendInt(ByteToAsciiHex(AD_MANUAL_INDEX), pm.prgIndexMANUAL);
}

void BTP_Prompt_SendControlMode()
{
  BTP_Prompt_SendInt(ByteToAsciiHex(AD_CONTROL_MODE), btp.controlMode);
}



void BTP_Prompt_SendDices()
{
  BTP_Prompt_SendChain(ByteToAsciiHex(AD_DICES_4),  &btp.hexDices4, 4);
  BTP_Prompt_SendChain(ByteToAsciiHex(AD_DICES_16),  &btp.hexDices16, 16);
}
/********************************************************************
                           RECEPTION
                                       |  |
                    ______|            |  |
                   |    # |,\|/--,_____|__|O___
                   |    # |  ` o  ,____________)
                   |    # |( c o ,_____o000____)
                   |____#_|'.,-'`
                          | /|\
********************************************************************/

void BTP_Prompt_Income()
{
  int i,j, nb;
  for (j=0;j<PROMPT_NB_FIELDS;j++)
  {
    prompt.fields[j].nb = 0;
    for (i=0;i<PROMPT_NB_CAR_MAX;i++)
      prompt.fields[j].chain[i]= 0;
  }

  uint8_t blocIndex = 0;
  char* bloc = strtok(prompt.rxBuffer, ",");
  while (bloc != 0)
  {
    nb = strlen(bloc);
    prompt.fields[blocIndex].nb = nb;
    for (i=0;i<nb;i++)
      prompt.fields[blocIndex].chain[i]=bloc[i];

    blocIndex++;
    bloc = strtok(0, ","); //Next
  }


  if (blocIndex == 3) //Valid
  {
    uint16_t id = atoi(prompt.fields[0].chain);// blocValues[0];
    uint16_t cmd = AsciiHexToByte(prompt.fields[1].chain[0]);//AsciiHexToByte(CmdCar);
    uint16_t value = atoi(prompt.fields[2].chain);//blocValues[2];

    switch (cmd)
    {
      case AD_MODE:
        btp.mode = value; 
        break;
        
      case AD_PROGRAM: 
        if (btp.controlMode == CONTROL_MODE_AUTO)
          btp.currentProgram = value; 
        break;
      
      case AD_TIME: 
        btp.t = value; 
        break;
      
      case AD_COLOR: 
        btp.paletteIndex = value; 
        break;
      
      case AD_DICES_4:  
        strcpy(btp.hexDices4,prompt.fields[2].chain);
        AsciiHexChainToByteChain(&btp.hexDices4,&btp.dices4,4);
        break;
        
      case AD_DICES_16:  
        strcpy(btp.hexDices16,prompt.fields[2].chain);
        AsciiHexChainToByteChain(&btp.hexDices16,&btp.dices16,16);
        break;

      case AD_BLACKOUT:
        if (btp.slave)
          btp.blackout = value;
        break;

      case AD_MANUAL_INDEX:
        if (btp.slave && btp.controlMode == CONTROL_MODE_AUTO)
          pm.prgIndexMANUAL = value;
        btp.masterManualIndex = value;
        break;

      case AD_CONTROL_MODE:
        btp.masterControlMode = value;
        break;

    }
  }
  

  prompt.rxNbCar = 0; //Clear
}

void BTP_Prompt_FurnishByte(uint8_t car)
{
  //Slave Mode Autodetection
  btp.slaveTimer = millis(); //RAZ Slave Watchdog
  btp.slave = true;
    
  if (car == 10) return; //LF mask
  if (prompt.rxNbCar<PROMPT_NB_CAR_MAX)
    prompt.rxBuffer[prompt.rxNbCar++] = car;
  if (car == 13) //CR
  {
    prompt.rxBuffer[prompt.rxNbCar] = 0; //EOF
    BTP_Prompt_Income();
  }
 // Serial_Write(car);
}






/********************************************************************
                         VOLUME & COLORS TOOLS
                                    ____________________________
   _____                          ,\\    ___________________    \
  |     `------------------------'  ||  (___________________)   `|
  |_____.------------------------._ ||  ____________________     |
          jgs                     `//__(____________________)___/

**********************************O*********************************/


//Read volume imput records from present to past
uint8_t BTP_ReadInput(uint8_t x)
{
  uint16_t readPtr = btp.inputPtr - x;
  if (readPtr<0)
    readPtr+=INPUT_BUFFER_SIZE;
  return btp.input[(uint8_t)readPtr];
}

//Scale volume from records range (for low dynamics)
uint8_t BTP_ScaleInputRange(uint8_t vol)
{
  return MapBoundInt16(vol,btp.volumeRangeMin,btp.volumeRangeMax,0,255);
}

//Read range scaled volume imput records from present to past
uint8_t AD_ReadRangedInput(uint8_t x)
{
  return BTP_ScaleInputRange(BTP_ReadInput(x));
}

//Get color from palette including cross color
Color AD_GetColor(uint8_t index)
{
  uint8_t disorderIndex = btp.dices4[index];
  return btp.palette.colors[disorderIndex];
}

uint8_t AD_GetRollColorID_4To2(uint8_t index)
{
  uint8_t colorID = 0;
  switch(index)
  {
    case 0: colorID = (btp.t4 >> 1) << 1; break;
    case 1: colorID = ((((btp.t4+1)%4) >> 1) << 1)+ 1; break;
  }
  return colorID;
}

Color AD_GetRollColor_4To2(uint8_t index)
{
  uint8_t colorID = AD_GetRollColorID_4To2(index);
  return AD_GetColor(colorID);
}

//A Eviter comme effet visuel
//Get color from palette including cross color and sound dynamic brightness
Color AD_GetDynamicColor(uint8_t index)
{
  Color color = AD_GetColor(index);
  uint8_t dyn = BTP_ScaleInputRange(btp.dynamic);
  float brightness = (float)dyn/255;
  color = Color_Brightness(color, brightness);
  return color;
}

/******************************************************************
                        PALETTE & PROGRAM TRANSITIONS
                                _____          /|
                             .-'@ & #`'-.     //
                            / %        8 \   //
                           | m   () _     | //
                            \  0   ( '-._/ //
                      jgs    '-.____'.     y 
**********************************O*********************************/


//Execute colors transitions
void AD_ProcessPaletteTransition()
{
  if (millis() - btp.paletteTransitionTimer > 50 &&  btp.paletteTransitionTimer)
  {
    btp.paletteTransitionRatio += 0.05;
    btp.paletteTransitionTimer = millis();

    if (btp.paletteTransitionRatio >= 1)
    {
      
      btp.paletteTransitionTimer = 0; //Off
      btp.paletteTransitionRatio = 0;
      btp.paletteIndex++;
      btp.paletteIndex %= PALETTE_SIZE;
      
    }
    else
    {
      int i;
      Palette current = btp.palettes[btp.paletteIndex];
      uint8_t nextIndex = (btp.paletteIndex+1) % PALETTE_SIZE;
      Palette next = btp.palettes[nextIndex];
      for(i=0;i<PALETTE_NB_COLORS;i++)
        btp.palette.colors[i] = Color_Degrade(current.colors[i], next.colors[i], btp.paletteTransitionRatio);
    }
  }
}

void AD_ProgramRandomReload()
{
  if (btp.mode == MODE_CALM) return; //Evite les sursauts de couleurs lors des changements auto de mappings
  SetDisorderChain(&btp.dices4, 4); //Automaticaly change order of led bar mapping
  SetDisorderChain(&btp.dices16, 16); //Automaticaly change random path for "pattern type" program

  ByteChainToAsciiHexChain(&btp.dices4, &btp.hexDices4,4);
  ByteChainToAsciiHexChain(&btp.dices16, &btp.hexDices16,16);

  BTP_Prompt_SendDices();
}

void AD_SyncProgram()
{
  switch(btp.controlMode)
  {
    case CONTROL_MODE_AUTO: 
      pm.prgMode = btp.mode;
      break;
       
    case CONTROL_MODE_MANUAL:
      pm.prgMode = PROGRAM_MODE_MANUAL;
      break;
  }
  btp.currentProgram = Program_GetProgramNumber();
  if (!btp.slave)
    BTP_Prompt_SendProgram();
}


void AD_OnModeChange()
{
  if (btp.controlMode == CONTROL_MODE_AUTO && btp.mode == MODE_MATH)
  {
    AD_OnProgramChange();
    btp.t=0;
  }
  
  AD_SyncProgram();
  BTP_Prompt_SendMode();


}

void AD_OnProgramChange()
{
  if (btp.slave) return;
  Program_IncrementCurrent(); //Auto Change Program
  AD_ProgramRandomReload();
  Layers_Clear(); //Clear all persist color
}

/********************************************************************
                                TICK
                               ______  
                               '`-. / 
                                  //___ 
                                 / _.-' 
                                /.'  
**********************************O*********************************/

//Comes here at each beat pulsation
void AD_Tick()
{
  //pulsations time 0 to 31
  btp.t++;
  btp.t %= 32;

  //modulo reduced pulsations
  btp.t2 = btp.t % 2;
  btp.t4 = btp.t % 4;
  btp.t8 = btp.t % 8;
  btp.t16 = btp.t % 16;

  //Palette transition every 16 pulsations
  if (btp.t16 == 0 && btp.t16 != btp.lastPaletteTransitionTime)
  {
      btp.paletteTransitionTimer = millis();
      if (!btp.slave)
        BTP_Prompt_SendColor();
  }
  btp.lastPaletteTransitionTime = btp.t16;

  //Program change every 16 pulsations
  uint8_t programSynchro = btp.t16;
  if (programSynchro == 0 && programSynchro != btp.lastProgramTransitionTime && btp.controlMode == CONTROL_MODE_AUTO)
    AD_OnProgramChange();
  btp.lastProgramTransitionTime = programSynchro;



  if(!btp.slave || btp.controlMode == CONTROL_MODE_MANUAL)
    AD_SyncProgram(); //To syncronise manual change (prevent glitchs)



}


void AD_HalfTick()
{
  if (!btp.slave)
    BTP_Prompt_SendTime();
}

/********************************************************************
                              SYNCHRONISE
                            ______________
                          _/______________\_
                         /  ______________  \
                        |  |  _     _  _  |  |
                        |  | |_| o | | _| |  |\
                        |  |  _| o |_| _| |  | |
                        |  |______________|  |/
                        |                __  |
                        |  _   _   _    |  | |\
                        | |_| |_| |_|   |__| |/
                        \____________________/
                           \______________/
**********************************O*********************************/

//Beat Tracker analog inputs syncronisation
//Read SAW_PIN gives rhythme (usefull in MATH MODE)
//Read SHAPE_PIN gives volume shape for sound reactive effects (usefull in SCAN MODE)
//Filter inputs in case of main supply parasits
//Analyses sound dynamics and beats increments
void AD_Synchronise()
{
  int i;


  //FILTERED SYNCHRO
  uint8_t sync = analogRead(btp.pinSaw)>>2;
  if (micros() - btp.syncFilterTimer > 5)
  {
    btp.syncFilterTimer = micros();
    btp.syncFilter[btp.syncFilterPtr++]=sync;
    btp.syncFilterPtr%=SYNC_FILTER_SIZE;
  }
  
  uint16_t sum=0;
  if (sync<btp.lastSync-128) //front descendant -> raz filter
  {
    for (i=0;i<SYNC_FILTER_SIZE;i++)
      btp.syncFilter[i]=0;
     btp.sync = 0;
  }
  else
  {
    for (i=0;i<SYNC_FILTER_SIZE;i++)
      sum+=btp.syncFilter[i];
    btp.sync = sum >> 2;
  }
  
 //   Debug("SYNC=", btp.sync);



  analogWrite(DAC0,btp.sync);
  
  //Detection front descendant -> Tick
  if (btp.sync<btp.lastSync-128) 
      AD_Tick();
  btp.lastSync = btp.sync;

  if (btp.sync > 128 && btp.lastHalfSync <= 128) 
      AD_HalfTick();
  btp.lastHalfSync = btp.sync;





  
  //FILTERED VOLUME
  uint8_t vol = (uint8_t)MapBoundInt16(analogRead(btp.pinShape),VOLUME_CALIB_MIN,VOLUME_CALIB_MAX,0,255);
  if (micros() - btp.volumeFilterTimer > 500)
  {
    btp.volumeFilterTimer = micros();
    btp.volumeFilter[btp.volumeFilterPtr++]=vol;
    btp.volumeFilterPtr%=INPUT_FILTER_SIZE;
  }
  sum=0;
  for (i=0;i<INPUT_FILTER_SIZE;i++)
    sum+=btp.volumeFilter[i];
  btp.volume = sum>>3;
  
  //VOLUME DYNAMIC
  if (millis() - btp.inputTimer > 2)
  {
    btp.inputTimer = millis();
    btp.input[btp.inputPtr++]=btp.dynamic;
    //ONSET - DYNAMIC
    if (btp.volume > btp.lastVolume + btp.dynamicHysterisis && btp.volume > btp.dynamic)
    {
      btp.onset=1;
      btp.dynamic = btp.volume;
      btp.dynamicStrength = (uint8_t)BoundInt16((btp.volume - btp.lastVolume)<<1,0,255);
    }
    else
    {
      btp.onset=0;
      if (btp.dynamic>=DYNAMIC_DECREMENT)
        btp.dynamic-=DYNAMIC_DECREMENT;
      else
        btp.dynamic =0;
    }
    btp.lastVolume = btp.volume;
  }

  //VOLUME RANGE
  btp.volumeRangeMax=50;
  btp.volumeRangeMin=255;
  for (i=0;i<INPUT_BUFFER_SIZE;i++)
  {
    uint8_t vol = btp.input[i];
    if (vol>btp.volumeRangeMax)
      btp.volumeRangeMax=vol;
    if (vol<btp.volumeRangeMin)
      btp.volumeRangeMin=vol;
  }
}


//Read logics mode digital inputs
void AD_ReadMode()
{
  if (btp.slave) return;
  
  btp.newMode = 0;
  btp.newMode += digitalRead(btp.pinM0);
  btp.newMode += digitalRead(btp.pinM1)<<1;

  if (btp.newMode != btp.mode)
  {
    btp.mode = btp.newMode;
    AD_OnModeChange();
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

//Execute Beat Tracker Pro Driver
void AD_Loop() 
{

  AD_ReadMode();
  AD_ProcessPaletteTransition();
  AD_Synchronise();


  //Slave Mode Watchdog Timeout
  if (millis() - btp.slaveTimer > 2000) //master mode return after 2s 
  {
    btp.slaveTimer = millis();
    btp.slave = false;
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
