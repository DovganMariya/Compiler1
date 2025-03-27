using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SampleFactory.Factory.Parts
{
    public class CityWheels : IWheels
    {
        public CityWheels()
        {
            Console.WriteLine("Установка колес \"15 радиуса");
        }
    }
}
