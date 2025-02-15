using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SampleStrategy.Quack
{
    internal class NoQuack : IQuackble
    {
        public void Quack()
        {
            Console.WriteLine("silence");
        }
    }
}
