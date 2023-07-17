using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Newtonsoft.Json;

namespace WinFormsApp2
{
    internal class Plane
    {
        [JsonProperty(PropertyName = "id")]
        public string ID { get; set; }

        [JsonProperty(PropertyName = "type")]
        public string Type { get; set; }

        [JsonProperty(PropertyName = "model")]
        public string Model { get; set; }

        [JsonProperty(PropertyName = "workers")]
        public List<Worker> Workers { get; set; } = new List<Worker>();

        [JsonProperty(PropertyName = "numberOfPlace")]
        public int NumberOfPlace { get; set; }

        [JsonProperty(PropertyName = "carrying")]
        public int Carrying { get; set; }

        [JsonProperty(PropertyName = "technicalInspection")]
        public DateTime TechnicalInspection { get; set; }

        public Plane(string ID, string type, string model, string crew, int numberOfPlace, int carrying, DateTime technicalInspection)
        {
            if (ID != "")
            {
                this.ID = ID;
            }
            else
            {
                this.ID = "1";
            }
            this.Type = type;
            this.Model = model;
            this.NumberOfPlace = numberOfPlace;
            this.Carrying = carrying;
            this.TechnicalInspection = technicalInspection;

            if (crew != null)
            {
                foreach (var worker in crew.Split(','))
                {
                    Worker worker1 = new Worker(worker.Split(':')[1], worker.Split(':')[0]);
                    Workers.Add(worker1);
                }
            }
        }
    }
}
