#ifndef __MYMENU_H__
#define __MYMENU_H__

#include "cocos2d.h"

class MyMenu
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Menu* CreateMenu();

	// a selector callback
	static void menuCloseCallback(cocos2d::Ref* pSender);
};

#endif // __HELLOWORLD_SCENE_H__
