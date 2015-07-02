#include "MyMenu.h"
#include "BlueScene.h"
#include "HelloWorldScene.h"

USING_NS_CC;

Menu* MyMenu::CreateMenu()
{
	//create menu
	auto MenuItem_Game = MenuItemFont::create("Start Game");
	MenuItem_Game->setCallback([&](Ref *sender) {
		Director::getInstance()->replaceScene(TransitionFlipX::create(1, BlueScene::createScene()));
	});
	auto MenuItem_About = MenuItemFont::create("About");
	MenuItem_About->setCallback([&](Ref *sender) {
		//Director::getInstance()->replaceScene(TransitionFlipX::create(1, AboutScene::createScene()));
	});
	auto MenuItem_Exit = MenuItemFont::create("Exit");
	MenuItem_Exit->setCallback([&](Ref *sender) {
		menuCloseCallback(sender);
	});

	Vector<MenuItem*> items;
	items.pushBack(MenuItem_Game); items.pushBack(MenuItem_About); items.pushBack(MenuItem_Exit);

	auto menu = Menu::createWithArray(items);
	menu->alignItemsVerticallyWithPadding(20);

	return menu;
}

void MyMenu::menuCloseCallback(Ref* pSender)
{
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}