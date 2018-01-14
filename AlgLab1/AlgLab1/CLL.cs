using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

//Задача 2. Вокруг считающего стоит N человек, из которых выделен первый, а остальные занумерованы по часовой стрелке числами от 2 до N. Считающий, начиная с кого-то, ведет счет до M. Человек на котором остановился счет, выходит из круга. Счет продолжается со следующего человека и так до тех пор, пока не останется один человек.
//Определить
//a) номер оставшегося человека, если известно M и то, что счет начинался с первого человека;
//b) номер человека c которого начинался счет, если известно M и номер оставшегося человека L.

namespace AlgLab1
{
    class CLL
    {
        private class node
        {
            public int number;
            public node next;
            public node()
            {
                number = 0;
                next = null;
            }
        }
        private node _head = new node();
        //remove
        private node _current;
        //remove
        private int length = 0;
        public CLL()
        {
            this._head = null;
            this._current = null;
        }
        public CLL(int size)
        {
            _head.number = 1;
            _head.next = _head;
            _current = _head;
            for (int i = 1; i < size; i++)
            {
                node temp = new node();
                temp.number = i + 1;
                temp.next = _current.next;
                _current.next = temp;
                _current = temp;
            }
            length = size;
            _current = _head;
        }
        private CLL DeepCopy()
        {
            return new CLL(length);
        }
        public int Length { get { return length; } }
        public void Print()
        {
            _current = _head;
            for(int i=0;i<length;i++)
            {
                Console.WriteLine(_current.number);
                _current = _current.next;
            }
        }
        public int Counting(int count)
        {
            CLL tmp = DeepCopy();
            for(int i=0;i<length-1;i++)
            {
                for (int j = 1; j < count-1; j++)
                {
                    //Console.WriteLine($"Текущий {tmp.number}");
                    tmp._current = tmp._current.next;                    
                }
                //Console.WriteLine($"Выбыл {tmp.next.number}");
                tmp._current.next = tmp._current.next.next;
                tmp._current = tmp._current.next;           
            }
            return tmp._current.number;
        }
        public int WhoStart(int number_of_last,int count)
        {
            int shift = number_of_last - Counting(count);
            //Console.WriteLine(shift);
            _current = _head;
            if (shift<0)
            {
                for (int i = 0; i < shift+length; i++)
                {
                    _current = _current.next; 
                }
            }
            else
            {
                for (int i = 0; i < shift; i++)
                {
                    _current = _current.next;
                }
            }
            return _current.number;
        }
    }
}
