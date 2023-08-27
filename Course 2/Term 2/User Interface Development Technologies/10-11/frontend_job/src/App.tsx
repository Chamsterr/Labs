import React from 'react';
import logo from './logo.svg';
import './App.css';
import AppBar from '@mui/material/AppBar';
import Header from './components/header';
import Vacancy from './components/Vacancy';
import Container from '@mui/material/Container';
import Main from './components/main';
import { Provider } from "react-redux";
import { store } from "./redux/store";

function App() {
  return (
    <Provider store={store}>
      <div className="App" style={{ width: '100%', height: '100%' }}>
        <Container maxWidth="lg">
          <header className="App-header">
            <Header></Header>
          </header>
        </Container>
        <Main></Main>
      </div>
    </Provider>
  );
}


export default App;
