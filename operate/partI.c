//
// Created by 5-1-302 on 2024/1/13.
//
#include "partI.h"
#include "partII.h"
#include "partIII.h"
#include <string.h>

HANDLE consoleHandle;// 操作控制台（也就是那个黑框框）需要的一个变量
int w, h;
COORD co;
int AP_enemy = enemy_originAP, AP_own = own_originAP;
Role yelan, xingqiu, zhongli, liulangzhe, yanfei, yunjin;
char allocate_save[15];
int allocate_num = 0;
//todo
int bossNowAction_num = 0;
int zhongli_explode = 0;
int yunjin_explode = 0;
int element_specialAttack = 0;
int element_num = 0;
Role bossNow, role_one, role_two, role_three;

Role leize = {
        .place={
                .X=boss_x,
                .Y=AP_line1
        },
        .name="雷泽",
        .skill_2="利爪苍雷",
        .skill_3="钢脊雷牙",
        .atk_2=3,
        .atk_2_copy="3",
        .atk_3=7,
        .atk_3_copy="7",
        .condition="\0",
        .atk_add=0,
        .HP=boss_HP,
        .skill_2_num=0,
        .element_effect="\0"
};

Role yelan = {
        .place={
                .X=boss_x,
                .Y=AP_line1
        },
        .name="夜兰",
        .skill_2="萦络纵命",
        .skill_3="渊图玲珑",
        .atk_2=3,
        .atk_2_copy="3",
        .atk_3=3,
        .atk_3_copy="3",
        .condition="\0",
        .atk_add=0,
        .HP=boss_HP,
        .skill_2_num=0,
        .element_effect="\0"
};

Role xingqiu = {
        .name="行秋",
        .skill_2="古华剑法",
        .skill_3="裁雨留虹",
        .atk_2=3,
        .atk_2_copy="3",
        .atk_3=5,
        .atk_3_copy="5",
        .condition="雨帘剑",
        .atk_add="眩晕",
        .HP=role_originHP,
        .ifChosen=0,
        .ifAllocate=0,
        .skill_2_num=0,
        .element="水"
};

Role zhongli = {
        .name="钟离",
        .skill_2="玉璋护盾",
        .skill_3="天动万象",
        .atk_2=3,
        .atk_2_copy="3",
        .atk_3=5,
        .atk_3_copy="5",
        .condition="岩脊",
        .atk_add="虚弱",//扣对方AP
        .HP=role_originHP,
        .ifChosen=0,
        .ifAllocate=0,
        .skill_2_num=0,
        .element="岩"
};

Role liulangzhe = {
        .name="散兵",
        .skill_2="风姿华歌",
        .skill_3="久世浮倾",
        .atk_2=3,
        .atk_2_copy="3",
        .atk_3=6,
        .atk_3_copy="6",
        .condition="羽画",
        .atk_add="流血",
        .HP=role_originHP,
        .ifChosen=0,
        .ifAllocate=0,
        .skill_2_num=0,
        .element="风"
};

Role yanfei = {
        .name="烟绯",
        .skill_2="丹书立约",
        .skill_3="凭火结契",
        .atk_2=3,
        .atk_2_copy="3",
        .atk_3=5,
        .atk_3_copy="5",
        .condition="炼宝印",
        .atk_add="眩晕",
        .HP=yanfei_originHP,
        .ifChosen=0,
        .ifAllocate=0,
        .skill_2_num=0,
        .element="火"
};

Role yunjin = {
        .name="云堇",
        .skill_2="旋云开相",
        .skill_3="破嶂见笙",
        .atk_2=3,
        .atk_2_copy="3",
        .atk_3=5,
        .atk_3_copy="5",
        .condition="拂云",
        .atk_add="虚弱",
        .HP=role_originHP,
        .ifChosen=0,
        .ifAllocate=0,
        .skill_2_num=0,
        .element="岩"
};

