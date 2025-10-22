import { Router } from "express";
import { prismaClient } from "../../prisma/client.js";
import { permissionsMiddleware } from "../middlewares/permissions.js";

export const reposRouter = Router();

reposRouter.get("/:id", permissionsMiddleware([["read", "repo"]]), async (req, res, next) => {
  try {
    const id = parseInt(req.params.id);
    console.log(id);
    if (!id) throw new Error("Repos ID is not provided");
    const repo = await prismaClient.repo.findUnique({where: {id}});
    if (!repo) throw new Error("Repos ID provided is not found");
    res.json(repo);
  } catch (error) {
    next(error);
  }
});

reposRouter.get("/", permissionsMiddleware([["read", "repo"]]), async (req, res, next) => {
  try {
    console.log(req.isAuthenticated());
    console.log(req.user);
    const repos = await prismaClient.repo.findMany();
    res.json(repos);
  } catch (error) {
    next(error);
  }
});

reposRouter.post("/", permissionsMiddleware([["create", "repo"]]), async (req, res, next) => {
  try {
    const {name} = req.body;
    if (!name) throw new Error("Repo name is not provided");
    const {id: authorId} = req.user;
    const newRepo = await prismaClient.repo.create({
      data: {
        name,
        authorId,
      },
    });
    res.json(newRepo);
  } catch (error) {
    next(error);
  }
});

reposRouter.put("/:id", async (req, res, next) => {
  try{
    console.log("123")
    const id = parseInt(req.params.id);
    const repo = await prismaClient.repo.findFirst({
      where: {id},
      include : {
        author:{
          select:{
            id:true
          }
        }
      }
    });
    console.log("username id: " + req.user.id + repo.author);
    if (req.user.id != repo.author.id && req.user.role != 'Admin') throw new Error("Forbidden access");
    if (!repo) throw new Error("Repos ID provided is not found");
    return permissionsMiddleware([["update", "repo", `${repo.author.id}`]])(req, res, next);
  } catch (e){
    next(e);
  }
}, async (req, res, next) => {
  try {
    const id = parseInt(req.params.id);
    if (!id) throw new Error("Repos ID is not provided");
    const repo = await prismaClient.repo.findFirst({
      where: {id},
    });
    if (!repo) throw new Error("Repos ID provided is not found");
    const {name} = req.body;
    const updatedRepo = await prismaClient.repo.update({
      where: {id},
      data: {
        ...(name && {name}),
      },
    });
    res.json(updatedRepo);
  } catch (error) {
    next(error);
  }
});

reposRouter.delete("/:id", permissionsMiddleware([["delete", "repo"]]), async (req, res, next) => {
  try {
    const isAdmin = req.user.role === 'Admin';
    const id = parseInt(req.params.id);
    if (!id) throw new Error("Repos ID is not provided");
    const {id: authorId} = req.user;
    const repo = await prismaClient.repo.findFirst({
      where: {id, ...(!isAdmin && {authorId})},
    });
    if (!repo) throw new Error("Repos ID provided is not found");
    const deletedRepo = await prismaClient.repo.delete({
      where: {
        id,
      },
    });
    res.json(deletedRepo);
  } catch (error) {
    next(error);
  }
});

reposRouter.get("/:id/commits", permissionsMiddleware([["read", "commit"]]), async (req, res, next) => {
  try {
    const id = parseInt(req.params.id);
    if (!id) throw new Error("Repos ID is not provided");
    const repo = await prismaClient.repo.findFirst({
      where: {id},
    });
    if (!repo) throw new Error("Repos ID provided is not found");
    const commits = await prismaClient.commit.findMany({where: {repoId: id}});
    res.json(commits);
  } catch (error) {
    next(error);
  }
});

reposRouter.get("/:id/commits/:commitId", permissionsMiddleware([["read", "commit"]]), async (req, res, next) => {
  try {
    const id = parseInt(req.params.id);
    const commitId = parseInt(req.params.commitId);
    if (!id || !commitId) throw new Error("Repo ID or Commit ID is not provided");
    const repo = await prismaClient.repo.findFirst({
      where: {id},
    });
    console.log(repo);
    if (!repo) throw new Error("Repos ID provided is not found");
    const commit = await prismaClient.commit.findFirst({
      where: {
        AND: [
          { id: commitId },
          { repoId: id }
        ]
      },
    });
    console.log(commit);
    if (!commit) throw new Error("Commit ID provided is not found");
    res.json(commit);
  } catch (error) {
    next(error);
  }
});

reposRouter.post("/:id/commits", async (req, res, next) => {
  try{
    const id = parseInt(req.params.id);
    const repo = await prismaClient.repo.findFirst({
      where: {id},
      include : {
        author:{
          select:{
            id:true
          }
        }
      }
    });
    if (req.user.role == 'Admin' && req.user.id != repo.author.id) throw new Error("Forbidden access");
    if (!repo) throw new Error("Repos ID provided is not found");
    return permissionsMiddleware([["create", "commit", `${repo.author.id}`]])(req, res, next);
  } catch (e){
    next(e);
  }
}, async (req, res, next) => {
  try {
    const id = parseInt(req.params.id);
    if (!id) throw new Error("Repo ID  is not provided");
    const {message} = await req.body;
    if (!message) throw new Error("Commit message is not provided");
    const repo = await prismaClient.repo.findFirst({
      where: {id},
    });
    if (!repo) throw new Error("Repos ID provided is not found");
    const commit = await prismaClient.commit.create({
      data: {
        message,
        repoId: id,
      },
    });
    res.json(commit);
  } catch (error) {
    next(error);
  }
});
