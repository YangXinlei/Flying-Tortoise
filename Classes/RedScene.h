#ifndef __RED_SCENE_H__
#define __RED_SCENE_H__

#include "cocos2d.h"

class RedScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

	// a selector callback
	static void CloseBtnCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(RedScene);


};


#endif // __HELLOWORLD_SCENE_H__