void printRole(int y, int x, Role role) {
    co.X = x;
    co.Y = y;
    SetConsoleCursorPosition(consoleHandle, co);
    printf("+");
    for (int i = 1; i <= 7; i++) {
        printf("-");
    }
    printf("+");
    co.Y++;
    SetConsoleCursorPosition(consoleHandle, co);
    for (int i = 1; i <= 4; i++) {
        printf("|");
        for (int j = 2; j <= 8; j++) {
            if (i == 1) {
                if (strcmp(role.name, "夜兰") == 0 || strcmp(role.name, "雷泽") == 0) {
                    printf("%d     ", role.HP);
                } else if (strcmp(role.name, "烟绯") == 0 && role.HP >= 10) {
                    printf("%d   \033[1;31m%s\033[0m", role.HP, role.element);
                } else {
                    if (strcmp(role.name, "烟绯") == 0) {
                        printf("%d    \033[1;31m%s\033[0m", role.HP, role.element);
                    } else if (strcmp(role.name, "行秋") == 0) {
                        printf("%d    \033[1;34m%s\033[0m", role.HP, role.element);
                    } else if (strcmp(role.name, "散兵") == 0) {
                        printf("%d    \033[1;36m%s\033[0m", role.HP, role.element);
                    } else if (strcmp(role.name, "钟离") == 0) {
                        printf("%d    \033[1;33m%s\033[0m", role.HP, role.element);
                    } else if (strcmp(role.name, "云堇") == 0) {
                        printf("%d    \033[1;33m%s\033[0m", role.HP, role.element);
                    }
                }
                break;
            } else {
                printf(" ");
            }
        }
        printf("|");
        co.Y++;
        SetConsoleCursorPosition(consoleHandle, co);
    }
    printf("+");
    for (int i = 1; i <= 7; i++) {
        printf("-");
    }
    printf("+");
    locateCursor(y, x);
    co.X += 2;
    co.Y += 2;
    SetConsoleCursorPosition(consoleHandle, co);
    printf("%s", role.name);
    if (role.ifChosen) {
        printNOW(y, x);
    }
}

void locateCursor(int y, int x) {
    co.X = x;
    co.Y = y;
    SetConsoleCursorPosition(consoleHandle, co);  // 设置你的光标位置
}

void start(void) {
    locateCursor(12, 15);
    printf(" __   ___              __                  __            ___    __          ___  __   __  \n");
    locateCursor(13, 15);
    printf("/ _` |__  |\\ | | |  | /__`    | |\\ | \\  / /  \\ |__/  /\\   |  | /  \\ |\\ |     |  /  ` / _` \n");
    locateCursor(14, 15);
    printf("\\__> |___ | \\| | \\__/ .__/    | | \\|  \\/  \\__/ |  \\ /~~\\  |  | \\__/ | \\|     |  \\__, \\__> \n");
    locateCursor(15, 92);
    printf("七圣召唤");

    locateCursor(17, 93);
    printf("\033[2m");
    printf("按Q开始游戏");
    locateCursor(18, 93);
    printf("按Esc键退出");
    printf("\033[0m");
}

void printBorder(char border, int length) {
    for (int i = 0; i < length; i++) {
        printf("%c", border);
    }
    printf("\n");
}

void recordAP(int y, int x, int num) {
    locateCursor(y, x);
    printf("     ");
    locateCursor(y, x);
    printf("AP:%d", num);
}

void recordCondition(int y, int x, char *str) {
    locateCursor(y + 1, x + 8);
    printf("%s", str);
}

void operationTip() {
    locateCursor(mapLength, 0);
    printf("</>左右切换选择角色\n"
           "A键发动攻击，需要1点行动点（AP）\n"
           "E键使用元素战技，需要3点行动点，使用一次积累1点战技，最多2点\n"
           "Q键使用元素爆发，需要5点行动点和2点战技\n"
           "C键选择该人物出场，切换时需要1点行动点\n"
           "I/O键查看/关闭当前卡牌信息（攻击/元素战技/元素爆发效果）\n"
           "J键查看敌方卡牌信息（攻击/元素战技/元素爆发效果）\n");
}

void ClearSide(int line) {
    locateCursor(line, mapBroader);
    for (int i = 0; i < (w - mapBroader); i++) {
        printf(" ");
    }
}

