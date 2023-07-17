using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Collections.Specialized;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;

namespace OOP9
{
    class Software
    {
        public string name { get; set; }
        public Software(string name)
        {
            this.name = name;
        }

        public override string ToString()
        {
            return name;
        }
    }

    class SortedList<T> : IList
    {
        private object[] _contents = new object[8];
        private int _count;

        public SortedList()
        {
            _count = 0;
        }

        // IList Members
        public int Add(object value)
        {
            if (_count < _contents.Length)
            {
                _contents[_count] = value;
                _count++;

                return (_count - 1);
            }

            return -1;
        }

        public void Clear()
        {
            _count = 0;
        }

        public bool Contains(object value)
        {
            for (int i = 0; i < Count; i++)
            {
                if (_contents[i] == value)
                {
                    return true;
                }
            }
            return false;
        }

        public int IndexOf(object value)
        {
            for (int i = 0; i < Count; i++)
            {
                if (_contents[i] == value)
                {
                    return i;
                }
            }
            return -1;
        }

        public void Insert(int index, object value)
        {
            if ((_count + 1 <= _contents.Length) && (index < Count) && (index >= 0))
            {
                _count++;

                for (int i = Count - 1; i > index; i--)
                {
                    _contents[i] = _contents[i - 1];
                }
                _contents[index] = value;
            }
        }

        public bool IsFixedSize
        {
            get
            {
                return true;
            }
        }

        public bool IsReadOnly
        {
            get
            {
                return false;
            }
        }

        public void Remove(object value)
        {
            RemoveAt(IndexOf(value));
        }

        public void RemoveAt(int index)
        {
            if ((index >= 0) && (index < Count))
            {
                for (int i = index; i < Count - 1; i++)
                {
                    _contents[i] = _contents[i + 1];
                }
                _count--;
            }
        }

        public object this[int index]
        {
            get
            {
                return _contents[index];
            }
            set
            {
                _contents[index] = value;
            }
        }

        // ICollection members.

        public void CopyTo(Array array, int index)
        {
            for (int i = 0; i < Count; i++)
            {
                array.SetValue(_contents[i], index++);
            }
        }

        public int Count
        {
            get
            {
                return _count;
            }
        }

        public bool IsSynchronized
        {
            get
            {
                return false;
            }
        }

        // Return the current instance since the underlying store is not
        // publicly available.
        public object SyncRoot
        {
            get
            {
                return this;
            }
        }

        // IEnumerable Members

        public IEnumerator GetEnumerator()
        {
            // Refer to the IEnumerator documentation for an example of
            // implementing an enumerator.
            throw new NotImplementedException("The method or operation is not implemented.");
        }

        public void PrintContents()
        {
            Console.WriteLine($"List has a capacity of {_contents.Length} and currently has {_count} elements.");
            Console.Write("List contents:");
            for (int i = 0; i < Count; i++)
            {
                Console.Write($" {_contents[i]}");
            }
            Console.WriteLine();
        }

        public void DeleteNitems(int from, int n)
        {
            for (int i = 0; i < n; i++)
            {
                this.RemoveAt(from);
            }
        }

        public void CopyToStack(GeneralStack<T> gs)
        {
            for (int i = 0; i < this.Count; i++)
            {
                gs.Push(_contents[i]);
            }
        }
    }

    public class GeneralStack<T>
    {
        private Stack<object> _contents = new Stack<object> { };
        private List<object> _contentsForPrint = new List<object> { };
        public void Push(object obj)
        {
            _contents.Push(obj);
            _contentsForPrint.Add(obj);
        }
        public int Size()
        {
            return _contents.Count;
        }
        public void PrintElements()
        {
            foreach (object obj in _contents)
            {
                Console.WriteLine(obj.ToString());
            }
        }

        public int FindElement(T name)
        {
            for (int i = 0; i < _contents.Count; i++)
            {
                if (_contentsForPrint[i].ToString() == name.ToString())
                {
                    return i;
                }
            }
            return -1;
        }

    }

    class Program
    {
        static void Main(string[] args)
        {
            Software software = new Software("Mathcad");
            Software software2 = new Software("Git Bash");
            Software software3 = new Software("Cclear");
            SortedList<int> collection =  new SortedList<int>() { };

            var test = "kkkk";
            int k = 4;

            collection.Add(software);
            collection.Add(software2);
            collection.Add(software3);
            collection.Add(test);
            collection.Add(k);

            collection.PrintContents();

            Console.WriteLine("-------------------Удаление--------------------");
            collection.RemoveAt(0);

            collection.PrintContents();
            //------------------------------------------------------------------

            collection.DeleteNitems(1, 2);
            collection.PrintContents();

            //------------------------------------------------------------------

            GeneralStack<int> gstack = new GeneralStack<int> { };

            Console.WriteLine("-------------------Вторая коллекция--------------------");
            collection.CopyToStack(gstack);
            gstack.PrintElements();

            Console.WriteLine("-------------------Поиск в коллекции--------------------");
            Console.WriteLine(gstack.FindElement(4));

            Console.WriteLine("Создайте объект наблюдаемой коллекции ObservableCollection");
            ObservableCollection<Software> values = new ObservableCollection<Software>();

            values.CollectionChanged += CollectionChangedd;

            values.Add(software);

            static void CollectionChangedd(object obj, NotifyCollectionChangedEventArgs e)
            {
                switch (e.Action)
                {
                    case NotifyCollectionChangedAction.Add:
                        Console.WriteLine($"Добавлен новый объект");
                        break;

                    case NotifyCollectionChangedAction.Remove:
                        Console.WriteLine($"Удален объект");
                        break;
                }
            }
        }
    }
}
