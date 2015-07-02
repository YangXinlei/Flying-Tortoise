#ifndef __BLUE_SCENE_H__
#define __BLUE_SCENE_H__

#include "cocos2d.h"

class Background;	class Tortoise;
class BlueScene : public cocos2d::Layer
{
public:
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	void update(float t);
	void tFlyUp();


	bool onContactBegin(cocos2d::PhysicsContact& contact);



	// implement the "static create()" method manually
	CREATE_FUNC(BlueScene);
	
	static int score;
	static float theSpeed;
	const static float SPEED;
	static float fallingSpeed;
	const static float FALLSPEED, FALLOFFSET;
private:
	Background* bg;
	Tortoise* tor;
};
#endif // __HELLOWORLD_SCENE_H__
