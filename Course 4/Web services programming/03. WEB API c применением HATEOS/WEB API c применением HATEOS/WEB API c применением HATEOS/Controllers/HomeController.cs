using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using WEB_API_c_применением_HATEOS.Models;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Newtonsoft.Json;

namespace WEB_API_c_применением_HATEOS.Controllers
{
    public class StudentResponse
    {
        [JsonProperty(NullValueHandling = NullValueHandling.Ignore)]
        public int? Id { get; set; }

        [JsonProperty(NullValueHandling = NullValueHandling.Ignore)]
        public string Name { get; set; }

        [JsonProperty(NullValueHandling = NullValueHandling.Ignore)]
        public string Phone { get; set; }

        public List<Link> Links { get; set; }
    }
    public class StudentsResponse
    {
        public List<StudentResponse> Students { get; set; }
    }

    public class Link
    {
        public string Rel { get; set; }
        public string Href { get; set; }
        public string Method { get; set; }
    }


    public class ErrorResponse
    {
        public int StatusCode { get; set; }
        public string Message { get; set; }
        public string ErrorCode { get; set; }
        public List<Link> Links { get; set; }
    }

    public class ErrorInfoResponse
    {
        public string Code { get; set; }
        public string Description { get; set; }
    }

    [Route("api/[controller]")]
    [ApiController]
    [Produces("application/json", "application/xml")]
    public class StudentsController : ControllerBase
    {
        private readonly ApplicationDbContext _context;

        public StudentsController(ApplicationDbContext context)
        {
            _context = context;
        }

        private IActionResult CreateErrorResponse(int statusCode, string message, string errorCode)
        {
            var errorResponse = new ErrorResponse
            {
                StatusCode = statusCode,
                Message = message,
                ErrorCode = errorCode,
                Links = new List<Link>
                {
                    new Link
                    {
                        Rel = "self",
                        Href = Url.Action("GetErrorDetails", new { code = errorCode }),
                        Method = "GET"
                    }
                }
            };

            return StatusCode(statusCode, errorResponse);
        }

        // GET: api/students
        [HttpGet]
        public async Task<IActionResult> GetStudents(
            int? limit = null,
            string sort = null,
            int? offset = null,
            int? minid = null,
            int? maxid = null,
            string like = null,
            string globalike = null,
            string columns = null)
        {
            IQueryable<Student> query = _context.Students;

            if (minid.HasValue)
                query = query.Where(s => s.ID >= minid);
            if (maxid.HasValue)
                query = query.Where(s => s.ID <= maxid);
            if (!string.IsNullOrEmpty(like))
                query = query.Where(s => s.Name.Contains(like));
            if (!string.IsNullOrEmpty(globalike))
            {
                query = query.Where(s => EF.Functions.Like(
                    s.ID.ToString() + s.Name + s.Phone,
                    "%" + globalike + "%"));
            }
            if (!string.IsNullOrEmpty(sort) && sort.ToUpper() == "NAME")
            {
                query = query.OrderBy(s => s.Name);
            }
            else
            {
                query = query.OrderBy(s => s.ID);
            }
            if (offset.HasValue)
                query = query.Skip(offset.Value);
            if (limit.HasValue)
                query = query.Take(limit.Value);

            var students = await query.ToListAsync();

            var result = new StudentsResponse
            {
                Students = students.Select(student =>
                {
                    var studentResponse = new StudentResponse
                    {
                        Links = new List<Link>
                {
                    new Link
                    {
                        Rel = "get",
                        Href = Url.Action(nameof(GetStudent), new { id = student.ID }),
                        Method = "GET"
                    },
                    new Link
                    {
                        Rel = "update",
                        Href = Url.Action(nameof(PutStudent), new { id = student.ID }),
                        Method = "PUT"
                    },
                    new Link
                    {
                        Rel = "delete",
                        Href = Url.Action(nameof(DeleteStudent), new { id = student.ID }),
                        Method = "DELETE"
                    }
                }
                    };

                    if (!string.IsNullOrEmpty(columns))
                    {
                        var requestedColumns = columns.Split(',').Select(c => c.Trim().ToLower()).ToList();

                        if (requestedColumns.Contains("id"))
                        {
                            studentResponse.Id = student.ID;
                        }

                        if (requestedColumns.Contains("name"))
                        {
                            studentResponse.Name = student.Name;
                        }

                        if (requestedColumns.Contains("phone"))
                        {
                            studentResponse.Phone = student.Phone;
                        }
                    }
                    else
                    {
                        studentResponse.Id = student.ID;
                        studentResponse.Name = student.Name;
                        studentResponse.Phone = student.Phone;
                    }

                    return studentResponse;
                }).ToList()
            };

            return Ok(result);
        }


