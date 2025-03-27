using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SampleFactory.Factory.Parts
{
    public class DieselEngine : IEngine
    {
        public DieselEngine()
        {
            Console.WriteLine("Установка дизильного двигателя");
        }
    }
}
