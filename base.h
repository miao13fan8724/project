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
// ��ҷɻ��ṹ
struct Player {
    int x, y;   // �ɻ���λ������
    int r;   // �ɻ��İ뾶
    int hp;     // ����ֵ
    int speed;//�ٶ�
};

// ���˷ɻ��ṹ
struct Enemy {
    int x, y;   // ���˵�λ������
    int r;   // ���˵İ뾶
    int hp;     // ����ֵ
    int speed;  // �ƶ��ٶ�
    bool isLive;
};

// �ӵ��ṹ
struct Bullet {
    int x, y;       // �ӵ���λ������
    int r;       // �ӵ��İ뾶
    int speed;      // �ӵ����ƶ��ٶ�
    bool isPlayer;  // �Ƿ�����ҷ�����ӵ�
    bool isLive;
};

const int WD_WIDTH = 1080;		//���ڿ��
const int WD_HEIGHT = 660;    //���ڸ߶�              
//int ids[5] = { 10001,10002,10003,10004 };
//char names[5][10] = { "����", "����", "����", "����" };
//char passwords[5][16] = { "aaaaa","bbbbb","ccccc","ddddd" };
//int uNum = 4;
//int uid;
//string password;