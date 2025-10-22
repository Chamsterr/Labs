using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using System.Text;

namespace UWSR.Pages.Auth
{
    public class CreateModel : PageModel
    {
        private readonly UWSR.Data.AppDbContext _context;

        public CreateModel(UWSR.Data.AppDbContext context)
        {
            _context = context;
        }

        public IActionResult OnGet()
        {
            if (Request.Query.TryGetValue("shortcut", out var shortcutValues))
            {
                if (shortcutValues == "ctrl `")
                {
                    return Page();
                }
            }
            return NotFound();
        }

        [BindProperty]
        public string Password { get; set; } = default!;

        public async Task<IActionResult> OnPostAsync()
        {

            if (_context.Links == null || Password == null)
            {
                return Page();
            }

            if (Password == "admin+")
            {
                HttpContext.Session.Set("isAdmin", Encoding.UTF8.GetBytes("true"));
            }

            return Redirect("http://localhost:6118/");
        }
    }
}
