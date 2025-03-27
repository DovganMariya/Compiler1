using SampleFactory.Car;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SampleFactory.Factory
{
    public abstract class Facility
    {
        protected abstract Icar GetCar();

        public Icar BuildCar()
        {
            var car = GetCar();
            Console.WriteLine("Создание машины {0}", car.GetName());
            car.AssemblyBody();
            car.AssemblyEngine();
            car.AssemblyWheels();
            return car;
        }
    }
}
