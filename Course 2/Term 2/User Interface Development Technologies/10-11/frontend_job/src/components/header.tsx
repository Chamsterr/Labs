import { AppBar, Button, IconButton, Toolbar, Typography, makeStyles } from "@mui/material";
import MenuIcon from '@mui/icons-material/Menu';
import Logo from "./logo";
import Link from '@mui/material/Link';

function Header() {

    return (
        <div>
            <AppBar position="static" sx={{  flexGrow: 1, backgroundColor: 'white', boxShadow: 'none', height: 64 }}>
                <Toolbar>
                    <IconButton
                        size="large"
                        edge="start"
                        color="inherit"
                        aria-label="menu"
                        sx={{ mr: 2 }}
                    >
                        <Logo />
                    </IconButton>
                    <Link href="#" variant="h6" underline="none" sx={{flexGrow: 2, textAlign: "center", color: "black"}}>
                        Поиск вакансий
                    </Link>
                    <Link href="#" variant="h6" underline="none" sx={{flexGrow: 3, color: "black"}}>
                        Избранные вакансии
                    </Link>
                    <Button color="inherit">Login</Button>
                </Toolbar>
            </AppBar>
        </div>
    )
}

export default Header;