#include <stdio.h>
#include <locale.h>

int main(void)
{
	setlocale(LC_ALL, "Russian");
	
	printf("1. Перевести из 10 в 16 систему:\n");
	printf("   12345678 dec to hex: BC614E\n");
	printf("    1000000 dec to hex: F4240\n\n");
	
	printf("2. Перевести из 16 в 10 систему:\n");
	printf("   12345678 hex to dec: 305419896\n");
	printf("    1000000 hex to dec: 16777216\n\n");
	
	printf("3. Записать в виде логического выражения ответ Винни Пуха:\n");
	printf("   \"Сгущенного молока и меда и можно без хлеба\"\n");
	printf("   уточнение: \"можно\" как логическая операция опускается, тогда\n");
	printf("   A - cгущенное молоко\n");
	printf("   B - мед\n");
	printf("   C - хлеб\n");
	printf("   A & B & !C\n\n");
	
	printf("4. Доказать тождества:\n");
	printf("   A -> B = !A || B\n");
	printf("   поскольку A -> B = !A + B, то выражение истинно\n\n");
	printf("   A<->B = (A & B) || (!A & !B)\n");
	printf("   Состовим таблицу инстинности правой и левой частей\n\n");
	printf("   A<->B\n");
	printf("   ------\n");
	printf("   A	B	A<->B\n");
	printf("   0	0	1\n");
	printf("   0	1	0\n");
	printf("   1	0	0\n");
	printf("   1	1	1\n\n");
	
	printf("   (A & B) || (!A & !B)\n");
	printf("   ------\n");
	printf("   A	B	A & B		!A & !B			(A & B) || (!A & !B)\n");
	printf("   0	0	0		1			1\n");
	printf("   0	1	0		0			0\n");
	printf("   1	0	0		0			0\n");
	printf("   1	1	1		0			1\n\n");
	
	printf("   Таблицы истинности совпадают, следовательно, выражение истинно\n");
	
	return 0;
}
