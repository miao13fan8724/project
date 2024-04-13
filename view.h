#pragma once
#include "extra.h"
#include "service.h"
using namespace std;


const int width = 53; // ����Ϊ53����λ��1057/20��
const int height = 33; // ����Ϊ33����λ��660/20��

void DrawGameStartScreen(); // ǰ������
void DrawPauseMenu();
void DrawGameOverScreen();
// ��ʼ����Ϸ����
// ������: 
// ����: ��ʼ����Ϸ���ڣ����ô��ڴ�С������ͳ�ʼ���档
// ����: ��
// ����ֵ: ��
void InitGameWindow();

// ������Ϸ�˵�����
// ������: 
// ����: ������Ϸ�˵����棬�ṩ��ʼ��Ϸ���˳���Ϸ��ѡ�
// ����: ��
// ����ֵ: ��
void DrawMenu();


void Setup();

void Draw();
void Input();


void Logic();
// ������: 
// ����: ��ʾ��Ϸ�����еĽ��棬��ʾ��ҷɻ������˷ɻ����ӵ��Լ��÷֡�
// ����: 
// ����ֵ: ��
void PlayingGame();
// �����ˣ�
// ���ܣ���Ϸ����
// ������
// ����ֵ����
void GameView();
// ������: 
// ����: ������Ϸ��ͣ���棬�ṩ������Ϸ�ͷ������˵���ѡ�
// ����: ��
// ����ֵ: ��
void DrawPauseMenu();
// ������: 
// ����: ������Ϸ�������棬��ʾ������յ÷ֺ����¿�ʼ���˳���Ϸ��ѡ�
// ����: ��
// ����ֵ: ��
void DrawGameOverScreen();

// ������: 
// ����: ������Ϸ��ʼ���档
// ����: ��
// ����ֵ: ��
void DrawGameStartScreen();

void DrawRegisterScreen();//ע��
void DrawLoginScreen();//����¼



