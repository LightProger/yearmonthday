#include <stdio.h>
/* **********************************************
 * Получает на вход целое число и выводит строку:
 *			"До отпуска: x день/дня/дней."
 * Работает для любых значений.
 *
 * Измените программу таким образом, чтобы она
 * подсчитывала еще и количество месяцев и лет,
 * т.е. при вводе числа 615, вывод должен быть:
 * До отпуска: 1 год, 8 месяцев и 10 дней.
 *
 * На вход может поступить число, при котором
 * понадобится уточнять написание:
 * 1 год/ 3 года / 6 лет, но не более 60 лет.
 * То же касается и месяцев.
 *
 * Предполагается, что в каждом году 365 дней.
 * А в каждом месяце - 30 дней.
 * *********************************************/

typedef char* StriNg;				// объявляем новый тип string
int Days (int);						// номер элемента массива s[]
int LastDouble (int);				// две последние цифры числа

int main (void)
{
  StriNg s[3] = {"день", "дня", "дней"};
  StriNg year[3] = {"год", "года", "лет"};
  StriNg mon[3] = {"месяц", "месяца", "месяцев"};
  StriNg message = "Сколько дней до отпуска?:";

  // ввод числа
  int n;
  int restYears, restDays, restMonth, total, a;

  total = 365 * 60;  // вычисляем лимит в 60 лет

  do{
      printf("%s ", message);
      scanf("%d", &n);
      getchar();
    }while(n < 0 || n > total);

  // разбиваем число на годы, месяцы и дни
  restYears = n / 365;
  a = n - restYears * 365;
  restMonth = a / 30;
  restDays = a - restMonth * 30;

  // если число равно 0, то вывести дней
  if(n == 0) { printf("До отпуска: %i %s.\n", restDays, s[Days (restDays)]); }

  // если года кратны 365, выводим только год
  else if(n % 365 == 0)
    {
      printf("До отпуска: %i %s.\n", restYears, year[Days (restYears)]);
    }

    // если число кратно 30, то выводим только месяц
  else if(n % 30 == 0) { printf("До отпуска: %i %s.\n", restMonth, mon[Days (restMonth)]);}

    // если число tsменьше 30, выводим только дни
  else if(restYears == 0 && restMonth == 0 && restDays < 30)
    {
      printf("До отпуска: %i %s.\n", n, s[Days(n)]);
    }

    // выводим, дни и месяцы
  else if(restDays < 30 && restMonth < 12 && restYears == 0)
    {
      printf("До отпуска: %i %s %i %s.\n", restMonth, mon[Days (restMonth)],
                 restDays, s[Days(restDays)]);
    }

    // выводим годы + дни
  else if(restYears > 0 && restMonth == 0 && restDays > 0)
    {
      printf("До отпуска: %i %s %i %s.\n", restYears, year[Days (restYears)],
                 restDays, s[Days (restDays)]);
    }

    // выводим годы + месяцы
  else if (restYears > 0 && restMonth > 0 && restDays == 0)
    {
      printf("До отпуска: %i %s %i %s.\n", restYears, year[Days (restYears)], restMonth,
                     mon[Days (restMonth)]);
    }
    // выводим годы + месяцы + дни
  else
    {
      if(restYears > 0 && restMonth > 0 && restDays > 0)
        {
          printf("До отпуска: %i %s %i %s %i %s.\n", restYears, year[Days (restYears)], restMonth,
                 mon[Days (restMonth)], restDays, s[Days (restDays)]);
        }
    }

  return 0;
}
//-------------------------------------------------------------------------
// номер элемента массива s[] для любых значений num
//-------------------------------------------------------------------------
int Days (int num)
{
  int answer, m;			/* answer: 0 - 1 элемент массива, 1 - 2 элемент, 2 - 3 элемент */
  if (num > 0)
    {
      if (num < 100)
        {
          m = num % 10;
          if (num < 20)
            {
              if (num > 4) answer = 2;
              else
                {
                  if (num == 1) answer = 0;
                  if (num > 1) answer = 1;
                }
            }
          else if (!m) answer = 2;
          else
            {
              if (m == 1) answer = 0;
              else if (m > 1 && m < 5) answer = 1;
              else answer = 2;
            }
        }
      else answer = Days(LastDouble(num));
    }
  else answer = 2;
  return answer;
}
//-------------------------------------------------------------------------
//возвращает две последние цифры числа
//-------------------------------------------------------------------------
int LastDouble (int z)
{
  int a, b, c;
  b = z % 10;
  z /= 10;
  a = z % 10;
  c = (a * 10) + b;
  return c;
}