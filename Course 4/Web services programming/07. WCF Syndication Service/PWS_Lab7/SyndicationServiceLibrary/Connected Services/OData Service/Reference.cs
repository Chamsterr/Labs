﻿//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//     Runtime Version:4.0.30319.42000
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

// Original file name:
// Generation date: 9/30/2024 3:17:26 PM
namespace StudentsModel
{
    
    /// <summary>
    /// There are no comments for StudentsEntities11 in the schema.
    /// </summary>
    public partial class StudentsEntities11 : global::System.Data.Services.Client.DataServiceContext
    {
        /// <summary>
        /// Initialize a new StudentsEntities11 object.
        /// </summary>
        [global::System.CodeDom.Compiler.GeneratedCodeAttribute("System.Data.Services.Design", "1.0.0")]
        public StudentsEntities11(global::System.Uri serviceRoot) : 
                base(serviceRoot, global::System.Data.Services.Common.DataServiceProtocolVersion.V3)
        {
            this.OnContextCreated();
            this.Format.LoadServiceModel = GeneratedEdmModel.GetInstance;
        }
        partial void OnContextCreated();
        /// <summary>
        /// There are no comments for notes in the schema.
        /// </summary>
        [global::System.CodeDom.Compiler.GeneratedCodeAttribute("System.Data.Services.Design", "1.0.0")]
        public global::System.Data.Services.Client.DataServiceQuery<note> notes
        {
            get
            {
                if ((this._notes == null))
                {
                    this._notes = base.CreateQuery<note>("notes");
                }
                return this._notes;
            }
        }
        [global::System.CodeDom.Compiler.GeneratedCodeAttribute("System.Data.Services.Design", "1.0.0")]
        private global::System.Data.Services.Client.DataServiceQuery<note> _notes;
        /// <summary>
        /// There are no comments for students in the schema.
        /// </summary>
        [global::System.CodeDom.Compiler.GeneratedCodeAttribute("System.Data.Services.Design", "1.0.0")]
        public global::System.Data.Services.Client.DataServiceQuery<student> students
        {
            get
            {
                if ((this._students == null))
                {
                    this._students = base.CreateQuery<student>("students");
                }
                return this._students;
            }
        }
        [global::System.CodeDom.Compiler.GeneratedCodeAttribute("System.Data.Services.Design", "1.0.0")]
        private global::System.Data.Services.Client.DataServiceQuery<student> _students;
        /// <summary>
        /// There are no comments for notes in the schema.
        /// </summary>
        [global::System.CodeDom.Compiler.GeneratedCodeAttribute("System.Data.Services.Design", "1.0.0")]
        public void AddTonotes(note note)
        {
            base.AddObject("notes", note);
        }
        /// <summary>
        /// There are no comments for students in the schema.
        /// </summary>
        [global::System.CodeDom.Compiler.GeneratedCodeAttribute("System.Data.Services.Design", "1.0.0")]
        public void AddTostudents(student student)
        {
            base.AddObject("students", student);
        }
        [global::System.CodeDom.Compiler.GeneratedCodeAttribute("System.Data.Services.Design", "1.0.0")]
        private abstract class GeneratedEdmModel
        {
            [global::System.CodeDom.Compiler.GeneratedCodeAttribute("System.Data.Services.Design", "1.0.0")]
            private static global::Microsoft.Data.Edm.IEdmModel ParsedModel = LoadModelFromString();
            [global::System.CodeDom.Compiler.GeneratedCodeAttribute("System.Data.Services.Design", "1.0.0")]
            private const string ModelPart0 = "<edmx:Edmx Version=\"1.0\" xmlns:edmx=\"http://schemas.microsoft.com/ado/2007/06/edm" +
                "x\"><edmx:DataServices m:DataServiceVersion=\"1.0\" m:MaxDataServiceVersion=\"3.0\" x" +
                "mlns:m=\"http://schemas.microsoft.com/ado/2007/08/dataservices/metadata\"><Schema " +
                "Namespace=\"StudentsModel\" xmlns=\"http://schemas.microsoft.com/ado/2009/11/edm\"><" +
                "EntityType Name=\"note\"><Key><PropertyRef Name=\"id\" /></Key><Property Name=\"id\" T" +
                "ype=\"Edm.Int32\" Nullable=\"false\" p6:StoreGeneratedPattern=\"Identity\" xmlns:p6=\"h" +
                "ttp://schemas.microsoft.com/ado/2009/02/edm/annotation\" /><Property Name=\"stud_i" +
                "d\" Type=\"Edm.Int32\" /><Property Name=\"subject\" Type=\"Edm.String\" MaxLength=\"20\" " +
                "FixedLength=\"false\" Unicode=\"true\" /><Property Name=\"note1\" Type=\"Edm.Int32\" /><" +
                "NavigationProperty Name=\"student\" Relationship=\"StudentsModel.FK__note__stud_id_" +
                "_38996AB5\" ToRole=\"student\" FromRole=\"note\" /></EntityType><EntityType Name=\"stu" +
                "dent\"><Key><PropertyRef Name=\"id\" /></Key><Property Name=\"id\" Type=\"Edm.Int32\" N" +
                "ullable=\"false\" p6:StoreGeneratedPattern=\"Identity\" xmlns:p6=\"http://schemas.mic" +
                "rosoft.com/ado/2009/02/edm/annotation\" /><Property Name=\"name\" Type=\"Edm.String\"" +
                " MaxLength=\"50\" FixedLength=\"false\" Unicode=\"true\" /><NavigationProperty Name=\"n" +
                "otes\" Relationship=\"StudentsModel.FK__note__stud_id__38996AB5\" ToRole=\"note\" Fro" +
                "mRole=\"student\" /></EntityType><Association Name=\"FK__note__stud_id__38996AB5\"><" +
                "End Type=\"StudentsModel.student\" Role=\"student\" Multiplicity=\"0..1\" /><End Type=" +
                "\"StudentsModel.note\" Role=\"note\" Multiplicity=\"*\" /><ReferentialConstraint><Prin" +
                "cipal Role=\"student\"><PropertyRef Name=\"id\" /></Principal><Dependent Role=\"note\"" +
                "><PropertyRef Name=\"stud_id\" /></Dependent></ReferentialConstraint></Association" +
                "></Schema><Schema Namespace=\"PWS_Lab6\" xmlns=\"http://schemas.microsoft.com/ado/2" +
                "009/11/edm\"><EntityContainer Name=\"StudentsEntities11\" m:IsDefaultEntityContaine" +
                "r=\"true\"><EntitySet Name=\"notes\" EntityType=\"StudentsModel.note\" /><EntitySet Na" +
                "me=\"students\" EntityType=\"StudentsModel.student\" /><AssociationSet Name=\"FK__not" +
                "e__stud_id__38996AB5\" Association=\"StudentsModel.FK__note__stud_id__38996AB5\"><E" +
                "nd Role=\"note\" EntitySet=\"notes\" /><End Role=\"student\" EntitySet=\"students\" /></" +
                "AssociationSet></EntityContainer></Schema></edmx:DataServices></edmx:Edmx>";
            [global::System.CodeDom.Compiler.GeneratedCodeAttribute("System.Data.Services.Design", "1.0.0")]
            private static string GetConcatenatedEdmxString()
            {
                return string.Concat(ModelPart0);
            }
            [global::System.CodeDom.Compiler.GeneratedCodeAttribute("System.Data.Services.Design", "1.0.0")]
            public static global::Microsoft.Data.Edm.IEdmModel GetInstance()
            {
                return ParsedModel;
            }
            [global::System.CodeDom.Compiler.GeneratedCodeAttribute("System.Data.Services.Design", "1.0.0")]
            private static global::Microsoft.Data.Edm.IEdmModel LoadModelFromString()
            {
                string edmxToParse = GetConcatenatedEdmxString();
                global::System.Xml.XmlReader reader = CreateXmlReader(edmxToParse);
                try
                {
                    return global::Microsoft.Data.Edm.Csdl.EdmxReader.Parse(reader);
                }
                finally
                {
                    ((global::System.IDisposable)(reader)).Dispose();
                }
            }
            [global::System.CodeDom.Compiler.GeneratedCodeAttribute("System.Data.Services.Design", "1.0.0")]
            private static global::System.Xml.XmlReader CreateXmlReader(string edmxToParse)
            {
                return global::System.Xml.XmlReader.Create(new global::System.IO.StringReader(edmxToParse));
            }
        }
    }
    /// <summary>
    /// There are no comments for StudentsModel.note in the schema.
    /// </summary>
    /// <KeyProperties>
    /// id
    /// </KeyProperties>
    [global::System.Data.Services.Common.DataServiceKeyAttribute("id")]
    public partial class note
    {
        /// <summary>
        /// Create a new note object.
        /// </summary>
        /// <param name="ID">Initial value of id.</param>
        [global::System.CodeDom.Compiler.GeneratedCodeAttribute("System.Data.Services.Design", "1.0.0")]
        public static note Createnote(int ID)
        {
            note note = new note();
            note.id = ID;
            return note;
        }
        /// <summary>
        /// There are no comments for Property id in the schema.
        /// </summary>
        [global::System.CodeDom.Compiler.GeneratedCodeAttribute("System.Data.Services.Design", "1.0.0")]
        public int id
        {
            get
            {
                return this._id;
            }
            set
            {
                this.OnidChanging(value);
                this._id = value;
                this.OnidChanged();
            }
        }
        [global::System.CodeDom.Compiler.GeneratedCodeAttribute("System.Data.Services.Design", "1.0.0")]
        private int _id;
        partial void OnidChanging(int value);
        partial void OnidChanged();
        /// <summary>
        /// There are no comments for Property stud_id in the schema.
        /// </summary>
        [global::System.CodeDom.Compiler.GeneratedCodeAttribute("System.Data.Services.Design", "1.0.0")]
        public global::System.Nullable<int> stud_id
        {
            get
            {
                return this._stud_id;
            }
            set
            {
                this.Onstud_idChanging(value);
                this._stud_id = value;
                this.Onstud_idChanged();
            }
        }
        [global::System.CodeDom.Compiler.GeneratedCodeAttribute("System.Data.Services.Design", "1.0.0")]
        private global::System.Nullable<int> _stud_id;
        partial void Onstud_idChanging(global::System.Nullable<int> value);
        partial void Onstud_idChanged();
        /// <summary>
        /// There are no comments for Property subject in the schema.
        /// </summary>
        [global::System.CodeDom.Compiler.GeneratedCodeAttribute("System.Data.Services.Design", "1.0.0")]
        public string subject
        {
            get
            {
                return this._subject;
            }
            set
            {
                this.OnsubjectChanging(value);
                this._subject = value;
                this.OnsubjectChanged();
            }
        }
        [global::System.CodeDom.Compiler.GeneratedCodeAttribute("System.Data.Services.Design", "1.0.0")]
        private string _subject;
        partial void OnsubjectChanging(string value);
        partial void OnsubjectChanged();
        /// <summary>
        /// There are no comments for Property note1 in the schema.
        /// </summary>
        [global::System.CodeDom.Compiler.GeneratedCodeAttribute("System.Data.Services.Design", "1.0.0")]
        public global::System.Nullable<int> note1
        {
            get
            {
                return this._note1;
            }
            set
            {
                this.Onnote1Changing(value);
                this._note1 = value;
                this.Onnote1Changed();
            }
        }
        [global::System.CodeDom.Compiler.GeneratedCodeAttribute("System.Data.Services.Design", "1.0.0")]
        private global::System.Nullable<int> _note1;
        partial void Onnote1Changing(global::System.Nullable<int> value);
        partial void Onnote1Changed();
        /// <summary>
        /// There are no comments for student in the schema.
        /// </summary>
        [global::System.CodeDom.Compiler.GeneratedCodeAttribute("System.Data.Services.Design", "1.0.0")]
        public student student
        {
            get
            {
                return this._student;
            }
            set
            {
                this._student = value;
            }
        }
        [global::System.CodeDom.Compiler.GeneratedCodeAttribute("System.Data.Services.Design", "1.0.0")]
        private student _student;
    }
    /// <summary>
    /// There are no comments for StudentsModel.student in the schema.
    /// </summary>
    /// <KeyProperties>
    /// id
    /// </KeyProperties>
    [global::System.Data.Services.Common.DataServiceKeyAttribute("id")]
    public partial class student
    {
        /// <summary>
        /// Create a new student object.
        /// </summary>
        /// <param name="ID">Initial value of id.</param>
        [global::System.CodeDom.Compiler.GeneratedCodeAttribute("System.Data.Services.Design", "1.0.0")]
        public static student Createstudent(int ID)
        {
            student student = new student();
            student.id = ID;
            return student;
        }
        /// <summary>
        /// There are no comments for Property id in the schema.
        /// </summary>
        [global::System.CodeDom.Compiler.GeneratedCodeAttribute("System.Data.Services.Design", "1.0.0")]
        public int id
        {
            get
            {
                return this._id;
            }
            set
            {
                this.OnidChanging(value);
                this._id = value;
                this.OnidChanged();
            }
        }
        [global::System.CodeDom.Compiler.GeneratedCodeAttribute("System.Data.Services.Design", "1.0.0")]
        private int _id;
        partial void OnidChanging(int value);
        partial void OnidChanged();
        /// <summary>
        /// There are no comments for Property name in the schema.
        /// </summary>
        [global::System.CodeDom.Compiler.GeneratedCodeAttribute("System.Data.Services.Design", "1.0.0")]
        public string name
        {
            get
            {
                return this._name;
            }
            set
            {
                this.OnnameChanging(value);
                this._name = value;
                this.OnnameChanged();
            }
        }
        [global::System.CodeDom.Compiler.GeneratedCodeAttribute("System.Data.Services.Design", "1.0.0")]
        private string _name;
        partial void OnnameChanging(string value);
        partial void OnnameChanged();
        /// <summary>
        /// There are no comments for notes in the schema.
        /// </summary>
        [global::System.CodeDom.Compiler.GeneratedCodeAttribute("System.Data.Services.Design", "1.0.0")]
        public global::System.Collections.ObjectModel.Collection<note> notes
        {
            get
            {
                return this._notes;
            }
            set
            {
                if ((value != null))
                {
                    this._notes = value;
                }
            }
        }
        [global::System.CodeDom.Compiler.GeneratedCodeAttribute("System.Data.Services.Design", "1.0.0")]
        private global::System.Collections.ObjectModel.Collection<note> _notes = new global::System.Collections.ObjectModel.Collection<note>();
    }
}
