import jwt from 'jsonwebtoken';
import { prismaClient } from '../../prisma/client.js';

export const authMiddleware = async (req, res, next) => {
  const accessToken = req.cookies.accessToken;

  if (!accessToken) {
    console.error('JWT not provided');
    return res.status(401).send('Access Denied: No token provided.');
  }

  try {
    const { id } = jwt.verify(accessToken, process.env.ACCESS_TOKEN_SECRET);
    const user = await prismaClient.user.findUnique({ where: { id } });

    if (!user) {
      console.error('User not found');
      return res.status(404).send('User does not exist.');
    }

    req.user = user;
    console.log('authMiddleware:', req.user);
    next();
  } catch (error) {
    console.error('Invalid token', error);
    req.user = null;
    next();
  }
};
