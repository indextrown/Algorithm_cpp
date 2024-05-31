#include <stdio.h>
#include <stdlib.h>

// 특정 연도와 월의 첫 날이 무슨 요일인지 반환하는 함수
int get_starting_day(int year, int month)
{
    int starting_day;

    // Zeller's Congruence 알고리즘을 사용하여 요일 계산
    if (month < 3) {
        month += 12;
        year--;
    }
    starting_day = (1 + (13 * (month + 1)) / 5 + year + year / 4 - year / 100 + year / 400) % 7;

    // 일요일은 0, 월요일은 1, ..., 토요일은 6으로 반환
    return starting_day;
}


void printcalendar(char *year, char *month)
{
    // 달력 출력을 위한 기본 정보 설정
    int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int year_num = atoi(year);
    int month_num = atoi(month);

    // 윤년 체크 (2월이 29일인지 확인)
    if ((year_num % 4 == 0 && year_num % 100 != 0) || (year_num % 400 == 0))
        days_in_month[1] = 29;

    // 월과 연도 출력
    printf("Calendar for %s %s:\n", month, year);

    // 요일 출력
    printf("SUN MON TUE WED THU FRI SAT\n");

    // 해당 월의 첫 날을 요일에 맞게 출력
    int starting_day = get_starting_day(year_num, month_num);
    for (int i = 0; i < starting_day; i++)
        printf("    ");

    // 해당 월의 날짜 출력
    for (int day = 1; day <= days_in_month[month_num - 1]; day++) {
        printf("%3d ", day);
        if ((day + starting_day) % 7 == 0 || day == days_in_month[month_num - 1])
            printf("\n");
    }
}


