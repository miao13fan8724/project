#pragma once
#include "base.h"
#include<time.h>
#include "img.h"

//注册
//void registerUID();
////登录
//char* selectUserById(int uid);
//char* selectPassById(int uid);
//int login(int uid, string password);
// 负责人: 
// 功能: 初始化玩家数据，设置玩家的初始位置、生命值和图像。清空子弹列表
// 参数: 
// 返回值: void
void InitPlayer();

// 负责人: 
// 功能: 初始化敌人列表，预先填充一定数量的敌人到游戏中。
// 参数: 
// 返回值: void
void InitEnemies();

// 负责人: 
// 功能: 向游戏中添加一个新的敌人，设置敌人的位置、生命值、速度和图像。
// 参数: Enemy enemies(也可以不传参数，可以定义一个时间的间隔秒数，然后
//			每隔一段时间，自动调用这个函数，然后构造一个Enemy,插入到敌人数组中去）
// 返回值: void
//void AddEnemy(Enemy enemies)
//{
//	srand(time(nullptr));
//	enemies.x = rand() % 600;
//	enemies.y = 0;
//	enemies.hp = 100;
//	enemies.r = 10;
//	enemies.speed = 5;
//	enemies.push_back(enemy);
//}
void AddEnemy();

// 负责人: 
// 功能: 根据玩家输入（wdsa space)更新玩家的位置。
// 参数: 
// 返回值: void
void UpdatePlayerPosition();

// 负责人: 
// 功能: 处理玩家射击，创建新的子弹并添加到游戏中。
// 参数: 无
// 返回值: void
void PlayerShoot();

// 负责人: 
// 功能: 更新所有敌人的位置，根据它们的速度和方向进行移动。
//		让所有的敌人的y+=speed;
// 参数: 无
// 返回值: void
void UpdateEnemiesPosition();

// 负责人: 
// 功能: 选定的敌人进行射击，创建新的子弹并添加到游戏中。
// 参数:	enemyIndex - 射击的敌人索引
// 返回值: void
void EnemyShoot(int enemyIndex);

// 负责人：
// 功能：让玩家和敌人的子弹移动
//		遍历子弹数组，移动所有的子弹
// 参数： 无
// 返回值： void
void BulletMove();

// 负责人：
// 功能：更新目标的存活状态
//		将HP<=0或者飞出边界的敌人和子弹从对应数组中删除
// 参数：无
// 返回值：void
void IsLive();

// 负责人：
// 功能： 检测并且处理所有的碰撞事件
// 参数：无
// 返回值：void
void CheckCollisions(); //敌机子弹与飞机碰撞


