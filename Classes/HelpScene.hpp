//
//  HelpScene.hpp
//  luobo
//
//  Created by student on 18/5/7.
//
//

#ifndef HelpScene_hpp
#define HelpScene_hpp

#include <stdio.h>

#include "cocos2d.h"
class HelpScene:public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    bool init()override;
    
    CREATE_FUNC(HelpScene);
private:
    cocos2d::Layer* m_layer;
};
#endif /* HelpScene_hpp */
