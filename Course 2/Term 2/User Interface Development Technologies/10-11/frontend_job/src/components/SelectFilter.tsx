import React, { useState } from 'react';
import { Select, MenuItem } from '@mui/material';
import { Grid } from "@mui/material";
import { ListItemIcon } from "@mui/material";
import WorkIcon from '@mui/icons-material/Work';
import StarIcon from '@mui/icons-material/Star';
import AccessAlarm from '@mui/icons-material/AccessAlarm';

interface SelectFilterProps {
    icon: 'Work' | 'Star' | 'AccessAlarm';
    options: string[];
}

const SelectFilter: React.FC<SelectFilterProps> = ({ icon, options }) => {
    const [selectedOption, setSelectedOption] = useState<string | null>(null);

    const handleOptionSelect = (option: string) => {
        setSelectedOption(option);
    };

    const getIconComponent = (icon: string) => {
        switch (icon) {
            case 'Work':
                return <WorkIcon fontSize="medium" style={{ color: '#0070FB', marginRight: 15 }} />;
            case 'Star':
                return <StarIcon fontSize="medium" style={{ color: '#0070FB', marginRight: 15 }} />;
            case 'AccessAlarm':
                return <AccessAlarm fontSize="medium" style={{ color: '#0070FB', marginRight: 15 }} />;
            default:
                return null;
        }
    };

    return (
        <Select
            sx={{
                flexGrow: 1,
                '& .MuiSelect-icon': { display: 'none' },
                '& .MuiOutlinedInput-notchedOutline': { border: 'none' },
            }}
            defaultValue="filter1"
        >
            {options.map((option, index) => (
                <MenuItem key={index} value={`filter${index + 1}`} sx={{ width: '100%' }}>
                    <Grid container>
                        {getIconComponent(icon)}
                        <span>{option}</span>
                    </Grid>
                </MenuItem>
            ))}
        </Select>
    );
};

export default SelectFilter;
