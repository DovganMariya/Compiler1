using SampleStrategy.Fly;
using SampleStrategy.Quack;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;

namespace SampleStrategy.Duck
{
    public abstract class DuckBase
    {
        protected IFlyable flyBehavior;
        protected IQuackble quackBehavior;

        public DuckBase()
        {
            flyBehavior = new SimpleFly();
            quackBehavior = new SimpleQuack();
        }
        public abstract void Dispay();
        public void DoSomething()
        {
            flyBehavior.Fly();
            quackBehavior.Quack();
        }
        public void SetFlyStrat(IFlyable fly)
        {
            flyBehavior = fly;

        }
        public void SetQuackStrat(IQuackble quack)
        {
            quackBehavior = quack;
        }
    }

}
