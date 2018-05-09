//
//  FirstScene.cpp
//  luobo
//
//  Created by student on 18/5/7.
//
//

#include "FirstScene.hpp"
#include "UIManager.hpp"
#include "MusicManager.hpp"
using namespace cocos2d;

Scene* FirstScene::createScene()
{
    return FirstScene::create();
}
bool FirstScene::init()
{
    if (!Scene::init())
    {
        return false;
    }
    CCLOG("FirstScene");
    m_layer = UIManager::CreateLayer(UIManager::FIRST);
    this->addChild(m_layer);
    
    return true;
}
void FirstScene::onEnter()
{
    MusicManager::playBackgroundMusic("Music/Main/BGMusic.mp3");
    Scene::onEnter();
}
void FirstScene::onExit()
{
    MusicManager::stopBackgroundMusic();
    Scene::onExit();
}