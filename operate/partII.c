//
// Created by 5-1-302 on 2024/1/17.
//

#include "partII.h"
#include "partI.h"
#include "partIII.h"

int recordLine = warNoteLine + 1;
char logRecord[40][45] = {0};

void allocate_record(void) {
    Role *role = DefineAllocate();
    if (role == NULL) {
        return;
    }
    if (recordLine == maxLogLine) {
        MoveUpFile();
    }
    locateCursor(recordLine, mapBroader);
    printf("-%s替换%s", role->name, allocate_save);

    strcat(logRecord[recordLine], "-");
    strcat(logRecord[recordLine], role->name);
    strcat(logRecord[recordLine], "替换");
    strcat(logRecord[recordLine], allocate_save);
    recordLine++;
}

void NewRound(void) {
    if (recordLine == maxLogLine) {
        MoveUpFile();
    }
    locateCursor(recordLine, mapBroader);
    printf("-进入新的回合");
    strcpy(logRecord[recordLine], "-进入新的回合");
    recordLine++;
    AP_enemy = enemy_originAP;
    AP_own = own_originAP;
    recordAP(AP_line1, AP_x, AP_enemy);
    recordAP(AP_line2, AP_x, AP_own);
}

void MoveUpFile(void) {
    //todoe
    // 清屏和逐项输出，并且对数组进行重新赋值，并修改record——line
    for (int i = warNoteLine + 1; i < maxLogLine; i++) {
        ClearSide(i);
    }
    for (int i = warNoteLine + 1; i < (maxLogLine - 1); i++) {
        strcpy(logRecord[i], logRecord[i + 1]);
        locateCursor(i, mapBroader);
        printf("%s", logRecord[i]);
    }
    strcpy(logRecord[maxLogLine - 1], "\0");
    recordLine--;
}

void NowActionParty(int line) {
    locateCursor(line + 1, AP_x);
    printf("[*]");
}

void ClearLastParty(int line) {
    locateCursor(line + 1, AP_x);
    printf("   ");
}

void clear_RoleCondition(Role *role) {
    locateCursor(role->place.Y + 1, role->place.X + 9);
    printf("         ");
}

void clear_BossCondition(void) {
    locateCursor(bossNow.place.Y + 1, bossNow.place.X + 9);
    printf("      ");
    strcpy(bossNow.condition, "\0");
}
////

void CommonAttack_RoleChange() {
    AP_own--;
    recordAP(AP_line2, AP_x, AP_own);
    bossNow.HP -= atk_1;
    if (bossNow.HP < 0) {
        bossNow.HP = 0;
    }
    locateCursor(bossNow.place.Y + 1, bossNow.place.X + 1);
    printf("%d ", bossNow.HP);
}

void CommonAttack_record(Role *role) {
    if (recordLine == maxLogLine) {
        MoveUpFile();
    }
    locateCursor(recordLine, mapBroader);
    printf("-%s对%s使用普通攻击，%s生命-%d", role->name, bossNow.name, bossNow.name, atk_1);
    strcat(logRecord[recordLine], "-");
    strcat(logRecord[recordLine], role->name);
    if (strcmp(bossNow.name, "夜兰") == 0) {
        strcat(logRecord[recordLine], "对夜兰使用普通攻击，夜兰生命-");
    } else {
        strcat(logRecord[recordLine], "对雷泽使用普通攻击，雷泽生命-");
    }
    char str[2] = {0};
    sprintf(str, "%d", atk_1);
    strcat(logRecord[recordLine], str);
    recordLine++;
}

void CommonAttack() {
    element_specialAttack = 1;
    Role *role = DefineAllocate();
    if (role != NULL) {
        CommonAttack_record(role);
        CommonAttack_RoleChange();
    }
    ClearLastParty(AP_line1);
    NowActionParty(AP_line2);
}

void SkillAttack_RoleChange(Role *role) {
    AP_own -= 3;
    recordAP(AP_line2, AP_x, AP_own);
    bossNow.HP -= role->atk_2;
    if (bossNow.HP < 0) {
        bossNow.HP = 0;
    }
    locateCursor(bossNow.place.Y + 1, bossNow.place.X + 1);
    printf("%d ", bossNow.HP);

    locateCursor(bossNow.place.Y + 1, bossNow.place.X + 9);
    printf("%s", role->atk_add);
    strcpy(bossNow.condition, role->atk_add);

    if (element_num == 0) {
        locateCursor(bossNow.place.Y - 1, bossNow.place.X);
        PrintElement(role);
        strcat(bossNow.element_effect, role->element);
        element_num++;
    } else {
        if (strcmp(bossNow.element_effect, role->element) != 0) {
            locateCursor(bossNow.place.Y - 1, bossNow.place.X + 3);
            PrintElement(role);
            strcat(bossNow.element_effect, role->element);
            element_specialAttack = 2;
            Element_react(role);
            element_num++;
        }
    }


    if (role->skill_2_num < 2) {
        role->skill_2_num++;
    }
    if (role->skill_2_num <= 2) {
        locateCursor(role->place.Y + 1, role->place.X + 9);
        printf("%s(%d)", role->condition, role->skill_2_num);
    }

}

