using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

//Задача 12. Дана разреженная матрица CSR. Найти её определитель.
namespace AlgLab2
{
    class Program
    {
        static void Main(string[] args)
        {
            //int[,] mass = new int[3,3]{ { 0, 2, 1 }, { 0, 0, 0 }, { 1, 0, 0 } };
            int[] A = new int[] { 1, 3,2,7,4,3,9,5,2,3 };
            int[] LJ = new int[] { 1, 2,3,1,2,3,1,4,5,6 };
            int[] LI = new int[] { 1, 4,6,7,9,10,11 };
            CSRmatrix matrix = new CSRmatrix(A,LJ,LI);
            matrix.Print_Pack();
            Console.WriteLine();
            matrix.Print_Unpack();
            Console.WriteLine();
            Console.WriteLine($"Определитель матрицы равен { matrix.Determinant()}");//-1530 http://matematikam.ru/matrici-online/determinant.php
            Console.ReadLine();
        }
    }
}
