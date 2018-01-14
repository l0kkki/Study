using System;

namespace AlgLab1
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Введите длину списка");
            int size = Int32.Parse(Console.ReadLine());
            CLL list = new CLL(size);
            Console.WriteLine("Введите номер выбывающего");
            int count = Int32.Parse(Console.ReadLine());
            Console.WriteLine($"При длине списка {list.Length} при выбывании каждого {count} останется");
            Console.WriteLine(list.Counting(count));
            Console.WriteLine();
            Console.WriteLine("Введите номер оставшегося");
            int last = Int32.Parse(Console.ReadLine());
            Console.WriteLine("Введите номер выбывающего");
            count = Int32.Parse(Console.ReadLine());
            Console.WriteLine($"Если при длине списка {list.Length} при выбывании каждого {count} останется {last}");
            Console.WriteLine($"Отсчет надо начать с {list.WhoStart(last, count)}");
            Console.ReadLine();
        }
    }
}
