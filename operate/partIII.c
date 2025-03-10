//
// Created by 5-1-302 on 2024/1/21.
//
#include "partIII.h"
#include "partII.h"
#include "partI.h"

//some operations to simplify and NewFunction
void KillBossOnce(void) {
    bossNow.HP--;
    locateCursor(bossNow.place.Y + 1, bossNow.place.X + 1);
    printf("%d ", bossNow.HP);
}

void AddLifeOnce(void) {
    if (strcmp(role_one.name, "云堇") == 0) {
        role_one.HP++;
        locateCursor(role_one.place.Y + 1, role_one.place.X + 1);
        printf("%d ", role_one.HP);
    } else if (strcmp(role_two.name, "云堇") == 0) {
        role_two.HP++;
        locateCursor(role_two.place.Y + 1, role_two.place.X + 1);
        printf("%d ", role_two.HP);
    } else {
        role_three.HP++;
        locateCursor(role_three.place.Y + 1, role_three.place.X + 1);
        printf("%d ", role_three.HP);
    }
}

void PrintSkillNum(Role *role) {
    if (role->skill_2_num <= 2 && role->skill_2_num > 0) {
        locateCursor(role->place.Y + 1, role->place.X + 9);
        printf("%s(%d)", role->condition, role->skill_2_num);
    }
}

void ChooseStage(void) {
    system("cls");
    locateCursor(13, 45);
    printf("请选择关卡：");
    locateCursor(14, 45);
    printf("关卡1：雷泽（按1选择该关卡）");
    locateCursor(15, 45);
    printf("关卡2：夜兰（按2选择该关卡）");
}

void NewGame(void) {
    //一些全局变量
    allocate_num = 0;
    bossNowAction_num = 0;
    zhongli_explode = 0;
    yunjin_explode = 0;
    element_num = 0;
    //清空日志记录
    recordLine = warNoteLine + 1;
    memset(logRecord, '\0', 1800);
    //todo
    //AP点数回归
    AP_own = own_originAP;
    AP_enemy = enemy_originAP;
    //卡牌展示回归到原来
}

void YouHaveChosen(int num, int order) {

    locateCursor(22, 55 + (order - 1) * 2);
    if (order == 3) {
        printf("%d", num);
    } else {
        printf("%d,", num);
    }

}

void PrintElement(Role *role) {
    if (strcmp(role->name, "烟绯") == 0) {
        printf("\033[1;31m%s\033[0m", role->element);
    } else if (strcmp(role->name, "行秋") == 0) {
        printf("\033[1;34m%s\033[0m", role->element);
    } else if (strcmp(role->name, "散兵") == 0) {
        printf("\033[1;36m%s\033[0m", role->element);
    } else if (strcmp(role->name, "钟离") == 0) {
        printf("\033[1;33m%s\033[0m", role->element);
    } else if (strcmp(role->name, "云堇") == 0) {
        printf("\033[1;33m%s\033[0m", role->element);
    }
}

void ChoiceRole(void) {
    enum {
        yanFei = 49,
        yunJin = 50,
        xingQiu = 51,
        zhongLi = 52,
        sanBing = 53
    };

    system("cls");
    locateCursor(8, 45);
    printf("请在如下五个角色中选择三个角色");
    printf("\033[2m");
    printf("（不可取消选择，可以重复选择）");
    printf("\033[0m");

    locateCursor(10, 45);
    printf("1.烟绯（火）（按1选择）");
    locateCursor(11, 45);
    printf("\033[2m元素战技：眩晕/元素爆发：对敌方造成五点伤害/具有生命天赋");
    printf("\033[0m");

    locateCursor(12, 45);
    printf("2.云堇（岩）（按2选择）");
    locateCursor(13, 45);
    printf("\033[2m元素战技：虚弱/元素爆发：对敌方造成五点伤害，并且回合末自身生命+1");
    printf("\033[0m");

    locateCursor(14, 45);
    printf("3.行秋（水）（按3选择）");
    locateCursor(15, 45);
    printf("\033[2m元素战技：眩晕/元素爆发：对敌方造成五点伤害，并且自身生命立即+1");
    printf("\033[0m");

    locateCursor(16, 45);
    printf("4.钟离（岩）（按4选择）");
    locateCursor(17, 45);
    printf("\033[2m元素战技：虚弱/元素爆发：对敌方造成五点伤害，并且回合末敌方生命-1");
    printf("\033[0m");

    locateCursor(18, 45);
    printf("5.散兵（风）（按5选择）");
    locateCursor(19, 45);
    printf("\033[2m元素战技：流血/元素爆发：对敌方造成六点伤害");
    printf("\033[0m");

    locateCursor(22, 45);
    printf("您已选择：");

    printf("\033[2m");
    locateCursor(23, 45);
    printf("按Q开始游戏");
    printf("\033[0m");

    for (int i = 1; i <= 3; i++) {
        char choice = getch();
        switch (choice) {
            case yanFei:
                if (i == 1) {
                    role_one = yanfei;
                } else if (i == 2) {
                    role_two = yanfei;
                } else {
                    role_three = yanfei;
                }
                YouHaveChosen(1, i);
                break;
            case yunJin:
                if (i == 1) {
                    role_one = yunjin;
                } else if (i == 2) {
                    role_two = yunjin;
                } else {
                    role_three = yunjin;
                }
                YouHaveChosen(2, i);
                break;
            case xingQiu:
                if (i == 1) {
                    role_one = xingqiu;
                } else if (i == 2) {
                    role_two = xingqiu;
                } else {
                    role_three = xingqiu;
                }
                YouHaveChosen(3, i);
                break;
            case zhongLi:
                if (i == 1) {
                    role_one = zhongli;
                } else if (i == 2) {
                    role_two = zhongli;
                } else {
                    role_three = zhongli;
                }
                YouHaveChosen(4, i);
                break;
            case sanBing:
                if (i == 1) {
                    role_one = liulangzhe;
                } else if (i == 2) {
                    role_two = liulangzhe;
                } else {
                    role_three = liulangzhe;
                }
                YouHaveChosen(5, i);
                break;
            default:
                i--;
                break;
        }
    }

    while (1) {
        char enterGame = getch();
        if (enterGame == 113) {
            break;
        }
    }

    role_one.place.X = role1_x;
    role_one.place.Y = AP_line2;
    role_one.left = NULL;
    role_one.right = &role_two;
    role_one.ifChosen = 1;

    role_two.place.X = role2_x;
    role_two.place.Y = AP_line2;
    role_two.left = &role_one;
    role_two.right = &role_three;

    role_three.place.X = role3_x;
    role_three.place.Y = AP_line2;
    role_three.left = &role_two;
    role_three.right = NULL;
}

