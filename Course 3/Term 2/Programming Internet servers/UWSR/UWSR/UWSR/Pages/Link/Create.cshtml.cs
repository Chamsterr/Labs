using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using UWSR.Models;

namespace UWSR.Pages.Link
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
            return Page();
        }

        [BindProperty]
        public Links Link { get; set; } = default!;


        public async Task<IActionResult> OnPostAsync()
        {
            Link.Plus = 0;
            Link.Minus = 0;
            if (_context.Links == null || Link == null)
            {
                return Page();
            }

            _context.Links.Add(Link);
            await _context.SaveChangesAsync();

            return RedirectToPage("./Index");
        }
    }
}
