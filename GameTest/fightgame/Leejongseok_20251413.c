//학생의 Action의 return 값은 
//return Wait(hp, name);
//return Heal(hp, name);
//둘중 하나여야함

//도박 메타

int LJS(int hp, char* name)
{
    // 1) 체력이 너무 낮으면 힐 (죽기 싫음)
    if (hp <= 25) {
        return Heal(hp, name);
    }

    // 2) 체력이 26~50이면 공격적으로 Wait (도박 유지)
    if (hp <= 50) {
        int r = rand() % 10;  // 0~9
        if (r < 7) {
            return Wait(hp, name);  // 70% 회피(공격)
        }
        else {
            return Heal(hp, name);  // 30% 힐(안전)
        }
    }

    // 3) 체력이 51 이상이면 무조건 회피 (도박 최강)
    return Wait(hp, name);
}