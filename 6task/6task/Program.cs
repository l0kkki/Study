using System;

//Сохранить бинарное дерево в одномерный массив, 
//Реализовать методы Add(int) и Delete и Print.
//Распечатать дерево с учётом уровней(отступы сделать по уровню)

namespace _6task
{
    class Program
    {
        static void Main(string[] args)
        {
            BinTree Tree = new BinTree();
            for (int i = 0; i < 15; i++)
            {
                Tree.Add(i);
            }
            Tree.Delete(6);
            Tree.Print();
            foreach (int item in Tree.ToArray())
            {
                Console.Write($"{item} ");
            }
            Console.ReadLine();
        }
    }
}
