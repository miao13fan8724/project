#include "service.h"
#include "base.h"
extern ExMessage msg;				 // ����
extern Player player;               // �������
extern std::vector<Enemy> enemies;  // �����б�
extern std::vector<Bullet> bullets; // �ӵ��б�
extern int score;                   // ��ҵ÷�
            
//--------------------------------------------------------------------------��¼------------------------------------------------------------------------------
//��¼����
//char* selectUserById(int uid)
//{
//	for (int n = 0; n < 4; n++)
//	{
//		if (ids[n] == uid)
//		{
//			return names[n];
//		}
//	}
//	return NULL;
//}
//
//char* selectPassById(int uid)
//{
//	for (int n = 0; n < 4; n++)
//	{
//		if (ids[n] == uid)
//		{
//			return passwords[n];
//		}
//	}
//	return NULL;
//}
//
//int login(int uid, string password)
//{
//	if (selectUserById(uid) != NULL)
//	{
//		if (selectPassById(uid) == password)
//		{
//			return 0;
//		}
//		else
//		{
//			return 2;
//		}
//	}
//	else
//	{
//		return 1;
//	}
//}
//
//void showLoginPage()
//{
//	cout << "������uid" << endl;
//	cin >> uid;
//	cout << "����������" << endl;
//	cin.ignore();  // ����֮ǰ�Ļ��з�
//	getline(cin, password);
//	if (login(uid, password) == 0)
//	{
//		cout << "��¼�ɹ�" << endl;
//	}
//	else if (login(uid, password) == 1)
//	{
//		cout << "�˺Ų�����" << endl;
//	}
//	else if (login(uid, password) == 2)
//	{
//
//		cout << "�˺Ų�����" << endl;
//	}
//}







//--------------------------------------------------------------------------��Ϸ------------------------------------------------------------------------------
// ������: 
// ����: ��ʼ��������ݣ�������ҵĳ�ʼλ�á�����ֵ��ͼ������ӵ��б�
// ����: 
// ����ֵ: void
void InitPlayer()
{
	player.r = 50;
	player.x = WD_WIDTH / 2;
	player.y = WD_HEIGHT - player.r;//��ҵĳ�ʼλ��
	player.hp = 100;//����ֵ
	//loadimage(&plane_img,"./.jpg");wda
	bullets.clear();//����ӵ��б�
}

// ������: 
// ����: ��ʼ�������б�Ԥ�����һ�������ĵ��˵���Ϸ�С�
// ����: 
// ����ֵ: void
void InitEnemies()
{
	// �����ʼ��ʱ����10������
	int numEnemies = 10;
	for (int i = 0; i < numEnemies; i++) {
		Enemy enemy;
		enemy.x = rand() % WD_WIDTH;  // ���λ��
		enemy.y = 0;            // ��ʼ�ڴ��ڶ���
		enemy.r = 30;           // ��ʼ���˵İ뾶Ϊ30
		enemy.hp = 100;         // ����ֵΪ100
		enemy.speed = 5 + rand() % 5;  // �ٶ�Ϊ5��10֮��

		enemies.push_back(enemy);
	}
}


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
void AddEnemy()
{
	srand(time(nullptr));
	Enemy new_enemy;
	new_enemy.x = rand() % 600;
	new_enemy.y = 0;
	new_enemy.hp = 100;
	new_enemy.r = 10;
	new_enemy.speed = 5;
	enemies.push_back(new_enemy);
}


// ������: 
// ����: ����������루wdsa space)������ҵ�λ�á�
// ����: 
// ����ֵ: void
void UpdatePlayerPosition()
{
	player.y += player.speed;    // ���y������������ٶ�
	if (player.y < 0)             // ���y����С��0�������y��������Ϊ0
	{
		player.y = 0;
	}
	if (player.y > 480 - player.r) // ���y�������480-��Ұ뾶�������y��������Ϊ640-��Ұ뾶
	{
		player.y = 640 - player.r;
	}
}

// ������: 
// ����: �����������������µ��ӵ�����ӵ���Ϸ�С�
// ����: ��
// ����ֵ: void
void PlayerShoot()
{
	Bullet bullet = {};// �����ӵ�
	bullet.x = player.x + player.r / 2 - bullet.r / 2; // �ӵ�x����Ϊ�ɻ�x����+�ɻ��뾶-�ӵ��뾶
	bullet.y = player.y + player.r;                        // �ӵ�y����Ϊ�ɻ�y����+�ɻ��뾶  
	bullet.speed = 10;                                         // �ӵ��ٶ�Ϊ10
	bullets.push_back(bullet);                                  // �ӵ���ӵ��ӵ��б��� 
}

// ������: 
// ����: �������е��˵�λ�ã��������ǵ��ٶȺͷ�������ƶ���
//		�����еĵ��˵�y+=speed;
// ����: ��
// ����ֵ: void
void UpdateEnemiesPosition()
{
	for (auto& enemy : enemies) {
		enemy.y += enemy.speed; // ʹ�� enemy ���ʵ�ǰԪ�أ���������
		// ����y������������ٶ�
		if (enemy.y < 0)             // ����y����С��0�������y��������Ϊ0
		{
			enemy.y = 0;
		}
		if (enemy.y > 480 - enemy.r) // ����y�������480-��Ұ뾶�������y��������Ϊ640-��Ұ뾶
		{
			enemy.y = 640 - enemy.r;
		}
	}
}

