using StudentsModel;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web.Mvc;

namespace web_ws_6.Controllers
{
    public class HomeController : Controller
    {
        private StudentsModel.StudentsEntities11 service = new StudentsEntities11(new Uri("http://localhost:1395/Service1.svc"));

        public ActionResult Index()
        {
            IEnumerable<student> students = service.students.ToList();
            IEnumerable<note> notes = service.notes.ToList();
            var model = Tuple.Create(students, notes);
            return View(model);
        }


        [HttpPost]
        public ActionResult AddStudent(string studentName)
        {
            if (!string.IsNullOrEmpty(studentName))
            {
                try
                {
                    var student = new student { name = studentName };
                    service.AddTostudents(student);
                    service.SaveChanges();
                }
                catch (Exception exc)
                {
                    ViewBag.ErrorMessage = exc.Message;
                }
            }
            return RedirectToAction("Index");
        }

        [HttpPost]
        public ActionResult DeleteStudent(int id)
        {
            try
            {
                var student = service.students.AsEnumerable().FirstOrDefault(s => s.id == id);
                if (student != null)
                {
                    service.DeleteObject(student);
                    service.SaveChanges();
                }
            }
            catch (Exception exc)
            {
                ViewBag.ErrorMessage = exc.Message;
            }
            return RedirectToAction("Index");
        }

        [HttpPost]
        public ActionResult UpdateStudent(int id, string studentName)
        {
            if (!string.IsNullOrEmpty(studentName))
            {
                try
                {
                    var student = service.students.AsEnumerable().FirstOrDefault(s => s.id == id);
                    if (student != null)
                    {
                        student.name = studentName;
                        service.UpdateObject(student);
                        service.SaveChanges();
                    }
                }
                catch (Exception exc)
                {
                    ViewBag.ErrorMessage = exc.Message;
                }
            }
            return RedirectToAction("Index");
        }

        [HttpPost]
        public ActionResult AddNote(int stud_id, string subject, int note1)
        {
            if (!string.IsNullOrEmpty(subject))
            {
                try
                {
                    var note = new note { stud_id = stud_id, subject = subject, note1 = note1 };
                    service.AddTonotes(note);
                    service.SaveChanges();
                }
                catch (Exception exc)
                {
                    ViewBag.ErrorMessage = exc.Message;
                }
            }
            return RedirectToAction("Index");
        }

        [HttpPost]
        public ActionResult DeleteNote(int id)
        {
            try
            {
                var note = service.notes.AsEnumerable().FirstOrDefault(n => n.id == id);
                if (note != null)
                {
                    service.DeleteObject(note);
                    service.SaveChanges();
                }
            }
            catch (Exception exc)
            {
                ViewBag.ErrorMessage = exc.Message;
            }
            return RedirectToAction("Index");
        }
    }
}
