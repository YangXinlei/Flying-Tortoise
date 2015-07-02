#include "Background.h"
#include "BlueScene.h"

USING_NS_CC;

float Background::bg1StartPosX = 0.0f;
// on "init" you need to initialize your instance
bool Background::init()
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
	bgLayer = LayerColor::create(Color4B(0x23, 0x23, 0xff, 0xff), visibleSize.width, visibleSize.height);
	bgLayer->setAnchorPoint(Vec2(0, 0));
	bgLayer->setPosition(Vec2(0, 0));
	
	bg1 = Sprite::create("bg.png");
	bg1->setAnchorPoint(Vec2(0, 0));
	bg1->setPosition(Vec2(0, 0));
	
	bg2 = Sprite::create("bg.png");
	bg2->setAnchorPoint(Vec2(0, 0));
	bg2->setPosition(Vec2(bg1->getContentSize().width, 0));
	bgLayer->addChild(bg1, 0);
	bgLayer->addChild(bg2, 0);

	this->addChild(bgLayer, 0);
	scheduleUpdate();
    return true;
}

void Background::update(float t)
{
	bg1->setPosition(Vec2(bg1->getPositionX() - BlueScene::theSpeed, 0));
	bg2->setPosition(Vec2(bg2->getPositionX() - BlueScene::theSpeed, 0));

	if (bg1->getPositionX() <= 0)
	{
		bg2->setPosition(Vec2(bg1->getPositionX() + bg1->getContentSize().width, 0));
	}
	if (bg2->getPositionX() <= 0)
	{
		bg1->setPosition(Vec2(bg2->getPositionX() + bg2->getContentSize().width, 0));
	}

	bg1StartPosX = bg1->getPositionX();
}

void Background::onSpeedUp()
{

}

void Background::onFlyUp()
{
	BlueScene::fallingSpeed = 0;
	float oldSpeed = BlueScene::theSpeed;
	BlueScene::theSpeed = 0;

	auto moveBackward = MoveBy::create(0.5, Vec2(-50, 0));
	auto easingMove = EaseOut::create(moveBackward->clone(), 0.6);

	bg1->runAction(easingMove);
	bg2->runAction(easingMove->clone());

	BlueScene::theSpeed = oldSpeed;
	BlueScene::fallingSpeed = BlueScene::FALLSPEED;
}