using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _5task
{
    class CSCMatrix
    {
        int[] A;
        int[] LI;
        int[] LJ;
        int _size;
        public CSCMatrix(int[] value_arr, int[] rows_arr, int[] column_arr)
        {
            A = value_arr;
            LI = rows_arr;
            LJ = column_arr;
            _size = LJ.Length - 1;
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
            for (int i = 0; i < LI.Length; i++)
            {
                Console.Write($"{LI[i]} ");
            }
            Console.WriteLine();
            for (int i = 0; i < LJ.Length; i++)
            {
                Console.Write($"{LJ[i]} ");
            }
            Console.WriteLine();
        }
        public int GetValue(int i, int j)
        {
            int AA = 0; // значение искомого элемента
            int N1 = LJ[j] - 1;
            int N2 = LJ[j + 1] - 1;
            for (int k = N1; k < N2; k++)
            {
                if (LI[k] == i + 1)
                {
                    AA = A[k];
                    break;
                }
            }
            return AA;
        }
    }
}
