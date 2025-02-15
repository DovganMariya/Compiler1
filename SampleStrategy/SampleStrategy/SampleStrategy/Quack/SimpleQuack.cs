using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SampleStrategy.Quack
{
    public class SimpleQuack : IQuackble
    {
        void IQuackble.Quack()
        {
            Console.WriteLine("kryakrya");
        }
    }
}
