#include <iostream>
#include"base.h"
#include"view.h"
#include"service.h"
// 游戏全局数据
ExMessage msg;				 // 输入
Player player;               // 玩家数据
std::vector<Enemy> enemies;  // 敌人列表
std::vector<Bullet> bullets; // 子弹列表
int score;                   // 玩家得分




int main()
{
	GameView();
	return 0;
}