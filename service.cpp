#include "service.h"
#include "base.h"
extern ExMessage msg;				 // 输入
extern Player player;               // 玩家数据
extern std::vector<Enemy> enemies;  // 敌人列表
extern std::vector<Bullet> bullets; // 子弹列表
extern int score;                   // 玩家得分
            
//--------------------------------------------------------------------------登录------------------------------------------------------------------------------
//登录功能
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
//	cout << "请输入uid" << endl;
//	cin >> uid;
//	cout << "请输入密码" << endl;
//	cin.ignore();  // 忽略之前的换行符
//	getline(cin, password);
//	if (login(uid, password) == 0)
//	{
//		cout << "登录成功" << endl;
//	}
//	else if (login(uid, password) == 1)
//	{
//		cout << "账号不存在" << endl;
//	}
//	else if (login(uid, password) == 2)
//	{
//
//		cout << "账号不存在" << endl;
//	}
//}







//--------------------------------------------------------------------------游戏------------------------------------------------------------------------------
// 负责人: 
// 功能: 初始化玩家数据，设置玩家的初始位置、生命值和图像。清空子弹列表
// 参数: 
// 返回值: void
void InitPlayer()
{
	player.r = 50;
	player.x = WD_WIDTH / 2;
	player.y = WD_HEIGHT - player.r;//玩家的初始位置
	player.hp = 100;//生命值
	//loadimage(&plane_img,"./.jpg");wda
	bullets.clear();//清空子弹列表
}

// 负责人: 
// 功能: 初始化敌人列表，预先填充一定数量的敌人到游戏中。
// 参数: 
// 返回值: void
void InitEnemies()
{
	// 假设初始化时创建10个敌人
	int numEnemies = 10;
	for (int i = 0; i < numEnemies; i++) {
		Enemy enemy;
		enemy.x = rand() % WD_WIDTH;  // 随机位置
		enemy.y = 0;            // 初始在窗口顶端
		enemy.r = 30;           // 初始敌人的半径为30
		enemy.hp = 100;         // 生命值为100
		enemy.speed = 5 + rand() % 5;  // 速度为5至10之间

		enemies.push_back(enemy);
	}
}


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


// 负责人: 
// 功能: 根据玩家输入（wdsa space)更新玩家的位置。
// 参数: 
// 返回值: void
void UpdatePlayerPosition()
{
	player.y += player.speed;    // 玩家y坐标增加玩家速度
	if (player.y < 0)             // 玩家y坐标小于0，则玩家y坐标设置为0
	{
		player.y = 0;
	}
	if (player.y > 480 - player.r) // 玩家y坐标大于480-玩家半径，则玩家y坐标设置为640-玩家半径
	{
		player.y = 640 - player.r;
	}
}

// 负责人: 
// 功能: 处理玩家射击，创建新的子弹并添加到游戏中。
// 参数: 无
// 返回值: void
void PlayerShoot()
{
	Bullet bullet = {};// 创建子弹
	bullet.x = player.x + player.r / 2 - bullet.r / 2; // 子弹x坐标为飞机x坐标+飞机半径-子弹半径
	bullet.y = player.y + player.r;                        // 子弹y坐标为飞机y坐标+飞机半径  
	bullet.speed = 10;                                         // 子弹速度为10
	bullets.push_back(bullet);                                  // 子弹添加到子弹列表中 
}

// 负责人: 
// 功能: 更新所有敌人的位置，根据它们的速度和方向进行移动。
//		让所有的敌人的y+=speed;
// 参数: 无
// 返回值: void
void UpdateEnemiesPosition()
{
	for (auto& enemy : enemies) {
		enemy.y += enemy.speed; // 使用 enemy 访问当前元素，遍历容器
		// 敌人y坐标增加玩家速度
		if (enemy.y < 0)             // 敌人y坐标小于0，则敌人y坐标设置为0
		{
			enemy.y = 0;
		}
		if (enemy.y > 480 - enemy.r) // 敌人y坐标大于480-玩家半径，则敌人y坐标设置为640-玩家半径
		{
			enemy.y = 640 - enemy.r;
		}
	}
}

