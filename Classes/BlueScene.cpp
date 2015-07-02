#include "BlueScene.h"
#include "MyMenu.h"
#include "Background.h"
#include "GameOverScene.h"
#include "Tortoise.h"
#include "Egg.h"

USING_NS_CC;

int BlueScene::score = 0;
float BlueScene::theSpeed = 2.0f;
const float BlueScene::SPEED = 2.0f;
float BlueScene::fallingSpeed = 0.0f;
const float BlueScene::FALLSPEED = fallingSpeed;
const float BlueScene::FALLOFFSET = 0.02f;

Scene* BlueScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::createWithPhysics();
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);


	// 'layer' is an autorelease object
	auto layer = BlueScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool BlueScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}
	//static value init
	score = 0;
	fallingSpeed = FALLSPEED;
	theSpeed = SPEED;

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//bg
	auto bgLayer = LayerColor::create(Color4B(0x23, 0x23, 0xff, 0xff), visibleSize.width, visibleSize.height);
	this->addChild(bgLayer, -1);

	bg = Background::create();
	this->addChild(bg, -1);

	//score
	auto scoreLabel = Label::createWithTTF("Score: " + Value(BlueScene::score).asString(), "fonts/Marker Felt.ttf", 24);
	scoreLabel->setAnchorPoint(Vec2(1, 1));
	scoreLabel->setPosition(Vec2(visibleSize.width - 10, visibleSize.height - 10));
	this->addChild(scoreLabel);

	//tortoise
	tor = Tortoise::create();
	tor->setAnchorPoint(Vec2(0, 0));
	tor->setPosition(Vec2(visibleSize.width / 2 - 150, visibleSize.height / 2 + 300));
	this->addChild(tor, 1);

	//touch listener
	auto tl = EventListenerTouchOneByOne::create();
	tl->setSwallowTouches(false);
	tl->onTouchBegan = [this](Touch* touch, Event* event) {
		this->tFlyUp();

		return true;
	};
	tl->onTouchMoved = [](Touch* touch, Event* event) {

	};
	tl->onTouchEnded = [=](Touch* touch, Event* event) {

	};
	this->_eventDispatcher->addEventListenerWithFixedPriority(tl, -129);

	//eggs
	auto egg = Egg::create();
	egg->setName("egg");
	this->addChild(egg);

	//auto lineEggs = Egg::createLinearEggs(6);
	//lineEggs->setTag(10);
	//lineEggs->setPosition(Vec2(Background::bg1StartPosX + 1000, 300));
	//this->addChild(lineEggs);

	scheduleUpdate();
	return true;
}

void BlueScene::update(float t)
{
	tor->setPosition(Vec2(tor->getPositionX(), tor->getPositionY() - BlueScene::fallingSpeed));
	fallingSpeed += BlueScene::FALLOFFSET;

	if (tor->getPositionY() <= 0)
	{
		tor->getChildByTag(5)->stopAllActions();
		this->unscheduleUpdate();
		this->_eventDispatcher->removeAllEventListeners();
		
		Director::getInstance()->replaceScene(cocos2d::TransitionCrossFade::create(0.5, GameOverScene::createScene()) );
	}

	//this->getChildByTag(10)->setPosition(Vec2(Background::bg1StartPosX + 1000, getChildByTag(10)->getPositionY()));
	this->getChildByName("egg")->setPosition(Vec2(Background::bg1StartPosX + 1000, 500));
}

void BlueScene::tFlyUp()
{
	MoveBy* move;

	if (tor->getPositionY() > Director::getInstance()->getVisibleSize().height - tor->getChildByTag(5)->getContentSize().height)
		move = MoveBy::create(0.3, Vec2(0, 0));
	else 
		move = MoveBy::create(0.3, Vec2(0, 30));
	auto jump = EaseOut::create(move->clone(), 0.8f);

	tor->onFlyUp();
	tor->runAction(jump);

	bg->onFlyUp();
}

bool onContactBegin(PhysicsContact& contact)
{
	return true;
}