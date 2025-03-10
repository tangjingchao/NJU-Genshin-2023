//
// Created by 5-1-302 on 2024/1/13.
//
#include "partI.h"
#include "partII.h"
#include "partIII.h"
#include <string.h>

HANDLE consoleHandle;// ��������̨��Ҳ�����Ǹ��ڿ����Ҫ��һ������
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
        .name="����",
        .skill_2="��צ����",
        .skill_3="�ּ�����",
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
        .name="ҹ��",
        .skill_2="��������",
        .skill_3="Ԩͼ����",
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
        .name="����",
        .skill_2="�Ż�����",
        .skill_3="��������",
        .atk_2=3,
        .atk_2_copy="3",
        .atk_3=5,
        .atk_3_copy="5",
        .condition="������",
        .atk_add="ѣ��",
        .HP=role_originHP,
        .ifChosen=0,
        .ifAllocate=0,
        .skill_2_num=0,
        .element="ˮ"
};

Role zhongli = {
        .name="����",
        .skill_2="��谻���",
        .skill_3="�춯����",
        .atk_2=3,
        .atk_2_copy="3",
        .atk_3=5,
        .atk_3_copy="5",
        .condition="�Ҽ�",
        .atk_add="����",//�۶Է�AP
        .HP=role_originHP,
        .ifChosen=0,
        .ifAllocate=0,
        .skill_2_num=0,
        .element="��"
};

Role liulangzhe = {
        .name="ɢ��",
        .skill_2="���˻���",
        .skill_3="��������",
        .atk_2=3,
        .atk_2_copy="3",
        .atk_3=6,
        .atk_3_copy="6",
        .condition="��",
        .atk_add="��Ѫ",
        .HP=role_originHP,
        .ifChosen=0,
        .ifAllocate=0,
        .skill_2_num=0,
        .element="��"
};

Role yanfei = {
        .name="���",
        .skill_2="������Լ",
        .skill_3="ƾ�����",
        .atk_2=3,
        .atk_2_copy="3",
        .atk_3=5,
        .atk_3_copy="5",
        .condition="����ӡ",
        .atk_add="ѣ��",
        .HP=yanfei_originHP,
        .ifChosen=0,
        .ifAllocate=0,
        .skill_2_num=0,
        .element="��"
};

