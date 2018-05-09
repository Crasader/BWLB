//
//  MaoxianScene.cpp
//  luobo
//
//  Created by student on 18/5/8.
//
//

#include "MaoxianScene.hpp"
#include "UIManager.hpp"
using namespace cocos2d;
Scene* MaoxianScene::createScene()
{
    return MaoxianScene::create();
}
bool MaoxianScene::init()
{
    if (!Scene::init())
    {
        return false;
    }
    CCLOG("MaoxianScene");
    m_layer = UIManager::CreateLayer(UIManager::MAOXIAN);
    this->addChild(m_layer);
    return true;
}