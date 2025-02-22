using SampleObsever.Subscriber;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;

namespace SampleObsever.Publisher
{
    public class NewsAgregator : IPublisher
    {
        private List<ISubscriber> subscribers;
        private Random random;
        public NewsAgregator()
        {
            subscribers = new List<ISubscriber>();
            random=new Random();
        }
        public void notify()
        {
            string telegramText = getTelegramNews();
            string vkText = getVkNews();
            string icqText = getIcqNews();

            foreach(ISubscriber subscriber in subscribers)
            {
                subscriber.update(telegramText, vkText, icqText);
            }
        }

        private string getIcqNews()
        {
            var news = new List<string>()
            {
                "0 новостей 1","0 новострей 2","0 новостей 2"
            };
            return news[random.Next(3)];
        }

        private string getVkNews()
        {
            var news = new List<string>()
            {
                "бла бла","Мизулина стала женой Шамана","В столовой нету скидок"
            };
            return news[random.Next(3)];
        }

        private string getTelegramNews()
        {
            var news = new List<string>() {
            "Павел дуров искупался в ванной",
            "Новость телеграм 2","Новость телега 3"};
            return news[random.Next(3)];
        }

        public void subscribe(ISubscriber subscriber)
        {
            subscribers.Add(subscriber);
        }

        public void unsubscribe(ISubscriber subscriber)
        {
            subscribers.Remove(subscriber);
        }
    }
}
