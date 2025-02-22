using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SampleObsever.Subscriber
{
    public class WidgetTelegram : ISubscriber
    {
        private string telegramText = " ";
        public void update(string telegram, string vk, string icq)
        {
            telegramText= telegram;
            display(); 
        }
        private void display()
        {
            Console.WriteLine("Telegram:{0}",telegramText);
        }
    }
}
