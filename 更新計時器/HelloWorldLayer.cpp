#include "HelloWorldLayer.h"

USING_NS_CC;


bool HelloWorldLayer::init()
{
    if (!Layer::init())
    {
        return false;
    }


    auto* dispatcher = Director::getInstance()->getEventDispatcher();
    auto* keyListener = EventListenerKeyboard::create(); //Áä½LÄ²µo
    keyListener->onKeyPressed = CC_CALLBACK_2(HelloWorldLayer::onKeyPressed, this);
    keyListener->onKeyReleased = CC_CALLBACK_2(HelloWorldLayer::onKeyReleased, this);
    dispatcher->addEventListenerWithSceneGraphPriority(keyListener, this);

    this->scheduleUpdate();

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
        animate[i] = Animate::create(animation[i]);
        animate[i]->retain();
    }

    return true;
}

void HelloWorldLayer::update(float delta)
{
    Vec2 currentPos = sprite->getPosition();
    sprite->setPosition(currentPos.x + sprite_velocity_x, currentPos.y + sprite_velocity_y);
}

void HelloWorldLayer::onKeyPressed(EventKeyboard::KeyCode keycode, Event* event)
{
    switch (keycode)
    {
    case EventKeyboard::KeyCode::KEY_UP_ARROW:
        sprite->stopAllActions();
        sprite->runAction(animate[UP]);
        sprite_velocity_y += 1;
        break;
    case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
        sprite->stopAllActions();
        sprite->runAction(animate[DOWN]);
        sprite_velocity_y += -1;
        break;
    case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
        sprite->stopAllActions();
        sprite->runAction(animate[RIGHT]);
        sprite_velocity_x += 1;
        break;
    case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
        sprite->stopAllActions();
        sprite->runAction(animate[LEFT]);
        sprite_velocity_x += -1;
        break;
    }
}

void HelloWorldLayer::onKeyReleased(EventKeyboard::KeyCode keycode, Event* event)
{
    switch (keycode)
    {
    case EventKeyboard::KeyCode::KEY_UP_ARROW:
        sprite_velocity_y -= 1;
        break;
    case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
        sprite_velocity_y -= -1;
        break;
    case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
        sprite_velocity_x -= 1;
        break;
    case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
        sprite_velocity_x -= -1;
        break;


    case EventKeyboard::KeyCode::KEY_ESCAPE:
        Director::getInstance()->end();
        break;
    }
}