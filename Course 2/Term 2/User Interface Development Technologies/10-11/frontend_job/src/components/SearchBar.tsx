// import React from 'react';
// import { Grid } from "@mui/material";
// import { Box } from '@mui/material';
// import SearchInput from './SearchInput';
// import SelectFilter from './SelectFilter';
// import Button from '@mui/material/Button';

// export default function SearchBar() {
//   return (
//     <div style={{ display: 'flex', flexDirection: 'row', backgroundColor: 'white', borderRadius: '15px' }}>
//       <Grid display="flex" alignItems="center" style={{ borderRight: '1px solid #F9F9F9' }}>
//         <SearchInput icon="AirplanemodeActive" />
//       </Grid>

//       <Grid container alignItems="center" style={{ borderRight: '1px solid #F9F9F9' }}>
//         <SelectFilter icon="AccessAlarm" options={['Option 1', 'Option 2', 'Option 3']} />
//       </Grid>

//       <Grid container alignItems="center" style={{ borderRight: '1px solid #F9F9F9' }}>
//         <SelectFilter icon="Work" options={['Option 1', 'Option 2', 'Option 3']} />
//       </Grid>

//       <Grid container alignItems="center" style={{ borderRight: '1px solid #F9F9F9' }}>
//         <SelectFilter icon="Star" options={['Option 1', 'Option 2', 'Option 3']} />
//       </Grid>

//       <Grid container alignItems="center" style={{ borderRight: '1px solid #F9F9F9' }}>
//         <SearchInput icon="Sell" />
//       </Grid>
    
//       <Button variant="contained" sx={{ borderRadius: '0 15px 15px 0', textTransform: 'none', backgroundColor: '#0070FB' }}>Поиск</Button>
//     </div>
//   );
// }

import React from 'react';
import TextField from '@mui/material/TextField';
import Autocomplete from '@mui/material/Autocomplete';
import Select from '@mui/material/Select';
import MenuItem from '@mui/material/MenuItem';
import { ListItemIcon } from "@mui/material";
import { Grid } from "@mui/material";
import StarIcon from '@mui/icons-material/Star';
import { Box } from '@mui/material';

import WorkIcon from '@mui/icons-material/Work';
import AirplanemodeActiveIcon from '@mui/icons-material/AirplanemodeActive';
import AccessAlarmIcon from '@mui/icons-material/AccessAlarm';
import Button from '@mui/material/Button';
import SellIcon from '@mui/icons-material/Sell';

export default function SearchBar() {
    const searchOptions = ['Option 1', 'Option 2', 'Option 3']; 

    return (
        <div style={{ display: 'flex', flexDirection: 'row', backgroundColor: 'white', borderRadius: '15px 15px 15px 15px'}}>
            <Grid display="flex" alignItems="center" style={{ borderRight: '1px solid #F9F9F9' }}>
                <ListItemIcon style={{ minWidth: '0', marginLeft: 15 }}>
                    <AirplanemodeActiveIcon fontSize="medium" style={{ color: '#0070FB' }}/>
                </ListItemIcon>
                <input style={{ border: 'none', outline: 'none', marginLeft: 15, width: 125, fontSize: 18 }} />
            </Grid>

            <Grid container alignItems="center" style={{ borderRight: '1px solid #F9F9F9', display: 'flex', alignItems: 'center' }}>
                <ListItemIcon style={{ minWidth: '0', overflow: 'hidden', marginLeft: 15 }}>
                    <AccessAlarmIcon fontSize="medium" style={{ color: '#0070FB' }}/>
                </ListItemIcon>
                <Select
                    sx={{
                        '& .MuiSelect-icon': { display: 'none' },
                        '& .MuiOutlinedInput-notchedOutline': { border: 'none' },
                        '& .MuiPopover-paper': { boxShadow: 'none' }
                    }}
                    defaultValue="filter1"
                >
                    <MenuItem value="filter1">
                        <Grid container>
                            <span>Option 1</span>
                        </Grid>
                    </MenuItem>
                    <MenuItem value="filter2">Filter 2</MenuItem>
                    <MenuItem value="filter3">Filter 3</MenuItem>
                </Select>
            </Grid>

            <Grid container alignItems="center" style={{ borderRight: '1px solid #F9F9F9' }}>
            <ListItemIcon style={{ minWidth: '0', overflow: 'hidden', marginLeft: 15 }}>
                <WorkIcon fontSize="medium" style={{ color: '#0070FB' }}/>
            </ListItemIcon>
                <Select
                    sx={{
                        '& .MuiSelect-icon': { display: 'none' },
                        '& .MuiOutlinedInput-notchedOutline': { border: 'none' },
                    }}
                    defaultValue="filter1"
                >
                    <MenuItem value="filter1">
                        <Grid container>
                            <span>Option 1</span>
                        </Grid>
                    </MenuItem>
                    <MenuItem value="filter2">Filter 2</MenuItem>
                    <MenuItem value="filter3">Filter 3</MenuItem>
                </Select>
            </Grid>
            <Grid container alignItems="center" style={{ borderRight: '1px solid #F9F9F9' }}>
            <ListItemIcon style={{ minWidth: '0', overflow: 'hidden', marginLeft: 15 }}>
                <StarIcon fontSize="medium" style={{ color: '#0070FB' }}/>
            </ListItemIcon>
                <Select
                    sx={{
                        '& .MuiSelect-icon': { display: 'none' },
                        '& .MuiOutlinedInput-notchedOutline': { border: 'none' },
                    }}
                    defaultValue="filter1"
                >
                    <MenuItem value="filter1">
                        <Grid container>
                            <span>Option 1</span>
                        </Grid>
                    </MenuItem>
                    <MenuItem value="filter2">Filter 2</MenuItem>
                    <MenuItem value="filter3">Filter 3</MenuItem>
                </Select>
            </Grid>
            <Grid container alignItems="center" style={{ borderRight: '1px solid #F9F9F9' }}>
            <ListItemIcon style={{ minWidth: '0', overflow: 'hidden', marginLeft: 15 }}>
                <SellIcon fontSize="medium" style={{ color: '#0070FB' }} />
            </ListItemIcon>
            <input style={{ border: 'none', outline: 'none', marginLeft: 15, width: 125, fontSize: 18 }} />

            </Grid>
            <Button variant="contained" sx={{ borderRadius: '0 15px 15px 0', textTransform: 'none', backgroundColor: '#0070FB' }}>Поиск</Button>

        </div>
    );
}
