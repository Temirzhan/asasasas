#include<iostream>
#include<locale.h>
#include<stdio.h>
#include<math.h>
#include<time.h>

using namespace std;

char f;

void main() {
	setlocale(LC_ALL, "rus");
	do {
		int F;
		cout << "Выберите задание" << endl;
		cin >> F;
		if (F == 1)
		{
			/*1.	Дан квадратный массив из n элементов. Найти произведение элементов первой строки*/
			int A[10][10];
			int proizv = 1;
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					A[i][j] = 1 + rand() % 1000;
					cout << "A[" << i << "]" << "[" << j << "]= " << A[i][j] << "\t";
				}cout << endl;
			}
			for (int i = 0; i < 10; i++)
			{
				proizv *= A[0][i];
			}
			cout << "Произведение первой строки =" << proizv << endl;
		}
		else if (F == 2)
		{
			/*2.	Дана целочисленная квадратная матрица. Написать программу упорядочения ее строк по возрастанию сумм их элементов*/
			int A[10][10]; int B[10] = { 0 }; int Z[10] = {0,1,2,3,4,5,6,7,8,9}; int temp;
			int value; int index;
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					A[i][j] = 1 + rand() % 1000;
					cout << "A[" << i << "]" << "[" << j << "]= " << A[i][j] << "\t";
				}cout << endl;
			}
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					B[i] += A[i][j];
				}
			}	
			for (int i = 0; i < 9; i++)
			{
				for(int j=9;j>i;j--)
					if (B[j - 1] > B[j])
					{
						temp = B[j - 1];
						B[j - 1] = B[j];
						B[j] = temp;
						index = Z[j - 1];
						Z[j - 1] = Z[j];
						Z[j] = index;
					}
			}
			cout << "-------" << endl;
			for (int i=0; i < 10; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					cout << "A[" << i << "]" << "[" << j << "]= " << A[Z[i]][j] << "\t";
				}cout << endl;
			}
			
		}
		else if (F == 3)
		{
			/*3.	Дана целочисленная матрица размера 5×10. Найти минимальное значение среди сумм элементов всех ее строк*/
			int A[10][10];
			int mix = 10000;
			int index;
			int summa = 0;
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					A[i][j] = 1 + rand() % 1000;
					cout << "A[" << i << "]" << "[" << j << "]= " << A[i][j] << "\t";
				}cout << endl;
			}
			for (int i = 0; i < 10; i++)
			{
				summa = 0;
				for (int j = 0; j < 10; j++)
				{
					summa += A[i][j];
				}
				if (mix > summa)
				{
					mix = summa;
					index = i;
				}
			}
			cout << "минимальная строка по сумме = " << summa << "принадлежит строке = " << index << endl;
		}
		else if (F == 4)
		{
			/*4.	В произвольной матрице - отсортировать по убыванию элементы последовательности, расположенные после второго отрицательного числа.*/
			int A[10];
			int index;
			int count;
			int temp;
			for (int i = 0; i < 10; i++)
			{
				A[i] = -10 + rand() % 40;
				cout << "A[" << i << "]= " << A[i] << endl;
			}
			for (int i = 0; i < 10; i++)
			{
				if (A[i] < 0)
				{
					count++;
					index = i;
					if (count == 2)
						break;
				}
			}
			for (int i = index + 1; i<9; i++)
				for (int j = 9; j>i; j--)
					if (A[j - 1] < A[j])
					{
						temp = A[j - 1];
						A[j - 1] = A[j];
						A[j] = temp;
					}
			for (int i = 0; i < 10; i++)
			{
				cout << "A[" << i << "]= " << A[i] << endl;
			}

		}
		else if (F == 5)
		{
			/*5.	Дан массив A(n,m). Удалить строки массива, не имеющие ни одного повторяющегося элемента*/
			int A[4][4]; int flag = 0;

			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					A[i][j] = 1 + rand() % 30;
					cout << "A[" << i << "]" << "[" << j << "]= " << A[i][j] << "\t";
				}cout << endl;
			}
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					for (int s = j + 1; s < 4; s++)
					{
						if (A[i][j] == A[i][s])
						{
							flag = 1;
						}
					}
				}
				if (flag == 0)
				{
					for (int j = 0; j < 4; j++)
					{
						A[i][j] = 0;
					}
				}
			}
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					cout << "A[" << i << "]" << "[" << j << "]= " << A[i][j] << "\t";
				}cout << endl;
			}
		}
		else if (F == 6)
		{
			/*6.	Элементы матрицы A сделать с помощью генератора случайных чисел.
			Сделать новую матрицу B , в которой удалить с матрицы А ряд,
			в котором минимальный элемент среди элементов главной диагонали*/
			int A[4][4]; int B[4][4];
			int min = 10000;
			int index;
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					A[i][j] = 1 + rand() % 30;
					cout << "A[" << i << "]" << "[" << j << "]= " << A[i][j] << "\t";
				}cout << endl;
			}
			for (int i = 0, j = 0; i < 4, j<4; i++, j++)
			{
				if (min > A[i][j])
				{
					min = A[i][j];
					index = i;
				}
			}
			cout << "Минимальное диаганальное число = " << min << endl;;
			for (int j = 0; j<4; j++)
			{
				A[index][j] = 0;
			}
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					cout << "A[" << i << "]" << "[" << j << "]= " << A[i][j] << "\t";
				}cout << endl;
			}
		}
		else if (F == 7)
		{
			//7.	Составить программу, которая заполняет квадратную матрицу порядка n натуральными числами 1, 2, 3, .. ., n2,записывая их в нее "по спирали" против часовой стрелки.
			int A[4][4];
			int natur = 0;
			int chet = 0;
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					natur++;
					A[j][0] = natur;
					cout << "A[" << i << "]" << "[" << j << "]= " << A[i][j] << "\t";
				}
				for (int j = 1; j < 4; j++)
				{
					natur++;
					A[3][j] = natur;
				}
				for (int j = 1; j < 4; j++)
				{
					natur++;
					A[][j] = natur;
				}
			}
		}
		else if (F == 8)
		{
			/*8.	Написать программу, которая в матрице чисел A(N,M) находит все элементы, равные числу, введенному с клавиатуры. Подсчитать число таких элементов*/
			int A[4][4];
			int che = 0;
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					A[i][j] = 1 + rand() % 30;
					cout << "A[" << i << "]" << "[" << j << "]= " << A[i][j] << "\t";
				}cout << endl;
			}
			int c;
			cout << "Введите число" << endl;
			cin >> c;
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					if (c == A[i][j])
						che++;
				}
			}
			cout << "совпадений = " << che << endl;
		}
		else if (F == 9)
		{
			/*9.	Дана целочисленная матрица размера 5х5. Заменить в данной матрице все отрицательные элементы первой строки числом 0. */
			int A[5][5];
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					A[i][j] = -10 + rand() % 30;
					cout << "A[" << i << "]" << "[" << j << "]= " << A[i][j] << "\t";
				}cout << endl;
			}
			for (int i = 0; i < 5; i++)
			{

				if (A[0][i] < 0)
					A[0][i] = 0;
			}
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					cout << "A[" << i << "]" << "[" << j << "]= " << A[i][j] << "\t";
				}cout << endl;
			}
		}
		else if (F == 10)
		{
			/*10.	Дана целочисленная прямоугольная матрица размера M·N.
			Отсортировать каждый столбец с четным номером по неубыванию,
			а каждый  столбец с нечетным номером -по невозрастанию.*/

			int A[2][4]; int temp;
			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					A[i][j] = 1 + rand() % 30;
					cout << "A[" << i << "]" << "[" << j << "]= " << A[i][j] << "\t";
				}cout << endl;
			}
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 1; j++)
				{
					for (int z = 1; z < j; z--)
					{
						if ((A[z - 1][i] > A[z][i]) && ((i % 2) != 0))
						{
							temp = A[z - 1][i];
							A[z - 1][i] = A[z][i];
							A[z][i] = temp;
						}
						if ((A[z - 1][i] > A[z][i]) && ((i % 2) != 0))
						{
							temp = A[z - 1][i];
							A[z - 1][i] = A[z][i];
							A[z][i] = temp;
						}
					}
				}
			}
			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					cout << "A[" << i << "]" << "[" << j << "]= " << A[i][j] << "\t";
				}cout << endl;
			}
		}
		else if (F == 11)
		{
			/*11.	Дана целочисленная прямоугольная матрица размера M·N.
			Сформировать одномерный массив, состоящий из элементов, лежащих в интервале [1,20].
			Найти среднеарифметическое  полученного одномерного массива*/
			int A[4][8]; int temp;
			int Z[32];
			int index1 = 0;
			int zh = 0;
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					A[i][j] = 1 + rand() % 100;
					cout << "A[" << i << "]" << "[" << j << "]= " << A[i][j] << "\t";
				}cout << endl;
			}
			cout << "-----------------" << endl;
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					if ((A[i][j] > 0) && (A[i][j] < 8))
					{
						Z[index1] = A[i][j];
						zh += Z[index1];
						index1++;
					}

				}
			}
			for (int i = 0; i < index1; i++)
			{
				cout << "Z[" << i << "]= " << Z[i] << endl;
			}
			cout << "среднее арифметическое этой матрицы= " << zh / index1 << endl;
		}
		else if (F == 12)
		{
			/*12.	Дана матрица целых чисел размера NxM. Вывести номер строки, содержащей минимальное число одинаковых элементов*/
			int A[3][4];
			int index;
			int chet = 0;
			int min = 1000;
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					A[i][j] = 1 + rand() % 10;
					cout << "A[" << i << "]" << "[" << j << "]= " << A[i][j] << "\t";
				}cout << endl;
			}
			for (int i = 0; i < 3; i++)
			{
				chet = 0;
				for (int j = 0; j < 4; j++)
				{
					for (int z = j + 1; z < 4; z++)
					{
						if (A[i][j] == A[i][z])
						{
							chet++;
						}
					}
				}
				if (min > chet)
				{
					min = chet;
					index = i;
				}
			}
			cout << " минимальное колличество совподений в строке " << index << endl;

		}
		else if (F == 13)
		{
			/*13.	Дан массив фамилий студентов 1-го курса и массив их результатов в беге на 100 метров.
			Составьте команду из четырех лучших бегунов для участия в эстафете.*/
			int A[5];
			char B[5][10];
			int temp;
			unsigned char Z[48];
			for (int i = 0; i < 5; i++)
			{
				cout << "Введите имя " << i << "студента" << endl;
				cin >> B[i];
			}
			for (int i = 0; i < 5; i++)
			{
				A[i] = 1 + rand() % 13;
				cout << B[i] << " Студент пробежал за " << A[i] << " секунд" << endl;
			}
			for (int i = 0; i < 4; i++)
				for (int j = 4; j > i; j--)
					if (A[j - 1] < A[j])
					{
						temp = A[j - 1];
						A[j - 1] = A[j];
						A[j] = temp;
						for (int g = 0; g < 10; g++)
						{
							Z[g] = B[j - 1][g];
							B[j - 1][g] = B[j][g];
							B[j][g] = Z[g];
						}
					}
			for (int i = 0; i < 4; i++)
			{
				cout << B[i] << " Студент пробежал за " << A[i] << " секунд" << endl;
			}
		}
		else if (F == 14)
		{
			/*14.	Сформируйте массив L(I,J) с помощью датчика случайных чисел. Увеличить каждый элемент массива в 3 раза и поменяйте знак на противоположный.
			Массив выведите на экран в виде таблицы.*/
			int A[3][4];
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					A[i][j] = 1 + rand() % 10;
					cout << "A[" << i << "]" << "[" << j << "]= " << A[i][j] << "\t";
				}cout << endl;
			}
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					A[i][j] *= 3 * (-1);
				}
			}
			cout << "----------------------" << endl;
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					cout << "A[" << i << "]" << "[" << j << "]= " << A[i][j] << "\t";
				}cout << endl;
			}

		}
		else if (F == 15)
		{
			/*15.	Дана квадратная матрица. Сформировать одномерный массив, состоящий из элементов, расположенных ниже главной диагонали матрицы.
			Выполнить сортировку одномерного массива. Вывести матрицу, одномерный массив до сортировки, одномерный массив после сортировки.*/
			int A[5][5];
			int B[5];
			int temp;
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					A[i][j] = 1 + rand() % 10;
					cout << "A[" << i << "]" << "[" << j << "]= " << A[i][j] << "\t";
				}cout << endl;
			}
			for (int i = 0, j = 0; i<5, j < 5; i++, j++)
			{
				B[i] = A[i][j];
			}
			cout << "ДО сортировки" << endl;
			for (int i = 0; i < 5; i++)
			{
				cout << "B[" << i << "]= " << B[i] << endl;
			}
			for (int i = 0; i < 4; i++)
				for (int j = 4; j > i; j--)
					if (B[j - 1] > B[j])
					{
						temp = B[j - 1];
						B[j - 1] = B[j];
						B[j] = temp;
					}
			cout << "После" << endl;
			for (int i = 0; i < 5; i++)
			{
				cout << "B[" << i << "]= " << B[i] << endl;
			}
		}
		else if (F == 16)
		{
			/*16.	Разработать программу, реализующую обработку числового двухмерного произвольного массива тремя методами сортировки (пузырьком, вставкой, выбором).*/
			int A[5][5];
			int temp;
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					A[i][j] = 1 + rand() % 10;
					cout << "A[" << i << "]" << "[" << j << "]= " << A[i][j] << "\t";
				}cout << endl;
			}
			cout << "Сортировка пузырьком" << endl;
			for (int z = 0; z < 5; z++)
			{
				for (int i = 0; i < 4; i++)
					for (int j = 4; j > i; j--)
						if (A[z][j - 1] > A[z][j])
						{
							temp = A[z][j - 1];
							A[z][j - 1] = A[z][j];
							A[z][j] = temp;
						}

			}
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					cout << "A[" << i << "]" << "[" << j << "]= " << A[i][j] << "\t";
				}cout << endl;
			}
			cout << "Cортировка выбором" << endl;
			int min;
			for (int z = 0; z < 5; z++)
			{
				for (int i = 0; i < 4; i++)
				{
					min = i;
					for (int j = i + 1; j < 4; j++)
					{
						if (A[z][j] < A[z][min])
							min = j;
					}
					temp = A[z][i];
					A[i] - A[min];
					A[z][min] = temp;
				}
			}
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					cout << "A[" << i << "]" << "[" << j << "]= " << A[i][j] << "\t";
				}cout << endl;
			}
			cout << "Сортировка вставкой" << endl;
			int value;
			int index;
			for (int z = 0; z < 5; z++)
			{
				for (int i = 1; i < 5; i++)
				{
					value = A[z][i];
					index = i;
					while ((index > 0) && (A[z][index - 1] > value))
					{
						A[z][index] = A[z][index - 1];
						index--;
					}
					A[z][index] = value;
				}
			}
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					cout << "A[" << i << "]" << "[" << j << "]= " << A[i][j] << "\t";
				}cout << endl;
			}
		

		}
		cin >> f;
	} while (f = 'y');
}