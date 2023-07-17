using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WinFormsApp2
{
    internal class Worker
    {
        [JsonProperty]
        public string FullName { get; set; }
        [JsonProperty]
        public string JobTitle { get; set; }

        public Worker(string full, string job)
        {
            FullName = full;
            JobTitle = job;
        }

        public override string ToString()
        {
            return $"{JobTitle}: {FullName}";
        }
    }
}
