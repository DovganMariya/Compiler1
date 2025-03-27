using SampleFactory.Factory;
using SampleFactory.Factory.Parts;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SampleFactory.Car
{
    public class Tiguan : Icar
    {
        private string _name;
        private string _body;
        private IEngine _engine;
        private IWheels _wheels;
        private ICarPartsFactory _partsFactory;

        public Tiguan(ICarPartsFactory partsFactory)
        {
            _name = "Golf";
            _body = "Hetchback";
            _partsFactory = partsFactory;
        }

        public void AssemblyBody()
        {
            Console.WriteLine("Установка кузова {0}", _body);
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
