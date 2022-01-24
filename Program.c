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
           |              \       |               Program.c              |      /                   |
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
            
#include "Program.h"
#include "Mapping.h"
#include "PixelStudio.h"

/********************************************************************
                               GLOBAL VAR
                         __(.)< __(.)> __(.)=
                         \___)  \___)  \___) hjw
**********************************O*********************************/
//Global shared objets
extern BTP btp;
extern MappingStructure ms;
ProgramManager pm;
extern MappingManager mm;
extern PixelStudio ps;


//------------------------------
// DEFINITIONS OF PROGRAM GROUPS
//------------------------------

uint8_t prgNbCALM = 1;
uint16_t prgCALM[] = {PROGRAM_PRIDE};

uint8_t prgNbSCAN = 3;
uint16_t prgSCAN[] = {PROGRAM_REACTIVE,PROGRAM_PATTERN,PROGRAM_SNAKES};

uint8_t prgNbMATH = 9;
uint16_t prgMATH[] = {PROGRAM_DANCE_1,
                     PROGRAM_DANCE_2,
                     PROGRAM_DANCE_3,
                     PROGRAM_DANCE_4,
                     PROGRAM_DISTRIB,
                     PROGRAM_BUBBLE,
                     PROGRAM_PULSE,
                     PROGRAM_CLAP,
                     PROGRAM_FLASH,
                     PROGRAM_SPARKS,
                     };

uint8_t prgNbLOST = 2;
uint16_t prgLOST[] = {PROGRAM_STARS,PROGRAM_DROPS};

uint8_t prgNbMANUAL = 16;
uint16_t prgMANUAL[] = { PROGRAM_PRIDE,
                         PROGRAM_REACTIVE,
                         PROGRAM_PATTERN, PROGRAM_SNAKES,
                         PROGRAM_DANCE_1,
                         PROGRAM_DANCE_2,
                         PROGRAM_DANCE_3,
                         PROGRAM_DANCE_4,
                         PROGRAM_DISTRIB,
                         PROGRAM_BUBBLE,
                         PROGRAM_PULSE,
                         PROGRAM_CLAP,
                         PROGRAM_FLASH,
                         PROGRAM_SPARKS,
                         PROGRAM_STARS,
                         PROGRAM_DROPS,
                         };


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
//Programs collections for each of the 4 modes
uint8_t Program_GetProgramNumber()
{
  switch(pm.prgMode)
  {
    case PROGRAM_MODE_CALM: return prgCALM[pm.prgIndexCALM];
    case PROGRAM_MODE_SCAN: return prgSCAN[pm.prgIndexSCAN];
    case PROGRAM_MODE_MATH: return prgMATH[pm.prgIndexMATH];
    case PROGRAM_MODE_LOST: return prgLOST[pm.prgIndexLOST];
    case PROGRAM_MODE_MANUAL: return prgMANUAL[pm.prgIndexMANUAL];
  }
  return 0;
}

void Program_Increment(uint8_t programGroup, uint8_t up)
{
  if (up)
  {
    switch(programGroup)
    {
      case PROGRAM_MODE_CALM:
        pm.prgIndexCALM++;
        pm.prgIndexCALM %= prgNbCALM;
        break;

      case PROGRAM_MODE_SCAN:
        pm.prgIndexSCAN++;
        pm.prgIndexSCAN%= prgNbSCAN;
        break;

      case PROGRAM_MODE_MATH:
        pm.prgIndexMATH++;
        pm.prgIndexMATH %= prgNbMATH;
        break;

      case PROGRAM_MODE_LOST:
        pm.prgIndexLOST++;
        pm.prgIndexLOST %= prgNbLOST;
        break;

      case PROGRAM_MODE_MANUAL:
        pm.prgIndexMANUAL++;
        pm.prgIndexMANUAL %= prgNbMANUAL;
        break;
    }
  }
  else
  {
    int newIndex;
    switch(programGroup)
    {
      case PROGRAM_MODE_CALM:
        newIndex = pm.prgIndexCALM - 1;
        if (newIndex<0)
          newIndex += prgNbCALM;
        pm.prgIndexCALM = newIndex;
        break;

      case PROGRAM_MODE_SCAN:
        newIndex = pm.prgIndexSCAN - 1;
        if (newIndex<0)
          newIndex += prgNbSCAN;
        pm.prgIndexSCAN = newIndex;
        break;

      case PROGRAM_MODE_MATH:
        newIndex = pm.prgIndexMATH - 1;
        if (newIndex<0)
          newIndex += prgNbMATH;
        pm.prgIndexMATH = newIndex;
        break;

      case PROGRAM_MODE_LOST:
        newIndex = pm.prgIndexLOST - 1;
        if (newIndex<0)
          newIndex += prgNbLOST;
        pm.prgIndexLOST = newIndex;
        break;

      case PROGRAM_MODE_MANUAL:
        newIndex = pm.prgIndexMANUAL - 1;
        if (newIndex<0)
          newIndex += prgNbMANUAL;
        pm.prgIndexMANUAL = newIndex;
        break;
    }
  }
}


