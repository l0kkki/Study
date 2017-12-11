using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AlgLab2
{
    class CSRmatrix
    {
        int[] A;
        int[] LJ;
        int[] LI;
        int _size;
        public CSRmatrix(int[] value_arr, int[] column_arr, int[] rows_arr)
        {
            A = value_arr;
            LJ = column_arr;
            LI = rows_arr;
            _size = LI.Length - 1;
        }
        public void Print_Unpack()
        {
            Console.WriteLine("Матрциа в развернутом видет имеет вид: ");
            for (int i = 0; i < _size; i++)
            {
                for (int j = 0; j < _size; j++)
                {
                    Console.Write(GetValue(i, j));
                }
                Console.WriteLine();
            }
        }
        public void Print_Pack()
        {
            Console.WriteLine("Матрица хранится в 3х массивах:");
            for (int i = 0; i < A.Length; i++)
            {
                Console.Write($"{A[i]} ");
            }
            Console.WriteLine();
            for (int i = 0; i < LJ.Length; i++)
            {
                Console.Write($"{LJ[i]} ");
            }
            Console.WriteLine();
            for (int i = 0; i < LI.Length; i++)
            {
                Console.Write($"{LI[i]} ");
            }
            Console.WriteLine();
        }
        public int GetValue(int i, int j)
        {
            int AA = 0; // значение искомого элемента
            int N1 = LI[i]-1;
            int N2 = LI[i+1]-1;
            for (int k = N1; k < N2; k++)
            {
                if (LJ[k] == j+1)
                {
                    AA = A[k];
                    break;
                }
            }
            return AA;
        }
        public int Determinant()
        {
            int Det = 0;
            if (_size == 1)
                return this.GetValue(0, 0);
            if (_size == 2)
                return this.GetValue(0, 0) * this.GetValue(1, 1);
            for (int j = 0; j < _size; j++)
            {
                Det = Det + (int)Math.Pow(-1,j+2)*this.GetValue(0, j) * this.Minor(0, j).Determinant();
            }
            return Det;
        }        
        public CSRmatrix Minor(int i, int j)
        {
            //удаляем строку
            //массив строк сократится на 1
            int[] cut_rows_LI = new int[LI.Length - 1];
            //считаем сколько элементов хранилось в этой строке
            int count_value_in_rows = LI[i + 1] - LI[i];//счетчик значений в строке
            //уменьшаем соответственно на это число массив элементов и массив столбцов
            int[] cut_rows_A = new int[A.Length - count_value_in_rows];
            int[] cut_rows_LJ = new int[cut_rows_A.Length];
            //работаем с массивом строк
            //до i строки количество элементов не поменялось переносим все без измениений
            for (int k = 0; k <= i; k++)
            {
                cut_rows_LI[k] = LI[k];
            }
            //начиная с i+1 строки в новом масиве переносим значения i+2 из старого массива уменшенное
            //на количество удаленных элементов count_value_in_rows
            for (int k = i + 1; k < cut_rows_LI.Length; k++)
            {
                cut_rows_LI[k] = LI[k + 1] - count_value_in_rows;
            }
            //работаем с массивом значений
            //LI[i] - LI[0] первых значений остаются в новом массиве
            for (int k = 0; k < LI[i] - LI[0]; k++)
            {
                cut_rows_A[k] = A[k];
            }
            //LI[i] - LI[0]+1 значение в новом массиве будет равнятся LI[i] - LI[0]+count_value_in_rows в старом
            for (int k = LI[i] - LI[0]; k < cut_rows_A.Length; k++)
            {
                cut_rows_A[k] = A[k+count_value_in_rows];
            }
            //аналогично преобразуется массив столбцов
            for (int k = 0; k < LI[i] - LI[0]; k++)
            {
                cut_rows_LJ[k] = LJ[k];
            }
            for (int k = LI[i] - LI[0] ; k < cut_rows_LJ.Length; k++)
            {
                cut_rows_LJ[k] = LJ[k + count_value_in_rows];
            }
            //удаляем cтолбец
            //просмтатриваем массив столбцов, считаем сколько элементов есть в этом столбце
            int count_value_in_columns = 0;//счетчик значений в столбце
            for (int k = 0; k < cut_rows_LJ.Length; k++)
            {
                if (cut_rows_LJ[k] - 1 == j)
                    count_value_in_columns++;
            }
            //выделяем память под итоговые массивы
            //уменьшится массив значений и массив столбцов
            //массив строк без изменений размера
            int[] summary_LI = new int[cut_rows_LI.Length];
            //копируем массив строк
            cut_rows_LI.CopyTo(summary_LI,0);
            int[] summary_A = new int[cut_rows_A.Length - count_value_in_columns];
            int[] summary_LJ = new int[summary_A.Length];
            int index_count = 0;
            for (int k = 0; k < cut_rows_LJ.Length; k++)
            {
                //при каждом совпадении номера столбца в LJ с номером удаляемого столбца
                //уменьшаем значение элементов в LI на 1 в соответствующем интервале
                if(cut_rows_LJ[k]-1==j)
                {
                    for (int l = cut_rows_LI.Length-1; cut_rows_LI[l]-1>k; l--)
                    {
                        summary_LI[l]--;
                    }
                }
                //элементы, кторые не надо удалять переносим без изменений
                //номера столбцов без изменений до удаляемого
                //и уменьшаем на 1 при переносе после удаляемого
                else
                {
                    summary_A[index_count] = cut_rows_A[k];
                    if (cut_rows_LJ[k]-1 < j)
                        summary_LJ[index_count] = cut_rows_LJ[k];
                    else if (cut_rows_LJ[k]-1 > j)
                        summary_LJ[index_count] = cut_rows_LJ[k] - 1;
                    index_count++;
                }
            }
            return new CSRmatrix(summary_A, summary_LJ, summary_LI);
        }            
    }
}
