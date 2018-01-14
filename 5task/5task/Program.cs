using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _5task
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] A = new int[] {2,5,8,1,4,9,1,1,3};
            int[] LI = new int[] {1,3,6,1,6,4,3,4,6};
            int[] LJ = new int[] {1,1,4,4,6,7,10};
            CSCMatrix matrix = new CSCMatrix(A, LI, LJ);
            matrix.Print_Pack();
            Console.WriteLine();
            matrix.Print_Unpack();
            Console.ReadLine();
        }
    }
}
