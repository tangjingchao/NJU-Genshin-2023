
#include "operate/partI.h"
#include "operate/partII.h"
#include "operate/partIII.h"

int wanna_escape = 0;
int NewChoice = 0;
CONSOLE_CURSOR_INFO cci;  // 光标信息
enum order {
    left = 75,
    right = 77,
    attack = 97,
    skill = 101,
    change = 99,
    require = 105,
    close = 111,
    escape = 27,
    explode = 113,
    require_boss = 106,
    startAgain = 13
};

int main() {
    consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);   // 初始化这个操作器
    CONSOLE_SCREEN_BUFFER_INFO csbi;                   // 屏幕的信息
    GetConsoleScreenBufferInfo(consoleHandle, &csbi);  // 获取屏幕信息
    w = csbi.dwSize.X;
    h = csbi.dwSize.Y;  // 得到宽度高度
    cci.dwSize = 100;
    cci.bVisible = FALSE;// 不可见
    SetConsoleCursorInfo(consoleHandle, &cci);  // 将光标特性应用到控制台
    int play = 1;

    while (play) {
        NewChoice = 0;
        NewGame();
        start();
        while (1) {
            char c = getch();
            if (c == 113) {
                ChooseStage();
                break;
            } else if (c == 27) {
                return 0;
            }
        }
        while (1) {
            char c_1 = getch();
            if (c_1 == 49) {
                bossNow = leize;
                break;
            } else if (c_1 == 50) {
                bossNow = yelan;
                break;
            } else if (c_1 == 27) {
                return 0;
            }
        }
        //选择角色
        ChoiceRole();
        //进行后续操作
        FundamentalMap();
        while (1) {
            if (wanna_escape == 1) {
                play = 0;
                break;
            }
            if (AP_own == 0 && AP_enemy > 0 && bossNow.HP > 0) {
                Sleep(1000);
                clear_BossCondition();
                if (element_num == 2) {
                    clear_BossElement();
                }
                bossAction();
            }
            if (AP_own == 0 && AP_enemy == 0) {
                if (zhongli_explode == 1) {
                    KillBossOnce();
                    zhongli_explode = 0;
                }
                if (yunjin_explode == 1) {
                    AddLifeOnce();
                    yunjin_explode = 0;
                }
            }
            if (bossNow.HP == 0 && (role_one.HP > 0 || role_two.HP > 0 || role_three.HP > 0)) {
                Sleep(1000);
                win();
                while (1) {
                    char out_win = getch();
                    if (out_win == 27) {
                        play = 0;
                        break;
                    } else if (out_win == 113) {
                        system("cls");
                        NewGame();
                        break;
                    }
                }
                break;
            }
            if (bossNow.HP > 0 && role_one.HP == 0 && role_two.HP == 0 && role_three.HP == 0) {
                Sleep(1000);
                lose();
                while (1) {
                    char out_lose = getch();
                    if (out_lose == 27) {
                        play = 0;
                        break;
                    } else if (out_lose == 113) {
                        system("cls");
                        NewGame();
                        break;
                    }
                }
                break;
            }
            if (AP_own == 0 && AP_enemy == 0) {
                NewRound();
            }
            Role *role_ifDie = DefineAllocate();
            if (role_ifDie != NULL && role_ifDie->HP == 0) {
                allocate_num = 0;
            }
            warProcess();
            if (NewChoice == 1) {
                system("cls");
                break;
            }
        }
    }
    // 游戏结束，我们要恢复光标显示
    cci.bVisible = TRUE;                        // 可见
    SetConsoleCursorInfo(consoleHandle, &cci);  // 重新设置
    return 0;
}

void warProcess() {
    // 有键盘敲击，我们获取是哪一个键
    char c_2 = getch();
    switch (c_2) {
        case left:
            leftRole();
            break;
        case right:
            rightRole();
            break;
        case change:
            if (AP_own < 1) {
                break;
            }
            clear_BossCondition();
            if (element_num == 2) {
                clear_BossElement();
            }
            allocate_num++;
            allocate();
            break;
        case require:
            DisplayMessage();
            break;
        case close:
            CloseMessage();
            break;
        case attack:
            if (AP_own == 0 || (DefineAllocate() != NULL && DefineAllocate()->HP == 0)) {
                break;
            }
            clear_BossCondition();
            if (element_num == 2) {
                clear_BossElement();
            }
            if (DefineAllocate() != NULL) {
                CommonAttack();
                Sleep(300);
                if (AP_enemy >= 1) {
                    Role *role = DefineAllocate();
                    EnemyAttack(role);
                }
            }
            break;
        case skill:
            if (AP_own < 3 || (DefineAllocate() != NULL && DefineAllocate()->HP == 0)) {
                break;
            }
            if (strcmp(bossNow.condition, "\0") != 0) {
                clear_BossCondition();
            }
            if (element_num == 2) {
                clear_BossElement();
            }
            if (DefineAllocate() != NULL) {
                SkillAttack();
                Sleep(300);
                if (AP_enemy >= 1) {
                    Role *role = DefineAllocate();
                    EnemyAttack(role);
                }
            }
            break;
        case escape:
            wanna_escape = 1;
            break;
        case explode:
            if (strcmp(bossNow.condition, "\0") != 0) {
                clear_BossCondition();
            }
            if (element_num == 2) {
                clear_BossElement();
            }
            if (DefineAllocate() != NULL) {
                Role *role_explode = DefineAllocate();
                if (AP_own >= 5 && role_explode->skill_2_num == 2 && role_explode->HP > 0) {
                    explode_Attack(role_explode);
                    Sleep(300);
                    if (AP_enemy >= 1) {
                        Role *role = DefineAllocate();
                        EnemyAttack(role);
                    }
                }
            }
            break;
        case require_boss:
            DisplaybossNow();
            break;
        case startAgain:
            NewChoice = 1;
            break;
        default:
            break;
    }
}

