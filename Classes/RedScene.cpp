#include "RedScene.h"
#include "ui/CocosGUI.h"
#include "MyMenu.h"
#include "HelloWorldScene.h"
#include <iostream>

USING_NS_CC;

Scene* RedScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = RedScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool RedScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//bg
	auto bgLayer = LayerColor::create(Color4B(0xcc, 0x23, 0x66, 0xff), visibleSize.width, visibleSize.height);
	this->addChild(bgLayer, -1);
	//menu
	this->addChild(MyMenu::CreateMenu(), 1);
	auto closeBtn = ui::Button::create("CloseNormal.png", "CloseSelected.png");
	closeBtn->setPosition(Vec2(visibleSize.width - closeBtn->getSize().width, 0));
	closeBtn->setAnchorPoint(Vec2(0, 0));
	closeBtn->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
			CloseBtnCallback(sender);	
			break;
		default:
			break;
		}
	});
	this->addChild(closeBtn, 2);

    return true;
}

void RedScene::CloseBtnCallback(Ref* pSender)
{
	Director::getInstance()->replaceScene(TransitionFlipX::create(1, HelloWorld::createScene(), TransitionScene::Orientation::RIGHT_OVER) );
}