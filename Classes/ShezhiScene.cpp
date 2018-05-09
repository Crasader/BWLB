//
//  ShezhiScene.cpp
//  luobo
//
//  Created by student on 18/5/8.
//
//

#include "ShezhiScene.hpp"
#include "UIManager.hpp"
#include "MusicManager.hpp"
using namespace cocos2d;

Scene* ShezhiScene::createScene()
{
    return ShezhiScene::create();
}
bool ShezhiScene::init()
{
    if (!Scene::init())
    {
        return false;
    }
    CCLOG("ShezhiScene");
    m_layer = UIManager::CreateLayer(UIManager::SHEZHI);
    this->addChild(m_layer);
    
    return true;
}
void ShezhiScene::onEnter()
{
    MusicManager::playBackgroundMusic("Music/Main/BGMusic.mp3");
    Scene::onEnter();
}
void ShezhiScene::onExit()
{
    MusicManager::stopBackgroundMusic();
    Scene::onExit();
}


