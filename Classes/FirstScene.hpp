//
//  FirstScene.hpp
//  luobo
//
//  Created by student on 18/5/7.
//
//

#ifndef FirstScene_hpp
#define FirstScene_hpp

#include <stdio.h>
#include "cocos2d.h"
class FirstScene:public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    bool init()override;
    
    void onEnter()override;
    void onExit()override;
    
    CREATE_FUNC(FirstScene);
private:
    cocos2d::Layer* m_layer;
};
#endif /* FirstScene_hpp */