// 负责人: 
// 功能: 选定的敌人进行射击，创建新的子弹并添加到游戏中。
// 参数:	enemyIndex - 射击的敌人索引
// 返回值: void
void EnemyShoot(int enemyIndex)
{
	// 选定的敌人
	Enemy& enemy = enemies[enemyIndex];

	// 创建子弹
	Bullet bullet = {};
	bullet.x = enemy.x + enemy.r / 2 - bullet.r / 2; // 子弹x坐标为敌人x坐标+敌人半径-子弹半径
	bullet.y = enemy.y + enemy.r;                        // 子弹y坐标为敌人y坐标+敌人半径  
	bullet.speed = 10;                                         // 子弹速度为10
	bullets.push_back(bullet);                                  // 子弹添加到子弹列表中 
}

// 负责人：
// 功能：让玩家和敌人的子弹移动
//		遍历子弹数组，移动所有的子弹
// 参数： 无
// 返回值： void
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

// 负责人：
// 功能：更新目标的存活状态
//		将HP<=0或者飞出边界的敌人和子弹从对应数组中删除
// 参数：无
// 返回值：void
void IsLive()
{
	// 更新敌人的存活状态
	auto ite = enemies.begin();
	while (ite != enemies.end()) {
		if (ite->hp <= 0 || ite->y > WD_HEIGHT || ite->y < 0 || ite->x > WD_WIDTH || ite->x < 0) { // 血量小于0，或者敌人飞出上下界面和左右界面
			ite = enemies.erase(ite);
		}
		else {
			++ite;
		}
	}

	// 更新子弹的存活状态
	auto itb = bullets.begin();
	while (itb != bullets.end()) {
		if ((itb->y < 0 || itb->y > 800) || itb->x < 0 || itb->x > 200) { // 考虑子弹飞出上下边界和左右边界
			itb = bullets.erase(itb);
		}
		else {
			++itb;
		}
	}
}

// 负责人：
// 功能： 检测并且处理所有的碰撞事件
// 参数：无
// 返回值：void
void CheckCollisions()
{
	for (int i = 1; i <= 500; i++) {
		if (!bullets[i - 1].isPlayer && bullets[i - 1].isLive)
		{
			//计算该子弹与玩家的圆心距，并判断是否小于两者半径之和
			double x_2 = pow(bullets[i - 1].x + bullets[i - 1].r / 2 - player.x - player.x / 2, 2);
			double y_2 = pow(bullets[i - 1].y + bullets[i - 1].r / 2 - player.y - player.y / 2, 2);
			double dis = pow(x_2 + y_2, 0.5);
			if (dis < (double)(bullets[i - 1].r / 2 + player.r / 2)) {
				player.hp -= 20;//玩家血量扣减
				score -= 20;//分数扣减值为玩家收到伤害
				bullets[i - 1].isLive = false;//该子弹消失
			}
		}
	}//敌机子弹与飞机碰撞

	for (int i = 1; i <= 50; i++) {
		if (enemies[i - 1].isLive) {
			//计算圆心距
			int x_player = player.x + player.r / 2;
			int y_player = player.y + player.r / 2;
			int x_Ene = enemies[i - 1].x + enemies[i - 1].r / 2;
			int y_Ene = enemies[i - 1].y + enemies[i - 1].r / 2;
			double x_2 = pow(x_player - x_Ene, 2);
			double y_2 = pow(y_player - y_Ene, 2);
			double dis = pow(x_2 + y_2, 0.5);
			//判断是否碰撞
			if (dis < (double)(enemies[i].r / 2 + player.r / 2))
			{

				enemies[i - 1].isLive = false;//敌人去世
				player.hp -= 50;//扣减玩家血量
				score -= 50;//按伤害值扣分

			}
		}
	}//敌机与飞机碰撞

	for (int i = 0; i < 50; i++) //遍历敌人数组
	{
		if (enemies[i].isLive) {
			for (int j = 0; j < 500; j++) //遍历子弹数组
			{
				if (bullets[j].isLive && bullets[j].isPlayer) {
					//计算二者圆心距
					double x_2 = pow(enemies[i].x + enemies[i].r / 2 - bullets[j].x - bullets[j].r / 2, 2);
					double y_2 = pow(enemies[i].y + enemies[i].r / 2 - bullets[j].y - bullets[j].r / 2, 2);
					double dis_2 = x_2 + y_2;
					if (dis_2 < pow(enemies[i].r / 2 + bullets[j].r / 2, 2))
					{
						enemies[i].hp -= 50;//扣减敌人血量
						score += 50;//分数增加
						bullets[j].isLive = false;//子弹消失
					}
				}
			}
		}
	}//主角子弹与敌机碰撞
}
