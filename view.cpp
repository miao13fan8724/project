#include "view.h"
#include "service.h"
#include <vector>

extern ExMessage msg;			 // ����
extern Player player;             // �������
extern std::vector<Enemy> enemies;// �����б�
extern std::vector<Bullet> bullets;// �ӵ��б�
extern int score;                 // ��ҵ÷�
extern IMAGE login_page;

//view�е�ȫ�ֱ���
int x, y, enemyX, enemyY, bulletX, bulletY, playerHealth, gameTime; // ����������ֵ����Ϸʱ�����
IMAGE imgBackground; // ���屳��ͼƬ
IMAGE imgPlayer; // ������ҷɻ�ͼƬ
enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
Direction dir;

void InitGameWindow()
{
    initgraph(WD_WIDTH, WD_HEIGHT, NULL);
    cleardevice();
    HWND window_title = GetHWnd();
    SetWindowTextW(window_title, L"�����Ȱ���");
}

void DrawMenu()
{
    loadimage(&login_page, _T("D:/ͼ��Ժ/��Ŀ�ĵ�/ͼ/����ͼ/��ʼ�˵�/��ʼ�˵�.jpg"));
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
    playerHealth = 100; // ��ʼ���������ֵ
    gameTime = 0; // ��ʼ����Ϸʱ��
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
    settextstyle(20, 0, _T("΢���ź�"));
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
    // ����ӵ��͵���֮�����ײ
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

    // �����Һ͵���֮�����ײ
    for (int i = 0; i < enemies.size(); i++) {
        if (enemyY == height - 1 && enemyX == x) {
            playerHealth -= 10;
            enemyX = rand() % width;
            enemyY = 0;
        }
    }

    // �������������ײ�����������ֵ����
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
    loadimage(&imgBackground, _T("D:/ͼ��Ժ/��Ŀ�ĵ�/project��/project/ͼ/����ͼ/��Ϸ����/��Ϸ����.png"), WD_WIDTH, WD_HEIGHT);
    loadimage(&imgPlayer, _T("D:/ͼ��Ժ/��Ŀ�ĵ�/project��/project/ͼ/����ͼ/��Ϸ����/��Ϸ���� - ����.png"));
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
                loadimage(&img1, _T("D:/ͼ��Ժ/��Ŀ�ĵ�/project��/project/ͼ/����ͼ/��Ϸ����/��ͣ.jpg"), 1080, 660);
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
    loadimage(&img1, _T("��������.jpg"));
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
    loadimage(&img, _T("./project/ͼ/����ͼ/��ʼ�˵�/��ʼ�˵�.jpg"));

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
    loadimage(&img, _T("D:/ͼ��Ժ/��Ŀ�ĵ�/project��/project/ͼ/����ͼ/��¼ģ��/����¼����.jpg"));

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
    loadimage(&img, _T("D:/ͼ��Ժ/��Ŀ�ĵ�/ͼ/����ͼ/��¼ģ��/ע�����.jpg"));

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
