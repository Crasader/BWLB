//
//  MusicManager.cpp
//  luobo
//
//  Created by student on 18/5/7.
//
//

#include "MusicManager.hpp"

#include "cocos2d.h"
using namespace cocos2d;
/*
 UserDefault  cocos封装的用来将数据存储到文件中的类
 
 使用时要获取单例对象
 UserDefault::getInstance();
 
 */

SimpleAudioEngine* MusicManager::m_audio = SimpleAudioEngine::getInstance();
bool MusicManager::m_MusicFlags =  UserDefault::getInstance()->getBoolForKey("music", true);
void MusicManager::playBackgroundMusic(const char* backMusic,bool loops)
{
    if (m_MusicFlags)
    {
        m_audio->playBackgroundMusic(backMusic,loops);
    }
}

void MusicManager::stopBackgroundMusic()
{
    m_audio->stopBackgroundMusic();
}

void MusicManager::pauseBackgroundMusic()
{
    m_audio->pauseBackgroundMusic();
}
void MusicManager::resumeBackgroundMusic()
{
    m_audio->resumeBackgroundMusic();
}
void MusicManager::setFlags(bool flag)
{
    m_MusicFlags = flag;
    UserDefault::getInstance()->setBoolForKey("music",flag);
}
bool MusicManager::getFlags()
{
    return m_MusicFlags;
}