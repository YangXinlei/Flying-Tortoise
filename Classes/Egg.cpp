#include "Egg.h"

USING_NS_CC;

// on "init" you need to initialize your instance
bool Egg::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto egg = Sprite::create("egg.png");
	egg->setAnchorPoint(Vec2(0, 0));
	egg->setPosition(0, 0);
	egg->setName("egg");

	////physics
	auto pb = PhysicsBody::createBox(Size(25, 35));
	pb->setDynamic(true);
	pb->setGroup(-1);
	pb->setGravityEnable(false);
	
	egg->setPhysicsBody(pb);

	this->addChild(egg);

    return true;
}
void Egg::onEnter()
{
	Layer::onEnter();
	this->getChildByName("egg")->setPosition(0, 0);
}

Layer* Egg::createLinearEggs(int n)
{
	Layer* rlt = Layer::create();

	for (int i = 0; i < n; ++i)
	{
		auto egg = Sprite::create("egg.png");
		egg->setAnchorPoint(Vec2(0, 0));
		////physics
		auto pb = PhysicsBody::createBox(Size(25, 35));
		pb->setDynamic(false);
		pb->setGroup(-1);
		pb->setGravityEnable(false);
		egg->setPhysicsBody(pb);

		egg->setPosition(i * (egg->getContentSize().width + 30), 0);
		egg->setName("egg" + Value(i).asString());
		rlt->addChild(egg);
	}

	return rlt;
}