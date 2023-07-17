using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_17_18_OOP
{
    public interface ITelephoneExchange
    {
        ITelephoneExchange Clone();
        void GetSubscribers();
    }
}