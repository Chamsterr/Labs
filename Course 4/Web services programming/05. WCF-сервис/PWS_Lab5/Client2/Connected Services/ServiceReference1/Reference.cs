﻿//------------------------------------------------------------------------------
// <auto-generated>
//     Этот код создан программой.
//     Исполняемая версия:4.0.30319.42000
//
//     Изменения в этом файле могут привести к неправильной работе и будут потеряны в случае
//     повторной генерации кода.
// </auto-generated>
//------------------------------------------------------------------------------

namespace Client2.ServiceReference1 {
    
    
    [System.CodeDom.Compiler.GeneratedCodeAttribute("System.ServiceModel", "4.0.0.0")]
    [System.ServiceModel.ServiceContractAttribute(ConfigurationName="ServiceReference1.IService")]
    public interface IService {
        
        [System.ServiceModel.OperationContractAttribute(Action="http://tempuri.org/IService/Add", ReplyAction="http://tempuri.org/IService/AddResponse")]
        int Add(int x, int y);
        
        [System.ServiceModel.OperationContractAttribute(Action="http://tempuri.org/IService/Add", ReplyAction="http://tempuri.org/IService/AddResponse")]
        System.Threading.Tasks.Task<int> AddAsync(int x, int y);
        
        [System.ServiceModel.OperationContractAttribute(Action="http://tempuri.org/IService/Concat", ReplyAction="http://tempuri.org/IService/ConcatResponse")]
        string Concat(string x, double y);
        
        [System.ServiceModel.OperationContractAttribute(Action="http://tempuri.org/IService/Concat", ReplyAction="http://tempuri.org/IService/ConcatResponse")]
        System.Threading.Tasks.Task<string> ConcatAsync(string x, double y);
        
        [System.ServiceModel.OperationContractAttribute(Action="http://tempuri.org/IService/Sum", ReplyAction="http://tempuri.org/IService/SumResponse")]
        WCF.A Sum(WCF.A x, WCF.A y);
        
        [System.ServiceModel.OperationContractAttribute(Action="http://tempuri.org/IService/Sum", ReplyAction="http://tempuri.org/IService/SumResponse")]
        System.Threading.Tasks.Task<WCF.A> SumAsync(WCF.A x, WCF.A y);
    }
    
    [System.CodeDom.Compiler.GeneratedCodeAttribute("System.ServiceModel", "4.0.0.0")]
    public interface IServiceChannel : Client2.ServiceReference1.IService, System.ServiceModel.IClientChannel {
    }
    
    [System.Diagnostics.DebuggerStepThroughAttribute()]
    [System.CodeDom.Compiler.GeneratedCodeAttribute("System.ServiceModel", "4.0.0.0")]
    public partial class ServiceClient : System.ServiceModel.ClientBase<Client2.ServiceReference1.IService>, Client2.ServiceReference1.IService {
        
        public ServiceClient() {
        }
        
        public ServiceClient(string endpointConfigurationName) : 
                base(endpointConfigurationName) {
        }
        
        public ServiceClient(string endpointConfigurationName, string remoteAddress) : 
                base(endpointConfigurationName, remoteAddress) {
        }
        
        public ServiceClient(string endpointConfigurationName, System.ServiceModel.EndpointAddress remoteAddress) : 
                base(endpointConfigurationName, remoteAddress) {
        }
        
        public ServiceClient(System.ServiceModel.Channels.Binding binding, System.ServiceModel.EndpointAddress remoteAddress) : 
                base(binding, remoteAddress) {
        }
        
        public int Add(int x, int y) {
            return base.Channel.Add(x, y);
        }
        
        public System.Threading.Tasks.Task<int> AddAsync(int x, int y) {
            return base.Channel.AddAsync(x, y);
        }
        
        public string Concat(string x, double y) {
            return base.Channel.Concat(x, y);
        }
        
        public System.Threading.Tasks.Task<string> ConcatAsync(string x, double y) {
            return base.Channel.ConcatAsync(x, y);
        }
        
        public WCF.A Sum(WCF.A x, WCF.A y) {
            return base.Channel.Sum(x, y);
        }
        
        public System.Threading.Tasks.Task<WCF.A> SumAsync(WCF.A x, WCF.A y) {
            return base.Channel.SumAsync(x, y);
        }
    }
}
