import { Router } from 'express';
import { getUserPermissions, permissionsMiddleware } from '../middlewares/permissions.js';
import { prismaClient } from '../../prisma/client.js';

export const usersRouter = Router();

const handleError = (error, res, next) => {
  console.error(error.message);
  res.status(error.status || 500).send(error.message || 'An error occurred');
  next(error);
};

const isAuthenticated = (req, res, next) => {
  if (!req.user || !req.user.id) {
    const error = new Error('Authentication required');
    error.status = 401;
    throw error;
  }
  next();
};

usersRouter.get('/me', isAuthenticated, async (req, res, next) => {
  try {
    const userAbilities = getUserPermissions(req.user.role, req.user.id);
    if (!userAbilities.can('read', 'user', `${req.user.id}`)) {
      throw new Error('Access Forbidden');
    }

    const user = await prismaClient.user.findUnique({
      where: { id: req.user.id },
      select: {
        id: true,
        username: true,
        email: true,
        role: true,
        password: false,
      },
    });

    if (!user) {
      throw new Error('User does not exist');
    }

    res.json(user);
  } catch (error) {
    handleError(error, res, next);
  }
});

usersRouter.get('/:id', permissionsMiddleware([['read', 'user']]), async (req, res, next) => {
  try {
    const id = parseInt(req.params.id);
    if (isNaN(id)) {
      throw new Error('Invalid ID provided');
    }

    const user = await prismaClient.user.findUnique({
      where: { id },
      select: {
        id: true,
        username: true,
        email: true,
        role: true,
        password: false,
      },
    });

    if (!user) {
      throw new Error('User with the provided ID does not exist');
    }

    res.json(user);
  } catch (error) {
    handleError(error, res, next);
  }
});

usersRouter.get('/', permissionsMiddleware([['manage', 'all']]), async (req, res, next) => {
  try {
    const users = await prismaClient.user.findMany({
      select: {
        id: true,
        username: true,
        email: true,
        role: true,
        password: false,
      },
    });

    res.json(users);
  } catch (error) {
    handleError(error, res, next);
  }
});
