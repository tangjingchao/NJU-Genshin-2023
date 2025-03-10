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
    printf("-%s�滻%s", role->name, allocate_save);

    strcat(logRecord[recordLine], "-");
    strcat(logRecord[recordLine], role->name);
    strcat(logRecord[recordLine], "�滻");
    strcat(logRecord[recordLine], allocate_save);
    recordLine++;
}

void NewRound(void) {
    if (recordLine == maxLogLine) {
        MoveUpFile();
    }
    locateCursor(recordLine, mapBroader);
    printf("-�����µĻغ�");
    strcpy(logRecord[recordLine], "-�����µĻغ�");
    recordLine++;
    AP_enemy = enemy_originAP;
    AP_own = own_originAP;
    recordAP(AP_line1, AP_x, AP_enemy);
    recordAP(AP_line2, AP_x, AP_own);
}

void MoveUpFile(void) {
    //todoe
    // ������������������Ҷ�����������¸�ֵ�����޸�record����line
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
    printf("-%s��%sʹ����ͨ������%s����-%d", role->name, bossNow.name, bossNow.name, atk_1);
    strcat(logRecord[recordLine], "-");
    strcat(logRecord[recordLine], role->name);
    if (strcmp(bossNow.name, "ҹ��") == 0) {
        strcat(logRecord[recordLine], "��ҹ��ʹ����ͨ������ҹ������-");
    } else {
        strcat(logRecord[recordLine], "������ʹ����ͨ��������������-");
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
    printf("-%s��%sʹ��%s��%s����-%d����", role->name, bossNow.name, role->skill_2, bossNow.name, role->atk_2);

    strcat(logRecord[recordLine], "-");
    strcat(logRecord[recordLine], role->name);
    if (strcmp(bossNow.name, "ҹ��") == 0) {
        strcat(logRecord[recordLine], "��ҹ��ʹ��");
        strcat(logRecord[recordLine], role->skill_2);
        strcat(logRecord[recordLine], "��ҹ������-");
    } else {
        strcat(logRecord[recordLine], "������ʹ��");
        strcat(logRecord[recordLine], role->skill_2);
        strcat(logRecord[recordLine], "����������-");
    }
    strcat(logRecord[recordLine], role->atk_2_copy);
    strcat(logRecord[recordLine], "����");

    recordLine++;

    if (recordLine == maxLogLine) {
        MoveUpFile();
    }
    locateCursor(recordLine, mapBroader);
    printf("��%sһ�غ�,%s���%s", role->atk_add, role->name, role->condition);

    strcat(logRecord[recordLine], "��");
    strcat(logRecord[recordLine], role->atk_add);
    strcat(logRecord[recordLine], "һ�غϣ�");
    strcat(logRecord[recordLine], role->name);
    strcat(logRecord[recordLine], "���");
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
    printf("-%s��%sʹ�ü���%s��%s����-%d", role->name, bossNow.name, role->skill_3, bossNow.name, role->atk_3);

    strcat(logRecord[recordLine], "-");
    strcat(logRecord[recordLine], role->name);
    if (strcmp(bossNow.name, "ҹ��") == 0) {
        strcat(logRecord[recordLine], "��ҹ��ʹ��");
        strcat(logRecord[recordLine], role->skill_3);
        strcat(logRecord[recordLine], "��ҹ������-");
    } else {
        strcat(logRecord[recordLine], "������ʹ��");
        strcat(logRecord[recordLine], role->skill_3);
        strcat(logRecord[recordLine], "����������-");
    }
    strcat(logRecord[recordLine], role->atk_3_copy);

    recordLine++;

    if (recordLine == maxLogLine) {
        MoveUpFile();
    }
    locateCursor(recordLine, mapBroader);

    if (strcmp(role->skill_3, "��������") == 0) {
        printf("��������Ѫ��+1");
        strcat(logRecord[recordLine], "��������Ѫ��+1");
        recordLine++;
    } else if (strcmp(role->skill_3, "�춯����") == 0) {
        printf("���Ҹûغ�ĩ�Է���������-1");
        strcat(logRecord[recordLine], "���Ҹûغ�ĩ�Է���������-1");
        recordLine++;
    } else if (strcmp(role->skill_3, "���ּ���") == 0) {
        printf("���Ҹûغ�ĩ������������+1");
        strcat(logRecord[recordLine], "���Ҹûغ�ĩ������������+1");
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

    if (strcmp(role->name, "����") == 0) {
        role->HP++;
        if (role->HP > role_originHP) {
            role->HP = role_originHP;
        }
        locateCursor(role->place.Y + 1, role->place.X + 1);
        printf("%d ", role->HP);
    } else if (strcmp(role->name, "����") == 0) {
        zhongli_explode = 1;
    } else if (strcmp(role->name, "����") == 0) {
        yunjin_explode = 1;
    }

}

////
void BossExplodeRecord(Role *role) {
    if (recordLine == maxLogLine) {
        MoveUpFile();
    }
    locateCursor(recordLine, mapBroader);


    if (strcmp(bossNow.name, "ҹ��") == 0) {
        printf("-%s��%sʹ��%s��%s����-%d����", bossNow.name, role->name, bossNow.skill_3, role->name, bossNow.atk_3);
        strcat(logRecord[recordLine], "-ҹ����");
        strcat(logRecord[recordLine], role->name);
        strcat(logRecord[recordLine], "ʹ��");
        strcat(logRecord[recordLine], bossNow.skill_3);
        strcat(logRecord[recordLine], "��");
        strcat(logRecord[recordLine], role->name);
        strcat(logRecord[recordLine], "����-");
        strcat(logRecord[recordLine], bossNow.atk_3_copy);
        strcat(logRecord[recordLine], "����");

        recordLine++;

        if (recordLine == maxLogLine) {
            MoveUpFile();
        }
        locateCursor(recordLine, mapBroader);
        printf("ҹ������+%d", yelan_rewound);

        strcat(logRecord[recordLine], "ҹ������+");
        strcat(logRecord[recordLine], yelan_rewoundCopy);

        recordLine++;
    } else {
        printf("-%s��%sʹ��%s��%s����-%d", bossNow.name, role->name, bossNow.skill_3, role->name, bossNow.atk_3);
        strcat(logRecord[recordLine], "-�����");
        strcat(logRecord[recordLine], role->name);
        strcat(logRecord[recordLine], "ʹ��");
        strcat(logRecord[recordLine], bossNow.skill_3);
        strcat(logRecord[recordLine], "��");
        strcat(logRecord[recordLine], role->name);
        strcat(logRecord[recordLine], "����-");
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

    if (strcmp(bossNow.name, "ҹ��") == 0) {
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
    //�չ���������
    bossNowAction_num = 0;
    //log
    if (recordLine == maxLogLine) {
        MoveUpFile();
    }
    locateCursor(recordLine, mapBroader);
    if (strcmp(bossNow.name, "ҹ��") == 0) {
        printf("-ҹ����%sʹ��%s��%s����-%d", role->name, bossNow.skill_2, role->name, bossNow.atk_2);

        strcat(logRecord[recordLine], "-ҹ����");
    } else {
        printf("-�����%sʹ��%s��%s����-%d", role->name, bossNow.skill_2, role->name, bossNow.atk_2);
        strcat(logRecord[recordLine], "-�����");
    }
    strcat(logRecord[recordLine], role->name);
    strcat(logRecord[recordLine], "ʹ��");
    strcat(logRecord[recordLine], bossNow.skill_2);
    strcat(logRecord[recordLine], "��");
    strcat(logRecord[recordLine], role->name);
    strcat(logRecord[recordLine], "����-");
    strcat(logRecord[recordLine], bossNow.atk_2_copy);

    recordLine++;
}

void EnemyAttack(Role *role) {
    if (strcmp(bossNow.condition, "ѣ��") == 0) {
        return;
    } else if (strcmp(bossNow.condition, "����") == 0) {
        AP_enemy--;
        if (AP_enemy < 0) {
            AP_enemy = 0;
        }
        recordAP(AP_line1, AP_x, AP_enemy);
    } else if (strcmp(bossNow.condition, "��Ѫ") == 0) {
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
    //�ۼ��չ�����
    bossNowAction_num++;
    //log
    if (recordLine == maxLogLine) {
        MoveUpFile();
    }
    locateCursor(recordLine, mapBroader);
    printf("-%s��%sʹ����ͨ������%s����-%d", bossNow.name, role->name, role->name, atk_1);

    strcat(logRecord[recordLine], "-");
    strcat(logRecord[recordLine], bossNow.name);
    strcat(logRecord[recordLine], "��");
    strcat(logRecord[recordLine], role->name);
    strcat(logRecord[recordLine], "ʹ����ͨ������");
    strcat(logRecord[recordLine], role->name);
    strcat(logRecord[recordLine], "����-");
    strcat(logRecord[recordLine], atk_1_copy);

    recordLine++;
}

void bossAction(void) {
    if (recordLine == maxLogLine) {
        MoveUpFile();
    }
    locateCursor(recordLine, mapBroader);
    printf("-���ĵ�����գ��Է�������������");
    strcpy(logRecord[recordLine], "-���ĵ�����գ��Է�������������");
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
    locateCursor(h / 2 - 1, w / 2 - 9);// ������Ĺ��λ��
    printf("��ϲ����Ӯ����ʤ����\n");
    locateCursor(h / 2, w / 2 - 9);
    printf("��Q���¿�ʼ\n");
    locateCursor(h / 2 + 1, w / 2 - 9);
    printf("��Esc�˳�\n");
}

void lose(void) {
    system("cls");
    locateCursor(h / 2 - 1, w / 2 - 9);
    SetConsoleCursorPosition(consoleHandle, co);  // ������Ĺ��λ��
    printf("�ǳ��ź�����ʧ���ˣ�\n");
    locateCursor(h / 2, w / 2 - 9);
    printf("��Q���¿�ʼ\n");
    locateCursor(h / 2 + 1, w / 2 - 9);
    printf("��Esc�˳�\n");
}







