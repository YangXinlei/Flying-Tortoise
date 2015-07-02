#ifndef __EGG_SCENE_H__
#define __EGG_SCENE_H__

#include "cocos2d.h"

class Egg : public cocos2d::Layer
{
public:

	static cocos2d::Layer* createEggWithShape(int shapeCode);
	static cocos2d::Layer* createLinearEggs(int eggNum);
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
	void onEnter();
    // implement the "static create()" method manually
	CREATE_FUNC(Egg);
};


#endif // __HELLOWORLD_SCENE_H__
