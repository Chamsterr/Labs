package com.example.demo.controller;
import com.example.demo.forms.AlbumForm;
import com.example.demo.forms.DelAlbumForm;
import com.example.demo.forms.UpdateAlbumForm;
import com.example.demo.model.Album;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.servlet.ModelAndView;

import java.util.ArrayList;
import java.util.List;

@Controller
public class AlbumController {
    private static List<Album> albums = new ArrayList<Album>();

    static {
        albums.add(new Album(1, "Lesnoy dviz", "Sanya Merlou"));
        albums.add(new Album(2, "Promo", "StatePromo"));
    }

    @Value("${welcome.message}")
    private String message;

    @Value("${error.message}")
    private String errorMessage;

    @RequestMapping(value = {"/", "/index"}, method = RequestMethod.GET)
    public ModelAndView index(Model model){
        ModelAndView modelAndView = new ModelAndView();
        modelAndView.setViewName("index");
        model.addAttribute("message", message);

        return modelAndView;
    }

    @RequestMapping(value = {"/allalbums"}, method = RequestMethod.GET)
    public ModelAndView albumList(Model model){
        ModelAndView modelAndView = new ModelAndView();
        modelAndView.setViewName("albumlist");
        model.addAttribute("albums", albums);
        return modelAndView;
    }

    @RequestMapping(value = {"/addalbum"}, method = RequestMethod.GET)
    public ModelAndView showAddAlbum(Model model){
        ModelAndView modelAndView = new ModelAndView("addalbum");
        AlbumForm albumForm = new AlbumForm();
        model.addAttribute("albumform", albumForm);

        return modelAndView;
    }

    @RequestMapping(value = {"/addalbum"}, method = RequestMethod.POST)
    public ModelAndView saveAlbum(Model model, @ModelAttribute("albumform") AlbumForm albumForm){
        ModelAndView modelAndView = new ModelAndView();
        modelAndView.setViewName("albumlist");
        String title = albumForm.getTitle();
        String author = albumForm.getAuthor();

        if (title != null && title.length() > 0 && author != null && author.length() > 0){
            Album newAlbum = new Album(albums.size(), title, author);
            albums.add(newAlbum);
            model.addAttribute("albums", albums);
            return modelAndView;
        }
        model.addAttribute("errorMessage", errorMessage);
        modelAndView.setViewName("addAlbum");
        modelAndView.setViewName("redirect:/allalbums");
        return modelAndView;
    }

    @RequestMapping(value = {"/delalbum"}, method = RequestMethod.POST)
        public ModelAndView delAlbum(Model model, @ModelAttribute("delalbumform") DelAlbumForm delAlbumForm){
        ModelAndView modelAndView = new ModelAndView();
        albums.removeIf(album -> album.getId().equals(delAlbumForm.getId()));
        // Шляпа
        model.addAttribute("albums", albums);
        modelAndView.setViewName("redirect:/allalbums");
        return modelAndView;
    }
@RequestMapping(value = {"/updatealbum"}, method = RequestMethod.POST)
public ModelAndView updateAlbum(Model model, @ModelAttribute("updatealbumform") UpdateAlbumForm updateAlbumForm) {
    ModelAndView modelAndView = new ModelAndView();

    Album albumToUpdate = albums.stream()
            .filter(album -> album.getId().equals(updateAlbumForm.getId()))
            .findFirst()
            .orElse(null);

    if (albumToUpdate != null) {
        albumToUpdate.setTitle(updateAlbumForm.getTitle());
        albumToUpdate.setAuthor(updateAlbumForm.getAuthor());
        modelAndView.setViewName("redirect:/allalbums");
    }
    return modelAndView;
}
}