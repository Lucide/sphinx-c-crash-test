/**
 * @file
 * @brief The VisualT header.
 */

#pragma once
#ifndef VISUALT_INCLUDE_VISUALT_VISUALT_H_
#define VISUALT_INCLUDE_VISUALT_VISUALT_H_

#include <stdbool.h>
#include <stdint.h>

/**
 * @brief Represents a UTF8-encoded read-only codepoint.
 *
 * This is what the API expects when passing a single UTF8-encoded codepoint. Like in @b LINK @n
 * Being a fully UTF8 compatible library, VisualT stores UTF8 encoded characters in 4 Bytes @c uint32_t variables.
 */
typedef uint32_t VTChar;

/**
 * @brief A pointer to a UTF8-encoded read-only string.
 *
 * This is what the API expects when passing an UTF8-encoded string. Like in @b LINK @n
 * It's just an alias that makes things easier to read.
 */
typedef uint8_t const *VTStr;

/**
 * @brief A pointer to a read-only array of VTStr.
 *
 * This is what the API expects when passing an array of UTF8-encoded strings. Like in @b LINK
 */
typedef uint8_t const *const *VTStrs;

/**
 * @brief A pointer to a read-only pair of positive integers.
 *
 * This is what the API expects when passing the size of something. Like in @ft :func:`vtInitializeBlank` @nf.
 */
typedef unsigned int const (*VTSizes)[2];

/**
 * @brief A pointer to a read-only array of read-only Objects.
 *
 * This is what the API expects when passing an array of Objects. Like in @b LINK
 */
typedef struct vtObj const *const *VTObjs;

/**
 * @brief A helper macro to cast a literal glyph to a VTChar.
 * @code
 * vtFill(&obj, LTCHAR"↺");
 * @endcode
 */
#define LTCHAR *(VTChar *const)

/**
 * @brief A helper macro to cast a literal string to VTStr.
 * @code
 * vtSetText(&obj, LTSTR"hello world");
 * @endcode
 */
#define LTSTR (VTStr)

/**
 * @brief A helper macro to cast a literal array of strings to VTStrs.
 *
 * The main use case is when you want to initialize an Object from one or more literal strings:
 * @code
 * vtInitializeString(&obj, 3, LTSTRS{"spriteA","spriteB","spriteC"});
 * @endcode
 */
#define LTSTRS (VTStrs)(char const *const [])

/**
 * @brief A helper macro to cast a literal array of integer pairs to VTSizes.
 *
 * The main use case is when you want to initialize a blank Object given its sprites sizes:
 * @code
 * vtInitializeBlank(&canvas, 2, LTSIZES{{10, 5},{5, 10}});
 * @endcode
 */
#define LTSIZES (VTSizes)(unsigned const int [][2])

/**
 * @brief A helper macro to cast a literal array of Objects to VTObjs.
 *
 * The main use case is when you want to render a group of Objects:
 * @code
 * vtRender(&canvas, 3, LTOBJS{&objA, &objB, &objC});
 * @endcode
 */
#define LTOBJS (VTObjs)(struct vtObj const *const [])

struct vtCharMap {
	VTChar *chars;
	unsigned int width, height;
};

struct vtObj {
	struct vtCharMap *sprites, *currentSprite;
	VTChar penChar;
	int x, y;
	unsigned int length;
	unsigned short penSize;
	bool visible;
};

//----MISC----
/**
 * @brief Prints info about VisualT.
 *
 * Prints the @b version, <b>build date</b>, and <b>GitHub website</b>
 */
void vtAbout();

/**
 * @brief Initializes  @p obj to a blank Object with @p sizesLength Sprites of @p sizes size.
 * @param obj the Object to initialize
 * @param sizesLength the length of @p sizes, equivalent to the number of Sprites
 * @param sizes an array of pairs, each pair represent the dimension of a sprite
 *
 *
 */
