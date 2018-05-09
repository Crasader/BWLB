//
//  ShezhiScene.hpp
//  luobo
//
//  Created by student on 18/5/8.
//
//

#ifndef ShezhiScene_hpp
#define ShezhiScene_hpp

#include <stdio.h>
class ShezhiScene:public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    bool init()override;
    
    void onEnter()override;
    void onExit()override;
    
    
    CREATE_FUNC(ShezhiScene);
private:
    cocos2d::Layer* m_layer;
};
#endif /* ShezhiScene_hpp */
