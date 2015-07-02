#include "HelloWorldScene.h"
#include "MyMenu.h"

USING_NS_CC;
Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
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

	//std::string infoStr = Value(static_cast<int>(visibleSize.width)).asString() + " X " + Value(static_cast<int>(visibleSize.height)).asString();
	auto infoLabel = Label::createWithTTF("Flying Tortoise", "fonts/Marker Felt.ttf", 50);
	infoLabel->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 + 200) );
	this->addChild(infoLabel, 1);

	//menu
	this->addChild(MyMenu::CreateMenu(), 1);


    
    return true;
}

