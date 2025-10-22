package com.example.demo.forms;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;


@Data
@AllArgsConstructor
@NoArgsConstructor
public class UpdateAlbumForm {
    private Integer id;
    private String title;
    private String author;
}