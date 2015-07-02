#ifndef __Backgournd_H__
#define __Backgournd_H__

#include "cocos2d.h"

class Background : public cocos2d::Layer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
	void update(float t);

	void onSpeedUp();
	void onFlyUp();
    
    // implement the "static create()" method manually
    CREATE_FUNC(Background);

	static float bg1StartPosX;
private:
	cocos2d::Sprite* bg1, *bg2;
	cocos2d::LayerColor* bgLayer;
};

#endif 
