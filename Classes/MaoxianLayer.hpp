//
//  MaoxianLayer.hpp
//  luobo
//
//  Created by student on 18/5/7.
//
//

#ifndef MaoxianLayer_hpp
#define MaoxianLayer_hpp

#include <stdio.h>
#include "UIBaseLayer.hpp"

class MaoxianLayer:public UIBaseLayer
{
public:
    CREATE_FUNC(MaoxianLayer);
    
    void onCreate()override;
    
//    void onActive()override;
//    void onDestroy()override;
    
    void fanhui(cocos2d::Ref*);
    void help(cocos2d::Ref*);
    
    
private:
};

#endif /* MaoxianLayer_hpp */
