using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SampleFactory.Car
{
    public interface Icar
    {
        string GetName();
        void AssemblyBody();
        void AssemblyEngine();
        void AssemblyWheels();
    }
}
