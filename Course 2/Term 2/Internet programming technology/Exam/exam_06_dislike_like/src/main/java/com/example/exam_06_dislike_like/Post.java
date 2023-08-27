package com.example.exam_06_dislike_like;

public class Post {
    public String text;
    public Integer like;
    public Integer dislike;

    public String getText() {
        return text;
    }

    public Integer getLike() {
        return like;
    }

    public Integer getDislike() {
        return dislike;
    }

    public Post(String text, Integer like, Integer dislike) {
        this.text = text;
        this.like = like;
        this.dislike = dislike;
    }
}
