//
// Created by 5-1-302 on 2024/1/13.
//

#ifndef INC_2023_PROJECT_PARTI_H
#define INC_2023_PROJECT_PARTI_H

#include <conio.h>  // 必须
#include <windows.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define mapBroader 80
#define messagePart 7
#define atk_1 2
#define atk_1_copy "2"
#define mapLength 22
#define AP_x 5
#define warNoteLine 8
#define enemy_originAP 13
#define own_originAP 11
#define AP_line1 4
#define AP_line2 12
#define boss_x 35
#define role1_x 15
#define role2_x 35
#define role3_x 55
#define role_originHP 9
#define yanfei_originHP 12
#define boss_HP 28
#define yelan_rewound 4
#define yelan_rewoundCopy "4"
#define xingqiu_rewound 1
#define xingqiu_rewoundCopy "1"

extern HANDLE consoleHandle;// 操作控制台（也就是那个黑框框）需要的一个变量
extern COORD co;
extern int w, h;
extern int AP_enemy, AP_own;
extern char allocate_save[15];
extern int allocate_num;
extern int zhongli_explode;
extern int yunjin_explode;
extern int element_specialAttack;
extern int element_num;
//todo
extern int bossNowAction_num;

typedef struct Role {
    COORD place;
    char name[15];
    char skill_2[15];//2技能名称
    int atk_2;//2技能伤害
    char atk_2_copy[3];
    char condition[15];//我方给boss施加的状态
    char atk_add[15];//我方2技能给自身施加状态//todo元素爆发
    char skill_3[15];//三技能名称
    int atk_3;//伤害
    char atk_3_copy[3];
    int skill_2_num;
    //todo
    int HP;
    bool ifChosen;
    bool ifAllocate;
    struct Role *left;
    struct Role *right;
    char element[5];
    char element_effect[10];
} Role;
extern Role yelan, xingqiu, zhongli, liulangzhe, leize, yanfei, yunjin;
extern Role bossNow, role_one, role_two, role_three;

//基础操作

void ClearSide(int line);

void locateCursor(int y, int x);

void recordAP(int y, int x, int num);

void printBorder(char border, int length);

void printRole(int y, int x, Role role);

void printNOW(int y, int x);

Role *DefineChosen(void);

Role *DefineAllocate(void);

//界面组成
void start(void);

void FundamentalMap(void);

void operationTip(void);

void warNote(void);

//基本行动
void warProcess(void);

//**change功能
void allocate(void);

void Moveout(Role *role);

void comeBack(Role *role);

//**L/R功能
void Deselect(int y, int x);

void switchNOW(Role *role, bool ifLeft);

void leftRole(void);

void rightRole(void);

//**I/O功能
void DisplayMessage(void);

void CloseMessage(void);

//**J功能
void DisplaybossNow(void);


#endif //INC_2023_PROJECT_PARTI_H
