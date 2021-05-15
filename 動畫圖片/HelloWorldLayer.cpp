#include "HelloWorldLayer.h"

USING_NS_CC;


bool HelloWorldLayer::init()
{
    auto* dispatcher = Director::getInstance()->getEventDispatcher();
    auto* keyListener = EventListenerKeyboard::create(); //Áä½LÄ²µo
    keyListener->onKeyPressed = CC_CALLBACK_2(HelloWorldLayer::onKeyPressed, this);
    keyListener->onKeyReleased = CC_CALLBACK_2(HelloWorldLayer::onKeyReleased, this);
    dispatcher->addEventListenerWithSceneGraphPriority(keyListener, this);


    Size visibleSize = Director::getInstance()->getVisibleSize();


    sprite = Sprite::create("hero_sheet.png", Rect(48 * 1, 64 * 2, 48, 64));
    sprite->setAnchorPoint(Point(0.5, 0.5));
    sprite->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
    this->addChild(sprite, 0);

    for (int i = 0; i < 4; i++)
    {
        animation[i] = cocos2d::Animation::create();
        for (int j = 0; j < 4; j++)
        {
            SpriteFrame* spriteframe = SpriteFrame::create("hero_sheet.png", Rect(48 * j, 64 * i, 48, 64));
            animation[i]->addSpriteFrame(spriteframe);
        }
        animation[i]->setDelayPerUnit(0.3);
        animation[i]->setLoops(-1);
    }

    animate[DOWN] = Animate::create(animation[DOWN]);
    RepeatForever* repeat = RepeatForever::create(animate[DOWN]);
    sprite->runAction(animate[DOWN]);

    return true;
}

void HelloWorldLayer::onKeyPressed(EventKeyboard::KeyCode keycode, Event* event)
{
    
    switch (keycode)
    {
    case EventKeyboard::KeyCode::KEY_UP_ARROW:
    {
        Size visibleSize = Director::getInstance()->getVisibleSize();
        auto moveTo = MoveTo::create(0, Vec2(visibleSize.width / 2, visibleSize.height / 4 * 3));
        sprite->runAction(moveTo);
        break;
    }
    case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
    {
        Size visibleSize = Director::getInstance()->getVisibleSize();
        auto moveTo = MoveTo::create(0, Vec2(visibleSize.width / 2, visibleSize.height / 4));
        sprite->runAction(moveTo);
        break;
    }
    case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
    {
        Size visibleSize = Director::getInstance()->getVisibleSize();
        auto moveTo = MoveTo::create(0, Vec2(visibleSize.width / 4*3, visibleSize.height / 2));
        sprite->runAction(moveTo);
        break;
    }
    case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
    {
        Size visibleSize = Director::getInstance()->getVisibleSize();
        auto moveTo = MoveTo::create(0, Vec2(visibleSize.width / 4, visibleSize.height / 2));
        sprite->runAction(moveTo);
        break;
    }
    }
}

void HelloWorldLayer::onKeyReleased(EventKeyboard::KeyCode keycode, Event* event)
{
    switch (keycode)
    {
    case EventKeyboard::KeyCode::KEY_ESCAPE:
        Director::getInstance()->end();
        break;
    }
}