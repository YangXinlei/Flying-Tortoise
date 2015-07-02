#include "GameOverScene.h"
#include "ui/CocosGUI.h"
#include "BlueScene.h"
#include "MyMenu.h"

USING_NS_CC;

Scene* GameOverScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
	auto layer = GameOverScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameOverScene::init()
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
	auto bgLayer = LayerColor::create(Color4B(0x23, 0x23, 0x23, 0xff), visibleSize.width, visibleSize.height);
	this->addChild(bgLayer, -1);

	auto scoreLabel = Label::createWithTTF("Score: " + Value(BlueScene::score).asString(), "fonts/Marker Felt.ttf", 24);
	scoreLabel->setAnchorPoint(Vec2(1, 1));
	scoreLabel->setPosition(Vec2(visibleSize.width - 10, visibleSize.height - 10));
	this->addChild(scoreLabel);

	auto overLabel = Label::createWithTTF("Game Over!", "fonts/Marker Felt.ttf", 50);
	overLabel->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(overLabel);

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

void GameOverScene::CloseBtnCallback(Ref* pSender)
{
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}