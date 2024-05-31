#include <stdio.h>

// 윤년인지 구함
// 윤년은 4로 나누어 떨어지면서 100으로 나누어 떨어지지 않거나 400으로 나누어 떨어지는 연도이다
int is_leaf_year(int year)
{
    if (year % 400 == 0)  return 1;
    if ((year % 100 != 0) && (year % 4 == 0))  return 1;
    return 0;
}

// 월별 날수를 구함
// 주어진 연도와 월에 대한 월의 일수 반환
int get_day_of_month(int year, int month)
{
    int day_of_month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    day_of_month[2] += is_leaf_year(year);
    return day_of_month[month];
}

// 특정 연도와 특정 월의 1일의 요일을 구함
// 기준일로부터 얼마만큼 지났느냐 == year년 month 월의 일 수의 누적합
int get_day(int year, int month)
{
    int past = 0;
    for (int i=1; i<year; i++)  
        past = past + 365 + is_leaf_year(i);
    for (int i=1; i<month; i++)
        past = past + get_day_of_month(year, i);
    return (1 + past) % 7; // 1:월요일 2:화요일...6:토요일
}

// 출력
void printcalendar()
{
    int year, month;
    scanf("%d%d", &year, &month);
    int start_day = get_day(year, month);
    int day_num = get_day_of_month(year, month);
    // printf("%d %d", start_day, day_num);
    printf("  SUN MON THU WED THU FRI SAT\n");
    for (int i=0; i<start_day; i++)
    {
        printf("    ");
    }
    for (int day=1, ke = start_day; day <= day_num; day++, ke++)
    {
        printf("%4d", day);
        if (ke % 7 == 6)
            printf("\n");
    }
}

int main()
{
    printcalendar();   
    return 0;
}