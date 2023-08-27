import { Card, CardContent, Typography } from '@mui/material';
import React from 'react'

interface Vacancy {
    companyName: string;
    vacancyName: string;
    location: string;
    date: string;
    image: string;
    stack: String[];
    info: string;
}

interface VacancyInfoProps {
    vacancy: Vacancy | null;
}

const VacancyInfo: React.FC<VacancyInfoProps> = ({ vacancy }) => {
    if (!vacancy) return null;  // Если нет вакансии, не отображаем ничего

    return (
        <Card sx={{ height: '100%', boxShadow: '0px 3px 15px rgba(0, 0, 0, 0.03)' }}>
            <CardContent>
                <Typography variant="h5">
                    {vacancy.vacancyName}
                </Typography>
                <Typography color="textSecondary">
                    {vacancy.companyName}
                </Typography>
                <Typography variant="body2">
                    {vacancy.info}
                </Typography>
            </CardContent>
        </Card>
    );
}

export default VacancyInfo;