void Element_react(Role *role) {
    if (recordLine == maxLogLine) {
        MoveUpFile();
    }
    locateCursor(recordLine, mapBroader);
    if (strcmp(bossNow.element_effect, "火岩") == 0 || strcmp(bossNow.element_effect, "岩火") == 0) {
        bossNow.HP--;
        if (bossNow.HP < 0) {
            bossNow.HP = 0;
        }

        printf("-火与岩反应，敌方生命-1");
        strcat(logRecord[recordLine], "-火与岩反应，敌方生命-1");

        locateCursor(bossNow.place.Y + 1, bossNow.place.X + 1);
        printf("%d ", bossNow.HP);
    } else if (strcmp(bossNow.element_effect, "水岩") == 0 || strcmp(bossNow.element_effect, "岩水") == 0) {
        role->HP++;
        if (strcmp(role->name, "烟绯") == 0) {
            if (role->HP > yanfei_originHP) {
                role->HP = yanfei_originHP;
            }
        } else {
            if (role->HP > role_originHP) {
                role->HP = role_originHP;
            }
        }

        printf("-水与岩反应，我方生命+1");
        strcat(logRecord[recordLine], "-水与岩反应，我方生命+1");

        locateCursor(role->place.Y + 1, role->place.X + 1);
        printf("%d ", role->HP);

    } else if (strcmp(bossNow.element_effect, "风岩") == 0 || strcmp(bossNow.element_effect, "岩风") == 0) {
        bossNow.HP--;
        if (bossNow.HP < 0) {
            bossNow.HP = 0;
        }
        printf("-风与岩反应，敌方生命-1");
        strcat(logRecord[recordLine], "-风与岩反应，敌方生命-1");

        locateCursor(bossNow.place.Y + 1, bossNow.place.X + 1);
        printf("%d ", bossNow.HP);
    } else if (strcmp(bossNow.element_effect, "水火") == 0 || strcmp(bossNow.element_effect, "火水") == 0) {
        if (element_specialAttack == 2) {
            bossNow.HP -= role->atk_2;
        } else if (element_specialAttack == 3) {
            bossNow.HP -= role->atk_3;
        }
        if (bossNow.HP < 0) {
            bossNow.HP = 0;
        }
        printf("-火与水反应，我方攻击力*2");
        strcat(logRecord[recordLine], "-火与水反应，我方攻击力*2");

        locateCursor(bossNow.place.Y + 1, bossNow.place.X + 1);
        printf("%d ", bossNow.HP);

    } else if (strcmp(bossNow.element_effect, "水风") == 0 || strcmp(bossNow.element_effect, "风水") == 0) {
        bossNow.HP++;
        if (bossNow.HP > boss_HP) {
            bossNow.HP = boss_HP;
        }
        printf("-水与风反应，敌方生命+1");
        strcat(logRecord[recordLine], "-水与岩反应，敌方生命+1");
        locateCursor(bossNow.place.Y + 1, bossNow.place.X + 1);
        printf("%d ", bossNow.HP);


    } else {
        printf("-火与风反应无效");
        strcat(logRecord[recordLine], "-火与风反应无效");
    }
    recordLine++;
}

void clear_BossElement(void) {
    locateCursor(bossNow.place.Y - 1, bossNow.place.X);
    printf("      ");
    strcpy(bossNow.element_effect, "\0");
    element_num = 0;
}








