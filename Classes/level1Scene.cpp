//
//  level1Scene.cpp
//  luobo
//
//  Created by student on 18/5/10.
//
//

#include "level1Scene.hpp"
#include "GoLayer.hpp"
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
    
    auto guaiwuLayer = map->getObjectGroup("guaijiao");//对象层
    auto leftspInfo = guaiwuLayer->getObject("spr1");
    auto leftsp = Sprite::create("cloud01.png");
    leftsp->setPosition(leftspInfo["x"].asFloat(),leftspInfo["y"].asFloat());
    
    auto midspInfo = guaiwuLayer->getObject("spr2");
    auto midsp = Sprite::create("cloud02.png");
    leftsp->setPosition(midspInfo["x"].asFloat(),midspInfo["y"].asFloat());
    
    auto rightspInfo = guaiwuLayer->getObject("spr1");
    auto rightsp = Sprite::create("cloud03.png");
    leftsp->setPosition(rightspInfo["x"].asFloat(),rightspInfo["y"].asFloat());
    
    
    auto guaiwuInfo = guaiwuLayer->getObject("obj1");//对象信息
    sp = Sprite::create("PetFly11_01.png");
    sp->setPosition(guaiwuInfo["x"].asFloat(),guaiwuInfo["y"].asFloat());
    map->addChild(sp);
    /*
//    auto guaiwuInfo2 = guaiwuLayer->getObject("obj2");
//    Vec2 pos2(guaiwuInfo2["x"].asFloat(),guaiwuInfo2["y"].asFloat());
//    auto move2 = MoveTo::create(2,pos2);
//    
//    auto guaiwuInfo3 = guaiwuLayer->getObject("obj3");
//    Vec2 pos3(guaiwuInfo3["x"].asFloat(),guaiwuInfo3["y"].asFloat());
//    auto move3 = MoveTo::create(2,pos3);
//    
//    auto guaiwuInfo4 = guaiwuLayer->getObject("obj4");
//    Vec2 pos4(guaiwuInfo4["x"].asFloat(),guaiwuInfo4["y"].asFloat());
//    auto move4 = MoveTo::create(2,pos4);
//    
//    auto guaiwuInfo5 = guaiwuLayer->getObject("obj5");
//    Vec2 pos5(guaiwuInfo5["x"].asFloat(),guaiwuInfo5["y"].asFloat());
//    auto move5 = MoveTo::create(2,pos5);
//    
//    auto guaiwuInfo6 = guaiwuLayer->getObject("obj6");
//    Vec2 pos6(guaiwuInfo6["x"].asFloat(),guaiwuInfo6["y"].asFloat());
//    auto move6 = MoveTo::create(2,pos6);
//    
//    auto guaiwuInfo7 = guaiwuLayer->getObject("obj7");
//    Vec2 pos7(guaiwuInfo7["x"].asFloat(),guaiwuInfo7["y"].asFloat());
//    auto move7 = MoveTo::create(2,pos7);
//    
    auto guaiwuInfo8 = guaiwuLayer->getObject("obj8");
    Vec2 pos8(guaiwuInfo8["x"].asFloat(),guaiwuInfo8["y"].asFloat());
//    auto move8 = MoveTo::create(2,pos8);
//    
//    auto seq = Sequence::create(move2,move3,move4,move5,move6,move7,move8, NULL);
//    sp->runAction(seq);*/
    
    auto guaiwuInfo8 = guaiwuLayer->getObject("obj8");
    Vec2 pos8(guaiwuInfo8["x"].asFloat(),guaiwuInfo8["y"].asFloat());
    
    lb = Sprite::create();
    lb->setSpriteFrame("hlb10.png");
    lb->setPosition(pos8);
    this->addChild(lb);
    
    int i = 1;
    this->schedule([=](float dt)mutable{
        char str[20];
        sprintf(str,"obj%d",i);
        auto guaiwuInfo = guaiwuLayer->getObject(str);//对象信息
        Vec2 pos(guaiwuInfo["x"].asFloat(),guaiwuInfo["y"].asFloat());
        auto move = MoveTo::create(1.5,pos);
        sp->runAction(move);
        ++i;
    },1.5,7,0,"guaiwu");
    
    luobo();
    return true;
}

void Level1Scene::createGuaiwu(float dt)
{
    auto guaiwuLayer = map->getObjectGroup("guaijiao");//对象层
    auto guaiwuInfo = guaiwuLayer->getObject("obj1");//对象信息
    auto sp = Sprite::create("PetFly11_01.png");
    m_vec.pushBack(sp);
    sp->setPosition(guaiwuInfo["x"].asFloat(),guaiwuInfo["y"].asFloat());
    map->addChild(sp);
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