// ������: 
// ����: ѡ���ĵ��˽�������������µ��ӵ�����ӵ���Ϸ�С�
// ����:	enemyIndex - ����ĵ�������
// ����ֵ: void
void EnemyShoot(int enemyIndex)
{
	// ѡ���ĵ���
	Enemy& enemy = enemies[enemyIndex];

	// �����ӵ�
	Bullet bullet = {};
	bullet.x = enemy.x + enemy.r / 2 - bullet.r / 2; // �ӵ�x����Ϊ����x����+���˰뾶-�ӵ��뾶
	bullet.y = enemy.y + enemy.r;                        // �ӵ�y����Ϊ����y����+���˰뾶  
	bullet.speed = 10;                                         // �ӵ��ٶ�Ϊ10
	bullets.push_back(bullet);                                  // �ӵ���ӵ��ӵ��б��� 
}

// �����ˣ�
// ���ܣ�����Һ͵��˵��ӵ��ƶ�
//		�����ӵ����飬�ƶ����е��ӵ�
// ������ ��
// ����ֵ�� void
void BulletMove()
{
	for (auto& bullet : bullets)
	{
		if (bullet.isPlayer)
		{
			bullet.y -= bullet.speed;
		}
		else
		{
			bullet.y += bullet.speed;
		}
	}
}

// �����ˣ�
// ���ܣ�����Ŀ��Ĵ��״̬
//		��HP<=0���߷ɳ��߽�ĵ��˺��ӵ��Ӷ�Ӧ������ɾ��
// ��������
// ����ֵ��void
void IsLive()
{
	// ���µ��˵Ĵ��״̬
	auto ite = enemies.begin();
	while (ite != enemies.end()) {
		if (ite->hp <= 0 || ite->y > WD_HEIGHT || ite->y < 0 || ite->x > WD_WIDTH || ite->x < 0) { // Ѫ��С��0�����ߵ��˷ɳ����½�������ҽ���
			ite = enemies.erase(ite);
		}
		else {
			++ite;
		}
	}

	// �����ӵ��Ĵ��״̬
	auto itb = bullets.begin();
	while (itb != bullets.end()) {
		if ((itb->y < 0 || itb->y > 800) || itb->x < 0 || itb->x > 200) { // �����ӵ��ɳ����±߽�����ұ߽�
			itb = bullets.erase(itb);
		}
		else {
			++itb;
		}
	}
}

// �����ˣ�
// ���ܣ� ��Ⲣ�Ҵ������е���ײ�¼�
// ��������
// ����ֵ��void
void CheckCollisions()
{
	for (int i = 1; i <= 500; i++) {
		if (!bullets[i - 1].isPlayer && bullets[i - 1].isLive)
		{
			//������ӵ�����ҵ�Բ�ľ࣬���ж��Ƿ�С�����߰뾶֮��
			double x_2 = pow(bullets[i - 1].x + bullets[i - 1].r / 2 - player.x - player.x / 2, 2);
			double y_2 = pow(bullets[i - 1].y + bullets[i - 1].r / 2 - player.y - player.y / 2, 2);
			double dis = pow(x_2 + y_2, 0.5);
			if (dis < (double)(bullets[i - 1].r / 2 + player.r / 2)) {
				player.hp -= 20;//���Ѫ���ۼ�
				score -= 20;//�����ۼ�ֵΪ����յ��˺�
				bullets[i - 1].isLive = false;//���ӵ���ʧ
			}
		}
	}//�л��ӵ���ɻ���ײ

	for (int i = 1; i <= 50; i++) {
		if (enemies[i - 1].isLive) {
			//����Բ�ľ�
			int x_player = player.x + player.r / 2;
			int y_player = player.y + player.r / 2;
			int x_Ene = enemies[i - 1].x + enemies[i - 1].r / 2;
			int y_Ene = enemies[i - 1].y + enemies[i - 1].r / 2;
			double x_2 = pow(x_player - x_Ene, 2);
			double y_2 = pow(y_player - y_Ene, 2);
			double dis = pow(x_2 + y_2, 0.5);
			//�ж��Ƿ���ײ
			if (dis < (double)(enemies[i].r / 2 + player.r / 2))
			{

				enemies[i - 1].isLive = false;//����ȥ��
				player.hp -= 50;//�ۼ����Ѫ��
				score -= 50;//���˺�ֵ�۷�

			}
		}
	}//�л���ɻ���ײ

	for (int i = 0; i < 50; i++) //������������
	{
		if (enemies[i].isLive) {
			for (int j = 0; j < 500; j++) //�����ӵ�����
			{
				if (bullets[j].isLive && bullets[j].isPlayer) {
					//�������Բ�ľ�
					double x_2 = pow(enemies[i].x + enemies[i].r / 2 - bullets[j].x - bullets[j].r / 2, 2);
					double y_2 = pow(enemies[i].y + enemies[i].r / 2 - bullets[j].y - bullets[j].r / 2, 2);
					double dis_2 = x_2 + y_2;
					if (dis_2 < pow(enemies[i].r / 2 + bullets[j].r / 2, 2))
					{
						enemies[i].hp -= 50;//�ۼ�����Ѫ��
						score += 50;//��������
						bullets[j].isLive = false;//�ӵ���ʧ
					}
				}
			}
		}
	}//�����ӵ���л���ײ
}
