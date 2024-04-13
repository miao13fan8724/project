#include "view.h"
#include "service.h"
#include <vector>

extern ExMessage msg;			 // 输入
extern Player player;             // 玩家数据
extern std::vector<Enemy> enemies;// 敌人列表
extern std::vector<Bullet> bullets;// 子弹列表
extern int score;                 // 玩家得分
extern IMAGE login_page;

//view中的全局变量
int x, y, enemyX, enemyY, bulletX, bulletY, playerHealth, gameTime; // 添加玩家生命值和游戏时间变量
IMAGE imgBackground; // 定义背景图片
IMAGE imgPlayer; // 定义玩家飞机图片
enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
Direction dir;

void InitGameWindow()
{
    initgraph(WD_WIDTH, WD_HEIGHT, NULL);
    cleardevice();
    HWND window_title = GetHWnd();
    SetWindowTextW(window_title, L"公主救阿坤");
}

void DrawMenu()
{
    loadimage(&login_page, _T("D:/图灵院/项目文档/图/界面图/开始菜单/开始菜单.jpg"));
    putimage(0, 0, &login_page);
    Display_Link_Login();
    Get_Mouse_Login();
}

void Setup() {
    dir = STOP;
    x = width / 2;
    y = height - 2;
    enemyX = rand() % width;
    enemyY = 0;
    bulletX = x;
    bulletY = y;
    score = 0;
    playerHealth = 100; // 初始化玩家生命值
    gameTime = 0; // 初始化游戏时间
}

void Draw() {
    cleardevice();
    putimage(0, 0, &imgBackground);
    putimage(x * 20, y * 20, &imgPlayer);
    setcolor(RED);
    setfillcolor(RED);
    fillrectangle(enemyX * 20, enemyY * 20, (enemyX + 1) * 20, (enemyY + 1) * 20);
    setcolor(GREEN);
    setfillcolor(GREEN);
    fillrectangle(bulletX * 20, bulletY * 20, (bulletX + 1) * 20, (bulletY + 1) * 20);
    setbkmode(TRANSPARENT);
    setcolor(RED);
    settextstyle(20, 0, _T("微软雅黑"));
    outtextxy(0, height * 20 - 20, _T("Score: "));
    outtextxy(100, height * 20 - 20, std::to_wstring(score).c_str());
    outtextxy(250, height * 20 - 20, _T("Health: "));
    outtextxy(350, height * 20 - 20, std::to_wstring(playerHealth).c_str());
}

bool CheckCollision(const Bullet& bullet, const Enemy& enemy) {
    double distance = sqrt(pow(bullet.x - enemy.x, 2) + pow(bullet.y - enemy.y, 2));
    if (distance <= bullet.r + enemy.r) {
        return true;
    }
    return false;
}

void CheckCollisions() {
    // 检测子弹和敌人之间的碰撞
    for (int i = 0; i < bullets.size(); i++) {
        for (int j = 0; j < enemies.size(); j++) {
            if (CheckCollision(bullets[i], enemies[j])) {
                bullets.erase(bullets.begin() + i);
                enemies.erase(enemies.begin() + j);
                score++;
                break; // Exit the inner loop after collision detected
            }
        }
    }

    // 检测玩家和敌人之间的碰撞
    for (int i = 0; i < enemies.size(); i++) {
        if (enemyY == height - 1 && enemyX == x) {
            playerHealth -= 10;
            enemyX = rand() % width;
            enemyY = 0;
        }
    }

    // 如果玩家与敌人碰撞，则玩家生命值减少
    for (int i = 0; i < enemies.size(); i++) {
        if (x == enemies[i].x && y == enemies[i].y) {
            playerHealth -= 10;
            enemies.erase(enemies.begin() + i);
            break;
        }
    }
}


void Input() {
    if (_kbhit()) {
        char key = _getch();
        switch (tolower(key)) {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'q':
            exit(0);
            break;
        case 27:
            while (true) {
                if (_kbhit() && _getch() == 27)
                    break;
            }
            break;
        }
    }
    else {
        dir = STOP;
    }
}

