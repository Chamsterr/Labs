using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.ServiceModel;
using System.Text;

// ПРИМЕЧАНИЕ. Команду "Переименовать" в меню "Рефакторинг" можно использовать для одновременного изменения имени интерфейса "IService2" в коде и файле конфигурации.
[ServiceContract]
public interface IService2
{
    [OperationContract]
    void DoWork();
}