void warNote() {
    locateCursor(messagePart, mapBroader);
    for (int j = 0; j < (w - mapBroader); j++) {
        printf("-");
    }
    locateCursor(messagePart + 1, mapBroader);
    printf("战斗日志:");

}

void FundamentalMap() {
    system("cls");

    locateCursor(0, 0);
    printBorder('@', mapBroader);
    // Print right border
    for (int i = 2; i < mapLength; i++) {
        printf("@");
        for (int j = 2; j < mapBroader; j++) {
            printf(" ");
        }
        printf("@\n");
    }
    printBorder('@', mapBroader);
    locateCursor(1, 1);
    printf("\033[2m");
    printf("按Enter键返回到最初");
    printf("\033[0m");

    printRole(bossNow.place.Y, bossNow.place.X, bossNow);
    printRole(role_one.place.Y, role_one.place.X, role_one);
    printRole(role_two.place.Y, role_two.place.X, role_two);
    printRole(role_three.place.Y, role_three.place.X, role_three);

    recordAP(AP_line1, AP_x, AP_enemy);
    recordAP(AP_line2, AP_x, AP_own);

    operationTip();
    warNote();
}


////角色实现功能





void Moveout(Role *role) {
    clear_RoleCondition(role);
    role->place.Y -= 2;
    printRole((*role).place.Y, (*role).place.X, (*role));
    locateCursor((*role).place.Y + 6, (*role).place.X);
    printf("         ");
    locateCursor((*role).place.Y + 7, (*role).place.X);
    printf("         ");
    (*role).ifAllocate++;
    PrintSkillNum(role);
}

void comeBack(Role *role) {
    clear_RoleCondition(role);
    if ((*role).ifAllocate) {
        (*role).place.Y += 2;
        (*role).ifAllocate = 0;
    }
    locateCursor((*role).place.Y - 1, (*role).place.X);
    printf("                  ");
    locateCursor((*role).place.Y - 2, (*role).place.X);
    printf("                  ");
    printRole((*role).place.Y, (*role).place.X, (*role));
    PrintSkillNum(role);
}

void switchNOW(Role *role, bool ifLeft) {
    Deselect((*role).place.Y, (*role).place.X);
    (*role).ifChosen = 0;
    if (ifLeft) {
        printNOW((*role).left->place.Y, (*role).left->place.X);
        (*role).left->ifChosen = 1;
    } else {
        printNOW((*role).right->place.Y, (*role).right->place.X);
        (*role).right->ifChosen = 1;
    }
}

void leftRole() {
    if (role_two.ifChosen) {
        switchNOW(&role_two, 1);
    } else if (role_three.ifChosen) {
        switchNOW(&role_three, 1);
    }
}

void rightRole() {
    if (role_two.ifChosen) {
        switchNOW(&role_two, 0);
    } else if (role_one.ifChosen) {
        switchNOW(&role_one, 0);
    }
}

void printNOW(int y, int x) {
    locateCursor(y + 3, x + 2);
    printf("[NOW]");
}

void Deselect(int y, int x) {
    locateCursor(y + 3, x + 2);
    printf("     ");
}

Role *DefineAllocate(void) {
    if (role_one.ifAllocate) {
        return &role_one;
    } else if (role_two.ifAllocate) {
        return &role_two;
    } else if (role_three.ifAllocate) {
        return &role_three;
    } else {
        return NULL;
    }
}

void allocate(void) {
    Role *role = DefineChosen();
    if (role->HP == 0) {
        return;
    }

    Role *origin = DefineAllocate();
    if (origin != NULL) {
        strcpy(allocate_save, origin->name);
    }

    if (role->ifAllocate == 1) {
        return;
    }
    Moveout(role);
    if ((*role).left != NULL) {
        comeBack((*role).left);
        if ((*role).left->left != NULL) {
            comeBack((*role).left->left);
        }
    }
    if ((*role).right != NULL) {
        comeBack((*role).right);
        if ((*role).right->right != NULL) {
            comeBack((*role).right->right);
        }
    }
    if (allocate_num != 1) {
        AP_own -= 1;
        recordAP(AP_line2, AP_x, AP_own);
        allocate_record();
    }

}

