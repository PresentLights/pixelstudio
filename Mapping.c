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
           |              \       |               Mapping.c              |      /                   |
           |               \      |                                      |     /                    |
           |               /      |______________________________________|     \                    |
           |              /__________)                                (_________\                   |
           |                                                                                        |
           |           This section permit you to configure your own physical ledstrips structure   |
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



#include "BTP.h"
#include "Mapping.h"
#include "Program.h"
#include "PixelStudio.h"

/********************************************************************
                               GLOBAL VAR
                         __(.)< __(.)> __(.)=
                         \___)  \___)  \___) hjw
**********************************O*********************************/

//Global shared objets
extern BTP btp;
extern ProgramManager pm;
extern PixelStudio ps;
MappingManager mm;


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
//Configuration of each strip (one by output pin)
void Strip_Init(LedStrip *strip, uint8_t address,uint16_t nb,Color *buffer) 
{
  strip->address = address;
  strip->nb = nb;
  strip->buffer = buffer;
}

//Configuration of strip subdivision
//Each strip can be splited in many diferents fragments
//Two fragments can be surimposed (diversity of mappings)
void Strip_FragmentInit(LedFragment *frag, LedStrip *strip, uint16_t start, uint16_t nbPixels, char reverse) 
{
  frag->strip = strip;
  frag->start = start;
  frag->nbPixels = nbPixels;
  frag->reverse = reverse;
}

//Configuration of subdivision merge
//One LedMap (painting output) is composed by a number of fragments
void Strip_LedMapInit(LedMap *map, LedFragment *fragments, uint16_t nbFragments) 
{
  map->fragments = fragments;
  map->nbFragments = nbFragments;
  map->nbPixels = 0;
  int i;
  for(i=0;i<nbFragments;i++)
    map->nbPixels +=  fragments[i].nbPixels;
}


void Mapping_InitUniverse(uint8_t address, uint8_t barLength) 
{
  Universe *uni = &mm.universes[address];
  Strip_Init(&uni->strip, address, STRIP_BAR_NB_LEDS_MAX, uni->stripBuffer);
  Strip_FragmentInit(&uni->Frag_Bar1, &uni->strip, barLength-1, barLength, true); //Reversed = true to have the zero at the bottom
  Strip_FragmentInit(&uni->Frag_Bar2, &uni->strip, barLength*2-1, barLength, true);
  Strip_FragmentInit(&uni->Frag_Bar3, &uni->strip, barLength*3-1, barLength, true);
  Strip_FragmentInit(&uni->Frag_Bar4, &uni->strip, barLength*4-1, barLength, true);

  //flat mapping 1:1
  Strip_LedMapInit(&uni->Map_Bar1,  &uni->Frag_Bar1, 1); 
  Strip_LedMapInit(&uni->Map_Bar2,  &uni->Frag_Bar2, 1); 
  Strip_LedMapInit(&uni->Map_Bar3,  &uni->Frag_Bar3, 1); 
  Strip_LedMapInit(&uni->Map_Bar4,  &uni->Frag_Bar4, 1); 
}

//Configure your physical led strip structure
//this example is very simple and doesn't demonstrate the complexity of possibles mappings (see others examples like "le prestige infini")
void Mapping_Setup() 
{
  //Bar Length Binary configuration 0= 1m / 1=1,5m
  if (ps.mappingPreset & 1)
    Mapping_InitUniverse(0,42); 
  else
    Mapping_InitUniverse(0,28); 
    
  if (ps.mappingPreset & 2)
    Mapping_InitUniverse(1,42); 
  else
    Mapping_InitUniverse(1,28); 
    
  if (ps.mappingPreset & 4)
    Mapping_InitUniverse(2,42); 
  else
    Mapping_InitUniverse(2,28); 
  
  Layers_SetSize(42);
  
}

/********************************************************************
                        MAPPING PRESETS - PATCH
                            .--.
                           |.__.|
                           ||||||
                          /      \
                          `.__|_.'
********************************************************************/
//Switch led bars according to the current dices (randomized chain)
LedMap *LedMap_GetFromDices(uint8_t numBar)
{
  uint8_t disorderIndex = btp.dices4[numBar-1];
//  uint8_t disorderIndex = numBar-1;  //Bypass, return correct numBar for tests
  switch(disorderIndex)
  {
    case 0: return &mm.currentUniverse->Map_Bar1;
    case 1: return &mm.currentUniverse->Map_Bar2;
    case 2: return &mm.currentUniverse->Map_Bar3;
    case 3: return &mm.currentUniverse->Map_Bar4;
  }
  return 0;
}


//These following functions are called by the compositions programs
//This function is usefull to limit the code and preset Mapping* objects
//Each Mapping is composed by a number of LedMap, it will paint the same pattern in each of them even if their sizes difers
void Mapping_Preset(Mapping *m, uint8_t preset)
{
  switch(preset)
  {
    case MAP_BAR_1: 
      m->nbMaps = 1;
      m->maps[0] = LedMap_GetFromDices(1);
      break;

    case MAP_BAR_2:
      m->nbMaps = 1;
      m->maps[0] = LedMap_GetFromDices(2);
      break;

    case MAP_BAR_3:
      m->nbMaps = 1;
      m->maps[0] = LedMap_GetFromDices(3);
      break;

    case MAP_BAR_4:
      m->nbMaps = 1;
      m->maps[0] = LedMap_GetFromDices(4);
      break;

    case MAP_BAR_ODD:
      m->nbMaps = 2;
      m->maps[0] = LedMap_GetFromDices(2);
      m->maps[1] = LedMap_GetFromDices(4);
      break;

    case MAP_BAR_EVEN:
      m->nbMaps = 2;
      m->maps[0] = LedMap_GetFromDices(1);
      m->maps[1] = LedMap_GetFromDices(3);
      break;

    case MAP_BAR_LEFT:
      m->nbMaps = 2;
      m->maps[0] = LedMap_GetFromDices(1);
      m->maps[1] = LedMap_GetFromDices(2);
      break;

    case MAP_BAR_RIGHT:
      m->nbMaps = 2;
      m->maps[0] = LedMap_GetFromDices(3);
      m->maps[1] = LedMap_GetFromDices(4);
      break;

    case MAP_BAR_CENTER:
      m->nbMaps = 2;
      m->maps[0] = LedMap_GetFromDices(2);
      m->maps[1] = LedMap_GetFromDices(3);
      break;

    case MAP_BAR_EXT:
      m->nbMaps = 2;
      m->maps[0] = LedMap_GetFromDices(1);
      m->maps[1] = LedMap_GetFromDices(4);
      break;

    case MAP_BAR_ALL:
      m->nbMaps = 4;
      m->maps[0] = LedMap_GetFromDices(1);
      m->maps[1] = LedMap_GetFromDices(2);
      m->maps[2] = LedMap_GetFromDices(3);
      m->maps[3] = LedMap_GetFromDices(4);
      break;

  }
}



uint8_t Mapping_FromID(uint8_t mappingID)
{
  switch (mappingID)
  {
    case 0: return MAP_BAR_1;
    case 1: return MAP_BAR_2;
    case 2: return MAP_BAR_3;
    case 3: return MAP_BAR_4;
  }
  return 0;
}

//Return randomly one of these 4 preset
uint8_t Mapping_GetRandomPreset()
{
  uint16_t rnd = GetRandom(4);
  return Mapping_FromID(rnd);
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

//Clear strip output buffer (every frame)
void Mapping_ClearStrip(LedStrip *strip)
{
    Color *writeBuffer = strip->buffer;    
    int i;
    for(i=0;i<strip->nb;i++)
        writeBuffer[i] = BLACK;
}

//Scale a byte position to the size of the map
float Mapping_MapBound(uint8_t x, LedMap *map)
{
  uint16_t nb = map->nbPixels;
  return MapBoundFloat(x,0,255,0,nb);
}


/********************************************************************
                       MAP
                    ________
                   /\       \
                  /  \       \
                 /    \       \
                /      \_______\
                \      /       /
              ___\    /   ____/___
             /\   \  /   /\       \
            /  \   \/___/  \       \
           /    \       \   \       \
          /      \_______\   \_______\
          \      /       /   /       /
           \    /       /   /       /
            \  /       /\  /       /
             \/_______/  \/_______/   logico 

********************************************************************/

//Do the mapping job...
//Project a color to a position on a LedMap

void Mapping_Pixel(float pos, Color color, LedMap *map)
{
  uint16_t nb = map->nbPixels;
  if (pos>=nb) return;
  int readPtr=0;
  int fragIndex;
  for(fragIndex=0;fragIndex<map->nbFragments;fragIndex++)
  {
    LedFragment *frag = &map->fragments[fragIndex];
    LedStrip *strip = frag->strip;
    Color *writeBuffer = strip->buffer;    
    int i;
    int writePtr= frag->start;
    for(i=0;i<frag->nbPixels;i++)
    {
      if (pos == readPtr)
        writeBuffer[writePtr] = color;
        
      if (frag->reverse)
        writePtr--;
      else
        writePtr++;
      if (writePtr<0)
        writePtr+=strip->nb;
      writePtr%=strip->nb;
      readPtr++;
      readPtr %= nb;
    }
  }
}

/******************************************************************
                        PAINT
                        _____          /|
                     .-'@ & #`'-.     //
                    / %        8 \   //
                   | m   () _     | //
                    \  0   ( '-._/ //
              jgs    '-.____'.     y 
********************************************************************/
//These following functions are called by your programs compositions (Program.c)


//Project a color to a byte position on a Mapping
void Paint_Plot(uint8_t x, Color color, Mapping *m)
{
  int i;
  for(i=0;i<m->nbMaps;i++)
  {
    LedMap *map = m->maps[i];
    float pos = Mapping_MapBound(x, map);
    Mapping_Pixel(pos,color, map);
  }
}



//Project a beam from byte x0 to byte x1 on a Mapping
void Paint_Bean(uint8_t x0,uint8_t x1, Color color, Mapping *m)
{
  int i,j;
  for(i=0;i<m->nbMaps;i++)
  {
    LedMap *map = m->maps[i];
    float pos0 = Mapping_MapBound(x0, map);
    float pos1 = Mapping_MapBound(x1, map);
    if (pos0 < pos1)
      for(j=pos0;j<pos1;j++)
          Mapping_Pixel(j,color, map);
    else
      for(j=pos1;j<pos0;j++)
          Mapping_Pixel(j,color, map);
  }
}

//Paint a full degrade from color c1 to color c2 on a mapping
void Paint_Degrade(Color c1,Color c2, Mapping *m)
{
  int i,j;
  for(i=0;i<m->nbMaps;i++)
  {
    LedMap *map = m->maps[i];
    int nb = map->nbPixels;
    for(j=0;j<nb;j++)
    {
      float f = (float)j/nb;
      Color color = Color_Degrade(c1, c2, f);
      color = Color_Brightness(color,0.2);
      Mapping_Pixel(j,color, map);
    }
  }
}


void Layers_Clear()
{
  int i,j,k;
  for (k=0;k<NB_UNIVERSES;k++)
  {
    Universe *uni = &mm.universes[k];
    for (i=0;i<NB_LAYERS;i++)
    {
      Layer *l = &uni->layers[i];
      l->lastPos = -1; //first frame
      l->rndScale = 0;
      l->rndFlash = 0;
      l->rndBurn = 0;
      l->rndColor = 0;
      
      for (j=0;j<l->nbPoints;j++)
      {
        LayerPixel *pix = &l->pixels[j];
        pix->color = BLACK;
        pix->scale = 0;
        pix->active = false;
          
      }
    }
  }
}

void Layers_SetScale(uint8_t scale)
{
  int i,k;
  for (k=0;k<NB_UNIVERSES;k++)
  {
    Universe *uni = &mm.universes[k];
    for (i=0;i<NB_LAYERS;i++)
    {
      Layer *l = &uni->layers[i];
      l->scale = scale;
    }
  }
}

void Layers_SetSize(uint8_t nbPoints)
{
  int i,k;
  for (k=0;k<NB_UNIVERSES;k++)
  {
    Universe *uni = &mm.universes[k];
    for (i=0;i<NB_LAYERS;i++)
    {
      Layer *l = &uni->layers[i];
      l->nbPoints = nbPoints;
    }
  }
}
  
void Layers_SetRandomize(uint8_t rndScale, uint8_t rndFlash, uint8_t rndBurn, uint8_t rndColor)
{
  int i;
  for (i=0;i<NB_LAYERS;i++)
  {
    Layer *l = &mm.currentUniverse->layers[i];
    l->rndScale = rndScale;
    l->rndFlash = rndFlash;
    l->rndBurn = rndBurn;
    l->rndColor = rndColor;
  }
}


void LayerEffect_Degrade(Layer *layer, LayerPixel *pix, float e)
{
  uint8_t x = (uint8_t)e*256;
  uint8_t y = Signal_Compress(x, true);
  float intens = (float)y / 255;
  Color c1 = BTP_GetColor(layer->colorID);
  Color c2 = BTP_GetColor((layer->colorID + 1)%4);
  Color color = Color_Degrade(c1, c2, e);
  pix->color = Color_Brightness(color, intens);
}



void LayerEffect_Persist(Layer *layer, LayerPixel *pix, float e)
{
  uint8_t x = (uint8_t)(e*256);
 // uint8_t y = 255-Signal_Expand(x);
  float intens = 1.0-e;//-(float)y / 255;
  
  pix->color = Color_Brightness(pix->stampColor, intens);
}


void LayerEffect_Sparks(Layer *layer, LayerPixel *pix, float e)
{
  uint8_t x = (uint8_t)(e*256);
 // uint8_t y = 255-Signal_Expand(x);
  float intens = 1.0-e;//-(float)y / 255;


  Color color = pix->stampColor;
  if (layer->rndColor)
    color = Color_RandomMove(color, layer->rndColor);


  char on = true;
    
  if (layer->rndFlash)
  {
    uint8_t sparkScale = (uint8_t)(e*layer->rndFlash);
    uint8_t sparkRnd = GetRandom(sparkScale);
    if (sparkRnd != 0)
      on = false;
  }
  
  pix->color = BLACK;
  if (on)
    pix->color = Color_Brightness(color, intens);
  
  if (layer->rndBurn)
  {
    uint8_t burnRnd = GetRandom(layer->rndBurn);
    if (burnRnd == 0)
      pix->sync = btp.sync;
  }
}

void Layer_ExecutePersist(Layer *layer)
{
  int i;
  for (i=0;i<layer->nbPoints;i++)
  {
    LayerPixel *pix = &layer->pixels[i];
    
    if (pix->active)
    {
      int16_t deltaTime =  btp.sync - pix->sync;
      if (deltaTime < 0)
        deltaTime+=256;

      uint8_t scale = layer->scale;
      if (pix->scale > 0)
        scale = pix->scale;
        
      float e = MapFloat(deltaTime,0,scale,0,1);
      if (e>=0 && e<1)
      {
        switch (layer->effect)
        {
          case LAYER_EFFECT_PERSIST: LayerEffect_Persist(layer, pix, e); break;
            
          case LAYER_EFFECT_DEGRADE: LayerEffect_Degrade(layer, pix, e); break;            
          case LAYER_EFFECT_SPARKS: LayerEffect_Sparks(layer, pix, e); break;
        }
      }
      else
      {
        pix->color = BLACK;
        pix->active = false;
      } 
    }
  }
}


void Layer_PaintPersist(Layer *layer, Mapping *m)
{
  int i,j;
  for(i=0;i<m->nbMaps;i++)
  {
    LedMap *map = m->maps[i];
    for(j=0;j<layer->nbPoints;j++)
    {
      LayerPixel *pix = &layer->pixels[j];
      int16_t pos = (int16_t)MapFloat(j,0,layer->nbPoints,0,map->nbPixels);
      if (pix->active)
        Mapping_Pixel(pos,pix->color, map);
    }
  }
}


void Layer_FeedPersist(Layer *layer, uint8_t x, Color color, char fill)
{
  int16_t pointPos = (int16_t) MapFloat(x, 0,256,0,layer->nbPoints);

  LayerPixel *pix;
  int i;
  if (layer->scale == 0)
  {
    for(i=0;i<layer->nbPoints;i++)
    {
      pix = &layer->pixels[i];
      pix->color = BLACK;
      pix->active = false;
    }
  }
  
  pix = &layer->pixels[pointPos];
  pix->color = color;
  pix->stampColor = color; //Save original color
  pix->sync = btp.sync;
  pix->active = true;
        
  if (layer->lastPos != -1 && fill)//not first frame
  {
    int16_t delta = pointPos - layer->lastPos;
    uint8_t halfLength = layer->nbPoints >> 1;
    if (delta < -halfLength)
      delta += layer->nbPoints;
        
    if (delta > halfLength)
      delta -= layer->nbPoints;
        
    uint8_t distance = abs(delta);
    int step = 1;
      if (delta<0)
        step = -1;
          
    uint8_t pos = layer->lastPos;
    
    for(i=0;i<distance;i++)
    {
      pos += step;
      if (pos >= 0 && pos < layer->nbPoints)//  && i%2)
      {
        pix = &layer->pixels[pos];
        pix->color = color;
        pix->stampColor = color; //Save original color
        pix->sync = btp.sync;
        pix->active = true;

        switch (layer->effect)
        {
          case LAYER_EFFECT_PERSIST: 
            break;
            
          case LAYER_EFFECT_DEGRADE: 
            break;            
          case LAYER_EFFECT_SPARKS: 
            
            break;
        }

        if (layer->rndScale)
          pix->scale = GetRandom(layer->rndScale)+layer->scale;
 
      }
    }
  }
  layer->lastPos = pointPos; //filling memory
}


void Paint_PlotPersist(uint8_t x, uint8_t colorID, Mapping *m, Layer *layer)
{
  //Init Effect
  layer->effect = LAYER_EFFECT_PERSIST;

  layer->colorID = colorID;
  Color color = BTP_GetColor(colorID);
  Layer_FeedPersist(layer, x, color, true);
  Layer_PaintPersist(layer, m);
  Layer_ExecutePersist(layer);
}


void Paint_PlotSparks(uint8_t x, uint8_t colorID, Mapping *m, Layer *layer)
{
  //Init Effect
  layer->effect = LAYER_EFFECT_SPARKS;

  
  layer->colorID = colorID;
  Color color = BTP_GetColor(colorID);
  Layer_FeedPersist(layer, x, color, true);
  Layer_PaintPersist(layer, m);
  Layer_ExecutePersist(layer);
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
