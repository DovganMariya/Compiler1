using SampleFactory.Factory;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SampleFactory.Car
{
    public class Golf : ICar
    {
        private string _name;
        private string _body;
        private IEngine _engine="Gasoline";
        private IWheels _wheels="\"14";
        private ICarPartsFactory _partsFactory;
        public Golf(ICarPartsFactory partsFactory)
        {
            _name = "Golf";
            _body = "Hatchback";
            _partsFactory= partsFactory;
        }

        public void AssemblyBody()
        {
            Console.WriteLine("Установка кузова{0}",_body);
        }

        public void AssemblyEngine()
        {
            _engine = _partsFactory.GetEngine();
        }

        public void AssemblyWheels()
        {
            _wheels = _partsFactory.GetWheels();
        }

        public string GetName()
        {
            return _name;
        }
    }

    
}
