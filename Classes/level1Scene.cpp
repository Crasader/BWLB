//
//  level1Scene.cpp
//  luobo
//
//  Created by student on 18/5/10.
//
//

#include "level1Scene.hpp"
#include "GoLayer.hpp"
#include "Bird.hpp"
using namespace cocos2d;

Scene* Level1Scene::createScene()
{
    return Level1Scene::create();
}
bool Level1Scene::init()
{
    if (!Scene::init())
    {
        return false;
    }
    FileUtils::getInstance()->addSearchPath("studio");
//    GoLayer::create();
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Items01-hd.plist");
    
    
    auto bg = Sprite::create("BG1-hd.pvr.png");
    this->addChild(bg);
    
    map = TMXTiledMap::create("level1_1dt.tmx");
//    map = TMXTiledMap::create("leve1_1.tmx");
    this->addChild(map);
    
    guaiwuLayer = map->getObjectGroup("guaijiao");//对象层
    auto leftspInfo = guaiwuLayer->getObject("spr1");
    auto leftsp = Sprite::create("cloud01.png");
    leftsp->setPosition(leftspInfo["x"].asFloat(),leftspInfo["y"].asFloat());
    map->addChild(leftsp);

    
    auto midspInfo = guaiwuLayer->getObject("spr2");
    auto midsp = Sprite::create("cloud02.png");
    midsp->setPosition(midspInfo["x"].asFloat(),midspInfo["y"].asFloat());
    map->addChild(midsp);
    
    auto rightspInfo = guaiwuLayer->getObject("spr3");
    auto rightsp = Sprite::create("cloud03.png");
    rightsp->setPosition(rightspInfo["x"].asFloat(),rightspInfo["y"].asFloat());
    map->addChild(rightsp);

    
    auto guaiwuInfo = guaiwuLayer->getObject("obj1");//对象信息
    auto n = Node::create();
    n->setPosition(guaiwuInfo["x"].asFloat(),guaiwuInfo["y"].asFloat());
//    sp = Sprite::create("PetFly11_01.png");
//    sp->setPosition(guaiwuInfo["x"].asFloat(),guaiwuInfo["y"].asFloat());
//    map->addChild(sp);
    startPos = n->getPosition();

    
    auto guaiwuInfo8 = guaiwuLayer->getObject("obj8");
    Vec2 pos8(guaiwuInfo8["x"].asFloat(),guaiwuInfo8["y"].asFloat());
    
    lb = Sprite::create();
    lb->setSpriteFrame("hlb10.png");
    lb->setPosition(pos8);
    this->addChild(lb);
    
    this->schedule(CC_CALLBACK_1(Level1Scene::createGuaiwu, this),3,9,0,"create");

    for(auto guaiwu : m_vec)
    {
    int i = 1;
//    this->schedule([=](float dt)mutable{
//       
//            char str[20];
//            sprintf(str,"obj%d",i);
//            auto guaiwuInfo = guaiwuLayer->getObject(str);//对象信息
//            Vec2 pos(guaiwuInfo["x"].asFloat(),guaiwuInfo["y"].asFloat());
//            auto move = MoveTo::create(1.5,pos);
//            guaiwu->runAction(move);
//        
//        ++i;
//    },1.5,7,0,"guaiwu");
        
    }
    
    
    
//    luobo();
    return true;
}

void Level1Scene::createGuaiwu(float dt)
{
//    auto guaiwuLayer = map->getObjectGroup("guaijiao");//对象层
//    auto guaiwuInfo = guaiwuLayer->getObject("obj1");//对象信息
//    auto sp = Sprite::create("PetFly11_01.png");
    auto everySp = Bird::create();
    everySp->setPosition(startPos);
    map->addChild(everySp);
    m_vec.pushBack(everySp);
//    sp->setPosition(guaiwuInfo["x"].asFloat(),guaiwuInfo["y"].asFloat());
//    map->addChild(sp);
    
//    int i = 1;
//    this->schedule([=](float dt)mutable{
////        for(auto guaiwu : m_vec)
////        {
//            char str[20];
//            sprintf(str,"obj%d",i);
//            auto guaiwuInfo = guaiwuLayer->getObject(str);//对象信息
//            Vec2 pos(guaiwuInfo["x"].asFloat(),guaiwuInfo["y"].asFloat());
//            auto move = MoveTo::create(1.5,pos);
//            everySp->runAction(move);
////        }
//        ++i;
//    },1.5,7,0,"guaiwu");
    
    
    
    
}
void Level1Scene::luobo()
{
    this->schedule([=](float dt){
        if (lb->getBoundingBox().intersectsRect(sp->getBoundingBox()))
        {
            lb->setSpriteFrame("hlb11.png");
//            sp->removeFromParent();
            sp->setVisible(false);
        }
    },1.0/60,-1,0,"ppp");
}


