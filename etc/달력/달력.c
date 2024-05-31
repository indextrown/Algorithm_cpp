#include<stdio.h>
//함수의 원형
void printMonth(int year, int month);
void printMonthTitle(int year, int month);
void printMonthName(int month);
void printMonthBody(int year, int month);
int getStartDay(int year, int month);
int getTotalNumberOfDays(int year, int month);
int getNumberOfDaysInMonth(int year, int month);
int isLeapYear(int year);

//year와 month를 전달 받아 해당 월을 출력 -> title, body
void printMonth(int year, int month) {
	printMonthTitle(year, month);
	printMonthBody(year, month);
}

//월과 년도를 출력
void printMonthTitle(int year, int month) {
	printMonthName(month);
	printf(" %d\n", year);
	printf("-----------------------------\n");
	printf(" Sun Mon Tue Wed Thu Fri Sat\n");
}

//month를 전달 받아 해당 달의 영어 이름을 출력
void printMonthName(int month) {
	switch (month) {
	case 1: printf("January"); break;
	case 2: printf("February"); break;
	case 3: printf("March"); break;
	case 4: printf("April"); break;
	case 5: printf("May"); break;
	case 6: printf("June"); break;
	case 7: printf("July"); break;
	case 8: printf("August"); break;
	case 9: printf("September"); break;
	case 10: printf("October"); break;
	case 11: printf("November"); break;
	case 12: printf("December"); break;
	}
}

//year와 month를 전달 받아 요일과 일을 출력
void printMonthBody(int year, int month) {
	int startday = getStartDay(year, month);
	int numberofdaysinmonth = getNumberOfDaysInMonth(year, month);

	for (int i = 0; i < startday; i++) printf("    ");
	for (int i = 1; i <= numberofdaysinmonth; i++) {
		printf("%4d", i);
		if ((i + startday) % 7 == 0) printf("\n");
	}
}

// 해당 월의 시작하는 날이 몇 요일인지 찾는 함수
int getStartDay(int year, int month) {
	int startday1800 = 3;
	int totalnumberofdays = getTotalNumberOfDays(year, month);
	return (startday1800 + totalnumberofdays) % 7;
}

// 1800년 1월 1일 부터 며칠이 되는지 계산
int getTotalNumberOfDays(int year, int month) {
	int total = 0;
	for (int i = 1800; i < year; i++) {
		if (isLeapYear(i)) total += 366;
		else total += 365;
	}
	for (int i = 1; i < month; i++) total = total + getNumberOfDaysInMonth(year, i);
	return total;
}

//year와 month를 전달 받아 해당월에 몇일이 있는지
int getNumberOfDaysInMonth(int year, int month) {
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) return 31;
	if (month == 4 || month == 6 || month == 9 || month == 11) return 30;
	if (month == 2) {
		if (isLeapYear(year) == 1) return 29;
		else return 28;
	}
}

//year를 전달받아 윤년인지 확인
int isLeapYear(int year) {
	if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) return 1;
	else return 0;
}

int main(void) {
	int year, month;
    // 년도 입력
    printf("year : ");
	scanf("%d", &year);
    // 월 입력
    printf("month : ");
	scanf("%d", &month);
	printMonth(year, month);
	return 0;
}