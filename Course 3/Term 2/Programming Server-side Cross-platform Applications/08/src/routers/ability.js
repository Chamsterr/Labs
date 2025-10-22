import { Router } from "express";
import { getUserPermissions, permissionsMiddleware } from "../middlewares/permissions.js";

export const abilityRouter = Router();

abilityRouter.get("/", (req, res, next) => {
    try {
        const role = req?.user?.role || 'Guest';
        const { rules } = getUserPermissions(role);
        res.status(200).json({ permissions: rules });

    } catch (error) {
        next(error);
    }
});
