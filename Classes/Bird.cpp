//
//  Bird.cpp
//  luobo
//
//  Created by student on 18/5/10.
//
//

#include "Bird.hpp"
using namespace cocos2d;

bool Bird::init()
{
    if (!Sprite::init())
    {
        return false;
    }
    
    TextureCache* _textureCache = Director::getInstance()->getTextureCache();
    Texture2D* _t1 = _textureCache->addImage("studio/bird.png");
    Texture2D* _t2 =  _textureCache->addImage("PetFly11_01.png");
    
//    vec.pushBack(_t1);
//    vec.pushBack(_t2);
//    auto animation = Animation::create();
//    animation->addSpriteFrame(_t1);
    
    m_blood = Sprite::create("bloodBar.png");
    m_blood->setPosition(this->getContentSize().width,this->getContentSize().height +30);
    m_blood->setScale(0.5);
    this->addChild(m_blood);
    
//    this = Sprite::create("studio/bird.png");
    this->setTexture("studio/bird.png");
    
    
    
    return true;
}