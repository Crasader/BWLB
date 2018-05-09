//
//  SceneManager.cpp
//  luobo
//
//  Created by student on 18/5/7.
//
//

#include "SceneManager.hpp"

#include "FirstScene.hpp"
#include "HelpScene.hpp"
#include "ShezhiScene.hpp"
#include "MaoxianScene.hpp"
USING_NS_CC;
void SceneMannger::goToFirstScene()
{
    auto firstScene = FirstScene::createScene();
    Director::getInstance()->replaceScene(firstScene);
}
void SceneMannger::goToHelpScene()
{
    auto helpscene = HelpScene::createScene();
//    auto scene = TransitionRotoZoom::create(1,helpscene);
    Director::getInstance()->replaceScene(helpscene);
}
void SceneMannger::gotoShezhiScene()
{
    auto shezhiScene = ShezhiScene::createScene();
    Director::getInstance()->replaceScene(shezhiScene);
    
}
void SceneMannger::gotoMaoxianScene()
{
    auto maoxianScene = MaoxianScene::createScene();
    Director::getInstance()->replaceScene(maoxianScene);
}