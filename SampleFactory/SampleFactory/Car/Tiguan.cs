using SampleFactory.Factory;
using SampleFactory.Parts;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SampleFactory.Car
{
    public class Tiguan : ICar
    {
        private string _name;
        private string _body;
        private IEngine _engine = "Gasoline";
        private IWheels _wheels = "\"14";
        private ICarPartsFactory _partsFactory;
        public Tiguan(ICarPartsFactory _partsFactory)
        {
            _name = "Tiguan";
            _body = "Crossover";
        }

        public void AssemblyBody()
        {
            Console.WriteLine("Установка кузова{0}", _body);
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