void Program_IncrementCurrent() {Program_Increment(pm.prgMode, true); }

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
                         OBJECTS TOOLS
                                    ____________________________
   _____                          ,\\    ___________________    \
  |     `------------------------'  ||  (___________________)   `|
  |_____.------------------------._ ||  ____________________     |
          jgs                     `//__(____________________)___/

********************************************************************/
//Common routines for specific programs...


//Create a new flash object that is used for sound reactive programs
//At onset detection, his intensity is maximum but will decrease with time (FLASH_DURATION)
//Flashs are created from static collection, I've choosen not using malloc for security
OnsetFlash *NewFlash()
{
  int i;
  for(i=0;i<NB_FLASHS_MAX;i++)
  {
    OnsetFlash *f = &pm.flashs[i];
    if (!f->active)
    {
      f->active = true;
      f->timer = millis();
      f->intensity = 1;
      return f;
    }
  }
  return 0;
}

//This routine is only called by programs using it
//It will procces the intensity decrease and then disactivation of the object
void Execute_Flashs()
{
  int i;
  for(i=0;i<NB_FLASHS_MAX;i++)
  {
    OnsetFlash *f = &pm.flashs[i];
    if (f->active)
    {
      uint32_t delta = millis() - f->timer;
      if(delta>FLASH_DURATION)
        f->active = false;
      f->intensity = MapFloat(delta,0,FLASH_DURATION,1,0);
    }
  }
}


  
//Create a new shuttle object that is used for sound reactive programs
//A shuttle caries some informations like position, whith, mapping preset, colors, and many other you can add
//Shuttle are created from static collection, I've choosen not using malloc for security
Shuttle *NewShuttle()
{
  int i;
  for(i=0;i<NB_SHUTTLE_MAX;i++)
  {
    Shuttle *sh = &pm.shuttles[i];
    if (!sh->active)
    {
      sh->active = true;
      return sh;
    }
  }
  return 0;
}



/********************************************************************************************************
                                                 COMPOSITIONS
                                                  _____          /|
                                               .-'@ & #`'-.     //
                                              / %        8 \   //
                                             | m   () _     | //
                                              \  0   ( '-._/ //
                                        jgs    '-.____'.     y 
********************************************************************************************************/

/********************************************************************
                     RHYTHMIC (MATH MODE)
                      ======o     o======
                         ___________
                        |___________|  
                         |\  /\  /\|
                         |_\/__\/__|
                        |___________| AH
********************************************************************/

void Execute_Program_Dance()
{
  Layers_SetScale(LAYER_DEFAULT_SCALE); 
  Mapping m1, m2;
  uint8_t x1,x2;
  

  switch (u->programPreset)
  {
    case PROGRAM_PRESET_VERTICAL:
      //Where do I want to project my effects?
      Mapping_Preset(&m1, MAP_BAR_CENTER);
      Mapping_Preset(&m2, MAP_BAR_EXT);
    
      //Gets the realtime values for two bounce functions in two different rhythme value
      x1 = SignalPlay_Bounce(NOIRE,0);
      x2 = SignalPlay_Bounce(BLANCHE,0);
    
      //Draw two plots on two mappings, with the first and second colors of the actual palette
      Paint_PlotPersist(x1, 0, &m1, L0);
      Paint_PlotPersist(x2, 1, &m2, L1);
      break;

    case PROGRAM_PRESET_HORIZONTAL:
                  
        Layers_SetScale(50);
        Layers_SetRandomize(0, 20, 50, 50);
        
        Mapping m1, m2, m3, m4;
        Mapping_Preset(&m1, MAP_BAR_1);
        Mapping_Preset(&m2, MAP_BAR_2);
        Mapping_Preset(&m3, MAP_BAR_3);
        Mapping_Preset(&m4, MAP_BAR_4);
        x1 = SignalPlay_Trip(BLANCHE,0);
        Paint_PlotSparks(x1, 0, &m1, L0);
        Paint_PlotSparks(x1, 1, &m2, L1);
        Paint_PlotSparks(x1, 2, &m3, L2);
        Paint_PlotSparks(x1, 3, &m4, L3);
      break;
      
  
      
   
  }


  
  
}

void Execute_Program_Dance2()
{
  Layers_SetScale(LAYER_DEFAULT_SCALE); 
  Mapping m1, m2;
  uint8_t x1,x2;

  switch (u->programPreset)
  {
    case PROGRAM_PRESET_VERTICAL:
      Mapping_Preset(&m1, MAP_BAR_CENTER);
      Mapping_Preset(&m2, MAP_BAR_EXT);
      uint8_t x1 = SignalPlay_Bounce(NOIRE,0);
      uint8_t x2 = SignalPlay_Sinus(BLANCHE,0);
      Paint_PlotPersist(x1, 0, &m1, L0);
      Paint_PlotPersist(x2, 1, &m2, L1);
      break;

    case PROGRAM_PRESET_HORIZONTAL:
      Mapping_Preset(&m1, MAP_BAR_LEFT);
      Mapping_Preset(&m2, MAP_BAR_RIGHT);
      x1 = SignalPlay_TripConcave(BLANCHE,1,0);
      Paint_Plot(x1, BTP_GetRollColor_4To2(0), &m1);
      Paint_Plot(x1, BTP_GetRollColor_4To2(1), &m2);
      break;
  }
  
}


void Execute_Program_Dance3()
{
  Layers_SetScale(LAYER_DEFAULT_SCALE); 

  Mapping m1, m2;
  Mapping_Preset(&m1, MAP_BAR_ODD);
  Mapping_Preset(&m2, MAP_BAR_EVEN);
  uint8_t x1 = SignalPlay_Bounce(BLANCHE,0);
  uint8_t x2 = SignalPlay_Bounce(BLANCHE,128);
  Paint_PlotPersist(x1, 0, &m1, L0);
  Paint_PlotPersist(x2, 1, &m2, L1);
}

void Execute_Program_Dance4()
{
  Layers_SetScale(LAYER_DEFAULT_SCALE); 
  Mapping m1,m2,m3,m4;
  uint8_t x1,x2,x3,x4;

  switch (u->programPreset)
  {
    case PROGRAM_PRESET_VERTICAL:
      Mapping_Preset(&m1, MAP_BAR_1);
      Mapping_Preset(&m2, MAP_BAR_3);
      Mapping_Preset(&m3, MAP_BAR_2);
      Mapping_Preset(&m4, MAP_BAR_4);
      x1 = SignalPlay_Bounce4(RONDE,0);
      x2 = SignalPlay_Bounce4(RONDE,64);
      x3 = SignalPlay_Bounce4(RONDE,128);
      x4 = SignalPlay_Bounce4(RONDE,192);
    
      Paint_PlotPersist(x1, 0, &m1, L0);
      Paint_PlotPersist(x2, 1, &m2, L1);
      Paint_PlotPersist(x3, 2, &m3, L2);
      Paint_PlotPersist(x4, 3, &m4, L3);


      
      break;

    case PROGRAM_PRESET_HORIZONTAL:
      Mapping_Preset(&m1, MAP_BAR_LEFT);
      Mapping_Preset(&m2, MAP_BAR_RIGHT);
      x1 = SignalPlay_Trip(BLANCHE,0);
      Paint_Plot(x1, BTP_GetRollColor_4To2(0), &m1);
      Paint_Plot(x1, BTP_GetRollColor_4To2(1), &m2);
      break;
  }

   
  

}


void Execute_Program_Distribution()
{
  Layers_SetScale(128); 


  Mapping m1,m2,m3,m4;
  uint8_t x1,x2,x3,x4;

  Mapping_Preset(&m1, MAP_BAR_1);
  Mapping_Preset(&m2, MAP_BAR_2);
  Mapping_Preset(&m3, MAP_BAR_3);
  Mapping_Preset(&m4, MAP_BAR_4);
  
  switch (u->programPreset)
  {
    case PROGRAM_PRESET_VERTICAL:
      
      x1 = SignalPlay_ConcavOrder(RONDE,2,0);
      x2 = SignalPlay_ConcavOrder(RONDE,2,64);
      x3 = SignalPlay_ConcavOrder(RONDE,2,128);
      x4 = SignalPlay_ConcavOrder(RONDE,2,192);
      Paint_PlotPersist(255-x1, 0, &m1, L0);
      Paint_PlotPersist(255-x2, 1, &m2, L1);
      Paint_PlotPersist(255-x3, 2, &m3, L2);
      Paint_PlotPersist(255-x4, 3, &m4, L3);
      break;

    case PROGRAM_PRESET_HORIZONTAL:
      x1 = SignalPlay_Explode(RONDE,0);
      x2 = SignalPlay_Explode(RONDE,64);
      x3 = SignalPlay_Explode(RONDE,128);
      x4 = SignalPlay_Explode(RONDE,192);

      Paint_PlotPersist(x1, 0, &m1, L0);
      Paint_PlotPersist(x2, 1, &m2, L1);
      Paint_PlotPersist(x3, 2, &m3, L2);
      Paint_PlotPersist(x4, 3, &m4, L3);
      break;
  }

}



void Execute_Program_Bubbles()
{
  Layers_SetScale(LAYER_DEFAULT_SCALE); 
  //Layers_SetScale(50); 
  
  Mapping m1, m2;
  Mapping_Preset(&m1, MAP_BAR_LEFT);
  Mapping_Preset(&m2, MAP_BAR_RIGHT);
  uint8_t x1 = SignalPlay_Compress(BLANCHE,0);
  uint8_t x2 = SignalPlay_Expand(BLANCHE,0);
  uint8_t x3 = SignalPlay_Compress(BLANCHE,128);
  uint8_t x4 = SignalPlay_Expand(BLANCHE,128);
  Paint_PlotPersist(x1, 0, &m1, L0);
  Paint_PlotPersist(x2, 0, &m1, L1);
  Paint_PlotPersist(x3, 1, &m2, L2);
  Paint_PlotPersist(x4, 1, &m2, L3);
}


void Execute_Program_Pulse()
{
  Layers_SetScale(LAYER_DEFAULT_SCALE); 
  Mapping m1;
  uint8_t x1,x2,x3,x4;
  Mapping_Preset(&m1, MAP_BAR_ALL);

  switch (u->programPreset)
  {
    case PROGRAM_PRESET_VERTICAL:
      x1 = 255 - SignalPlay_Concav(BLANCHE,0);
      x2 = 255 - SignalPlay_Concav(BLANCHE,128);
      break;

    case PROGRAM_PRESET_HORIZONTAL:
      x1 = SignalPlay_Concav(BLANCHE,0);
      x2 = SignalPlay_Concav(BLANCHE,128);
      break;
  }
  
  Paint_PlotPersist(x1, BTP_GetRollColorID_4To2(0), &m1, L0);
  Paint_PlotPersist(x2, BTP_GetRollColorID_4To2(1), &m1, L1);
}




void Execute_Program_Cross()
{
  Layers_SetScale(LAYER_DEFAULT_SCALE); 
  Mapping m1, m2;
  Mapping_Preset(&m1, MAP_BAR_LEFT);
  Mapping_Preset(&m2, MAP_BAR_RIGHT);
  uint8_t x1 = SignalPlay_SinusConvex(BLANCHE,118);
  uint8_t x2 = SignalPlay_SinusConvex(BLANCHE,138);
  //Two plots in the same mapping...
  Paint_PlotPersist(x1, 0, &m1, L0);
  Paint_PlotPersist(255-x1, 1, &m1, L1);
  Paint_PlotPersist(x2, 0, &m2, L2);
  Paint_PlotPersist(255-x2, 1, &m2, L3);
}


void Execute_Program_Clap()
{
  Layers_SetScale(LAYER_DEFAULT_SCALE); 
  Mapping m1,m2,m3,m4;
  uint8_t x1 = SignalPlay_Bounce(NOIRE,0);
  
  switch (u->programPreset)
  {
    case PROGRAM_PRESET_VERTICAL:
      Mapping_Preset(&m1, MAP_BAR_ALL);
      Paint_PlotPersist(128+(x1>>1), 0, &m1, L0);
      Paint_PlotPersist(128-(x1>>1), 1, &m1, L1);
      break;

    case PROGRAM_PRESET_HORIZONTAL:
      Mapping_Preset(&m1, MAP_BAR_1);
      Mapping_Preset(&m2, MAP_BAR_2);
      Mapping_Preset(&m3, MAP_BAR_3);
      Mapping_Preset(&m4, MAP_BAR_4);
      Paint_PlotPersist(x1, 0, &m1, L0);
      Paint_PlotPersist(x1, 1, &m2, L1);
      Paint_PlotPersist(x1, 2, &m3, L2);
      Paint_PlotPersist(x1, 3, &m4, L3);
      break;
  }

  
}



void Execute_Program_Flash()
{
  Layers_SetScale(LAYER_DEFAULT_SCALE); 
  Mapping m1, m2;
  Mapping_Preset(&m1, MAP_BAR_CENTER);
  Mapping_Preset(&m2, MAP_BAR_EXT);
  uint8_t x1 = SignalPlay_Bounce(BLANCHE,0);
  uint8_t x2 = SignalPlay_Bounce(BLANCHE,128);
  Color c1 = BTP_GetColor(0);
  float dim = (float)(255-x2)/255;
  c1 = Color_Brightness(c1,dim);
  Color c2 = BTP_GetColor(1);
  dim = (float)(255-x1)/255;
  c2 = Color_Brightness(c2,dim);
  //A beam permit to fill a region between 2 plots
  Paint_Bean((x2>>1),255-(x2>>1), c1, &m1);
  Paint_Bean(128+(x1>>1),128-(x1>>1), c2, &m2);
}


/********************************************************************
                    SOUND REACTIVE (SCAN MODE)
                           ______  
                           '`-. / 
                              //___ 
                             / _.-' 
                            /.'  

********************************************************************/
void Execute_Program_Volume()
{
  Mapping m1,m2,m3,m4;
  Mapping_Preset(&m1, MAP_BAR_1);
  Mapping_Preset(&m2, MAP_BAR_4);
  Mapping_Preset(&m3, MAP_BAR_2);
  Mapping_Preset(&m4, MAP_BAR_3);

  int i;
  for(i=0;i<4;i++)
  {
    //Read differents regions of the volume record
    //The value is scaled whit min & max to avoid low dynamics
    uint8_t vol = BTP_ReadRangedInput(i*20+1)>>1;
    switch(i)
    {
      case 0:Paint_Bean(128-vol,128+vol, BTP_GetDynamicColor(0), &m1);break;
      case 1:Paint_Bean(128-vol,128+vol, BTP_GetDynamicColor(1), &m2);break;
      case 2:Paint_Bean(128-vol,128+vol, BTP_GetDynamicColor(2), &m3);break;
      case 3:Paint_Bean(128-vol,128+vol, BTP_GetDynamicColor(3), &m4);break;
    }
  }
}



//This program is quite complex using Flash & Shuttle objects
//It will lights many beams in random place, random color and decreasing in width & intensity
void Execute_Program_Reactive()
{
  btp.dynamicHysterisis = 2; //Lots of hits
  Mapping m1;
  
  int i;
  if (btp.onset)
  {
    //Flash creation on onset detection
    OnsetFlash *f = NewFlash();
    if (f)
    {
      //Shuttle creation linked to the flash
      Shuttle *sh = NewShuttle();
      if (sh)
      {
        //Random shuttle initialization
        sh->flash = f;
        sh->colorId = GetRandom(4);
        sh->mappingPreset = Mapping_GetRandomPreset();
        sh->pos = GetRandom(255);
        sh->width = btp.dynamicStrength;
      }
    }
  }
  
  //Flashs runtime...
  Execute_Flashs();

  //Rendering of each shuttle
  int j;
  for(i=0;i<NB_SHUTTLE_MAX;i++)
  {
    Shuttle *sh = &pm.shuttles[i];
    if (sh->active)
    {
      OnsetFlash *f = sh->flash;
      if (f->active)
      {
        Color color = BTP_GetColor(sh->colorId);
        color = Color_Brightness(color, f->intensity);
        uint8_t width = sh->width*f->intensity;
        Mapping_Preset(&m1, sh->mappingPreset); //output on randomly predefined map
        uint8_t x0 = (uint8_t)BoundInt16(sh->pos - width,0,255);
        uint8_t x1 = (uint8_t)BoundInt16(sh->pos + width,0,255);
        Paint_Bean(x0, x1, color, &m1);
      }
      else
        sh->active = false; //Dispose on flash disactivation
    }
  }
}








//This program is quite complex using Flash & Shuttle objects
//It will lights many beams in random place, random color and decreasing in width & intensity
void Execute_Program_Pattern()
{
  btp.dynamicHysterisis = 10; //Few hits
  
  uint8_t sync = SignalPlay_Function(BLANCHE,0, 0);
  uint8_t pathIndex = MapInt16(sync,0,256,0,16);
  pathIndex = btp.dices16[pathIndex];
  
  uint8_t pathMap = pathIndex / 4;
  uint8_t pathPos = pathIndex % 4;

  uint8_t pos = MapInt16(pathPos,0,3,64,224);
  
  Mapping m1;

  
  int i;
  if (btp.onset)
  {
    //Flash creation on onset detection
    OnsetFlash *f = NewFlash();
    if (f)
    {
      //Shuttle creation linked to the flash
      Shuttle *sh = NewShuttle();
      if (sh)
      {
        //Random shuttle initialization
        sh->flash = f;
        sh->colorId = pathPos;
        sh->mappingPreset = pathMap + 1;
        sh->pos = pos;
        sh->width = btp.dynamicStrength;
      }
    }
  }

 // return;
  
  //Flashs runtime...
  Execute_Flashs();

  //Rendering of each shuttle
  int j;
  for(i=0;i<NB_SHUTTLE_MAX;i++)
  {
    Shuttle *sh = &pm.shuttles[i];
    if (sh->active)
    {
      OnsetFlash *f = sh->flash;
      if (f->active)
      {
        Color color = BTP_GetColor(sh->colorId);
        color = Color_Brightness(color, f->intensity);
        uint8_t width = sh->width*f->intensity;
        Mapping_Preset(&m1, sh->mappingPreset); //output on randomly predefined map
        uint8_t x0 = (uint8_t)BoundInt16(sh->pos - width,0,255);
        uint8_t x1 = (uint8_t)BoundInt16(sh->pos + width,0,255);
        Paint_Bean(x0, x1, color, &m1);
      }
      else
        sh->active = false; //Dispose on flash disactivation
    }
  }
}

/********************************************************************
                        PRIDE - (CALM MODE)   
                              .-.
                             (. .)__,')
                             / V      )
                       ()    \  (   \/
                     <)-`\()  `._`._ \
                       <).>=====<<==`'====  hjw
********************************************************************/
void Execute_Program_Pride()
{
  Mapping m1,m2,m3,m4;
  Mapping_Preset(&m1, MAP_BAR_1);
  Mapping_Preset(&m2, MAP_BAR_2);
  Mapping_Preset(&m3, MAP_BAR_3);
  Mapping_Preset(&m4, MAP_BAR_4);
  //Paint a full degrade between two colors
  Paint_Degrade(BTP_GetColor(0),BTP_GetColor(1), &m1);
  Paint_Degrade(BTP_GetColor(1),BTP_GetColor(2), &m2);
  Paint_Degrade(BTP_GetColor(2),BTP_GetColor(3), &m3);
  Paint_Degrade(BTP_GetColor(3),BTP_GetColor(0), &m4);
}

/********************************************************************
                            LOST MODE
                              .-.
                             (. .)__,')
                             / V      )
                       ()    \  (   \/
                     <)-`\()  `._`._ \
                       <).>=====<<==`'====  hjw
********************************************************************/
void Execute_Program_Stars()
{
  
  if (millis() - pm.programFreeTimer > 50)
  {
    pm.programFreeTimer = millis();
    Mapping m1;
    uint8_t x1 = GetRandom(255);
    Mapping_Preset(&m1, Mapping_GetRandomPreset()); //output on randomly predefined map
    Paint_Plot(x1, WHITE, &m1);
  }
  
}



void Execute_Program_Drops()
{
  Layers_SetScale(128); 
  Mapping m1;

  if (millis() - pm.programFreeTimer > 50)
  {
    pm.programFreeTimer = millis();
    
    uint8_t x = GetRandom(255);
    uint8_t colorID = GetRandom(4);
    uint8_t mappingID = GetRandom(4);
    uint8_t mappingPreset = Mapping_FromID(mappingID);
    Mapping_Preset(&m1, mappingPreset); //output on randomly predefined map

    Layer *l = &mm.currentUniverse->layers[mappingID];
    l->effect = LAYER_EFFECT_PERSIST;
    l->colorID = colorID;
    Color color = BTP_GetColor(colorID);
    Layer_FeedPersist(l, x, color, false);
  
  }

  int i;
  for (i=0;i<4;i++)
  {
    Layer *l = &mm.currentUniverse->layers[i];
    uint8_t mappingPreset = Mapping_FromID(i);
    Mapping_Preset(&m1, mappingPreset); //output on randomly predefined map
    Layer_PaintPersist(l, &m1);
    Layer_ExecutePersist(l);
  }
  
  
}

/********************************************************************
                            NEW PROGRAMS
                              .-.
                             (. .)__,')
                             / V      )
                       ()    \  (   \/
                     <)-`\()  `._`._ \
                       <).>=====<<==`'====  hjw
********************************************************************/
void Execute_Program_Explode()
{
   Mapping m1;

  //Where do I want to project my effects?
  //Mapping_Preset(&m1, MAP_BAR_CENTER);
  Mapping_Preset(&m1, MAP_BAR_ALL);

  //Gets the realtime values for two bounce functions in two different rhythme value
  uint8_t x1 = SignalPlay_Explode(BLANCHE,0);
  uint8_t x2 = SignalPlay_Explode(BLANCHE,128);

  //Draw two plots on two mappings, with the first and second colors of the actual palette
  Paint_Plot(x1, BTP_GetRollColor_4To2(0), &m1);
  Paint_Plot(x2, BTP_GetRollColor_4To2(1), &m1);
//Color BTP_GetRollColor_4To2(uint8_t index);
}


void Execute_Program_Hammer()
{
  
}


void Execute_Program_Bounce()
{
  
}


void Execute_Program_Snakes()
{
  Mapping m1;
  btp.dynamicHysterisis = 10; //Few hits

  int i;
  if (btp.onset)
  {
    //Flash creation on onset detection
    OnsetFlash *f = NewFlash();
    if (f)
    {
      //Shuttle creation linked to the flash
      Shuttle *sh = NewShuttle();
      if (sh)
      {
        //Random shuttle initialization
        sh->flash = f;
        sh->colorId = GetRandom(4);
        sh->mappingPreset = Mapping_GetRandomPreset();
        sh->pos = GetRandom(255);

        sh->effectStep  = 10;
        sh->effectStart = millis();
        sh->scale = btp.dynamicStrength;
        sh->effectStop = sh->effectStart + sh->scale * sh->effectStep;

        sh->direction = GetRandom(2);
        sh->posOffset = 0;
      }
    }
  }
  
  //Flashs runtime...
  Execute_Flashs();

  //Rendering of each shuttle
  int j;
  for(i=0;i<NB_SHUTTLE_MAX;i++)
  {
    Shuttle *sh = &pm.shuttles[i];
    if (sh->active)
    {
      OnsetFlash *f = sh->flash;
      if (f->active)
      {
        

        if (millis() > sh->effectStop)
        {
          f->active = false;
          sh->active = false;
        }
        else
        {
          Mapping_Preset(&m1, sh->mappingPreset); //output on randomly predefined map

          uint8_t sync = MapFloat(millis(),sh->effectStart,sh->effectStop,0,255);
          uint8_t compressSync = Signal_Compress(sync, true);

          
          Color color = BTP_GetColor(sh->colorId);
          float intensity = MapFloat(compressSync,0,255,0,1);
          color = Color_Brightness(color, intensity);
        
          sh->posOffset += sh->speed;

        
          
  
          sh->speed = MapFloat(compressSync,0,255,0,2);
          if (sh->direction)
            sh->speed = -sh->speed;
          sh->posOffset += sh->speed;
  
  
  
          
          float x1 = sh->pos + sh->posOffset;
          if (x1 >= 256)
            x1 -= 256;
          if (x1 <= 0)
            x1 += 256;
  
          Paint_Plot(x1, color, &m1);
        }
        
      }
      else
        sh->active = false; //Dispose on flash disactivation
    }
  }
}


void Execute_Program_Linear()
{
  Mapping m1, m2;
  Mapping_Preset(&m1, MAP_BAR_LEFT);
  Mapping_Preset(&m2, MAP_BAR_RIGHT);
  uint8_t x1 = SignalPlay_Trip(BLANCHE,0);
  Paint_Plot(x1, BTP_GetRollColor_4To2(0), &m1);
  Paint_Plot(x1, BTP_GetRollColor_4To2(1), &m2);
}


void Execute_Program_Sparks()
{
  Layers_SetScale(50);
  Layers_SetRandomize(50, 0, 50, 100);
  
  Mapping m1, m2, m3, m4;
  Mapping_Preset(&m1, MAP_BAR_1);
  Mapping_Preset(&m2, MAP_BAR_2);
  Mapping_Preset(&m3, MAP_BAR_3);
  Mapping_Preset(&m4, MAP_BAR_4);
  uint8_t x1 = SignalPlay_Trip(BLANCHE,0);
  Paint_PlotSparks(x1, 0, &m1, L0);
  Paint_PlotSparks(x1, 1, &m2, L1);
  Paint_PlotSparks(x1, 2, &m3, L2);
  Paint_PlotSparks(x1, 3, &m4, L3);
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
//Execution of selected program
void Program_LoopRelease()
{

  switch(btp.currentProgram)
  {
    case PROGRAM_PRIDE: Execute_Program_Pride(); break;
    case PROGRAM_REACTIVE: Execute_Program_Reactive(); break;
    case PROGRAM_PATTERN: Execute_Program_Pattern(); break;
    case PROGRAM_DANCE_1: Execute_Program_Dance(); break;
    case PROGRAM_DANCE_2: Execute_Program_Dance2(); break;
    case PROGRAM_DANCE_3: Execute_Program_Dance3(); break;
    case PROGRAM_DANCE_4: Execute_Program_Dance4(); break;
    case PROGRAM_DISTRIB: Execute_Program_Distribution(); break;
    case PROGRAM_BUBBLE: Execute_Program_Bubbles(); break;
    case PROGRAM_PULSE: Execute_Program_Pulse(); break;
    case PROGRAM_CROSS: Execute_Program_Cross(); break;
    case PROGRAM_CLAP: Execute_Program_Clap(); break;
    case PROGRAM_FLASH: Execute_Program_Flash(); break;
    case PROGRAM_STARS: Execute_Program_Stars(); break;

    case PROGRAM_EXPLODE: Execute_Program_Explode(); break;
    case PROGRAM_HAMMER: Execute_Program_Hammer(); break;
    case PROGRAM_BOUNCE: Execute_Program_Bounce(); break;
    case PROGRAM_SNAKES: Execute_Program_Snakes(); break;
    case PROGRAM_LINEAR: Execute_Program_Linear(); break;
    case PROGRAM_DROPS: Execute_Program_Drops(); break;
    case PROGRAM_SPARKS: Execute_Program_Sparks(); break;

  }
}


//For each frame, whe have to clear all led strips...
//execute de program...
//copy the buffer to Cpp FastLed memory...
//then tell FastLed librairy to show ou magnificient program
void Program_LoopUniverse(Universe *uni)
{
  mm.currentUniverse = uni;
  //Clear all strips at each frame
  Mapping_ClearStrip(&uni->strip); 

  if (!btp.blackout)
  {

    Program_LoopRelease();        //Final loop
   // Execute_Program_Dance4();
    
    //Test loop
    //Execute_Program_Reactive();     
    //Execute_Program_Pattern();
    //Execute_Program_Stars();
    
    //Execute_Program_Explode();
    
    //Execute_Program_Hammer();
    //Execute_Program_Bounce();
    //Execute_Program_Snakes();
    //Execute_Program_Linear();
    
    //Execute_Program_Sparks();
  }

  //to cpp FastLed Wrapper
  FastLED_StripOut(&uni->strip);  
}


//3 Universe : 40 FPS
//2 Universe : 60 FPS
//1 Universe : 120 FPS

void Program_Loop()
{
  if (ps.strip1Active)
    Program_LoopUniverse(U0);
  if (ps.strip2Active)
    Program_LoopUniverse(U1);
  

  FastLED_Show();                   //Enjoy!
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
