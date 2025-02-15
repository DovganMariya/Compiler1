using SampleStrategy.Fly;
using SampleStrategy.Quack;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SampleStrategy.Duck
{
    public class DisabledDuck : DuckBase
    {
        public DisabledDuck() 
        {
            flyBehavior = new NoFly();
            quackBehavior = new NoQuack();
        }
        public override void Dispay()
        {
            Console.WriteLine("Выключенная утка");
        }
    }
}