        // GET: api/students/{id}
        [HttpGet("{id}")]
        public async Task<IActionResult> GetStudent(int id)
        {
            var student = await _context.Students.FindAsync(id);
            if (student == null)
                return CreateErrorResponse(400, "Student not found.", "STUDENT_NOT_FOUND");

            var result = new StudentResponse
            {
                Id = student.ID,
                Name = student.Name,
                Phone = student.Phone,
                Links = new List<Link>
                {
                    new Link
                    {
                        Rel = "self",
                        Href = Url.Action(nameof(GetStudent), new { id = student.ID }),
                        Method = "GET"
                    },
                    new Link
                    {
                        Rel = "update",
                        Href = Url.Action(nameof(PutStudent), new { id = student.ID }),
                        Method = "PUT"
                    },
                    new Link
                    {
                        Rel = "delete",
                        Href = Url.Action(nameof(DeleteStudent), new { id = student.ID }),
                        Method = "DELETE"
                    }
                }
            };

            return Ok(result);
        }
        // GET: api/students/error/{code}
        [HttpGet("error/{code}")]
        public IActionResult GetErrorDetails(string code)
        {
            var errorDescriptions = new Dictionary<string, string>
            {
                { "STUDENT_NOT_FOUND", "The student with the given ID was not found." },
                { "ID_MISMATCH", "The ID in the route does not match the ID in the provided model." }
            };

            if (errorDescriptions.TryGetValue(code, out var description))
            {
                var errorResponse = new ErrorInfoResponse
                {
                    Code = code,
                    Description = description
                };
                return Ok(errorResponse);

            }

            return NotFound(new ErrorInfoResponse
            {
                Code = code,
                Description = description
            });
        }

        // POST: api/students
        [HttpPost]
        public async Task<IActionResult> PostStudent(Student student)
        {
            _context.Students.Add(student);
            await _context.SaveChangesAsync();

            var result = new StudentResponse
            {
                Id = student.ID,
                Name = student.Name,
                Phone = student.Phone,
                Links = new List<Link>
                {
                    new Link
                    {
                        Rel = "self",
                        Href = Url.Action(nameof(GetStudent), new { id = student.ID }),
                        Method = "GET"
                    },
                    new Link
                    {
                        Rel = "update",
                        Href = Url.Action(nameof(PutStudent), new { id = student.ID }),
                        Method = "PUT"
                    },
                    new Link
                    {
                        Rel = "delete",
                        Href = Url.Action(nameof(DeleteStudent), new { id = student.ID }),
                        Method = "DELETE"
                    }
                }
            };

            return CreatedAtAction(nameof(GetStudent), new { id = student.ID }, result);
        }

        // PUT: api/students/{id}
        [HttpPut("{id}")]
        public async Task<IActionResult> PutStudent(int id, Student student)
        {
            if (id != student.ID)
                return CreateErrorResponse(400, "Student ID mismatch.", "ID_MISMATCH");

            _context.Entry(student).State = EntityState.Modified;

            try
            {
                await _context.SaveChangesAsync();
            }
            catch (DbUpdateConcurrencyException)
            {
                if (!StudentExists(id))
                    return CreateErrorResponse(400, "Student not found.", "STUDENT_NOT_FOUND");
                throw;
            }

            return NoContent();
        }

        // DELETE: api/students/{id}
        [HttpDelete("{id}")]
        public async Task<IActionResult> DeleteStudent(int id)
        {
            var student = await _context.Students.FindAsync(id);
            if (student == null)
                return CreateErrorResponse(400, "Student not found.", "STUDENT_NOT_FOUND");

            _context.Students.Remove(student);
            await _context.SaveChangesAsync();

            return NoContent();
        }

        private bool StudentExists(int id) => _context.Students.Any(e => e.ID == id);
    }
}