Role yunjin = {
        .name="����",
        .skill_2="���ƿ���",
        .skill_3="���ּ���",
        .atk_2=3,
        .atk_2_copy="3",
        .atk_3=5,
        .atk_3_copy="5",
        .condition="����",
        .atk_add="����",
        .HP=role_originHP,
        .ifChosen=0,
        .ifAllocate=0,
        .skill_2_num=0,
        .element="��"
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
                if (strcmp(role.name, "ҹ��") == 0 || strcmp(role.name, "����") == 0) {
                    printf("%d     ", role.HP);
                } else if (strcmp(role.name, "���") == 0 && role.HP >= 10) {
                    printf("%d   \033[1;31m%s\033[0m", role.HP, role.element);
                } else {
                    if (strcmp(role.name, "���") == 0) {
                        printf("%d    \033[1;31m%s\033[0m", role.HP, role.element);
                    } else if (strcmp(role.name, "����") == 0) {
                        printf("%d    \033[1;34m%s\033[0m", role.HP, role.element);
                    } else if (strcmp(role.name, "ɢ��") == 0) {
                        printf("%d    \033[1;36m%s\033[0m", role.HP, role.element);
                    } else if (strcmp(role.name, "����") == 0) {
                        printf("%d    \033[1;33m%s\033[0m", role.HP, role.element);
                    } else if (strcmp(role.name, "����") == 0) {
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
    SetConsoleCursorPosition(consoleHandle, co);  // ������Ĺ��λ��
}

void start(void) {
    locateCursor(12, 15);
    printf(" __   ___              __                  __            ___    __          ___  __   __  \n");
    locateCursor(13, 15);
    printf("/ _` |__  |\\ | | |  | /__`    | |\\ | \\  / /  \\ |__/  /\\   |  | /  \\ |\\ |     |  /  ` / _` \n");
    locateCursor(14, 15);
    printf("\\__> |___ | \\| | \\__/ .__/    | | \\|  \\/  \\__/ |  \\ /~~\\  |  | \\__/ | \\|     |  \\__, \\__> \n");
    locateCursor(15, 92);
    printf("��ʥ�ٻ�");

    locateCursor(17, 93);
    printf("\033[2m");
    printf("��Q��ʼ��Ϸ");
    locateCursor(18, 93);
    printf("��Esc���˳�");
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
    printf("</>�����л�ѡ���ɫ\n"
           "A��������������Ҫ1���ж��㣨AP��\n"
           "E��ʹ��Ԫ��ս������Ҫ3���ж��㣬ʹ��һ�λ���1��ս�������2��\n"
           "Q��ʹ��Ԫ�ر�������Ҫ5���ж����2��ս��\n"
           "C��ѡ�������������л�ʱ��Ҫ1���ж���\n"
           "I/O���鿴/�رյ�ǰ������Ϣ������/Ԫ��ս��/Ԫ�ر���Ч����\n"
           "J���鿴�з�������Ϣ������/Ԫ��ս��/Ԫ�ر���Ч����\n");
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
    printf("ս����־:");

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
    printf("��Enter�����ص����");
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


////��ɫʵ�ֹ���





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
    printf("������Ϣ��");
    locateCursor(1, mapBroader);
    if (strcmp(role->name, "���") == 0) {
        printf("  ��糣��츳������ֵ��3��");
    } else {
        printf("  %s", role->name);
    }
    locateCursor(2, mapBroader);
    printf("    ��ͨ�������з�����-%d", atk_1);
    locateCursor(3, mapBroader);
    printf("    %s���з�����-%d������%sһ�غ�", role->skill_2, role->atk_2, role->atk_add);

    if (strcmp(role->name, "����") == 0) {
        locateCursor(4, mapBroader);
        printf("    %s:�з��޷��ж�", role->atk_add);
        locateCursor(5, mapBroader);
        printf("    %s���з�����-%d����������+%d", role->skill_3, role->atk_3, xingqiu_rewound);
    } else if (strcmp(role->name, "����") == 0) {
        locateCursor(4, mapBroader);
        printf("    %s:�з�AP-1", role->atk_add);
        locateCursor(5, mapBroader);
        printf("    %s���з�����-%d���Ҹûغ�ĩ�з�", role->skill_3, role->atk_3);
        locateCursor(6, mapBroader);
        printf("  ��������-1");
    } else if (strcmp(role->name, "ɢ��") == 0) {
        locateCursor(4, mapBroader);
        printf("    %s:�з���������-1", role->atk_add);
        locateCursor(5, mapBroader);
        printf("    %s���з�����-%d", role->skill_3, role->atk_3);
    } else if (strcmp(role->name, "���") == 0) {
        locateCursor(4, mapBroader);
        printf("    %s:�з��޷��ж�", role->atk_add);
        locateCursor(5, mapBroader);
        printf("    %s���з�����-%d", role->skill_3, role->atk_3);
    } else if (strcmp(role->name, "����") == 0) {
        locateCursor(4, mapBroader);
        printf("    %s:�з�AP-1", role->atk_add);
        locateCursor(5, mapBroader);
        printf("    %s���з�����-%d���Ҹûغ�ĩ����", role->skill_3, role->atk_3);
        locateCursor(6, mapBroader);
        printf("  ��������+1");
    }

}

void DisplaybossNow(void) {
    CloseMessage();
    locateCursor(0, mapBroader);
    printf("������Ϣ��");
    locateCursor(1, mapBroader);
    printf("  %s", bossNow.name);
    locateCursor(2, mapBroader);
    printf("    ��ͨ�������з�����-%d������1��AP", atk_1);
    locateCursor(3, mapBroader);
    printf("    %s���з�����-%d������2��AP��ÿ", bossNow.skill_2, bossNow.atk_2);
    locateCursor(4, mapBroader);
    printf("  ������ͨ�������Զ�����");
    locateCursor(5, mapBroader);
    if (strcmp(bossNow.name, yelan.name) == 0) {
        printf("    %s���з�����-%d����������+%d����", bossNow.skill_3, bossNow.atk_3, yelan_rewound);
        locateCursor(6, mapBroader);
        printf("  ��5��AP��APΪ5ʱ�Զ�����");
    } else if (strcmp(bossNow.name, leize.name) == 0) {
        printf("    %s���з�����-%d������5��AP��AP", bossNow.skill_3, bossNow.atk_3);
        locateCursor(6, mapBroader);
        printf("  Ϊ5ʱ�Զ�����");
    }
}
