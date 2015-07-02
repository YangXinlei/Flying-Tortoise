#include "Tortoise.h"

USING_NS_CC;

// on "init" you need to initialize your instance
bool Tortoise::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//tortoise sprite
	tor = Sprite::create("Wings.png");
	tor->setTag(5);
	tor->setAnchorPoint(Vec2(0, 0));

	//physics
	auto pb = PhysicsBody::createBox(Size(100, 80), PhysicsMaterial(0.1f, 0, 0));
	pb->setGravityEnable(false);
	tor->setPhysicsBody(pb);


	Vector<SpriteFrame*> norAnimFrames;  norAnimFrames.reserve(3);
	norAnimFrames.pushBack(SpriteFrame::create("WingsUp.png", Rect(0, 0, 100, 100)));
	norAnimFrames.pushBack(SpriteFrame::create("Wings.png", Rect(0, 0, 100, 100)));
	norAnimFrames.pushBack(SpriteFrame::create("WingsDown.png", Rect(0, 0, 100, 100)));
	auto normalAnimation = Animation::createWithSpriteFrames(norAnimFrames, 0.2f);
	normalAnimate = Animate::create(normalAnimation);
	normalAnimate->setTag(2);



	Director::getInstance()->getActionManager()->addAction(normalAnimate, tor, false);

	tor->runAction(RepeatForever::create(static_cast<ActionInterval*>(Director::getInstance()->getActionManager()->getActionByTag(2, tor))));
	
	this->addChild(tor);

    return true;
}

void Tortoise::onFlyUp()
{
	Director::getInstance()->getActionManager()->pauseTarget(tor);

	Vector<SpriteFrame*> flyUpAnimFrames;
	flyUpAnimFrames.pushBack(SpriteFrame::create("WingsUp.png", Rect(0, 0, 100, 100)));
	flyUpAnimFrames.pushBack(SpriteFrame::create("WingsDown.png", Rect(0, 0, 100, 100)));
	auto flyUpAnimation = Animation::createWithSpriteFrames(flyUpAnimFrames, 0.1f);
	flyUpAnimate = Animate::create(flyUpAnimation);

	tor->runAction(flyUpAnimate);


	Director::getInstance()->getActionManager()->resumeTarget(tor);

}