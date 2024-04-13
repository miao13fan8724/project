#pragma once
#pragma once
#include <vector>
#include "easyx.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <conio.h>
#include <easyx.h>
#include <graphics.h>
#include <time.h>
#include <mmsystem.h>
#include <string>
#include <cmath>
using namespace std;
// 玩家飞机结构
struct Player {
    int x, y;   // 飞机的位置坐标
    int r;   // 飞机的半径
    int hp;     // 生命值
    int speed;//速度
};

// 敌人飞机结构
struct Enemy {
    int x, y;   // 敌人的位置坐标
    int r;   // 敌人的半径
    int hp;     // 生命值
    int speed;  // 移动速度
    bool isLive;
};

// 子弹结构
struct Bullet {
    int x, y;       // 子弹的位置坐标
    int r;       // 子弹的半径
    int speed;      // 子弹的移动速度
    bool isPlayer;  // 是否是玩家发射的子弹
    bool isLive;
};

const int WD_WIDTH = 1080;		//窗口宽度
const int WD_HEIGHT = 660;    //窗口高度              
//int ids[5] = { 10001,10002,10003,10004 };
//char names[5][10] = { "张三", "李四", "王五", "赵六" };
//char passwords[5][16] = { "aaaaa","bbbbb","ccccc","ddddd" };
//int uNum = 4;
//int uid;
//string password;