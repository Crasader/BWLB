//
//  Bird.hpp
//  luobo
//
//  Created by student on 18/5/10.
//
//

#ifndef Bird_hpp
#define Bird_hpp

#include <stdio.h>
#include "cocos2d.h"

class Bird:public cocos2d::Sprite
{
public:
    CREATE_FUNC(Bird);
    
    bool init()override;
private:
    cocos2d::Vector<cocos2d::Texture2D*> vec;
    
    cocos2d::Sprite* m_blood;
    
};


#endif /* Bird_hpp */