Role *DefineChosen() {
    if (role_one.ifChosen) {
        return &role_one;
    } else if (role_two.ifChosen) {
        return &role_two;
    } else {
        return &role_three;
    }
}

void CloseMessage() {
    for (int i = 0; i < messagePart; i++) {
        locateCursor(i, mapBroader);
        for (int j = 0; j < (w - mapBroader); j++) {
            printf(" ");
        }
    }
}

void DisplayMessage() {
    CloseMessage();
    Role *role = DefineChosen();
    locateCursor(0, mapBroader);
    printf("卡牌信息：");
    locateCursor(1, mapBroader);
    if (strcmp(role->name, "烟绯") == 0) {
        printf("  烟绯（天赋：生命值＋3）");
    } else {
        printf("  %s", role->name);
    }
    locateCursor(2, mapBroader);
    printf("    普通攻击：敌方生命-%d", atk_1);
    locateCursor(3, mapBroader);
    printf("    %s：敌方生命-%d，陷入%s一回合", role->skill_2, role->atk_2, role->atk_add);

    if (strcmp(role->name, "行秋") == 0) {
        locateCursor(4, mapBroader);
        printf("    %s:敌方无法行动", role->atk_add);
        locateCursor(5, mapBroader);
        printf("    %s：敌方生命-%d，自身生命+%d", role->skill_3, role->atk_3, xingqiu_rewound);
    } else if (strcmp(role->name, "钟离") == 0) {
        locateCursor(4, mapBroader);
        printf("    %s:敌方AP-1", role->atk_add);
        locateCursor(5, mapBroader);
        printf("    %s：敌方生命-%d，且该回合末敌方", role->skill_3, role->atk_3);
        locateCursor(6, mapBroader);
        printf("  生命额外-1");
    } else if (strcmp(role->name, "散兵") == 0) {
        locateCursor(4, mapBroader);
        printf("    %s:敌方生命额外-1", role->atk_add);
        locateCursor(5, mapBroader);
        printf("    %s：敌方生命-%d", role->skill_3, role->atk_3);
    } else if (strcmp(role->name, "烟绯") == 0) {
        locateCursor(4, mapBroader);
        printf("    %s:敌方无法行动", role->atk_add);
        locateCursor(5, mapBroader);
        printf("    %s：敌方生命-%d", role->skill_3, role->atk_3);
    } else if (strcmp(role->name, "云堇") == 0) {
        locateCursor(4, mapBroader);
        printf("    %s:敌方AP-1", role->atk_add);
        locateCursor(5, mapBroader);
        printf("    %s：敌方生命-%d，且该回合末自身", role->skill_3, role->atk_3);
        locateCursor(6, mapBroader);
        printf("  生命额外+1");
    }

}

void DisplaybossNow(void) {
    CloseMessage();
    locateCursor(0, mapBroader);
    printf("卡牌信息：");
    locateCursor(1, mapBroader);
    printf("  %s", bossNow.name);
    locateCursor(2, mapBroader);
    printf("    普通攻击：敌方生命-%d，消耗1点AP", atk_1);
    locateCursor(3, mapBroader);
    printf("    %s：敌方生命-%d，消耗2点AP，每", bossNow.skill_2, bossNow.atk_2);
    locateCursor(4, mapBroader);
    printf("  两次普通攻击后自动触发");
    locateCursor(5, mapBroader);
    if (strcmp(bossNow.name, yelan.name) == 0) {
        printf("    %s：敌方生命-%d，自身生命+%d，消", bossNow.skill_3, bossNow.atk_3, yelan_rewound);
        locateCursor(6, mapBroader);
        printf("  耗5点AP，AP为5时自动触发");
    } else if (strcmp(bossNow.name, leize.name) == 0) {
        printf("    %s：敌方生命-%d，消耗5点AP，AP", bossNow.skill_3, bossNow.atk_3);
        locateCursor(6, mapBroader);
        printf("  为5时自动触发");
    }
}
