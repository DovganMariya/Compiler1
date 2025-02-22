using SampleObsever.Subscriber;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SampleObsever.Publisher
{
    public interface IPublisher
    {
        void subscribe(ISubscriber subscriber);
        void unsubscribe(ISubscriber subscriber);
        void notify(); 
    }
}
