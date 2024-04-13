#pragma once
#include "base.h"
#include<time.h>
#include "img.h"

//ע��
//void registerUID();
////��¼
//char* selectUserById(int uid);
//char* selectPassById(int uid);
//int login(int uid, string password);
// ������: 
// ����: ��ʼ��������ݣ�������ҵĳ�ʼλ�á�����ֵ��ͼ������ӵ��б�
// ����: 
// ����ֵ: void
void InitPlayer();

// ������: 
// ����: ��ʼ�������б�Ԥ�����һ�������ĵ��˵���Ϸ�С�
// ����: 
// ����ֵ: void
void InitEnemies();

// ������: 
// ����: ����Ϸ�����һ���µĵ��ˣ����õ��˵�λ�á�����ֵ���ٶȺ�ͼ��
// ����: Enemy enemies(Ҳ���Բ������������Զ���һ��ʱ��ļ��������Ȼ��
//			ÿ��һ��ʱ�䣬�Զ��������������Ȼ����һ��Enemy,���뵽����������ȥ��
// ����ֵ: void
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

// ������: 
// ����: ����������루wdsa space)������ҵ�λ�á�
// ����: 
// ����ֵ: void
void UpdatePlayerPosition();

// ������: 
// ����: �����������������µ��ӵ�����ӵ���Ϸ�С�
// ����: ��
// ����ֵ: void
void PlayerShoot();

// ������: 
// ����: �������е��˵�λ�ã��������ǵ��ٶȺͷ�������ƶ���
//		�����еĵ��˵�y+=speed;
// ����: ��
// ����ֵ: void
void UpdateEnemiesPosition();

// ������: 
// ����: ѡ���ĵ��˽�������������µ��ӵ�����ӵ���Ϸ�С�
// ����:	enemyIndex - ����ĵ�������
// ����ֵ: void
void EnemyShoot(int enemyIndex);

// �����ˣ�
// ���ܣ�����Һ͵��˵��ӵ��ƶ�
//		�����ӵ����飬�ƶ����е��ӵ�
// ������ ��
// ����ֵ�� void
void BulletMove();

// �����ˣ�
// ���ܣ�����Ŀ��Ĵ��״̬
//		��HP<=0���߷ɳ��߽�ĵ��˺��ӵ��Ӷ�Ӧ������ɾ��
// ��������
// ����ֵ��void
void IsLive();

// �����ˣ�
// ���ܣ� ��Ⲣ�Ҵ������е���ײ�¼�
// ��������
// ����ֵ��void
void CheckCollisions(); //�л��ӵ���ɻ���ײ


