using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SampleObsever.Subscriber
{
    internal class WidgetIcq : ISubscriber
    {
        private string icqText = "";
        public void update(string telegram, string vk, string icq)
        {
            icqText = icq;
            display();
        }
        private void display()
        {
            Console.WriteLine("ICQ:{0}",icqText);
        }
    }
}
