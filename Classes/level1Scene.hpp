//
//  level1Scene.hpp
//  luobo
//
//  Created by student on 18/5/10.
//
//

#ifndef level1Scene_hpp
#define level1Scene_hpp

#include <stdio.h>
#include"cocos2d.h"
//#include "UIBaseLayer.hpp"

class Level1Scene:public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    bool init()override;
    
    void createGuaiwu(float dt);
    void luobo();
    
    CREATE_FUNC(Level1Scene);
private:
    cocos2d::TMXTiledMap* map;
    cocos2d::Vector<cocos2d::Sprite*> m_vec;
//    cocos2d::Vector<cocos2d::Vec2> m_posVec;
    
    cocos2d::Sprite* lb;
    cocos2d::Sprite* sp;
};

#endif /* level1Scene_hpp */
