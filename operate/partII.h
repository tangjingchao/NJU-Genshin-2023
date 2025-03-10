//
// Created by 5-1-302 on 2024/1/17.
//

#ifndef INC_2023_PROJECT_PARTII_H
#define INC_2023_PROJECT_PARTII_H

#include "partI.h"

#define maxLogLine 29
extern int recordLine;
extern char logRecord[40][45];

//note change
void allocate_record(void);

void clear_BossCondition(void);

void clear_RoleCondition(Role *role);

void NewRound(void);

void MoveUpFile(void);

void NowActionParty(int line);

void ClearLastParty(int line);

//own action
void CommonAttack(void);

void CommonAttack_record(Role *role);

void CommonAttack_RoleChange();

void SkillAttack(void);

void SkillAttack_record(Role *role);

void SkillAttack_RoleChange(Role *role);

void explode_Attack(Role *role);

void explodeAttack_record(Role *role);

void explodeAttack_RoleChange(Role *role);

//enemy action
void BossExplodeRecord(Role *role);

void BossExplodeAttack(Role *role);

void EnemySkillAttack(Role *role);

void EnemyAttack(Role *role);

void bossAction(void);

//Ω·À„ª≠√Ê
void win(void);

void lose(void);

#endif //INC_2023_PROJECT_PARTII_H
