#ifndef __TORTOISE_H__
#define __TORTOISE_H__

#include "cocos2d.h"

class Tortoise : public cocos2d::Layer
{
public:

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
	void onFlyUp();

    // implement the "static create()" method manually
    CREATE_FUNC(Tortoise);

private:
	cocos2d::Sprite* tor;

	cocos2d::Animate *normalAnimate, *flyUpAnimate, *slowDownAnimate, *diveAnimate;
};


#endif