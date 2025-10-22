import { Router } from "express";
import jwt from "jsonwebtoken";
import { PrismaClient } from "@prisma/client";

export const authRouter = Router();
export const prisma = new PrismaClient();
import passport from 'passport';



authRouter.get("/login", (req, res) => {
    console.log(req.isAuthenticated());
    res.send(
        `<html lang="en">
            <head>
                <meta charset="UTF-8"/>
                <meta http-equiv="X-UA-Compatible" content="IE=edge"/>
                <meta name="viewport" content="width=device-width, initial-scale=1.0"/>
                <title>Sign In</title>
            </head>
            <body>            
                <form method="POST" action="/auth/login">
                    <input name="username" type="text" placeholder="Username" />
                    <input name="password" type="password" placeholder="Password" />
                    <button type="submit">Login</button>
                </form>
            </body>
        </html>`
        );
});


authRouter.post("/login", passport.authenticate('local', { failureRedirect: '/login' }), async (req, res, next) => {
    try {
        const { username, password } = req.body;

        if (!username || !password) {
            return res.status(400).send("Username or password is not provided");
        }

        const user = await prisma.user.findFirst({
            where: { username },
        });

        if (!user || user.password !== password) {
            return res.status(401).send("Username or password is incorrect");
        }

        const accessToken = jwt.sign({ id: user.id }, process.env.ACCESS_TOKEN_SECRET, { expiresIn: '1h' });

        res.cookie("accessToken", accessToken, { httpOnly: true });
        res.status(200).send({ message: "Login successful", username });
    } catch (error) {
        next(error);
    }
});

authRouter.get("/register", (req, res) => {
    if (req.isAuthenticated() && req.user.role === 'Admin') {
        res.send(
            `<html lang="en">
                <head>
                    <meta charset="UTF-8"/>
                    <meta http-equiv="X-UA-Compatible" content="IE=edge"/>
                    <meta name="viewport" content="width=device-width, initial-scale=1.0"/>
                    <title>Register</title>
                </head>
                <body>
                    <form  method="POST" action="/auth/register">
                        <input id="username" name="username" type="text" placeholder="username"/>
                        <input id="email" name="email" type="email" placeholder="email"/>
                        <input id="password" name="password" type="password" placeholder="password"/>
                        <input id="role" name="role" type="text" placeholder="role"/>
                        <button type="submit">Register</button>
                    </form>
                </body>
            </html>`
        );
      } 
    else {
        res.status(403).send('Forbidden access');
      }
    }
);


authRouter.post("/register", async (req, res, next) => {
    const {email, username, password, role} = req.body;
    const validRoles = ['Guest', 'User', 'Admin'];

    try {
        if (req.user.role !== 'Admin') throw new Error("Forbidden access");
        if (!validRoles.includes(role)) throw new Error(`Incorrect role`);
        if (!email || !username || !password || !role) throw new Error(`Not all info are provided`);
        const checkUser = await prisma.user.findFirst({
            where: { OR: [{email}, {username}] },
        });
        if (checkUser) throw new Error(`User with this email or username has already exists`);

        const newUser = await prisma.user.create({
            data: { email, username, password, role },
        });
        res.json(newUser);
    } catch (error) {
        next(error);
    }
});
    

authRouter.get("/logout", (req, res) => {
    req.logout(function(err) {
        if (err) { return next(err); }
        res.clearCookie("token").send("Logged out");
        
        req.session.destroy(function(err) {
          if (err) {
            console.log("Ошибка при уничтожении сессии: ", err);
          }
        });
      });
    }
);
