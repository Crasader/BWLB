//
//  MaoxianScene.hpp
//  luobo
//
//  Created by student on 18/5/8.
//
//

#ifndef MaoxianScene_hpp
#define MaoxianScene_hpp

#include <stdio.h>
#include "cocos2d.h"

class MaoxianScene:public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    bool init()override;
    
    CREATE_FUNC(MaoxianScene);
    
private:
    cocos2d::Layer* m_layer;
    
};


#endif /* MaoxianScene_hpp */