void SkillAttack_record(Role *role) {
    if (recordLine == maxLogLine) {
        MoveUpFile();
    }
    locateCursor(recordLine, mapBroader);
    printf("-%s对%s使用%s，%s生命-%d且陷", role->name, bossNow.name, role->skill_2, bossNow.name, role->atk_2);

    strcat(logRecord[recordLine], "-");
    strcat(logRecord[recordLine], role->name);
    if (strcmp(bossNow.name, "夜兰") == 0) {
        strcat(logRecord[recordLine], "对夜兰使用");
        strcat(logRecord[recordLine], role->skill_2);
        strcat(logRecord[recordLine], "，夜兰生命-");
    } else {
        strcat(logRecord[recordLine], "对雷泽使用");
        strcat(logRecord[recordLine], role->skill_2);
        strcat(logRecord[recordLine], "，雷泽生命-");
    }
    strcat(logRecord[recordLine], role->atk_2_copy);
    strcat(logRecord[recordLine], "且陷");

    recordLine++;

    if (recordLine == maxLogLine) {
        MoveUpFile();
    }
    locateCursor(recordLine, mapBroader);
    printf("入%s一回合,%s获得%s", role->atk_add, role->name, role->condition);

    strcat(logRecord[recordLine], "入");
    strcat(logRecord[recordLine], role->atk_add);
    strcat(logRecord[recordLine], "一回合，");
    strcat(logRecord[recordLine], role->name);
    strcat(logRecord[recordLine], "获得");
    strcat(logRecord[recordLine], role->condition);

    recordLine++;

}

void SkillAttack() {
    Role *role = DefineAllocate();
    if (role == NULL) {
        return;
    }
    SkillAttack_record(role);
    SkillAttack_RoleChange(role);
    ClearLastParty(AP_line1);
    NowActionParty(AP_line2);
}

void explode_Attack(Role *role) {

    explodeAttack_record(role);
    explodeAttack_RoleChange(role);

    ClearLastParty(AP_line1);
    NowActionParty(AP_line2);
}

void explodeAttack_record(Role *role) {
    if (recordLine == maxLogLine) {
        MoveUpFile();
    }
    locateCursor(recordLine, mapBroader);
    printf("-%s对%s使用技能%s，%s生命-%d", role->name, bossNow.name, role->skill_3, bossNow.name, role->atk_3);

    strcat(logRecord[recordLine], "-");
    strcat(logRecord[recordLine], role->name);
    if (strcmp(bossNow.name, "夜兰") == 0) {
        strcat(logRecord[recordLine], "对夜兰使用");
        strcat(logRecord[recordLine], role->skill_3);
        strcat(logRecord[recordLine], "，夜兰生命-");
    } else {
        strcat(logRecord[recordLine], "对雷泽使用");
        strcat(logRecord[recordLine], role->skill_3);
        strcat(logRecord[recordLine], "，雷泽生命-");
    }
    strcat(logRecord[recordLine], role->atk_3_copy);

    recordLine++;

    if (recordLine == maxLogLine) {
        MoveUpFile();
    }
    locateCursor(recordLine, mapBroader);

    if (strcmp(role->skill_3, "裁雨留虹") == 0) {
        printf("并且行秋血量+1");
        strcat(logRecord[recordLine], "并且行秋血量+1");
        recordLine++;
    } else if (strcmp(role->skill_3, "天动万象") == 0) {
        printf("并且该回合末对方生命额外-1");
        strcat(logRecord[recordLine], "并且该回合末对方生命额外-1");
        recordLine++;
    } else if (strcmp(role->skill_3, "破嶂见笙") == 0) {
        printf("并且该回合末云堇生命额外+1");
        strcat(logRecord[recordLine], "并且该回合末云堇生命额外+1");
        recordLine++;
    }
}

