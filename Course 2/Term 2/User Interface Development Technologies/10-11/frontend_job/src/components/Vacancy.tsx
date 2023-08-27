import * as React from 'react';
import Card from '@mui/material/Card';
import CardActions from '@mui/material/CardActions';
import CardContent from '@mui/material/CardContent';
import CardMedia from '@mui/material/CardMedia';
import Button from '@mui/material/Button';
import Typography from '@mui/material/Typography';
import Grid from '@mui/material/Grid';
import { CardActionArea } from '@mui/material';
import FavoriteIcon from '@mui/icons-material/Favorite';

import { useDispatch } from 'react-redux';
import { selectVacancy } from '../redux/actions';

interface VacancyProps {
  companyName: string;
  vacancyName: string;
  location: string;
  imageSrc: string;
  date: string;
  stack: String[];
  id: number;
}

export default function Vacancy({ companyName, vacancyName, location, imageSrc, date, stack, id }: VacancyProps) {
  const dispatch = useDispatch();

  const handleSelect = () => {
    dispatch(selectVacancy(id));
  };

  return (
    <Card sx={{borderRadius: '10px', maxWidth: 460, display: 'flex', marginBottom: 2, boxShadow: '0px 3px 15px rgba(0, 0, 0, 0.03)' }}>
      <CardActionArea onClick={handleSelect}>
        <Grid container>
          <Grid item xs={3} >
            <CardMedia
              component="img"
              height="68"
              sx={{ width: '68px', margin: "20% 10% 10% 20%" }}
              image={imageSrc}
              title={vacancyName}
            />
          </Grid>
          <Grid item xs={9}>
            <CardContent>
              <Typography gutterBottom sx={{ fontSize: 10 }} color="#33ACFF">
                {companyName}
              </Typography>
              <Typography sx={{ fontSize: 14 }} >
                {vacancyName}
              </Typography>
              <Typography sx={{ fontSize: 10 }} >
                {location}
              </Typography>
              <Typography sx={{ fontSize: 10, position: 'absolute', right: 10, bottom: 10 }} >
                {date}
              </Typography>
              {stack.map((item, index) => (
                <Button key={index} sx={{ fontSize: 9, minWidth: 10, minHeight: 10, color: '#0584EC', background: '#F7F8F9', marginRight: '5px', marginBottom: '5px', marginTop: '5px' }}>
                  {item}
                </Button>
              ))}
              <FavoriteIcon sx={{color: '#E1E1E1', position: 'absolute', right: 10, top: 10 }}></FavoriteIcon>
            </CardContent>
          </Grid>
        </Grid>
      </CardActionArea>
    </Card>
  );
}