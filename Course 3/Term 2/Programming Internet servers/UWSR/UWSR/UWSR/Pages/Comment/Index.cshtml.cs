using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using Microsoft.EntityFrameworkCore;
using UWSR.Models;

namespace UWSR.Pages.Comment
{
    public class IndexModel : PageModel
    {
        private readonly UWSR.Data.AppDbContext _context;


        public IndexModel(UWSR.Data.AppDbContext context)
        {
            _context = context;

        }

        public IList<Comments> Comment { get;set; } = default!;

        public async Task OnGetAsync()
        {
            if (_context.Comments != null)
            {
                Comment = await _context.Comments.ToListAsync();
            }
        }

        public IActionResult OnPostClearCookies()
        {
            HttpContext.Session.Remove("isAdmin");


            return RedirectToPage(); 
        }
    }
}
