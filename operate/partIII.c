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
    if (strcmp(role_one.name, "����") == 0) {
        role_one.HP++;
        locateCursor(role_one.place.Y + 1, role_one.place.X + 1);
        printf("%d ", role_one.HP);
    } else if (strcmp(role_two.name, "����") == 0) {
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
    printf("��ѡ��ؿ���");
    locateCursor(14, 45);
    printf("�ؿ�1�����󣨰�1ѡ��ùؿ���");
    locateCursor(15, 45);
    printf("�ؿ�2��ҹ������2ѡ��ùؿ���");
}

void NewGame(void) {
    //һЩȫ�ֱ���
    allocate_num = 0;
    bossNowAction_num = 0;
    zhongli_explode = 0;
    yunjin_explode = 0;
    element_num = 0;
    //�����־��¼
    recordLine = warNoteLine + 1;
    memset(logRecord, '\0', 1800);
    //todo
    //AP�����ع�
    AP_own = own_originAP;
    AP_enemy = enemy_originAP;
    //����չʾ�ع鵽ԭ��
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
    if (strcmp(role->name, "���") == 0) {
        printf("\033[1;31m%s\033[0m", role->element);
    } else if (strcmp(role->name, "����") == 0) {
        printf("\033[1;34m%s\033[0m", role->element);
    } else if (strcmp(role->name, "ɢ��") == 0) {
        printf("\033[1;36m%s\033[0m", role->element);
    } else if (strcmp(role->name, "����") == 0) {
        printf("\033[1;33m%s\033[0m", role->element);
    } else if (strcmp(role->name, "����") == 0) {
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
    printf("�������������ɫ��ѡ��������ɫ");
    printf("\033[2m");
    printf("������ȡ��ѡ�񣬿����ظ�ѡ��");
    printf("\033[0m");

    locateCursor(10, 45);
    printf("1.��糣��𣩣���1ѡ��");
    locateCursor(11, 45);
    printf("\033[2mԪ��ս����ѣ��/Ԫ�ر������Եз��������˺�/���������츳");
    printf("\033[0m");

    locateCursor(12, 45);
    printf("2.�������ң�����2ѡ��");
    locateCursor(13, 45);
    printf("\033[2mԪ��ս��������/Ԫ�ر������Եз��������˺������һغ�ĩ��������+1");
    printf("\033[0m");

    locateCursor(14, 45);
    printf("3.���ˮ������3ѡ��");
    locateCursor(15, 45);
    printf("\033[2mԪ��ս����ѣ��/Ԫ�ر������Եз��������˺�������������������+1");
    printf("\033[0m");

    locateCursor(16, 45);
    printf("4.���루�ң�����4ѡ��");
    locateCursor(17, 45);
    printf("\033[2mԪ��ս��������/Ԫ�ر������Եз��������˺������һغ�ĩ�з�����-1");
    printf("\033[0m");

    locateCursor(18, 45);
    printf("5.ɢ�����磩����5ѡ��");
    locateCursor(19, 45);
    printf("\033[2mԪ��ս������Ѫ/Ԫ�ر������Եз���������˺�");
    printf("\033[0m");

    locateCursor(22, 45);
    printf("����ѡ��");

    printf("\033[2m");
    locateCursor(23, 45);
    printf("��Q��ʼ��Ϸ");
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
    if (strcmp(bossNow.element_effect, "����") == 0 || strcmp(bossNow.element_effect, "�һ�") == 0) {
        bossNow.HP--;
        if (bossNow.HP < 0) {
            bossNow.HP = 0;
        }

        printf("-�����ҷ�Ӧ���з�����-1");
        strcat(logRecord[recordLine], "-�����ҷ�Ӧ���з�����-1");

        locateCursor(bossNow.place.Y + 1, bossNow.place.X + 1);
        printf("%d ", bossNow.HP);
    } else if (strcmp(bossNow.element_effect, "ˮ��") == 0 || strcmp(bossNow.element_effect, "��ˮ") == 0) {
        role->HP++;
        if (strcmp(role->name, "���") == 0) {
            if (role->HP > yanfei_originHP) {
                role->HP = yanfei_originHP;
            }
        } else {
            if (role->HP > role_originHP) {
                role->HP = role_originHP;
            }
        }

        printf("-ˮ���ҷ�Ӧ���ҷ�����+1");
        strcat(logRecord[recordLine], "-ˮ���ҷ�Ӧ���ҷ�����+1");

        locateCursor(role->place.Y + 1, role->place.X + 1);
        printf("%d ", role->HP);

    } else if (strcmp(bossNow.element_effect, "����") == 0 || strcmp(bossNow.element_effect, "�ҷ�") == 0) {
        bossNow.HP--;
        if (bossNow.HP < 0) {
            bossNow.HP = 0;
        }
        printf("-�����ҷ�Ӧ���з�����-1");
        strcat(logRecord[recordLine], "-�����ҷ�Ӧ���з�����-1");

        locateCursor(bossNow.place.Y + 1, bossNow.place.X + 1);
        printf("%d ", bossNow.HP);
    } else if (strcmp(bossNow.element_effect, "ˮ��") == 0 || strcmp(bossNow.element_effect, "��ˮ") == 0) {
        if (element_specialAttack == 2) {
            bossNow.HP -= role->atk_2;
        } else if (element_specialAttack == 3) {
            bossNow.HP -= role->atk_3;
        }
        if (bossNow.HP < 0) {
            bossNow.HP = 0;
        }
        printf("-����ˮ��Ӧ���ҷ�������*2");
        strcat(logRecord[recordLine], "-����ˮ��Ӧ���ҷ�������*2");

        locateCursor(bossNow.place.Y + 1, bossNow.place.X + 1);
        printf("%d ", bossNow.HP);

    } else if (strcmp(bossNow.element_effect, "ˮ��") == 0 || strcmp(bossNow.element_effect, "��ˮ") == 0) {
        bossNow.HP++;
        if (bossNow.HP > boss_HP) {
            bossNow.HP = boss_HP;
        }
        printf("-ˮ��練Ӧ���з�����+1");
        strcat(logRecord[recordLine], "-ˮ���ҷ�Ӧ���з�����+1");
        locateCursor(bossNow.place.Y + 1, bossNow.place.X + 1);
        printf("%d ", bossNow.HP);


    } else {
        printf("-����練Ӧ��Ч");
        strcat(logRecord[recordLine], "-����練Ӧ��Ч");
    }
    recordLine++;
}

void clear_BossElement(void) {
    locateCursor(bossNow.place.Y - 1, bossNow.place.X);
    printf("      ");
    strcpy(bossNow.element_effect, "\0");
    element_num = 0;
}








