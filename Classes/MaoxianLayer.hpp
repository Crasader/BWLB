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
#include "cocos2d.h"
#include "UIBaseLayer.hpp"
#include "ui/CocosGUI.h"

class MaoxianLayer:public UIBaseLayer
{
public:
    CREATE_FUNC(MaoxianLayer);
    
    void onCreate()override;
    
//    void onActive()override;
//    void onDestroy()override;
    
    void fanhui(cocos2d::Ref*);
    void help(cocos2d::Ref*);
    void charpterOne(cocos2d::Ref*);
    
    
private:
    cocos2d::Vector<cocos2d::ui::Button*> m_vec;
};

#endif /* MaoxianLayer_hpp */