void explodeAttack_RoleChange(Role *role) {
    AP_own -= 5;
    recordAP(AP_line2, AP_x, AP_own);

    bossNow.HP -= role->atk_3;

    if (bossNow.HP < 0) {
        bossNow.HP = 0;
    }

    locateCursor(bossNow.place.Y + 1, bossNow.place.X + 1);
    printf("%d ", bossNow.HP);

    if (element_num == 0) {
        locateCursor(bossNow.place.Y - 1, bossNow.place.X);
        PrintElement(role);
        strcat(bossNow.element_effect, role->element);
        element_num++;
    } else {
        if (strcmp(bossNow.element_effect, role->element) != 0) {
            locateCursor(bossNow.place.Y - 1, bossNow.place.X + 3);
            PrintElement(role);
            strcat(bossNow.element_effect, role->element);
            element_specialAttack = 3;
            Element_react(role);
            element_num++;
        }
    }


    clear_RoleCondition(role);
    role->skill_2_num = 0;

    if (strcmp(role->name, "行秋") == 0) {
        role->HP++;
        if (role->HP > role_originHP) {
            role->HP = role_originHP;
        }
        locateCursor(role->place.Y + 1, role->place.X + 1);
        printf("%d ", role->HP);
    } else if (strcmp(role->name, "钟离") == 0) {
        zhongli_explode = 1;
    } else if (strcmp(role->name, "云堇") == 0) {
        yunjin_explode = 1;
    }

}

////
void BossExplodeRecord(Role *role) {
    if (recordLine == maxLogLine) {
        MoveUpFile();
    }
    locateCursor(recordLine, mapBroader);


    if (strcmp(bossNow.name, "夜兰") == 0) {
        printf("-%s对%s使用%s，%s生命-%d并且", bossNow.name, role->name, bossNow.skill_3, role->name, bossNow.atk_3);
        strcat(logRecord[recordLine], "-夜兰对");
        strcat(logRecord[recordLine], role->name);
        strcat(logRecord[recordLine], "使用");
        strcat(logRecord[recordLine], bossNow.skill_3);
        strcat(logRecord[recordLine], "，");
        strcat(logRecord[recordLine], role->name);
        strcat(logRecord[recordLine], "生命-");
        strcat(logRecord[recordLine], bossNow.atk_3_copy);
        strcat(logRecord[recordLine], "并且");

        recordLine++;

        if (recordLine == maxLogLine) {
            MoveUpFile();
        }
        locateCursor(recordLine, mapBroader);
        printf("夜兰生命+%d", yelan_rewound);

        strcat(logRecord[recordLine], "夜兰生命+");
        strcat(logRecord[recordLine], yelan_rewoundCopy);

        recordLine++;
    } else {
        printf("-%s对%s使用%s，%s生命-%d", bossNow.name, role->name, bossNow.skill_3, role->name, bossNow.atk_3);
        strcat(logRecord[recordLine], "-雷泽对");
        strcat(logRecord[recordLine], role->name);
        strcat(logRecord[recordLine], "使用");
        strcat(logRecord[recordLine], bossNow.skill_3);
        strcat(logRecord[recordLine], "，");
        strcat(logRecord[recordLine], role->name);
        strcat(logRecord[recordLine], "生命-");
        strcat(logRecord[recordLine], bossNow.atk_3_copy);
        recordLine++;
    }
}

void BossExplodeAttack(Role *role) {
    AP_enemy -= 5;
    recordAP(AP_line1, AP_x, AP_enemy);

    role->HP -= bossNow.atk_3;
    if (role->HP < 0) {
        role->HP = 0;
    }
    locateCursor(role->place.Y + 1, role->place.X + 1);
    printf("%d ", role->HP);

    if (strcmp(bossNow.name, "夜兰") == 0) {
        bossNow.HP += 4;
        if (bossNow.HP > boss_HP) {
            bossNow.HP = boss_HP;
        }
        locateCursor(bossNow.place.Y + 1, bossNow.place.X + 1);
        printf("%d ", bossNow.HP);
    }

    BossExplodeRecord(role);

}

