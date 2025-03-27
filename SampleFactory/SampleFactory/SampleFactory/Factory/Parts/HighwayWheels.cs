using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SampleFactory.Factory.Parts
{
    public class HighwayWheels : IWheels
    {
        public HighwayWheels()
        {
            Console.WriteLine("Установка колес \"17 радиуса");
        }
    }
}
