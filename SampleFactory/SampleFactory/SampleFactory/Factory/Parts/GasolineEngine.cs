using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SampleFactory.Factory.Parts
{
    public class GasolineEngine : IEngine
    {
        public GasolineEngine()
        {
            Console.WriteLine("Установка бензинового двигателя");
        }
    }
}