void vtInitializeBlank(struct vtObj *obj, unsigned int sizesLength, VTSizes sizes);
void vtInitializeArray(struct vtObj *obj, VTChar const *v);
void vtInitializeFile(struct vtObj *obj, char const *path);
void vtInitializeString(struct vtObj *obj, unsigned int utf8StringsLength, VTStrs utf8Strings);
void vtInitializeObj(struct vtObj *obj, struct vtObj const *src);
void vtRelease(unsigned int objsLength, VTObjs objs);
void vtCloneSprite(struct vtObj const *dest, unsigned int spriteDest, struct vtObj const *src, unsigned int spriteSrc);
void vtResize(struct vtObj *obj, unsigned int width, unsigned int height);
//----REFRESH----
void vtRender(struct vtObj const *canvas, unsigned int objsLength, VTObjs objs);
void vtStamp(struct vtObj const *canvas, unsigned int objsLength, VTObjs objs);
void vtPrint(struct vtObj const *canvas, bool border);
unsigned int vtPrintToString(struct vtObj const *canvas, bool border, uint8_t **utf8String);
//----SPRITE----
unsigned int vtSprites(struct vtObj const *obj);
unsigned int vtSpriteInd(struct vtObj const *obj);
void vtNextSprite(struct vtObj *obj);
void vtPrecSprite(struct vtObj *obj);
void vtSetSprite(struct vtObj *obj, unsigned int sprite);
unsigned int vtWidth(struct vtObj const *obj);
unsigned int vtHeight(struct vtObj const *obj);
void vtSetText(struct vtObj *obj, VTStr utf8Text);
void vtClear(struct vtObj const *canvas);
void vtFill(struct vtObj const *canvas, VTChar fillChar);
void vtOverlay(struct vtObj const *dest, unsigned int spriteDest, struct vtObj const *src, unsigned int spriteSrc);
void vtPrintAxes(struct vtObj const *canvas);
//----OBJ----
bool vtVisible(struct vtObj const *obj);
void vtShow(struct vtObj *obj);
void vtHide(struct vtObj *obj);
void vtSetVisibility(struct vtObj *obj, bool visible);
//----PEN----
VTChar vtPenChar(struct vtObj const *obj);
unsigned short vtPenSize(struct vtObj const *obj);
void vtSetPenSize(struct vtObj *obj, unsigned short size);
void vtSetPenChar(struct vtObj *obj, VTChar penChar);
//----MOVE----
int vtXPosition(struct vtObj const *obj);
int vtYPosition(struct vtObj const *obj);
void vtGotoXY(struct vtObj const *canvas, struct vtObj *obj, int x, int y);
void vtGotoX(struct vtObj const *canvas, struct vtObj *obj, int x);
void vtGotoY(struct vtObj const *canvas, struct vtObj *obj, int y);
void vtChangeX(struct vtObj const *canvas, struct vtObj *obj, int x);
void vtChangeY(struct vtObj const *canvas, struct vtObj *obj, int y);
void vtAlign(struct vtObj *obj, unsigned char position);
bool vtIsTouching(struct vtObj const *canvas, struct vtObj const *obj, unsigned int objsLength, VTObjs objs);
bool vtIsTouchingChar(struct vtObj const *canvas, struct vtObj const *obj, VTChar character);
bool vtIsOutside(struct vtObj const *canvas, struct vtObj const *obj);

#endif

//----MISC----

//to free a dynamic 2d array mna of width width

//----POINTERS----
//to refer to an Object's INDex
//to group "n" objects by passing their index
//to delete the data contained on a group; now you can reuse the group

//----GETTERS----
//to Get the Number of Objects loaded
//to Get the Object's INDex
//to Get the Object's NAME
//to Get the Object's Sprite Number
//to Get the Object's Sprite X size
//to Get the Object's Sprite Y size

//----INITIALIZATION----
//REQUIRED to initialize the library
//to load an Object
//to create a dynamic textbox
//to clone (reload) the Object
//to free all the memory allocated by the library

//----STAGE----
//to Get the STage Width
//to Get the STage Height
//to create/size a new stage
//to set the stage border visibility (enabled by default, for developers)

//----REFRESH----
//to render the scene
//to render to file
//to render to a printf() sequence, waiting for i milliseconds
//to move the cursor to a certain x y

//----TEXT----
//to change a textbox's content, works for every Object

//----LOOK----
//to Get the Object's current Sprite Number
//to Get the Object's VISIBILITY state
//to Get the Object's LAYER
//to show the Object
//to hide the Object
//to set the Object's visibility (1/0)
//to move the Object to the top layer
//to move the Object to the bottom layer
//to move the Object up a layer
//to move the Object down a layer
//to switch to the Object's next Sprite
//to switch to the Object's precedent Sprite
//to switch to the Object's n Sprite

//----PEN----
//to Get the Object's PEN state
//to Get the PEN CHaracter in use
//to Get the PEN SIZE
//to set the pen size
//to set the pen character
//to disable the Object's pen
//to enable the Object's pen
//to set the Object's pen (1/0)
//to stamp the Object on the pen layer
//to shift the pen layer by m direction m=0:left m=1:right m=2:top m=3:down
//to set the pen layer to a character
//to clear the pen layer

//----MOVE----
//to Get the Object's x position
//to Get the Object's y position
//to know if two Objects are touching  (d=0 to check for any Object)
//to know if the Object is touching a Character (d=0 to check for border)
//to move the Object to x y
//to move the Object to x
//to move the Object to y
//to change the Object's x position by x
//to change the Object's y position by y
//to move the Object's corner to his current position (useful with textboxes) m=0:top-left m=1:top-right m=2:bottom-left m=3:bottom-right

//----DEBUG----
//to show your program general status
//to show the status of all the loaded objects
//to show the oject's status
//to render x and y axes
