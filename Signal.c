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
           |              \       |               Signal.c               |      /                   |
           |               \      |                                      |     /                    |
           |               /      |______________________________________|     \                    |
           |              /__________)                                (_________\                   |
           |                                                                                        |
           |           This librairy provide various rhythmical signals for yours programs          |
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
           
#include "Signal.h"
#include "Program.h"
/********************************************************************
                               GLOBAL VAR
                         __(.)< __(.)> __(.)=
                         \___)  \___)  \___) hjw
**********************************O*********************************/
//Global shared objets
extern BTP btp;

/********************************************************************
                 CONSTANT FONCTIONS
                    .----.-.
                   /    ( o \
                  '|  __ ` ||
                   |||  ||| -'
********************************************************************/
//These constants arrays permit a fast transformation of 256*256 matrix

const uint8_t sinus[] = 
{
  128,131,134,137,140,143,146,149,153,156,159,162,165,168,171,174,
  177,180,182,185,188,191,194,196,199,201,204,207,209,211,214,216,
  218,220,223,225,227,229,231,232,234,236,238,239,241,242,243,245,
  246,247,248,249,250,251,252,253,253,254,254,255,255,255,255,255,
  255,255,255,255,255,254,254,253,253,252,251,251,250,249,248,247,
  245,244,243,241,240,238,237,235,233,232,230,228,226,224,222,219,
  217,215,213,210,208,205,203,200,198,195,192,189,187,184,181,178,
  175,172,169,166,163,160,157,154,151,148,145,142,139,135,132,129,
  126,123,120,116,113,110,107,104,101,98, 95, 92, 89, 86, 83, 80, 
  77, 74, 71, 68, 66, 63, 60, 57, 55, 52, 50, 47, 45, 42, 40, 38, 
  36, 33, 31, 29, 27, 25, 23, 22, 20, 18, 17, 15, 14, 12, 11, 10, 
  8,  7,  6,  5,  4,  4,  3,  2,  2,  1,  1,  0,  0,  0,  0,  0,  
  0,  0,  0,  0,  0,  1,  1,  2,  2,  3,  4,  5,  6,  7,  8,  9,  
  10, 12, 13, 14, 16, 17, 19, 21, 23, 24, 26, 28, 30, 32, 35, 37, 
  39, 41, 44, 46, 48, 51, 54, 56, 59, 61, 64, 67, 70, 73, 75, 78, 
  81, 84, 87, 90, 93, 96, 99, 102,106,109,112,115,118,121,124,127,
};

const uint8_t compress[] = 
{
  0,  1,  3,  5,  7,  9,  11, 13, 15, 17, 19, 20, 22, 24, 26, 28, 
  29, 31, 33, 34, 36, 38, 39, 41, 43, 44, 46, 48, 49, 51, 52, 54, 
  55, 57, 58, 60, 61, 63, 64, 66, 67, 69, 70, 72, 73, 75, 76, 77, 
  79, 80, 81, 83, 84, 85, 87, 88, 89, 91, 92, 93, 95, 96, 97, 99, 
  100,101,102,103,105,106,107,108,110,111,112,113,114,115,117,118,
  119,120,121,122,124,125,126,127,128,129,130,131,132,133,134,136,
  137,138,139,140,141,142,143,144,145,146,147,148,149,150,151,152,
  153,154,155,156,157,158,159,160,160,161,162,163,164,165,166,167,
  168,169,170,171,171,172,173,174,175,176,177,177,178,179,180,181,
  182,183,183,184,185,186,187,187,188,189,190,191,192,192,193,194,
  195,195,196,197,198,198,199,200,201,201,202,203,204,204,205,206,
  207,207,208,209,210,210,211,212,212,213,214,214,215,216,216,217,
  218,218,219,220,220,221,222,222,223,224,224,225,226,226,227,228,
  228,229,229,230,231,231,232,232,233,234,234,235,235,236,237,237,
  238,238,239,240,240,241,241,242,242,243,243,244,245,245,246,246,
  247,247,248,248,249,249,250,250,251,251,252,252,253,253,254,255,
};

const uint8_t concav[] = 
{
  0,  2,  5,  8,  10, 13, 15, 18, 20, 22, 24, 26, 28, 30, 32, 34, 
  35, 37, 39, 40, 42, 44, 45, 47, 48, 50, 51, 53, 54, 55, 57, 58, 
  59, 61, 62, 63, 64, 66, 67, 68, 69, 70, 71, 72, 73, 75, 76, 77, 
  78, 79, 80, 81, 82, 82, 83, 84, 85, 86, 87, 88, 89, 90, 90, 91, 
  92, 93, 94, 95, 95, 96, 97, 98, 98, 99, 100,100,101,102,103,103,
  104,105,105,106,106,107,108,108,109,109,110,111,111,112,112,113,
  113,114,114,115,116,116,117,117,117,118,118,119,119,120,120,121,
  121,122,122,122,123,123,124,124,124,125,125,125,126,126,126,127,
  127,128,128,128,129,129,129,130,130,130,131,131,132,132,132,133,
  133,134,134,135,135,136,136,137,137,137,138,138,139,140,140,141,
  141,142,142,143,143,144,145,145,146,146,147,148,148,149,149,150,
  151,151,152,153,154,154,155,156,156,157,158,159,159,160,161,162,
  163,164,164,165,166,167,168,169,170,171,172,172,173,174,175,176,
  177,178,180,181,182,183,184,185,186,187,188,190,191,192,193,195,
  196,197,199,200,201,203,204,206,207,209,210,212,214,215,217,219,
  220,222,224,226,228,230,232,234,236,239,241,244,246,249,252,255,
};

const uint8_t convex[] = 
{
  0,  0,  0,  1,  1,  1,  2,  2,  2,  3,  3,  4,  4,  4,  5,  5,  
  6,  6,  6,  7,  7,  8,  8,  9,  9,  10, 10, 11, 11, 12, 12, 13, 
  13, 14, 14, 15, 16, 16, 17, 17, 18, 19, 19, 20, 20, 21, 22, 22, 
  23, 24, 24, 25, 26, 26, 27, 28, 29, 29, 30, 31, 32, 32, 33, 34, 
  35, 36, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 45, 46, 47, 48, 
  49, 50, 51, 53, 54, 55, 56, 57, 58, 59, 60, 62, 63, 64, 65, 66, 
  68, 69, 70, 72, 73, 75, 76, 77, 79, 80, 82, 84, 85, 87, 89, 90, 
  92, 94, 96, 98, 99, 101,104,106,108,110,112,115,117,120,123,126,
  128,131,134,137,139,142,144,146,148,150,153,155,156,158,160,162,
  164,165,167,169,170,172,174,175,177,178,179,181,182,184,185,186,
  188,189,190,191,192,194,195,196,197,198,199,200,201,203,204,205,
  206,207,208,209,210,210,211,212,213,214,215,216,217,218,218,219,
  220,221,222,222,223,224,225,225,226,227,228,228,229,230,230,231,
  232,232,233,234,234,235,235,236,237,237,238,238,239,240,240,241,
  241,242,242,243,243,244,244,245,245,246,246,247,247,248,248,248,
  249,249,250,250,250,251,251,252,252,252,253,253,253,254,254,255,
};

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

//The expand function is obtained by mirroring X and Y
uint8_t Signal_Expand(uint8_t x)
{
  return 255-compress[255-x];
}

uint8_t Signal_Compress(uint8_t x, bool invert)
{
  uint8_t y = compress[x];
  if (invert)
    y = 255-y;
  return y;
}

/******************************************************************
                        EXECUTE FUCTION
      .-.                                   .-.
     /   \                                 /   \    
    /     \                               /     \  
   /       \       .-.                   /       \       .-. 
  /         \     /   \                 /         \     /   \
 /           \___/     \_______________/           \___/     \
********************************************************************/

//Execute full calculation of the signal object including stages tranformations
uint8_t Signal_Function(Signal *sig, uint8_t x)
{
  sig->val = x;
  int i,j;
  if (sig->nbStages == 0)
    sig->nbStages = 1; //base = 1
  for (i=0;i<sig->nbStages;i++)
  {
    SignalStage *st = &sig->stages[i];
    
    //PHASE
    sig->val = sig->val - st->phase;
    if (sig->val < 0)
      sig->val += 256;
      
    //MIRROR
    if (st->mirror)
      sig->val = 255 - sig->val;
    //ORDER
    if (st->order == 0)
      st->order = 1; //base = 1
    
    
    for (j=0;j<st->order;j++)
    {
      switch (st->function)
      {
        case TRIP:      sig->val = 255 - abs(255 - (sig->val<<1));  break;
        case SINUS:     sig->val = sinus[sig->val];                    break;
        case COMPRESS:  sig->val = compress[sig->val];                 break;
        case EXPAND:    sig->val = Signal_Expand(sig->val);            break;
        case CONCAV:    sig->val = concav[sig->val];                  break;
        case CONVEX:    sig->val = convex[sig->val];                  break;
      }
    }
    
    //INVERT
    if (st->invert)
      sig->val = 255 - sig->val;
  }
  return sig->val;
}

//Execute the signal according to his rhythmical value
void Signal_ExecuteSolfege(Signal *sig)
{
  switch (sig->solfege)
  {
    case NOIRE:         sig->val = btp.sync;     break;
    case CROCHE:        sig->val = btp.sync<<1;  break;
    case DOUBLE_CROCHE: sig->val = btp.sync<<2;  break;
    case TRIPLE_CROCHE: sig->val = btp.sync<<3;  break;
    case BLANCHE:       sig->val = (uint8_t)(((uint16_t)(btp.t2<<8) + btp.sync) >> 1); break;
    case RONDE:         sig->val = (uint8_t)(((uint16_t)(btp.t4<<8) + btp.sync) >> 2); break;
    case PHRASE:        sig->val = (uint8_t)(((uint16_t)(btp.t8<<8) + btp.sync) >> 3); break;
    case DEMI_PAGE:     sig->val = (uint8_t)(((uint16_t)(btp.t16<<8)+ btp.sync) >> 4);break;
    case PAGE:          sig->val = (uint8_t)(((uint16_t)(btp.t<<8)  + btp.sync) >> 5);break;
  }
  Signal_Function(sig, sig->val);
}



/********************************************************************
                        SIGNAL PRESETS
                            .--.
                           |.__.|
                           ||||||
                          /      \
                          `.__|_.'
********************************************************************/

//Initialization of signal arguments producing a bounce effect
void SignalPreset_Bounce(Signal *s, uint8_t solfege, uint8_t order, uint8_t mirror, uint8_t invert, uint8_t phase)
{
  s->solfege = solfege;
  s->nbStages = 2;
    
    SignalStage *st0 = &s->stages[0];
    st0->function = TRIP;
    st0->phase = phase;

    SignalStage *st1 = &s->stages[1];
    st1->function = COMPRESS;
    st1->order = order;
    st1->mirror = mirror;
    st1->invert = invert;
}

//Initialization of signal arguments for a unique stage function
void SignalPreset(Signal *s, uint8_t solfege, uint8_t function, uint8_t order, uint8_t mirror, uint8_t invert, uint8_t phase)
{
  
  s->solfege = solfege;
  s->nbStages = 1;
  SignalStage *st = &s->stages[0];
  st->function = function;
  st->order = order;
  st->mirror = mirror;
  st->invert = invert;
  st->phase = phase;
}

//Initialization of signal arguments for a function with a convex second stage
void SignalPreset_FunctionConvex(Signal *s, uint8_t solfege, uint8_t function, uint8_t order, uint8_t mirror, uint8_t invert, uint8_t phase)
{
  s->solfege = solfege;
  s->nbStages = 2;
  SignalStage *st0 = &s->stages[0];
  st0->function = function;
  st0->phase = phase;
  SignalStage *st1 = &s->stages[1];
  st1->function = CONVEX;
  st1->order = order;
  st1->mirror = mirror;
  st1->invert = invert;
}


void SignalPreset_FunctionDouble(Signal *s, uint8_t solfege, uint8_t function1, uint8_t function2, uint8_t order2, uint8_t mirror, uint8_t phase)
{
  s->solfege = solfege;
  s->nbStages = 2;
  SignalStage *st0 = &s->stages[0];
  st0->function = function1;
  st0->phase = phase;
  SignalStage *st1 = &s->stages[1];
  st1->function = function2;
  st1->order = order2;
  st1->mirror = mirror;
}

//USER+
//Add here your new SignalPreset_Functions()...
/******************************************************************
                                  PLAY
                           ,-.        _.---._
                          |  `\.__.-''       `.
                           \  _        _  ,.   \
     ,+++=._________________)_||______|_|_||    |
    (_.ooo.===================||======|=|=||    |
       ~~'                 |  ~'      `~' o o  /
                            \   /~`\     o o  /
                             `~'    `-.____.-' 
******************************************************************/
//These following functions are called by your programs compositions (Program.c)
//They gives you the real time value of a predefined signal according to his rhythmical value

uint8_t SignalPlay_BounceOrder(uint8_t solfege,uint8_t order, uint8_t phase)
{
  Signal s;
  memset(&s,0,sizeof(Signal)); 
  SignalPreset_Bounce(&s, solfege, order, false, false, phase);
  Signal_ExecuteSolfege(&s);
  return s.val;
}

uint8_t SignalPlay_FunctionConvex(uint8_t solfege,uint8_t function, uint8_t phase)
{
  Signal s;
  memset(&s,0,sizeof(Signal));
  SignalPreset_FunctionConvex(&s, solfege, function, 1, false, false, phase);
  Signal_ExecuteSolfege(&s);
  return s.val;
}



uint8_t SignalPlay_FunctionOrder(uint8_t solfege,uint8_t function, uint8_t order, uint8_t phase)
{
  Signal s;
  memset(&s,0,sizeof(Signal));
  SignalPreset(&s, solfege, function, order, false, false, phase);
  Signal_ExecuteSolfege(&s);
  return s.val;
}

uint8_t SignalPlay_Function(uint8_t solfege,uint8_t function, uint8_t phase)
{
  return SignalPlay_FunctionOrder(solfege, function, 1, phase);
}
/*
uint8_t SignalPlay_Function(uint8_t solfege,uint8_t function, uint8_t phase)
{
  Signal s;
  memset(&s,0,sizeof(Signal));
  SignalPreset(&s, solfege, function, 1, false, false, phase);
  Signal_ExecuteSolfege(&s);
  return s.val;
}
*/
uint8_t SignalPlay_Bounce(uint8_t solfege,uint8_t phase){return SignalPlay_BounceOrder(solfege,2, phase);}
uint8_t SignalPlay_Bounce4(uint8_t solfege,uint8_t phase){return SignalPlay_BounceOrder(solfege,4, phase);}
uint8_t SignalPlay_Sinus(uint8_t solfege,uint8_t phase) {return SignalPlay_Function(solfege,SINUS, phase);}
uint8_t SignalPlay_Compress(uint8_t solfege,uint8_t phase){return SignalPlay_Function(solfege,COMPRESS, phase);}
uint8_t SignalPlay_Expand(uint8_t solfege,uint8_t phase){return SignalPlay_Function(solfege,EXPAND, phase);}
uint8_t SignalPlay_Concav(uint8_t solfege,uint8_t phase){return SignalPlay_Function(solfege,CONCAV, phase);}
uint8_t SignalPlay_Convex(uint8_t solfege,uint8_t phase){return SignalPlay_Function(solfege,CONVEX, phase);}
uint8_t SignalPlay_SinusConvex(uint8_t solfege,uint8_t phase){return SignalPlay_FunctionConvex(solfege,SINUS, phase);}


//New
uint8_t SignalPlay_Explode(uint8_t solfege,uint8_t phase){return SignalPlay_FunctionOrder(solfege,COMPRESS,3, phase);}
uint8_t SignalPlay_Trip(uint8_t solfege,uint8_t phase){return SignalPlay_Function(solfege,TRIP, phase);}

uint8_t SignalPlay_ConcavOrder(uint8_t solfege, uint8_t order,uint8_t phase){return SignalPlay_FunctionOrder(solfege,CONCAV,order, phase);}

uint8_t SignalPlay_TripConcave(uint8_t solfege, uint8_t order, uint8_t phase)
{
  Signal s;
  memset(&s,0,sizeof(Signal));
  SignalPreset_FunctionDouble(&s, solfege, TRIP, CONCAV, order, false, phase);
  Signal_ExecuteSolfege(&s);
  return s.val;
}


//USER+
//Add here your new SignalPlay_Functions()...

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