void Logic() {
    switch (dir) {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }
    if (x >= width) x = width - 1;
    if (x < 0) x = 0;
    if (y >= height) y = height - 1;
    if (y < 0) y = 0;

    enemyY++;

    if (bulletY == enemyY && bulletX == enemyX) {
        double chance = (double)rand() / RAND_MAX;
        if (chance <= 0.3) {
            bulletX = x;
            bulletY = y;
        }
        else {
            score++;
            enemyX = rand() % width;
            enemyY = 0;
            bulletX = x;
            bulletY = y;
        }
    }
    if (enemyY == height) {
        enemyX = rand() % width;
        enemyY = 0;
    }
    if (bulletY == 0) {
        bulletX = x;
        bulletY = y;
    }
    bulletY--;

    CheckCollisions();

    gameTime++;
}

void PlayingGame()
{
    initgraph(WD_WIDTH, WD_HEIGHT);
    loadimage(&imgBackground, _T("D:/图灵院/项目文档/project汪/project/图/界面图/游戏界面/游戏背景.png"), WD_WIDTH, WD_HEIGHT);
    loadimage(&imgPlayer, _T("D:/图灵院/项目文档/project汪/project/图/界面图/游戏界面/游戏背景 - 副本.png"));
    Setup();
    while (playerHealth > 0) {
        Draw();
        Input();
        Logic();
        Sleep(10);
    }
    outtextxy(200, height * 10, _T("Game Over!"));
    outtextxy(200, height * 11, _T("Press any key to exit..."));
    _getch();
    closegraph();
}

void GameView()
{
    InitGameWindow();
    InitEnemies();
    InitPlayer();
    while (1)
    {
        InitPlayer();
        InitEnemies();
        UpdatePlayerPosition();
        PlayerShoot();
        PlayingGame();
        IsLive();
        Enemy enemy;
        int enemyIndex;
        AddEnemy();
        UpdateEnemiesPosition();
        for (int i = 0; i < enemies.size(); i++)
            EnemyShoot(i);
        BulletMove();
        if (player.hp <= 0)
        {
            DrawGameOverScreen();
            break;
        }
    }
}

void DrawPauseMenu()
{
    ExMessage m;
    while (true)
    {
        m = getmessage(EX_MOUSE | EX_KEY);
        switch (m.message)
        {
        case WM_LBUTTONDOWN:
            if (m.x >= 5 && m.x <= 126 && m.y >= 83 && m.y <= 121)
            {
                IMAGE img1;
                loadimage(&img1, _T("D:/图灵院/项目文档/project汪/project/图/界面图/游戏界面/暂停.jpg"), 1080, 660);
                putimage(0, 0, &img1);
            }
            break;
        }
    }
}

void DrawGameOverScreen()
{
    initgraph(1080, 660);
    setbkcolor(WHITE);
    cleardevice();
    IMAGE img1;
    loadimage(&img1, _T("结束界面.jpg"));
    putimage(0, 0, &img1);
    setfillcolor(RED);
    solidrectangle(428, 584, 500, 660);
    ExMessage m;
}

void DrawGameStartScreen()
{
    initgraph(1080, 660);
    cleardevice();

    IMAGE img;
    loadimage(&img, _T("./project/图/界面图/开始菜单/开始菜单.jpg"));

    putimage(0, 0, &img);

    _getch();
    while (true) {
        if (_kbhit()) {
            char key = _getch();
            if (key == ' ') {
                break;
            }
        }
    }
    closegraph();
}

void DrawLoginScreen()
{
    initgraph(1080, 660);
    cleardevice();

    IMAGE img;
    loadimage(&img, _T("D:/图灵院/项目文档/project汪/project/图/界面图/登录模块/主登录界面.jpg"));

    putimage(0, 0, &img);

    _getch();
    while (true) {
        if (_kbhit()) {
            char key = _getch();
            if (key == ' ') {
                break;
            }
        }
    }
    closegraph();
}

void DrawRegisterScreen()
{
    initgraph(1080, 660);
    cleardevice();

    IMAGE img;
    loadimage(&img, _T("D:/图灵院/项目文档/图/界面图/登录模块/注册界面.jpg"));

    putimage(0, 0, &img);

    _getch();
    while (true) {
        if (_kbhit()) {
            char key = _getch();
            if (key == ' ') {
                break;
            }
        }
    }
    closegraph();
}
