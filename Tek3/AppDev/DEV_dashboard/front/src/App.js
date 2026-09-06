import React, { useReducer } from 'react';

import { BrowserRouter, Route, Switch, Redirect } from 'react-router-dom';

import { ThemeProvider } from '@material-ui/styles';

import Login from './Login';
import Dashboard from './Dashboard';
import NotFoundPage from './NotFound';
import About from './About';

import dataReducer, { dataInitialState } from './reducers/dataReducer';

import DataContext from './contexts/dataContext';

import mainTheme from './styles/themeProvider';

export default function App() {

    const [dataState, dataDispatch] = useReducer(dataReducer, dataInitialState);

    return (
        <ThemeProvider theme={mainTheme}>
            <DataContext.Provider value={[dataState, dataDispatch]}>
                <BrowserRouter>
                    <Switch>
                        <Route exact path="/login" component={Login} />
                        <Route path="/dashboard" component={Dashboard} />
                        <Route exact path="/about.json" component={About} />
                        <Redirect exact from="/" to="/login" />
                        <Route component={NotFoundPage} />
                    </Switch>
                </BrowserRouter>
            </DataContext.Provider>
        </ThemeProvider>
    );
}
