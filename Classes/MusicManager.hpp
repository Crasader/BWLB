//
//  MusicManager.hpp
//  luobo
//
//  Created by student on 18/5/7.
//
//

#ifndef MusicManager_hpp
#define MusicManager_hpp

#include <stdio.h>
#include "audio/include/SimpleAudioEngine.h"
using namespace CocosDenshion;
class MusicManager
{
public:
    
    static void playBackgroundMusic(const char* backMusic,bool loops = false);
    static void stopBackgroundMusic();
    
    static void pauseBackgroundMusic();
    static void resumeBackgroundMusic();
    
    static void setFlags(bool flag);
    static bool getFlags();
    
private:
    static bool m_MusicFlags;
    static SimpleAudioEngine* m_audio;
};



#endif /* MusicManager_hpp */
