//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated from a template.
//
//     Manual changes to this file may cause unexpected behavior in your application.
//     Manual changes to this file will be overwritten if the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

namespace PWS_Lab6
{
    using System;
    using System.Collections.Generic;
    
    public partial class note
    {
        public int id { get; set; }
        public Nullable<int> stud_id { get; set; }
        public string subject { get; set; }
        public Nullable<int> note1 { get; set; }
    
        public virtual student student { get; set; }
    }
}
