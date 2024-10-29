using System.ServiceModel;

namespace WCF
{
    [ServiceContract]
    public interface IService
    {
        [OperationContract]
        int Add(int x, int y);

        [OperationContract]
        string Concat(string x, double y);

        [OperationContract]
        A Sum(A x, A y);
    }
}
