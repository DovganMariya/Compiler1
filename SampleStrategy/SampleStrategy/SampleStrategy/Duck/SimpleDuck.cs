using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SampleStrategy.Duck
{
    public class SimpleDuck : DuckBase
    {
        public override void Dispay()
        {
            Console.WriteLine("Обычная утка");
        }
    }
}
