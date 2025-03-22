using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SampleFactory.Parts
{
    public class DieselEngine : IEngine
    {
        public DieselEngine()
        {
            Console.WriteLine("Установка дизельного двигателя");
        }
    }
}
