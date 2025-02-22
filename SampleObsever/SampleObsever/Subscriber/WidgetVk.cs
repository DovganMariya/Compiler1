using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SampleObsever.Subscriber
{
    public class WidgetVk : ISubscriber
    {
        private string vkText = "";
        public void update(string telegram, string vk, string icq)
        {
            vkText = vk;
            display();
        }
        private void display()
        {
            Console.WriteLine("VK: {0}", vkText);
        }
    }
}
