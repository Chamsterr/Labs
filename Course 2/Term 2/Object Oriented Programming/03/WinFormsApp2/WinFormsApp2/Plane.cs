using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;
using Newtonsoft.Json;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;

namespace WinFormsApp2
{
    internal class Plane
    {
        [ID]
        [JsonProperty(PropertyName = "id")]
        public string ID { get; set; }

        [Required(ErrorMessage = "Type is required.")]
        [JsonProperty(PropertyName = "type")]
        public string Type { get; set; }

        [Required(ErrorMessage = "Model is required.")]
        [JsonProperty(PropertyName = "model")]
        public string Model { get; set; }

        [Required(ErrorMessage = "Crew is required.")]
        [MinLength(1, ErrorMessage = "Crew is required.")]
        [JsonProperty(PropertyName = "workers")]
        public List<Worker> Workers { get; set; } = new List<Worker>();

        [JsonProperty(PropertyName = "numberOfPlace")]
        public int NumberOfPlace { get; set; }

        [JsonProperty(PropertyName = "carrying")]
        public int Carrying { get; set; }

        [TechnicalServiceDate(nameof(date), nameof(TechnicalInspection))]
        [JsonProperty(PropertyName = "date")]
        public DateTime date { get; set; }

        [TechnicalServiceDate("date", "TechnicalInspection")]
        [JsonProperty(PropertyName = "technicalInspection")]
        public DateTime TechnicalInspection { get; set; }


        public Plane(string ID, string type, string model, string crew, int numberOfPlace, int carrying, DateTime date, DateTime technicalInspection)
        {
            this.ID = ID;
            this.Type = type;
            this.Model = model; 
            this.NumberOfPlace = numberOfPlace;
            this.Carrying = carrying;
            this.date = date;
            this.TechnicalInspection = technicalInspection;

            if (crew != "" && crew != null)
            {
                foreach (var worker in crew.Split(','))
                {
                    Worker worker1 = new Worker(worker.Split(':')[1], worker.Split(':')[0]);
                    Workers.Add(worker1);
                }
            }
        }
        public override string ToString()
        {
            StringBuilder sb = new StringBuilder();
            sb.Append("==================================");
            sb.Append($" ID: {ID}\n Type: {Type}\n Model: {Model}\n Number of places: {NumberOfPlace}\n Carrying: {Carrying}\n TechnicalInspection: {TechnicalInspection}\n Date: {date} \n");
            sb.Append(" Crew:\n ");
            foreach (var worker in Workers)
            {
                sb.Append($"{worker.ToString()}\n");
            }
            return sb.ToString();
        }

    }
}
