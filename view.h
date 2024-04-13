#pragma once
#include "extra.h"
#include "service.h"
using namespace std;


const int width = 53; // 定义为53个单位（1057/20）
const int height = 33; // 定义为33个单位（660/20）

void DrawGameStartScreen(); // 前置声明
void DrawPauseMenu();
void DrawGameOverScreen();
// 初始化游戏窗口
// 负责人: 
// 功能: 初始化游戏窗口，设置窗口大小、标题和初始界面。
// 参数: 无
// 返回值: 无
void InitGameWindow();

// 绘制游戏菜单界面
// 负责人: 
// 功能: 绘制游戏菜单界面，提供开始游戏和退出游戏等选项。
// 参数: 无
// 返回值: 无
void DrawMenu();


void Setup();

void Draw();
void Input();


void Logic();
// 负责人: 
// 功能: 显示游戏进行中的界面，显示玩家飞机、敌人飞机、子弹以及得分。
// 参数: 
// 返回值: 无
void PlayingGame();
// 负责人：
// 功能：游戏界面
// 参数：
// 返回值：无
void GameView();
// 负责人: 
// 功能: 绘制游戏暂停界面，提供继续游戏和返回主菜单的选项。
// 参数: 无
// 返回值: 无
void DrawPauseMenu();
// 负责人: 
// 功能: 绘制游戏结束界面，显示玩家最终得分和重新开始或退出游戏的选项。
// 参数: 无
// 返回值: 无
void DrawGameOverScreen();

// 负责人: 
// 功能: 绘制游戏开始界面。
// 参数: 无
// 返回值: 无
void DrawGameStartScreen();

void DrawRegisterScreen();//注册
void DrawLoginScreen();//主登录



