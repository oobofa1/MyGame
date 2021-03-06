//
//  Cannon.cpp
//  FishingJoy
//
//  Created by Ringo_D on 12-9-11.
//
//

#include "CannonLayer.h"
#include "StaticData.h"
USING_NS_CC;
bool CannonLayer::init()
{
    if(CCLayer::init()){
        CCSize winSize = CCDirector::sharedDirector()->getWinSize();
        _weapon = Weapon::create();
        _weapon->setPosition(winSize.width*0.5, _weapon->getCannon()->getCurCannonSprite()->getContentSize().height*0.26);
        this->addChild(_weapon);
        
        _subItem = CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName(STATIC_DATA_STRING("button_sub")), CCSprite::createWithSpriteFrameName(STATIC_DATA_STRING("button_sub")), this, menu_selector(CannonLayer::switchCannon));
        _addItem = CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName(STATIC_DATA_STRING("button_add")), CCSprite::createWithSpriteFrameName(STATIC_DATA_STRING("button_add")), this, menu_selector(CannonLayer::switchCannon));
        CCMenu* menu = CCMenu::create(_subItem, _addItem, NULL);
        menu->alignItemsHorizontallyWithPadding(_weapon->getCannon()->getCurCannonSprite()->getContentSize().width+10);
        menu->setPosition(CCPointMake(winSize.width*0.5, _subItem->getContentSize().height*0.5));
        this->addChild(menu);
        return true;
    }
    return false;
}
void CannonLayer::switchCannon(CCMenuItemSprite* sender)
{
    CannonType type = _weapon->getCannon()->getType();
    int temp = (int)type;
    if(sender == _addItem){
        temp++;
    }else if(sender == _subItem){
        temp--;
    }
    _weapon->getCannon()->setType((CannonType)temp);
}
void CannonLayer::aimAt(CCPoint target)
{
    _weapon->aimAt(target);
}
bool CannonLayer::shootTo(CCPoint target)
{
    return _weapon->shootTo(target);
}