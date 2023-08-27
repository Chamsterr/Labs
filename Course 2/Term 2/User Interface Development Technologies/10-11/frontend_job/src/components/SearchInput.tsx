import React from 'react';
import { Grid } from "@mui/material";
import { ListItemIcon } from "@mui/material";
import AirplanemodeActiveIcon from '@mui/icons-material/AirplanemodeActive';
import SellIcon from '@mui/icons-material/Sell';

interface SearchInputProps {
  icon: 'AirplanemodeActive' | 'Sell';
}

const SearchInput: React.FC<SearchInputProps> = ({ icon }) => {
  const getIconComponent = (icon: string) => {
    switch (icon) {
      case 'AirplanemodeActive':
        return <AirplanemodeActiveIcon fontSize="medium" style={{ color: '#0070FB' }} />;
      case 'Sell':
        return <SellIcon fontSize="medium" style={{ color: '#0070FB' }} />;
      default:
        return null;
    }
  };

  return (
    <React.Fragment>
      <ListItemIcon style={{ minWidth: '0', marginLeft: 15 }}>
        {getIconComponent(icon)}
      </ListItemIcon>
      <input style={{ border: 'none', outline: 'none', marginLeft: 15, width: 125, fontSize: 18 }} />
    </React.Fragment>
  );
};

export default SearchInput;