void EnemySkillAttack(Role *role) {
    AP_enemy -= 2;
    recordAP(AP_line1, AP_x, AP_enemy);

    role->HP -= bossNow.atk_2;
    if (role->HP < 0) {
        role->HP = 0;
    }
    locateCursor(role->place.Y + 1, role->place.X + 1);
    printf("%d ", role->HP);
    //普攻点数清零
    bossNowAction_num = 0;
    //log
    if (recordLine == maxLogLine) {
        MoveUpFile();
    }
    locateCursor(recordLine, mapBroader);
    if (strcmp(bossNow.name, "夜兰") == 0) {
        printf("-夜兰对%s使用%s，%s生命-%d", role->name, bossNow.skill_2, role->name, bossNow.atk_2);

        strcat(logRecord[recordLine], "-夜兰对");
    } else {
        printf("-雷泽对%s使用%s，%s生命-%d", role->name, bossNow.skill_2, role->name, bossNow.atk_2);
        strcat(logRecord[recordLine], "-雷泽对");
    }
    strcat(logRecord[recordLine], role->name);
    strcat(logRecord[recordLine], "使用");
    strcat(logRecord[recordLine], bossNow.skill_2);
    strcat(logRecord[recordLine], "，");
    strcat(logRecord[recordLine], role->name);
    strcat(logRecord[recordLine], "生命-");
    strcat(logRecord[recordLine], bossNow.atk_2_copy);

    recordLine++;
}

void EnemyAttack(Role *role) {
    if (strcmp(bossNow.condition, "眩晕") == 0) {
        return;
    } else if (strcmp(bossNow.condition, "虚弱") == 0) {
        AP_enemy--;
        if (AP_enemy < 0) {
            AP_enemy = 0;
        }
        recordAP(AP_line1, AP_x, AP_enemy);
    } else if (strcmp(bossNow.condition, "流血") == 0) {
        bossNow.HP--;
        if (bossNow.HP < 0) {
            bossNow.HP = 0;
        }
        locateCursor(bossNow.place.Y + 1, bossNow.place.X + 1);
        printf("%d ", bossNow.HP);
    }

    if (bossNow.HP == 0 || AP_enemy == 0) {
        return;
    }
    if (role == NULL) {
        return;
    }
    ClearLastParty(AP_line2);
    NowActionParty(AP_line1);

    if (AP_enemy == 5) {
        BossExplodeAttack(role);
        return;
    }

    if (bossNowAction_num == 2 && AP_enemy >= 2) {
        EnemySkillAttack(role);
        return;
    }

    AP_enemy--;
    recordAP(AP_line1, AP_x, AP_enemy);
    role->HP -= atk_1;
    if (role->HP < 0) {
        role->HP = 0;
    }
    locateCursor(role->place.Y + 1, role->place.X + 1);
    printf("%d ", role->HP);
    //累加普攻点数
    bossNowAction_num++;
    //log
    if (recordLine == maxLogLine) {
        MoveUpFile();
    }
    locateCursor(recordLine, mapBroader);
    printf("-%s对%s使用普通攻击，%s生命-%d", bossNow.name, role->name, role->name, atk_1);

    strcat(logRecord[recordLine], "-");
    strcat(logRecord[recordLine], bossNow.name);
    strcat(logRecord[recordLine], "对");
    strcat(logRecord[recordLine], role->name);
    strcat(logRecord[recordLine], "使用普通攻击，");
    strcat(logRecord[recordLine], role->name);
    strcat(logRecord[recordLine], "生命-");
    strcat(logRecord[recordLine], atk_1_copy);

    recordLine++;
}

void bossAction(void) {
    if (recordLine == maxLogLine) {
        MoveUpFile();
    }
    locateCursor(recordLine, mapBroader);
    printf("-您的点数清空，对方发动连续攻击");
    strcpy(logRecord[recordLine], "-您的点数清空，对方发动连续攻击");
    recordLine++;
    Sleep(300);

    while (role_one.HP != 0 && AP_enemy > 0) {
        EnemyAttack(&role_one);
        Sleep(1000);
    }
    if (role_one.HP > 0) {
        return;
    }
    while (role_two.HP != 0 && AP_enemy > 0) {
        EnemyAttack(&role_two);
        Sleep(1000);
    }
    if (role_two.HP > 0) {
        return;
    }
    while (role_three.HP != 0 && AP_enemy > 0) {
        EnemyAttack(&role_three);
        Sleep(1000);
    }
}

//////
void win(void) {
    system("cls");
    locateCursor(h / 2 - 1, w / 2 - 9);// 设置你的光标位置
    printf("恭喜，你赢得了胜利！\n");
    locateCursor(h / 2, w / 2 - 9);
    printf("按Q重新开始\n");
    locateCursor(h / 2 + 1, w / 2 - 9);
    printf("按Esc退出\n");
}

void lose(void) {
    system("cls");
    locateCursor(h / 2 - 1, w / 2 - 9);
    SetConsoleCursorPosition(consoleHandle, co);  // 设置你的光标位置
    printf("非常遗憾，你失败了！\n");
    locateCursor(h / 2, w / 2 - 9);
    printf("按Q重新开始\n");
    locateCursor(h / 2 + 1, w / 2 - 9);
    printf("按Esc退出\n");
}







